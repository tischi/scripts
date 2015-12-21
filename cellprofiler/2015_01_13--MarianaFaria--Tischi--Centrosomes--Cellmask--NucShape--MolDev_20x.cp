CellProfiler Pipeline: http://www.cellprofiler.org
Version:1
SVNRevision:11047

LoadImages:[module_num:1|svn_version:\'11031\'|variable_revision_number:11|show_window:False|notes:\x5B\x5D]
    File type to be loaded:individual images
    File selection method:Text-Exact match
    Number of images in each group?:3
    Type the text that the excluded images have in common:Do not use
    Analyze all subfolders within the selected folder?:All
    Input image file location:Elsewhere...\x7C/g/almfscreen/tischer/mariana_faria--1stScreen--Reanalyse--2015/data
    Check image sets for missing or duplicate files?:Yes
    Group images by metadata?:No
    Exclude certain files?:No
    Specify metadata fields to group by:
    Select subfolders to analyze:Bettencourt_centriole_assay_07_batch1_02--badMolDev
    Image count:4
    Text that these images have in common (case-sensitive):C01
    Position of this image in each group:1
    Extract metadata from where?:Both
    Regular expression that finds metadata in the file name:^(?P<dum5>.*)--(?P<siRNA>.*)--(?P<gene>.*)--W(?P<WellNum>.*)--P(?P<PosNum>.*)--T.*
    Type the regular expression that finds metadata in the subfolder path:.*\x5B\\\\/\x5D(?P<PlateName>.*)\x5B\\\\/\x5D(?P<dum3>.*)\x5B\\\\/\x5D(?P<dum4>.*)$
    Channel count:1
    Group the movie frames?:No
    Grouping method:Interleaved
    Number of channels per group:3
    Load the input as images or objects?:Images
    Name this loaded image:DNA
    Name this loaded object:Nuclei
    Retain outlines of loaded objects?:No
    Name the outline image:LoadedImageOutlines
    Channel number:1
    Rescale intensities?:Yes
    Text that these images have in common (case-sensitive):C02
    Position of this image in each group:2
    Extract metadata from where?:Both
    Regular expression that finds metadata in the file name:^(?P<dum1>.*)--(?P<siRNA_gene>.*--.*)--W.*
    Type the regular expression that finds metadata in the subfolder path:(?P<pathBase>.*)\x5B\\\\/\x5D(?P<pathPlate>.*)\x5B\\\\/\x5D(?P<pathWell>.*)\x5B\\\\/\x5D(?P<pathPos>.*)$
    Channel count:1
    Group the movie frames?:No
    Grouping method:Interleaved
    Number of channels per group:3
    Load the input as images or objects?:Images
    Name this loaded image:Centrin
    Name this loaded object:Nuclei
    Retain outlines of loaded objects?:No
    Name the outline image:LoadedImageOutlines
    Channel number:1
    Rescale intensities?:Yes
    Text that these images have in common (case-sensitive):C03
    Position of this image in each group:3
    Extract metadata from where?:File name
    Regular expression that finds metadata in the file name:^(?P<ImageBaseName>.*)--T.*
    Type the regular expression that finds metadata in the subfolder path:.*\x5B\\\\/\x5D(?P<Date>.*)\x5B\\\\/\x5D(?P<Run>.*)$
    Channel count:1
    Group the movie frames?:No
    Grouping method:Interleaved
    Number of channels per group:3
    Load the input as images or objects?:Images
    Name this loaded image:CEP135
    Name this loaded object:Nuclei
    Retain outlines of loaded objects?:No
    Name the outline image:LoadedImageOutlines
    Channel number:1
    Rescale intensities?:Yes
    Text that these images have in common (case-sensitive):C04
    Position of this image in each group:4
    Extract metadata from where?:None
    Regular expression that finds metadata in the file name:^(?P<Plate>.*)_(?P<Well>\x5BA-P\x5D\x5B0-9\x5D{2})_s(?P<Site>\x5B0-9\x5D)
    Type the regular expression that finds metadata in the subfolder path:.*\x5B\\\\/\x5D(?P<Date>.*)\x5B\\\\/\x5D(?P<Run>.*)$
    Channel count:1
    Group the movie frames?:No
    Grouping method:Interleaved
    Number of channels per group:3
    Load the input as images or objects?:Images
    Name this loaded image:Cellmask
    Name this loaded object:Nuclei
    Retain outlines of loaded objects?:No
    Name the outline image:LoadedImageOutlines
    Channel number:1
    Rescale intensities?:Yes

ImageMath:[module_num:2|svn_version:\'11025\'|variable_revision_number:3|show_window:False|notes:\x5B\'here a fixed background is subtracted from the image\'\x5D]
    Operation:None
    Raise the power of the result by:1
    Multiply the result by:1
    Add to result:-0.00178
    Set values less than 0 equal to 0?:No
    Set values greater than 1 equal to 1?:No
    Ignore the image masks?:No
    Name the output image:Centrin-BGcorr
    Image or measurement?:Image
    Select the first image:Centrin
    Multiply the first image by:1
    Measurement:
    Image or measurement?:Image
    Select the second image:
    Multiply the second image by:1
    Measurement:

ImageMath:[module_num:3|svn_version:\'11025\'|variable_revision_number:3|show_window:False|notes:\x5B\'here a fixed background is subtracted from the image\'\x5D]
    Operation:None
    Raise the power of the result by:1
    Multiply the result by:1
    Add to result:-0.00251
    Set values less than 0 equal to 0?:No
    Set values greater than 1 equal to 1?:No
    Ignore the image masks?:No
    Name the output image:CEP135-BGcorr
    Image or measurement?:Image
    Select the first image:CEP135
    Multiply the first image by:1
    Measurement:
    Image or measurement?:Image
    Select the second image:
    Multiply the second image by:1
    Measurement:

MeasureImageIntensity:[module_num:4|svn_version:\'11025\'|variable_revision_number:2|show_window:False|notes:\x5B\x5D]
    Select the image to measure:CEP135
    Measure the intensity only from areas enclosed by objects?:No
    Select the input objects:None

Smooth:[module_num:5|svn_version:\'11025\'|variable_revision_number:1|show_window:False|notes:\x5B\x5D]
    Select the input image:DNA
    Name the output image:DNA-smooth
    Select smoothing method:Median Filter
    Calculate artifact diameter automatically?:No
    Typical artifact diameter, in  pixels:8
    Edge intensity difference:0.1

IdentifyPrimaryObjects:[module_num:6|svn_version:\'11047\'|variable_revision_number:8|show_window:False|notes:\x5B\'# 2015-01-14\x3A changed Typical diameter Min from 30 to 25 to keep more of the elongated (small) cells\', \'\'\x5D]
    Select the input image:DNA
    Name the primary objects to be identified:NucleiTmpTmp
    Typical diameter of objects, in pixel units (Min,Max):25,10000
    Discard objects outside the diameter range?:Yes
    Try to merge too small objects with nearby larger objects?:No
    Discard objects touching the border of the image?:No
    Select the thresholding method:Otsu Global
    Threshold correction factor:0.9
    Lower and upper bounds on threshold:0.0025,1.0
    Approximate fraction of image covered by objects?:0.01
    Method to distinguish clumped objects:Shape
    Method to draw dividing lines between clumped objects:Shape
    Size of smoothing filter:10
    Suppress local maxima that are closer than this minimum allowed distance:7
    Speed up by using lower-resolution image to find local maxima?:Yes
    Name the outline image:PrimaryOutlines
    Fill holes in identified objects?:Yes
    Automatically calculate size of smoothing filter?:Yes
    Automatically calculate minimum allowed distance between local maxima?:Yes
    Manual threshold:0.004
    Select binary image:None
    Retain outlines of the identified objects?:No
    Automatically calculate the threshold using the Otsu method?:Yes
    Enter Laplacian of Gaussian threshold:0.5
    Two-class or three-class thresholding?:Two classes
    Minimize the weighted variance or the entropy?:Weighted variance
    Assign pixels in the middle intensity class to the foreground or the background?:Foreground
    Automatically calculate the size of objects for the Laplacian of Gaussian filter?:Yes
    Enter LoG filter diameter:5
    Handling of objects if excessive number of objects identified:Continue
    Maximum number of objects:500
    Select the measurement to threshold with:None

MeasureImageQuality:[module_num:7|svn_version:\'11045\'|variable_revision_number:4|show_window:False|notes:\x5B\x5D]
    Calculate metrics for which images?:Select...
    Image count:1
    Scale count:1
    Threshold count:1
    Select the images to measure:CEP135,Centrin,DNA
    Include the image rescaling value?:Yes
    Calculate blur metrics?:Yes
    Window size for blur measurements:20
    Calculate saturation metrics?:No
    Calculate intensity metrics?:No
    Calculate thresholds?:No
    Use all thresholding methods?:Yes
    Select a thresholding method:Otsu Global
    Typical fraction of the image covered by objects:0.1
    Two-class or three-class thresholding?:Two classes
    Minimize the weighted variance or the entropy?:Weighted variance
    Assign pixels in the middle intensity class to the foreground or the background?:Foreground

Smooth:[module_num:8|svn_version:\'11025\'|variable_revision_number:1|show_window:False|notes:\x5B\x5D]
    Select the input image:Cellmask
    Name the output image:CellMask-smoothed
    Select smoothing method:Gaussian Filter
    Calculate artifact diameter automatically?:No
    Typical artifact diameter, in  pixels:15
    Edge intensity difference:0.1

IdentifySecondaryObjects:[module_num:9|svn_version:\'11025\'|variable_revision_number:7|show_window:False|notes:\x5B\x5D]
    Select the input objects:NucleiTmpTmp
    Name the objects to be identified:CellsTmp
    Select the method to identify the secondary objects:Watershed - Image
    Select the input image:CellMask-smoothed
    Select the thresholding method:Otsu Global
    Threshold correction factor:1.0
    Lower and upper bounds on threshold:0.000000,1.000000
    Approximate fraction of image covered by objects?:0.99
    Number of pixels by which to expand the primary objects:10
    Regularization factor:0.05
    Name the outline image:Cells-outlines
    Manual threshold:0.004
    Select binary image:None
    Retain outlines of the identified secondary objects?:No
    Two-class or three-class thresholding?:Three classes
    Minimize the weighted variance or the entropy?:Weighted variance
    Assign pixels in the middle intensity class to the foreground or the background?:Foreground
    Discard secondary objects that touch the edge of the image?:Yes
    Discard the associated primary objects?:Yes
    Name the new primary objects:NucleiTmp
    Retain outlines of the new primary objects?:Yes
    Name the new primary object outlines:NucleiTmpOutlines
    Select the measurement to threshold with:None
    Fill holes in identified objects?:Yes

MeasureObjectSizeShape:[module_num:10|svn_version:\'1\'|variable_revision_number:1|show_window:False|notes:\x5B\x5D]
    Select objects to measure:NucleiTmp
    Calculate the Zernike features?:No

MeasureObjectIntensity:[module_num:11|svn_version:\'11025\'|variable_revision_number:3|show_window:False|notes:\x5B\x5D]
    Hidden:1
    Select an image to measure:DNA
    Select objects to measure:NucleiTmp

DisplayDataOnImage:[module_num:12|svn_version:\'11025\'|variable_revision_number:2|show_window:False|notes:\x5B\x5D]
    Display object or image measurements?:Object
    Select the input objects:NucleiTmp
    Measurement to display:AreaShape_MinorAxisLength
    Select the image on which to display the measurements:DNA
    Text color:red
    Name the output image that has the measurements displayed:DisplayImage
    Font size (points):10
    Number of decimals:2
    Image elements to save:Image

CalculateMath:[module_num:13|svn_version:\'11025\'|variable_revision_number:1|show_window:False|notes:\x5B\'measure how variable the nucleus signal is (in order to filter out weird nuclei)\'\x5D]
    Name the output measurement:CV-DNA
    Operation:Divide
    Select the numerator measurement type:Object
    Select the numerator objects:NucleiTmp
    Select the numerator measurement:Intensity_StdIntensity_DNA
    Multiply the above operand by:1
    Raise the power of above operand by:1
    Select the denominator measurement type:Object
    Select the denominator objects:NucleiTmp
    Select the denominator measurement:Intensity_MeanIntensity_DNA
    Multiply the above operand by:1
    Raise the power of above operand by:1
    Take log10 of result?:No
    Multiply the result by:1
    Raise the power of result by:1

DisplayDataOnImage:[module_num:14|svn_version:\'11025\'|variable_revision_number:2|show_window:False|notes:\x5B\x5D]
    Display object or image measurements?:Object
    Select the input objects:NucleiTmp
    Measurement to display:Math_CV-DNA
    Select the image on which to display the measurements:DNA
    Text color:red
    Name the output image that has the measurements displayed:DisplayImage
    Font size (points):10
    Number of decimals:3
    Image elements to save:Image

FilterObjects:[module_num:15|svn_version:\'11025\'|variable_revision_number:5|show_window:False|notes:\x5B\'fiter weird nuclei, based on shape and on intensity variations (CV).\', \'CV=0.5 for MolDev\', \'\'\x5D]
    Name the output objects:Nuclei
    Select the object to filter:NucleiTmp
    Filter using classifier rules or measurements?:Measurements
    Select the filtering method:Limits
    Select the objects that contain the filtered objects:None
    Retain outlines of the identified objects?:Yes
    Name the outline image:Nuclei-outlines
    Rules file location:Default Input Folder\x7CNone
    Rules file name:rules.txt
    Measurement count:2
    Additional object count:1
    Select the measurement to filter by:AreaShape_MinorAxisLength
    Filter using a minimum measurement value?:Yes
    Minimum value:30.0
    Filter using a maximum measurement value?:No
    Maximum value:1
    Select the measurement to filter by:Math_CV-DNA
    Filter using a minimum measurement value?:No
    Minimum value:0.4
    Filter using a maximum measurement value?:Yes
    Maximum value:0.5
    Select additional object to relabel:CellsTmp
    Name the relabeled objects:Cells
    Retain outlines of relabeled objects?:Yes
    Name the outline image:Cells-outlines

EnhanceOrSuppressFeatures:[module_num:16|svn_version:\'11025\'|variable_revision_number:3|show_window:False|notes:\x5B\x5D]
    Select the input image:CEP135
    Name the output image:CEP135-Tophat
    Select the operation:Enhance
    Feature size:10
    Feature type:Speckles
    Range of hole sizes:1,10
    Smoothing scale:2.0
    Shear angle:0
    Decay:0.95

EnhanceOrSuppressFeatures:[module_num:17|svn_version:\'11025\'|variable_revision_number:3|show_window:False|notes:\x5B\x5D]
    Select the input image:Centrin
    Name the output image:Centrin-Tophat
    Select the operation:Enhance
    Feature size:10
    Feature type:Speckles
    Range of hole sizes:1,10
    Smoothing scale:2.0
    Shear angle:0
    Decay:0.95

Crop:[module_num:18|svn_version:\'11025\'|variable_revision_number:2|show_window:False|notes:\x5B\x5D]
    Select the input image:CEP135-Tophat
    Name the output image:CEP135-Tophat-CellCrop
    Select the cropping shape:Objects
    Select the cropping method:Coordinates
    Apply which cycle\'s cropping pattern?:Every
    Left and right rectangle positions:0,end
    Top and bottom rectangle positions:0,end
    Coordinates of ellipse center:500,500
    Ellipse radius, X direction:400
    Ellipse radius, Y direction:200
    Use Plate Fix?:No
    Remove empty rows and columns?:No
    Select the masking image:None
    Select the image with a cropping mask:None
    Select the objects:Cells

Crop:[module_num:19|svn_version:\'11025\'|variable_revision_number:2|show_window:False|notes:\x5B\x5D]
    Select the input image:Centrin-Tophat
    Name the output image:Cetrin-Tophat-CellCrop
    Select the cropping shape:Objects
    Select the cropping method:Coordinates
    Apply which cycle\'s cropping pattern?:Every
    Left and right rectangle positions:0,end
    Top and bottom rectangle positions:0,end
    Coordinates of ellipse center:500,500
    Ellipse radius, X direction:400
    Ellipse radius, Y direction:200
    Use Plate Fix?:No
    Remove empty rows and columns?:No
    Select the masking image:None
    Select the image with a cropping mask:None
    Select the objects:Cells

IdentifyPrimaryObjects:[module_num:20|svn_version:\'11047\'|variable_revision_number:8|show_window:False|notes:\x5B\x5D]
    Select the input image:CEP135-Tophat-CellCrop
    Name the primary objects to be identified:CEP135
    Typical diameter of objects, in pixel units (Min,Max):10,40
    Discard objects outside the diameter range?:No
    Try to merge too small objects with nearby larger objects?:No
    Discard objects touching the border of the image?:No
    Select the thresholding method:RobustBackground PerObject
    Threshold correction factor:4
    Lower and upper bounds on threshold:0.000000,1.000000
    Approximate fraction of image covered by objects?:0.01
    Method to distinguish clumped objects:None
    Method to draw dividing lines between clumped objects:Intensity
    Size of smoothing filter:10
    Suppress local maxima that are closer than this minimum allowed distance:7
    Speed up by using lower-resolution image to find local maxima?:Yes
    Name the outline image:CEP135-outlines
    Fill holes in identified objects?:No
    Automatically calculate size of smoothing filter?:Yes
    Automatically calculate minimum allowed distance between local maxima?:Yes
    Manual threshold:0.0
    Select binary image:None
    Retain outlines of the identified objects?:Yes
    Automatically calculate the threshold using the Otsu method?:Yes
    Enter Laplacian of Gaussian threshold:0.5
    Two-class or three-class thresholding?:Two classes
    Minimize the weighted variance or the entropy?:Weighted variance
    Assign pixels in the middle intensity class to the foreground or the background?:Foreground
    Automatically calculate the size of objects for the Laplacian of Gaussian filter?:Yes
    Enter LoG filter diameter:5
    Handling of objects if excessive number of objects identified:Continue
    Maximum number of objects:500
    Select the measurement to threshold with:None

IdentifyPrimaryObjects:[module_num:21|svn_version:\'11047\'|variable_revision_number:8|show_window:False|notes:\x5B\x5D]
    Select the input image:Cetrin-Tophat-CellCrop
    Name the primary objects to be identified:Centrin
    Typical diameter of objects, in pixel units (Min,Max):10,40
    Discard objects outside the diameter range?:No
    Try to merge too small objects with nearby larger objects?:No
    Discard objects touching the border of the image?:No
    Select the thresholding method:RobustBackground PerObject
    Threshold correction factor:3
    Lower and upper bounds on threshold:0.000000,1.000000
    Approximate fraction of image covered by objects?:0.01
    Method to distinguish clumped objects:None
    Method to draw dividing lines between clumped objects:Intensity
    Size of smoothing filter:10
    Suppress local maxima that are closer than this minimum allowed distance:7
    Speed up by using lower-resolution image to find local maxima?:Yes
    Name the outline image:Centrin-outlines
    Fill holes in identified objects?:No
    Automatically calculate size of smoothing filter?:Yes
    Automatically calculate minimum allowed distance between local maxima?:Yes
    Manual threshold:0.0
    Select binary image:None
    Retain outlines of the identified objects?:Yes
    Automatically calculate the threshold using the Otsu method?:Yes
    Enter Laplacian of Gaussian threshold:0.5
    Two-class or three-class thresholding?:Two classes
    Minimize the weighted variance or the entropy?:Weighted variance
    Assign pixels in the middle intensity class to the foreground or the background?:Foreground
    Automatically calculate the size of objects for the Laplacian of Gaussian filter?:Yes
    Enter LoG filter diameter:5
    Handling of objects if excessive number of objects identified:Continue
    Maximum number of objects:500
    Select the measurement to threshold with:None

ConvertObjectsToImage:[module_num:22|svn_version:\'11025\'|variable_revision_number:1|show_window:False|notes:\x5B\x5D]
    Select the input objects:Centrin
    Name the output image:Centrin-bw
    Select the color type:Binary (black & white)
    Select the colormap:Default

ConvertObjectsToImage:[module_num:23|svn_version:\'11025\'|variable_revision_number:1|show_window:False|notes:\x5B\x5D]
    Select the input objects:CEP135
    Name the output image:CEP135-bw
    Select the color type:Binary (black & white)
    Select the colormap:Default

ImageMath:[module_num:24|svn_version:\'11025\'|variable_revision_number:3|show_window:False|notes:\x5B\x5D]
    Operation:Add
    Raise the power of the result by:1
    Multiply the result by:1
    Add to result:0
    Set values less than 0 equal to 0?:Yes
    Set values greater than 1 equal to 1?:No
    Ignore the image masks?:No
    Name the output image:CepPlusCentBW
    Image or measurement?:Image
    Select the first image:CEP135-bw
    Multiply the first image by:1
    Measurement:
    Image or measurement?:Image
    Select the second image:Centrin-bw
    Multiply the second image by:1
    Measurement:

IdentifyPrimaryObjects:[module_num:25|svn_version:\'11047\'|variable_revision_number:8|show_window:False|notes:\x5B\x5D]
    Select the input image:CepPlusCentBW
    Name the primary objects to be identified:CentrosomeTmp
    Typical diameter of objects, in pixel units (Min,Max):10,40
    Discard objects outside the diameter range?:No
    Try to merge too small objects with nearby larger objects?:No
    Discard objects touching the border of the image?:Yes
    Select the thresholding method:Manual
    Threshold correction factor:1
    Lower and upper bounds on threshold:0.000000,1.000000
    Approximate fraction of image covered by objects?:0.01
    Method to distinguish clumped objects:None
    Method to draw dividing lines between clumped objects:Intensity
    Size of smoothing filter:10
    Suppress local maxima that are closer than this minimum allowed distance:7
    Speed up by using lower-resolution image to find local maxima?:Yes
    Name the outline image:PrimaryOutlines
    Fill holes in identified objects?:Yes
    Automatically calculate size of smoothing filter?:Yes
    Automatically calculate minimum allowed distance between local maxima?:Yes
    Manual threshold:0.5
    Select binary image:None
    Retain outlines of the identified objects?:No
    Automatically calculate the threshold using the Otsu method?:Yes
    Enter Laplacian of Gaussian threshold:0.5
    Two-class or three-class thresholding?:Two classes
    Minimize the weighted variance or the entropy?:Weighted variance
    Assign pixels in the middle intensity class to the foreground or the background?:Foreground
    Automatically calculate the size of objects for the Laplacian of Gaussian filter?:Yes
    Enter LoG filter diameter:5
    Handling of objects if excessive number of objects identified:Continue
    Maximum number of objects:500
    Select the measurement to threshold with:None

MeasureObjectIntensity:[module_num:26|svn_version:\'11025\'|variable_revision_number:3|show_window:False|notes:\x5B\x5D]
    Hidden:1
    Select an image to measure:CepPlusCentBW
    Select objects to measure:CentrosomeTmp

FilterObjects:[module_num:27|svn_version:\'11025\'|variable_revision_number:5|show_window:False|notes:\x5B\x5D]
    Name the output objects:Centrosome
    Select the object to filter:CentrosomeTmp
    Filter using classifier rules or measurements?:Measurements
    Select the filtering method:Limits
    Select the objects that contain the filtered objects:None
    Retain outlines of the identified objects?:Yes
    Name the outline image:Centrosome-outlines
    Rules file location:Default Input Folder\x7CNone
    Rules file name:rules.txt
    Measurement count:1
    Additional object count:0
    Select the measurement to filter by:Intensity_MaxIntensity_CepPlusCentBW
    Filter using a minimum measurement value?:Yes
    Minimum value:2
    Filter using a maximum measurement value?:No
    Maximum value:10000000

RescaleIntensity:[module_num:28|svn_version:\'6746\'|variable_revision_number:2|show_window:False|notes:\x5B\x5D]
    Select the input image:CEP135
    Name the output image:CEP135-RS
    Select rescaling method:Stretch each image to use the full intensity range
    How do you want to calculate the minimum intensity?:Custom
    How do you want to calculate the maximum intensity?:Custom
    Enter the lower limit for the intensity range for the input image:0
    Enter the upper limit for the intensity range for the input image:1
    Enter the intensity range for the input image:0.000000,1.000000
    Enter the desired intensity range for the final, rescaled image:0.000000,1.000000
    Select method for rescaling pixels below the lower limit:Mask pixels
    Enter custom value for pixels below lower limit:0
    Select method for rescaling pixels above the upper limit:Mask pixels
    Enter custom value for pixels below upper limit:0
    Select image to match in maximum intensity:None
    Enter the divisor:1
    Select the measurement to use as a divisor:None

RescaleIntensity:[module_num:29|svn_version:\'6746\'|variable_revision_number:2|show_window:False|notes:\x5B\x5D]
    Select the input image:Centrin
    Name the output image:Centrin-RS
    Select rescaling method:Stretch each image to use the full intensity range
    How do you want to calculate the minimum intensity?:Custom
    How do you want to calculate the maximum intensity?:Custom
    Enter the lower limit for the intensity range for the input image:0
    Enter the upper limit for the intensity range for the input image:1
    Enter the intensity range for the input image:0.000000,1.000000
    Enter the desired intensity range for the final, rescaled image:0.000000,1.000000
    Select method for rescaling pixels below the lower limit:Mask pixels
    Enter custom value for pixels below lower limit:0
    Select method for rescaling pixels above the upper limit:Mask pixels
    Enter custom value for pixels below upper limit:0
    Select image to match in maximum intensity:None
    Enter the divisor:1
    Select the measurement to use as a divisor:None

RescaleIntensity:[module_num:30|svn_version:\'6746\'|variable_revision_number:2|show_window:False|notes:\x5B\x5D]
    Select the input image:DNA
    Name the output image:DNA-RS
    Select rescaling method:Stretch each image to use the full intensity range
    How do you want to calculate the minimum intensity?:Custom
    How do you want to calculate the maximum intensity?:Custom
    Enter the lower limit for the intensity range for the input image:0
    Enter the upper limit for the intensity range for the input image:1
    Enter the intensity range for the input image:0.000000,1.000000
    Enter the desired intensity range for the final, rescaled image:0.000000,1.000000
    Select method for rescaling pixels below the lower limit:Mask pixels
    Enter custom value for pixels below lower limit:0
    Select method for rescaling pixels above the upper limit:Mask pixels
    Enter custom value for pixels below upper limit:0
    Select image to match in maximum intensity:None
    Enter the divisor:1
    Select the measurement to use as a divisor:None

GrayToColor:[module_num:31|svn_version:\'11025\'|variable_revision_number:2|show_window:False|notes:\x5B\x5D]
    Select a color scheme:RGB
    Select the input image to be colored red:CEP135-RS
    Select the input image to be colored green:Centrin-RS
    Select the input image to be colored blue:DNA-RS
    Name the output image:ColorImage
    Relative weight for the red image:1.0
    Relative weight for the green image:1
    Relative weight for the blue image:1
    Select the input image to be colored cyan:Leave this black
    Select the input image to be colored magenta:Leave this black
    Select the input image to be colored yellow:Leave this black
    Select the input image that determines brightness:Leave this black
    Relative weight for the cyan image:1
    Relative weight for the magenta image:1
    Relative weight for the yellow image:1
    Relative weight for the brightness image:1
    Select the input image to add to the stacked image:None

ExpandOrShrinkObjects:[module_num:32|svn_version:\'11025\'|variable_revision_number:1|show_window:False|notes:\x5B\x5D]
    Select the input objects:Centrosome
    Name the output objects:CentrosomeDilated
    Select the operation:Expand objects by a specified number of pixels
    Number of pixels by which to expand or shrink:3
    Fill holes in objects so that all objects shrink to a single point?:No
    Retain the outlines of the identified objects for use later in the pipeline (for example, in SaveImages)?:Yes
    Name the outline image:CentrosomeDilated-Outlines

OverlayOutlines:[module_num:33|svn_version:\'11025\'|variable_revision_number:2|show_window:False|notes:\x5B\'overlay outlines on color image\'\x5D]
    Display outlines on a blank image?:No
    Select image on which to display outlines:ColorImage
    Name the output image:ColorOverlay
    Select outline display mode:Color
    Select method to determine brightness of outlines:Max of image
    Width of outlines:1
    Select outlines to display:Cells-outlines
    Select outline color:Red
    Select outlines to display:Centrosome-outlines
    Select outline color:White
    Select outlines to display:Nuclei-outlines
    Select outline color:Blue

CalculateMath:[module_num:34|svn_version:\'11025\'|variable_revision_number:1|show_window:False|notes:\x5B\x5D]
    Name the output measurement:fractionNormalNuclei
    Operation:Divide
    Select the numerator measurement type:Image
    Select the numerator objects:None
    Select the numerator measurement:Count_Nuclei
    Multiply the above operand by:1
    Raise the power of above operand by:1
    Select the denominator measurement type:Image
    Select the denominator objects:None
    Select the denominator measurement:Count_NucleiTmp
    Multiply the above operand by:1
    Raise the power of above operand by:1
    Take log10 of result?:No
    Multiply the result by:1
    Raise the power of result by:1

OverlayOutlines:[module_num:35|svn_version:\'11025\'|variable_revision_number:2|show_window:False|notes:\x5B\x5D]
    Display outlines on a blank image?:No
    Select image on which to display outlines:DNA-RS
    Name the output image:DNAOverlay
    Select outline display mode:Color
    Select method to determine brightness of outlines:Max of image
    Width of outlines:1
    Select outlines to display:NucleiTmpOutlines
    Select outline color:Blue
    Select outlines to display:Nuclei-outlines
    Select outline color:Green

OverlayOutlines:[module_num:36|svn_version:\'11025\'|variable_revision_number:2|show_window:True|notes:\x5B\x5D]
    Display outlines on a blank image?:No
    Select image on which to display outlines:DNA-RS
    Name the output image:DNAOverlapTest
    Select outline display mode:Color
    Select method to determine brightness of outlines:Max of image
    Width of outlines:1
    Select outlines to display:NucleiTmpOutlines
    Select outline color:Blue

OverlayOutlines:[module_num:37|svn_version:\'11025\'|variable_revision_number:2|show_window:True|notes:\x5B\x5D]
    Display outlines on a blank image?:No
    Select image on which to display outlines:DNA-RS
    Name the output image:DNAOverlayTestTest
    Select outline display mode:Color
    Select method to determine brightness of outlines:Max of image
    Width of outlines:1
    Select outlines to display:Nuclei-outlines
    Select outline color:Green

SaveImages:[module_num:38|svn_version:\'11042\'|variable_revision_number:7|show_window:False|notes:\x5B\x5D]
    Select the type of image to save:Image
    Select the image to save:ColorImage
    Select the objects to save:None
    Select the module display window to save:None
    Select method for constructing file names:Single name
    Select image name for file prefix:DNA
    Enter single file name:\\g<ImageBaseName>--RBG
    Do you want to add a suffix to the image file name?:Yes
    Text to append to the image name:--cp
    Select file format to use:png
    Output file location:Elsewhere...\x7C\\g<pathBase>--cp/\\g<pathPlate>--cp/content/
    Image bit depth:8
    Overwrite existing files without warning?:Yes
    Select how often to save:Every cycle
    Rescale the images? :Yes
    Save as grayscale or color image?:Grayscale
    Select colormap:gray
    Store file and path information to the saved image?:Yes
    Create subfolders in the output folder?:No

SaveImages:[module_num:39|svn_version:\'11042\'|variable_revision_number:7|show_window:False|notes:\x5B\x5D]
    Select the type of image to save:Image
    Select the image to save:ColorOverlay
    Select the objects to save:None
    Select the module display window to save:None
    Select method for constructing file names:Single name
    Select image name for file prefix:DNA
    Enter single file name:\\g<ImageBaseName>--RBGO
    Do you want to add a suffix to the image file name?:Yes
    Text to append to the image name:--cp
    Select file format to use:png
    Output file location:Elsewhere...\x7C\\g<pathBase>--cp/\\g<pathPlate>--cp/content/
    Image bit depth:8
    Overwrite existing files without warning?:Yes
    Select how often to save:Every cycle
    Rescale the images? :Yes
    Save as grayscale or color image?:Grayscale
    Select colormap:gray
    Store file and path information to the saved image?:Yes
    Create subfolders in the output folder?:No

SaveImages:[module_num:40|svn_version:\'11042\'|variable_revision_number:7|show_window:False|notes:\x5B\x5D]
    Select the type of image to save:Image
    Select the image to save:DNAOverlay
    Select the objects to save:None
    Select the module display window to save:None
    Select method for constructing file names:Single name
    Select image name for file prefix:DNA
    Enter single file name:\\g<ImageBaseName>--NucO
    Do you want to add a suffix to the image file name?:Yes
    Text to append to the image name:--cp
    Select file format to use:png
    Output file location:Elsewhere...\x7C\\g<pathBase>--cp/\\g<pathPlate>--cp/content/
    Image bit depth:8
    Overwrite existing files without warning?:Yes
    Select how often to save:Every cycle
    Rescale the images? :Yes
    Save as grayscale or color image?:Grayscale
    Select colormap:gray
    Store file and path information to the saved image?:Yes
    Create subfolders in the output folder?:No

ConvertObjectsToImage:[module_num:41|svn_version:\'11025\'|variable_revision_number:1|show_window:False|notes:\x5B\x5D]
    Select the input objects:Centrosome
    Name the output image:CentrosomeBW
    Select the color type:Binary (black & white)
    Select the colormap:Default

ImageMath:[module_num:42|svn_version:\'11025\'|variable_revision_number:3|show_window:False|notes:\x5B\x5D]
    Operation:Multiply
    Raise the power of the result by:1
    Multiply the result by:1
    Add to result:0
    Set values less than 0 equal to 0?:Yes
    Set values greater than 1 equal to 1?:Yes
    Ignore the image masks?:No
    Name the output image:CEP135-Tophat-CentroBW
    Image or measurement?:Image
    Select the first image:CEP135-Tophat
    Multiply the first image by:1
    Measurement:
    Image or measurement?:Image
    Select the second image:CentrosomeBW
    Multiply the second image by:1
    Measurement:
    Image or measurement?:Image
    Select the third image:CEP135-bw
    Multiply the third image by:1
    Measurement:

ImageMath:[module_num:43|svn_version:\'11025\'|variable_revision_number:3|show_window:False|notes:\x5B\x5D]
    Operation:Multiply
    Raise the power of the result by:1
    Multiply the result by:1
    Add to result:0
    Set values less than 0 equal to 0?:Yes
    Set values greater than 1 equal to 1?:Yes
    Ignore the image masks?:No
    Name the output image:Centrin-Tophat-CentroBW
    Image or measurement?:Image
    Select the first image:Centrin-Tophat
    Multiply the first image by:1
    Measurement:
    Image or measurement?:Image
    Select the second image:CentrosomeBW
    Multiply the second image by:1
    Measurement:
    Image or measurement?:Image
    Select the third image:Centrin-bw
    Multiply the third image by:1
    Measurement:

RelateObjects:[module_num:44|svn_version:\'11025\'|variable_revision_number:2|show_window:False|notes:\x5B\x5D]
    Select the input child objects:Centrosome
    Select the input parent objects:Cells
    Calculate distances?:None
    Calculate per-parent means for all child measurements?:Yes
    Calculate distances to other parents?:No
    Parent name:None

FilterObjects:[module_num:45|svn_version:\'11025\'|variable_revision_number:5|show_window:False|notes:\x5B\x5D]
    Name the output objects:CentroCells
    Select the object to filter:Cells
    Filter using classifier rules or measurements?:Measurements
    Select the filtering method:Limits
    Select the objects that contain the filtered objects:None
    Retain outlines of the identified objects?:No
    Name the outline image:FilteredObjects
    Rules file location:Default Input Folder\x7CNone
    Rules file name:rules.txt
    Measurement count:1
    Additional object count:0
    Select the measurement to filter by:Children_Centrosome_Count
    Filter using a minimum measurement value?:Yes
    Minimum value:1
    Filter using a maximum measurement value?:No
    Maximum value:1

MeasureObjectIntensity:[module_num:46|svn_version:\'11025\'|variable_revision_number:3|show_window:False|notes:\x5B\x5D]
    Hidden:4
    Select an image to measure:CEP135-Tophat-CentroBW
    Select an image to measure:Centrin-Tophat-CentroBW
    Select an image to measure:CEP135-BGcorr
    Select an image to measure:Centrin-BGcorr
    Select objects to measure:CentroCells
    Select objects to measure:Nuclei

MeasureObjectSizeShape:[module_num:47|svn_version:\'1\'|variable_revision_number:1|show_window:False|notes:\x5B\x5D]
    Select objects to measure:CentroCells
    Calculate the Zernike features?:No

CalculateMath:[module_num:48|svn_version:\'11025\'|variable_revision_number:1|show_window:False|notes:\x5B\'Compute ratio of total Centrin signal in centrosome and the mean Centrin intensity of the cell\', \'\'\x5D]
    Name the output measurement:CentrinNorm
    Operation:Divide
    Select the numerator measurement type:Object
    Select the numerator objects:CentroCells
    Select the numerator measurement:Intensity_IntegratedIntensity_Centrin-Tophat-CentroBW
    Multiply the above operand by:1
    Raise the power of above operand by:1
    Select the denominator measurement type:Object
    Select the denominator objects:CentroCells
    Select the denominator measurement:Intensity_MeanIntensity_Centrin-BGcorr
    Multiply the above operand by:1
    Raise the power of above operand by:1
    Take log10 of result?:No
    Multiply the result by:1
    Raise the power of result by:1

CalculateMath:[module_num:49|svn_version:\'11025\'|variable_revision_number:1|show_window:False|notes:\x5B\'Compute ratio of total CEP135 signal in centrosome and the mean CEP135 intensity of the cell\'\x5D]
    Name the output measurement:CEP135norm
    Operation:Divide
    Select the numerator measurement type:Object
    Select the numerator objects:CentroCells
    Select the numerator measurement:Intensity_IntegratedIntensity_CEP135-Tophat-CentroBW
    Multiply the above operand by:1
    Raise the power of above operand by:1
    Select the denominator measurement type:Object
    Select the denominator objects:CentroCells
    Select the denominator measurement:Intensity_MeanIntensity_CEP135-BGcorr
    Multiply the above operand by:1
    Raise the power of above operand by:1
    Take log10 of result?:No
    Multiply the result by:1
    Raise the power of result by:1

CalculateMath:[module_num:50|svn_version:\'11025\'|variable_revision_number:1|show_window:False|notes:\x5B\x5D]
    Name the output measurement:CentrinNormTot
    Operation:Divide
    Select the numerator measurement type:Object
    Select the numerator objects:CentroCells
    Select the numerator measurement:Intensity_IntegratedIntensity_Centrin-Tophat-CentroBW
    Multiply the above operand by:1
    Raise the power of above operand by:1
    Select the denominator measurement type:Object
    Select the denominator objects:CentroCells
    Select the denominator measurement:Intensity_IntegratedIntensity_Centrin-BGcorr
    Multiply the above operand by:1
    Raise the power of above operand by:1
    Take log10 of result?:No
    Multiply the result by:1
    Raise the power of result by:1

CalculateMath:[module_num:51|svn_version:\'11025\'|variable_revision_number:1|show_window:False|notes:\x5B\x5D]
    Name the output measurement:CEP135normTot
    Operation:Divide
    Select the numerator measurement type:Object
    Select the numerator objects:CentroCells
    Select the numerator measurement:Intensity_IntegratedIntensity_CEP135-Tophat-CentroBW
    Multiply the above operand by:1
    Raise the power of above operand by:1
    Select the denominator measurement type:Object
    Select the denominator objects:CentroCells
    Select the denominator measurement:Intensity_IntegratedIntensity_CEP135-BGcorr
    Multiply the above operand by:1
    Raise the power of above operand by:1
    Take log10 of result?:No
    Multiply the result by:1
    Raise the power of result by:1

CalculateMath:[module_num:52|svn_version:\'11025\'|variable_revision_number:1|show_window:False|notes:\x5B\'divide the normalised total signals in the centrosomal regions\'\x5D]
    Name the output measurement:CentrinDivCEP135
    Operation:Divide
    Select the numerator measurement type:Object
    Select the numerator objects:CentroCells
    Select the numerator measurement:Math_CentrinNorm
    Multiply the above operand by:1
    Raise the power of above operand by:1
    Select the denominator measurement type:Object
    Select the denominator objects:CentroCells
    Select the denominator measurement:Math_CEP135norm
    Multiply the above operand by:1
    Raise the power of above operand by:1
    Take log10 of result?:No
    Multiply the result by:1
    Raise the power of result by:1

CalculateMath:[module_num:53|svn_version:\'11025\'|variable_revision_number:1|show_window:False|notes:\x5B\x5D]
    Name the output measurement:CentrinDivCEP135normTot
    Operation:Divide
    Select the numerator measurement type:Object
    Select the numerator objects:CentroCells
    Select the numerator measurement:Math_CentrinNormTot
    Multiply the above operand by:1
    Raise the power of above operand by:1
    Select the denominator measurement type:Object
    Select the denominator objects:CentroCells
    Select the denominator measurement:Math_CEP135normTot
    Multiply the above operand by:1
    Raise the power of above operand by:1
    Take log10 of result?:No
    Multiply the result by:1
    Raise the power of result by:1

DisplayDataOnImage:[module_num:54|svn_version:\'11025\'|variable_revision_number:2|show_window:False|notes:\x5B\x5D]
    Display object or image measurements?:Object
    Select the input objects:CentroCells
    Measurement to display:Math_CentrinDivCEP135
    Select the image on which to display the measurements:Centrin-RS
    Text color:red
    Name the output image that has the measurements displayed:DisplayImage
    Font size (points):10
    Number of decimals:2
    Image elements to save:Image

DisplayDataOnImage:[module_num:55|svn_version:\'11025\'|variable_revision_number:2|show_window:False|notes:\x5B\x5D]
    Display object or image measurements?:Object
    Select the input objects:Cells
    Measurement to display:Children_Centrosome_Count
    Select the image on which to display the measurements:Cells-outlines
    Text color:red
    Name the output image that has the measurements displayed:DisplayImage
    Font size (points):20
    Number of decimals:0
    Image elements to save:Image

ExportToSpreadsheet:[module_num:56|svn_version:\'11042\'|variable_revision_number:7|show_window:False|notes:\x5B\x5D]
    Select or enter the column delimiter:Comma (",")
    Prepend the output file name to the data file names?:No
    Add image metadata columns to your object data file?:Yes
    Limit output to a size that is allowed in Excel?:No
    Select the columns of measurements to export?:Yes
    Calculate the per-image mean values for object measurements?:Yes
    Calculate the per-image median values for object measurements?:No
    Calculate the per-image standard deviation values for object measurements?:No
    Output file location:Elsewhere...\x7C\\g<pathBase>--cp/\\g<pathPlate>--cp/content/\\g<pathWell>/\\g<pathPos>
    Create a GenePattern GCT file?:No
    Select source of sample row name:Metadata
    Select the image to use as the identifier:None
    Select the metadata to use as the identifier:None
    Export all measurements, using default file names?:No
    Press button to select measurements to export:Cells\x7CChildren_Centrosome_Count,Image\x7CCount_CentroCells,Image\x7CCount_Nuclei,Image\x7CCount_Cells,Image\x7CCount_NucleiTmp,Image\x7CImageQuality_PowerLogLogSlope_DNA,Image\x7CImageQuality_PowerLogLogSlope_Centrin,Image\x7CImageQuality_PowerLogLogSlope_CEP135,Image\x7CFileName_ColorOverlay,Image\x7CFileName_DNA,Image\x7CFileName_Cellmask,Image\x7CFileName_Centrin,Image\x7CFileName_CEP135,Image\x7CFileName_DNAOverlay,Image\x7CFileName_ColorImage,Image\x7CPathName_ColorOverlay,Image\x7CPathName_DNA,Image\x7CPathName_Cellmask,Image\x7CPathName_Centrin,Image\x7CPathName_CEP135,Image\x7CPathName_DNAOverlay,Image\x7CPathName_ColorImage,Image\x7CMath_fractionNormalNuclei,Image\x7CMetadata_PosNum,Image\x7CMetadata_PlateName,Image\x7CMetadata_ImageBaseName,Image\x7CMetadata_pathWell,Image\x7CMetadata_WellNum,Image\x7CMetadata_pathPlate,Image\x7CMetadata_pathBase,Image\x7CMetadata_pathPos,Image\x7CMetadata_gene,Image\x7CMetadata_siRNA,Image\x7CMetadata_siRNA_gene,CentroCells\x7CIntensity_MeanIntensity_CEP135-BGcorr,CentroCells\x7CIntensity_MeanIntensity_Centrin-BGcorr,CentroCells\x7CIntensity_IntegratedIntensity_CEP135-BGcorr,CentroCells\x7CIntensity_IntegratedIntensity_Centrin-BGcorr,CentroCells\x7CIntensity_IntegratedIntensity_Centrin-Tophat-CentroBW,CentroCells\x7CIntensity_IntegratedIntensity_CEP135-Tophat-CentroBW,CentroCells\x7CAreaShape_Area,CentroCells\x7CMath_CentrinNorm,CentroCells\x7CMath_CEP135norm,CentroCells\x7CMath_CentrinNormTot,CentroCells\x7CMath_CentrinDivCEP135,CentroCells\x7CMath_CEP135normTot,CentroCells\x7CMath_CentrinDivCEP135normTot,Nuclei\x7CIntensity_MedianIntensity_CEP135-BGcorr,Nuclei\x7CIntensity_MedianIntensity_Centrin-BGcorr,Nuclei\x7CIntensity_IntegratedIntensity_CEP135-BGcorr,Nuclei\x7CIntensity_IntegratedIntensity_Centrin-BGcorr,NucleiTmp\x7CAreaShape_FormFactor,NucleiTmp\x7CAreaShape_Area,NucleiTmp\x7CAreaShape_Eccentricity,NucleiTmp\x7CAreaShape_MinorAxisLength
    Data to export:Image
    Combine these object measurements with those of the previous object?:No
    File name:image.csv
    Use the object name for the file name?:No

CreateBatchFiles:[module_num:57|svn_version:\'11025\'|variable_revision_number:4|show_window:False|notes:\x5B\x5D]
    Store batch files in default output folder?:No
    Output folder path:/g/almfscreen/tischer/mariana_faria--1stScreen--Reanalyse--2015/
    Are the cluster computers running Windows?:No
    Hidden\x3A in batch mode:No
    Hidden\x3A default input folder at time of save:/home/tischer
    Hidden\x3A SVN revision number:0
    Local root path:/home/tischer
    Cluster root path:/home/tischer
