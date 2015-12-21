"""
1) Start Fiji, open the script editor with the menu File->New->Script.
2) In the script editor File->open and choose the script
3) Press the run button.
"""

import sys
import os
from os.path import join, basename, splitext
from glob import glob

import re

from ij import IJ, ImagePlus
from ij.io import FileSaver
from ij.plugin import ChannelSplitter
from loci.plugins import BF
import time

	


def to_wellbased_nameing_scheme(title, iCh, iSlice):
    chstr = "C%04d" %(int(iCh))
    sliceStr = "Z%04d" %(int(iSlice))
    ntitle = String("_".join([title, chstr, sliceStr]) + ".tif")
    ntitle = ntitle.replaceAll("_+", "__")
    return ntitle

def split_image(file_):
    print "Processing: %s" %(basename(file_))
    #load with loci (allows also to load *.czi)
    images = BF.openImagePlus(file_)
    image = images[0]
    #split channels
    chSp = ChannelSplitter()
    title = splitext(image.title)[0]
    imageC = chSp.split(image)
    print "Number of channels: ", len(imageC)
    for iCh in range(0, len(imageC)):
    	imageStack = imageC[iCh].getImageStack()
    	for iSlice in range(0,imageC[0].getNSlices()):
    		#print iSlice
    		impOut = ImagePlus("outImg", imageStack.getProcessor(iSlice+1))
	        ntitle = to_wellbased_nameing_scheme(title, iCh+1, iSlice+1)
	        IJ.log("Image: %s -> %s " %(title, ntitle))
	        IJ.saveAs(impOut, "Tiff", join(outdir, ntitle) )
    print ""


indir = IJ.getDirectory("Choose the input directory")
if indir is None:
    raise SystemExit
outdir = IJ.getDirectory("Choose the output directory")
if outdir is None:
    raise SystemExit
if not os.path.exists(outdir):
	os.mkdir(outdir)

for root, dirs, files in os.walk(indir, topdown = False):
	ifiles = glob(root+"/*.lsm")
	ifiles = ifiles + glob(root+"/*.czi")
	print "%d Images found in %s " %(len(ifiles),root)
	for ifile in ifiles:
		split_image(ifile)
	

print "finished"
