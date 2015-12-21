#############################################################################
# Simple test code that segments centrioles in a 3D Stack using vigra/numpy
#
# The code performs the following steps: 
#
# 1. Create a numpy array to hold the stack and populate it by reading the files
# slice by slice
# 2. Smooth the volume in 3D
# 3. Threshold with a fixed intensity value to find bright objects 
# 4. Label the objects (connected components)
# 5. Calculate features of connected components
# 6. Filter connected components based on voxel count and return 
#    x,y coordinates of the centre of mass
#
#
#
#
# June 2014
# Volker.Hilsenstein@embl.de

import vigra
import numpy as np
import scipy.ndimage as spnd
import pyqtgraph as pg # for inspecting intermediate steps and results
import tifffile
import sys
import h5py as h5

## import volumina viewer
from PyQt4 import Qt
from PyQt4.QtGui import QColor
sys.path.append('/adminuser/home/tmp/volumina')
import volumina.viewer as vv

## start Qt
app = Qt.QApplication(sys.argv)


## load data 

### load vigra h5 

va = vigra.impex.readHDF5('/media/tmp/h5/vigra01.h5','tischi')

### make plane numpy array with txyzc

nt = 2
nx = va.shape[0]
ny = va.shape[1]
nz = va.shape[2]
nc = va.shape[3]
na = np.zeros((nt,nx,ny,nz,nc))

### add 2 dummy time-points
na[0,...] = va
na[1,...] = va


## save as h5 file

f = h5.File('/media/tmp/h5/numpy_txyzc_01.h5','w')
f.create_dataset('data', data=na, dtype=np.uint8, chunks=True)
f.close()

## open h5 file

f = h5.File('/media/tmp/h5/numpy_txyzc_01.h5')


viewer = vv.Viewer()
viewer.addRGBALayer(f['data'],name='from_hdf5')
viewer.show()

viewer = vv.Viewer()
viewer.addGrayscaleLayer(f['data'],name='from_hdf5')
viewer.show()


f = h5.File('/media/tmp/blabla.h5', 'w')
f['data'] = (np.random.random((1,100,100,100,4))) * 255
na = np.random.random((1,100,100,100,4)) * 255
viewer.addGrayscaleLayer(na)  # works 
viewer.addGrayscaleLayer(f['data'], name='from_hdf5')  # does not work
viewer.show()

viewer = vv.Viewer()

array3 = (np.random.random((100,100,100,3))) * 255
red_layer = viewer.addAlphaModulatedLayer(array3[...,0], name="array3-red", tintColor=QColor(255,0,0))
green_layer = viewer.addAlphaModulatedLayer(array3[...,1], name="array3-green", tintColor=QColor(0,255,0))
blue_layer = viewer.addAlphaModulatedLayer(array3[...,2], name="array3-blue", tintColor=QColor(0,0,255))

red_layer.opacity = 1.0
green_layer.opacity = 0.66
blue_layer.opacity = 0.33

viewer.raise_()

#va_txyzc = vigra.Volume((2,nx,ny,nz,nc), dtype=np.uint8, axistags=vigra.defaultAxistags("txyzc"))
#va = va[numpy.newaxis,:,:,:,:]
#va.axistags = vigra.defaultAxistags("txyzc")
#va[2,...] = va[1,...]

### save vigra h5 
vigra.impex.writeHDF5(va.astype('uint8'),'/media/tmp/h5/vigra_txyzc_01.h5','data')


va.shape

viewer = vv.Viewer()
viewer.addRGBALayer(va)

viewer.addGrayscaleLayer(va[...,1])
viewer.show()
viewer.addGrayscaleLayer(array1)


### examine lif files
import javabridge
import bioformats as bf
javabridge.start_vm(class_path=bf.JARS)

path = '/media/tmp/lif/fish test.lif'

#### get the series count
ox = bf.OMEXML(bf.get_omexml_metadata(path))
series_count = ox.image_count
print series_count


#### other version

import javabridge
ImageReader = javabridge.JClassWrapper("loci.formats.ImageReader")
MetadataTools = javabridge.JClassWrapper("loci.formats.MetadataTools")
reader = ImageReader()
omeMeta = MetadataTools.createOMEXMLMetadata()
reader.setMetadataStore(omeMeta)
reader.setId(path)
print reader.getSeriesCount()

#### load z-stack

i = 0

