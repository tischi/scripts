'''Module with tools to perform automated imaging'''
import traceback
import re
import math
import sys
import warnings
import random
from ij.plugin import RGBStackMerge
from ij import IJ
from ij import ImagePlus
from ij.plugin import ImageCalculator
from ij.plugin import Duplicator
import segment_Particles
from ij.plugin import ZProjector
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
from javax.swing import (BoxLayout,  ImageIcon, JButton, JFrame, JPanel,
	JPasswordField, JLabel, JTextArea, JTextField, JScrollPane,
	SwingConstants, WindowConstants, SpringLayout, Box, JComboBox, JSeparator)
from java.awt import Component, GridLayout, BorderLayout, Dimension, Container, Color
from java.awt.event import ActionListener, WindowAdapter

from Message import Message
from zeiss import ZeissKeys
from org.apache.commons.io.monitor import FileAlterationListener, FileAlterationListenerAdaptor, FileAlterationMonitor, FileAlterationObserver
from java.awt.event import MouseAdapter
from java.lang import Thread


class ML(MouseAdapter):
	mouseWasPressed = False;
	x = 0;
	y = 0;
	
	def mousePressed(self, event):
		canvas = event.getSource()
		#imp = canvas.getImage()
		p = canvas.getCursorLoc()
		self.mouseWasPressed = True
		IJ.log("mouse was clicked at:"+str(p.x)+" "+str(p.y))
		self.x = p.x
		self.y = p.y
		
	def getMouseStatus(self):
		return self.mouseWasPressed

class GetMouseClickCoordinates():
	pos = None
	def __init__(self, img):
		self.imp = img
	def run(self):
		IJ.resetEscape()
		IJ.setTool("point")
		listener = ML()
		self.imp.show()
		canvas = self.imp.getWindow().getCanvas()
		canvas.addMouseListener(listener)
		# wait for mouse click
		while((not listener.mouseWasPressed) and (not IJ.escapePressed())):
			Thread.sleep(200) # todo: how to make this better?
		canvas.removeMouseListener(listener)
		if IJ.escapePressed():
			IJ.log("command has been aborted")
		else:
			print listener.x, listener.y
			self.pos = [listener.x, listener.y]


def convertCoordToString(pts):
	'''convert a list of points (x,y,(z)) to a string separated by ;'''
	if pts is None or len(pts) == 0:
		xpos = ''
		ypos = ''
		zpos = ''
	else:
		xpos =  '; '.join([str(round(pt[0],2)) for pt in pts])
		ypos =  '; '.join([str(round(pt[1],2)) for pt in pts]) 
		if len(pts[0]) > 2:
			zpos =  '; '.join([str(round(pt[2],2)) for pt in pts])
		else:
			zpos = None
	return [xpos, ypos, zpos]

  	


def writePositionToRegistry(pts):
	'''write points which is a list of 2-3 elements to registry'''
	zk = ZeissKeys()
	coord =  convertCoordToString(pts)
	IJ.run("Read Write Windows Registry", "action=write location=[HKCU\\"+zk.regkey+"] key="+zk.subkey_xpos+" value=["+coord[0]+"] windows=REG_SZ")
	IJ.run("Read Write Windows Registry", "action=write location=[HKCU\\"+zk.regkey+"] key="+zk.subkey_ypos+" value=["+coord[1]+"] windows=REG_SZ")
	if coord[2] is not None:
		IJ.run("Read Write Windows Registry", "action=write location=[HKCU\\"+zk.regkey+"] key="+zk.subkey_zpos+" value=["+coord[2]+"] windows=REG_SZ")
	else:
		IJ.run("Read Write Windows Registry", "action=write location=[HKCU\\"+zk.regkey+"] key="+zk.subkey_zpos+" value=[""] windows=REG_SZ")

def writeFcsPositionToRegistry(pts, zFcs):
	'''write points coordinates, a list of 2-3 elements to registry FCS coordinates. If zFcs also pass zposition of pts'''
	zk = ZeissKeys()
	coord =  convertCoordToString(pts)
	IJ.run("Read Write Windows Registry", "action=write location=[HKCU\\"+zk.regkey+"] key="+zk.subkey_fcsx+" value=["+coord[0]+"] windows=REG_SZ")
	IJ.run("Read Write Windows Registry", "action=write location=[HKCU\\"+zk.regkey+"] key="+zk.subkey_fcsy+" value=["+coord[1]+"] windows=REG_SZ")
	if coord[2] is not None and zFcs:
		IJ.run("Read Write Windows Registry", "action=write location=[HKCU\\"+zk.regkey+"] key="+zk.subkey_fcsz+" value=["+coord[2]+"] windows=REG_SZ")
	else:
		IJ.run("Read Write Windows Registry", "action=write location=[HKCU\\"+zk.regkey+"] key="+zk.subkey_fcsz+" value=[""] windows=REG_SZ")

def randomParticle(image, roiArray):
	'''random pick a particle'''
	part = random.randint(0,len(roiArray)-1)
	image.setRoi(roiArray[part])
	stats = image.getStatistics(Measurements.CENTROID + Measurements.AREA + Measurements.ELLIPSE)
	return part, (stats.xCentroid, stats.yCentroid), stats.area, (stats.xCentroid, stats.yCentroid, stats.major, stats.minor, stats.angle)

		
def brightestParticle(image, roiArray):
	'''find particle closest to the center given roiArray and its ellipse'''
	distMin = image.width*image.width + image.height*image.height
	m = [0]
	for i, roi in enumerate(roiArray):
		image.setRoi(roi)
		stats = image.getStatistics(Measurements.CENTROID + Measurements.MEAN)
		if stats.mean > m:
			m = stats.mean
			part = i
			centroid = (stats.xCentroid, stats.yCentroid)
	
	
	return part, centroid


		
