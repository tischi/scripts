"""Author: Antonio Politi, EMBL. mail@apoliti.de"""

from org.apache.commons.io.monitor import FileAlterationListener, FileAlterationListenerAdaptor, FileAlterationMonitor, FileAlterationObserver
from java import awt
from threading import Thread
from javax.swing import *
from java.io import FileNotFoundException
import java.awt.event.WindowAdapter
from javax.swing import (BoxLayout,  ImageIcon, JButton, JRadioButton, ButtonGroup, JFrame, JPanel, JSeparator,
		JPasswordField, JLabel, JTextArea, JTextField, JScrollPane, JCheckBox, 
		SwingConstants, WindowConstants, SpringLayout, Box, JComboBox, JSeparator, BorderFactory)
from java.awt import Component, GridLayout, BorderLayout, Dimension
from java.awt.event import ActionListener, WindowAdapter
import os
import time
import traceback
import pickle
from ij.io import OpenDialog
from ij.io import SaveDialog
from loci.plugins import BF
from ij.plugin import ChannelSplitter

from ij import IJ
from Message import Message
from zeiss import ZeissKeys
import WindowsRegistry

class WindowEventHandler(WindowAdapter):
	def __init__(self, closeFun = None):
		super(WindowAdapter, self).__init__()
		if closeFun is not None:
			self.closeFun = closeFun
			
	def windowClosing(self, event):
		self.closeFun()

class FileListener(FileAlterationListenerAdaptor):
	''' Define methods FileAlterationListenerAdaptor method run on file will be created at runTime'''
	def __init__(self, runOnFile = None, onlyNewFiles = True):
		super(FileListener, self).__init__()
		self.onlyNewFiles = onlyNewFiles
		if runOnFile:
			self.runOnFile = runOnFile

	def onFileChange(self, afile):
		'''run only for images that have been changed'''
		if ('.lsm' in str(afile) or '.czi'  in str(afile)) and not self.onlyNewFiles:
			print "Changed file " + str(afile)
			self.runOnFile(afile)
	
	def onFileCreate(self, afile):
		try:
			if ('.lsm' in str(afile) or '.czi'  in str(afile)):
				print "New file " + str(afile)
				self.runOnFile(afile)
		except BaseException, err:
			IJ.log(str(err))
	
	def onFileDelete(self, file):
		IJ.log("File " + str(file) + " has been deleted")
	
