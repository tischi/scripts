#
#Macro to segment blobs and choose the nuclei that contains territories
#
from trainableSegmentation import WekaSegmentation
from fiji.threshold import Auto_Local_Threshold
from ij.plugin.filter import Analyzer
from random import randint
import traceback
import re
import math
import sys
import warnings
from threading import Thread
from ij.plugin import RGBStackMerge
from ij import IJ, ImagePlus, ImageStack 
from ij.plugin import ImageCalculator, ChannelSplitter
from ij.plugin import Duplicator
import segment_Particles
from ij.plugin import ZProjector, Slicer
from ij.plugin.frame import RoiManager
from ij.measure import Measurements
from ij.io import Opener
from ij.io import FileInfo
from ij.io import OpenDialog
import embl.almf.WindowsRegistry as WindowsRegistry
import automatedImgTools as autTool
#from embl.almf import WindowsRegistry #this does not work?? I can't access the methods
import sys
import os.path
import time
import copy
import random
from loci.plugins import BF
from ij.plugin import ZProjector

from ij.gui import ImageWindow
from javax.swing import (BoxLayout,	ImageIcon, JButton, JFrame, JPanel,
	JPasswordField, JLabel, JTextArea, JTextField, JScrollPane,
	SwingConstants, WindowConstants, SpringLayout, Box, JComboBox, JSeparator, SwingUtilities)
from java.awt import Component, GridLayout, BorderLayout, Dimension, Container, Color
from java.awt.event import ActionListener, WindowAdapter
from loci.plugins import BF
from Message import Message
from zeiss import ZeissKeys
import fileMonitoring
from fileMonitoring import DialogParameters
from org.apache.commons.io.monitor import FileAlterationListener, FileAlterationListenerAdaptor, FileAlterationMonitor, FileAlterationObserver
from java.awt.event import MouseAdapter
from threading import Thread
from java import lang



