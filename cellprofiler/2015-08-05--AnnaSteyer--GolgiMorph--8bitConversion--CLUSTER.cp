CellProfiler Pipeline: http://www.cellprofiler.org
Version:1
SVNRevision:11047

LoadImages:[module_num:1|svn_version:\'11031\'|variable_revision_number:11|show_window:True|notes:\x5B\x5D]
    File type to be loaded:individual images
    File selection method:Text-Exact match
    Number of images in each group?:3
    Type the text that the excluded images have in common:Do not use
    Analyze all subfolders within the selected folder?:All
    Input image file location:Elsewhere...\x7C/g/almfscreen/steyer
    Check image sets for missing or duplicate files?:Yes
    Group images by metadata?:No
    Exclude certain files?:No
    Specify metadata fields to group by:
    Select subfolders to analyze:
    Image count:2
    Text that these images have in common (case-sensitive):C02.ome.tif
    Position of this image in each group:1
    Extract metadata from where?:Both
    Regular expression that finds metadata in the file name:^(?P<plate>.*)--(?P<siRNA>.*)--(?P<gene>.*)--W(?P<wellNum>.*)--P(?P<posNum>.*)--T(?P<timeNum>.*)--Z(?P<zNum>.*)--(?P<channel>.*).ome.tif
    Type the regular expression that finds metadata in the subfolder path:(?P<rootPath>.*)\x5B\\\\/\x5D(?P<dum3>.*)\x5B\\\\/\x5D(?P<dum2>.*)\x5B\\\\/\x5D(?P<dum1>.*)$
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
    Text that these images have in common (case-sensitive):C01.ome.tif
    Position of this image in each group:2
    Extract metadata from where?:None
    Regular expression that finds metadata in the file name:^(?P<Plate>.*)_(?P<Well>\x5BA-P\x5D\x5B0-9\x5D{2})_s(?P<Site>\x5B0-9\x5D)
    Type the regular expression that finds metadata in the subfolder path:.*\x5B\\\\/\x5D(?P<Date>.*)\x5B\\\\/\x5D(?P<Run>.*)$
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

RescaleIntensity:[module_num:2|svn_version:\'6746\'|variable_revision_number:2|show_window:True|notes:\x5B\x5D]
    Select the input image:Golgi
    Name the output image:GolgiRS
    Select rescaling method:Choose specific values to be reset to the full intensity range
    How do you want to calculate the minimum intensity?:Custom
    How do you want to calculate the maximum intensity?:Custom
    Enter the lower limit for the intensity range for the input image:0
    Enter the upper limit for the intensity range for the input image:1
    Enter the intensity range for the input image:0.0,0.0625
    Enter the desired intensity range for the final, rescaled image:0.000000,1.000000
    Select method for rescaling pixels below the lower limit:Set to zero
    Enter custom value for pixels below lower limit:0
    Select method for rescaling pixels above the upper limit:Set to one
    Enter custom value for pixels below upper limit:0
    Select image to match in maximum intensity:None
    Enter the divisor:1
    Select the measurement to use as a divisor:None

SaveImages:[module_num:3|svn_version:\'11042\'|variable_revision_number:7|show_window:True|notes:\x5B\x5D]
    Select the type of image to save:Image
    Select the image to save:GolgiRS
    Select the objects to save:None
    Select the module display window to save:None
    Select method for constructing file names:From image filename
    Select image name for file prefix:Golgi
    Enter single file name:OrigBlue
    Do you want to add a suffix to the image file name?:Yes
    Text to append to the image name:--8bit
    Select file format to use:tif
    Output file location:Same folder as image\x7CNone
    Image bit depth:8
    Overwrite existing files without warning?:Yes
    Select how often to save:Every cycle
    Rescale the images? :Yes
    Save as grayscale or color image?:Grayscale
    Select colormap:gray
    Store file and path information to the saved image?:No
    Create subfolders in the output folder?:No

CreateBatchFiles:[module_num:4|svn_version:\'11025\'|variable_revision_number:4|show_window:True|notes:\x5B\x5D]
    Store batch files in default output folder?:No
    Output folder path:/g/almfscreen/steyer/
    Are the cluster computers running Windows?:No
    Hidden\x3A in batch mode:No
    Hidden\x3A default input folder at time of save:/home/tischer
    Hidden\x3A SVN revision number:0
    Local root path:/home/tischer
    Cluster root path:/home/tischer