class DialogMonitor(object):
	''' general class for a fileListener dialog. It is used to define parameters of used by runOnFile. runOnFile will be defined by the child class '''
	
	__slots__ = ['frameMain', 'framePara', 'monitor', 'observer', 'listener', 'dirField', 'msgLabel1', 'msgLabel2']
	
	def __init__(self, macroName):
		#pollingTime should not be too short otherwise the system get confused. 50 ms
		self.pollingTime = 50
		#if an image is to be opened wait a delay of sec before opening it
		self.waitForImageOpening = 0.2
		self.outDir = None
		#Three classes used to specify the apache monitor
		self.monitor = None 
		self.listener = None
		self.observer = None
		#Setup of GUI
		#Gui fo parameters
		self.framePara = None
		#Main gui
		self.frameMain = JFrame('Run jython ' + macroName + ' on directory',
			defaultCloseOperation = JFrame.DISPOSE_ON_CLOSE,
			size = (300, 300)
		)
		self.frameMain.addWindowListener(WindowEventHandler(self.close))
		pane = self.frameMain.getContentPane()
		
		panel = JPanel()
		panel.setLayout(BoxLayout(panel, BoxLayout.LINE_AXIS))
		panel.setBorder(BorderFactory.createTitledBorder("Directory to monitor"))


		self.dirField = JTextField('',50)
		panel.add(self.dirField)
		
		panel.add(JButton('...', actionPerformed=self.open_folder))
		self.onlyNewFiles = JCheckBox('analyze only new files', actionPerformed = self.restart)
		panel.add(self.onlyNewFiles)
		self.onlyNewFiles.getModel().setSelected(True)
		pane.add(panel,  BorderLayout.NORTH)
		
		panel = JPanel()
		panel.setLayout(BoxLayout(panel, BoxLayout.LINE_AXIS))
		panel.add(Box.createHorizontalGlue())
		
		panel.setBorder(BorderFactory.createTitledBorder("Commands"))
		
		self.ButtonStart = JButton('Start', actionPerformed=self.start)
		self.ButtonStop = JButton('Stop', actionPerformed=self.stop)
		self.ButtonRunOnDir = JButton('RunOnDir', actionPerformed = self.buttonRunOnDir)
		
		panel.add(JButton('Parameters', actionPerformed=self.setupPara))
		
		panel.add(self.ButtonRunOnDir)
		panel.add(self.ButtonStart)
		panel.add(self.ButtonStop)
		self.activateButtons(0)
		self.ButtonStop.setEnabled(False)
		pane.add(panel,   BorderLayout.CENTER)

		
		panel = JPanel()
		panel.setLayout(BoxLayout(panel, BoxLayout.PAGE_AXIS))
		panel.add(Box.createHorizontalGlue())
		panel.setBorder(BorderFactory.createTitledBorder("Analyze results saving"))
		self.noSave = JRadioButton("Do not save results");
		self.saveLocally = JRadioButton("Save in \AnalyzeIJ below the image directory");
		self.saveGlobally = JRadioButton("Save in \AnalyzeIJ below monitored directory");
		bG = ButtonGroup()
		panel.add(self.noSave)
		panel.add(self.saveLocally)
		panel.add(self.saveGlobally)
		self.saveGlobally.getModel().setSelected(True)
		bG.add(self.noSave)
		bG.add(self.saveLocally)
		bG.add(self.saveGlobally)
		pane.add(panel,  BorderLayout.LINE_START)
		
		panel =  JPanel(GridLayout(4,1))
		panel.setBorder(BorderFactory.createTitledBorder("Monitor Status"));
		panel.add(JLabel("Monitoring:", SwingConstants.LEFT))
		
		self.msgLabel1 = JLabel("", SwingConstants.LEFT)
		panel.add(self.msgLabel1)
		panel.add(JLabel("Latest file:", SwingConstants.LEFT))
		self.msgLabel2 = JLabel("", SwingConstants.LEFT)
		
		panel.add(self.msgLabel2)
		pane.add(panel,   BorderLayout.PAGE_END)
		
		self.frameMain.pack()
		self.frameMain.visible = True
		
	def open_folder(self, event):
		indir = IJ.getDirectory("Choose the input directory")
		self.dirField.setText(indir)
		if self.monitor is not None:
			self.start(event)
		
	def openFile(self, filepath, imgPrefix, force = 0):
		'''openfile with img prefix and split channels returns Channel splitted ImageJ plus pixelSioze filepath and filaname'''
		nrtry = 0

		if filepath == '':
			od = OpenDialog("Choose image file", None)
			if od.getFileName() == None:
				return None
			filepath = os.path.join(od.getDirectory(), od.getFileName())
		filename = os.path.splitext(os.path.basename(filepath))
		# and ('.lsm' in filename or '.czi' in filename)

		if imgPrefix is not '' and imgPrefix in filename[0] and ('.lsm' == filename[1] or '.czi' == filename[1])  or force:
			IJ.run("Close All", "")
			IJ.run("Clear Results")
			#leave a little bit of time for ZEN to write before opening 
			time.sleep(self.waitForImageOpening)
			while nrtry < 4:
				try:
					images = BF.openImagePlus(filepath)
					nrtry = 4
				except FileNotFoundException, err:
					nrtry = nrtry + 1
					time.sleep(self.waitForImageOpening)
					if nrtry == 4:
						raise IOError('Failed to access file ' + str(filepath) + '. ' + str(err))
			#this opens also czi images
			image = images[0]
			if image is None:
				raise NameError('Fiji failed to open image ' + filepath)	
			pixelSize = image.getCalibration().pixelWidth
			IJ.run(image, "Set Scale...", "distance=0 known=0 pixel=1 unit=pixel")
			if image.getNChannels() > 1: 
					chSp = ChannelSplitter()
					imageC = chSp.split(image)
			else:
				imageC = [image.duplicate()]
			return [imageC, pixelSize, filepath, filename]
		else: 
			IJ.log("fileMonitoring.py: Nothing to do for " + filepath )
			return  None

	
	def getPrefix(self, pip, task):
		if 'AFS' in pip:
			return pip
		else:
			return pip + task + "_"
				
	def start(self, event):
		'''Start monitoring of a folder'''
		try:
			self.setSaving()				
			self.stopMonitor()
			self.outDir = None
			if not os.path.exists(self.dirField.getText()):
				IJ.showMessage("Directory " +  self.dirField.getText() + " does not exists!" )
				return
			if self.dirField.getText() == "":
				IJ.showMessage("You need to define a directory to monitor!" )
				return
				
			if self.onlyNewFiles.isSelected():
				IJ.showMessage("analyze only new files: On. \n Macro will analyze only new created image files!\n Be sure to have deleted all old images in monitored directory")

			self.saveStartParameters(event)
			self.observer = FileAlterationObserver(self.dirField.getText())
			#this is the polling time. If it is too short it will 
			self.monitor = FileAlterationMonitor(self.pollingTime)
			self.listener = FileListener(self.runOnFile, self.onlyNewFiles.isSelected())
			self.observer.addListener(self.listener)
			self.monitor.addObserver(self.observer)
			self.monitor.start()
			self.msgLabel1.setText(self.dirField.getText())
			self.activateButtons(0)
			self.ButtonStop.setEnabled(1)
		except BaseException, err:
			print str(err)

	def close(self):
		try:
			if self.monitor is not None:
				self.monitor.stop()
		except:
			IJ.log("not able to dispose")
		self.frameMain.dispose()
		self.frameMain = None
		IJ.log("Monitors disposed")

	def restart(self, event):
		if self.monitor is not None:
			self.start(event)

	def stopMonitor(self):
		'''Stop monitoring of a folder'''
		if self.monitor is not None:
			self.monitor.stop()
			self.monitor.removeObserver(self.observer)
			self.observer.destroy()
			self.monitor = None
			
	def stop(self, event):
		'''stop monitoring and reactivate buttons'''
		self.stopMonitor()
		self.activateButtons(1)
		self.msgLabel1.setText("")

	def runOnFile(self, file, show = True, jobnr = None):
		'''executed on new files or modified image files. To be defined in child class'''
		IJ.log('No method runOnFile has been defined, just open the image')
		imageDef = self.openFile(file, '', 1)
		print imageDef
		if imageDef is not None:
			[imageC, pixelSize, filepath, filename] = imageDef
		imageC[0].show()
		
	def buttonRunOnDir(self, event):
		self.ButtonStop.setEnabled(1)
		self.ButtonStart.setEnabled(0)
		self.msgLabel1.setText("Stop runOnDir by pressing stop-button or ESC-key on Fiji Window")
		Thread(target=self.runOnDirThread).start()

	def setSaving(self):
		if self.noSave.isSelected():
			self.saving = 0
		if self.saveLocally.isSelected():
			self.saving = 1
		if self.saveGlobally.isSelected():
			self.saving = 2
		return self.saving	
	
	def runOnDirThread(self):
		self.setSaving()
		inDir = IJ.getDirectory("Choose the input directory")
		if self.saving == 2:
			self.outDir = IJ.getDirectory("Choose output directory for results")
			
		IJ.resetEscape();
		self.activateButtons(0)
		self.ButtonStop.setEnabled(1)
		for root, dirs, files in os.walk(inDir, topdown = False):
			for i, afile in enumerate(files):
				self.runOnFile(os.path.join(root,afile), False)
				IJ.showStatus("Files left to analyze in subdirectory " + str(len(files)-i) +" (press esc to abort)")
				IJ.log( str(self.ButtonStop.getModel().isPressed()))
				if not self.ButtonStop.getModel().isEnabled() or IJ.escapePressed():
					self.activateButtons(1)
					self.outDir = None
					return
		self.outDir = None
	
	def buttonRunOnFile(self, event):
		try:
			self.getParameters()
			self.saving = 0
			Thread(target = self.runOnFile, args = ('', 1, int(event.getSource().getClientProperty("job")))).start()
		except Exception, err:
			IJ.log('error ' + str(err))

	
	def saveStartParameters(self, event):
		IJ.log('No method saveParameters has been defined')
		
	def setupPara(self, event):
		'''executed to define parameters used by runOnFile'''
		IJ.log("No method defined to setup macro")


		
	def activateButtons(self, state):
		self.ButtonStart.setEnabled(state)
		self.ButtonStop.setEnabled(0)	
		self.ButtonRunOnDir.setEnabled(state)

	def saveOutputImg(self, image, filepath, ijob):
		IJ.log("Starts saving")
		if not self.saving:
			return
		if image is not None:
			if self.saving == 1:
				analyzeDir = os.path.join(os.path.dirname(filepath), 'AnalyzeIJ')
			if self.saving == 2:
				if self.outDir is None:
					if not os.path.isdir(self.dirField.getText()):
						return
					analyzeDir = os.path.join(self.dirField.getText(), 'AnalyzeIJ')
				else:
					analyzeDir = os.path.join(self.outDir, 'AnalyzeIJ')
			if not os.path.isdir(analyzeDir):
				os.makedirs(analyzeDir)
			fileout = os.path.join(analyzeDir, os.path.splitext(os.path.basename(filepath))[0] + '_job' + str(ijob))
			IJ.saveAs(image, "Jpeg", fileout)
		else:
			IJ.log("Can't save output as no output image has been created")
		IJ.log("Ends saving")


