CellProfiler Pipeline: http://www.cellprofiler.org
Version:1
SVNRevision:11047

LoadImages:[module_num:1|svn_version:\'11031\'|variable_revision_number:11|show_window:False|notes:\x5B\x5D]
    File type to be loaded:tif,tiff,flex,zvi movies
    File selection method:Text-Regular expressions
    Number of images in each group?:3
    Type the text that the excluded images have in common:Do not use
    Analyze all subfolders within the selected folder?:All
    Input image file location:Elsewhere...\x7C/g/almf/group/ALMFstuff/Tischi/projects/AleksandarNecakov_deRenzis/2014-09-17--Puncta_vs_PlasmaMembraneComparison
    Check image sets for missing or duplicate files?:Yes
    Group images by metadata?:No
    Exclude certain files?:No
    Specify metadata fields to group by:
    Select subfolders to analyze:
    Image count:1
    Text that these images have in common (case-sensitive):.*Color.tif
    Position of this image in each group:1
    Extract metadata from where?:Both
    Regular expression that finds metadata in the file name:^.*--(?P<date>.*)--(?P<treatment>.*)--.*--.*
    Type the regular expression that finds metadata in the subfolder path:^(?P<rootPath>.*)$
    Channel count:1
    Group the movie frames?:No
    Grouping method:Interleaved
    Number of channels per group:3
    Load the input as images or objects?:Images
    Name this loaded image:col
    Name this loaded object:Nuclei
    Retain outlines of loaded objects?:No
    Name the outline image:LoadedImageOutlines
    Channel number:1
    Rescale intensities?:Yes

ColorToGray:[module_num:2|svn_version:\'11025\'|variable_revision_number:2|show_window:False|notes:\x5B\x5D]
    Select the input image:col
    Conversion method:Split
    Image type\x3A:RGB
    Name the output image:OrigGray
    Relative weight of the red channel:1
    Relative weight of the green channel:1
    Relative weight of the blue channel:1
    Convert red to gray?:No
    Name the output image:OrigRed
    Convert green to gray?:Yes
    Name the output image:green
    Convert blue to gray?:Yes
    Name the output image:red
    Channel count:1
    Channel number\x3A:Red\x3A 1
    Relative weight of the channel:1
    Image name\x3A:Channel1

ClassifyPixels:[module_num:3|svn_version:\'Unknown\'|variable_revision_number:1|show_window:False|notes:\x5B\x5D]
    Select the input image:col
    Name of the output probability map:pd
    Class to choose:1
    Input classifier file location:Elsewhere...\x7C/g/almf/group/ALMFstuff/Tischi/projects/AleksandarNecakov_deRenzis/Code--Ilastik_CellProfiler
    Classfier File:dots_color__2014_06_23.h5

ClassifyPixels:[module_num:4|svn_version:\'Unknown\'|variable_revision_number:1|show_window:False|notes:\x5B\x5D]
    Select the input image:red
    Name of the output probability map:pm
    Class to choose:0
    Input classifier file location:Elsewhere...\x7C/g/almf/group/ALMFstuff/Tischi/projects/AleksandarNecakov_deRenzis/Code--Ilastik_CellProfiler
    Classfier File:membrane_red__2014_06_23.h5

IdentifyPrimaryObjects:[module_num:5|svn_version:\'11047\'|variable_revision_number:8|show_window:False|notes:\x5B\x5D]
    Select the input image:pm
    Name the primary objects to be identified:m
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
    Name the outline image:mOutlines
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

IdentifyPrimaryObjects:[module_num:6|svn_version:\'11047\'|variable_revision_number:8|show_window:False|notes:\x5B\x5D]
    Select the input image:pd
    Name the primary objects to be identified:dTmp
    Typical diameter of objects, in pixel units (Min,Max):2,40
    Discard objects outside the diameter range?:No
    Try to merge too small objects with nearby larger objects?:No
    Discard objects touching the border of the image?:No
    Select the thresholding method:Manual
    Threshold correction factor:1
    Lower and upper bounds on threshold:0.000000,1.000000
    Approximate fraction of image covered by objects?:0.01
    Method to distinguish clumped objects:Shape
    Method to draw dividing lines between clumped objects:Shape
    Size of smoothing filter:0
    Suppress local maxima that are closer than this minimum allowed distance:3
    Speed up by using lower-resolution image to find local maxima?:No
    Name the outline image:dOutlines
    Fill holes in identified objects?:Yes
    Automatically calculate size of smoothing filter?:No
    Automatically calculate minimum allowed distance between local maxima?:No
    Manual threshold:0.8
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

MeasureObjectSizeShape:[module_num:7|svn_version:\'1\'|variable_revision_number:1|show_window:False|notes:\x5B\x5D]
    Select objects to measure:dTmp
    Calculate the Zernike features?:No

FilterObjects:[module_num:8|svn_version:\'11025\'|variable_revision_number:5|show_window:False|notes:\x5B\x5D]
    Name the output objects:d
    Select the object to filter:dTmp
    Filter using classifier rules or measurements?:Measurements
    Select the filtering method:Limits
    Select the objects that contain the filtered objects:None
    Retain outlines of the identified objects?:Yes
    Name the outline image:dOutlines
    Rules file location:Default Input Folder\x7CNone
    Rules file name:rules.txt
    Measurement count:1
    Additional object count:0
    Select the measurement to filter by:AreaShape_Area
    Filter using a minimum measurement value?:Yes
    Minimum value:2
    Filter using a maximum measurement value?:Yes
    Maximum value:1000

ConvertObjectsToImage:[module_num:9|svn_version:\'11025\'|variable_revision_number:1|show_window:False|notes:\x5B\x5D]
    Select the input objects:m
    Name the output image:m
    Select the color type:Binary (black & white)
    Select the colormap:Default

ConvertObjectsToImage:[module_num:10|svn_version:\'11025\'|variable_revision_number:1|show_window:False|notes:\x5B\x5D]
    Select the input objects:d
    Name the output image:d
    Select the color type:Binary (black & white)
    Select the colormap:Default

ImageMath:[module_num:11|svn_version:\'11025\'|variable_revision_number:3|show_window:False|notes:\x5B\'get a mask for the the areas containing either dots or membrane\'\x5D]
    Operation:Maximum
    Raise the power of the result by:1
    Multiply the result by:1
    Add to result:0
    Set values less than 0 equal to 0?:No
    Set values greater than 1 equal to 1?:No
    Ignore the image masks?:No
    Name the output image:total
    Image or measurement?:Image
    Select the first image:m
    Multiply the first image by:1
    Measurement:
    Image or measurement?:Image
    Select the second image:d
    Multiply the second image by:1
    Measurement:

IdentifyPrimaryObjects:[module_num:12|svn_version:\'11047\'|variable_revision_number:8|show_window:False|notes:\x5B\x5D]
    Select the input image:total
    Name the primary objects to be identified:total
    Typical diameter of objects, in pixel units (Min,Max):2,40
    Discard objects outside the diameter range?:No
    Try to merge too small objects with nearby larger objects?:No
    Discard objects touching the border of the image?:No
    Select the thresholding method:Manual
    Threshold correction factor:1
    Lower and upper bounds on threshold:0.000000,1.000000
    Approximate fraction of image covered by objects?:0.01
    Method to distinguish clumped objects:None
    Method to draw dividing lines between clumped objects:Shape
    Size of smoothing filter:0
    Suppress local maxima that are closer than this minimum allowed distance:3
    Speed up by using lower-resolution image to find local maxima?:No
    Name the outline image:totalOutlines
    Fill holes in identified objects?:No
    Automatically calculate size of smoothing filter?:No
    Automatically calculate minimum allowed distance between local maxima?:No
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

EnhanceOrSuppressFeatures:[module_num:13|svn_version:\'11025\'|variable_revision_number:3|show_window:False|notes:\x5B\x5D]
    Select the input image:green
    Name the output image:green_TopHat
    Select the operation:Enhance
    Feature size:50
    Feature type:Speckles
    Range of hole sizes:1,10
    Smoothing scale:2.0
    Shear angle:0
    Decay:0.95

MeasureImageIntensity:[module_num:14|svn_version:\'11025\'|variable_revision_number:2|show_window:False|notes:\x5B\x5D]
    Select the image to measure:green
    Measure the intensity only from areas enclosed by objects?:Yes
    Select the input objects:d
    Select the image to measure:green
    Measure the intensity only from areas enclosed by objects?:Yes
    Select the input objects:total
    Select the image to measure:green_TopHat
    Measure the intensity only from areas enclosed by objects?:Yes
    Select the input objects:d
    Select the image to measure:green_TopHat
    Measure the intensity only from areas enclosed by objects?:Yes
    Select the input objects:total

OverlayOutlines:[module_num:15|svn_version:\'11025\'|variable_revision_number:2|show_window:False|notes:\x5B\x5D]
    Display outlines on a blank image?:No
    Select image on which to display outlines:green
    Name the output image:greenDotOverlay
    Select outline display mode:Color
    Select method to determine brightness of outlines:Max of image
    Width of outlines:1
    Select outlines to display:dOutlines
    Select outline color:Green

OverlayOutlines:[module_num:16|svn_version:\'11025\'|variable_revision_number:2|show_window:False|notes:\x5B\x5D]
    Display outlines on a blank image?:No
    Select image on which to display outlines:col
    Name the output image:colorTotalOverlay
    Select outline display mode:Color
    Select method to determine brightness of outlines:Max of image
    Width of outlines:1
    Select outlines to display:totalOutlines
    Select outline color:White

Tile:[module_num:17|svn_version:\'9034\'|variable_revision_number:1|show_window:True|notes:\x5B\x5D]
    Select an input image:red
    Name the output image:TiledImage
    Tile within cycles or across cycles?:Within cycles
    Number of rows in final tiled image:1
    Number of columns in final tiled image:2
    Begin tiling in which corner of the final image?:top left
    Begin tiling across a row, or down a column?:row
    Tile in meander mode?:No
    Automatically calculate number of rows?:No
    Automatically calculate number of columns?:Yes
    Select an additional image to tile:colorTotalOverlay
    Select an additional image to tile:green
    Select an additional image to tile:greenDotOverlay
    Select an additional image to tile:green_TopHat

SaveImages:[module_num:18|svn_version:\'11042\'|variable_revision_number:7|show_window:True|notes:\x5B\'for some weird reason one has to hardcode the output path here as the Metadata_rootPath does not work...\'\x5D]
    Select the type of image to save:Movie
    Select the image to save:TiledImage
    Select the objects to save:None
    Select the module display window to save:None
    Select method for constructing file names:From image filename
    Select image name for file prefix:col
    Enter single file name:OrigBlue
    Do you want to add a suffix to the image file name?:Yes
    Text to append to the image name:--Tiled-cpOut
    Select file format to use:png
    Output file location:Elsewhere...\x7C/g/almf/group/ALMFstuff/Tischi/projects/AleksandarNecakov_deRenzis/2014-09-17--Puncta_vs_PlasmaMembraneComparison--cp/images
    Image bit depth:8
    Overwrite existing files without warning?:Yes
    Select how often to save:Every cycle
    Rescale the images? :No
    Save as grayscale or color image?:Grayscale
    Select colormap:Greys
    Store file and path information to the saved image?:Yes
    Create subfolders in the output folder?:No

ExportToSpreadsheet:[module_num:19|svn_version:\'11042\'|variable_revision_number:7|show_window:False|notes:\x5B\x5D]
    Select or enter the column delimiter:Comma (",")
    Prepend the output file name to the data file names?:No
    Add image metadata columns to your object data file?:Yes
    Limit output to a size that is allowed in Excel?:No
    Select the columns of measurements to export?:Yes
    Calculate the per-image mean values for object measurements?:Yes
    Calculate the per-image median values for object measurements?:No
    Calculate the per-image standard deviation values for object measurements?:No
    Output file location:Elsewhere...\x7C/g/almf/group/ALMFstuff/Tischi/projects/AleksandarNecakov_deRenzis/2014-09-17--Puncta_vs_PlasmaMembraneComparison--cp/tables
    Create a GenePattern GCT file?:No
    Select source of sample row name:Metadata
    Select the image to use as the identifier:None
    Select the metadata to use as the identifier:None
    Export all measurements, using default file names?:No
    Press button to select measurements to export:Image\x7CCount_d,Image\x7CFileName_col,Image\x7CIntensity_TotalIntensity_green_TopHat_total,Image\x7CIntensity_TotalIntensity_green_TopHat_d,Image\x7CIntensity_TotalIntensity_green_total,Image\x7CIntensity_TotalIntensity_green_d,Image\x7CIntensity_TotalArea_green_total,Image\x7CIntensity_TotalArea_green_d,Image\x7CPathName_col,Image\x7CMetadata_rootPath,Image\x7CMetadata_treatment,Image\x7CMetadata_Series,Image\x7CMetadata_date,Image\x7CMetadata_Z,Image\x7CMetadata_T
    Data to export:Image
    Combine these object measurements with those of the previous object?:No
    File name:\\g<date>--\\g<treatment>--image.csv
    Use the object name for the file name?:No

CreateBatchFiles:[module_num:20|svn_version:\'11025\'|variable_revision_number:4|show_window:False|notes:\x5B\x5D]
    Store batch files in default output folder?:No
    Output folder path:/g/almf/group/ALMFstuff/Tischi/projects/AleksandarNecakov_deRenzis/Code--Ilastik_CellProfiler
    Are the cluster computers running Windows?:No
    Hidden\x3A in batch mode:No
    Hidden\x3A default input folder at time of save:/home/tischer
    Hidden\x3A SVN revision number:0
    Local root path:/home/tischer
    Cluster root path:/home/tischer
