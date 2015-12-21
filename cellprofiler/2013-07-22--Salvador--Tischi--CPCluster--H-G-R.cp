CellProfiler Pipeline: http://www.cellprofiler.org
Version:1
SVNRevision:11047

LoadImages:[module_num:1|svn_version:\'11031\'|variable_revision_number:11|show_window:False|notes:\x5B\x5D]
    File type to be loaded:individual images
    File selection method:Text-Exact match
    Number of images in each group?:3
    Type the text that the excluded images have in common:Do not use
    Analyze all subfolders within the selected folder?:All
    Input image file location:Default Output Folder sub-folder\x7Ctest
    Check image sets for missing or duplicate files?:Yes
    Group images by metadata?:No
    Exclude certain files?:No
    Specify metadata fields to group by:
    Select subfolders to analyze:
    Image count:3
    Text that these images have in common (case-sensitive):C01
    Position of this image in each group:1
    Extract metadata from where?:Both
    Regular expression that finds metadata in the file name:^(?P<platename>.*)--(?P<gene>.*)--(?P<siRNA>.*)--W(?P<wellNum>.*)--P(?P<posNum>.*)--T(?P<time>.*)--Z(?P<z>.*)--(?P<ch>.*)
    Type the regular expression that finds metadata in the subfolder path:(?P<rootPath>.*)\x5B\\\\/\x5D(?P<platePath>.*)\x5B\\\\/\x5D(?P<wellPath>.*)\x5B\\\\/\x5D(?P<posPath>.*)
    Channel count:1
    Group the movie frames?:No
    Grouping method:Interleaved
    Number of channels per group:3
    Load the input as images or objects?:Images
    Name this loaded image:Nuclei
    Name this loaded object:Nuclei
    Retain outlines of loaded objects?:No
    Name the outline image:LoadedImageOutlines
    Channel number:1
    Rescale intensities?:No
    Text that these images have in common (case-sensitive):C02
    Position of this image in each group:2
    Extract metadata from where?:File name
    Regular expression that finds metadata in the file name:^(?P<filenameBase>.*)--T(?P<dum1>.*)--(?P<dum2>.*)
    Type the regular expression that finds metadata in the subfolder path:.*\x5B\\\\/\x5D(?P<Date>.*)\x5B\\\\/\x5D(?P<Run>.*)$
    Channel count:1
    Group the movie frames?:No
    Grouping method:Interleaved
    Number of channels per group:3
    Load the input as images or objects?:Images
    Name this loaded image:LKB1
    Name this loaded object:Nuclei
    Retain outlines of loaded objects?:No
    Name the outline image:LoadedImageOutlines
    Channel number:1
    Rescale intensities?:No
    Text that these images have in common (case-sensitive):C03
    Position of this image in each group:3
    Extract metadata from where?:None
    Regular expression that finds metadata in the file name:^(?P<Plate>.*)_(?P<Well>\x5BA-P\x5D\x5B0-9\x5D{2})_s(?P<Site>\x5B0-9\x5D)
    Type the regular expression that finds metadata in the subfolder path:.*\x5B\\\\/\x5D(?P<Date>.*)\x5B\\\\/\x5D(?P<Run>.*)$
    Channel count:1
    Group the movie frames?:No
    Grouping method:Interleaved
    Number of channels per group:3
    Load the input as images or objects?:Images
    Name this loaded image:MOCK
    Name this loaded object:Nuclei
    Retain outlines of loaded objects?:No
    Name the outline image:LoadedImageOutlines
    Channel number:1
    Rescale intensities?:No

IdentifyPrimaryObjects:[module_num:2|svn_version:\'11047\'|variable_revision_number:8|show_window:False|notes:\x5B\x5D]
    Select the input image:Nuclei
    Name the primary objects to be identified:Nuclei
    Typical diameter of objects, in pixel units (Min,Max):7,10000000
    Discard objects outside the diameter range?:Yes
    Try to merge too small objects with nearby larger objects?:Yes
    Discard objects touching the border of the image?:Yes
    Select the thresholding method:Otsu Global
    Threshold correction factor:0.85
    Lower and upper bounds on threshold:0.000000,1.000000
    Approximate fraction of image covered by objects?:0.01
    Method to distinguish clumped objects:Shape
    Method to draw dividing lines between clumped objects:Shape
    Size of smoothing filter:3
    Suppress local maxima that are closer than this minimum allowed distance:10
    Speed up by using lower-resolution image to find local maxima?:Yes
    Name the outline image:NucleiOutlines
    Fill holes in identified objects?:Yes
    Automatically calculate size of smoothing filter?:No
    Automatically calculate minimum allowed distance between local maxima?:No
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

MeasureObjectIntensity:[module_num:3|svn_version:\'11025\'|variable_revision_number:3|show_window:False|notes:\x5B\x5D]
    Hidden:3
    Select an image to measure:LKB1
    Select an image to measure:MOCK
    Select an image to measure:Nuclei
    Select objects to measure:Nuclei

MeasureObjectSizeShape:[module_num:4|svn_version:\'1\'|variable_revision_number:1|show_window:False|notes:\x5B\x5D]
    Select objects to measure:Nuclei
    Calculate the Zernike features?:Yes

DisplayDataOnImage:[module_num:5|svn_version:\'11025\'|variable_revision_number:2|show_window:True|notes:\x5B\x5D]
    Display object or image measurements?:Object
    Select the input objects:Nuclei
    Measurement to display:Intensity_MeanIntensity_MOCK
    Select the image on which to display the measurements:MOCK
    Text color:red
    Name the output image that has the measurements displayed:DisplayImage
    Font size (points):10
    Number of decimals:5
    Image elements to save:Image

DisplayDataOnImage:[module_num:6|svn_version:\'11025\'|variable_revision_number:2|show_window:True|notes:\x5B\x5D]
    Display object or image measurements?:Object
    Select the input objects:Nuclei
    Measurement to display:Intensity_MeanIntensity_LKB1
    Select the image on which to display the measurements:LKB1
    Text color:green
    Name the output image that has the measurements displayed:DisplayImage
    Font size (points):10
    Number of decimals:4
    Image elements to save:Image

FilterObjects:[module_num:7|svn_version:\'11025\'|variable_revision_number:5|show_window:False|notes:\x5B\'Red=MOCK\'\x5D]
    Name the output objects:MOCK
    Select the object to filter:Nuclei
    Filter using classifier rules or measurements?:Measurements
    Select the filtering method:Limits
    Select the objects that contain the filtered objects:None
    Retain outlines of the identified objects?:Yes
    Name the outline image:MOCKOutlines
    Rules file location:Default Input Folder\x7CNone
    Rules file name:rules.txt
    Measurement count:1
    Additional object count:0
    Select the measurement to filter by:Intensity_MeanIntensity_MOCK
    Filter using a minimum measurement value?:Yes
    Minimum value:0.014
    Filter using a maximum measurement value?:No
    Maximum value:1

FilterObjects:[module_num:8|svn_version:\'11025\'|variable_revision_number:5|show_window:False|notes:\x5B\'\'\x5D]
    Name the output objects:LKB1
    Select the object to filter:Nuclei
    Filter using classifier rules or measurements?:Measurements
    Select the filtering method:Limits
    Select the objects that contain the filtered objects:None
    Retain outlines of the identified objects?:Yes
    Name the outline image:LKB1Outlines
    Rules file location:Default Input Folder\x7CNone
    Rules file name:rules.txt
    Measurement count:2
    Additional object count:0
    Select the measurement to filter by:Intensity_MeanIntensity_LKB1
    Filter using a minimum measurement value?:Yes
    Minimum value:0.0042
    Filter using a maximum measurement value?:No
    Maximum value:1
    Select the measurement to filter by:Intensity_MeanIntensity_MOCK
    Filter using a minimum measurement value?:No
    Minimum value:0
    Filter using a maximum measurement value?:Yes
    Maximum value:0.014

CalculateMath:[module_num:9|svn_version:\'11025\'|variable_revision_number:1|show_window:False|notes:\x5B\x5D]
    Name the output measurement:LKB1divMOCK
    Operation:Divide
    Select the numerator measurement type:Image
    Select the numerator objects:None
    Select the numerator measurement:Count_LKB1
    Multiply the above operand by:1.0
    Raise the power of above operand by:1
    Select the denominator measurement type:Image
    Select the denominator objects:None
    Select the denominator measurement:Count_MOCK
    Multiply the above operand by:1
    Raise the power of above operand by:1
    Take log10 of result?:No
    Multiply the result by:1
    Raise the power of result by:1

CalculateMath:[module_num:10|svn_version:\'11025\'|variable_revision_number:1|show_window:False|notes:\x5B\x5D]
    Name the output measurement:LKB1plusMOCK
    Operation:Add
    Select the first operand measurement type:Image
    Select the first operand objects:None
    Select the first operand measurement:Count_LKB1
    Multiply the above operand by:1
    Raise the power of above operand by:1
    Select the second operand measurement type:Image
    Select the second operand objects:None
    Select the second operand measurement:Count_MOCK
    Multiply the above operand by:1
    Raise the power of above operand by:1
    Take log10 of result?:No
    Multiply the result by:1
    Raise the power of result by:1

CalculateMath:[module_num:11|svn_version:\'11025\'|variable_revision_number:1|show_window:False|notes:\x5B\x5D]
    Name the output measurement:LKB1plusMOCKdivNUC
    Operation:Divide
    Select the numerator measurement type:Image
    Select the numerator objects:None
    Select the numerator measurement:Math_LKB1plusMOCK
    Multiply the above operand by:1
    Raise the power of above operand by:1
    Select the denominator measurement type:Image
    Select the denominator objects:None
    Select the denominator measurement:Count_Nuclei
    Multiply the above operand by:1
    Raise the power of above operand by:1
    Take log10 of result?:No
    Multiply the result by:1
    Raise the power of result by:1

ExpandOrShrinkObjects:[module_num:12|svn_version:\'11025\'|variable_revision_number:1|show_window:False|notes:\x5B\x5D]
    Select the input objects:Nuclei
    Name the output objects:ShrunkenNuclei
    Select the operation:Shrink objects by a specified number of pixels
    Number of pixels by which to expand or shrink:2
    Fill holes in objects so that all objects shrink to a single point?:No
    Retain the outlines of the identified objects for use later in the pipeline (for example, in SaveImages)?:Yes
    Name the outline image:ShrunkenNucleiOutlines

GrayToColor:[module_num:13|svn_version:\'11025\'|variable_revision_number:2|show_window:False|notes:\x5B\x5D]
    Select a color scheme:RGB
    Select the input image to be colored red:MOCK
    Select the input image to be colored green:LKB1
    Select the input image to be colored blue:Nuclei
    Name the output image:ColorImage
    Relative weight for the red image:1
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

OverlayOutlines:[module_num:14|svn_version:\'11025\'|variable_revision_number:2|show_window:False|notes:\x5B\x5D]
    Display outlines on a blank image?:No
    Select image on which to display outlines:ColorImage
    Name the output image:Overlay
    Select outline display mode:Color
    Select method to determine brightness of outlines:Max of image
    Width of outlines:2
    Select outlines to display:LKB1Outlines
    Select outline color:Green
    Select outlines to display:MOCKOutlines
    Select outline color:Red
    Select outlines to display:ShrunkenNucleiOutlines
    Select outline color:White

SaveImages:[module_num:15|svn_version:\'11042\'|variable_revision_number:7|show_window:False|notes:\x5B\x5D]
    Select the type of image to save:Image
    Select the image to save:Overlay
    Select the objects to save:None
    Select the module display window to save:None
    Select method for constructing file names:Single name
    Select image name for file prefix:Nuclei
    Enter single file name:\\g<filenameBase>--overlay
    Do you want to add a suffix to the image file name?:Yes
    Text to append to the image name:--segmentation
    Select file format to use:tif
    Output file location:Elsewhere...\x7C\\g<rootPath>/\\g<platePath>--cellprofiler
    Image bit depth:8
    Overwrite existing files without warning?:Yes
    Select how often to save:Every cycle
    Rescale the images? :Yes
    Save as grayscale or color image?:Grayscale
    Select colormap:gray
    Store file and path information to the saved image?:Yes
    Create subfolders in the output folder?:No

ExportToSpreadsheet:[module_num:16|svn_version:\'11042\'|variable_revision_number:7|show_window:False|notes:\x5B\x5D]
    Select or enter the column delimiter:Comma (",")
    Prepend the output file name to the data file names?:No
    Add image metadata columns to your object data file?:Yes
    Limit output to a size that is allowed in Excel?:No
    Select the columns of measurements to export?:Yes
    Calculate the per-image mean values for object measurements?:Yes
    Calculate the per-image median values for object measurements?:Yes
    Calculate the per-image standard deviation values for object measurements?:Yes
    Output file location:Elsewhere...\x7C\\g<rootPath>/\\g<platePath>--cellprofiler/W\\g<wellNum>/P\\g<posNum>
    Create a GenePattern GCT file?:No
    Select source of sample row name:Metadata
    Select the image to use as the identifier:None
    Select the metadata to use as the identifier:None
    Export all measurements, using default file names?:No
    Press button to select measurements to export:Image\x7CCount_LKB1,Image\x7CCount_Nuclei,Image\x7CCount_MOCK,Image\x7CFileName_LKB1,Image\x7CFileName_Nuclei,Image\x7CFileName_MOCK,Image\x7CFileName_Overlay,Image\x7CPathName_LKB1,Image\x7CPathName_Nuclei,Image\x7CPathName_MOCK,Image\x7CPathName_Overlay,Image\x7CMath_LKB1divMOCK,Image\x7CMath_LKB1plusMOCK,Image\x7CMath_LKB1plusMOCKdivNUC,Image\x7CMetadata_posNum,Image\x7CMetadata_platePath,Image\x7CMetadata_platename,Image\x7CMetadata_rootPath,Image\x7CMetadata_wellNum,Image\x7CMetadata_filenameBase,Image\x7CMetadata_posPath,Image\x7CMetadata_gene,Image\x7CMetadata_siRNA,Image\x7CMetadata_wellPath,Nuclei\x7CIntensity_MeanIntensity_LKB1,Nuclei\x7CIntensity_MeanIntensity_Nuclei,Nuclei\x7CIntensity_MeanIntensity_MOCK,Nuclei\x7CAreaShape_FormFactor,Nuclei\x7CAreaShape_Area
    Data to export:Image
    Combine these object measurements with those of the previous object?:No
    File name:image.csv
    Use the object name for the file name?:No
    Data to export:Nuclei
    Combine these object measurements with those of the previous object?:No
    File name:objects.csv
    Use the object name for the file name?:No
    Data to export:ShrunkenNuclei
    Combine these object measurements with those of the previous object?:Yes
    File name:DATA.csv
    Use the object name for the file name?:Yes

CreateBatchFiles:[module_num:17|svn_version:\'11025\'|variable_revision_number:4|show_window:False|notes:\x5B\x5D]
    Store batch files in default output folder?:Yes
    Output folder path:
    Are the cluster computers running Windows?:No
    Hidden\x3A in batch mode:No
    Hidden\x3A default input folder at time of save:/home/sarodrig
    Hidden\x3A SVN revision number:0
    Local root path:/home/sarodrig
    Cluster root path:/home/sarodrig
