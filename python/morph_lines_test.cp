CellProfiler Pipeline: http://www.cellprofiler.org
Version:1
SVNRevision:11047

LoadImages:[module_num:1|svn_version:\'11031\'|variable_revision_number:11|show_window:False|notes:\x5B\x5D]
    File type to be loaded:individual images
    File selection method:Text-Exact match
    Number of images in each group?:3
    Type the text that the excluded images have in common:Do not use
    Analyze all subfolders within the selected folder?:None
    Input image file location:Elsewhere...\x7C/g/almf/software/scripts/python
    Check image sets for missing or duplicate files?:Yes
    Group images by metadata?:No
    Exclude certain files?:No
    Specify metadata fields to group by:
    Select subfolders to analyze:
    Image count:1
    Text that these images have in common (case-sensitive):angle
    Position of this image in each group:1
    Extract metadata from where?:None
    Regular expression that finds metadata in the file name:^(?P<Plate>.*)_(?P<Well>\x5BA-P\x5D\x5B0-9\x5D{2})_s(?P<Site>\x5B0-9\x5D)
    Type the regular expression that finds metadata in the subfolder path:.*\x5B\\\\/\x5D(?P<Date>.*)\x5B\\\\/\x5D(?P<Run>.*)$
    Channel count:1
    Group the movie frames?:No
    Grouping method:Interleaved
    Number of channels per group:3
    Load the input as images or objects?:Images
    Name this loaded image:im
    Name this loaded object:Nuclei
    Retain outlines of loaded objects?:No
    Name the outline image:LoadedImageOutlines
    Channel number:1
    Rescale intensities?:Yes

Morph:[module_num:2|svn_version:\'11025\'|variable_revision_number:2|show_window:True|notes:\x5B\x5D]
    Select the input image:im
    Name the output image:directionOfLines
    Select the operation to perform:directionlines
    Number of times to repeat operation:Once
    Repetition number:2
    Scale:10

ImageMath:[module_num:3|svn_version:\'11025\'|variable_revision_number:3|show_window:True|notes:\x5B\x5D]
    Operation:None
    Raise the power of the result by:1
    Multiply the result by:1
    Add to result:0
    Set values less than 0 equal to 0?:No
    Set values greater than 1 equal to 1?:No
    Ignore the image masks?:No
    Name the output image:DirLinesRadians
    Image or measurement?:Image
    Select the first image:directionOfLines
    Multiply the first image by:0.0349
    Measurement:
    Image or measurement?:Image
    Select the second image:
    Multiply the second image by:1
    Measurement:

IdentifyPrimaryObjects:[module_num:4|svn_version:\'11047\'|variable_revision_number:8|show_window:True|notes:\x5B\x5D]
    Select the input image:im
    Name the primary objects to be identified:MT
    Typical diameter of objects, in pixel units (Min,Max):3,4000
    Discard objects outside the diameter range?:Yes
    Try to merge too small objects with nearby larger objects?:No
    Discard objects touching the border of the image?:No
    Select the thresholding method:Otsu Global
    Threshold correction factor:1.2
    Lower and upper bounds on threshold:0.000000,1.000000
    Approximate fraction of image covered by objects?:0.01
    Method to distinguish clumped objects:None
    Method to draw dividing lines between clumped objects:Intensity
    Size of smoothing filter:10
    Suppress local maxima that are closer than this minimum allowed distance:7
    Speed up by using lower-resolution image to find local maxima?:Yes
    Name the outline image:PrimaryOutlines
    Fill holes in identified objects?:No
    Automatically calculate size of smoothing filter?:Yes
    Automatically calculate minimum allowed distance between local maxima?:Yes
    Manual threshold:0.0
    Select binary image:None
    Retain outlines of the identified objects?:No
    Automatically calculate the threshold using the Otsu method?:Yes
    Enter Laplacian of Gaussian threshold:0.5
    Two-class or three-class thresholding?:Three classes
    Minimize the weighted variance or the entropy?:Weighted variance
    Assign pixels in the middle intensity class to the foreground or the background?:Background
    Automatically calculate the size of objects for the Laplacian of Gaussian filter?:Yes
    Enter LoG filter diameter:5
    Handling of objects if excessive number of objects identified:Continue
    Maximum number of objects:500
    Select the measurement to threshold with:None

ConvertObjectsToImage:[module_num:5|svn_version:\'11025\'|variable_revision_number:1|show_window:True|notes:\x5B\x5D]
    Select the input objects:MT
    Name the output image:MTBW
    Select the color type:Binary (black & white)
    Select the colormap:Default

MaskImage:[module_num:6|svn_version:\'11025\'|variable_revision_number:3|show_window:True|notes:\x5B\x5D]
    Select the input image:DirLinesRadians
    Name the output image:DirLinesRadiansMasked
    Use objects or an image as a mask?:Objects
    Select object for mask:MT
    Select image for mask:MTBW
    Invert the mask?:No

Smooth:[module_num:7|svn_version:\'11025\'|variable_revision_number:1|show_window:True|notes:\x5B\x5D]
    Select the input image:DirLinesRadiansMasked
    Name the output image:AngularVariance
    Select smoothing method:Angular Variance Filter
    Calculate artifact diameter automatically?:No
    Typical artifact diameter, in  pixels:11
    Edge intensity difference:0.1

ImageMath:[module_num:8|svn_version:\'11025\'|variable_revision_number:3|show_window:False|notes:\x5B\x5D]
    Operation:None
    Raise the power of the result by:1
    Multiply the result by:1
    Add to result:0
    Set values less than 0 equal to 0?:Yes
    Set values greater than 1 equal to 1?:Yes
    Ignore the image masks?:No
    Name the output image:ImageAfterMath
    Image or measurement?:Image
    Select the first image:MaskBlue
    Multiply the first image by:0.005
    Measurement:
    Image or measurement?:Image
    Select the second image:
    Multiply the second image by:1
    Measurement:

Tile:[module_num:9|svn_version:\'9034\'|variable_revision_number:1|show_window:True|notes:\x5B\x5D]
    Select an input image:im
    Name the output image:TiledImage
    Tile within cycles or across cycles?:Within cycles
    Number of rows in final tiled image:8
    Number of columns in final tiled image:12
    Begin tiling in which corner of the final image?:top left
    Begin tiling across a row, or down a column?:row
    Tile in meander mode?:No
    Automatically calculate number of rows?:Yes
    Automatically calculate number of columns?:Yes
    Select an additional image to tile:ImageAfterMath