class DialogParameters(DialogMonitor):
	'''Specify extra methods to manage parameters and different jobs'''
	#Contains description of paramters and possible values
	COMBO_FIELDS =  dict(pip=[['Image'],['None', 'Autofocus', 'Acquisition', 'Alt. acquisition',  'Trigger1', 'Trigger2']],
		  channel=[['channel'],["1", "2", "3", "4"]],
		  command=[['Command'], ["nothing", "focus", "trigger1", "tigger2", "fcs", "focus; fcs"]], 
		  seg_method=[['Seg. method'], ["Default", "Triangle", "Li", "Entropy"]], 
		  filter_rad=[['filer radius (px)'],[2]], 
		  area_max=[['Maximal size(um2)'],[2000]], 
		  area_min=[['Minimal size'], [200]], 
		  fcs_inside=[['FCS pts. inside obj.'],['0','1','2','3']], 
		  fcs_outside=[['FCS pts. outside obj.'],['0','1','2','3']])
	#order in which parameters should be shown
	COMBO_ORDER = ['pip', 'channel', 'command', 'seg_method', 'filter_rad', 'area_max', 'area_min', 'fcs_inside', 'fcs_outside'];
	COMBO_SEPARATOR = [2, 6]
	JOBS_DICT = {'None':'', 'Autofocus' : 'AF', 'Acquisition': 'AQ', 'Alt. acquisition': 'AL', 'Trigger1': 'TR1', 'Trigger2': 'TR2'}
	nrOfJobs = 2
	nrSeparators = 2
	def __init__(self, macroName = None):
		self.jobs = None
		self.macroName = macroName
		super(DialogParameters, self).__init__(self.macroName) #create dialogBox for super class
		
	def setupPara(self, event):
		''' create a dialogBox to enter and change parameters. Parameter are then saved in jobs'''
		try:
			self.framePara = JFrame('Parameters for ' + self.macroName,
				defaultCloseOperation = JFrame.DISPOSE_ON_CLOSE,
				size = (400, 400)
			)
			pane = self.framePara.getContentPane()
			jobPanel = JPanel(GridLayout(0,self.nrOfJobs+1))
			panel = JPanel(GridLayout(len(self.COMBO_FIELDS)+2+self.nrSeparators,0))
			
			panel.add(JLabel("", SwingConstants.RIGHT))
			
			for j, key in enumerate(self.COMBO_ORDER):
				panel.add(JLabel(self.COMBO_FIELDS[key][0][0], SwingConstants.RIGHT))
				if any(iSep == j for iSep in self.COMBO_SEPARATOR ) and self.nrSeparators > 0:
					panel.add(JSeparator(SwingConstants.HORIZONTAL))
			jobPanel.add(panel)

			#make entries for parameters
			print self.jobs
			for i in range(0, self.nrOfJobs):
				panel = JPanel(GridLayout(len(self.COMBO_FIELDS)+2+self.nrSeparators,0))
				panel.add(JLabel("Job"+str(i+1), SwingConstants.CENTER))

				panelEntries = self.getPanelEntries()
				try:
					self.updateGui(panelEntries, self.jobs[i])
				except:
					self.updateGui(panelEntries, self.jobs)
				for entry in panelEntries:
					panel.add(entry)
				button = JButton('Run on file', actionPerformed = self.buttonRunOnFile)
				button.putClientProperty("job", i)
				panel.add(button)
				jobPanel.add(panel)
			
			pane.add(jobPanel, BorderLayout.NORTH)
			panel = JPanel(GridLayout(0,3))
			#three buttons
			
			panel.add(JButton('Load Para', actionPerformed = self.loadParameters))
			
			panel.add(JButton('Save Para', actionPerformed = self.saveParameters))
			
			panel.add(JButton('OK', actionPerformed = self.buttonOK))
			pane.add(JSeparator(), BorderLayout.CENTER)
			pane.add(Box.createRigidArea(Dimension(0,50)))
			pane.add(panel, BorderLayout.EAST)
			self.framePara.pack();

			self.framePara.visible = True
			if self.jobs is not None:
				print all([job['pip']=='None' for job in self.jobs])
				if self.monitor is None:
					self.activateButtons(not all([job['pip']=='None' for job in self.jobs]))

			
		except BaseException, err:
			print(err)
	
	def getPanelEntries(self):
		panelEntries = []
		for j, key in enumerate(self.COMBO_ORDER):
			value = self.COMBO_FIELDS[key]
			#create a comboBox if several entries are give
			if len(value[1]) > 1:
				panelEntries.append(JComboBox(value[1]))
				#, actionListener = self.JCBoxEvent())) gives problems when we try to access it
			else:
				panelEntries.append(JTextField(str(value[1][0]), 4))
			if any(iSep == j for iSep in self.COMBO_SEPARATOR ) and self.nrSeparators>0:
				panelEntries.append(JSeparator(SwingConstants.HORIZONTAL))
		return panelEntries

	class JCBoxEvent(ActionListener):
		def actionPerformed(self, event):
			IJ.log("Nothing implemented yet")
		
	def updateGui(self, panelEntries, jobs):
		try:
			if jobs is None:
				return
			iPara = 0
			for item in enumerate(panelEntries):
				if item[1].getUIClassID() == 'SeparatorUI':
					continue
				key = self.COMBO_ORDER[iPara]
				value = self.COMBO_FIELDS[key]
				if item[1].getUIClassID() == 'ComboBoxUI':
					item[1].setSelectedIndex(value[1].index(str(jobs[key])))
				if item[1].getUIClassID() == 'TextFieldUI':
					item[1].setText(str(jobs[key]))
				iPara += 1
		except Exception:
			IJ.showMessage(" jobs variable does not contains the parameters for this macro!" )

	def loadParameters(self, event):
		IJ.log("No definition")
		od = OpenDialog("Load parameter file", None, "*.ini")
		fin = open(os.path.join(od.getDirectory(), od.getFileName()),"rb")	
		try:
			jobs = pickle.load(fin)
			if jobs is not None:
				for job in jobs:
					self.updateGui(self.getPanelEntries(), job)
			self.jobs = jobs
			self.framePara.dispose()
			self.framePara = None
			self.setupPara('')
		except:
			IJ.showMessage(os.path.join(od.getDirectory(), od.getFileName()) + " is not a parameter file for this macro!" )
		finally:
			fin.close()

	def saveStartParameters(self, event):
		fout = open(os.path.join(self.dirField.getText(), self.macroName + '.ini'), 'wb')
		pickle.dump(self.jobs, fout)
		fout.close()


	def saveParameters(self, event):
		try:
			od = SaveDialog("Save parameter file", None, self.macroName + '.ini', '')
			fout = open(os.path.join(od.getDirectory(), od.getFileName()), 'wb')
			self.getParameters()
			pickle.dump(self.jobs, fout)
			fout.close()
		except Exception,  err:
			print err

	def buttonOK(self, event):
		self.getParameters()
		if self.jobs is not None:
			print all([job['pip']=='None' for job in self.jobs])
			if self.monitor is None:
				self.activateButtons(not all([job['pip']=='None' for job in self.jobs]))
		self.framePara.dispose()
		self.framePara = None
	
	def exitWithError(self, errMsg):
		zk = ZeissKeys()
		msg = Message()
		IJ.run("Read Write Windows Registry", "action=write location=[HKCU\\"+zk.regkey+"] key="+zk.subkey_errormsg+" value=["+errMsg+"] windows=REG_SZ")
		IJ.run("Read Write Windows Registry", "action=write location=[HKCU\\"+zk.regkey+"] key="+zk.subkey_codemic+" value=["+msg.CODE_ERROR+"] windows=REG_SZ")
		#Can also use
		#WindowsRegistry.writeRegistry("HKCU\\"+zk.regkey, zk.subkey_errormsg, errMsg)
		#WindowsRegistry.writeRegistry("HKCU\\"+zk.regkey, zk.subkey_codemic, msg.CODE_ERROR)

		
	def getParameters(self):
		'''read parameters from framePara and store them in a variable'''
		try:
			jobs = []
			panelJobs = self.framePara.getContentPane().getComponents()[0]
			for i in range(0, self.nrOfJobs):
				ajob = dict()
				panel = panelJobs.getComponents()[i+1]
				#print [item.getSelectedItem()  for item in  panel.getComponents()]
				ipanel = 0
				for item in panel.getComponents()[1:]:
					if item.getUIClassID() == 'ComboBoxUI':
						ajob[self.COMBO_ORDER[ipanel]] = str(item.getSelectedItem())
					if item.getUIClassID() == 'TextFieldUI':
						try:
							ajob[self.COMBO_ORDER[ipanel]] = float(item.getText())
						except ValueError:
							ajob[self.COMBO_ORDER[ipanel]] = item.getText()
					if item.getUIClassID() == 'SeparatorUI':
						continue
					ipanel += 1
				jobs.append(ajob)
			self.jobs = jobs
			if self.monitor is None:
				self.activateButtons(not all([job[0]=='None' for job in self.jobs]))
			
		except BaseException, err:
			IJ.log(str(err))
			traceback.print_exc()

if __name__=="__main__":
	DialogParameters('Test')