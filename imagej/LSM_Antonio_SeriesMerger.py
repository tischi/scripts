'''
Opens series of .lsm files as a single hyperstack

20130712 Kota Miura (cmci.embl.de)
20141223 Tischi Tischer (modified it for the output of Antonio's Macro)

Choose a file among the file series, and this script searchs all the 
files with a pattern

	(basename)_W(.*)_P(.*)_T(time)\.lsm

with T (time) number being left to be variable, 
and then these files are merged in the orfer of the time value. 

'''

import os
import re
from ij import IJ, ImagePlus
from ij.io import Opener
from ij.plugin import Concatenator
from jarray import array

srcpath = IJ.getFilePath('Choose the first file')
filename = os.path.basename(srcpath)
srcDir = os.path.dirname(srcpath)

#chosefile = '20130711_R1_GR001_B1_L2.lsm'
pattern = re.compile('(.*)_W(.*)_P(.*)_T(.*)\.lsm')
res = re.search(pattern, filename)

basename = res.group(1)
well = res.group(2)
position = res.group(3)
time = res.group(4)

filelist = []
for root, directories, filenames in os.walk(srcDir):
	for filename in filenames:
		match = re.search(pattern, filename)
		if match is not None:
			#print filename, match.group(3)
			filelist.append(match.group(4))

print srcDir
print 'files: ', len(filelist)

filelist = sorted(filelist)
timeseries = []

for timepoint in filelist:
	thisfile = basename + '_W' + well + '_P' + position + '_T' + timepoint + '.lsm'
	print thisfile
	imp = Opener.openUsingBioFormats(os.path.join(srcDir, thisfile))
	imp.setOpenAsHyperStack(False)
	timeseries.append(imp)

newname = basename + '_W' + well + '_P' + position + '.lsm'
calib = timeseries[0].getCalibration()
dimA = timeseries[0].getDimensions()
jaimp = array(timeseries, ImagePlus)
ccc = Concatenator()
#allimp = ccc.concatenateHyperstacks(jaimp, newname, False)
allimp = ccc.concatenate(jaimp, False)
allimp.setDimensions(dimA[2], dimA[3], len(timeseries))
allimp.setCalibration(calib)
allimp.setOpenAsHyperStack(True)
allimp.show()