class locDialogParameters(DialogParameters, ActionListener):
	COMBO_FIELDS = dict(pip=[['Pipeline'],['None', 'Default',	'Trigger1' , 'Trigger2']],
			task = [['Img. Task'],	 ["1", "2", "3", "4", "5"]],
				channel=[['Channel'],["1", "2", "3", "4"]],
				command=[['Command'], ["nothing",	"trigger1", "trigger2", "setFcsPos", "focus"]], 
				clspath = [["Classifier path"], ["C:/Users/toni/Code/AutomatedMicroscopy/IJMacros/WekaPipeline/classifier.model"]],		
				nrPart = [["Min. # Particles"], [1]],
				minProb = [["Mean prob. value for obj"],[0.8]],		# Background subtract
				maxCirc=[["Max. Circularity"],[0.8]], 
				probThr = [["Prob. Threshold"], [0.6]])
	COMBO_ORDER = ['pip', 'task',	'channel', 'command', 	'clspath', 'nrPart', 'minProb', 'maxCirc', 'probThr']
	COMBO_SEPARATOR = [3]
	JOBS_DICT = {'None':'', 'Default' : 'DE_', 'Trigger1': 'TR1_', 'Trigger2': 'TR2_'}
	nrOfJobs = 2
	nrSeparators = len(COMBO_SEPARATOR)
	rois = [None]*nrOfJobs
	Segs = [None]*nrOfJobs
	Procs = [None]*nrOfJobs
	
	def __init__(self, macroname):
		super(locDialogParameters, self).__init__(macroname)
	
	def runOnFile(self, afile, show = True, jobnr = None):
		afile = str(afile)
		if afile == '' or afile is None:
			od = OpenDialog("Choose image file", None)
			if od.getFileName() == None:
				return
			afile = os.path.join(od.getDirectory(), od.getFileName())
		if '.log' in afile:
			return
		
		try:
			zk = ZeissKeys()
			msg = Message()
			print "Hi"
			if self.jobs is None:
				IJ.showMessage("You need to first set the parameters")
			
			if all([job['pip']=='None' for job in self.jobs]):
				IJ.showMessage("Nothing to do! At least on job different than None") 
				return 0
			
			#create a copy otherwise self.jobs gets overwritten
			jobs = copy.deepcopy(self.jobs)
			random.seed()
			
			#create a roiManager in case one is missing and reset it
			roim = RoiManager.getInstance()
			if roim == None:
				roim = RoiManager()
			roim.runCommand("reset")
			
			for i, job in enumerate(self.jobs):
				jobl = job #not really necessary
				if jobl['pip'] == 'None':
					continue
				self.JOBS_DICT[jobl['pip']] + jobl['task'] + "_" 
				
				if jobnr is not None:
					if jobnr == i:
						#force opening
						imageDef = self.openFile(afile, self.getPrefix(self.JOBS_DICT[jobl['pip']], jobl['task']), 1)
					else: 
						continue
				else:
					imageDef = self.openFile(afile, self.getPrefix(self.JOBS_DICT[jobl['pip']], jobl['task']))
				print imageDef
				jobl['channel'] = int(jobl['channel'])
				
				if imageDef is None:
					continue
				#clean up registry for errors
				IJ.log("Clean up errorMsg registry")
				IJ.run("Read Write Windows Registry", "action=write location=[HKCU\\"+zk.regkey+"] key="+zk.subkey_errormsg+" value=[""] windows=REG_SZ")
				
				[imageC, pixelSize, filepath, filename] = imageDef
				if jobl['channel'] > len(imageC):
					raise IOError('Expecting at least ' + str(jobl['channel']) + ' channels. Image has only ' + str(len(imageC)) + ' channel(s)')
				
				self.rois = [None]*self.nrOfJobs
				self.Segs = [None]*self.nrOfJobs
				self.Procs = [None]*self.nrOfJobs
				#switch color to Cyan for better visibility
				IJ.run(imageC[jobl['channel']-1], "Cyan", "")

				#segment
				self.Procs[i], self.Segs[i], validParticles, self.rois[i] = segmentChannel_Weka(imageC, **jobl)
				if validParticles is None:
					IJ.run("Read Write Windows Registry", "action=write location=[HKCU\\"+zk.regkey+"] key="+zk.subkey_codemic+" value=["+msg.CODE_NOTHING+"] windows=REG_SZ")

				#write values to registry
				try:
					executeTask_Weka(validParticles, **jobl)
				except Exception, err:
					self.exitWithError(str(err))
					return
				
				if self.rois[i] is None:
					imageC[jobl['channel']-1].show()
					self.Segs[i].show()
					self.Procs[i].show()
					continue
				if validParticles is None:
					particle = []
				else:
					particle = [part[0] for part in validParticles]
				imgOut = autTool.createOutputImg(imageC[jobl['channel']-1], self.rois[i], particle)
				
				imgOut.show()	
				self.saveOutputImg(imgOut, filepath, i+1)			
				
			IJ.run("Collect Garbage", "")

		except BaseException, err:
			self.exitWithError(str(err))


def extractChannel(imp, nChannel, nFrame):
  	""" Extract a stack for a specific color channel and time frame """
	stack = imp.getImageStack()
	ch = ImageStack(imp.width, imp.height)
	for i in range(1, imp.getNSlices() + 1):
		index = imp.getStackIndex(nChannel, i, nFrame)
		ch.addSlice(str(i), stack.getProcessor(index))
	return ImagePlus("Channel " + str(nChannel), ch)

def threshold(imp, threshold):
	""" Threshold image """
	impout = Duplicator().run(imp)
	IJ.setThreshold(impout, threshold, 1000000000)
	IJ.run(impout, "Convert to Mask", "stack")
	impout.setTitle("Threshold");
	return impout


	
