CellProfiler Pipeline: http://www.cellprofiler.org
Version:1
SVNRevision:11047

LoadImages:[module_num:1|svn_version:\'11031\'|variable_revision_number:11|show_window:False|notes:\x5B\'\'\x5D]
    File type to be loaded:individual images
    File selection method:Text-Exact match
    Number of images in each group?:3
    Type the text that the excluded images have in common:Do not use
    Analyze all subfolders within the selected folder?:All
    Input image file location:Elsewhere...\x7C/g/almfscreen/corallin/output
    Check image sets for missing or duplicate files?:Yes
    Group images by metadata?:No
    Exclude certain files?:No
    Specify metadata fields to group by:
    Select subfolders to analyze:Scita_Dorsal_Ruffles_plate01_batch1_03,Scita_Dorsal_Ruffles_plate03_batch2_03,Scita_Dorsal_Ruffles_plate02_batch1_08,Scita_Dorsal_Ruffles_plate03_batch1_01,Scita_Dorsal_Ruffles_plate03_batch1_02,Scita_Dorsal_Ruffles_plate03_batch1_05,Scita_Dorsal_Ruffles_plate01_batch1_07
    Image count:4
    Text that these images have in common (case-sensitive):C01.ome.tif
    Position of this image in each group:1
    Extract metadata from where?:Both
    Regular expression that finds metadata in the file name:(?P<ImageBaseName>.*)\x5B-\x5D\x5B-\x5D.*\x5B.\x5D.*$
    Type the regular expression that finds metadata in the subfolder path:(?P<PathBase>.*)\x5B\\\\/\x5D(?P<PathPlate>.*)\x5B\\\\/\x5D(?P<PathWell>.*)\x5B\\\\/\x5D(?P<PathPos>.*)$
    Channel count:1
    Group the movie frames?:No
    Grouping method:Interleaved
    Number of channels per group:3
    Load the input as images or objects?:Images
    Name this loaded image:nucleusRaw
    Name this loaded object:Nuclei
    Retain outlines of loaded objects?:No
    Name the outline image:NucleiOutlines
    Channel number:1
    Rescale intensities?:Yes
    Text that these images have in common (case-sensitive):C02.ome.tif
    Position of this image in each group:2
    Extract metadata from where?:File name
    Regular expression that finds metadata in the file name:^(?P<Layout>.*)_(?P<Replicate>.*)--(?P<siRNA>.*)--(?P<gene>.*)--W(?P<wellNum>.*)--P(?P<posNum>.*)--T(?P<timeNum>.*)--Z(?P<zNum>.*)--(?P<channel>.*).ome.tif
    Type the regular expression that finds metadata in the subfolder path:.*\x5B\\\\/\x5D(?P<treatment>.*)$
    Channel count:1
    Group the movie frames?:No
    Grouping method:Interleaved
    Number of channels per group:3
    Load the input as images or objects?:Images
    Name this loaded image:actinRaw
    Name this loaded object:Nuclei
    Retain outlines of loaded objects?:No
    Name the outline image:NucleiOutlines
    Channel number:1
    Rescale intensities?:Yes
    Text that these images have in common (case-sensitive):C03.ome.tif
    Position of this image in each group:3
    Extract metadata from where?:File name
    Regular expression that finds metadata in the file name:^(?P<dum1>.*)--(?P<siRNAgene>.*--.*)--.*--.*--.*--.*--.*
    Type the regular expression that finds metadata in the subfolder path:.*\x5B\\\\/\x5D(?P<Date>.*)\x5B\\\\/\x5D(?P<Run>.*)$
    Channel count:1
    Group the movie frames?:No
    Grouping method:Interleaved
    Number of channels per group:3
    Load the input as images or objects?:Images
    Name this loaded image:cytoRaw
    Name this loaded object:Nuclei
    Retain outlines of loaded objects?:No
    Name the outline image:NucleiOutlines
    Channel number:1
    Rescale intensities?:Yes
    Text that these images have in common (case-sensitive):8bit.tiff
    Position of this image in each group:4
    Extract metadata from where?:None
    Regular expression that finds metadata in the file name:^(?P<Plate>.*)_(?P<Well>\x5BA-P\x5D\x5B0-9\x5D{2})_s(?P<Site>\x5B0-9\x5D)
    Type the regular expression that finds metadata in the subfolder path:.*\x5B\\\\/\x5D(?P<Date>.*)\x5B\\\\/\x5D(?P<Run>.*)$
    Channel count:1
    Group the movie frames?:No
    Grouping method:Interleaved
    Number of channels per group:3
    Load the input as images or objects?:Images
    Name this loaded image:actin8bit
    Name this loaded object:Nuclei
    Retain outlines of loaded objects?:No
    Name the outline image:LoadedImageOutlines
    Channel number:1
    Rescale intensities?:Yes

ClassifyPixels:[module_num:2|svn_version:\'Unknown\'|variable_revision_number:1|show_window:False|notes:\x5B\x5D]
    Select the input image:actin8bit
    Name of the output probability map:ruffleP
    Class to choose:1
    Input classifier file location:Elsewhere...\x7C/g/almfscreen/corallin/Analysis
    Classfier File:ilastik_8bit_classifier_corralin_ruffles_2013-03-18_withdarkcells.h5

ApplyThreshold:[module_num:3|svn_version:\'6746\'|variable_revision_number:5|show_window:False|notes:\x5B\x5D]
    Select the input image:ruffleP
    Name the output image:ruffleBW
    Select the output image type:Binary (black and white)
    Set pixels below or above the threshold to zero?:Below threshold
    Subtract the threshold value from the remaining pixel intensities?:No
    Number of pixels by which to expand the thresholding around those excluded bright pixels:0.0
    Select the thresholding method:Manual
    Manual threshold:0.51
    Lower and upper bounds on threshold:0.000000,1.000000
    Threshold correction factor:1
    Approximate fraction of image covered by objects?:0.01
    Select the input objects:None
    Two-class or three-class thresholding?:Two classes
    Minimize the weighted variance or the entropy?:Weighted variance
    Assign pixels in the middle intensity class to the foreground or the background?:Foreground
    Select the measurement to threshold with:None

IdentifyPrimaryObjects:[module_num:4|svn_version:\'11047\'|variable_revision_number:8|show_window:False|notes:\x5B\x5D]
    Select the input image:ruffleBW
    Name the primary objects to be identified:ruffle
    Typical diameter of objects, in pixel units (Min,Max):10,40
    Discard objects outside the diameter range?:No
    Try to merge too small objects with nearby larger objects?:No
    Discard objects touching the border of the image?:No
    Select the thresholding method:Manual
    Threshold correction factor:1
    Lower and upper bounds on threshold:0.000000,1.000000
    Approximate fraction of image covered by objects?:0.01
    Method to distinguish clumped objects:None
    Method to draw dividing lines between clumped objects:Intensity
    Size of smoothing filter:10
    Suppress local maxima that are closer than this minimum allowed distance:7
    Speed up by using lower-resolution image to find local maxima?:Yes
    Name the outline image:ruffleOutlines
    Fill holes in identified objects?:No
    Automatically calculate size of smoothing filter?:Yes
    Automatically calculate minimum allowed distance between local maxima?:Yes
    Manual threshold:0.5
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

Morph:[module_num:5|svn_version:\'11025\'|variable_revision_number:2|show_window:False|notes:\x5B\x5D]
    Select the input image:ruffleBW
    Name the output image:ruffleBWclose
    Select the operation to perform:close
    Number of times to repeat operation:Once
    Repetition number:2
    Scale:7

IdentifyPrimaryObjects:[module_num:6|svn_version:\'11047\'|variable_revision_number:8|show_window:False|notes:\x5B\x5D]
    Select the input image:ruffleBWclose
    Name the primary objects to be identified:ruffleBWcloseBig
    Typical diameter of objects, in pixel units (Min,Max):15,40000
    Discard objects outside the diameter range?:Yes
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
    Name the outline image:bigRufflesOutlines
    Fill holes in identified objects?:No
    Automatically calculate size of smoothing filter?:Yes
    Automatically calculate minimum allowed distance between local maxima?:Yes
    Manual threshold:0.5
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

ConvertObjectsToImage:[module_num:7|svn_version:\'11025\'|variable_revision_number:1|show_window:False|notes:\x5B\x5D]
    Select the input objects:ruffleBWcloseBig
    Name the output image:ruffleBWcloseBig
    Select the color type:Binary (black & white)
    Select the colormap:Default

RescaleIntensity:[module_num:8|svn_version:\'6746\'|variable_revision_number:2|show_window:False|notes:\x5B\x5D]
    Select the input image:nucleusRaw
    Name the output image:nucleus
    Select rescaling method:Choose specific values to be reset to the full intensity range
    How do you want to calculate the minimum intensity?:Custom
    How do you want to calculate the maximum intensity?:Custom
    Enter the lower limit for the intensity range for the input image:0
    Enter the upper limit for the intensity range for the input image:1
    Enter the intensity range for the input image:0.0,0.0624761585
    Enter the desired intensity range for the final, rescaled image:0.000000,1.000000
    Select method for rescaling pixels below the lower limit:Set to zero
    Enter custom value for pixels below lower limit:
    Select method for rescaling pixels above the upper limit:Set to one
    Enter custom value for pixels below upper limit:
    Select image to match in maximum intensity:None
    Enter the divisor:1
    Select the measurement to use as a divisor:None

RescaleIntensity:[module_num:9|svn_version:\'6746\'|variable_revision_number:2|show_window:False|notes:\x5B\x5D]
    Select the input image:actinRaw
    Name the output image:actin
    Select rescaling method:Choose specific values to be reset to the full intensity range
    How do you want to calculate the minimum intensity?:Custom
    How do you want to calculate the maximum intensity?:Custom
    Enter the lower limit for the intensity range for the input image:0
    Enter the upper limit for the intensity range for the input image:1
    Enter the intensity range for the input image:0.0,0.0624761585
    Enter the desired intensity range for the final, rescaled image:0.000000,1.000000
    Select method for rescaling pixels below the lower limit:Set to zero
    Enter custom value for pixels below lower limit:0
    Select method for rescaling pixels above the upper limit:Set to one
    Enter custom value for pixels below upper limit:0
    Select image to match in maximum intensity:None
    Enter the divisor:1
    Select the measurement to use as a divisor:None

RescaleIntensity:[module_num:10|svn_version:\'6746\'|variable_revision_number:2|show_window:False|notes:\x5B\x5D]
    Select the input image:cytoRaw
    Name the output image:cyto
    Select rescaling method:Choose specific values to be reset to the full intensity range
    How do you want to calculate the minimum intensity?:Custom
    How do you want to calculate the maximum intensity?:Custom
    Enter the lower limit for the intensity range for the input image:0
    Enter the upper limit for the intensity range for the input image:0.0624761585
    Enter the intensity range for the input image:0.0,0.0624761585
    Enter the desired intensity range for the final, rescaled image:0.000000,1.000000
    Select method for rescaling pixels below the lower limit:Set to zero
    Enter custom value for pixels below lower limit:0
    Select method for rescaling pixels above the upper limit:Set to one
    Enter custom value for pixels below upper limit:0
    Select image to match in maximum intensity:None
    Enter the divisor:1
    Select the measurement to use as a divisor:None

Crop:[module_num:11|svn_version:\'11025\'|variable_revision_number:2|show_window:False|notes:\x5B\x5D]
    Select the input image:cyto
    Name the output image:cytoCenter
    Select the cropping shape:Rectangle
    Select the cropping method:Coordinates
    Apply which cycle\'s cropping pattern?:Every
    Left and right rectangle positions:150,-150
    Top and bottom rectangle positions:150,-150
    Coordinates of ellipse center:500,500
    Ellipse radius, X direction:400
    Ellipse radius, Y direction:200
    Use Plate Fix?:No
    Remove empty rows and columns?:All
    Select the masking image:None
    Select the image with a cropping mask:None
    Select the objects:None

MeasureImageIntensity:[module_num:12|svn_version:\'11025\'|variable_revision_number:2|show_window:False|notes:\x5B\x5D]
    Select the image to measure:cytoCenter
    Measure the intensity only from areas enclosed by objects?:No
    Select the input objects:None

ImageMath:[module_num:13|svn_version:\'11025\'|variable_revision_number:3|show_window:False|notes:\x5B\x5D]
    Operation:Subtract
    Raise the power of the result by:1
    Multiply the result by:1
    Add to result:0
    Set values less than 0 equal to 0?:Yes
    Set values greater than 1 equal to 1?:Yes
    Ignore the image masks?:No
    Name the output image:cytoBGsubtracted
    Image or measurement?:Image
    Select the first image:cyto
    Multiply the first image by:1
    Measurement:Intensity_MedianIntensity_cytoCenter
    Image or measurement?:Measurement
    Select the second image:
    Multiply the second image by:1
    Measurement:Intensity_MinIntensity_cytoCenter

MeasureImageQuality:[module_num:14|svn_version:\'11045\'|variable_revision_number:4|show_window:False|notes:\x5B\x5D]
    Calculate metrics for which images?:Select...
    Image count:1
    Scale count:1
    Threshold count:1
    Select the images to measure:nucleus
    Include the image rescaling value?:No
    Calculate blur metrics?:Yes
    Window size for blur measurements:20
    Calculate saturation metrics?:No
    Calculate intensity metrics?:No
    Calculate thresholds?:No
    Use all thresholding methods?:No
    Select a thresholding method:Otsu Global
    Typical fraction of the image covered by objects:0.1
    Two-class or three-class thresholding?:Two classes
    Minimize the weighted variance or the entropy?:Weighted variance
    Assign pixels in the middle intensity class to the foreground or the background?:Foreground

IdentifyPrimaryObjects:[module_num:15|svn_version:\'11047\'|variable_revision_number:8|show_window:False|notes:\x5B\x5D]
    Select the input image:nucleus
    Name the primary objects to be identified:nucleusTmp
    Typical diameter of objects, in pixel units (Min,Max):20,150
    Discard objects outside the diameter range?:Yes
    Try to merge too small objects with nearby larger objects?:No
    Discard objects touching the border of the image?:No
    Select the thresholding method:Otsu Global
    Threshold correction factor:1
    Lower and upper bounds on threshold:0.06,1.0
    Approximate fraction of image covered by objects?:0.01
    Method to distinguish clumped objects:None
    Method to draw dividing lines between clumped objects:Shape
    Size of smoothing filter:10
    Suppress local maxima that are closer than this minimum allowed distance:7
    Speed up by using lower-resolution image to find local maxima?:Yes
    Name the outline image:nucleus_outline
    Fill holes in identified objects?:Yes
    Automatically calculate size of smoothing filter?:Yes
    Automatically calculate minimum allowed distance between local maxima?:Yes
    Manual threshold:0.0
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

Smooth:[module_num:16|svn_version:\'11025\'|variable_revision_number:1|show_window:False|notes:\x5B\x5D]
    Select the input image:cytoBGsubtracted
    Name the output image:cytosmooth
    Select smoothing method:Gaussian Filter
    Calculate artifact diameter automatically?:No
    Typical artifact diameter, in  pixels:10
    Edge intensity difference:0.1

IdentifySecondaryObjects:[module_num:17|svn_version:\'11025\'|variable_revision_number:7|show_window:False|notes:\x5B\'\'\x5D]
    Select the input objects:nucleusTmp
    Name the objects to be identified:cellTmp
    Select the method to identify the secondary objects:Watershed - Image
    Select the input image:cytosmooth
    Select the thresholding method:Manual
    Threshold correction factor:1
    Lower and upper bounds on threshold:0.000000,1.000000
    Approximate fraction of image covered by objects?:0.01
    Number of pixels by which to expand the primary objects:70
    Regularization factor:0.1
    Name the outline image:cellOutline
    Manual threshold:0.04
    Select binary image:None
    Retain outlines of the identified secondary objects?:No
    Two-class or three-class thresholding?:Three classes
    Minimize the weighted variance or the entropy?:Weighted variance
    Assign pixels in the middle intensity class to the foreground or the background?:Foreground
    Discard secondary objects that touch the edge of the image?:No
    Discard the associated primary objects?:Yes
    Name the new primary objects:nucleusTmp
    Retain outlines of the new primary objects?:No
    Name the new primary object outlines:nucleusOutline
    Select the measurement to threshold with:Math_CellMaskThreshold
    Fill holes in identified objects?:Yes

ApplyThreshold:[module_num:18|svn_version:\'6746\'|variable_revision_number:5|show_window:False|notes:\x5B\x5D]
    Select the input image:actin8bit
    Name the output image:actin8bitSatu
    Select the output image type:Binary (black and white)
    Set pixels below or above the threshold to zero?:Below threshold
    Subtract the threshold value from the remaining pixel intensities?:No
    Number of pixels by which to expand the thresholding around those excluded bright pixels:0.0
    Select the thresholding method:Manual
    Manual threshold:0.99
    Lower and upper bounds on threshold:0.000000,1.000000
    Threshold correction factor:1
    Approximate fraction of image covered by objects?:0.01
    Select the input objects:None
    Two-class or three-class thresholding?:Two classes
    Minimize the weighted variance or the entropy?:Weighted variance
    Assign pixels in the middle intensity class to the foreground or the background?:Foreground
    Select the measurement to threshold with:None

ExpandOrShrinkObjects:[module_num:19|svn_version:\'11025\'|variable_revision_number:1|show_window:False|notes:\x5B\x5D]
    Select the input objects:cellTmp
    Name the output objects:cellShrunkTmp
    Select the operation:Shrink objects by a specified number of pixels
    Number of pixels by which to expand or shrink:5
    Fill holes in objects so that all objects shrink to a single point?:No
    Retain the outlines of the identified objects for use later in the pipeline (for example, in SaveImages)?:Yes
    Name the outline image:cellShrunkOutlinesTmp

MeasureObjectSizeShape:[module_num:20|svn_version:\'1\'|variable_revision_number:1|show_window:False|notes:\x5B\x5D]
    Select objects to measure:cellShrunkTmp
    Calculate the Zernike features?:No

MeasureObjectIntensity:[module_num:21|svn_version:\'11025\'|variable_revision_number:3|show_window:False|notes:\x5B\x5D]
    Hidden:2
    Select an image to measure:actin8bitSatu
    Select an image to measure:actin
    Select objects to measure:cellShrunkTmp

OverlayOutlines:[module_num:22|svn_version:\'11025\'|variable_revision_number:2|show_window:False|notes:\x5B\x5D]
    Display outlines on a blank image?:No
    Select image on which to display outlines:actin
    Name the output image:OrigOverlay
    Select outline display mode:Color
    Select method to determine brightness of outlines:Max of image
    Width of outlines:1
    Select outlines to display:cellShrunkOutlinesTmp
    Select outline color:Red

FilterObjects:[module_num:23|svn_version:\'11025\'|variable_revision_number:5|show_window:False|notes:\x5B\x5D]
    Name the output objects:cellShrunk
    Select the object to filter:cellShrunkTmp
    Filter using classifier rules or measurements?:Measurements
    Select the filtering method:Limits
    Select the objects that contain the filtered objects:None
    Retain outlines of the identified objects?:Yes
    Name the outline image:cellShrunkOutlines
    Rules file location:Default Input Folder\x7CNone
    Rules file name:rules.txt
    Measurement count:3
    Additional object count:1
    Select the measurement to filter by:AreaShape_Area
    Filter using a minimum measurement value?:Yes
    Minimum value:2500
    Filter using a maximum measurement value?:Yes
    Maximum value:10000000000
    Select the measurement to filter by:Intensity_IntegratedIntensity_actin8bitSatu
    Filter using a minimum measurement value?:Yes
    Minimum value:0
    Filter using a maximum measurement value?:Yes
    Maximum value:500.0
    Select the measurement to filter by:Intensity_MeanIntensity_actin
    Filter using a minimum measurement value?:Yes
    Minimum value:0.095
    Filter using a maximum measurement value?:Yes
    Maximum value:1
    Select additional object to relabel:nucleusTmp
    Name the relabeled objects:nucleus
    Retain outlines of relabeled objects?:No
    Name the outline image:cellShrunkOutlines

ConvertObjectsToImage:[module_num:24|svn_version:\'11025\'|variable_revision_number:1|show_window:False|notes:\x5B\x5D]
    Select the input objects:ruffleBWcloseBig
    Name the output image:ruffleBWcloseBig
    Select the color type:Binary (black & white)
    Select the colormap:Default

MaskImage:[module_num:25|svn_version:\'11025\'|variable_revision_number:3|show_window:False|notes:\x5B\x5D]
    Select the input image:ruffleBWcloseBig
    Name the output image:ruffleBWcloseBigInsideCells
    Use objects or an image as a mask?:Objects
    Select object for mask:cellShrunk
    Select image for mask:None
    Invert the mask?:No

IdentifyPrimaryObjects:[module_num:26|svn_version:\'11047\'|variable_revision_number:8|show_window:False|notes:\x5B\x5D]
    Select the input image:ruffleBWcloseBigInsideCells
    Name the primary objects to be identified:rufflesInsideCells
    Typical diameter of objects, in pixel units (Min,Max):10,40
    Discard objects outside the diameter range?:No
    Try to merge too small objects with nearby larger objects?:No
    Discard objects touching the border of the image?:No
    Select the thresholding method:Manual
    Threshold correction factor:1
    Lower and upper bounds on threshold:0.000000,1.000000
    Approximate fraction of image covered by objects?:0.01
    Method to distinguish clumped objects:None
    Method to draw dividing lines between clumped objects:Intensity
    Size of smoothing filter:10
    Suppress local maxima that are closer than this minimum allowed distance:7
    Speed up by using lower-resolution image to find local maxima?:Yes
    Name the outline image:RufflesInsideCellsOutlines
    Fill holes in identified objects?:Yes
    Automatically calculate size of smoothing filter?:Yes
    Automatically calculate minimum allowed distance between local maxima?:Yes
    Manual threshold:0.5
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

OverlayOutlines:[module_num:27|svn_version:\'11025\'|variable_revision_number:2|show_window:False|notes:\x5B\x5D]
    Display outlines on a blank image?:No
    Select image on which to display outlines:actin
    Name the output image:actinRufflesOverlay
    Select outline display mode:Color
    Select method to determine brightness of outlines:Max of image
    Width of outlines:2
    Select outlines to display:ruffleOutlines
    Select outline color:Blue
    Select outlines to display:cellShrunkOutlines
    Select outline color:Green

OverlayOutlines:[module_num:28|svn_version:\'11025\'|variable_revision_number:2|show_window:False|notes:\x5B\x5D]
    Display outlines on a blank image?:No
    Select image on which to display outlines:actin
    Name the output image:actinBigRufflesOverlay
    Select outline display mode:Color
    Select method to determine brightness of outlines:Max of image
    Width of outlines:2
    Select outlines to display:RufflesInsideCellsOutlines
    Select outline color:Blue
    Select outlines to display:cellShrunkOutlines
    Select outline color:Green

Tile:[module_num:29|svn_version:\'9034\'|variable_revision_number:1|show_window:False|notes:\x5B\x5D]
    Select an input image:actin
    Name the output image:actinTiled
    Tile within cycles or across cycles?:Within cycles
    Number of rows in final tiled image:8
    Number of columns in final tiled image:12
    Begin tiling in which corner of the final image?:top left
    Begin tiling across a row, or down a column?:row
    Tile in meander mode?:No
    Automatically calculate number of rows?:Yes
    Automatically calculate number of columns?:Yes
    Select an additional image to tile:actinBigRufflesOverlay

SaveImages:[module_num:30|svn_version:\'11042\'|variable_revision_number:7|show_window:False|notes:\x5B\x5D]
    Select the type of image to save:Image
    Select the image to save:actinTiled
    Select the objects to save:None
    Select the module display window to save:None
    Select method for constructing file names:Single name
    Select image name for file prefix:nucleusRaw
    Enter single file name:\\g<ImageBaseName>--actinOverlayTiled
    Do you want to add a suffix to the image file name?:Yes
    Text to append to the image name:--scoreSeg31
    Select file format to use:jpeg
    Output file location:Elsewhere...\x7C\\g<PathBase>--cellprofiler--20130319/\\g<PathPlate>--cellprofiler/\\g<PathWell>/\\g<PathPos>
    Image bit depth:8
    Overwrite existing files without warning?:Yes
    Select how often to save:Every cycle
    Rescale the images? :No
    Save as grayscale or color image?:Grayscale
    Select colormap:gray
    Store file and path information to the saved image?:Yes
    Create subfolders in the output folder?:No

SaveImages:[module_num:31|svn_version:\'11042\'|variable_revision_number:7|show_window:False|notes:\x5B\x5D]
    Select the type of image to save:Image
    Select the image to save:actinBigRufflesOverlay
    Select the objects to save:None
    Select the module display window to save:None
    Select method for constructing file names:Single name
    Select image name for file prefix:nucleusRaw
    Enter single file name:\\g<ImageBaseName>--actinOverlay
    Do you want to add a suffix to the image file name?:Yes
    Text to append to the image name:--scoreSeg31
    Select file format to use:png
    Output file location:Elsewhere...\x7C\\g<PathBase>--cellprofiler--20130319/\\g<PathPlate>--cellprofiler/\\g<PathWell>/\\g<PathPos>
    Image bit depth:8
    Overwrite existing files without warning?:Yes
    Select how often to save:Every cycle
    Rescale the images? :No
    Save as grayscale or color image?:Grayscale
    Select colormap:gray
    Store file and path information to the saved image?:Yes
    Create subfolders in the output folder?:No

MeasureObjectSizeShape:[module_num:32|svn_version:\'1\'|variable_revision_number:1|show_window:False|notes:\x5B\x5D]
    Select objects to measure:cellShrunk
    Calculate the Zernike features?:No

MaskImage:[module_num:33|svn_version:\'11025\'|variable_revision_number:3|show_window:False|notes:\x5B\x5D]
    Select the input image:ruffleP
    Name the output image:rufflePmasked
    Use objects or an image as a mask?:Image
    Select object for mask:None
    Select image for mask:ruffleBWcloseBigInsideCells
    Invert the mask?:No

MeasureObjectIntensity:[module_num:34|svn_version:\'11025\'|variable_revision_number:3|show_window:False|notes:\x5B\x5D]
    Hidden:4
    Select an image to measure:ruffleBWcloseBig
    Select an image to measure:actin
    Select an image to measure:nucleus
    Select an image to measure:rufflePmasked
    Select objects to measure:cellShrunk
    Select objects to measure:nucleus

ExportToSpreadsheet:[module_num:35|svn_version:\'11042\'|variable_revision_number:7|show_window:False|notes:\x5B\x5D]
    Select or enter the column delimiter:Comma (",")
    Prepend the output file name to the data file names?:No
    Add image metadata columns to your object data file?:Yes
    Limit output to a size that is allowed in Excel?:No
    Select the columns of measurements to export?:Yes
    Calculate the per-image mean values for object measurements?:Yes
    Calculate the per-image median values for object measurements?:Yes
    Calculate the per-image standard deviation values for object measurements?:Yes
    Output file location:Elsewhere...\x7C\\g<PathBase>--cellprofiler--20130319/\\g<PathPlate>--cellprofiler/\\g<PathWell>/\\g<PathPos>
    Create a GenePattern GCT file?:No
    Select source of sample row name:Metadata
    Select the image to use as the identifier:None
    Select the metadata to use as the identifier:None
    Export all measurements, using default file names?:No
    Press button to select measurements to export:Image\x7CCount_nucleus,Image\x7CCount_cellShrunk,Image\x7CImageQuality_PowerLogLogSlope_nucleus,Image\x7CFileName_cytoRaw,Image\x7CFileName_nucleusRaw,Image\x7CFileName_actinTiled,Image\x7CFileName_actinRaw,Image\x7CFileName_actinBigRufflesOverlay,Image\x7CFileName_actin8bit,Image\x7CPathName_cytoRaw,Image\x7CPathName_nucleusRaw,Image\x7CPathName_actinTiled,Image\x7CPathName_actinRaw,Image\x7CPathName_actinBigRufflesOverlay,Image\x7CPathName_actin8bit,Image\x7CMetadata_posNum,Image\x7CMetadata_Layout,Image\x7CMetadata_siRNAgene,Image\x7CMetadata_wellNum,Image\x7CMetadata_Replicate,Image\x7CMetadata_gene,Image\x7CMetadata_siRNA,nucleus\x7CIntensity_MeanIntensity_nucleus,nucleus\x7CLocation_Center_Y,nucleus\x7CLocation_Center_X,nucleus\x7CNumber_Object_Number,cellShrunk\x7CNumber_Object_Number,cellShrunk\x7CIntensity_MeanIntensity_actin,cellShrunk\x7CIntensity_IntegratedIntensity_ruffleBWcloseBig,cellShrunk\x7CIntensity_IntegratedIntensity_rufflePmasked,cellShrunk\x7CLocation_Center_Y,cellShrunk\x7CLocation_Center_X,cellShrunk\x7CAreaShape_FormFactor,cellShrunk\x7CAreaShape_Area,cellShrunk\x7CAreaShape_Eccentricity
    Data to export:nucleus
    Combine these object measurements with those of the previous object?:No
    File name:objects.csv
    Use the object name for the file name?:No
    Data to export:cellShrunk
    Combine these object measurements with those of the previous object?:Yes
    File name:DATA.csv
    Use the object name for the file name?:Yes
    Data to export:Image
    Combine these object measurements with those of the previous object?:No
    File name:image.csv
    Use the object name for the file name?:No

CreateBatchFiles:[module_num:36|svn_version:\'11025\'|variable_revision_number:4|show_window:False|notes:\x5B\x5D]
    Store batch files in default output folder?:No
    Output folder path:/g/almfscreen/corallin/Analysis
    Are the cluster computers running Windows?:No
    Hidden\x3A in batch mode:No
    Hidden\x3A default input folder at time of save:/g/almfscreen/SalvatoreCorallino/Pilot/10minPDGF_2012-11-09_002
    Hidden\x3A SVN revision number:0
