#
#Macro to segment blobs and choose the best nuclei (closest to the center)
#

from ij import IJ
from ij import ImagePlus
from ij.plugin import Duplicator
import segment_Particles
from ij.plugin import ChannelSplitter
from ij.plugin import ZProjector
from ij.plugin.frame import RoiManager
from ij.measure import Measurements
from ij.io import Opener
from ij.io import FileInfo
from ij.io import OpenDialog
#from embl.almf import WindowsRegistry #this does not work?? I can't access the methods
import os.path
import time

from Message import Message
from zeiss import ZeissKeys

print "Main"
def run():
	zk = ZeissKeys()
	msg = Message()
	timestart = time.clock()
	channel = 1
	#size in um2
	minArea = 20 
	maxArea = 200
	maxMetaArea = 70
	minMetaAR = 1.8
	method = "Triangle"
	print "Enter run"
	detectionNucleus = [minArea, maxArea]
	detectionMetaphase = [minArea, maxMetaArea]
	filepath = ""
	try:			 
		filepath  = getArgument()
		image = IJ.openImage(filepath) #arguments provided by runMacro
	except NameError:
		try: 
			filepath = newImagePath  #argument provided by the macroRunner
		except NameError: #no file name specified
			errMsg = "Fiji error segmentNuclei.py: no filepath has been passed to the macro"
			exitWithError(errMsg)
			od = OpenDialog("Choose image file", None)
			if od.getFileName() == None:
				return
			filepath = os.path.join(od.getDirectory(), od.getFileName())
	
	# A roimanager is recquired
	roim = RoiManager.getInstance()
	if roim == None:
		roim = RoiManager()
	#test a last time
	if roim == None:
		print 'Fiji error segmentNuclei.py: no RoiManager!'
		exitWithError('Fiji error segmentNuclei.py: no RoiManager!')
		
	try:	
		IJ.run("Close all forced")
		IJ.run("Clear Results")
		IJ.log("\\Clear")
		image = IJ.openImage(filepath)
		IJ.log("File Path  " + filepath)
		
		try: 
			image.hide()
		except: 
			image = IJ.getImage()
			image.hide()
		image.show()	
		if image is None:
			exitWithError("Fiji failed to open image")
			return 0 

		#convert um2 to pixels
		pixelSize = image.getCalibration().pixelWidth
		detectionNucleus = [area/pixelSize/pixelSize for area in detectionNucleus]
		detectionMetaphase = [area/pixelSize/pixelSize for area in detectionMetaphase]
		detectionMetaphase.append(minMetaAR)
		
		title = image.getTitle()
		
		imageC = None
		#split colors if needed
		if image.getNChannels() > 1: 
			chSp = ChannelSplitter()
			imageC = chSp.split(image)
			imageSeg = imageC[channel-1].duplicate()
		else: 
			imageSeg = image.duplicate()
		
		imageSeg.setTitle("SEG_"+title)

				
		sp = segment_Particles()
		imageSeg = sp.preprocessImage(imageSeg, "MAX", "C1", 2, 2)
		imageSeg = sp.segmentParticles(imageSeg, method, detectionNucleus[0], detectionNucleus[1], 2, 2)


		roim = RoiManager.getInstance()
		if roim == None:
			print 'Fiji error segmentNuclei.py: no RoiManager!'
			exitWithError('Fiji error segmentNuclei.py: no RoiManager!')

		#compute central object
		if roim.getCount() > 0:
			centPart, msg.position = centerParticle(imageSeg, roim)
			msg.position = msg.position + (focusParticle(image, roim, centPart),)
			writePositionToRegistry(msg.position)
		else:
			IJ.run("Read Write Windows Registry", "action=write location=[HKCU\\"+zk.regkey+"] key="+zk.subkey_codemic+" value=["+msg.CODE_NOTHING+"] windows=REG_SZ")
			return 0
		#create output image
		if imageC is None:
			impOut = createOutputImg(image, roim, centPart, 0)
		else:
			impOut = createOutputImg(imageC[channel-1], roim, centPart, 0)
		impOut.show()

		#save outut image
		#saveOutputImg(impOut, filepath, 'Analyzed')

		#check for roi properties to identofy metaphase
		metaphase = isSpecialParticle(image, roim, centPart,detectionNucleus, detectionMetaphase,pixelSize, msg.position[2])
		if os.path.basename(filepath).startswith('TR1_') or '_TR1_' in  os.path.basename(filepath):
			metaphase = 0
		if metaphase:
			IJ.run("Read Write Windows Registry", "action=write location=[HKCU\\"+zk.regkey+"] key="+zk.subkey_codemic+" value=["+msg.CODE_TRIGGER1+"] windows=REG_SZ")
		else:
			IJ.run("Read Write Windows Registry", "action=write location=[HKCU\\"+zk.regkey+"] key="+zk.subkey_codemic+" value=["+msg.CODE_FOCUS+"] windows=REG_SZ")

		IJ.log("time focus " + str(time.clock() - timestart))
		IJ.run("Collect Garbage")
		
		#IJ.run("Close all forced")
		#IJ.run("Clear Results")
		
	except BaseException, err:
		errMsg = "Fiji error segmentNuclei.py for " + filepath + " " + str(err)
		exitWithError(errMsg)
		print errMsg
	except:
		errMsg = "Unexpected Fiji error segmentNuclei.py " + filepath
		exitWithError(errMsg)

