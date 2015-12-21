# to be added to cpmorphology

def directionlines(image, linelength=10, dAngle=10, mask=None):
    '''Does a morphological opening along lines of different angles.
    Return the max-response angle for each pixel
    
    image - pixel image to operate on
    linelength - length of the structural element
    dAngle - angle step for the rotating lines
    mask - if present, only use unmasked pixels for operations
    '''
	
    nAngles = 180/dAngle
    openingstack = np.zeros((nAngles,image.shape[0],image.shape[1]),image.dtype)
    
    for iAngle in range(nAngles):
      angle = dAngle * iAngle
      #print(angle)
      se = strel_line(linelength, angle)
      openingstack[iAngle,:,:] = opening(image, mask=mask, footprint=se)
      
    imAngles = np.pi / 180 * dAngle * np.argmax(openingstack, axis=0) 
    imAngles = np.ndarray.astype(imAngles,image.dtype)
    
    return imAngles


# to be added (amongst some small things) to morph.py

<td><i>DirectionLines</i></td><td>Performs a grayscale opening using a rotating linear structural element. 
It returns the maximum response angle, which is the direction of the fluorescence in this region of the image, if it is in a linear structure.
The values are scaled from 0 to Pi, where 0 and Pi are parallel (i.e. the same direction) and 0 and Pi/2 are at 90 degrees. 
In order to use this data for computation of the local angular variance of the structures in the image (see Smooth module) 
the values should be multiplied by 2 using the ImageMath module, such that they are between 0 and 2 * Pi.</td> 

 elif function_name == F_DIRECTIONLINES:  
                return morph.directionlines(pixel_data, linelength = scale, mask=mask)


# to be added to filter.py

def angular_variance(image, radius, mask):
    '''Computes the circular variance of an image
    
    image - 2-d image array with values between 0 and 2*pi
    mask  - binary mask of significant pixels
    radius - radius of square kernel to use
    '''
    
    #
    # Kernel for computing the mean
    #
    diameter = round(radius,0) * 2 + 1
    kernel = np.ones((diameter, diameter))

    #
    # Make a mask if there is none
    #
    if mask is None:
        mask = np.ones(image.shape,np.uint8)
    else:
        mask = np.array(mask, np.uint8)
    
    #
    # Compute circular statistics (code adapted from the scipy.stats.circvar)
    # see also: https://en.wikipedia.org/wiki/Directional_statistics
    # Var(z) = 1 - R = 1 - 
    # taking into account the masking
    #
    
    # initialisation
    image_sin_mean = np.zeros(image.shape)
    image_cos_mean = np.zeros(image.shape)

    # compute the proper normalisation including the mask
    image_norm = masked_convolution(mask, np.ones(image.shape,np.uint8), kernel)

    # determine pixels that have at least one valid value in the kernel neighborhood
    idx = image_norm > 0

    # compute the convolutions and normalise to the number of contributing pixels
    image_sin_mean[idx] = masked_convolution(np.sin(image), mask, kernel)[idx] / image_norm[idx]
    image_cos_mean[idx] = masked_convolution(np.cos(image), mask, kernel)[idx] / image_norm[idx]

    # compute the variance
    image_var = abs(1 - (image_sin_mean ** 2 + image_cos_mean ** 2))
    
    # set non-valid pixels to zero
    image_var[ mask==0 ] = 0

    return image_var



# to be added to (amongst some small things) smooth.py

            <li><i>Angular Variance Filter:</i> This method computes the local variance of an image where the values are between 
            0 and 2Pi using circular statistics. This is mostly useful for the output of the DirectionLines filter in the morph module,
            in order to find out how parallel the structures in your image in certain regions are. </li>

     
        elif self.smoothing_method.value == ANGULAR_VARIANCE_FILTER:  #ct
            output_pixels = angular_variance(pixel_data, object_size/2+1, image.mask)    #ct
 
           