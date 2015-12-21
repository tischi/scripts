# for running on an interactive cluster node
cellprofiler_path = '/g/almf/software/CP2C/CellProfiler11047/'
import sys
sys.path.append(cellprofiler_path)
import cellprofiler.cpmath.cpmorphology as morph
import Image 
import numpy as np
import 

def s(a):
  Image.fromarray(a).show()

Image.init()
img =  Image.open('/g/almfscreen/tischer/test.tif')
img =  Image.open('/g/almfscreen/tischer/angle_test.tif')
img =  Image.open('/g/almf/software/scripts/python/morph-decomp-test01.tif')
img =  Image.open('/g/almf/software/scripts/python/morph-decomp-test02.tif')
orig = np.array(img)
  
# multiple erosion along lines

def openlines(image, linelength=10, dAngle=10, mask=None):
    '''Do a morphological opening along lines of different angles
    Return difference between max and min response to different angles for each pixel
    
    image - pixel image to operate on
    length - length of the structural element
    angluar_resolution - angle step for the rotating lines
    mask - if present, only use unmasked pixels for operations
    '''
	
    nAngles = 180/dAngle
    openingstack = np.zeros((nAngles,image.shape[0],image.shape[1]),image.dtype)
    
    for iAngle in range(nAngles):
      angle = dAngle * iAngle
      se = strel_line(linelength,angle)
      openingstack[iAngle,:,:] = opening(image, mask=mask, footprint=se)
      
    imLines = np.max(openingstack,axis=0) - np.min(openingstack,axis=0)
    return imLines


def directionlines(image, linelength=10, dAngle=10, mask=None):
    '''Do a morphological opening along lines of different angles
    Return difference between max and min response to different angles for each pixel
    
    image - pixel image to operate on
    length - length of the structural element
    angluar_resolution - angle step for the rotating lines
    mask - if present, only use unmasked pixels for operations
    '''
	
    nAngles = 180/dAngle
    openingstack = np.zeros((nAngles,image.shape[0],image.shape[1]),image.dtype)
    
    for iAngle in range(nAngles):
      angle = dAngle * iAngle
      #print(angle)
      se = strel_line(linelength,angle)
      openingstack[iAngle,:,:] = opening(image, mask=mask, footprint=se)
      
    imAngles = dAngle * np.argmax(openingstack,axis=0) 
    imAngles = np.ndarray.astype(imAngles,image.dtype)
    return imAngles


    
imlines = opening_lines(orig)
imAngles = morph.directionlines(orig)

s(imlines)