def writePositionToRegistry(position):
	zk = ZeissKeys()
	IJ.run("Read Write Windows Registry", "action=write location=[HKCU\\"+zk.regkey+"] key="+zk.subkey_xpos+" value=["+str(position[0])+"] windows=REG_SZ")
	IJ.run("Read Write Windows Registry", "action=write location=[HKCU\\"+zk.regkey+"] key="+zk.subkey_ypos+" value=["+str(position[1])+"] windows=REG_SZ")
	if len(position) > 2:
		IJ.run("Read Write Windows Registry", "action=write location=[HKCU\\"+zk.regkey+"] key="+zk.subkey_zpos+" value=["+str(position[2])+"] windows=REG_SZ")

def saveOutputImg(impOut, filepath, diranalyzed):
	if impOut is not None:
			analyzeDir = os.path.join(os.path.dirname(filepath), diranalyzed)
			if not os.path.isdir(analyzeDir):
				os.makedirs(analyzeDir)
			fileout = 	os.path.join(analyzeDir, os.path.basename(filepath))	
			IJ.saveAs(impOut, "Jpeg", fileout)

def createOutputImg(image, roim, centPart, metaphase):
	#maximal projection
	imp = image
	if image.getNSlices() > 1:
		zp = ZProjector()
		zp.setMethod(zp.MAX_METHOD)
		zp.setImage(image)
		zp.doProjection()
		imp = zp.getProjection()
	else:
		imp = image
	IJ.run(imp,"Enhance Contrast", "saturated=0.35")
	IJ.setForegroundColor(255,0,0)
	#need to show the image to draw overlay
	imp.show()
	IJ.run(imp,"RGB Color", "");
	for i in range(roim.getCount()):
		roim.select(imp, i)
		roim.runCommand("Draw")
	if metaphase:
		IJ.setForegroundColor(0,255,255)
	else:
		IJ.setForegroundColor(0,255,0)	
	roim.select(imp, centPart)
	roim.runCommand("Draw")
	imp.updateAndDraw()
	return imp

def exitWithError(errMsg):
	zk = ZeissKeys()
	msg = Message()
	IJ.run("Read Write Windows Registry", "action=write location=[HKCU\\"+zk.regkey+"] key="+zk.subkey_codemic+" value=["+msg.CODE_ERROR+"] windows=REG_SZ");
	IJ.run("Read Write Windows Registry", "action=write location=[HKCU\\"+zk.regkey+"] key="+zk.subkey_errormsg+" value=["+errMsg+"] windows=REG_SZ");


def centerParticle(image, roim):
	"""find particle closest to the center"""
	distMin = image.width*image.width + image.height*image.height
	for i, roi in enumerate(roim.getRoisAsArray()):
		image.setRoi(roi)
		stats = image.getStatistics(Measurements.CENTROID)
		dist = pow(stats.xCentroid-(image.width-1)/2,2) + pow(stats.yCentroid-(image.height-1)/2,2)
		if dist < distMin:
			centPart = i
			x = stats.xCentroid
			y = stats.yCentroid
			distMin = dist
	return centPart, (x, y) 

def isSpecialParticle(image, roim, iParticle, boundariesNuc, boundariesMito, pixelSize, z):
	try:
		image.setSlice(int(round(z)))
		image2 = ImagePlus("slice",image.getProcessor())
		roim.select(image2, iParticle)
		image3 = Duplicator().run(image2);
		image3.show()
		sp = segment_Particles()
		image3 = sp.preprocessImage(image3, "MAX", "C1", 0, 0)
		image3 = sp.segmentParticles(image3, "Triangle", boundariesNuc[0], boundariesNuc[1], 0, 0)
		if roim.getCount() > 0:
			roim.select(image3, 0)
			stats = image3.getStatistics(Measurements.AREA + Measurements.SHAPE_DESCRIPTORS)
			IJ.log("Area (um2) " + str(stats.area*pixelSize*pixelSize) + "; Aspect Ratio " + str(stats.major/stats.minor))
			if stats.area > boundariesMito[0] and stats.area < boundariesMito[1] and stats.major/stats.minor > boundariesMito[2]:
				return 1
			else:
				return 0
	except BaseException, err:
		print str(err)
		print "error in isSpecialParticle"
		return 0
		
def focusParticle(image, roim, iParticle):
	"""compute weighted mean of roi along z-direction"""
	meanInt = []
	sliceVal = []
	prod = []
	roim.select(image, iParticle)
	print "focusParticle1"
	#measure each single slice
	if image.getNSlices() > 1:
		for i in range(1,image.getNSlices()+1):
			image.setSlice(i)
			stats = image.getStatistics(Measurements.MEAN)
			meanInt.append(stats.mean)
			sliceVal.append(i-1)
		#dot product
		print sliceVal
		minInt =  min(meanInt)
		print meanInt
		meanInt = [m-minInt for m in meanInt]
		for i in range(len(meanInt)):
			print i
			prod.append(meanInt[i]*sliceVal[i])
		#prod = [a*b for a,b in zip(meanInt, sliceVal)] does not work with macro_runner
		#weighted mean
		print prod
		print "focusParticle3"
		return sum([p/sum(meanInt) for p in prod])
	else:
		return 0
run()		
