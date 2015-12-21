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
import pyqtgraph as pg # for inspecting intermediate steps and results

####
# global parameters
####

thresh = 40 # fixed intensity threshold for segmentation (crude, but works)
min_voxel_count = 100 # minimum number of voxels in a connected component

base= '/g/almf/group/ALMFstuff/Tischi/projects/tmp/zstack01-crop-ch1_Probabilities--'

suffix = ".tif"

####
# prepare array and load by slice 
####
nz = 34
nx = 132
ny = 121
vol = vigra.Volume((nx,ny,nz),dtype=np.uint8)
for i in range(nz):
    imname= base+str(i).zfill(4)+suffix
    print(imname)
    vol[:,:,i] = vigra.impex.readImage(imname)

####
# preprocessing 
####
smoothed = vigra.filters.gaussianSmoothing(vol*1.0,2.0)

####
# segmentation
####
thresholded = (smoothed > thresh)

####
# clean up segmentation
#####

#
# here, we could clean up things like isolated pixels using morphological operators
# 


####
# label connected components
####
labeled = vigra.analysis.labelVolumeWithBackground(thresholded*1.0)

####
# calculate features for the connected components
# using vigra's feature accumulator
####
acc=vigra.analysis.extractRegionFeatures(vol*1.0, labeled, features=('Weighted<RegionCenter>','Count'))
# alternative: calculate all features
# acc=vigra.analysis.extractRegionFeatures(vol*1.0, labeled)


###########################
# here we could filter 
# the components based on their features
###########################

######
# print the list with the centers of mass for each region
#
print acc['Weighted<RegionCenter>']
print acc['Count']

# filter all objects based on pixel count
for  i in range(len(acc['Count'])):
    if acc['Count'][i] > min_voxel_count:
        print "Count for object ", i ,":", acc['Count'][i] , " Location", acc['Weighted<RegionCenter>'][i]
    else:  # set objects that are too small to background - needed for display only
        labeled[labeled==i]=0


# for viewing

#pg.image(vol.transposeToNumpyOrder())