def segmentChannel_Weka(image, **kwargs):
	""" SegmentChannel using a Weka Classification"""
	ch = kwargs['channel']
	if ch > len(image): 
		raise Exception('Expecting at least ' + str(ch) + ' channels. Image has only ' + str(len(imageC)) + ' channel(s)')
	imp = image[ch-1].duplicate()
	ws = WekaSegmentation(imp)	# create an instance
	ws.loadClassifier(kwargs['clspath']) # load classifier
	impProb  = ws.applyClassifier(imp, 0, True)
	impMetaProb = extractChannel(impProb,1,1)
	impMetaProb.setTitle("MetaProb")
	# segmentation
	impBW = threshold(impMetaProb, kwargs['probThr'])
	impMetaProb.show()
	IJ.run("Set Measurements...", " mean center shape area redirect=MetaProb decimal=2");
	
	# particle analysis
	IJ.run(impBW, "Analyze Particles...", "size=10-10000 pixel area circularity=0.00-1.00 display exclude clear stack add");
	rt = Analyzer.getResultsTable()
	validParticles = []
	roim = RoiManager.getInstance()
	if roim == None:
		raise Exception('Fiji error segmentNuclei.py: no RoiManager!')
	if roim.getCount() > 0:
		rois = roim.getRoisAsArray()
	else:
		IJ.log("# particles = 0")
		return impMetaProb, impBW, None, None
	X = rt.getColumn(rt.getColumnIndex("XM"))
	Y = rt.getColumn(rt.getColumnIndex("YM"))
	Mean = rt.getColumn(rt.getColumnIndex("Mean"))
	Circ = rt.getColumn(rt.getColumnIndex("Circ."))
	Area = rt.getColumn(rt.getColumnIndex("Area"))
	print "# particles = " + str(len(Mean))
	for i in range(len(Mean)):
		valid = (Mean[i]>kwargs['minProb']) and (Circ[i]<kwargs['maxCirc']) # filter particles post detection
		if(valid):
			validParticles.append([i, X[i], Y[i]])
	random.shuffle(validParticles)
	IJ.log("# valid particles = %d " % len(validParticles))
	if len(validParticles) == 0:
		validParticles = None
	return impMetaProb, impBW, validParticles, rois
		
def executeTask_Weka(validParticles, **kwargs):
	'''execute task for microscope'''
	zk = ZeissKeys()
	msg = Message()
	if validParticles is None or len(validParticles) < kwargs["nrPart"]:
		IJ.run("Read Write Windows Registry", "action=write location=[HKCU\\"+zk.regkey+"] key="+zk.subkey_codemic+" value=["+msg.CODE_NOTHING+"] windows=REG_SZ")
		return validParticles
	random.shuffle(validParticles)
	if kwargs['command'] != 'nothing':
		autTool.writePositionToRegistry([[part[1], part[2]] for part in validParticles[0:int(kwargs["nrPart"])]])
	IJ.run("Read Write Windows Registry", "action=write location=[HKCU\\"+zk.regkey+"] key="+zk.subkey_codemic+" value=["+kwargs['command']+"] windows=REG_SZ")
	return validParticles

test = 0



if test ==0:
	locDialogParameters('Weka_Metaphase_Detection')
	
if test ==1 :
	IJ.run("Close All", "");
	roim = RoiManager.getInstance()
	if roim == None:
		roim = RoiManager()
	
	roim.runCommand("reset");
	imagePath =	r"C:\Users\toni\Code\AutomatedMicroscopy\IJMacros\WekaPipeline\TestImage_1024.tif"
	imp = IJ.openImage(imagePath)
	imp.show()
	kwargs={'pip':'Default', 'task':1, 'channel':1, 'command':"trigger1", 'clspath':"C:\\Users\\toni\\Code\\AutomatedMicroscopy\\IJMacros\\WekaPipeline\\classifier.model", 'nrPart':3, 
	'Min Intensity':0.8, 'maxCirc': 0.8, 'probThr':0.6}
	
	procs, segs, validParticles, rois =  segmentChannel_Weka([imp], **kwargs)
	executeTask_Weka(validParticles,  **kwargs)
	particle = [part[0] for part in validParticles]
	print particle
	imgOut = autTool.createOutputImg(imp, rois, particle)



