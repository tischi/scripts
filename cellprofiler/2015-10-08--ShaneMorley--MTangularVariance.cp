CellProfiler Pipeline: http://www.cellprofiler.org
Version:1
SVNRevision:11047

LoadImages:[module_num:1|svn_version:\'11031\'|variable_revision_number:11|show_window:False|notes:\x5B\x5D]
    File type to be loaded:individual images
    File selection method:Text-Regular expressions
    Number of images in each group?:3
    Type the text that the excluded images have in common:Do not use
    Analyze all subfolders within the selected folder?:All
    Input image file location:Elsewhere...\x7C/g/almf/group/ALMFstuff/Tischi/projects/EMBL-Monterotondo_ShaneMorely/MT_SuperRes
    Check image sets for missing or duplicate files?:Yes
    Group images by metadata?:No
    Exclude certain files?:No
    Specify metadata fields to group by:
    Select subfolders to analyze:
    Image count:1
    Text that these images have in common (case-sensitive):.tif$
    Position of this image in each group:1
    Extract metadata from where?:Path
    Regular expression that finds metadata in the file name:^(?P<Plate>.*)_(?P<Well>\x5BA-P\x5D\x5B0-9\x5D{2})_s(?P<Site>\x5B0-9\x5D)
    Type the regular expression that finds metadata in the subfolder path:(?P<RootFolder>.*)\x5B\\\\/\x5D(?P<CleanedOrNot>.*)\x5B\\\\/\x5D(?P<Treatment>.*)$
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
    Rescale intensities?:No

Morph:[module_num:2|svn_version:\'11025\'|variable_revision_number:2|show_window:False|notes:\x5B\x5D]
    Select the input image:im
    Name the output image:DirLines
    Select the operation to perform:directionlines
    Number of times to repeat operation:Once
    Repetition number:2
    Scale:11.0

ImageMath:[module_num:3|svn_version:\'11025\'|variable_revision_number:3|show_window:False|notes:\x5B"angle doubling is necessary for this kind of data as there are only orientations bewteen 0 and 180 degrees and 0=180 degress because we don\'t measure the directionality of the microtubules. so after the multiplication we have 0=360"\x5D]
    Operation:None
    Raise the power of the result by:1
    Multiply the result by:2
    Add to result:0
    Set values less than 0 equal to 0?:No
    Set values greater than 1 equal to 1?:No
    Ignore the image masks?:No
    Name the output image:DirLinesAngleDoubling
    Image or measurement?:Image
    Select the first image:DirLines
    Multiply the first image by:1
    Measurement:
    Image or measurement?:Image
    Select the second image:
    Multiply the second image by:1
    Measurement:

Morph:[module_num:4|svn_version:\'11025\'|variable_revision_number:2|show_window:False|notes:\x5B\x5D]
    Select the input image:im
    Name the output image:imth
    Select the operation to perform:tophat
    Number of times to repeat operation:Once
    Repetition number:2
    Scale:11

IdentifyPrimaryObjects:[module_num:5|svn_version:\'11047\'|variable_revision_number:8|show_window:False|notes:\x5B\x5D]
    Select the input image:im
    Name the primary objects to be identified:MT
    Typical diameter of objects, in pixel units (Min,Max):5,4000000
    Discard objects outside the diameter range?:Yes
    Try to merge too small objects with nearby larger objects?:No
    Discard objects touching the border of the image?:No
    Select the thresholding method:Manual
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
    Manual threshold:0.08
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

MaskImage:[module_num:6|svn_version:\'11025\'|variable_revision_number:3|show_window:False|notes:\x5B\x5D]
    Select the input image:DirLinesAngleDoubling
    Name the output image:DirLinesRadiansMasked
    Use objects or an image as a mask?:Objects
    Select object for mask:MT
    Select image for mask:MTBW
    Invert the mask?:No

Smooth:[module_num:7|svn_version:\'11025\'|variable_revision_number:1|show_window:False|notes:\x5B\'the diameter here is important as it determines the size of the region in the image in which it is measured how criss-cross the MTs are.\', \'if this becomes very big, the variance should increase.\', \'\'\x5D]
    Select the input image:DirLinesRadiansMasked
    Name the output image:AngularVariance
    Select smoothing method:Angular Variance Filter
    Calculate artifact diameter automatically?:No
    Typical artifact diameter, in  pixels:51
    Edge intensity difference:0.1

RescaleIntensity:[module_num:8|svn_version:\'6746\'|variable_revision_number:2|show_window:False|notes:\x5B\x5D]
    Select the input image:DirLinesRadiansMasked
    Name the output image:DirLinesRadiansMasked01
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

ImageMath:[module_num:9|svn_version:\'11025\'|variable_revision_number:3|show_window:False|notes:\x5B\x5D]
    Operation:None
    Raise the power of the result by:4
    Multiply the result by:1
    Add to result:0.1
    Set values less than 0 equal to 0?:No
    Set values greater than 1 equal to 1?:No
    Ignore the image masks?:No
    Name the output image:AngularVarianceSquared
    Image or measurement?:Image
    Select the first image:AngularVariance
    Multiply the first image by:1
    Measurement:
    Image or measurement?:Image
    Select the second image:
    Multiply the second image by:1
    Measurement:

MaskImage:[module_num:10|svn_version:\'11025\'|variable_revision_number:3|show_window:False|notes:\x5B\x5D]
    Select the input image:AngularVarianceSquared
    Name the output image:AngularVarianceSquaredMasked
    Use objects or an image as a mask?:Objects
    Select object for mask:MT
    Select image for mask:None
    Invert the mask?:No

MeasureImageIntensity:[module_num:11|svn_version:\'11025\'|variable_revision_number:2|show_window:False|notes:\x5B\x5D]
    Select the image to measure:AngularVariance
    Measure the intensity only from areas enclosed by objects?:Yes
    Select the input objects:MT

Tile:[module_num:12|svn_version:\'9034\'|variable_revision_number:1|show_window:False|notes:\x5B\x5D]
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
    Select an additional image to tile:DirLinesRadiansMasked01
    Select an additional image to tile:AngularVarianceSquared

SaveImages:[module_num:13|svn_version:\'11042\'|variable_revision_number:7|show_window:False|notes:\x5B\x5D]
    Select the type of image to save:Image
    Select the image to save:TiledImage
    Select the objects to save:None
    Select the module display window to save:None
    Select method for constructing file names:From image filename
    Select image name for file prefix:im
    Enter single file name:OrigBlue
    Do you want to add a suffix to the image file name?:Yes
    Text to append to the image name:--\\g<Treatment>--AngularVariance
    Select file format to use:png
    Output file location:Elsewhere...\x7C\\g<RootFolder>--cp_out/\\g<CleanedOrNot>
    Image bit depth:8
    Overwrite existing files without warning?:Yes
    Select how often to save:Every cycle
    Rescale the images? :Yes
    Save as grayscale or color image?:Grayscale
    Select colormap:gray
    Store file and path information to the saved image?:Yes
    Create subfolders in the output folder?:No

ExportToSpreadsheet:[module_num:14|svn_version:\'11042\'|variable_revision_number:7|show_window:False|notes:\x5B\x5D]
    Select or enter the column delimiter:Comma (",")
    Prepend the output file name to the data file names?:No
    Add image metadata columns to your object data file?:No
    Limit output to a size that is allowed in Excel?:No
    Select the columns of measurements to export?:Yes
    Calculate the per-image mean values for object measurements?:No
    Calculate the per-image median values for object measurements?:No
    Calculate the per-image standard deviation values for object measurements?:No
    Output file location:Elsewhere...\x7C\\g<RootFolder>--cp_out
    Create a GenePattern GCT file?:No
    Select source of sample row name:Metadata
    Select the image to use as the identifier:None
    Select the metadata to use as the identifier:None
    Export all measurements, using default file names?:No
    Press button to select measurements to export:Image\x7CFileName_im,Image\x7CIntensity_TotalArea_AngularVariance_MT,Image\x7CIntensity_MeanIntensity_AngularVariance_MT,Image\x7CMetadata_CleanedOrNot,Image\x7CMetadata_Treatment
    Data to export:Image
    Combine these object measurements with those of the previous object?:No
    File name:AngularVariance.csv
    Use the object name for the file name?:No
