# for running on an interactive cluster node
cellprofiler_path = '/g/almf/software/CP2C/CellProfiler11047/'
import sys
sys.path.append(cellprofiler_path)
import cellprofiler.cpmath.cpmorphology as morph
import Image 

import numpy as np
from scipy import stats
from scipy.ndimage import convolve

x = np.array([0,10,20,10,20,350])/360.*2.*np.pi
stats.circvar(x)
stats.circmean(x)

import numpy as np
from scipy import stats
from scipy.ndimage import convolve

radius = 3
image = np.ones((10,10))

kernel = np.ones((radius,radius))/radius**2
image_sin_mean = convolve(np.sin(image), kernel, mode='constant')
image_cos_mean = convolve(np.cos(image), kernel, mode='constant')
image_var = 1 - (image_sin_mean ** 2 + image_cos_mean ** 2)


import cellprofiler.cpmath.filter as filter
import numpy as np

image = np.ones((10,10))
image[5,5] = 10
mask = np.array(image, np.uint8)
mask[5,5] = 0
kernel = np.ones((3, 3))
image_norm = filter.masked_convolution(mask, np.ones(image.shape,np.uint8), kernel)
image_sum = filter.masked_convolution(image, mask, kernel)
image_mean = np.zeros(image.shape)
image_mean[image_norm > 0] = image_sum[image_norm > 0] / image_norm[image_norm > 0]
np.round(image_mean,1)


reload(filter)

