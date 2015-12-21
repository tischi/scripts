CellProfiler Pipeline: http://www.cellprofiler.org
Version:1
SVNRevision:11047

LoadImages:[module_num:1|svn_version:\'11031\'|variable_revision_number:11|show_window:False|notes:\x5B\x5D]
    File type to be loaded:individual images
    File selection method:Text-Exact match
    Number of images in each group?:3
    Type the text that the excluded images have in common:Do not use
    Analyze all subfolders within the selected folder?:All
    Input image file location:Elsewhere...\x7C/g/almf/software/scripts/cellprofiler/MorphDecompExamples
    Check image sets for missing or duplicate files?:Yes
    Group images by metadata?:No
    Exclude certain files?:No
    Specify metadata fields to group by:
    Select subfolders to analyze:
    Image count:2
    Text that these images have in common (case-sensitive):Dapi
    Position of this image in each group:1
    Extract metadata from where?:None
    Regular expression that finds metadata in the file name:^(?P<Treatment>.*)--W(?P<WellNum>.*)--P(?P<PosNum>.*)--Z.*
    Type the regular expression that finds metadata in the subfolder path:(?P<rootPath>.*)\x5B\\\\/\x5D(?P<platePath>.*)\x5B\\\\/\x5Ddata$
    Channel count:1
    Group the movie frames?:No
    Grouping method:Interleaved
    Number of channels per group:3
    Load the input as images or objects?:Images
    Name this loaded image:Dna
    Name this loaded object:Nuclei
    Retain outlines of loaded objects?:No
    Name the outline image:LoadedImageOutlines
    Channel number:1
    Rescale intensities?:Yes
    Text that these images have in common (case-sensitive):GFP
    Position of this image in each group:2
    Extract metadata from where?:None
    Regular expression that finds metadata in the file name:^(?P<FullFilename>.*)
    Type the regular expression that finds metadata in the subfolder path:(?P<FullPath>.*)$
    Channel count:1
    Group the movie frames?:No
    Grouping method:Interleaved
    Number of channels per group:3
    Load the input as images or objects?:Images
    Name this loaded image:Golgi
    Name this loaded object:Nuclei
    Retain outlines of loaded objects?:No
    Name the outline image:LoadedImageOutlines
    Channel number:1
    Rescale intensities?:Yes

Morph:[module_num:2|svn_version:\'11025\'|variable_revision_number:2|show_window:False|notes:\x5B\'Separates structures from diffusive background\'\x5D]
    Select the input image:Golgi
    Name the output image:GolgiStructures
    Select the operation to perform:tophat
    Number of times to repeat operation:Once
    Repetition number:2
    Scale:15

Morph:[module_num:3|svn_version:\'11025\'|variable_revision_number:2|show_window:False|notes:\x5B\'Separates tubular from vesicular structures\'\x5D]
    Select the input image:GolgiStructures
    Name the output image:GolgiTubular
    Select the operation to perform:openlines
    Number of times to repeat operation:Once
    Repetition number:2
    Scale:20

ImageMath:[module_num:4|svn_version:\'11025\'|variable_revision_number:3|show_window:False|notes:\x5B\x5D]
    Operation:Subtract
    Raise the power of the result by:1
    Multiply the result by:1
    Add to result:0
    Set values less than 0 equal to 0?:Yes
    Set values greater than 1 equal to 1?:Yes
    Ignore the image masks?:No
    Name the output image:GolgiVesicular
    Image or measurement?:Image
    Select the first image:GolgiStructures
    Multiply the first image by:1
    Measurement:
    Image or measurement?:Image
    Select the second image:GolgiTubular
    Multiply the second image by:1
    Measurement:

ImageMath:[module_num:5|svn_version:\'11025\'|variable_revision_number:3|show_window:False|notes:\x5B\x5D]
    Operation:Subtract
    Raise the power of the result by:1
    Multiply the result by:1
    Add to result:0
    Set values less than 0 equal to 0?:Yes
    Set values greater than 1 equal to 1?:Yes
    Ignore the image masks?:No
    Name the output image:GolgiDiffuse
    Image or measurement?:Image
    Select the first image:Golgi
    Multiply the first image by:1
    Measurement:
    Image or measurement?:Image
    Select the second image:GolgiStructures
    Multiply the second image by:1
    Measurement:

Smooth:[module_num:6|svn_version:\'11025\'|variable_revision_number:1|show_window:False|notes:\x5B\x5D]
    Select the input image:Dna
    Name the output image:DnaSmooth
    Select smoothing method:Median Filter
    Calculate artifact diameter automatically?:No
    Typical artifact diameter, in  pixels:5
    Edge intensity difference:0.1

IdentifyPrimaryObjects:[module_num:7|svn_version:\'11047\'|variable_revision_number:8|show_window:False|notes:\x5B\x5D]
    Select the input image:DnaSmooth
    Name the primary objects to be identified:Nuclei
    Typical diameter of objects, in pixel units (Min,Max):30,1000000
    Discard objects outside the diameter range?:Yes
    Try to merge too small objects with nearby larger objects?:No
    Discard objects touching the border of the image?:Yes
    Select the thresholding method:Otsu Global
    Threshold correction factor:1
    Lower and upper bounds on threshold:0.000000,1.000000
    Approximate fraction of image covered by objects?:0.01
    Method to distinguish clumped objects:None
    Method to draw dividing lines between clumped objects:Shape
    Size of smoothing filter:10
    Suppress local maxima that are closer than this minimum allowed distance:7
    Speed up by using lower-resolution image to find local maxima?:Yes
    Name the outline image:NucleiOutlines
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
    Assign pixels in the middle intensity class to the foreground or the background?:Background
    Automatically calculate the size of objects for the Laplacian of Gaussian filter?:Yes
    Enter LoG filter diameter:5
    Handling of objects if excessive number of objects identified:Continue
    Maximum number of objects:500
    Select the measurement to threshold with:None

IdentifySecondaryObjects:[module_num:8|svn_version:\'11025\'|variable_revision_number:7|show_window:False|notes:\x5B\x5D]
    Select the input objects:Nuclei
    Name the objects to be identified:Cells
    Select the method to identify the secondary objects:Distance - N
    Select the input image:Golgi
    Select the thresholding method:Otsu Global
    Threshold correction factor:1
    Lower and upper bounds on threshold:0.000000,1.000000
    Approximate fraction of image covered by objects?:0.01
    Number of pixels by which to expand the primary objects:10
    Regularization factor:0.05
    Name the outline image:CellsOutlines
    Manual threshold:0.0
    Select binary image:None
    Retain outlines of the identified secondary objects?:No
    Two-class or three-class thresholding?:Two classes
    Minimize the weighted variance or the entropy?:Weighted variance
    Assign pixels in the middle intensity class to the foreground or the background?:Foreground
    Discard secondary objects that touch the edge of the image?:No
    Discard the associated primary objects?:No
    Name the new primary objects:NucleiTmp
    Retain outlines of the new primary objects?:No
    Name the new primary object outlines:NucleiOutlines
    Select the measurement to threshold with:None
    Fill holes in identified objects?:Yes

MeasureObjectIntensity:[module_num:9|svn_version:\'11025\'|variable_revision_number:3|show_window:False|notes:\x5B\x5D]
    Hidden:4
    Select an image to measure:Golgi
    Select an image to measure:GolgiDiffuse
    Select an image to measure:GolgiVesicular
    Select an image to measure:GolgiTubular
    Select objects to measure:Cells

CalculateMath:[module_num:10|svn_version:\'11025\'|variable_revision_number:1|show_window:False|notes:\x5B\x5D]
    Name the output measurement:Total
    Operation:Divide
    Select the numerator measurement type:Object
    Select the numerator objects:Cells
    Select the numerator measurement:Intensity_IntegratedIntensity_Golgi
    Multiply the above operand by:1
    Raise the power of above operand by:1
    Select the denominator measurement type:Object
    Select the denominator objects:Cells
    Select the denominator measurement:Intensity_IntegratedIntensity_Golgi
    Multiply the above operand by:1
    Raise the power of above operand by:1
    Take log10 of result?:No
    Multiply the result by:1
    Raise the power of result by:1

CalculateMath:[module_num:11|svn_version:\'11025\'|variable_revision_number:1|show_window:False|notes:\x5B\x5D]
    Name the output measurement:Diffuse
    Operation:Divide
    Select the numerator measurement type:Object
    Select the numerator objects:Cells
    Select the numerator measurement:Intensity_IntegratedIntensity_GolgiDiffuse
    Multiply the above operand by:1
    Raise the power of above operand by:1
    Select the denominator measurement type:Object
    Select the denominator objects:Cells
    Select the denominator measurement:Intensity_IntegratedIntensity_Golgi
    Multiply the above operand by:1
    Raise the power of above operand by:1
    Take log10 of result?:No
    Multiply the result by:1
    Raise the power of result by:1

CalculateMath:[module_num:12|svn_version:\'11025\'|variable_revision_number:1|show_window:False|notes:\x5B\x5D]
    Name the output measurement:Vesicular
    Operation:Divide
    Select the numerator measurement type:Object
    Select the numerator objects:Cells
    Select the numerator measurement:Intensity_IntegratedIntensity_GolgiVesicular
    Multiply the above operand by:1
    Raise the power of above operand by:1
    Select the denominator measurement type:Object
    Select the denominator objects:Cells
    Select the denominator measurement:Intensity_IntegratedIntensity_Golgi
    Multiply the above operand by:1
    Raise the power of above operand by:1
    Take log10 of result?:No
    Multiply the result by:1
    Raise the power of result by:1

CalculateMath:[module_num:13|svn_version:\'11025\'|variable_revision_number:1|show_window:False|notes:\x5B\x5D]
    Name the output measurement:Tubular
    Operation:Divide
    Select the numerator measurement type:Object
    Select the numerator objects:Cells
    Select the numerator measurement:Intensity_IntegratedIntensity_GolgiTubular
    Multiply the above operand by:1
    Raise the power of above operand by:1
    Select the denominator measurement type:Object
    Select the denominator objects:Cells
    Select the denominator measurement:Intensity_IntegratedIntensity_Golgi
    Multiply the above operand by:1
    Raise the power of above operand by:1
    Take log10 of result?:No
    Multiply the result by:1
    Raise the power of result by:1

DisplayDataOnImage:[module_num:14|svn_version:\'11025\'|variable_revision_number:2|show_window:False|notes:\x5B\x5D]
    Display object or image measurements?:Object
    Select the input objects:Cells
    Measurement to display:Math_Total
    Select the image on which to display the measurements:Golgi
    Text color:red
    Name the output image that has the measurements displayed:GolgiTotalDisplay
    Font size (points):10
    Number of decimals:2
    Image elements to save:Image

DisplayDataOnImage:[module_num:15|svn_version:\'11025\'|variable_revision_number:2|show_window:False|notes:\x5B\x5D]
    Display object or image measurements?:Object
    Select the input objects:Cells
    Measurement to display:Math_Diffuse
    Select the image on which to display the measurements:GolgiDiffuse
    Text color:red
    Name the output image that has the measurements displayed:GolgiDiffuseDisplay
    Font size (points):10
    Number of decimals:2
    Image elements to save:Image

DisplayDataOnImage:[module_num:16|svn_version:\'11025\'|variable_revision_number:2|show_window:False|notes:\x5B\x5D]
    Display object or image measurements?:Object
    Select the input objects:Cells
    Measurement to display:Math_Tubular
    Select the image on which to display the measurements:GolgiTubular
    Text color:red
    Name the output image that has the measurements displayed:GolgiTubularDisplay
    Font size (points):10
    Number of decimals:2
    Image elements to save:Image

DisplayDataOnImage:[module_num:17|svn_version:\'11025\'|variable_revision_number:2|show_window:False|notes:\x5B\x5D]
    Display object or image measurements?:Object
    Select the input objects:Cells
    Measurement to display:Math_Vesicular
    Select the image on which to display the measurements:GolgiVesicular
    Text color:red
    Name the output image that has the measurements displayed:GolgiVesicularDisplay
    Font size (points):10
    Number of decimals:2
    Image elements to save:Image

Tile:[module_num:18|svn_version:\'9034\'|variable_revision_number:1|show_window:True|notes:\x5B\x5D]
    Select an input image:GolgiTotalDisplay
    Name the output image:TiledImage
    Tile within cycles or across cycles?:Within cycles
    Number of rows in final tiled image:8
    Number of columns in final tiled image:12
    Begin tiling in which corner of the final image?:top left
    Begin tiling across a row, or down a column?:row
    Tile in meander mode?:No
    Automatically calculate number of rows?:Yes
    Automatically calculate number of columns?:Yes
    Select an additional image to tile:GolgiDiffuseDisplay
    Select an additional image to tile:GolgiTubularDisplay
    Select an additional image to tile:GolgiVesicularDisplay