nt = ox.image(i).Pixels.SizeT
nx = ox.image(i).Pixels.SizeX
ny = ox.image(i).Pixels.SizeY
nz = ox.image(i).Pixels.SizeZ
nc = ox.image(i).Pixels.SizeC

na = np.zeros((nt,nx,ny,nz,nc), dtype = 'uint8')

for it in range(nt):
  for iz in range(nz):
      na[it,:,:,iz,:] = bf.load_image(path, c=None, z=iz, t=it, series=i, index=None, rescale=False, wants_max_intensity=False, channel_names=None)

bg = np.zeros((nx,ny,nz), dtype = 'uint8')

viewer = vv.Viewer()
viewer.addGrayscaleLayer(bg, name="black")
green_layer = viewer.addAlphaModulatedLayer(na[0,...,0], name="green", tintColor=QColor(0,255,0))
blue_layer = viewer.addAlphaModulatedLayer(na[0,...,1], name="blue", tintColor=QColor(0,0,255))
green_layer.opacity = 1.0
blue_layer.opacity = 1.0
viewer.show()


#### load z-stack


javabridge.kill_vm()


 
### initialisation

baseName = '/media/tmp/zstack_0-100--'
channels = []
channels.append("ch1--Probabilities.tiff")
channels.append("ch2.tif")

img = tifffile.TIFFfile(baseName+channels[0]).asarray()
print(img.shape)
nz = img.shape[0]
nx = img.shape[1]
ny = img.shape[2]
nc = len(channels)

va = vigra.Volume((nz,nx,ny,nc),dtype=np.uint8, axistags=vigra.defaultAxistags("zxyc"))

for ic in range(len(channels)):
  print "loading:",baseName+channels[ic]
  npa = tifffile.TIFFfile(baseName+channels[ic]).asarray()
  print(npa.shape)
  va[...,ic] = npa
  pg.image(npa)
  

## object segmentation

ic_objects = 0

### preprocessing 

va_smoothed = vigra.filters.gaussianSmoothing(va[...,ic_objects]*1.0,1.0)
pg.image(va[...,ic_objects])
pg.image(va_smoothed)

### thresholding 

thresh = 255/2
va_bin = (va_smoothed > thresh) # this is now a TRUE and FALSE array
pg.image(va_smoothed)
pg.image(255*va_bin)

# todo: make overlay outlines (make a function!)

### label connected components

va_labeled = vigra.analysis.labelVolumeWithBackground(1.0 * va_bin)
print "Total objects: " , va_labeled.max()

## object feature calculation 

ic_features = 1

acc = vigra.analysis.extractRegionFeatures(1.0*va[...,ic_features], va_labeled, features=('Mean','Count','Maximum'))

## object classification

feature = "Maximum"
feature_th = 255/2

positive = []
negative = [] 

print acc[feature]

for  i in range(1,len(acc[feature])):
    #print "Object ", i ,":", acc[feature][i]   
    if acc[feature][i] > feature_th:
        positive.append(i)
    else:  
        negative.append(i)
        
print "Positive objects:",len(positive)
print "Negative objects:",len(negative)

va_classification = 0.0* va_smoothed   
va_classification[va_labeled in positive] = 2


#pg.image(va[...,ic_features])
#pg.image(va_classification)
        


## output

### segmentation

def getBoundaries(va):
  va_eroded = vigra.VigraArray(spnd.filters.minimum_filter(va,footprint=np.ones((3,3,3))), axistags=va.axistags)
  va_outlines = va - va_eroded
  return va_outlines

  
va_outlines = getBoundaries(va_classification)
rs = 255/va_outlines.max()
va_outlines = va_outlines * rs



##### the proper way would be to add to the h5 file instead of duplicating all the data!

nOutputChannels = 1
nc = len(channels)+nOutputChannels

va_output = vigra.Volume((nz,nx,ny,nc),dtype=np.uint8, axistags=vigra.defaultAxistags("zxyc"))
for ic in range(len(channels)):
  va_output[...,ic] = va[...,ic]
ic = ic + 1; va_output[...,ic] =  va_outlines
va_output.shape


def saveToTiffStacks(va,path):
  for ic in range(0,va.shape[3]):
     pathCh = path+"_ch"+str(ic)+".tif"
     tifffile.imsave(pathCh,va[...,ic])  

saveToTiffStacks(va_output,'/media/win/out/tiffStack')


# vigra.impex.writeHDF5(va_output.astype('uint8'),'/media/win/out/file03.h5','tischi') 

