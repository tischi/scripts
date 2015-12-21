CellProfiler Pipeline: http://www.cellprofiler.org
Version:1
SVNRevision:11047

LoadImages:[module_num:1|svn_version:\'11031\'|variable_revision_number:11|show_window:False|notes:\x5B\x5D]
    File type to be loaded:individual images
    File selection method:Text-Exact match
    Number of images in each group?:3
    Type the text that the excluded images have in common:Do not use
    Analyze all subfolders within the selected folder?:All
    Input image file location:Elsewhere...\x7C/g/almfscreen/embo_cbb_course_2015/Cube5_batch2
    Check image sets for missing or duplicate files?:Yes
    Group images by metadata?:No
    Exclude certain files?:No
    Specify metadata fields to group by:
    Select subfolders to analyze:
    Image count:2
    Text that these images have in common (case-sensitive):Dapi
    Position of this image in each group:1
    Extract metadata from where?:Both
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
    Extract metadata from where?:Both
    Regular expression that finds metadata in the file name:^(?P<FullFilename>.*)
    Type the regular expression that finds metadata in the subfolder path:(?P<FullPath>.*)$
    Channel count:1
    Group the movie frames?:No
    Grouping method:Interleaved
    Number of channels per group:3
    Load the input as images or objects?:Images
    Name this loaded image:GolgiRaw
    Name this loaded object:Nuclei
    Retain outlines of loaded objects?:No
    Name the outline image:LoadedImageOutlines
    Channel number:1
    Rescale intensities?:Yes

RescaleIntensity:[module_num:2|svn_version:\'6746\'|variable_revision_number:2|show_window:False|notes:\x5B\'Rescale to 12bit and subtract background\'\x5D]
    Select the input image:GolgiRaw
    Name the output image:Golgi
    Select rescaling method:Choose specific values to be reset to the full intensity range
    How do you want to calculate the minimum intensity?:Custom
    How do you want to calculate the maximum intensity?:Custom
    Enter the lower limit for the intensity range for the input image:0
    Enter the upper limit for the intensity range for the input image:1
    Enter the intensity range for the input image:0.5003,0.5625
    Enter the desired intensity range for the final, rescaled image:0.000000,1.000000
    Select method for rescaling pixels below the lower limit:Set to zero
    Enter custom value for pixels below lower limit:0
    Select method for rescaling pixels above the upper limit:Set to one
    Enter custom value for pixels below upper limit:0
    Select image to match in maximum intensity:None
    Enter the divisor:1
    Select the measurement to use as a divisor:None

Morph:[module_num:3|svn_version:\'11025\'|variable_revision_number:2|show_window:False|notes:\x5B\'Separates foreground from diffusive background\'\x5D]
    Select the input image:Golgi
    Name the output image:GolgiTophatLarge
    Select the operation to perform:tophat
    Number of times to repeat operation:Once
    Repetition number:2
    Scale:20

Morph:[module_num:4|svn_version:\'11025\'|variable_revision_number:2|show_window:False|notes:\x5B\'Separates small dot or line-like features from blob-like ("compact") features\'\x5D]
    Select the input image:GolgiTophatLarge
    Name the output image:GolgiTophatSmall
    Select the operation to perform:tophat
    Number of times to repeat operation:Once
    Repetition number:2
    Scale:10

Morph:[module_num:5|svn_version:\'11025\'|variable_revision_number:2|show_window:False|notes:\x5B\'Separates tubular from vesicular structures\'\x5D]
    Select the input image:GolgiTophatSmall
    Name the output image:GolgiLines
    Select the operation to perform:openlines
    Number of times to repeat operation:Once
    Repetition number:2
    Scale:30

ImageMath:[module_num:6|svn_version:\'11025\'|variable_revision_number:3|show_window:False|notes:\x5B\x5D]
    Operation:Subtract
    Raise the power of the result by:1
    Multiply the result by:1
    Add to result:0
    Set values less than 0 equal to 0?:Yes
    Set values greater than 1 equal to 1?:Yes
    Ignore the image masks?:No
    Name the output image:GolgiDots
    Image or measurement?:Image
    Select the first image:GolgiTophatSmall
    Multiply the first image by:1
    Measurement:
    Image or measurement?:Image
    Select the second image:GolgiLines
    Multiply the second image by:1
    Measurement:

ImageMath:[module_num:7|svn_version:\'11025\'|variable_revision_number:3|show_window:False|notes:\x5B\x5D]
    Operation:Subtract
    Raise the power of the result by:1
    Multiply the result by:1
    Add to result:0
    Set values less than 0 equal to 0?:Yes
    Set values greater than 1 equal to 1?:Yes
    Ignore the image masks?:No
    Name the output image:GolgiBlobs
    Image or measurement?:Image
    Select the first image:GolgiTophatLarge
    Multiply the first image by:1
    Measurement:
    Image or measurement?:Image
    Select the second image:GolgiTophatSmall
    Multiply the second image by:1
    Measurement:

ImageMath:[module_num:8|svn_version:\'11025\'|variable_revision_number:3|show_window:False|notes:\x5B\x5D]
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
    Select the second image:GolgiTophatLarge
    Multiply the second image by:1
    Measurement:

Smooth:[module_num:9|svn_version:\'11025\'|variable_revision_number:1|show_window:False|notes:\x5B\x5D]
    Select the input image:Dna
    Name the output image:DnaSmooth
    Select smoothing method:Median Filter
    Calculate artifact diameter automatically?:No
    Typical artifact diameter, in  pixels:5
    Edge intensity difference:0.1

IdentifyPrimaryObjects:[module_num:10|svn_version:\'11047\'|variable_revision_number:8|show_window:False|notes:\x5B\x5D]
    Select the input image:DnaSmooth
    Name the primary objects to be identified:NucleiTmpTmp
    Typical diameter of objects, in pixel units (Min,Max):30,1000000
    Discard objects outside the diameter range?:Yes
    Try to merge too small objects with nearby larger objects?:No
    Discard objects touching the border of the image?:Yes
    Select the thresholding method:Otsu Global
    Threshold correction factor:1
    Lower and upper bounds on threshold:0.000000,1.000000
    Approximate fraction of image covered by objects?:0.01
    Method to distinguish clumped objects:Shape
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

IdentifySecondaryObjects:[module_num:11|svn_version:\'11025\'|variable_revision_number:7|show_window:False|notes:\x5B\x5D]
    Select the input objects:NucleiTmpTmp
    Name the objects to be identified:CellsTmp
    Select the method to identify the secondary objects:Distance - N
    Select the input image:Golgi
    Select the thresholding method:Otsu Global
    Threshold correction factor:1
    Lower and upper bounds on threshold:0.000000,1.000000
    Approximate fraction of image covered by objects?:0.01
    Number of pixels by which to expand the primary objects:40
    Regularization factor:0.05
    Name the outline image:CellsOutlines
    Manual threshold:0.0
    Select binary image:None
    Retain outlines of the identified secondary objects?:No
    Two-class or three-class thresholding?:Two classes
    Minimize the weighted variance or the entropy?:Weighted variance
    Assign pixels in the middle intensity class to the foreground or the background?:Foreground
    Discard secondary objects that touch the edge of the image?:Yes
    Discard the associated primary objects?:Yes
    Name the new primary objects:NucleiTmp
    Retain outlines of the new primary objects?:No
    Name the new primary object outlines:NucleiOutlines
    Select the measurement to threshold with:None
    Fill holes in identified objects?:Yes

MeasureObjectIntensity:[module_num:12|svn_version:\'11025\'|variable_revision_number:3|show_window:False|notes:\x5B\x5D]
    Hidden:1
    Select an image to measure:Golgi
    Select objects to measure:CellsTmp

DisplayDataOnImage:[module_num:13|svn_version:\'11025\'|variable_revision_number:2|show_window:False|notes:\x5B\x5D]
    Display object or image measurements?:Object
    Select the input objects:CellsTmp
    Measurement to display:Intensity_MeanIntensity_Golgi
    Select the image on which to display the measurements:Golgi
    Text color:red
    Name the output image that has the measurements displayed:DisplayImage
    Font size (points):10
    Number of decimals:5
    Image elements to save:Image

FilterObjects:[module_num:14|svn_version:\'11025\'|variable_revision_number:5|show_window:False|notes:\x5B\x5D]
    Name the output objects:Cells
    Select the object to filter:CellsTmp
    Filter using classifier rules or measurements?:Measurements
    Select the filtering method:Limits
    Select the objects that contain the filtered objects:None
    Retain outlines of the identified objects?:Yes
    Name the outline image:CellsOutlines
    Rules file location:Default Input Folder\x7CNone
    Rules file name:rules.txt
    Measurement count:1
    Additional object count:1
    Select the measurement to filter by:Intensity_MeanIntensity_Golgi
    Filter using a minimum measurement value?:Yes
    Minimum value:0.002
    Filter using a maximum measurement value?:No
    Maximum value:1
    Select additional object to relabel:NucleiTmp
    Name the relabeled objects:Nuclei
    Retain outlines of relabeled objects?:Yes
    Name the outline image:NucleiOutlines

DisplayDataOnImage:[module_num:15|svn_version:\'11025\'|variable_revision_number:2|show_window:False|notes:\x5B\x5D]
    Display object or image measurements?:Object
    Select the input objects:Cells
    Measurement to display:Location_Center_Y
    Select the image on which to display the measurements:Dna
    Text color:red
    Name the output image that has the measurements displayed:DisplayImage
    Font size (points):10
    Number of decimals:2
    Image elements to save:Image

Crop:[module_num:16|svn_version:\'11025\'|variable_revision_number:2|show_window:False|notes:\x5B\x5D]
    Select the input image:GolgiTophatLarge
    Name the output image:GolgiTopHatLargeCrop
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

IdentifyPrimaryObjects:[module_num:17|svn_version:\'11047\'|variable_revision_number:8|show_window:False|notes:\x5B\x5D]
    Select the input image:GolgiTopHatLargeCrop
    Name the primary objects to be identified:Golgi
    Typical diameter of objects, in pixel units (Min,Max):2,4000
    Discard objects outside the diameter range?:No
    Try to merge too small objects with nearby larger objects?:No
    Discard objects touching the border of the image?:No
    Select the thresholding method:RobustBackground PerObject
    Threshold correction factor:1
    Lower and upper bounds on threshold:0.000000,1.000000
    Approximate fraction of image covered by objects?:0.01
    Method to distinguish clumped objects:None
    Method to draw dividing lines between clumped objects:Intensity
    Size of smoothing filter:10
    Suppress local maxima that are closer than this minimum allowed distance:7
    Speed up by using lower-resolution image to find local maxima?:Yes
    Name the outline image:GolgiOutlines
    Fill holes in identified objects?:No
    Automatically calculate size of smoothing filter?:Yes
    Automatically calculate minimum allowed distance between local maxima?:Yes
    Manual threshold:0.001
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

MaskImage:[module_num:18|svn_version:\'11025\'|variable_revision_number:3|show_window:False|notes:\x5B\x5D]
    Select the input image:GolgiBlobs
    Name the output image:GolgiBlobsMasked
    Use objects or an image as a mask?:Objects
    Select object for mask:Golgi
    Select image for mask:None
    Invert the mask?:No

MaskImage:[module_num:19|svn_version:\'11025\'|variable_revision_number:3|show_window:False|notes:\x5B\x5D]
    Select the input image:GolgiDots
    Name the output image:GolgiDotsMasked
    Use objects or an image as a mask?:Objects
    Select object for mask:Golgi
    Select image for mask:None
    Invert the mask?:No

MaskImage:[module_num:20|svn_version:\'11025\'|variable_revision_number:3|show_window:False|notes:\x5B\x5D]
    Select the input image:GolgiLines
    Name the output image:GolgiLinesMasked
    Use objects or an image as a mask?:Objects
    Select object for mask:Golgi
    Select image for mask:None
    Invert the mask?:No

MeasureObjectIntensity:[module_num:21|svn_version:\'11025\'|variable_revision_number:3|show_window:False|notes:\x5B\x5D]
    Hidden:5
    Select an image to measure:Golgi
    Select an image to measure:GolgiDiffuse
    Select an image to measure:GolgiBlobsMasked
    Select an image to measure:GolgiDotsMasked
    Select an image to measure:GolgiLinesMasked
    Select objects to measure:Cells

Morph:[module_num:22|svn_version:\'11025\'|variable_revision_number:2|show_window:False|notes:\x5B\x5D]
    Select the input image:Dna
    Name the output image:DnaTophat
    Select the operation to perform:tophat
    Number of times to repeat operation:Once
    Repetition number:2
    Scale:5

MeasureObjectIntensity:[module_num:23|svn_version:\'11025\'|variable_revision_number:3|show_window:False|notes:\x5B\x5D]
    Hidden:2
    Select an image to measure:DnaTophat
    Select an image to measure:Dna
    Select objects to measure:Nuclei

MeasureObjectSizeShape:[module_num:24|svn_version:\'1\'|variable_revision_number:1|show_window:False|notes:\x5B\x5D]
    Select objects to measure:Nuclei
    Select objects to measure:Golgi
    Calculate the Zernike features?:No

FilterObjects:[module_num:25|svn_version:\'11025\'|variable_revision_number:5|show_window:False|notes:\x5B\x5D]
    Name the output objects:MaxGolgi
    Select the object to filter:Golgi
    Filter using classifier rules or measurements?:Measurements
    Select the filtering method:Maximal per object
    Select the objects that contain the filtered objects:Cells
    Retain outlines of the identified objects?:No
    Name the outline image:FilteredObjects
    Rules file location:Default Input Folder\x7CNone
    Rules file name:rules.txt
    Measurement count:1
    Additional object count:0
    Select the measurement to filter by:AreaShape_Area
    Filter using a minimum measurement value?:Yes
    Minimum value:0
    Filter using a maximum measurement value?:Yes
    Maximum value:1

MeasureObjectSizeShape:[module_num:26|svn_version:\'1\'|variable_revision_number:1|show_window:False|notes:\x5B\x5D]
    Select objects to measure:MaxGolgi
    Calculate the Zernike features?:No

RescaleIntensity:[module_num:27|svn_version:\'6746\'|variable_revision_number:2|show_window:False|notes:\x5B\x5D]
    Select the input image:Golgi
    Name the output image:GolgiRS
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

RescaleIntensity:[module_num:28|svn_version:\'6746\'|variable_revision_number:2|show_window:False|notes:\x5B\x5D]
    Select the input image:Dna
    Name the output image:DnaRS
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

GrayToColor:[module_num:29|svn_version:\'11025\'|variable_revision_number:2|show_window:False|notes:\x5B\x5D]
    Select a color scheme:RGB
    Select the input image to be colored red:Leave this black
    Select the input image to be colored green:GolgiRS
    Select the input image to be colored blue:DnaRS
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

OverlayOutlines:[module_num:30|svn_version:\'11025\'|variable_revision_number:2|show_window:False|notes:\x5B\x5D]
    Display outlines on a blank image?:No
    Select image on which to display outlines:ColorImage
    Name the output image:Overlay
    Select outline display mode:Color
    Select method to determine brightness of outlines:Max of image
    Width of outlines:2
    Select outlines to display:NucleiOutlines
    Select outline color:Blue
    Select outlines to display:GolgiOutlines
    Select outline color:Green
    Select outlines to display:CellsOutlines
    Select outline color:Red

SaveImages:[module_num:31|svn_version:\'11042\'|variable_revision_number:7|show_window:False|notes:\x5B\x5D]
    Select the type of image to save:Image
    Select the image to save:Overlay
    Select the objects to save:None
    Select the module display window to save:None
    Select method for constructing file names:Single name
    Select image name for file prefix:Dna
    Enter single file name:\\g<platePath>--\\g<Treatment>--\\g<WellNum>--\\g<PosNum>--overlay
    Do you want to add a suffix to the image file name?:Yes
    Text to append to the image name:--seg
    Select file format to use:png
    Output file location:Elsewhere...\x7C\\g<rootPath>--cp/images
    Image bit depth:8
    Overwrite existing files without warning?:Yes
    Select how often to save:Every cycle
    Rescale the images? :Yes
    Save as grayscale or color image?:Grayscale
    Select colormap:gray
    Store file and path information to the saved image?:Yes
    Create subfolders in the output folder?:No

SaveImages:[module_num:32|svn_version:\'11042\'|variable_revision_number:7|show_window:False|notes:\x5B\x5D]
    Select the type of image to save:Image
    Select the image to save:GolgiRS
    Select the objects to save:None
    Select the module display window to save:None
    Select method for constructing file names:Single name
    Select image name for file prefix:Dna
    Enter single file name:\\g<platePath>--\\g<Treatment>--\\g<WellNum>--\\g<PosNum>--Golgi
    Do you want to add a suffix to the image file name?:Yes
    Text to append to the image name:--seg
    Select file format to use:png
    Output file location:Elsewhere...\x7C\\g<rootPath>--cp/images
    Image bit depth:8
    Overwrite existing files without warning?:Yes
    Select how often to save:Every cycle
    Rescale the images? :Yes
    Save as grayscale or color image?:Grayscale
    Select colormap:gray
    Store file and path information to the saved image?:Yes
    Create subfolders in the output folder?:No

MeasureImageQuality:[module_num:33|svn_version:\'11045\'|variable_revision_number:4|show_window:False|notes:\x5B\x5D]
    Calculate metrics for which images?:Select...
    Image count:1
    Scale count:1
    Threshold count:1
    Select the images to measure:Dna
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

RelateObjects:[module_num:34|svn_version:\'11025\'|variable_revision_number:2|show_window:False|notes:\x5B\x5D]
    Select the input child objects:Golgi
    Select the input parent objects:Cells
    Calculate distances?:None
    Calculate per-parent means for all child measurements?:Yes
    Calculate distances to other parents?:No
    Parent name:None

RelateObjects:[module_num:35|svn_version:\'11025\'|variable_revision_number:2|show_window:False|notes:\x5B\x5D]
    Select the input child objects:Nuclei
    Select the input parent objects:Cells
    Calculate distances?:None
    Calculate per-parent means for all child measurements?:Yes
    Calculate distances to other parents?:No
    Parent name:None

RelateObjects:[module_num:36|svn_version:\'11025\'|variable_revision_number:2|show_window:False|notes:\x5B\x5D]
    Select the input child objects:MaxGolgi
    Select the input parent objects:Cells
    Calculate distances?:None
    Calculate per-parent means for all child measurements?:Yes
    Calculate distances to other parents?:No
    Parent name:None

ExportToSpreadsheet:[module_num:37|svn_version:\'11042\'|variable_revision_number:7|show_window:False|notes:\x5B\x5D]
    Select or enter the column delimiter:Comma (",")
    Prepend the output file name to the data file names?:No
    Add image metadata columns to your object data file?:Yes
    Limit output to a size that is allowed in Excel?:No
    Select the columns of measurements to export?:Yes
    Calculate the per-image mean values for object measurements?:Yes
    Calculate the per-image median values for object measurements?:No
    Calculate the per-image standard deviation values for object measurements?:No
    Output file location:Elsewhere...\x7C\\g<rootPath>--cp/tables
    Create a GenePattern GCT file?:No
    Select source of sample row name:Metadata
    Select the image to use as the identifier:None
    Select the metadata to use as the identifier:None
    Export all measurements, using default file names?:No
    Press button to select measurements to export:Image\x7CCount_Nuclei,Image\x7CImageQuality_PowerLogLogSlope_Dna,Image\x7CFileName_GolgiRaw,Image\x7CFileName_Dna,Image\x7CFileName_GolgiRS,Image\x7CFileName_Overlay,Image\x7CPathName_GolgiRaw,Image\x7CPathName_Dna,Image\x7CPathName_GolgiRS,Image\x7CPathName_Overlay,Image\x7CMetadata_PosNum,Image\x7CMetadata_platePath,Image\x7CMetadata_FullFilename,Image\x7CMetadata_rootPath,Image\x7CMetadata_WellNum,Image\x7CMetadata_Treatment,Image\x7CMetadata_FullPath,Nuclei\x7CAreaShape_Area,Cells\x7CIntensity_IntegratedIntensity_GolgiLinesMasked,Cells\x7CIntensity_IntegratedIntensity_GolgiDotsMasked,Cells\x7CIntensity_IntegratedIntensity_GolgiDiffuse,Cells\x7CIntensity_IntegratedIntensity_Golgi,Cells\x7CIntensity_IntegratedIntensity_GolgiBlobsMasked,Cells\x7CLocation_Center_Y,Cells\x7CLocation_Center_X,Cells\x7CChildren_Nuclei_Count,Cells\x7CChildren_MaxGolgi_Count,Cells\x7CChildren_Golgi_Count,Cells\x7CMean_Nuclei_Intensity_IntegratedIntensity_DnaTophat,Cells\x7CMean_Nuclei_Intensity_IntegratedIntensity_Dna,Cells\x7CMean_Nuclei_AreaShape_FormFactor,Cells\x7CMean_Nuclei_AreaShape_Area,Cells\x7CMean_MaxGolgi_AreaShape_FormFactor,Cells\x7CMean_MaxGolgi_AreaShape_Area,Cells\x7CMean_MaxGolgi_AreaShape_Compactness,Cells\x7CMean_Golgi_AreaShape_Area
    Data to export:Image
    Combine these object measurements with those of the previous object?:No
    File name:\\g<platePath>--W\\g<WellNum>--P\\g<PosNum>--image.csv
    Use the object name for the file name?:No
    Data to export:Cells
    Combine these object measurements with those of the previous object?:No
    File name:\\g<platePath>--W\\g<WellNum>--P\\g<PosNum>--objects.csv
    Use the object name for the file name?:No

CreateBatchFiles:[module_num:38|svn_version:\'11025\'|variable_revision_number:4|show_window:False|notes:\x5B\x5D]
    Store batch files in default output folder?:No
    Output folder path:/g/almfscreen/embo_cbb_course_2015
    Are the cluster computers running Windows?:No
    Hidden\x3A in batch mode:No
    Hidden\x3A default input folder at time of save:/home/tischer
    Hidden\x3A SVN revision number:0
    Local root path:/home/tischer
    Cluster root path:/home/tischer