def centerParticle(image, roiArray):
	'''find particle closest to the center given roiArray and its ellipse'''
	distMin = image.width*image.width + image.height*image.height
	for i, roi in enumerate(roiArray):
		image.setRoi(roi)
		stats = image.getStatistics(Measurements.CENTROID)
		dist = pow(stats.xCentroid-(image.width-1)/2,2) + pow(stats.yCentroid-(image.height-1)/2,2)
		if dist < distMin:
			centPart = i
			x = stats.xCentroid
			y = stats.yCentroid
			distMin = dist
	image.setRoi(roiArray[centPart])
	stats = image.getStatistics(Measurements.AREA + Measurements.ELLIPSE)
	return centPart, (x, y), stats.area, (x, y, stats.major, stats.minor, stats.angle)

def getPtEllipse(elli, alpha, coeff):
	'''
	get pt on ellipse at angle alpha from main axis and times coeff
	elli = (xfocus, yfocus, major_total_size, minor_total_size, angle)
	alpha is in radiants
	'''
	beta = -elli[4] * (math.pi/180)
	try:
		X = int(elli[0] + coeff[0]*(elli[2]/2+coeff[1])*math.cos(alpha)*math.cos(beta) - coeff[0]*(elli[3]/2+coeff[1])*math.sin(alpha)*math.sin(beta))
		Y = int(elli[1] + coeff[0]*(elli[2]/2+coeff[1])*math.cos(alpha)*math.sin(beta) + coeff[0]*(elli[3]/2+coeff[1])*math.sin(alpha)*math.cos(beta))
	except:
		X = int(elli[0] + coeff*(elli[2]/2)*math.cos(alpha)*math.cos(beta) - coeff*(elli[3]/2)*math.sin(alpha)*math.sin(beta))
		Y = int(elli[1] + coeff*(elli[2]/2)*math.cos(alpha)*math.sin(beta) + coeff*(elli[3]/2)*math.sin(alpha)*math.cos(beta))
	return (X,Y)

def drawEllipse(ip, ellipse):
	'''
	draw ellipse
	ip is image processor
	ellipse = (xfocus, yfocus, major_total_size, minor_total_size, angle)
	'''
	beta = -ellipse[4] * (math.pi/180)
	PtEll = [getPtEllipse(ellipse, alpha*math.pi/180, 1) for alpha in range(0,360,2)]
	PtAxis = [getPtEllipse(ellipse, alpha, 1) for alpha in [0, math.pi, math.pi/2, 3*math.pi/2]]
	ip.moveTo(PtEll[0][0], PtEll[0][1])
	for pt in PtEll[1:]:
		ip.lineTo(pt[0],pt[1])
	ip.drawLine(PtAxis[0][0], PtAxis[0][1], PtAxis[1][0], PtAxis[1][1])
	ip.drawLine(PtAxis[2][0], PtAxis[2][1], PtAxis[3][0], PtAxis[3][1])
	return ip

def focusParticle(imageC, channel, roi, method = 'mean'):
	"""compute weighted mean or peak of roi along z-direction for a given channel"""
	meanInt = []
	sliceVal = []
	prod = []
	if channel > len(imageC):
		raise IOError('Expecting at least ' + str(channels[jobNr]) + ' channels. Image has only ' + str(len(imageC)) + ' channels')
	#measure each single slice
	imageC[channel-1].setRoi(roi)
	if imageC[channel-1].getNSlices() > 1:
		for i in range(1,imageC[channel-1].getNSlices()+1):
			imageC[channel-1].setSlice(i)
			stats = imageC[channel-1].getStatistics(Measurements.MEAN)
			meanInt.append(stats.mean)
			sliceVal.append(i-1)
		#dot product
		#print sliceVal
		minInt =  min(meanInt)
 
		meanInt = [m-minInt for m in meanInt]
		maxSlice = sliceVal[meanInt.index(max(meanInt))]
		
		for i in range(len(meanInt)):
			prod.append(meanInt[i]*sliceVal[i])
		if method == 'mean':
			#this is the weighted mean
			return sum([p/sum(meanInt) for p in prod])
			#return maxSlice
		if method == 'peak':
			return maxSlice
	else:
		return 0

def createOutputImg(image, rois, particle, ptsFcs = None):
	'''create an output image which as overlay of channel'''
	IJ.setForegroundColor(255,0,0)
	
	IJ.run(image, "Enhance Contrast", "saturated=0")
	IJ.run(image, "RGB Color", "")
	IJ.setForegroundColor(255,0,0)
	ip = image.getProcessor()

	ip.setColor(Color.red)
	for roi in rois:
		ip.draw(roi)
	ip.setColor(Color.green)
	if particle is not None:
		for part in particle:
			ip.draw(rois[part])
	
	ip.setLineWidth(2)
	ip.setColor(Color.white)
	if ptsFcs is not None:
		print "Some fcs points"
		for i, pt in enumerate(ptsFcs):
			drawCross(ip, pt, 8)
			ip.drawString(str(i+1), pt[0]+1, pt[1]-1)
	image.setProcessor(ip)
	return image

def drawCross(ip, pt, sizepx):
	'''draw a cross'''
	ip.moveTo(pt[0]-sizepx/2, pt[1])
	ip.lineTo(pt[0]+sizepx/2, pt[1])
	
	ip.moveTo(pt[0], pt[1]-sizepx/2)
	ip.lineTo(pt[0],pt[1]+sizepx/2)

	