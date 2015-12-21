CellProfiler Pipeline: http://www.cellprofiler.org
Version:1
SVNRevision:11047

LoadImages:[module_num:1|svn_version:\'11031\'|variable_revision_number:11|show_window:False|notes:\x5B\x5D]
    File type to be loaded:individual images
    File selection method:Text-Exact match
    Number of images in each group?:3
    Type the text that the excluded images have in common:Do not use
    Analyze all subfolders within the selected folder?:All
    Input image file location:Elsewhere...\x7C/g/gavin/projects/Liposome_screen/15-09-23_run1847to1850
    Check image sets for missing or duplicate files?:No
    Group images by metadata?:No
    Exclude certain files?:No
    Specify metadata fields to group by:lipidID
    Select subfolders to analyze:
    Image count:13
    Text that these images have in common (case-sensitive):Cy5_3ms.ome.tif
    Position of this image in each group:1
    Extract metadata from where?:File name
    Regular expression that finds metadata in the file name:^(?P<plateName>.*)_(?P<plateRepl>.*)--(?P<lipid>.*)--(?P<protein>.*)--W(?P<wellNum>.*)--P(?P<pos>.*)--T(?P<time>.*)--(?P<z>.*)--(?P<channel>.*)
    Type the regular expression that finds metadata in the subfolder path:.*\x5B\\\\/\x5D(?P<run>.*)\x5B\\\\/\x5D(?P<well>.*)\x5B\\\\/\x5D(?P<position>.*)$
    Channel count:1
    Group the movie frames?:No
    Grouping method:Interleaved
    Number of channels per group:3
    Load the input as images or objects?:Images
    Name this loaded image:lipid_raw_3ms
    Name this loaded object:Nuclei
    Retain outlines of loaded objects?:No
    Name the outline image:LoadedImageOutlines
    Channel number:1
    Rescale intensities?:Yes
    Text that these images have in common (case-sensitive):gfp_1ms.ome.tif
    Position of this image in each group:2
    Extract metadata from where?:Path
    Regular expression that finds metadata in the file name:^(?P<Plate>.*)_(?P<Well>\x5BA-P\x5D\x5B0-9\x5D{2})_s(?P<Site>\x5B0-9\x5D)
    Type the regular expression that finds metadata in the subfolder path:(?P<rootPath>.*)\x5B\\\\/\x5D(?P<runPath>.*)\x5B\\\\/\x5D(?P<wellPath>.*)\x5B\\\\/\x5D(?P<posPath>.*)$
    Channel count:1
    Group the movie frames?:No
    Grouping method:Interleaved
    Number of channels per group:3
    Load the input as images or objects?:Images
    Name this loaded image:protein_raw_1ms
    Name this loaded object:Nuclei
    Retain outlines of loaded objects?:No
    Name the outline image:LoadedImageOutlines
    Channel number:1
    Rescale intensities?:Yes
    Text that these images have in common (case-sensitive):gfp_5ms.ome.tif
    Position of this image in each group:4
    Extract metadata from where?:None
    Regular expression that finds metadata in the file name:^(?P<Plate>.*)_(?P<Well>\x5BA-P\x5D\x5B0-9\x5D{2})_s(?P<Site>\x5B0-9\x5D)
    Type the regular expression that finds metadata in the subfolder path:.*\x5B\\\\/\x5D(?P<Date>.*)\x5B\\\\/\x5D(?P<Run>.*)$
    Channel count:1
    Group the movie frames?:No
    Grouping method:Interleaved
    Number of channels per group:3
    Load the input as images or objects?:Images
    Name this loaded image:protein_raw_5ms
    Name this loaded object:Nuclei
    Retain outlines of loaded objects?:No
    Name the outline image:LoadedImageOutlines
    Channel number:1
    Rescale intensities?:Yes
    Text that these images have in common (case-sensitive):gfp_10ms.ome.tif
    Position of this image in each group:6
    Extract metadata from where?:None
    Regular expression that finds metadata in the file name:^(?P<Plate>.*)_(?P<Well>\x5BA-P\x5D\x5B0-9\x5D{2})_s(?P<Site>\x5B0-9\x5D)
    Type the regular expression that finds metadata in the subfolder path:.*\x5B\\\\/\x5D(?P<Date>.*)\x5B\\\\/\x5D(?P<Run>.*)$
    Channel count:1
    Group the movie frames?:No
    Grouping method:Interleaved
    Number of channels per group:3
    Load the input as images or objects?:Images
    Name this loaded image:protein_raw_10ms
    Name this loaded object:Nuclei
    Retain outlines of loaded objects?:No
    Name the outline image:LoadedImageOutlines
    Channel number:1
    Rescale intensities?:Yes
    Text that these images have in common (case-sensitive):gfp_30ms.ome.tif
    Position of this image in each group:13
    Extract metadata from where?:None
    Regular expression that finds metadata in the file name:^(?P<Plate>.*)_(?P<Well>\x5BA-P\x5D\x5B0-9\x5D{2})_s(?P<Site>\x5B0-9\x5D)
    Type the regular expression that finds metadata in the subfolder path:.*\x5B\\\\/\x5D(?P<Date>.*)\x5B\\\\/\x5D(?P<Run>.*)$
    Channel count:1
    Group the movie frames?:No
    Grouping method:Interleaved
    Number of channels per group:3
    Load the input as images or objects?:Images
    Name this loaded image:protein_raw_30ms
    Name this loaded object:Nuclei
    Retain outlines of loaded objects?:No
    Name the outline image:LoadedImageOutlines
    Channel number:1
    Rescale intensities?:Yes
    Text that these images have in common (case-sensitive):gfp_50ms.ome.tif
    Position of this image in each group:7
    Extract metadata from where?:None
    Regular expression that finds metadata in the file name:^(?P<Plate>.*)_(?P<Well>\x5BA-P\x5D\x5B0-9\x5D{2})_s(?P<Site>\x5B0-9\x5D)
    Type the regular expression that finds metadata in the subfolder path:.*\x5B\\\\/\x5D(?P<Date>.*)\x5B\\\\/\x5D(?P<Run>.*)$
    Channel count:1
    Group the movie frames?:No
    Grouping method:Interleaved
    Number of channels per group:3
    Load the input as images or objects?:Images
    Name this loaded image:protein_raw_50ms
    Name this loaded object:Nuclei
    Retain outlines of loaded objects?:No
    Name the outline image:LoadedImageOutlines
    Channel number:1
    Rescale intensities?:Yes
    Text that these images have in common (case-sensitive):gfp_75ms.ome.tif
    Position of this image in each group:8
    Extract metadata from where?:None
    Regular expression that finds metadata in the file name:^(?P<Plate>.*)_(?P<Well>\x5BA-P\x5D\x5B0-9\x5D{2})_s(?P<Site>\x5B0-9\x5D)
    Type the regular expression that finds metadata in the subfolder path:(?P<rootPath>.*)\x5B\\\\/\x5D(?P<runPath>.*)\x5B\\\\/\x5D(?P<wellPath>.*)\x5B\\\\/\x5D(?P<posPath>.*)$
    Channel count:1
    Group the movie frames?:No
    Grouping method:Interleaved
    Number of channels per group:3
    Load the input as images or objects?:Images
    Name this loaded image:protein_raw_75ms
    Name this loaded object:Nuclei
    Retain outlines of loaded objects?:No
    Name the outline image:LoadedImageOutlines
    Channel number:1
    Rescale intensities?:Yes
    Text that these images have in common (case-sensitive):gfp_100ms.ome.tif
    Position of this image in each group:9
    Extract metadata from where?:None
    Regular expression that finds metadata in the file name:^(?P<Plate>.*)_(?P<Well>\x5BA-P\x5D\x5B0-9\x5D{2})_s(?P<Site>\x5B0-9\x5D)
    Type the regular expression that finds metadata in the subfolder path:.*\x5B\\\\/\x5D(?P<Date>.*)\x5B\\\\/\x5D(?P<Run>.*)$
    Channel count:1
    Group the movie frames?:No
    Grouping method:Interleaved
    Number of channels per group:3
    Load the input as images or objects?:Images
    Name this loaded image:protein_raw_100ms
    Name this loaded object:Nuclei
    Retain outlines of loaded objects?:No
    Name the outline image:LoadedImageOutlines
    Channel number:1
    Rescale intensities?:Yes
    Text that these images have in common (case-sensitive):gfp_200ms.ome.tif
    Position of this image in each group:9
    Extract metadata from where?:None
    Regular expression that finds metadata in the file name:^(?P<Plate>.*)_(?P<Well>\x5BA-P\x5D\x5B0-9\x5D{2})_s(?P<Site>\x5B0-9\x5D)
    Type the regular expression that finds metadata in the subfolder path:.*\x5B\\\\/\x5D(?P<Date>.*)\x5B\\\\/\x5D(?P<Run>.*)$
    Channel count:1
    Group the movie frames?:No
    Grouping method:Interleaved
    Number of channels per group:3
    Load the input as images or objects?:Images
    Name this loaded image:protein_raw_200ms
    Name this loaded object:Nuclei
    Retain outlines of loaded objects?:No
    Name the outline image:LoadedImageOutlines
    Channel number:1
    Rescale intensities?:Yes
    Text that these images have in common (case-sensitive):gfp_300ms.ome.tif
    Position of this image in each group:10
    Extract metadata from where?:None
    Regular expression that finds metadata in the file name:^(?P<Plate>.*)_(?P<Well>\x5BA-P\x5D\x5B0-9\x5D{2})_s(?P<Site>\x5B0-9\x5D)
    Type the regular expression that finds metadata in the subfolder path:.*\x5B\\\\/\x5D(?P<Date>.*)\x5B\\\\/\x5D(?P<Run>.*)$
    Channel count:1
    Group the movie frames?:No
    Grouping method:Interleaved
    Number of channels per group:3
    Load the input as images or objects?:Images
    Name this loaded image:protein_raw_300ms
    Name this loaded object:Nuclei
    Retain outlines of loaded objects?:No
    Name the outline image:LoadedImageOutlines
    Channel number:1
    Rescale intensities?:Yes
    Text that these images have in common (case-sensitive):gfp_1000ms.ome.tif
    Position of this image in each group:11
    Extract metadata from where?:None
    Regular expression that finds metadata in the file name:^(?P<Plate>.*)_(?P<Well>\x5BA-P\x5D\x5B0-9\x5D{2})_s(?P<Site>\x5B0-9\x5D)
    Type the regular expression that finds metadata in the subfolder path:.*\x5B\\\\/\x5D(?P<Date>.*)\x5B\\\\/\x5D(?P<Run>.*)$
    Channel count:1
    Group the movie frames?:No
    Grouping method:Interleaved
    Number of channels per group:3
    Load the input as images or objects?:Images
    Name this loaded image:protein_raw_1000ms
    Name this loaded object:Nuclei
    Retain outlines of loaded objects?:No
    Name the outline image:LoadedImageOutlines
    Channel number:1
    Rescale intensities?:Yes
    Text that these images have in common (case-sensitive):gfp_2000ms.ome.tif
    Position of this image in each group:12
    Extract metadata from where?:None
    Regular expression that finds metadata in the file name:^(?P<Plate>.*)_(?P<Well>\x5BA-P\x5D\x5B0-9\x5D{2})_s(?P<Site>\x5B0-9\x5D)
    Type the regular expression that finds metadata in the subfolder path:.*\x5B\\\\/\x5D(?P<Date>.*)\x5B\\\\/\x5D(?P<Run>.*)$
    Channel count:1
    Group the movie frames?:No
    Grouping method:Interleaved
    Number of channels per group:3
    Load the input as images or objects?:Images
    Name this loaded image:protein_raw_2000ms
    Name this loaded object:Nuclei
    Retain outlines of loaded objects?:No
    Name the outline image:LoadedImageOutlines
    Channel number:1
    Rescale intensities?:Yes
    Text that these images have in common (case-sensitive):gfp_4000ms.ome.tif
    Position of this image in each group:13
    Extract metadata from where?:None
    Regular expression that finds metadata in the file name:^(?P<Plate>.*)_(?P<Well>\x5BA-P\x5D\x5B0-9\x5D{2})_s(?P<Site>\x5B0-9\x5D)
    Type the regular expression that finds metadata in the subfolder path:.*\x5B\\\\/\x5D(?P<Date>.*)\x5B\\\\/\x5D(?P<Run>.*)$
    Channel count:1
    Group the movie frames?:No
    Grouping method:Interleaved
    Number of channels per group:3
    Load the input as images or objects?:Images
    Name this loaded image:protein_raw_4000ms
    Name this loaded object:Nuclei
    Retain outlines of loaded objects?:No
    Name the outline image:LoadedImageOutlines
    Channel number:1
    Rescale intensities?:Yes

RescaleIntensity:[module_num:2|svn_version:\'6746\'|variable_revision_number:2|show_window:False|notes:\x5Bu\'convert scanR gray range...to 0...1\', \'\'\x5D]
    Select the input image:lipid_raw_3ms
    Name the output image:lipid_3ms
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

RescaleIntensity:[module_num:3|svn_version:\'6746\'|variable_revision_number:2|show_window:False|notes:\x5B\x5D]
    Select the input image:protein_raw_1ms
    Name the output image:protein_1ms
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

RescaleIntensity:[module_num:4|svn_version:\'6746\'|variable_revision_number:2|show_window:False|notes:\x5B\x5D]
    Select the input image:protein_raw_5ms
    Name the output image:protein_5ms
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

RescaleIntensity:[module_num:5|svn_version:\'6746\'|variable_revision_number:2|show_window:False|notes:\x5B\x5D]
    Select the input image:protein_raw_10ms
    Name the output image:protein_10ms
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

RescaleIntensity:[module_num:6|svn_version:\'6746\'|variable_revision_number:2|show_window:False|notes:\x5B\x5D]
    Select the input image:protein_raw_30ms
    Name the output image:protein_30ms
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

RescaleIntensity:[module_num:7|svn_version:\'6746\'|variable_revision_number:2|show_window:False|notes:\x5B\x5D]
    Select the input image:protein_raw_50ms
    Name the output image:protein_50ms
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

RescaleIntensity:[module_num:8|svn_version:\'6746\'|variable_revision_number:2|show_window:False|notes:\x5B\x5D]
    Select the input image:protein_raw_75ms
    Name the output image:protein_75ms
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

RescaleIntensity:[module_num:9|svn_version:\'6746\'|variable_revision_number:2|show_window:False|notes:\x5B\x5D]
    Select the input image:protein_raw_100ms
    Name the output image:protein_100ms
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

RescaleIntensity:[module_num:10|svn_version:\'6746\'|variable_revision_number:2|show_window:False|notes:\x5B\x5D]
    Select the input image:protein_raw_200ms
    Name the output image:protein_200ms
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

RescaleIntensity:[module_num:11|svn_version:\'6746\'|variable_revision_number:2|show_window:False|notes:\x5B\x5D]
    Select the input image:protein_raw_300ms
    Name the output image:protein_300ms
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

RescaleIntensity:[module_num:12|svn_version:\'6746\'|variable_revision_number:2|show_window:False|notes:\x5B\x5D]
    Select the input image:protein_raw_1000ms
    Name the output image:protein_1000ms
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

RescaleIntensity:[module_num:13|svn_version:\'6746\'|variable_revision_number:2|show_window:False|notes:\x5B\x5D]
    Select the input image:protein_raw_2000ms
    Name the output image:protein_2000ms
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

RescaleIntensity:[module_num:14|svn_version:\'6746\'|variable_revision_number:2|show_window:False|notes:\x5B\x5D]
    Select the input image:protein_raw_4000ms
    Name the output image:protein_4000ms
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

Smooth:[module_num:15|svn_version:\'11025\'|variable_revision_number:1|show_window:False|notes:\x5B\x5D]
    Select the input image:lipid_3ms
    Name the output image:lipid_3 ms_smooth
    Select smoothing method:Gaussian Filter
    Calculate artifact diameter automatically?:No
    Typical artifact diameter, in  pixels:3
    Edge intensity difference:0.1

Smooth:[module_num:16|svn_version:\'11025\'|variable_revision_number:1|show_window:False|notes:\x5B\x5D]
    Select the input image:protein_1ms
    Name the output image:protein_1ms_smooth
    Select smoothing method:Gaussian Filter
    Calculate artifact diameter automatically?:No
    Typical artifact diameter, in  pixels:3
    Edge intensity difference:0.1

Smooth:[module_num:17|svn_version:\'11025\'|variable_revision_number:1|show_window:False|notes:\x5B\x5D]
    Select the input image:protein_5ms
    Name the output image:protein_5ms_smooth
    Select smoothing method:Gaussian Filter
    Calculate artifact diameter automatically?:No
    Typical artifact diameter, in  pixels:3
    Edge intensity difference:0.1

Smooth:[module_num:18|svn_version:\'11025\'|variable_revision_number:1|show_window:False|notes:\x5B\x5D]
    Select the input image:protein_10ms
    Name the output image:protein_10ms_smooth
    Select smoothing method:Gaussian Filter
    Calculate artifact diameter automatically?:No
    Typical artifact diameter, in  pixels:3
    Edge intensity difference:0.1

Smooth:[module_num:19|svn_version:\'11025\'|variable_revision_number:1|show_window:False|notes:\x5B\x5D]
    Select the input image:protein_30ms
    Name the output image:protein_30ms_smooth
    Select smoothing method:Gaussian Filter
    Calculate artifact diameter automatically?:No
    Typical artifact diameter, in  pixels:3
    Edge intensity difference:0.1

Smooth:[module_num:20|svn_version:\'11025\'|variable_revision_number:1|show_window:False|notes:\x5B\x5D]
    Select the input image:protein_50ms
    Name the output image:protein_50ms_smooth
    Select smoothing method:Gaussian Filter
    Calculate artifact diameter automatically?:No
    Typical artifact diameter, in  pixels:3
    Edge intensity difference:0.1

Smooth:[module_num:21|svn_version:\'11025\'|variable_revision_number:1|show_window:False|notes:\x5B\x5D]
    Select the input image:protein_75ms
    Name the output image:protein_75ms_smooth
    Select smoothing method:Gaussian Filter
    Calculate artifact diameter automatically?:No
    Typical artifact diameter, in  pixels:3
    Edge intensity difference:0.1

Smooth:[module_num:22|svn_version:\'11025\'|variable_revision_number:1|show_window:False|notes:\x5B\x5D]
    Select the input image:protein_100ms
    Name the output image:protein_100ms_smooth
    Select smoothing method:Gaussian Filter
    Calculate artifact diameter automatically?:No
    Typical artifact diameter, in  pixels:3
    Edge intensity difference:0.1

Smooth:[module_num:23|svn_version:\'11025\'|variable_revision_number:1|show_window:False|notes:\x5B\x5D]
    Select the input image:protein_200ms
    Name the output image:protein_200ms_smooth
    Select smoothing method:Gaussian Filter
    Calculate artifact diameter automatically?:No
    Typical artifact diameter, in  pixels:3
    Edge intensity difference:0.1

Smooth:[module_num:24|svn_version:\'11025\'|variable_revision_number:1|show_window:False|notes:\x5B\x5D]
    Select the input image:protein_300ms
    Name the output image:protein_300ms_smooth
    Select smoothing method:Gaussian Filter
    Calculate artifact diameter automatically?:No
    Typical artifact diameter, in  pixels:3
    Edge intensity difference:0.1

Smooth:[module_num:25|svn_version:\'11025\'|variable_revision_number:1|show_window:False|notes:\x5B\x5D]
    Select the input image:protein_1000ms
    Name the output image:protein_1000ms_smooth
    Select smoothing method:Gaussian Filter
    Calculate artifact diameter automatically?:No
    Typical artifact diameter, in  pixels:3
    Edge intensity difference:0.1

Smooth:[module_num:26|svn_version:\'11025\'|variable_revision_number:1|show_window:False|notes:\x5B\x5D]
    Select the input image:protein_2000ms
    Name the output image:protein_2000ms_smooth
    Select smoothing method:Gaussian Filter
    Calculate artifact diameter automatically?:No
    Typical artifact diameter, in  pixels:3
    Edge intensity difference:0.1

Smooth:[module_num:27|svn_version:\'11025\'|variable_revision_number:1|show_window:False|notes:\x5B\x5D]
    Select the input image:protein_4000ms
    Name the output image:protein_4000ms_smooth
    Select smoothing method:Gaussian Filter
    Calculate artifact diameter automatically?:No
    Typical artifact diameter, in  pixels:3
    Edge intensity difference:0.1

MeasureImageQuality:[module_num:28|svn_version:\'11045\'|variable_revision_number:4|show_window:False|notes:\x5B\x5D]
    Calculate metrics for which images?:All loaded images
    Image count:1
    Scale count:1
    Threshold count:1
    Select the images to measure:
    Include the image rescaling value?:Yes
    Calculate blur metrics?:No
    Window size for blur measurements:20
    Calculate saturation metrics?:Yes
    Calculate intensity metrics?:Yes
    Calculate thresholds?:No
    Use all thresholding methods?:No
    Select a thresholding method:Otsu Global
    Typical fraction of the image covered by objects:0.1
    Two-class or three-class thresholding?:Two classes
    Minimize the weighted variance or the entropy?:Weighted variance
    Assign pixels in the middle intensity class to the foreground or the background?:Foreground

Morph:[module_num:29|svn_version:\'11025\'|variable_revision_number:2|show_window:False|notes:\x5B\x5D]
    Select the input image:lipid_3 ms_smooth
    Name the output image:lipid_3ms_tophat
    Select the operation to perform:tophat
    Number of times to repeat operation:Once
    Repetition number:2
    Scale:5

Morph:[module_num:30|svn_version:\'11025\'|variable_revision_number:2|show_window:False|notes:\x5B\x5D]
    Select the input image:protein_1ms_smooth
    Name the output image:protein_1ms_tophat
    Select the operation to perform:tophat
    Number of times to repeat operation:Once
    Repetition number:2
    Scale:5

Morph:[module_num:31|svn_version:\'11025\'|variable_revision_number:2|show_window:False|notes:\x5B\x5D]
    Select the input image:protein_5ms_smooth
    Name the output image:protein_5ms_tophat
    Select the operation to perform:tophat
    Number of times to repeat operation:Once
    Repetition number:2
    Scale:5

Morph:[module_num:32|svn_version:\'11025\'|variable_revision_number:2|show_window:False|notes:\x5B\x5D]
    Select the input image:protein_10ms_smooth
    Name the output image:protein_10ms_tophat
    Select the operation to perform:tophat
    Number of times to repeat operation:Once
    Repetition number:2
    Scale:5

Morph:[module_num:33|svn_version:\'11025\'|variable_revision_number:2|show_window:False|notes:\x5B\x5D]
    Select the input image:protein_30ms_smooth
    Name the output image:protein_30ms_tophat
    Select the operation to perform:tophat
    Number of times to repeat operation:Once
    Repetition number:2
    Scale:5

Morph:[module_num:34|svn_version:\'11025\'|variable_revision_number:2|show_window:False|notes:\x5B\x5D]
    Select the input image:protein_50ms_smooth
    Name the output image:protein_50ms_tophat
    Select the operation to perform:tophat
    Number of times to repeat operation:Once
    Repetition number:2
    Scale:5

Morph:[module_num:35|svn_version:\'11025\'|variable_revision_number:2|show_window:False|notes:\x5B\x5D]
    Select the input image:protein_75ms_smooth
    Name the output image:protein_75ms_tophat
    Select the operation to perform:tophat
    Number of times to repeat operation:Once
    Repetition number:2
    Scale:5

Morph:[module_num:36|svn_version:\'11025\'|variable_revision_number:2|show_window:False|notes:\x5B\x5D]
    Select the input image:protein_100ms_smooth
    Name the output image:protein_100ms_tophat
    Select the operation to perform:tophat
    Number of times to repeat operation:Once
    Repetition number:2
    Scale:5

Morph:[module_num:37|svn_version:\'11025\'|variable_revision_number:2|show_window:False|notes:\x5B\x5D]
    Select the input image:protein_200ms_smooth
    Name the output image:protein_200ms_tophat
    Select the operation to perform:tophat
    Number of times to repeat operation:Once
    Repetition number:2
    Scale:5

Morph:[module_num:38|svn_version:\'11025\'|variable_revision_number:2|show_window:False|notes:\x5B\x5D]
    Select the input image:protein_300ms_smooth
    Name the output image:protein_300ms_tophat
    Select the operation to perform:tophat
    Number of times to repeat operation:Once
    Repetition number:2
    Scale:5

Morph:[module_num:39|svn_version:\'11025\'|variable_revision_number:2|show_window:False|notes:\x5B\x5D]
    Select the input image:protein_1000ms_smooth
    Name the output image:protein_1000ms_tophat
    Select the operation to perform:tophat
    Number of times to repeat operation:Once
    Repetition number:2
    Scale:5

Morph:[module_num:40|svn_version:\'11025\'|variable_revision_number:2|show_window:False|notes:\x5B\x5D]
    Select the input image:protein_2000ms_smooth
    Name the output image:protein_2000ms_tophat
    Select the operation to perform:tophat
    Number of times to repeat operation:Once
    Repetition number:2
    Scale:5

Morph:[module_num:41|svn_version:\'11025\'|variable_revision_number:2|show_window:False|notes:\x5B\x5D]
    Select the input image:protein_4000ms_smooth
    Name the output image:protein_4000ms_tophat
    Select the operation to perform:tophat
    Number of times to repeat operation:Once
    Repetition number:2
    Scale:5

ApplyThreshold:[module_num:42|svn_version:\'6746\'|variable_revision_number:5|show_window:False|notes:\x5B\x5D]
    Select the input image:lipid_3 ms_smooth
    Name the output image:lipid_3ms_saturated
    Select the output image type:Binary (black and white)
    Set pixels below or above the threshold to zero?:Below threshold
    Subtract the threshold value from the remaining pixel intensities?:No
    Number of pixels by which to expand the thresholding around those excluded bright pixels:0.0
    Select the thresholding method:Manual
    Manual threshold:0.999
    Lower and upper bounds on threshold:0.000000,1.000000
    Threshold correction factor:1
    Approximate fraction of image covered by objects?:0.01
    Select the input objects:None
    Two-class or three-class thresholding?:Two classes
    Minimize the weighted variance or the entropy?:Weighted variance
    Assign pixels in the middle intensity class to the foreground or the background?:Foreground
    Select the measurement to threshold with:None

ApplyThreshold:[module_num:43|svn_version:\'6746\'|variable_revision_number:5|show_window:False|notes:\x5B\x5D]
    Select the input image:protein_1ms_smooth
    Name the output image:protein_1ms_saturated
    Select the output image type:Binary (black and white)
    Set pixels below or above the threshold to zero?:Below threshold
    Subtract the threshold value from the remaining pixel intensities?:No
    Number of pixels by which to expand the thresholding around those excluded bright pixels:0.0
    Select the thresholding method:Manual
    Manual threshold:0.999
    Lower and upper bounds on threshold:0.000000,1.000000
    Threshold correction factor:1
    Approximate fraction of image covered by objects?:0.01
    Select the input objects:None
    Two-class or three-class thresholding?:Two classes
    Minimize the weighted variance or the entropy?:Weighted variance
    Assign pixels in the middle intensity class to the foreground or the background?:Foreground
    Select the measurement to threshold with:None

ApplyThreshold:[module_num:44|svn_version:\'6746\'|variable_revision_number:5|show_window:False|notes:\x5B\x5D]
    Select the input image:protein_5ms_smooth
    Name the output image:protein_5ms_saturated
    Select the output image type:Binary (black and white)
    Set pixels below or above the threshold to zero?:Below threshold
    Subtract the threshold value from the remaining pixel intensities?:No
    Number of pixels by which to expand the thresholding around those excluded bright pixels:0.0
    Select the thresholding method:Manual
    Manual threshold:0.999
    Lower and upper bounds on threshold:0.000000,1.000000
    Threshold correction factor:1
    Approximate fraction of image covered by objects?:0.01
    Select the input objects:None
    Two-class or three-class thresholding?:Two classes
    Minimize the weighted variance or the entropy?:Weighted variance
    Assign pixels in the middle intensity class to the foreground or the background?:Foreground
    Select the measurement to threshold with:None

ApplyThreshold:[module_num:45|svn_version:\'6746\'|variable_revision_number:5|show_window:False|notes:\x5B\x5D]
    Select the input image:protein_10ms_smooth
    Name the output image:protein_10ms_saturated
    Select the output image type:Binary (black and white)
    Set pixels below or above the threshold to zero?:Below threshold
    Subtract the threshold value from the remaining pixel intensities?:No
    Number of pixels by which to expand the thresholding around those excluded bright pixels:0.0
    Select the thresholding method:Manual
    Manual threshold:0.999
    Lower and upper bounds on threshold:0.000000,1.000000
    Threshold correction factor:1
    Approximate fraction of image covered by objects?:0.01
    Select the input objects:None
    Two-class or three-class thresholding?:Two classes
    Minimize the weighted variance or the entropy?:Weighted variance
    Assign pixels in the middle intensity class to the foreground or the background?:Foreground
    Select the measurement to threshold with:None

ApplyThreshold:[module_num:46|svn_version:\'6746\'|variable_revision_number:5|show_window:False|notes:\x5B\x5D]
    Select the input image:protein_30ms_smooth
    Name the output image:protein_30ms_saturated
    Select the output image type:Binary (black and white)
    Set pixels below or above the threshold to zero?:Below threshold
    Subtract the threshold value from the remaining pixel intensities?:No
    Number of pixels by which to expand the thresholding around those excluded bright pixels:0.0
    Select the thresholding method:Manual
    Manual threshold:0.999
    Lower and upper bounds on threshold:0.000000,1.000000
    Threshold correction factor:1
    Approximate fraction of image covered by objects?:0.01
    Select the input objects:None
    Two-class or three-class thresholding?:Two classes
    Minimize the weighted variance or the entropy?:Weighted variance
    Assign pixels in the middle intensity class to the foreground or the background?:Foreground
    Select the measurement to threshold with:None

ApplyThreshold:[module_num:47|svn_version:\'6746\'|variable_revision_number:5|show_window:False|notes:\x5B\x5D]
    Select the input image:protein_50ms_smooth
    Name the output image:protein_50ms_saturated
    Select the output image type:Binary (black and white)
    Set pixels below or above the threshold to zero?:Below threshold
    Subtract the threshold value from the remaining pixel intensities?:No
    Number of pixels by which to expand the thresholding around those excluded bright pixels:0.0
    Select the thresholding method:Manual
    Manual threshold:0.999
    Lower and upper bounds on threshold:0.000000,1.000000
    Threshold correction factor:1
    Approximate fraction of image covered by objects?:0.01
    Select the input objects:None
    Two-class or three-class thresholding?:Two classes
    Minimize the weighted variance or the entropy?:Weighted variance
    Assign pixels in the middle intensity class to the foreground or the background?:Foreground
    Select the measurement to threshold with:None

ApplyThreshold:[module_num:48|svn_version:\'6746\'|variable_revision_number:5|show_window:False|notes:\x5B\x5D]
    Select the input image:protein_75ms_smooth
    Name the output image:protein_75ms_saturated
    Select the output image type:Binary (black and white)
    Set pixels below or above the threshold to zero?:Below threshold
    Subtract the threshold value from the remaining pixel intensities?:No
    Number of pixels by which to expand the thresholding around those excluded bright pixels:0.0
    Select the thresholding method:Manual
    Manual threshold:0.999
    Lower and upper bounds on threshold:0.000000,1.000000
    Threshold correction factor:1
    Approximate fraction of image covered by objects?:0.01
    Select the input objects:None
    Two-class or three-class thresholding?:Two classes
    Minimize the weighted variance or the entropy?:Weighted variance
    Assign pixels in the middle intensity class to the foreground or the background?:Foreground
    Select the measurement to threshold with:None

ApplyThreshold:[module_num:49|svn_version:\'6746\'|variable_revision_number:5|show_window:False|notes:\x5B\x5D]
    Select the input image:protein_100ms_smooth
    Name the output image:protein_100ms_saturated
    Select the output image type:Binary (black and white)
    Set pixels below or above the threshold to zero?:Below threshold
    Subtract the threshold value from the remaining pixel intensities?:No
    Number of pixels by which to expand the thresholding around those excluded bright pixels:0.0
    Select the thresholding method:Manual
    Manual threshold:0.999
    Lower and upper bounds on threshold:0.000000,1.000000
    Threshold correction factor:1
    Approximate fraction of image covered by objects?:0.01
    Select the input objects:None
    Two-class or three-class thresholding?:Two classes
    Minimize the weighted variance or the entropy?:Weighted variance
    Assign pixels in the middle intensity class to the foreground or the background?:Foreground
    Select the measurement to threshold with:None

ApplyThreshold:[module_num:50|svn_version:\'6746\'|variable_revision_number:5|show_window:False|notes:\x5B\x5D]
    Select the input image:protein_200ms_smooth
    Name the output image:protein_200ms_saturated
    Select the output image type:Binary (black and white)
    Set pixels below or above the threshold to zero?:Below threshold
    Subtract the threshold value from the remaining pixel intensities?:No
    Number of pixels by which to expand the thresholding around those excluded bright pixels:0.0
    Select the thresholding method:Manual
    Manual threshold:0.999
    Lower and upper bounds on threshold:0.000000,1.000000
    Threshold correction factor:1
    Approximate fraction of image covered by objects?:0.01
    Select the input objects:None
    Two-class or three-class thresholding?:Two classes
    Minimize the weighted variance or the entropy?:Weighted variance
    Assign pixels in the middle intensity class to the foreground or the background?:Foreground
    Select the measurement to threshold with:None

ApplyThreshold:[module_num:51|svn_version:\'6746\'|variable_revision_number:5|show_window:False|notes:\x5B\x5D]
    Select the input image:protein_300ms_smooth
    Name the output image:protein_300ms_saturated
    Select the output image type:Binary (black and white)
    Set pixels below or above the threshold to zero?:Below threshold
    Subtract the threshold value from the remaining pixel intensities?:No
    Number of pixels by which to expand the thresholding around those excluded bright pixels:0.0
    Select the thresholding method:Manual
    Manual threshold:0.999
    Lower and upper bounds on threshold:0.000000,1.000000
    Threshold correction factor:1
    Approximate fraction of image covered by objects?:0.01
    Select the input objects:None
    Two-class or three-class thresholding?:Two classes
    Minimize the weighted variance or the entropy?:Weighted variance
    Assign pixels in the middle intensity class to the foreground or the background?:Foreground
    Select the measurement to threshold with:None

ApplyThreshold:[module_num:52|svn_version:\'6746\'|variable_revision_number:5|show_window:False|notes:\x5B\x5D]
    Select the input image:protein_1000ms_smooth
    Name the output image:protein_1000ms_saturated
    Select the output image type:Binary (black and white)
    Set pixels below or above the threshold to zero?:Below threshold
    Subtract the threshold value from the remaining pixel intensities?:No
    Number of pixels by which to expand the thresholding around those excluded bright pixels:0.0
    Select the thresholding method:Manual
    Manual threshold:0.999
    Lower and upper bounds on threshold:0.000000,1.000000
    Threshold correction factor:1
    Approximate fraction of image covered by objects?:0.01
    Select the input objects:None
    Two-class or three-class thresholding?:Two classes
    Minimize the weighted variance or the entropy?:Weighted variance
    Assign pixels in the middle intensity class to the foreground or the background?:Foreground
    Select the measurement to threshold with:None

ApplyThreshold:[module_num:53|svn_version:\'6746\'|variable_revision_number:5|show_window:False|notes:\x5B\x5D]
    Select the input image:protein_2000ms_smooth
    Name the output image:protein_2000ms_saturated
    Select the output image type:Binary (black and white)
    Set pixels below or above the threshold to zero?:Below threshold
    Subtract the threshold value from the remaining pixel intensities?:No
    Number of pixels by which to expand the thresholding around those excluded bright pixels:0.0
    Select the thresholding method:Manual
    Manual threshold:0.999
    Lower and upper bounds on threshold:0.000000,1.000000
    Threshold correction factor:1
    Approximate fraction of image covered by objects?:0.01
    Select the input objects:None
    Two-class or three-class thresholding?:Three classes
    Minimize the weighted variance or the entropy?:Weighted variance
    Assign pixels in the middle intensity class to the foreground or the background?:Foreground
    Select the measurement to threshold with:None

ApplyThreshold:[module_num:54|svn_version:\'6746\'|variable_revision_number:5|show_window:False|notes:\x5B\x5D]
    Select the input image:protein_4000ms_smooth
    Name the output image:protein_4000ms_saturated
    Select the output image type:Binary (black and white)
    Set pixels below or above the threshold to zero?:Below threshold
    Subtract the threshold value from the remaining pixel intensities?:No
    Number of pixels by which to expand the thresholding around those excluded bright pixels:0.0
    Select the thresholding method:Manual
    Manual threshold:0.999
    Lower and upper bounds on threshold:0.000000,1.000000
    Threshold correction factor:1
    Approximate fraction of image covered by objects?:0.01
    Select the input objects:None
    Two-class or three-class thresholding?:Three classes
    Minimize the weighted variance or the entropy?:Weighted variance
    Assign pixels in the middle intensity class to the foreground or the background?:Foreground
    Select the measurement to threshold with:None

ApplyThreshold:[module_num:55|svn_version:\'6746\'|variable_revision_number:5|show_window:False|notes:\x5B\x5D]
    Select the input image:lipid_3ms_tophat
    Name the output image:lipid_3ms_tophat_bw
    Select the output image type:Binary (black and white)
    Set pixels below or above the threshold to zero?:Below threshold
    Subtract the threshold value from the remaining pixel intensities?:No
    Number of pixels by which to expand the thresholding around those excluded bright pixels:0.0
    Select the thresholding method:Otsu Global
    Manual threshold:0.999
    Lower and upper bounds on threshold:0.000000,1.000000
    Threshold correction factor:1
    Approximate fraction of image covered by objects?:0.01
    Select the input objects:None
    Two-class or three-class thresholding?:Three classes
    Minimize the weighted variance or the entropy?:Weighted variance
    Assign pixels in the middle intensity class to the foreground or the background?:Foreground
    Select the measurement to threshold with:None

IdentifyPrimaryObjects:[module_num:56|svn_version:\'11047\'|variable_revision_number:8|show_window:False|notes:\x5B\x5D]
    Select the input image:lipid_3ms_tophat_bw
    Name the primary objects to be identified:boundaries
    Typical diameter of objects, in pixel units (Min,Max):7,10000
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
    Name the outline image:PrimaryOutlines
    Fill holes in identified objects?:No
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

ConvertObjectsToImage:[module_num:57|svn_version:\'11025\'|variable_revision_number:1|show_window:False|notes:\x5B\x5D]
    Select the input objects:boundaries
    Name the output image:boundaries
    Select the color type:Binary (black & white)
    Select the colormap:Default

Morph:[module_num:58|svn_version:\'11025\'|variable_revision_number:2|show_window:False|notes:\x5B\x5D]
    Select the input image:boundaries
    Name the output image:boundariesClosed
    Select the operation to perform:close
    Number of times to repeat operation:Once
    Repetition number:2
    Scale:5

Morph:[module_num:59|svn_version:\'11025\'|variable_revision_number:2|show_window:False|notes:\x5B\x5D]
    Select the input image:boundariesClosed
    Name the output image:boundariesClosedDilate
    Select the operation to perform:dilate
    Number of times to repeat operation:Once
    Repetition number:2
    Scale:3

ImageMath:[module_num:60|svn_version:\'11025\'|variable_revision_number:3|show_window:False|notes:\x5B\x5D]
    Operation:Invert
    Raise the power of the result by:1
    Multiply the result by:1
    Add to result:0
    Set values less than 0 equal to 0?:No
    Set values greater than 1 equal to 1?:No
    Ignore the image masks?:No
    Name the output image:boundariesClosedDilateInv
    Image or measurement?:Image
    Select the first image:boundariesClosedDilate
    Multiply the first image by:1
    Measurement:
    Image or measurement?:Image
    Select the second image:
    Multiply the second image by:1
    Measurement:

IdentifyPrimaryObjects:[module_num:61|svn_version:\'11047\'|variable_revision_number:8|show_window:False|notes:\x5B\x5D]
    Select the input image:boundariesClosedDilateInv
    Name the primary objects to be identified:liposomes
    Typical diameter of objects, in pixel units (Min,Max):10,100
    Discard objects outside the diameter range?:Yes
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
    Name the outline image:liposomeOutlines
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

ExpandOrShrinkObjects:[module_num:62|svn_version:\'11025\'|variable_revision_number:1|show_window:False|notes:\x5B\x5D]
    Select the input objects:liposomes
    Name the output objects:liposomeCenters
    Select the operation:Shrink objects to a point
    Number of pixels by which to expand or shrink:1
    Fill holes in objects so that all objects shrink to a single point?:Yes
    Retain the outlines of the identified objects for use later in the pipeline (for example, in SaveImages)?:Yes
    Name the outline image:liposomeCenterOutlines

OverlayOutlines:[module_num:63|svn_version:\'11025\'|variable_revision_number:2|show_window:False|notes:\x5B\x5D]
    Display outlines on a blank image?:No
    Select image on which to display outlines:lipid_3ms
    Name the output image:lipid_3ms_liposomCenter
    Select outline display mode:Color
    Select method to determine brightness of outlines:Max of image
    Width of outlines:7
    Select outlines to display:liposomeCenterOutlines
    Select outline color:Yellow

MeasureImageIntensity:[module_num:64|svn_version:\'11025\'|variable_revision_number:2|show_window:False|notes:\x5Bu\'total integrated intensity of these BW (0/1) images give you the number of saturated pixels\'\x5D]
    Select the image to measure:lipid_3ms_saturated
    Measure the intensity only from areas enclosed by objects?:No
    Select the input objects:None
    Select the image to measure:protein_5ms_saturated
    Measure the intensity only from areas enclosed by objects?:No
    Select the input objects:None
    Select the image to measure:protein_10ms_saturated
    Measure the intensity only from areas enclosed by objects?:No
    Select the input objects:None
    Select the image to measure:protein_30ms_saturated
    Measure the intensity only from areas enclosed by objects?:No
    Select the input objects:None
    Select the image to measure:protein_100ms_saturated
    Measure the intensity only from areas enclosed by objects?:No
    Select the input objects:None
    Select the image to measure:protein_1ms_saturated
    Measure the intensity only from areas enclosed by objects?:No
    Select the input objects:None
    Select the image to measure:protein_50ms_saturated
    Measure the intensity only from areas enclosed by objects?:No
    Select the input objects:None
    Select the image to measure:protein_75ms_saturated
    Measure the intensity only from areas enclosed by objects?:No
    Select the input objects:None
    Select the image to measure:protein_200ms_saturated
    Measure the intensity only from areas enclosed by objects?:No
    Select the input objects:None
    Select the image to measure:protein_300ms_saturated
    Measure the intensity only from areas enclosed by objects?:No
    Select the input objects:None
    Select the image to measure:protein_1000ms_saturated
    Measure the intensity only from areas enclosed by objects?:No
    Select the input objects:None
    Select the image to measure:protein_2000ms_saturated
    Measure the intensity only from areas enclosed by objects?:No
    Select the input objects:None
    Select the image to measure:protein_4000ms_saturated
    Measure the intensity only from areas enclosed by objects?:No
    Select the input objects:None

ImageMath:[module_num:65|svn_version:\'11025\'|variable_revision_number:3|show_window:False|notes:\x5Bu\'combine the saturated regions\'\x5D]
    Operation:Maximum
    Raise the power of the result by:1
    Multiply the result by:1
    Add to result:0
    Set values less than 0 equal to 0?:Yes
    Set values greater than 1 equal to 1?:Yes
    Ignore the image masks?:No
    Name the output image:3_1_saturation
    Image or measurement?:Image
    Select the first image:lipid_3ms_saturated
    Multiply the first image by:1
    Measurement:
    Image or measurement?:Image
    Select the second image:protein_1ms_saturated
    Multiply the second image by:1
    Measurement:

ImageMath:[module_num:66|svn_version:\'11025\'|variable_revision_number:3|show_window:False|notes:\x5B\x5D]
    Operation:Maximum
    Raise the power of the result by:1
    Multiply the result by:1
    Add to result:0
    Set values less than 0 equal to 0?:Yes
    Set values greater than 1 equal to 1?:Yes
    Ignore the image masks?:No
    Name the output image:3_5_saturation
    Image or measurement?:Image
    Select the first image:lipid_3ms_saturated
    Multiply the first image by:1
    Measurement:
    Image or measurement?:Image
    Select the second image:protein_5ms_saturated
    Multiply the second image by:1
    Measurement:

ImageMath:[module_num:67|svn_version:\'11025\'|variable_revision_number:3|show_window:False|notes:\x5B\x5D]
    Operation:Maximum
    Raise the power of the result by:1
    Multiply the result by:1
    Add to result:0
    Set values less than 0 equal to 0?:Yes
    Set values greater than 1 equal to 1?:Yes
    Ignore the image masks?:No
    Name the output image:3_10_saturation
    Image or measurement?:Image
    Select the first image:lipid_3ms_saturated
    Multiply the first image by:1
    Measurement:
    Image or measurement?:Image
    Select the second image:protein_10ms_saturated
    Multiply the second image by:1
    Measurement:

ImageMath:[module_num:68|svn_version:\'11025\'|variable_revision_number:3|show_window:False|notes:\x5B\x5D]
    Operation:Maximum
    Raise the power of the result by:1
    Multiply the result by:1
    Add to result:0
    Set values less than 0 equal to 0?:Yes
    Set values greater than 1 equal to 1?:Yes
    Ignore the image masks?:No
    Name the output image:3_30_saturation
    Image or measurement?:Image
    Select the first image:lipid_3ms_saturated
    Multiply the first image by:1
    Measurement:
    Image or measurement?:Image
    Select the second image:protein_30ms_saturated
    Multiply the second image by:1
    Measurement:

ImageMath:[module_num:69|svn_version:\'11025\'|variable_revision_number:3|show_window:False|notes:\x5B\x5D]
    Operation:Maximum
    Raise the power of the result by:1
    Multiply the result by:1
    Add to result:0
    Set values less than 0 equal to 0?:Yes
    Set values greater than 1 equal to 1?:Yes
    Ignore the image masks?:No
    Name the output image:3_50_saturation
    Image or measurement?:Image
    Select the first image:lipid_3ms_saturated
    Multiply the first image by:1
    Measurement:
    Image or measurement?:Image
    Select the second image:protein_50ms_saturated
    Multiply the second image by:1
    Measurement:

ImageMath:[module_num:70|svn_version:\'11025\'|variable_revision_number:3|show_window:False|notes:\x5B\x5D]
    Operation:Maximum
    Raise the power of the result by:1
    Multiply the result by:1
    Add to result:0
    Set values less than 0 equal to 0?:Yes
    Set values greater than 1 equal to 1?:Yes
    Ignore the image masks?:No
    Name the output image:3_75_saturation
    Image or measurement?:Image
    Select the first image:lipid_3ms_saturated
    Multiply the first image by:1
    Measurement:
    Image or measurement?:Image
    Select the second image:protein_75ms_saturated
    Multiply the second image by:1
    Measurement:

ImageMath:[module_num:71|svn_version:\'11025\'|variable_revision_number:3|show_window:False|notes:\x5B\x5D]
    Operation:Maximum
    Raise the power of the result by:1
    Multiply the result by:1
    Add to result:0
    Set values less than 0 equal to 0?:Yes
    Set values greater than 1 equal to 1?:Yes
    Ignore the image masks?:No
    Name the output image:3_100_saturation
    Image or measurement?:Image
    Select the first image:lipid_3ms_saturated
    Multiply the first image by:1
    Measurement:
    Image or measurement?:Image
    Select the second image:protein_100ms_saturated
    Multiply the second image by:1
    Measurement:

ImageMath:[module_num:72|svn_version:\'11025\'|variable_revision_number:3|show_window:False|notes:\x5B\x5D]
    Operation:Maximum
    Raise the power of the result by:1
    Multiply the result by:1
    Add to result:0
    Set values less than 0 equal to 0?:Yes
    Set values greater than 1 equal to 1?:Yes
    Ignore the image masks?:No
    Name the output image:3_200_saturation
    Image or measurement?:Image
    Select the first image:lipid_3ms_saturated
    Multiply the first image by:1
    Measurement:
    Image or measurement?:Image
    Select the second image:protein_200ms_saturated
    Multiply the second image by:1
    Measurement:

ImageMath:[module_num:73|svn_version:\'11025\'|variable_revision_number:3|show_window:False|notes:\x5B\x5D]
    Operation:Maximum
    Raise the power of the result by:1
    Multiply the result by:1
    Add to result:0
    Set values less than 0 equal to 0?:Yes
    Set values greater than 1 equal to 1?:Yes
    Ignore the image masks?:No
    Name the output image:3_300_saturation
    Image or measurement?:Image
    Select the first image:lipid_3ms_saturated
    Multiply the first image by:1
    Measurement:
    Image or measurement?:Image
    Select the second image:protein_300ms_saturated
    Multiply the second image by:1
    Measurement:

ImageMath:[module_num:74|svn_version:\'11025\'|variable_revision_number:3|show_window:False|notes:\x5B\x5D]
    Operation:Maximum
    Raise the power of the result by:1
    Multiply the result by:1
    Add to result:0
    Set values less than 0 equal to 0?:Yes
    Set values greater than 1 equal to 1?:Yes
    Ignore the image masks?:No
    Name the output image:3_1000_saturation
    Image or measurement?:Image
    Select the first image:lipid_3ms_saturated
    Multiply the first image by:1
    Measurement:
    Image or measurement?:Image
    Select the second image:protein_1000ms_saturated
    Multiply the second image by:1
    Measurement:

ImageMath:[module_num:75|svn_version:\'11025\'|variable_revision_number:3|show_window:False|notes:\x5B\x5D]
    Operation:Maximum
    Raise the power of the result by:1
    Multiply the result by:1
    Add to result:0
    Set values less than 0 equal to 0?:Yes
    Set values greater than 1 equal to 1?:Yes
    Ignore the image masks?:No
    Name the output image:3_2000_saturation
    Image or measurement?:Image
    Select the first image:lipid_3ms_saturated
    Multiply the first image by:1
    Measurement:
    Image or measurement?:Image
    Select the second image:protein_2000ms_saturated
    Multiply the second image by:1
    Measurement:

ImageMath:[module_num:76|svn_version:\'11025\'|variable_revision_number:3|show_window:False|notes:\x5B\x5D]
    Operation:Maximum
    Raise the power of the result by:1
    Multiply the result by:1
    Add to result:0
    Set values less than 0 equal to 0?:Yes
    Set values greater than 1 equal to 1?:Yes
    Ignore the image masks?:No
    Name the output image:3_4000_saturation
    Image or measurement?:Image
    Select the first image:lipid_3ms_saturated
    Multiply the first image by:1
    Measurement:
    Image or measurement?:Image
    Select the second image:protein_4000ms
    Multiply the second image by:1
    Measurement:

MaskImage:[module_num:77|svn_version:\'11025\'|variable_revision_number:3|show_window:False|notes:\x5B\x5D]
    Select the input image:lipid_3ms_tophat
    Name the output image:lipid_3ms_1ms_tophat_noSatu
    Use objects or an image as a mask?:Image
    Select object for mask:None
    Select image for mask:3_1_saturation
    Invert the mask?:Yes

MaskImage:[module_num:78|svn_version:\'11025\'|variable_revision_number:3|show_window:False|notes:\x5B\x5D]
    Select the input image:lipid_3ms_tophat
    Name the output image:lipid_3ms_5ms_tophat_noSatu
    Use objects or an image as a mask?:Image
    Select object for mask:None
    Select image for mask:3_5_saturation
    Invert the mask?:Yes

MaskImage:[module_num:79|svn_version:\'11025\'|variable_revision_number:3|show_window:False|notes:\x5B\x5D]
    Select the input image:lipid_3ms_tophat
    Name the output image:lipid_3ms_10ms_tophat_noSatu
    Use objects or an image as a mask?:Image
    Select object for mask:None
    Select image for mask:3_10_saturation
    Invert the mask?:Yes

MaskImage:[module_num:80|svn_version:\'11025\'|variable_revision_number:3|show_window:False|notes:\x5B\x5D]
    Select the input image:lipid_3ms_tophat
    Name the output image:lipid_3ms_30ms_tophat_noSatu
    Use objects or an image as a mask?:Image
    Select object for mask:None
    Select image for mask:3_30_saturation
    Invert the mask?:Yes

MaskImage:[module_num:81|svn_version:\'11025\'|variable_revision_number:3|show_window:False|notes:\x5B\x5D]
    Select the input image:lipid_3ms_tophat
    Name the output image:lipid_3ms_50ms_tophat_noSatu
    Use objects or an image as a mask?:Image
    Select object for mask:None
    Select image for mask:3_50_saturation
    Invert the mask?:Yes

MaskImage:[module_num:82|svn_version:\'11025\'|variable_revision_number:3|show_window:False|notes:\x5B\x5D]
    Select the input image:lipid_3ms_tophat
    Name the output image:lipid_3ms_75ms_tophat_noSatu
    Use objects or an image as a mask?:Image
    Select object for mask:None
    Select image for mask:3_75_saturation
    Invert the mask?:Yes

MaskImage:[module_num:83|svn_version:\'11025\'|variable_revision_number:3|show_window:False|notes:\x5B\x5D]
    Select the input image:lipid_3ms_tophat
    Name the output image:lipid_3ms_100ms_tophat_noSatu
    Use objects or an image as a mask?:Image
    Select object for mask:None
    Select image for mask:3_100_saturation
    Invert the mask?:Yes

MaskImage:[module_num:84|svn_version:\'11025\'|variable_revision_number:3|show_window:False|notes:\x5B\x5D]
    Select the input image:lipid_3ms_tophat
    Name the output image:lipid_3ms_200ms_tophat_noSatu
    Use objects or an image as a mask?:Image
    Select object for mask:None
    Select image for mask:3_200_saturation
    Invert the mask?:Yes

MaskImage:[module_num:85|svn_version:\'11025\'|variable_revision_number:3|show_window:False|notes:\x5B\x5D]
    Select the input image:lipid_3ms_tophat
    Name the output image:lipid_3ms_300ms_tophat_noSatu
    Use objects or an image as a mask?:Image
    Select object for mask:None
    Select image for mask:3_300_saturation
    Invert the mask?:Yes

MaskImage:[module_num:86|svn_version:\'11025\'|variable_revision_number:3|show_window:False|notes:\x5B\x5D]
    Select the input image:lipid_3ms_tophat
    Name the output image:lipid_3ms_1000ms_tophat_noSatu
    Use objects or an image as a mask?:Image
    Select object for mask:None
    Select image for mask:3_1000_saturation
    Invert the mask?:Yes

MaskImage:[module_num:87|svn_version:\'11025\'|variable_revision_number:3|show_window:False|notes:\x5B\x5D]
    Select the input image:lipid_3ms_tophat
    Name the output image:lipid_3ms_2000ms_tophat_noSatu
    Use objects or an image as a mask?:Image
    Select object for mask:None
    Select image for mask:3_2000_saturation
    Invert the mask?:Yes

MaskImage:[module_num:88|svn_version:\'11025\'|variable_revision_number:3|show_window:False|notes:\x5B\x5D]
    Select the input image:lipid_3ms_tophat
    Name the output image:lipid_3ms_4000ms_tophat_noSatu
    Use objects or an image as a mask?:Image
    Select object for mask:None
    Select image for mask:3_4000_saturation
    Invert the mask?:Yes

MaskImage:[module_num:89|svn_version:\'11025\'|variable_revision_number:3|show_window:False|notes:\x5B\x5D]
    Select the input image:protein_1ms_tophat
    Name the output image:protein_3ms_1ms_tophat_noSatu
    Use objects or an image as a mask?:Image
    Select object for mask:None
    Select image for mask:3_1_saturation
    Invert the mask?:Yes

MaskImage:[module_num:90|svn_version:\'11025\'|variable_revision_number:3|show_window:False|notes:\x5B\x5D]
    Select the input image:protein_5ms_tophat
    Name the output image:protein_3ms_5ms_tophat_noSatu
    Use objects or an image as a mask?:Image
    Select object for mask:None
    Select image for mask:3_5_saturation
    Invert the mask?:Yes

MaskImage:[module_num:91|svn_version:\'11025\'|variable_revision_number:3|show_window:False|notes:\x5B\x5D]
    Select the input image:protein_10ms_tophat
    Name the output image:protein_3ms_10ms_tophat_noSatu
    Use objects or an image as a mask?:Image
    Select object for mask:None
    Select image for mask:3_10_saturation
    Invert the mask?:Yes

MaskImage:[module_num:92|svn_version:\'11025\'|variable_revision_number:3|show_window:False|notes:\x5B\x5D]
    Select the input image:protein_30ms_tophat
    Name the output image:protein_3ms_30ms_tophat_noSatu
    Use objects or an image as a mask?:Image
    Select object for mask:None
    Select image for mask:3_30_saturation
    Invert the mask?:Yes

MaskImage:[module_num:93|svn_version:\'11025\'|variable_revision_number:3|show_window:False|notes:\x5B\x5D]
    Select the input image:protein_50ms_tophat
    Name the output image:protein_3ms_50ms_tophat_noSatu
    Use objects or an image as a mask?:Image
    Select object for mask:None
    Select image for mask:3_50_saturation
    Invert the mask?:Yes

MaskImage:[module_num:94|svn_version:\'11025\'|variable_revision_number:3|show_window:False|notes:\x5B\x5D]
    Select the input image:protein_75ms_tophat
    Name the output image:protein_3ms_75ms_tophat_noSatu
    Use objects or an image as a mask?:Image
    Select object for mask:None
    Select image for mask:3_75_saturation
    Invert the mask?:Yes

MaskImage:[module_num:95|svn_version:\'11025\'|variable_revision_number:3|show_window:False|notes:\x5B\x5D]
    Select the input image:protein_100ms_tophat
    Name the output image:protein_3ms_100ms_tophat_noSatu
    Use objects or an image as a mask?:Image
    Select object for mask:None
    Select image for mask:3_100_saturation
    Invert the mask?:Yes

MaskImage:[module_num:96|svn_version:\'11025\'|variable_revision_number:3|show_window:False|notes:\x5B\x5D]
    Select the input image:protein_200ms_tophat
    Name the output image:protein_3ms_200ms_tophat_noSatu
    Use objects or an image as a mask?:Image
    Select object for mask:None
    Select image for mask:3_200_saturation
    Invert the mask?:Yes

MaskImage:[module_num:97|svn_version:\'11025\'|variable_revision_number:3|show_window:False|notes:\x5B\x5D]
    Select the input image:protein_300ms_tophat
    Name the output image:protein_3ms_300ms_tophat_noSatu
    Use objects or an image as a mask?:Image
    Select object for mask:None
    Select image for mask:3_300_saturation
    Invert the mask?:Yes

MaskImage:[module_num:98|svn_version:\'11025\'|variable_revision_number:3|show_window:False|notes:\x5B\x5D]
    Select the input image:protein_1000ms_tophat
    Name the output image:protein_3ms_1000ms_tophat_noSatu
    Use objects or an image as a mask?:Image
    Select object for mask:None
    Select image for mask:3_1000_saturation
    Invert the mask?:Yes

MaskImage:[module_num:99|svn_version:\'11025\'|variable_revision_number:3|show_window:False|notes:\x5B\x5D]
    Select the input image:protein_2000ms_tophat
    Name the output image:protein_3ms_2000ms_tophat_noSatu
    Use objects or an image as a mask?:Image
    Select object for mask:None
    Select image for mask:3_2000_saturation
    Invert the mask?:Yes

MaskImage:[module_num:100|svn_version:\'11025\'|variable_revision_number:3|show_window:False|notes:\x5B\x5D]
    Select the input image:protein_4000ms_tophat
    Name the output image:protein_3ms_4000ms_tophat_noSatu
    Use objects or an image as a mask?:Image
    Select object for mask:None
    Select image for mask:3_4000_saturation
    Invert the mask?:Yes

IdentifyPrimaryObjects:[module_num:101|svn_version:\'11047\'|variable_revision_number:8|show_window:False|notes:\x5B\x5D]
    Select the input image:lipid_3ms_tophat
    Name the primary objects to be identified:membranes
    Typical diameter of objects, in pixel units (Min,Max):5,400
    Discard objects outside the diameter range?:Yes
    Try to merge too small objects with nearby larger objects?:No
    Discard objects touching the border of the image?:No
    Select the thresholding method:RobustBackground Global
    Threshold correction factor:1
    Lower and upper bounds on threshold:0.000000,1.000000
    Approximate fraction of image covered by objects?:0.01
    Method to distinguish clumped objects:None
    Method to draw dividing lines between clumped objects:Intensity
    Size of smoothing filter:10
    Suppress local maxima that are closer than this minimum allowed distance:7
    Speed up by using lower-resolution image to find local maxima?:Yes
    Name the outline image:membrane_outlines
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

ConvertObjectsToImage:[module_num:102|svn_version:\'11025\'|variable_revision_number:1|show_window:False|notes:\x5B\x5D]
    Select the input objects:membranes
    Name the output image:mask_membranes
    Select the color type:Color
    Select the colormap:gray

MaskImage:[module_num:103|svn_version:\'11025\'|variable_revision_number:3|show_window:False|notes:\x5B\x5D]
    Select the input image:lipid_3ms_1ms_tophat_noSatu
    Name the output image:lipid_3ms_1ms_tophat_noSatu_membrane
    Use objects or an image as a mask?:Objects
    Select object for mask:membranes
    Select image for mask:None
    Invert the mask?:No

MaskImage:[module_num:104|svn_version:\'11025\'|variable_revision_number:3|show_window:False|notes:\x5B\x5D]
    Select the input image:lipid_3ms_5ms_tophat_noSatu
    Name the output image:lipid_3ms_5ms_tophat_noSatu_membrane
    Use objects or an image as a mask?:Objects
    Select object for mask:membranes
    Select image for mask:None
    Invert the mask?:No

MaskImage:[module_num:105|svn_version:\'11025\'|variable_revision_number:3|show_window:False|notes:\x5B\x5D]
    Select the input image:lipid_3ms_10ms_tophat_noSatu
    Name the output image:lipid_3ms_10ms_tophat_noSatu_membrane
    Use objects or an image as a mask?:Objects
    Select object for mask:membranes
    Select image for mask:None
    Invert the mask?:No

MaskImage:[module_num:106|svn_version:\'11025\'|variable_revision_number:3|show_window:False|notes:\x5B\x5D]
    Select the input image:lipid_3ms_30ms_tophat_noSatu
    Name the output image:lipid_3ms_30ms_tophat_noSatu_membrane
    Use objects or an image as a mask?:Objects
    Select object for mask:membranes
    Select image for mask:None
    Invert the mask?:No

MaskImage:[module_num:107|svn_version:\'11025\'|variable_revision_number:3|show_window:False|notes:\x5B\x5D]
    Select the input image:lipid_3ms_50ms_tophat_noSatu
    Name the output image:lipid_3ms_50ms_tophat_noSatu_membrane
    Use objects or an image as a mask?:Objects
    Select object for mask:membranes
    Select image for mask:None
    Invert the mask?:No

MaskImage:[module_num:108|svn_version:\'11025\'|variable_revision_number:3|show_window:False|notes:\x5B\x5D]
    Select the input image:lipid_3ms_75ms_tophat_noSatu
    Name the output image:lipid_3ms_75ms_tophat_noSatu_membrane
    Use objects or an image as a mask?:Objects
    Select object for mask:membranes
    Select image for mask:None
    Invert the mask?:No

MaskImage:[module_num:109|svn_version:\'11025\'|variable_revision_number:3|show_window:False|notes:\x5B\x5D]
    Select the input image:lipid_3ms_100ms_tophat_noSatu
    Name the output image:lipid_3ms_100ms_tophat_noSatu_membrane
    Use objects or an image as a mask?:Objects
    Select object for mask:membranes
    Select image for mask:None
    Invert the mask?:No

MaskImage:[module_num:110|svn_version:\'11025\'|variable_revision_number:3|show_window:False|notes:\x5B\x5D]
    Select the input image:lipid_3ms_200ms_tophat_noSatu
    Name the output image:lipid_3ms_200ms_tophat_noSatu_membrane
    Use objects or an image as a mask?:Objects
    Select object for mask:membranes
    Select image for mask:None
    Invert the mask?:No

MaskImage:[module_num:111|svn_version:\'11025\'|variable_revision_number:3|show_window:False|notes:\x5B\x5D]
    Select the input image:lipid_3ms_300ms_tophat_noSatu
    Name the output image:lipid_3ms_300ms_tophat_noSatu_membrane
    Use objects or an image as a mask?:Objects
    Select object for mask:membranes
    Select image for mask:None
    Invert the mask?:No

MaskImage:[module_num:112|svn_version:\'11025\'|variable_revision_number:3|show_window:False|notes:\x5B\x5D]
    Select the input image:lipid_3ms_1000ms_tophat_noSatu
    Name the output image:lipid_3ms_1000ms_tophat_noSatu_membrane
    Use objects or an image as a mask?:Objects
    Select object for mask:membranes
    Select image for mask:None
    Invert the mask?:No

MaskImage:[module_num:113|svn_version:\'11025\'|variable_revision_number:3|show_window:False|notes:\x5B\x5D]
    Select the input image:lipid_3ms_2000ms_tophat_noSatu
    Name the output image:lipid_3ms_2000ms_tophat_noSatu_membrane
    Use objects or an image as a mask?:Objects
    Select object for mask:membranes
    Select image for mask:None
    Invert the mask?:No

MaskImage:[module_num:114|svn_version:\'11025\'|variable_revision_number:3|show_window:False|notes:\x5B\x5D]
    Select the input image:lipid_3ms_4000ms_tophat_noSatu
    Name the output image:lipid_3ms_4000ms_tophat_noSatu_membrane
    Use objects or an image as a mask?:Objects
    Select object for mask:membranes
    Select image for mask:None
    Invert the mask?:No

MaskImage:[module_num:115|svn_version:\'11025\'|variable_revision_number:3|show_window:False|notes:\x5B\x5D]
    Select the input image:protein_3ms_1ms_tophat_noSatu
    Name the output image:protein_3ms_1ms_tophat_noSatu_membrane
    Use objects or an image as a mask?:Objects
    Select object for mask:membranes
    Select image for mask:None
    Invert the mask?:No

MaskImage:[module_num:116|svn_version:\'11025\'|variable_revision_number:3|show_window:False|notes:\x5B\x5D]
    Select the input image:protein_3ms_5ms_tophat_noSatu
    Name the output image:protein_3ms_5ms_tophat_noSatu_membrane
    Use objects or an image as a mask?:Objects
    Select object for mask:membranes
    Select image for mask:None
    Invert the mask?:No

MaskImage:[module_num:117|svn_version:\'11025\'|variable_revision_number:3|show_window:False|notes:\x5B\x5D]
    Select the input image:protein_3ms_10ms_tophat_noSatu
    Name the output image:protein_3ms_10ms_tophat_noSatu_membrane
    Use objects or an image as a mask?:Objects
    Select object for mask:membranes
    Select image for mask:None
    Invert the mask?:No

MaskImage:[module_num:118|svn_version:\'11025\'|variable_revision_number:3|show_window:False|notes:\x5B\x5D]
    Select the input image:protein_3ms_30ms_tophat_noSatu
    Name the output image:protein_3ms_30ms_tophat_noSatu_membrane
    Use objects or an image as a mask?:Objects
    Select object for mask:membranes
    Select image for mask:None
    Invert the mask?:No

MaskImage:[module_num:119|svn_version:\'11025\'|variable_revision_number:3|show_window:False|notes:\x5B\x5D]
    Select the input image:protein_3ms_50ms_tophat_noSatu
    Name the output image:protein_3ms_50ms_tophat_noSatu_membrane
    Use objects or an image as a mask?:Objects
    Select object for mask:membranes
    Select image for mask:None
    Invert the mask?:No

MaskImage:[module_num:120|svn_version:\'11025\'|variable_revision_number:3|show_window:False|notes:\x5B\x5D]
    Select the input image:protein_3ms_75ms_tophat_noSatu
    Name the output image:protein_3ms_75ms_tophat_noSatu_membrane
    Use objects or an image as a mask?:Objects
    Select object for mask:membranes
    Select image for mask:None
    Invert the mask?:No

MaskImage:[module_num:121|svn_version:\'11025\'|variable_revision_number:3|show_window:False|notes:\x5B\x5D]
    Select the input image:protein_3ms_100ms_tophat_noSatu
    Name the output image:protein_3ms_100ms_tophat_noSatu_membrane
    Use objects or an image as a mask?:Objects
    Select object for mask:membranes
    Select image for mask:None
    Invert the mask?:No

MaskImage:[module_num:122|svn_version:\'11025\'|variable_revision_number:3|show_window:False|notes:\x5B\x5D]
    Select the input image:protein_3ms_200ms_tophat_noSatu
    Name the output image:protein_3ms_200ms_tophat_noSatu_membrane
    Use objects or an image as a mask?:Objects
    Select object for mask:membranes
    Select image for mask:None
    Invert the mask?:No

MaskImage:[module_num:123|svn_version:\'11025\'|variable_revision_number:3|show_window:False|notes:\x5B\x5D]
    Select the input image:protein_3ms_300ms_tophat_noSatu
    Name the output image:protein_3ms_300ms_tophat_noSatu_membrane
    Use objects or an image as a mask?:Objects
    Select object for mask:membranes
    Select image for mask:None
    Invert the mask?:No

MaskImage:[module_num:124|svn_version:\'11025\'|variable_revision_number:3|show_window:False|notes:\x5B\x5D]
    Select the input image:protein_3ms_1000ms_tophat_noSatu
    Name the output image:protein_3ms_1000ms_tophat_noSatu_membrane
    Use objects or an image as a mask?:Objects
    Select object for mask:membranes
    Select image for mask:None
    Invert the mask?:No

MaskImage:[module_num:125|svn_version:\'11025\'|variable_revision_number:3|show_window:False|notes:\x5B\x5D]
    Select the input image:protein_3ms_2000ms_tophat_noSatu
    Name the output image:protein_3ms_2000ms_tophat_noSatu_membrane
    Use objects or an image as a mask?:Objects
    Select object for mask:membranes
    Select image for mask:None
    Invert the mask?:No

MaskImage:[module_num:126|svn_version:\'11025\'|variable_revision_number:3|show_window:False|notes:\x5B\x5D]
    Select the input image:protein_3ms_4000ms_tophat_noSatu
    Name the output image:protein_3ms_4000ms_tophat_noSatu_membrane
    Use objects or an image as a mask?:Objects
    Select object for mask:membranes
    Select image for mask:None
    Invert the mask?:No

OverlayOutlines:[module_num:127|svn_version:\'11025\'|variable_revision_number:2|show_window:False|notes:\x5B\x5D]
    Display outlines on a blank image?:No
    Select image on which to display outlines:lipid_3ms
    Name the output image:lipid_3ms_maskOverlay
    Select outline display mode:Color
    Select method to determine brightness of outlines:Max of image
    Width of outlines:1
    Select outlines to display:membrane_outlines
    Select outline color:Red

OverlayOutlines:[module_num:128|svn_version:\'11025\'|variable_revision_number:2|show_window:False|notes:\x5B\x5D]
    Display outlines on a blank image?:No
    Select image on which to display outlines:lipid_3ms
    Name the output image:lipid_3ms_maskOverlay_withLiposCenters
    Select outline display mode:Color
    Select method to determine brightness of outlines:Max of image
    Width of outlines:3
    Select outlines to display:membrane_outlines
    Select outline color:Red
    Select outlines to display:liposomeCenterOutlines
    Select outline color:Yellow

ApplyThreshold:[module_num:129|svn_version:\'6746\'|variable_revision_number:5|show_window:False|notes:\x5B\x5D]
    Select the input image:lipid_3ms_1ms_tophat_noSatu_membrane
    Name the output image:lipid_3ms_1ms_finOutput_bw
    Select the output image type:Binary (black and white)
    Set pixels below or above the threshold to zero?:Below threshold
    Subtract the threshold value from the remaining pixel intensities?:No
    Number of pixels by which to expand the thresholding around those excluded bright pixels:0.0
    Select the thresholding method:Manual
    Manual threshold:0.0
    Lower and upper bounds on threshold:0.000000,1.000000
    Threshold correction factor:1
    Approximate fraction of image covered by objects?:0.01
    Select the input objects:None
    Two-class or three-class thresholding?:Two classes
    Minimize the weighted variance or the entropy?:Weighted variance
    Assign pixels in the middle intensity class to the foreground or the background?:Foreground
    Select the measurement to threshold with:None

ApplyThreshold:[module_num:130|svn_version:\'6746\'|variable_revision_number:5|show_window:False|notes:\x5B\x5D]
    Select the input image:lipid_3ms_5ms_tophat_noSatu_membrane
    Name the output image:lipid_3ms_5ms_finOutput_bw
    Select the output image type:Binary (black and white)
    Set pixels below or above the threshold to zero?:Below threshold
    Subtract the threshold value from the remaining pixel intensities?:No
    Number of pixels by which to expand the thresholding around those excluded bright pixels:0.0
    Select the thresholding method:Manual
    Manual threshold:0.0
    Lower and upper bounds on threshold:0.000000,1.000000
    Threshold correction factor:1
    Approximate fraction of image covered by objects?:0.01
    Select the input objects:None
    Two-class or three-class thresholding?:Two classes
    Minimize the weighted variance or the entropy?:Weighted variance
    Assign pixels in the middle intensity class to the foreground or the background?:Foreground
    Select the measurement to threshold with:None

ApplyThreshold:[module_num:131|svn_version:\'6746\'|variable_revision_number:5|show_window:False|notes:\x5B\x5D]
    Select the input image:lipid_3ms_10ms_tophat_noSatu_membrane
    Name the output image:lipid_3ms_10ms_finOutput_bw
    Select the output image type:Binary (black and white)
    Set pixels below or above the threshold to zero?:Below threshold
    Subtract the threshold value from the remaining pixel intensities?:No
    Number of pixels by which to expand the thresholding around those excluded bright pixels:0.0
    Select the thresholding method:Manual
    Manual threshold:0.0
    Lower and upper bounds on threshold:0.000000,1.000000
    Threshold correction factor:1
    Approximate fraction of image covered by objects?:0.01
    Select the input objects:None
    Two-class or three-class thresholding?:Two classes
    Minimize the weighted variance or the entropy?:Weighted variance
    Assign pixels in the middle intensity class to the foreground or the background?:Foreground
    Select the measurement to threshold with:None

ApplyThreshold:[module_num:132|svn_version:\'6746\'|variable_revision_number:5|show_window:False|notes:\x5B\x5D]
    Select the input image:lipid_3ms_30ms_tophat_noSatu_membrane
    Name the output image:lipid_3ms_30ms_finOutput_bw
    Select the output image type:Binary (black and white)
    Set pixels below or above the threshold to zero?:Below threshold
    Subtract the threshold value from the remaining pixel intensities?:No
    Number of pixels by which to expand the thresholding around those excluded bright pixels:0.0
    Select the thresholding method:Manual
    Manual threshold:0.0
    Lower and upper bounds on threshold:0.000000,1.000000
    Threshold correction factor:1
    Approximate fraction of image covered by objects?:0.01
    Select the input objects:None
    Two-class or three-class thresholding?:Two classes
    Minimize the weighted variance or the entropy?:Weighted variance
    Assign pixels in the middle intensity class to the foreground or the background?:Foreground
    Select the measurement to threshold with:None

ApplyThreshold:[module_num:133|svn_version:\'6746\'|variable_revision_number:5|show_window:False|notes:\x5B\x5D]
    Select the input image:lipid_3ms_50ms_tophat_noSatu_membrane
    Name the output image:lipid_3ms_50ms_finOutput_bw
    Select the output image type:Binary (black and white)
    Set pixels below or above the threshold to zero?:Below threshold
    Subtract the threshold value from the remaining pixel intensities?:No
    Number of pixels by which to expand the thresholding around those excluded bright pixels:0.0
    Select the thresholding method:Manual
    Manual threshold:0.0
    Lower and upper bounds on threshold:0.000000,1.000000
    Threshold correction factor:1
    Approximate fraction of image covered by objects?:0.01
    Select the input objects:None
    Two-class or three-class thresholding?:Two classes
    Minimize the weighted variance or the entropy?:Weighted variance
    Assign pixels in the middle intensity class to the foreground or the background?:Foreground
    Select the measurement to threshold with:None

ApplyThreshold:[module_num:134|svn_version:\'6746\'|variable_revision_number:5|show_window:False|notes:\x5B\x5D]
    Select the input image:lipid_3ms_75ms_tophat_noSatu_membrane
    Name the output image:lipid_3ms_75ms_finOutput_bw
    Select the output image type:Binary (black and white)
    Set pixels below or above the threshold to zero?:Below threshold
    Subtract the threshold value from the remaining pixel intensities?:No
    Number of pixels by which to expand the thresholding around those excluded bright pixels:0.0
    Select the thresholding method:Manual
    Manual threshold:0.0
    Lower and upper bounds on threshold:0.000000,1.000000
    Threshold correction factor:1
    Approximate fraction of image covered by objects?:0.01
    Select the input objects:None
    Two-class or three-class thresholding?:Two classes
    Minimize the weighted variance or the entropy?:Weighted variance
    Assign pixels in the middle intensity class to the foreground or the background?:Foreground
    Select the measurement to threshold with:None

ApplyThreshold:[module_num:135|svn_version:\'6746\'|variable_revision_number:5|show_window:False|notes:\x5B\x5D]
    Select the input image:lipid_3ms_100ms_tophat_noSatu_membrane
    Name the output image:lipid_3ms_100ms_finOutput_bw
    Select the output image type:Binary (black and white)
    Set pixels below or above the threshold to zero?:Below threshold
    Subtract the threshold value from the remaining pixel intensities?:No
    Number of pixels by which to expand the thresholding around those excluded bright pixels:0.0
    Select the thresholding method:Manual
    Manual threshold:0.0
    Lower and upper bounds on threshold:0.000000,1.000000
    Threshold correction factor:1
    Approximate fraction of image covered by objects?:0.01
    Select the input objects:None
    Two-class or three-class thresholding?:Two classes
    Minimize the weighted variance or the entropy?:Weighted variance
    Assign pixels in the middle intensity class to the foreground or the background?:Foreground
    Select the measurement to threshold with:None

ApplyThreshold:[module_num:136|svn_version:\'6746\'|variable_revision_number:5|show_window:False|notes:\x5B\x5D]
    Select the input image:lipid_3ms_200ms_tophat_noSatu_membrane
    Name the output image:lipid_3ms_200ms_finOutput_bw
    Select the output image type:Binary (black and white)
    Set pixels below or above the threshold to zero?:Below threshold
    Subtract the threshold value from the remaining pixel intensities?:No
    Number of pixels by which to expand the thresholding around those excluded bright pixels:0.0
    Select the thresholding method:Manual
    Manual threshold:0.0
    Lower and upper bounds on threshold:0.000000,1.000000
    Threshold correction factor:1
    Approximate fraction of image covered by objects?:0.01
    Select the input objects:None
    Two-class or three-class thresholding?:Two classes
    Minimize the weighted variance or the entropy?:Weighted variance
    Assign pixels in the middle intensity class to the foreground or the background?:Foreground
    Select the measurement to threshold with:None

ApplyThreshold:[module_num:137|svn_version:\'6746\'|variable_revision_number:5|show_window:False|notes:\x5B\x5D]
    Select the input image:lipid_3ms_300ms_tophat_noSatu_membrane
    Name the output image:lipid_3ms_300ms_finOutput_bw
    Select the output image type:Binary (black and white)
    Set pixels below or above the threshold to zero?:Below threshold
    Subtract the threshold value from the remaining pixel intensities?:No
    Number of pixels by which to expand the thresholding around those excluded bright pixels:0.0
    Select the thresholding method:Manual
    Manual threshold:0.0
    Lower and upper bounds on threshold:0.000000,1.000000
    Threshold correction factor:1
    Approximate fraction of image covered by objects?:0.01
    Select the input objects:None
    Two-class or three-class thresholding?:Two classes
    Minimize the weighted variance or the entropy?:Weighted variance
    Assign pixels in the middle intensity class to the foreground or the background?:Foreground
    Select the measurement to threshold with:None

ApplyThreshold:[module_num:138|svn_version:\'6746\'|variable_revision_number:5|show_window:False|notes:\x5B\x5D]
    Select the input image:lipid_3ms_1000ms_tophat_noSatu_membrane
    Name the output image:lipid_3ms_1000ms_finOutput_bw
    Select the output image type:Binary (black and white)
    Set pixels below or above the threshold to zero?:Below threshold
    Subtract the threshold value from the remaining pixel intensities?:No
    Number of pixels by which to expand the thresholding around those excluded bright pixels:0.0
    Select the thresholding method:Manual
    Manual threshold:0.0
    Lower and upper bounds on threshold:0.000000,1.000000
    Threshold correction factor:1
    Approximate fraction of image covered by objects?:0.01
    Select the input objects:None
    Two-class or three-class thresholding?:Two classes
    Minimize the weighted variance or the entropy?:Weighted variance
    Assign pixels in the middle intensity class to the foreground or the background?:Foreground
    Select the measurement to threshold with:None

ApplyThreshold:[module_num:139|svn_version:\'6746\'|variable_revision_number:5|show_window:False|notes:\x5B\x5D]
    Select the input image:lipid_3ms_2000ms_tophat_noSatu_membrane
    Name the output image:lipid_3ms_2000ms_finOutput_bw
    Select the output image type:Binary (black and white)
    Set pixels below or above the threshold to zero?:Below threshold
    Subtract the threshold value from the remaining pixel intensities?:No
    Number of pixels by which to expand the thresholding around those excluded bright pixels:0.0
    Select the thresholding method:Manual
    Manual threshold:0.0
    Lower and upper bounds on threshold:0.000000,1.000000
    Threshold correction factor:1
    Approximate fraction of image covered by objects?:0.01
    Select the input objects:None
    Two-class or three-class thresholding?:Two classes
    Minimize the weighted variance or the entropy?:Weighted variance
    Assign pixels in the middle intensity class to the foreground or the background?:Foreground
    Select the measurement to threshold with:None

ApplyThreshold:[module_num:140|svn_version:\'6746\'|variable_revision_number:5|show_window:False|notes:\x5B\x5D]
    Select the input image:lipid_3ms_4000ms_tophat_noSatu_membrane
    Name the output image:lipid_3ms_4000ms_finOutput_bw
    Select the output image type:Binary (black and white)
    Set pixels below or above the threshold to zero?:Below threshold
    Subtract the threshold value from the remaining pixel intensities?:No
    Number of pixels by which to expand the thresholding around those excluded bright pixels:0.0
    Select the thresholding method:Manual
    Manual threshold:0.0
    Lower and upper bounds on threshold:0.000000,1.000000
    Threshold correction factor:1
    Approximate fraction of image covered by objects?:0.01
    Select the input objects:None
    Two-class or three-class thresholding?:Two classes
    Minimize the weighted variance or the entropy?:Weighted variance
    Assign pixels in the middle intensity class to the foreground or the background?:Foreground
    Select the measurement to threshold with:None

ApplyThreshold:[module_num:141|svn_version:\'6746\'|variable_revision_number:5|show_window:False|notes:\x5B\x5D]
    Select the input image:protein_3ms_1ms_tophat_noSatu_membrane
    Name the output image:protein_3ms_1ms_finOutput_bw
    Select the output image type:Binary (black and white)
    Set pixels below or above the threshold to zero?:Below threshold
    Subtract the threshold value from the remaining pixel intensities?:No
    Number of pixels by which to expand the thresholding around those excluded bright pixels:0.0
    Select the thresholding method:Manual
    Manual threshold:0.0
    Lower and upper bounds on threshold:0.000000,1.000000
    Threshold correction factor:1
    Approximate fraction of image covered by objects?:0.01
    Select the input objects:None
    Two-class or three-class thresholding?:Two classes
    Minimize the weighted variance or the entropy?:Weighted variance
    Assign pixels in the middle intensity class to the foreground or the background?:Foreground
    Select the measurement to threshold with:None

ApplyThreshold:[module_num:142|svn_version:\'6746\'|variable_revision_number:5|show_window:False|notes:\x5B\x5D]
    Select the input image:protein_3ms_5ms_tophat_noSatu_membrane
    Name the output image:protein_3ms_5ms_finOutput_bw
    Select the output image type:Binary (black and white)
    Set pixels below or above the threshold to zero?:Below threshold
    Subtract the threshold value from the remaining pixel intensities?:No
    Number of pixels by which to expand the thresholding around those excluded bright pixels:0.0
    Select the thresholding method:Manual
    Manual threshold:0.0
    Lower and upper bounds on threshold:0.000000,1.000000
    Threshold correction factor:1
    Approximate fraction of image covered by objects?:0.01
    Select the input objects:None
    Two-class or three-class thresholding?:Two classes
    Minimize the weighted variance or the entropy?:Weighted variance
    Assign pixels in the middle intensity class to the foreground or the background?:Foreground
    Select the measurement to threshold with:None

ApplyThreshold:[module_num:143|svn_version:\'6746\'|variable_revision_number:5|show_window:False|notes:\x5B\x5D]
    Select the input image:protein_3ms_10ms_tophat_noSatu_membrane
    Name the output image:protein_3ms_10ms_finOutput_bw
    Select the output image type:Binary (black and white)
    Set pixels below or above the threshold to zero?:Below threshold
    Subtract the threshold value from the remaining pixel intensities?:No
    Number of pixels by which to expand the thresholding around those excluded bright pixels:0.0
    Select the thresholding method:Manual
    Manual threshold:0.0
    Lower and upper bounds on threshold:0.000000,1.000000
    Threshold correction factor:1
    Approximate fraction of image covered by objects?:0.01
    Select the input objects:None
    Two-class or three-class thresholding?:Two classes
    Minimize the weighted variance or the entropy?:Weighted variance
    Assign pixels in the middle intensity class to the foreground or the background?:Foreground
    Select the measurement to threshold with:None

ApplyThreshold:[module_num:144|svn_version:\'6746\'|variable_revision_number:5|show_window:False|notes:\x5B\x5D]
    Select the input image:protein_3ms_30ms_tophat_noSatu_membrane
    Name the output image:protein_3ms_30ms_finOutput_bw
    Select the output image type:Binary (black and white)
    Set pixels below or above the threshold to zero?:Below threshold
    Subtract the threshold value from the remaining pixel intensities?:No
    Number of pixels by which to expand the thresholding around those excluded bright pixels:0.0
    Select the thresholding method:Manual
    Manual threshold:0.0
    Lower and upper bounds on threshold:0.000000,1.000000
    Threshold correction factor:1
    Approximate fraction of image covered by objects?:0.01
    Select the input objects:None
    Two-class or three-class thresholding?:Two classes
    Minimize the weighted variance or the entropy?:Weighted variance
    Assign pixels in the middle intensity class to the foreground or the background?:Foreground
    Select the measurement to threshold with:None

ApplyThreshold:[module_num:145|svn_version:\'6746\'|variable_revision_number:5|show_window:False|notes:\x5B\x5D]
    Select the input image:protein_3ms_50ms_tophat_noSatu_membrane
    Name the output image:protein_3ms_50ms_finOutput_bw
    Select the output image type:Binary (black and white)
    Set pixels below or above the threshold to zero?:Below threshold
    Subtract the threshold value from the remaining pixel intensities?:No
    Number of pixels by which to expand the thresholding around those excluded bright pixels:0.0
    Select the thresholding method:Manual
    Manual threshold:0.0
    Lower and upper bounds on threshold:0.000000,1.000000
    Threshold correction factor:1
    Approximate fraction of image covered by objects?:0.01
    Select the input objects:None
    Two-class or three-class thresholding?:Two classes
    Minimize the weighted variance or the entropy?:Weighted variance
    Assign pixels in the middle intensity class to the foreground or the background?:Foreground
    Select the measurement to threshold with:None

ApplyThreshold:[module_num:146|svn_version:\'6746\'|variable_revision_number:5|show_window:False|notes:\x5B\x5D]
    Select the input image:protein_3ms_75ms_tophat_noSatu_membrane
    Name the output image:protein_3ms_75ms_finOutput_bw
    Select the output image type:Binary (black and white)
    Set pixels below or above the threshold to zero?:Below threshold
    Subtract the threshold value from the remaining pixel intensities?:No
    Number of pixels by which to expand the thresholding around those excluded bright pixels:0.0
    Select the thresholding method:Manual
    Manual threshold:0.0
    Lower and upper bounds on threshold:0.000000,1.000000
    Threshold correction factor:1
    Approximate fraction of image covered by objects?:0.01
    Select the input objects:None
    Two-class or three-class thresholding?:Two classes
    Minimize the weighted variance or the entropy?:Weighted variance
    Assign pixels in the middle intensity class to the foreground or the background?:Foreground
    Select the measurement to threshold with:None

ApplyThreshold:[module_num:147|svn_version:\'6746\'|variable_revision_number:5|show_window:False|notes:\x5B\x5D]
    Select the input image:protein_3ms_100ms_tophat_noSatu_membrane
    Name the output image:protein_3ms_100ms_finOutput_bw
    Select the output image type:Binary (black and white)
    Set pixels below or above the threshold to zero?:Below threshold
    Subtract the threshold value from the remaining pixel intensities?:No
    Number of pixels by which to expand the thresholding around those excluded bright pixels:0.0
    Select the thresholding method:Manual
    Manual threshold:0.0
    Lower and upper bounds on threshold:0.000000,1.000000
    Threshold correction factor:1
    Approximate fraction of image covered by objects?:0.01
    Select the input objects:None
    Two-class or three-class thresholding?:Two classes
    Minimize the weighted variance or the entropy?:Weighted variance
    Assign pixels in the middle intensity class to the foreground or the background?:Foreground
    Select the measurement to threshold with:None

ApplyThreshold:[module_num:148|svn_version:\'6746\'|variable_revision_number:5|show_window:False|notes:\x5B\x5D]
    Select the input image:protein_3ms_200ms_tophat_noSatu_membrane
    Name the output image:protein_3ms_200ms_finOutput_bw
    Select the output image type:Binary (black and white)
    Set pixels below or above the threshold to zero?:Below threshold
    Subtract the threshold value from the remaining pixel intensities?:No
    Number of pixels by which to expand the thresholding around those excluded bright pixels:0.0
    Select the thresholding method:Manual
    Manual threshold:0.0
    Lower and upper bounds on threshold:0.000000,1.000000
    Threshold correction factor:1
    Approximate fraction of image covered by objects?:0.01
    Select the input objects:None
    Two-class or three-class thresholding?:Two classes
    Minimize the weighted variance or the entropy?:Weighted variance
    Assign pixels in the middle intensity class to the foreground or the background?:Foreground
    Select the measurement to threshold with:None

ApplyThreshold:[module_num:149|svn_version:\'6746\'|variable_revision_number:5|show_window:False|notes:\x5B\x5D]
    Select the input image:protein_3ms_300ms_tophat_noSatu_membrane
    Name the output image:protein_3ms_300ms_finOutput_bw
    Select the output image type:Binary (black and white)
    Set pixels below or above the threshold to zero?:Below threshold
    Subtract the threshold value from the remaining pixel intensities?:No
    Number of pixels by which to expand the thresholding around those excluded bright pixels:0.0
    Select the thresholding method:Manual
    Manual threshold:0.0
    Lower and upper bounds on threshold:0.000000,1.000000
    Threshold correction factor:1
    Approximate fraction of image covered by objects?:0.01
    Select the input objects:None
    Two-class or three-class thresholding?:Two classes
    Minimize the weighted variance or the entropy?:Weighted variance
    Assign pixels in the middle intensity class to the foreground or the background?:Foreground
    Select the measurement to threshold with:None

ApplyThreshold:[module_num:150|svn_version:\'6746\'|variable_revision_number:5|show_window:False|notes:\x5B\x5D]
    Select the input image:protein_3ms_1000ms_tophat_noSatu_membrane
    Name the output image:protein_3ms_1000ms_finOutput_bw
    Select the output image type:Binary (black and white)
    Set pixels below or above the threshold to zero?:Below threshold
    Subtract the threshold value from the remaining pixel intensities?:No
    Number of pixels by which to expand the thresholding around those excluded bright pixels:0.0
    Select the thresholding method:Manual
    Manual threshold:0.0
    Lower and upper bounds on threshold:0.000000,1.000000
    Threshold correction factor:1
    Approximate fraction of image covered by objects?:0.01
    Select the input objects:None
    Two-class or three-class thresholding?:Two classes
    Minimize the weighted variance or the entropy?:Weighted variance
    Assign pixels in the middle intensity class to the foreground or the background?:Foreground
    Select the measurement to threshold with:None

ApplyThreshold:[module_num:151|svn_version:\'6746\'|variable_revision_number:5|show_window:False|notes:\x5B\x5D]
    Select the input image:protein_3ms_2000ms_tophat_noSatu_membrane
    Name the output image:protein_3ms_2000ms_finOutput_bw
    Select the output image type:Binary (black and white)
    Set pixels below or above the threshold to zero?:Below threshold
    Subtract the threshold value from the remaining pixel intensities?:No
    Number of pixels by which to expand the thresholding around those excluded bright pixels:0.0
    Select the thresholding method:Manual
    Manual threshold:0.0
    Lower and upper bounds on threshold:0.000000,1.000000
    Threshold correction factor:1
    Approximate fraction of image covered by objects?:0.01
    Select the input objects:None
    Two-class or three-class thresholding?:Two classes
    Minimize the weighted variance or the entropy?:Weighted variance
    Assign pixels in the middle intensity class to the foreground or the background?:Foreground
    Select the measurement to threshold with:None

ApplyThreshold:[module_num:152|svn_version:\'6746\'|variable_revision_number:5|show_window:False|notes:\x5B\x5D]
    Select the input image:protein_3ms_4000ms_tophat_noSatu_membrane
    Name the output image:protein_3ms_4000ms_finOutput_bw
    Select the output image type:Binary (black and white)
    Set pixels below or above the threshold to zero?:Below threshold
    Subtract the threshold value from the remaining pixel intensities?:No
    Number of pixels by which to expand the thresholding around those excluded bright pixels:0.0
    Select the thresholding method:Manual
    Manual threshold:0.0
    Lower and upper bounds on threshold:0.000000,1.000000
    Threshold correction factor:1
    Approximate fraction of image covered by objects?:0.01
    Select the input objects:None
    Two-class or three-class thresholding?:Two classes
    Minimize the weighted variance or the entropy?:Weighted variance
    Assign pixels in the middle intensity class to the foreground or the background?:Foreground
    Select the measurement to threshold with:None

GrayToColor:[module_num:153|svn_version:\'11025\'|variable_revision_number:2|show_window:False|notes:\x5B\x5D]
    Select a color scheme:RGB
    Select the input image to be colored red:lipid_3ms
    Select the input image to be colored green:Leave this black
    Select the input image to be colored blue:lipid_3ms_1ms_finOutput_bw
    Name the output image:lipid_3ms_1ms_rawVSfinalOutput
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

GrayToColor:[module_num:154|svn_version:\'11025\'|variable_revision_number:2|show_window:False|notes:\x5B\x5D]
    Select a color scheme:RGB
    Select the input image to be colored red:lipid_3ms
    Select the input image to be colored green:Leave this black
    Select the input image to be colored blue:lipid_3ms_5ms_finOutput_bw
    Name the output image:lipid_3ms_5ms_rawVSfinalOutput
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

GrayToColor:[module_num:155|svn_version:\'11025\'|variable_revision_number:2|show_window:False|notes:\x5B\x5D]
    Select a color scheme:RGB
    Select the input image to be colored red:lipid_3ms
    Select the input image to be colored green:Leave this black
    Select the input image to be colored blue:lipid_3ms_10ms_finOutput_bw
    Name the output image:lipid_3ms_10ms_rawVSfinalOutput
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

GrayToColor:[module_num:156|svn_version:\'11025\'|variable_revision_number:2|show_window:False|notes:\x5B\x5D]
    Select a color scheme:RGB
    Select the input image to be colored red:lipid_3ms
    Select the input image to be colored green:Leave this black
    Select the input image to be colored blue:lipid_3ms_30ms_finOutput_bw
    Name the output image:lipid_3ms_30ms_rawVSfinalOutput
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

GrayToColor:[module_num:157|svn_version:\'11025\'|variable_revision_number:2|show_window:False|notes:\x5B\x5D]
    Select a color scheme:RGB
    Select the input image to be colored red:lipid_3ms
    Select the input image to be colored green:Leave this black
    Select the input image to be colored blue:lipid_3ms_50ms_finOutput_bw
    Name the output image:lipid_3ms_50ms_rawVSfinalOutput
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

GrayToColor:[module_num:158|svn_version:\'11025\'|variable_revision_number:2|show_window:False|notes:\x5B\x5D]
    Select a color scheme:RGB
    Select the input image to be colored red:lipid_3ms
    Select the input image to be colored green:Leave this black
    Select the input image to be colored blue:lipid_3ms_75ms_finOutput_bw
    Name the output image:lipid_3ms_75ms_rawVSfinalOutput
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

GrayToColor:[module_num:159|svn_version:\'11025\'|variable_revision_number:2|show_window:False|notes:\x5B\x5D]
    Select a color scheme:RGB
    Select the input image to be colored red:lipid_3ms
    Select the input image to be colored green:Leave this black
    Select the input image to be colored blue:lipid_3ms_100ms_finOutput_bw
    Name the output image:lipid_3ms_100ms_rawVSfinalOutput
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

GrayToColor:[module_num:160|svn_version:\'11025\'|variable_revision_number:2|show_window:False|notes:\x5B\x5D]
    Select a color scheme:RGB
    Select the input image to be colored red:lipid_3ms
    Select the input image to be colored green:Leave this black
    Select the input image to be colored blue:lipid_3ms_200ms_finOutput_bw
    Name the output image:lipid_3ms_200ms_rawVSfinalOutput
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

GrayToColor:[module_num:161|svn_version:\'11025\'|variable_revision_number:2|show_window:False|notes:\x5B\x5D]
    Select a color scheme:RGB
    Select the input image to be colored red:lipid_3ms
    Select the input image to be colored green:Leave this black
    Select the input image to be colored blue:lipid_3ms_300ms_finOutput_bw
    Name the output image:lipid_3ms_300ms_rawVSfinalOutput
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

GrayToColor:[module_num:162|svn_version:\'11025\'|variable_revision_number:2|show_window:False|notes:\x5B\x5D]
    Select a color scheme:RGB
    Select the input image to be colored red:lipid_3ms
    Select the input image to be colored green:Leave this black
    Select the input image to be colored blue:lipid_3ms_1000ms_finOutput_bw
    Name the output image:lipid_3ms_1000ms_rawVSfinalOutput
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

GrayToColor:[module_num:163|svn_version:\'11025\'|variable_revision_number:2|show_window:False|notes:\x5B\x5D]
    Select a color scheme:RGB
    Select the input image to be colored red:lipid_3ms
    Select the input image to be colored green:Leave this black
    Select the input image to be colored blue:lipid_3ms_2000ms_finOutput_bw
    Name the output image:lipid_3ms_2000ms_rawVSfinalOutput
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

GrayToColor:[module_num:164|svn_version:\'11025\'|variable_revision_number:2|show_window:False|notes:\x5B\x5D]
    Select a color scheme:RGB
    Select the input image to be colored red:lipid_3ms
    Select the input image to be colored green:Leave this black
    Select the input image to be colored blue:lipid_3ms_4000ms_finOutput_bw
    Name the output image:lipid_3ms_4000ms_rawVSfinalOutput
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

GrayToColor:[module_num:165|svn_version:\'11025\'|variable_revision_number:2|show_window:False|notes:\x5B\x5D]
    Select a color scheme:RGB
    Select the input image to be colored red:Leave this black
    Select the input image to be colored green:protein_1ms
    Select the input image to be colored blue:protein_3ms_1ms_finOutput_bw
    Name the output image:protein_3ms_1ms_rawVSfinalOutput
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

GrayToColor:[module_num:166|svn_version:\'11025\'|variable_revision_number:2|show_window:False|notes:\x5B\x5D]
    Select a color scheme:RGB
    Select the input image to be colored red:Leave this black
    Select the input image to be colored green:protein_5ms
    Select the input image to be colored blue:protein_3ms_5ms_finOutput_bw
    Name the output image:protein_3ms_5ms_rawVSfinalOutput
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

GrayToColor:[module_num:167|svn_version:\'11025\'|variable_revision_number:2|show_window:False|notes:\x5B\x5D]
    Select a color scheme:RGB
    Select the input image to be colored red:Leave this black
    Select the input image to be colored green:protein_10ms
    Select the input image to be colored blue:protein_3ms_10ms_finOutput_bw
    Name the output image:protein_3ms_10ms_rawVSfinalOutput
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

GrayToColor:[module_num:168|svn_version:\'11025\'|variable_revision_number:2|show_window:False|notes:\x5B\x5D]
    Select a color scheme:RGB
    Select the input image to be colored red:Leave this black
    Select the input image to be colored green:protein_30ms
    Select the input image to be colored blue:protein_3ms_30ms_finOutput_bw
    Name the output image:protein_3ms_30ms_rawVSfinalOutput
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

GrayToColor:[module_num:169|svn_version:\'11025\'|variable_revision_number:2|show_window:False|notes:\x5B\x5D]
    Select a color scheme:RGB
    Select the input image to be colored red:Leave this black
    Select the input image to be colored green:protein_50ms
    Select the input image to be colored blue:protein_3ms_50ms_finOutput_bw
    Name the output image:protein_3ms_50ms_rawVSfinalOutput
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

GrayToColor:[module_num:170|svn_version:\'11025\'|variable_revision_number:2|show_window:False|notes:\x5B\x5D]
    Select a color scheme:RGB
    Select the input image to be colored red:Leave this black
    Select the input image to be colored green:protein_75ms
    Select the input image to be colored blue:protein_3ms_75ms_finOutput_bw
    Name the output image:protein_3ms_75ms_rawVSfinalOutput
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

GrayToColor:[module_num:171|svn_version:\'11025\'|variable_revision_number:2|show_window:False|notes:\x5B\x5D]
    Select a color scheme:RGB
    Select the input image to be colored red:Leave this black
    Select the input image to be colored green:protein_100ms
    Select the input image to be colored blue:protein_3ms_100ms_finOutput_bw
    Name the output image:protein_3ms_100ms_rawVSfinalOutput
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

GrayToColor:[module_num:172|svn_version:\'11025\'|variable_revision_number:2|show_window:False|notes:\x5B\x5D]
    Select a color scheme:RGB
    Select the input image to be colored red:Leave this black
    Select the input image to be colored green:protein_200ms
    Select the input image to be colored blue:protein_3ms_200ms_finOutput_bw
    Name the output image:protein_3ms_200ms_rawVSfinalOutput
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

GrayToColor:[module_num:173|svn_version:\'11025\'|variable_revision_number:2|show_window:False|notes:\x5B\x5D]
    Select a color scheme:RGB
    Select the input image to be colored red:Leave this black
    Select the input image to be colored green:protein_300ms
    Select the input image to be colored blue:protein_3ms_300ms_finOutput_bw
    Name the output image:protein_3ms_300ms_rawVSfinalOutput
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

GrayToColor:[module_num:174|svn_version:\'11025\'|variable_revision_number:2|show_window:False|notes:\x5B\x5D]
    Select a color scheme:RGB
    Select the input image to be colored red:Leave this black
    Select the input image to be colored green:protein_1000ms
    Select the input image to be colored blue:protein_3ms_1000ms_finOutput_bw
    Name the output image:protein_3ms_1000ms_rawVSfinalOutput
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

GrayToColor:[module_num:175|svn_version:\'11025\'|variable_revision_number:2|show_window:False|notes:\x5B\x5D]
    Select a color scheme:RGB
    Select the input image to be colored red:Leave this black
    Select the input image to be colored green:protein_2000ms
    Select the input image to be colored blue:protein_3ms_2000ms_finOutput_bw
    Name the output image:protein_3ms_2000ms_rawVSfinalOutput
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

GrayToColor:[module_num:176|svn_version:\'11025\'|variable_revision_number:2|show_window:False|notes:\x5B\x5D]
    Select a color scheme:RGB
    Select the input image to be colored red:Leave this black
    Select the input image to be colored green:protein_4000ms
    Select the input image to be colored blue:lipid_3ms_4000ms_finOutput_bw
    Name the output image:protein_3ms_4000ms_rawVSfinalOutput
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

SaveImages:[module_num:177|svn_version:\'11042\'|variable_revision_number:7|show_window:False|notes:\x5B\x5D]
    Select the type of image to save:Image
    Select the image to save:protein_3ms_1ms_tophat_noSatu_membrane
    Select the objects to save:None
    Select the module display window to save:None
    Select method for constructing file names:From image filename
    Select image name for file prefix:protein_raw_1ms
    Enter single file name:OrigBlue
    Do you want to add a suffix to the image file name?:Yes
    Text to append to the image name:--membraneGFP
    Select file format to use:jpeg
    Output file location:Elsewhere...\x7C/g/gavin/projects/Liposome_screen/www/\\g<runPath>--cellprofiler/\\g<wellPath>
    Image bit depth:8
    Overwrite existing files without warning?:Yes
    Select how often to save:Every cycle
    Rescale the images? :Yes
    Save as grayscale or color image?:Grayscale
    Select colormap:gray
    Store file and path information to the saved image?:No
    Create subfolders in the output folder?:No

SaveImages:[module_num:178|svn_version:\'11042\'|variable_revision_number:7|show_window:False|notes:\x5B\x5D]
    Select the type of image to save:Image
    Select the image to save:protein_3ms_1ms_rawVSfinalOutput
    Select the objects to save:None
    Select the module display window to save:None
    Select method for constructing file names:From image filename
    Select image name for file prefix:protein_raw_1ms
    Enter single file name:OrigBlue
    Do you want to add a suffix to the image file name?:Yes
    Text to append to the image name:--RawFinOverlayGFP
    Select file format to use:jpeg
    Output file location:Elsewhere...\x7C/g/gavin/projects/Liposome_screen/www/\\g<runPath>--cellprofiler/\\g<wellPath>
    Image bit depth:8
    Overwrite existing files without warning?:Yes
    Select how often to save:Every cycle
    Rescale the images? :Yes
    Save as grayscale or color image?:Grayscale
    Select colormap:gray
    Store file and path information to the saved image?:No
    Create subfolders in the output folder?:No

SaveImages:[module_num:179|svn_version:\'11042\'|variable_revision_number:7|show_window:False|notes:\x5B\x5D]
    Select the type of image to save:Image
    Select the image to save:lipid_3ms_1ms_rawVSfinalOutput
    Select the objects to save:None
    Select the module display window to save:None
    Select method for constructing file names:From image filename
    Select image name for file prefix:protein_raw_1ms
    Enter single file name:OrigBlue
    Do you want to add a suffix to the image file name?:Yes
    Text to append to the image name:--RawFinOverlayCy5
    Select file format to use:jpeg
    Output file location:Elsewhere...\x7C/g/gavin/projects/Liposome_screen/www/\\g<runPath>--cellprofiler/\\g<wellPath>
    Image bit depth:8
    Overwrite existing files without warning?:Yes
    Select how often to save:Every cycle
    Rescale the images? :Yes
    Save as grayscale or color image?:Grayscale
    Select colormap:gray
    Store file and path information to the saved image?:No
    Create subfolders in the output folder?:No

SaveImages:[module_num:180|svn_version:\'11042\'|variable_revision_number:7|show_window:False|notes:\x5B\x5D]
    Select the type of image to save:Image
    Select the image to save:protein_3ms_5ms_tophat_noSatu_membrane
    Select the objects to save:None
    Select the module display window to save:None
    Select method for constructing file names:From image filename
    Select image name for file prefix:protein_raw_5ms
    Enter single file name:OrigBlue
    Do you want to add a suffix to the image file name?:Yes
    Text to append to the image name:--membraneGFP
    Select file format to use:jpeg
    Output file location:Elsewhere...\x7C/g/gavin/projects/Liposome_screen/www/\\g<runPath>--cellprofiler/\\g<wellPath>
    Image bit depth:8
    Overwrite existing files without warning?:Yes
    Select how often to save:Every cycle
    Rescale the images? :Yes
    Save as grayscale or color image?:Grayscale
    Select colormap:gray
    Store file and path information to the saved image?:No
    Create subfolders in the output folder?:No

SaveImages:[module_num:181|svn_version:\'11042\'|variable_revision_number:7|show_window:False|notes:\x5B\x5D]
    Select the type of image to save:Image
    Select the image to save:protein_3ms_5ms_rawVSfinalOutput
    Select the objects to save:None
    Select the module display window to save:None
    Select method for constructing file names:From image filename
    Select image name for file prefix:protein_raw_5ms
    Enter single file name:OrigBlue
    Do you want to add a suffix to the image file name?:Yes
    Text to append to the image name:--RawFinOverlayGFP
    Select file format to use:jpeg
    Output file location:Elsewhere...\x7C/g/gavin/projects/Liposome_screen/www/\\g<runPath>--cellprofiler/\\g<wellPath>
    Image bit depth:8
    Overwrite existing files without warning?:Yes
    Select how often to save:Every cycle
    Rescale the images? :Yes
    Save as grayscale or color image?:Grayscale
    Select colormap:gray
    Store file and path information to the saved image?:No
    Create subfolders in the output folder?:No

SaveImages:[module_num:182|svn_version:\'11042\'|variable_revision_number:7|show_window:False|notes:\x5B\x5D]
    Select the type of image to save:Image
    Select the image to save:lipid_3ms_5ms_rawVSfinalOutput
    Select the objects to save:None
    Select the module display window to save:None
    Select method for constructing file names:From image filename
    Select image name for file prefix:protein_raw_5ms
    Enter single file name:OrigBlue
    Do you want to add a suffix to the image file name?:Yes
    Text to append to the image name:--RawFinOverlayCy5
    Select file format to use:jpeg
    Output file location:Elsewhere...\x7C/g/gavin/projects/Liposome_screen/www/\\g<runPath>--cellprofiler/\\g<wellPath>
    Image bit depth:8
    Overwrite existing files without warning?:Yes
    Select how often to save:Every cycle
    Rescale the images? :Yes
    Save as grayscale or color image?:Grayscale
    Select colormap:gray
    Store file and path information to the saved image?:No
    Create subfolders in the output folder?:No

SaveImages:[module_num:183|svn_version:\'11042\'|variable_revision_number:7|show_window:False|notes:\x5B\x5D]
    Select the type of image to save:Image
    Select the image to save:protein_3ms_10ms_tophat_noSatu_membrane
    Select the objects to save:None
    Select the module display window to save:None
    Select method for constructing file names:From image filename
    Select image name for file prefix:protein_raw_10ms
    Enter single file name:OrigBlue
    Do you want to add a suffix to the image file name?:Yes
    Text to append to the image name:--membraneGFP
    Select file format to use:jpeg
    Output file location:Elsewhere...\x7C/g/gavin/projects/Liposome_screen/www/\\g<runPath>--cellprofiler/\\g<wellPath>
    Image bit depth:8
    Overwrite existing files without warning?:Yes
    Select how often to save:Every cycle
    Rescale the images? :Yes
    Save as grayscale or color image?:Grayscale
    Select colormap:gray
    Store file and path information to the saved image?:No
    Create subfolders in the output folder?:No

SaveImages:[module_num:184|svn_version:\'11042\'|variable_revision_number:7|show_window:False|notes:\x5B\x5D]
    Select the type of image to save:Image
    Select the image to save:protein_3ms_10ms_rawVSfinalOutput
    Select the objects to save:None
    Select the module display window to save:None
    Select method for constructing file names:From image filename
    Select image name for file prefix:protein_raw_10ms
    Enter single file name:OrigBlue
    Do you want to add a suffix to the image file name?:Yes
    Text to append to the image name:--RawFinOverlayGFP
    Select file format to use:jpeg
    Output file location:Elsewhere...\x7C/g/gavin/projects/Liposome_screen/www/\\g<runPath>--cellprofiler/\\g<wellPath>
    Image bit depth:8
    Overwrite existing files without warning?:Yes
    Select how often to save:Every cycle
    Rescale the images? :Yes
    Save as grayscale or color image?:Grayscale
    Select colormap:gray
    Store file and path information to the saved image?:No
    Create subfolders in the output folder?:No

SaveImages:[module_num:185|svn_version:\'11042\'|variable_revision_number:7|show_window:False|notes:\x5B\x5D]
    Select the type of image to save:Image
    Select the image to save:lipid_3ms_10ms_rawVSfinalOutput
    Select the objects to save:None
    Select the module display window to save:None
    Select method for constructing file names:From image filename
    Select image name for file prefix:protein_raw_10ms
    Enter single file name:OrigBlue
    Do you want to add a suffix to the image file name?:Yes
    Text to append to the image name:--RawFinOverlayCy5
    Select file format to use:jpeg
    Output file location:Elsewhere...\x7C/g/gavin/projects/Liposome_screen/www/\\g<runPath>--cellprofiler/\\g<wellPath>
    Image bit depth:8
    Overwrite existing files without warning?:Yes
    Select how often to save:Every cycle
    Rescale the images? :Yes
    Save as grayscale or color image?:Grayscale
    Select colormap:gray
    Store file and path information to the saved image?:No
    Create subfolders in the output folder?:No

SaveImages:[module_num:186|svn_version:\'11042\'|variable_revision_number:7|show_window:False|notes:\x5B\x5D]
    Select the type of image to save:Image
    Select the image to save:protein_3ms_30ms_tophat_noSatu_membrane
    Select the objects to save:None
    Select the module display window to save:None
    Select method for constructing file names:From image filename
    Select image name for file prefix:protein_raw_30ms
    Enter single file name:OrigBlue
    Do you want to add a suffix to the image file name?:Yes
    Text to append to the image name:--membraneGFP
    Select file format to use:jpeg
    Output file location:Elsewhere...\x7C/g/gavin/projects/Liposome_screen/www/\\g<runPath>--cellprofiler/\\g<wellPath>
    Image bit depth:8
    Overwrite existing files without warning?:Yes
    Select how often to save:Every cycle
    Rescale the images? :Yes
    Save as grayscale or color image?:Grayscale
    Select colormap:gray
    Store file and path information to the saved image?:No
    Create subfolders in the output folder?:No

SaveImages:[module_num:187|svn_version:\'11042\'|variable_revision_number:7|show_window:False|notes:\x5B\x5D]
    Select the type of image to save:Image
    Select the image to save:protein_3ms_30ms_rawVSfinalOutput
    Select the objects to save:None
    Select the module display window to save:None
    Select method for constructing file names:From image filename
    Select image name for file prefix:protein_raw_30ms
    Enter single file name:OrigBlue
    Do you want to add a suffix to the image file name?:Yes
    Text to append to the image name:--RawFinOverlayGFP
    Select file format to use:jpeg
    Output file location:Elsewhere...\x7C/g/gavin/projects/Liposome_screen/www/\\g<runPath>--cellprofiler/\\g<wellPath>
    Image bit depth:8
    Overwrite existing files without warning?:Yes
    Select how often to save:Every cycle
    Rescale the images? :Yes
    Save as grayscale or color image?:Grayscale
    Select colormap:gray
    Store file and path information to the saved image?:No
    Create subfolders in the output folder?:No

SaveImages:[module_num:188|svn_version:\'11042\'|variable_revision_number:7|show_window:False|notes:\x5B\x5D]
    Select the type of image to save:Image
    Select the image to save:lipid_3ms_30ms_rawVSfinalOutput
    Select the objects to save:None
    Select the module display window to save:None
    Select method for constructing file names:From image filename
    Select image name for file prefix:protein_raw_30ms
    Enter single file name:OrigBlue
    Do you want to add a suffix to the image file name?:Yes
    Text to append to the image name:--RawFinOverlayCy5
    Select file format to use:jpeg
    Output file location:Elsewhere...\x7C/g/gavin/projects/Liposome_screen/www/\\g<runPath>--cellprofiler/\\g<wellPath>
    Image bit depth:8
    Overwrite existing files without warning?:Yes
    Select how often to save:Every cycle
    Rescale the images? :Yes
    Save as grayscale or color image?:Grayscale
    Select colormap:gray
    Store file and path information to the saved image?:No
    Create subfolders in the output folder?:No

SaveImages:[module_num:189|svn_version:\'11042\'|variable_revision_number:7|show_window:False|notes:\x5B\x5D]
    Select the type of image to save:Image
    Select the image to save:protein_3ms_50ms_tophat_noSatu_membrane
    Select the objects to save:None
    Select the module display window to save:None
    Select method for constructing file names:From image filename
    Select image name for file prefix:protein_raw_50ms
    Enter single file name:OrigBlue
    Do you want to add a suffix to the image file name?:Yes
    Text to append to the image name:--membraneGFP
    Select file format to use:jpeg
    Output file location:Elsewhere...\x7C/g/gavin/projects/Liposome_screen/www/\\g<runPath>--cellprofiler/\\g<wellPath>
    Image bit depth:8
    Overwrite existing files without warning?:Yes
    Select how often to save:Every cycle
    Rescale the images? :Yes
    Save as grayscale or color image?:Grayscale
    Select colormap:gray
    Store file and path information to the saved image?:No
    Create subfolders in the output folder?:No

SaveImages:[module_num:190|svn_version:\'11042\'|variable_revision_number:7|show_window:False|notes:\x5B\x5D]
    Select the type of image to save:Image
    Select the image to save:protein_3ms_50ms_rawVSfinalOutput
    Select the objects to save:None
    Select the module display window to save:None
    Select method for constructing file names:From image filename
    Select image name for file prefix:protein_raw_50ms
    Enter single file name:OrigBlue
    Do you want to add a suffix to the image file name?:Yes
    Text to append to the image name:--RawFinOverlayGFP
    Select file format to use:jpeg
    Output file location:Elsewhere...\x7C/g/gavin/projects/Liposome_screen/www/\\g<runPath>--cellprofiler/\\g<wellPath>
    Image bit depth:8
    Overwrite existing files without warning?:Yes
    Select how often to save:Every cycle
    Rescale the images? :Yes
    Save as grayscale or color image?:Grayscale
    Select colormap:gray
    Store file and path information to the saved image?:No
    Create subfolders in the output folder?:No

SaveImages:[module_num:191|svn_version:\'11042\'|variable_revision_number:7|show_window:False|notes:\x5B\x5D]
    Select the type of image to save:Image
    Select the image to save:lipid_3ms_50ms_rawVSfinalOutput
    Select the objects to save:None
    Select the module display window to save:None
    Select method for constructing file names:From image filename
    Select image name for file prefix:protein_raw_50ms
    Enter single file name:OrigBlue
    Do you want to add a suffix to the image file name?:Yes
    Text to append to the image name:--RawFinOverlayCy5
    Select file format to use:jpeg
    Output file location:Elsewhere...\x7C/g/gavin/projects/Liposome_screen/www/\\g<runPath>--cellprofiler/\\g<wellPath>
    Image bit depth:8
    Overwrite existing files without warning?:Yes
    Select how often to save:Every cycle
    Rescale the images? :Yes
    Save as grayscale or color image?:Grayscale
    Select colormap:gray
    Store file and path information to the saved image?:No
    Create subfolders in the output folder?:No

SaveImages:[module_num:192|svn_version:\'11042\'|variable_revision_number:7|show_window:False|notes:\x5B\x5D]
    Select the type of image to save:Image
    Select the image to save:protein_3ms_75ms_tophat_noSatu_membrane
    Select the objects to save:None
    Select the module display window to save:None
    Select method for constructing file names:From image filename
    Select image name for file prefix:protein_raw_75ms
    Enter single file name:OrigBlue
    Do you want to add a suffix to the image file name?:Yes
    Text to append to the image name:--membraneGFP
    Select file format to use:jpeg
    Output file location:Elsewhere...\x7C/g/gavin/projects/Liposome_screen/www/\\g<runPath>--cellprofiler/\\g<wellPath>
    Image bit depth:8
    Overwrite existing files without warning?:Yes
    Select how often to save:Every cycle
    Rescale the images? :Yes
    Save as grayscale or color image?:Grayscale
    Select colormap:gray
    Store file and path information to the saved image?:No
    Create subfolders in the output folder?:No

SaveImages:[module_num:193|svn_version:\'11042\'|variable_revision_number:7|show_window:False|notes:\x5B\x5D]
    Select the type of image to save:Image
    Select the image to save:protein_3ms_75ms_rawVSfinalOutput
    Select the objects to save:None
    Select the module display window to save:None
    Select method for constructing file names:From image filename
    Select image name for file prefix:protein_raw_75ms
    Enter single file name:OrigBlue
    Do you want to add a suffix to the image file name?:Yes
    Text to append to the image name:--RawFinOverlayGFP
    Select file format to use:jpeg
    Output file location:Elsewhere...\x7C/g/gavin/projects/Liposome_screen/www/\\g<runPath>--cellprofiler/\\g<wellPath>
    Image bit depth:8
    Overwrite existing files without warning?:Yes
    Select how often to save:Every cycle
    Rescale the images? :Yes
    Save as grayscale or color image?:Grayscale
    Select colormap:gray
    Store file and path information to the saved image?:No
    Create subfolders in the output folder?:No

SaveImages:[module_num:194|svn_version:\'11042\'|variable_revision_number:7|show_window:False|notes:\x5B\x5D]
    Select the type of image to save:Image
    Select the image to save:lipid_3ms_75ms_rawVSfinalOutput
    Select the objects to save:None
    Select the module display window to save:None
    Select method for constructing file names:From image filename
    Select image name for file prefix:protein_raw_75ms
    Enter single file name:OrigBlue
    Do you want to add a suffix to the image file name?:Yes
    Text to append to the image name:--RawFinOverlayCy5
    Select file format to use:jpeg
    Output file location:Elsewhere...\x7C/g/gavin/projects/Liposome_screen/www/\\g<runPath>--cellprofiler/\\g<wellPath>
    Image bit depth:8
    Overwrite existing files without warning?:Yes
    Select how often to save:Every cycle
    Rescale the images? :Yes
    Save as grayscale or color image?:Grayscale
    Select colormap:gray
    Store file and path information to the saved image?:No
    Create subfolders in the output folder?:No

SaveImages:[module_num:195|svn_version:\'11042\'|variable_revision_number:7|show_window:False|notes:\x5B\x5D]
    Select the type of image to save:Image
    Select the image to save:protein_3ms_100ms_tophat_noSatu_membrane
    Select the objects to save:None
    Select the module display window to save:None
    Select method for constructing file names:From image filename
    Select image name for file prefix:protein_raw_100ms
    Enter single file name:OrigBlue
    Do you want to add a suffix to the image file name?:Yes
    Text to append to the image name:--membraneGFP
    Select file format to use:jpeg
    Output file location:Elsewhere...\x7C/g/gavin/projects/Liposome_screen/www/\\g<runPath>--cellprofiler/\\g<wellPath>
    Image bit depth:8
    Overwrite existing files without warning?:Yes
    Select how often to save:Every cycle
    Rescale the images? :Yes
    Save as grayscale or color image?:Grayscale
    Select colormap:gray
    Store file and path information to the saved image?:No
    Create subfolders in the output folder?:No

SaveImages:[module_num:196|svn_version:\'11042\'|variable_revision_number:7|show_window:False|notes:\x5B\x5D]
    Select the type of image to save:Image
    Select the image to save:protein_3ms_100ms_rawVSfinalOutput
    Select the objects to save:None
    Select the module display window to save:None
    Select method for constructing file names:From image filename
    Select image name for file prefix:protein_raw_100ms
    Enter single file name:OrigBlue
    Do you want to add a suffix to the image file name?:Yes
    Text to append to the image name:--RawFinOverlayGFP
    Select file format to use:jpeg
    Output file location:Elsewhere...\x7C/g/gavin/projects/Liposome_screen/www/\\g<runPath>--cellprofiler/\\g<wellPath>
    Image bit depth:8
    Overwrite existing files without warning?:Yes
    Select how often to save:Every cycle
    Rescale the images? :Yes
    Save as grayscale or color image?:Grayscale
    Select colormap:gray
    Store file and path information to the saved image?:No
    Create subfolders in the output folder?:No

SaveImages:[module_num:197|svn_version:\'11042\'|variable_revision_number:7|show_window:False|notes:\x5B\x5D]
    Select the type of image to save:Image
    Select the image to save:lipid_3ms_100ms_rawVSfinalOutput
    Select the objects to save:None
    Select the module display window to save:None
    Select method for constructing file names:From image filename
    Select image name for file prefix:protein_raw_100ms
    Enter single file name:OrigBlue
    Do you want to add a suffix to the image file name?:Yes
    Text to append to the image name:--RawFinOverlayCy5
    Select file format to use:jpeg
    Output file location:Elsewhere...\x7C/g/gavin/projects/Liposome_screen/www/\\g<runPath>--cellprofiler/\\g<wellPath>
    Image bit depth:8
    Overwrite existing files without warning?:Yes
    Select how often to save:Every cycle
    Rescale the images? :Yes
    Save as grayscale or color image?:Grayscale
    Select colormap:gray
    Store file and path information to the saved image?:No
    Create subfolders in the output folder?:No

SaveImages:[module_num:198|svn_version:\'11042\'|variable_revision_number:7|show_window:False|notes:\x5B\x5D]
    Select the type of image to save:Image
    Select the image to save:protein_3ms_200ms_tophat_noSatu_membrane
    Select the objects to save:None
    Select the module display window to save:None
    Select method for constructing file names:From image filename
    Select image name for file prefix:protein_raw_200ms
    Enter single file name:OrigBlue
    Do you want to add a suffix to the image file name?:Yes
    Text to append to the image name:--membraneGFP
    Select file format to use:jpeg
    Output file location:Elsewhere...\x7C/g/gavin/projects/Liposome_screen/www/\\g<runPath>--cellprofiler/\\g<wellPath>
    Image bit depth:8
    Overwrite existing files without warning?:Yes
    Select how often to save:Every cycle
    Rescale the images? :Yes
    Save as grayscale or color image?:Grayscale
    Select colormap:gray
    Store file and path information to the saved image?:No
    Create subfolders in the output folder?:No

SaveImages:[module_num:199|svn_version:\'11042\'|variable_revision_number:7|show_window:False|notes:\x5B\x5D]
    Select the type of image to save:Image
    Select the image to save:protein_3ms_200ms_rawVSfinalOutput
    Select the objects to save:None
    Select the module display window to save:None
    Select method for constructing file names:From image filename
    Select image name for file prefix:protein_raw_200ms
    Enter single file name:OrigBlue
    Do you want to add a suffix to the image file name?:Yes
    Text to append to the image name:--RawFinOverlayGFP
    Select file format to use:jpeg
    Output file location:Elsewhere...\x7C/g/gavin/projects/Liposome_screen/www/\\g<runPath>--cellprofiler/\\g<wellPath>
    Image bit depth:8
    Overwrite existing files without warning?:Yes
    Select how often to save:Every cycle
    Rescale the images? :Yes
    Save as grayscale or color image?:Grayscale
    Select colormap:gray
    Store file and path information to the saved image?:No
    Create subfolders in the output folder?:No

SaveImages:[module_num:200|svn_version:\'11042\'|variable_revision_number:7|show_window:False|notes:\x5B\x5D]
    Select the type of image to save:Image
    Select the image to save:lipid_3ms_200ms_rawVSfinalOutput
    Select the objects to save:None
    Select the module display window to save:None
    Select method for constructing file names:From image filename
    Select image name for file prefix:protein_raw_200ms
    Enter single file name:OrigBlue
    Do you want to add a suffix to the image file name?:Yes
    Text to append to the image name:--RawFinOverlayCy5
    Select file format to use:jpeg
    Output file location:Elsewhere...\x7C/g/gavin/projects/Liposome_screen/www/\\g<runPath>--cellprofiler/\\g<wellPath>
    Image bit depth:8
    Overwrite existing files without warning?:Yes
    Select how often to save:Every cycle
    Rescale the images? :Yes
    Save as grayscale or color image?:Grayscale
    Select colormap:gray
    Store file and path information to the saved image?:No
    Create subfolders in the output folder?:No

SaveImages:[module_num:201|svn_version:\'11042\'|variable_revision_number:7|show_window:False|notes:\x5B\x5D]
    Select the type of image to save:Image
    Select the image to save:protein_3ms_300ms_tophat_noSatu_membrane
    Select the objects to save:None
    Select the module display window to save:None
    Select method for constructing file names:From image filename
    Select image name for file prefix:protein_raw_300ms
    Enter single file name:OrigBlue
    Do you want to add a suffix to the image file name?:Yes
    Text to append to the image name:--membraneGFP
    Select file format to use:jpeg
    Output file location:Elsewhere...\x7C/g/gavin/projects/Liposome_screen/www/\\g<runPath>--cellprofiler/\\g<wellPath>
    Image bit depth:8
    Overwrite existing files without warning?:Yes
    Select how often to save:Every cycle
    Rescale the images? :Yes
    Save as grayscale or color image?:Grayscale
    Select colormap:gray
    Store file and path information to the saved image?:No
    Create subfolders in the output folder?:No

SaveImages:[module_num:202|svn_version:\'11042\'|variable_revision_number:7|show_window:False|notes:\x5B\x5D]
    Select the type of image to save:Image
    Select the image to save:protein_3ms_300ms_rawVSfinalOutput
    Select the objects to save:None
    Select the module display window to save:None
    Select method for constructing file names:From image filename
    Select image name for file prefix:protein_raw_300ms
    Enter single file name:OrigBlue
    Do you want to add a suffix to the image file name?:Yes
    Text to append to the image name:--RawFinOverlayGFP
    Select file format to use:jpeg
    Output file location:Elsewhere...\x7C/g/gavin/projects/Liposome_screen/www/\\g<runPath>--cellprofiler/\\g<wellPath>
    Image bit depth:8
    Overwrite existing files without warning?:Yes
    Select how often to save:Every cycle
    Rescale the images? :Yes
    Save as grayscale or color image?:Grayscale
    Select colormap:gray
    Store file and path information to the saved image?:No
    Create subfolders in the output folder?:No

SaveImages:[module_num:203|svn_version:\'11042\'|variable_revision_number:7|show_window:False|notes:\x5B\x5D]
    Select the type of image to save:Image
    Select the image to save:lipid_3ms_300ms_rawVSfinalOutput
    Select the objects to save:None
    Select the module display window to save:None
    Select method for constructing file names:From image filename
    Select image name for file prefix:protein_raw_300ms
    Enter single file name:OrigBlue
    Do you want to add a suffix to the image file name?:Yes
    Text to append to the image name:--RawFinOverlayCy5
    Select file format to use:jpeg
    Output file location:Elsewhere...\x7C/g/gavin/projects/Liposome_screen/www/\\g<runPath>--cellprofiler/\\g<wellPath>
    Image bit depth:8
    Overwrite existing files without warning?:Yes
    Select how often to save:Every cycle
    Rescale the images? :Yes
    Save as grayscale or color image?:Grayscale
    Select colormap:gray
    Store file and path information to the saved image?:No
    Create subfolders in the output folder?:No

SaveImages:[module_num:204|svn_version:\'11042\'|variable_revision_number:7|show_window:False|notes:\x5B\x5D]
    Select the type of image to save:Image
    Select the image to save:protein_3ms_1000ms_tophat_noSatu_membrane
    Select the objects to save:None
    Select the module display window to save:None
    Select method for constructing file names:From image filename
    Select image name for file prefix:protein_raw_1000ms
    Enter single file name:OrigBlue
    Do you want to add a suffix to the image file name?:Yes
    Text to append to the image name:--membraneGFP
    Select file format to use:jpeg
    Output file location:Elsewhere...\x7C/g/gavin/projects/Liposome_screen/www/\\g<runPath>--cellprofiler/\\g<wellPath>
    Image bit depth:8
    Overwrite existing files without warning?:Yes
    Select how often to save:Every cycle
    Rescale the images? :Yes
    Save as grayscale or color image?:Grayscale
    Select colormap:gray
    Store file and path information to the saved image?:No
    Create subfolders in the output folder?:No

SaveImages:[module_num:205|svn_version:\'11042\'|variable_revision_number:7|show_window:False|notes:\x5B\x5D]
    Select the type of image to save:Image
    Select the image to save:protein_3ms_1000ms_rawVSfinalOutput
    Select the objects to save:None
    Select the module display window to save:None
    Select method for constructing file names:From image filename
    Select image name for file prefix:protein_raw_1000ms
    Enter single file name:OrigBlue
    Do you want to add a suffix to the image file name?:Yes
    Text to append to the image name:--RawFinOverlayGFP
    Select file format to use:jpeg
    Output file location:Elsewhere...\x7C/g/gavin/projects/Liposome_screen/www/\\g<runPath>--cellprofiler/\\g<wellPath>
    Image bit depth:8
    Overwrite existing files without warning?:Yes
    Select how often to save:Every cycle
    Rescale the images? :Yes
    Save as grayscale or color image?:Grayscale
    Select colormap:gray
    Store file and path information to the saved image?:No
    Create subfolders in the output folder?:No

SaveImages:[module_num:206|svn_version:\'11042\'|variable_revision_number:7|show_window:False|notes:\x5B\x5D]
    Select the type of image to save:Image
    Select the image to save:lipid_3ms_1000ms_rawVSfinalOutput
    Select the objects to save:None
    Select the module display window to save:None
    Select method for constructing file names:From image filename
    Select image name for file prefix:protein_raw_1000ms
    Enter single file name:OrigBlue
    Do you want to add a suffix to the image file name?:Yes
    Text to append to the image name:--RawFinOverlayCy5
    Select file format to use:jpeg
    Output file location:Elsewhere...\x7C/g/gavin/projects/Liposome_screen/www/\\g<runPath>--cellprofiler/\\g<wellPath>
    Image bit depth:8
    Overwrite existing files without warning?:Yes
    Select how often to save:Every cycle
    Rescale the images? :Yes
    Save as grayscale or color image?:Grayscale
    Select colormap:gray
    Store file and path information to the saved image?:No
    Create subfolders in the output folder?:No

SaveImages:[module_num:207|svn_version:\'11042\'|variable_revision_number:7|show_window:False|notes:\x5B\x5D]
    Select the type of image to save:Image
    Select the image to save:protein_3ms_2000ms_tophat_noSatu_membrane
    Select the objects to save:None
    Select the module display window to save:None
    Select method for constructing file names:From image filename
    Select image name for file prefix:protein_raw_2000ms
    Enter single file name:OrigBlue
    Do you want to add a suffix to the image file name?:Yes
    Text to append to the image name:--membraneGFP
    Select file format to use:jpeg
    Output file location:Elsewhere...\x7C/g/gavin/projects/Liposome_screen/www/\\g<runPath>--cellprofiler/\\g<wellPath>
    Image bit depth:8
    Overwrite existing files without warning?:Yes
    Select how often to save:Every cycle
    Rescale the images? :Yes
    Save as grayscale or color image?:Grayscale
    Select colormap:gray
    Store file and path information to the saved image?:No
    Create subfolders in the output folder?:No

SaveImages:[module_num:208|svn_version:\'11042\'|variable_revision_number:7|show_window:False|notes:\x5B\x5D]
    Select the type of image to save:Image
    Select the image to save:protein_3ms_2000ms_rawVSfinalOutput
    Select the objects to save:None
    Select the module display window to save:None
    Select method for constructing file names:From image filename
    Select image name for file prefix:protein_raw_2000ms
    Enter single file name:OrigBlue
    Do you want to add a suffix to the image file name?:Yes
    Text to append to the image name:--RawFinOverlayGFP
    Select file format to use:jpeg
    Output file location:Elsewhere...\x7C/g/gavin/projects/Liposome_screen/www/\\g<runPath>--cellprofiler/\\g<wellPath>
    Image bit depth:8
    Overwrite existing files without warning?:Yes
    Select how often to save:Every cycle
    Rescale the images? :Yes
    Save as grayscale or color image?:Grayscale
    Select colormap:gray
    Store file and path information to the saved image?:No
    Create subfolders in the output folder?:No

SaveImages:[module_num:209|svn_version:\'11042\'|variable_revision_number:7|show_window:False|notes:\x5B\x5D]
    Select the type of image to save:Image
    Select the image to save:lipid_3ms_2000ms_rawVSfinalOutput
    Select the objects to save:None
    Select the module display window to save:None
    Select method for constructing file names:From image filename
    Select image name for file prefix:protein_raw_2000ms
    Enter single file name:OrigBlue
    Do you want to add a suffix to the image file name?:Yes
    Text to append to the image name:--RawFinOverlayCy5
    Select file format to use:jpeg
    Output file location:Elsewhere...\x7C/g/gavin/projects/Liposome_screen/www/\\g<runPath>--cellprofiler/\\g<wellPath>
    Image bit depth:8
    Overwrite existing files without warning?:Yes
    Select how often to save:Every cycle
    Rescale the images? :Yes
    Save as grayscale or color image?:Grayscale
    Select colormap:gray
    Store file and path information to the saved image?:No
    Create subfolders in the output folder?:No

SaveImages:[module_num:210|svn_version:\'11042\'|variable_revision_number:7|show_window:False|notes:\x5B\x5D]
    Select the type of image to save:Image
    Select the image to save:protein_3ms_4000ms_tophat_noSatu_membrane
    Select the objects to save:None
    Select the module display window to save:None
    Select method for constructing file names:From image filename
    Select image name for file prefix:protein_raw_4000ms
    Enter single file name:OrigBlue
    Do you want to add a suffix to the image file name?:Yes
    Text to append to the image name:--membraneGFP
    Select file format to use:jpeg
    Output file location:Elsewhere...\x7C/g/gavin/projects/Liposome_screen/www/\\g<runPath>--cellprofiler/\\g<wellPath>
    Image bit depth:8
    Overwrite existing files without warning?:Yes
    Select how often to save:Every cycle
    Rescale the images? :Yes
    Save as grayscale or color image?:Grayscale
    Select colormap:gray
    Store file and path information to the saved image?:No
    Create subfolders in the output folder?:No

SaveImages:[module_num:211|svn_version:\'11042\'|variable_revision_number:7|show_window:False|notes:\x5B\x5D]
    Select the type of image to save:Image
    Select the image to save:protein_3ms_4000ms_rawVSfinalOutput
    Select the objects to save:None
    Select the module display window to save:None
    Select method for constructing file names:From image filename
    Select image name for file prefix:protein_raw_4000ms
    Enter single file name:OrigBlue
    Do you want to add a suffix to the image file name?:Yes
    Text to append to the image name:--RawFinOverlayGFP
    Select file format to use:jpeg
    Output file location:Elsewhere...\x7C/g/gavin/projects/Liposome_screen/www/\\g<runPath>--cellprofiler/\\g<wellPath>
    Image bit depth:8
    Overwrite existing files without warning?:Yes
    Select how often to save:Every cycle
    Rescale the images? :Yes
    Save as grayscale or color image?:Grayscale
    Select colormap:gray
    Store file and path information to the saved image?:No
    Create subfolders in the output folder?:No

SaveImages:[module_num:212|svn_version:\'11042\'|variable_revision_number:7|show_window:False|notes:\x5B\x5D]
    Select the type of image to save:Image
    Select the image to save:lipid_3ms_4000ms_rawVSfinalOutput
    Select the objects to save:None
    Select the module display window to save:None
    Select method for constructing file names:From image filename
    Select image name for file prefix:protein_raw_4000ms
    Enter single file name:OrigBlue
    Do you want to add a suffix to the image file name?:Yes
    Text to append to the image name:--RawFinOverlayCy5
    Select file format to use:jpeg
    Output file location:Elsewhere...\x7C/g/gavin/projects/Liposome_screen/www/\\g<runPath>--cellprofiler/\\g<wellPath>
    Image bit depth:8
    Overwrite existing files without warning?:Yes
    Select how often to save:Every cycle
    Rescale the images? :Yes
    Save as grayscale or color image?:Grayscale
    Select colormap:gray
    Store file and path information to the saved image?:No
    Create subfolders in the output folder?:No

SaveImages:[module_num:213|svn_version:\'11042\'|variable_revision_number:7|show_window:False|notes:\x5B\x5D]
    Select the type of image to save:Image
    Select the image to save:lipid_3ms
    Select the objects to save:None
    Select the module display window to save:None
    Select method for constructing file names:From image filename
    Select image name for file prefix:lipid_raw_3ms
    Enter single file name:OrigBlue
    Do you want to add a suffix to the image file name?:Yes
    Text to append to the image name:--rawimage
    Select file format to use:jpeg
    Output file location:Elsewhere...\x7C/g/gavin/projects/Liposome_screen/www/\\g<runPath>--cellprofiler/\\g<wellPath>
    Image bit depth:8
    Overwrite existing files without warning?:Yes
    Select how often to save:Every cycle
    Rescale the images? :Yes
    Save as grayscale or color image?:Grayscale
    Select colormap:gray
    Store file and path information to the saved image?:Yes
    Create subfolders in the output folder?:No

SaveImages:[module_num:214|svn_version:\'11042\'|variable_revision_number:7|show_window:False|notes:\x5B\x5D]
    Select the type of image to save:Image
    Select the image to save:lipid_3ms_maskOverlay
    Select the objects to save:None
    Select the module display window to save:None
    Select method for constructing file names:From image filename
    Select image name for file prefix:lipid_raw_3ms
    Enter single file name:OrigBlue
    Do you want to add a suffix to the image file name?:Yes
    Text to append to the image name:--overlay
    Select file format to use:jpeg
    Output file location:Elsewhere...\x7C/g/gavin/projects/Liposome_screen/www/\\g<runPath>--cellprofiler/\\g<wellPath>
    Image bit depth:8
    Overwrite existing files without warning?:Yes
    Select how often to save:Every cycle
    Rescale the images? :Yes
    Save as grayscale or color image?:Grayscale
    Select colormap:gray
    Store file and path information to the saved image?:Yes
    Create subfolders in the output folder?:No

SaveImages:[module_num:215|svn_version:\'11042\'|variable_revision_number:7|show_window:False|notes:\x5B\x5D]
    Select the type of image to save:Image
    Select the image to save:lipid_3ms_maskOverlay_withLiposCenters
    Select the objects to save:None
    Select the module display window to save:None
    Select method for constructing file names:From image filename
    Select image name for file prefix:lipid_raw_3ms
    Enter single file name:OrigBlue
    Do you want to add a suffix to the image file name?:Yes
    Text to append to the image name:--overlayWithCenters
    Select file format to use:jpeg
    Output file location:Elsewhere...\x7C/g/gavin/projects/Liposome_screen/www/\\g<runPath>--cellprofiler/\\g<wellPath>
    Image bit depth:8
    Overwrite existing files without warning?:Yes
    Select how often to save:Every cycle
    Rescale the images? :Yes
    Save as grayscale or color image?:Grayscale
    Select colormap:gray
    Store file and path information to the saved image?:Yes
    Create subfolders in the output folder?:No

SaveImages:[module_num:216|svn_version:\'11042\'|variable_revision_number:7|show_window:False|notes:\x5B\x5D]
    Select the type of image to save:Image
    Select the image to save:lipid_3ms_liposomCenter
    Select the objects to save:None
    Select the module display window to save:None
    Select method for constructing file names:From image filename
    Select image name for file prefix:lipid_raw_3ms
    Enter single file name:OrigBlue
    Do you want to add a suffix to the image file name?:Yes
    Text to append to the image name:--liposomeCenters
    Select file format to use:jpeg
    Output file location:Elsewhere...\x7C/g/gavin/projects/Liposome_screen/www/\\g<runPath>--cellprofiler/\\g<wellPath>
    Image bit depth:8
    Overwrite existing files without warning?:Yes
    Select how often to save:Every cycle
    Rescale the images? :Yes
    Save as grayscale or color image?:Grayscale
    Select colormap:gray
    Store file and path information to the saved image?:Yes
    Create subfolders in the output folder?:No

SaveImages:[module_num:217|svn_version:\'11042\'|variable_revision_number:7|show_window:False|notes:\x5B\x5D]
    Select the type of image to save:Image
    Select the image to save:protein_1ms
    Select the objects to save:None
    Select the module display window to save:None
    Select method for constructing file names:From image filename
    Select image name for file prefix:protein_raw_1ms
    Enter single file name:OrigBlue
    Do you want to add a suffix to the image file name?:Yes
    Text to append to the image name:--rawimage
    Select file format to use:jpeg
    Output file location:Elsewhere...\x7C/g/gavin/projects/Liposome_screen/www/\\g<runPath>--cellprofiler/\\g<wellPath>
    Image bit depth:8
    Overwrite existing files without warning?:Yes
    Select how often to save:Every cycle
    Rescale the images? :Yes
    Save as grayscale or color image?:Grayscale
    Select colormap:gray
    Store file and path information to the saved image?:No
    Create subfolders in the output folder?:No

SaveImages:[module_num:218|svn_version:\'11042\'|variable_revision_number:7|show_window:False|notes:\x5B\x5D]
    Select the type of image to save:Image
    Select the image to save:protein_5ms
    Select the objects to save:None
    Select the module display window to save:None
    Select method for constructing file names:From image filename
    Select image name for file prefix:protein_raw_5ms
    Enter single file name:OrigBlue
    Do you want to add a suffix to the image file name?:Yes
    Text to append to the image name:--rawimage
    Select file format to use:jpeg
    Output file location:Elsewhere...\x7C/g/gavin/projects/Liposome_screen/www/\\g<runPath>--cellprofiler/\\g<wellPath>
    Image bit depth:8
    Overwrite existing files without warning?:Yes
    Select how often to save:Every cycle
    Rescale the images? :Yes
    Save as grayscale or color image?:Grayscale
    Select colormap:gray
    Store file and path information to the saved image?:No
    Create subfolders in the output folder?:No

SaveImages:[module_num:219|svn_version:\'11042\'|variable_revision_number:7|show_window:False|notes:\x5B\x5D]
    Select the type of image to save:Image
    Select the image to save:protein_10ms
    Select the objects to save:None
    Select the module display window to save:None
    Select method for constructing file names:From image filename
    Select image name for file prefix:protein_raw_10ms
    Enter single file name:OrigBlue
    Do you want to add a suffix to the image file name?:Yes
    Text to append to the image name:--rawimage
    Select file format to use:jpeg
    Output file location:Elsewhere...\x7C/g/gavin/projects/Liposome_screen/www/\\g<runPath>--cellprofiler/\\g<wellPath>
    Image bit depth:8
    Overwrite existing files without warning?:Yes
    Select how often to save:Every cycle
    Rescale the images? :Yes
    Save as grayscale or color image?:Grayscale
    Select colormap:gray
    Store file and path information to the saved image?:No
    Create subfolders in the output folder?:No

SaveImages:[module_num:220|svn_version:\'11042\'|variable_revision_number:7|show_window:False|notes:\x5B\x5D]
    Select the type of image to save:Image
    Select the image to save:protein_30ms
    Select the objects to save:None
    Select the module display window to save:None
    Select method for constructing file names:From image filename
    Select image name for file prefix:protein_raw_30ms
    Enter single file name:OrigBlue
    Do you want to add a suffix to the image file name?:Yes
    Text to append to the image name:--rawimage
    Select file format to use:jpeg
    Output file location:Elsewhere...\x7C/g/gavin/projects/Liposome_screen/www/\\g<runPath>--cellprofiler/\\g<wellPath>
    Image bit depth:8
    Overwrite existing files without warning?:Yes
    Select how often to save:Every cycle
    Rescale the images? :Yes
    Save as grayscale or color image?:Grayscale
    Select colormap:gray
    Store file and path information to the saved image?:No
    Create subfolders in the output folder?:No

SaveImages:[module_num:221|svn_version:\'11042\'|variable_revision_number:7|show_window:False|notes:\x5B\x5D]
    Select the type of image to save:Image
    Select the image to save:protein_50ms
    Select the objects to save:None
    Select the module display window to save:None
    Select method for constructing file names:From image filename
    Select image name for file prefix:protein_raw_50ms
    Enter single file name:OrigBlue
    Do you want to add a suffix to the image file name?:Yes
    Text to append to the image name:--rawimage
    Select file format to use:jpeg
    Output file location:Elsewhere...\x7C/g/gavin/projects/Liposome_screen/www/\\g<runPath>--cellprofiler/\\g<wellPath>
    Image bit depth:8
    Overwrite existing files without warning?:Yes
    Select how often to save:Every cycle
    Rescale the images? :Yes
    Save as grayscale or color image?:Grayscale
    Select colormap:gray
    Store file and path information to the saved image?:No
    Create subfolders in the output folder?:No

SaveImages:[module_num:222|svn_version:\'11042\'|variable_revision_number:7|show_window:False|notes:\x5B\x5D]
    Select the type of image to save:Image
    Select the image to save:protein_75ms
    Select the objects to save:None
    Select the module display window to save:None
    Select method for constructing file names:From image filename
    Select image name for file prefix:protein_raw_75ms
    Enter single file name:OrigBlue
    Do you want to add a suffix to the image file name?:Yes
    Text to append to the image name:--rawimage
    Select file format to use:jpeg
    Output file location:Elsewhere...\x7C/g/gavin/projects/Liposome_screen/www/\\g<runPath>--cellprofiler/\\g<wellPath>
    Image bit depth:8
    Overwrite existing files without warning?:Yes
    Select how often to save:Every cycle
    Rescale the images? :Yes
    Save as grayscale or color image?:Grayscale
    Select colormap:gray
    Store file and path information to the saved image?:No
    Create subfolders in the output folder?:No

SaveImages:[module_num:223|svn_version:\'11042\'|variable_revision_number:7|show_window:False|notes:\x5B\x5D]
    Select the type of image to save:Image
    Select the image to save:protein_100ms
    Select the objects to save:None
    Select the module display window to save:None
    Select method for constructing file names:From image filename
    Select image name for file prefix:protein_raw_100ms
    Enter single file name:OrigBlue
    Do you want to add a suffix to the image file name?:Yes
    Text to append to the image name:--rawimage
    Select file format to use:jpeg
    Output file location:Elsewhere...\x7C/g/gavin/projects/Liposome_screen/www/\\g<runPath>--cellprofiler/\\g<wellPath>
    Image bit depth:8
    Overwrite existing files without warning?:Yes
    Select how often to save:Every cycle
    Rescale the images? :Yes
    Save as grayscale or color image?:Grayscale
    Select colormap:gray
    Store file and path information to the saved image?:No
    Create subfolders in the output folder?:No

SaveImages:[module_num:224|svn_version:\'11042\'|variable_revision_number:7|show_window:False|notes:\x5B\x5D]
    Select the type of image to save:Image
    Select the image to save:protein_200ms
    Select the objects to save:None
    Select the module display window to save:None
    Select method for constructing file names:From image filename
    Select image name for file prefix:protein_raw_200ms
    Enter single file name:OrigBlue
    Do you want to add a suffix to the image file name?:Yes
    Text to append to the image name:--rawimage
    Select file format to use:jpeg
    Output file location:Elsewhere...\x7C/g/gavin/projects/Liposome_screen/www/\\g<runPath>--cellprofiler/\\g<wellPath>
    Image bit depth:8
    Overwrite existing files without warning?:Yes
    Select how often to save:Every cycle
    Rescale the images? :Yes
    Save as grayscale or color image?:Grayscale
    Select colormap:gray
    Store file and path information to the saved image?:No
    Create subfolders in the output folder?:No

SaveImages:[module_num:225|svn_version:\'11042\'|variable_revision_number:7|show_window:False|notes:\x5B\x5D]
    Select the type of image to save:Image
    Select the image to save:protein_300ms
    Select the objects to save:None
    Select the module display window to save:None
    Select method for constructing file names:From image filename
    Select image name for file prefix:protein_raw_300ms
    Enter single file name:OrigBlue
    Do you want to add a suffix to the image file name?:Yes
    Text to append to the image name:--rawimage
    Select file format to use:jpeg
    Output file location:Elsewhere...\x7C/g/gavin/projects/Liposome_screen/www/\\g<runPath>--cellprofiler/\\g<wellPath>
    Image bit depth:8
    Overwrite existing files without warning?:Yes
    Select how often to save:Every cycle
    Rescale the images? :Yes
    Save as grayscale or color image?:Grayscale
    Select colormap:gray
    Store file and path information to the saved image?:No
    Create subfolders in the output folder?:No

SaveImages:[module_num:226|svn_version:\'11042\'|variable_revision_number:7|show_window:False|notes:\x5B\x5D]
    Select the type of image to save:Image
    Select the image to save:protein_1000ms
    Select the objects to save:None
    Select the module display window to save:None
    Select method for constructing file names:From image filename
    Select image name for file prefix:protein_raw_1000ms
    Enter single file name:OrigBlue
    Do you want to add a suffix to the image file name?:Yes
    Text to append to the image name:--rawimage
    Select file format to use:jpeg
    Output file location:Elsewhere...\x7C/g/gavin/projects/Liposome_screen/www/\\g<runPath>--cellprofiler/\\g<wellPath>
    Image bit depth:8
    Overwrite existing files without warning?:Yes
    Select how often to save:Every cycle
    Rescale the images? :Yes
    Save as grayscale or color image?:Grayscale
    Select colormap:gray
    Store file and path information to the saved image?:No
    Create subfolders in the output folder?:No

SaveImages:[module_num:227|svn_version:\'11042\'|variable_revision_number:7|show_window:False|notes:\x5B\x5D]
    Select the type of image to save:Image
    Select the image to save:protein_2000ms
    Select the objects to save:None
    Select the module display window to save:None
    Select method for constructing file names:From image filename
    Select image name for file prefix:protein_raw_2000ms
    Enter single file name:OrigBlue
    Do you want to add a suffix to the image file name?:Yes
    Text to append to the image name:--rawimage
    Select file format to use:jpeg
    Output file location:Elsewhere...\x7C/g/gavin/projects/Liposome_screen/www/\\g<runPath>--cellprofiler/\\g<wellPath>
    Image bit depth:8
    Overwrite existing files without warning?:Yes
    Select how often to save:Every cycle
    Rescale the images? :Yes
    Save as grayscale or color image?:Grayscale
    Select colormap:gray
    Store file and path information to the saved image?:No
    Create subfolders in the output folder?:No

SaveImages:[module_num:228|svn_version:\'11042\'|variable_revision_number:7|show_window:False|notes:\x5B\x5D]
    Select the type of image to save:Image
    Select the image to save:protein_4000ms
    Select the objects to save:None
    Select the module display window to save:None
    Select method for constructing file names:From image filename
    Select image name for file prefix:protein_raw_4000ms
    Enter single file name:OrigBlue
    Do you want to add a suffix to the image file name?:Yes
    Text to append to the image name:--rawimage
    Select file format to use:jpeg
    Output file location:Elsewhere...\x7C/g/gavin/projects/Liposome_screen/www/\\g<runPath>--cellprofiler/\\g<wellPath>
    Image bit depth:8
    Overwrite existing files without warning?:Yes
    Select how often to save:Every cycle
    Rescale the images? :Yes
    Save as grayscale or color image?:Grayscale
    Select colormap:gray
    Store file and path information to the saved image?:No
    Create subfolders in the output folder?:No

SaveImages:[module_num:229|svn_version:\'11042\'|variable_revision_number:7|show_window:False|notes:\x5B\x5D]
    Select the type of image to save:Image
    Select the image to save:mask_membranes
    Select the objects to save:None
    Select the module display window to save:None
    Select method for constructing file names:From image filename
    Select image name for file prefix:lipid_raw_3ms
    Enter single file name:OrigBlue
    Do you want to add a suffix to the image file name?:Yes
    Text to append to the image name:--mask
    Select file format to use:jpeg
    Output file location:Elsewhere...\x7C/g/gavin/projects/Liposome_screen/www/\\g<runPath>--cellprofiler/\\g<wellPath>
    Image bit depth:8
    Overwrite existing files without warning?:Yes
    Select how often to save:Every cycle
    Rescale the images? :Yes
    Save as grayscale or color image?:Grayscale
    Select colormap:gray
    Store file and path information to the saved image?:Yes
    Create subfolders in the output folder?:No

MeasureImageIntensity:[module_num:230|svn_version:\'11025\'|variable_revision_number:2|show_window:False|notes:\x5B\x5D]
    Select the image to measure:lipid_3ms_5ms_tophat_noSatu_membrane
    Measure the intensity only from areas enclosed by objects?:No
    Select the input objects:None
    Select the image to measure:protein_3ms_5ms_tophat_noSatu_membrane
    Measure the intensity only from areas enclosed by objects?:No
    Select the input objects:None
    Select the image to measure:lipid_3ms_10ms_tophat_noSatu_membrane
    Measure the intensity only from areas enclosed by objects?:No
    Select the input objects:None
    Select the image to measure:protein_3ms_10ms_tophat_noSatu_membrane
    Measure the intensity only from areas enclosed by objects?:No
    Select the input objects:None
    Select the image to measure:lipid_3ms_30ms_tophat_noSatu_membrane
    Measure the intensity only from areas enclosed by objects?:No
    Select the input objects:None
    Select the image to measure:protein_3ms_30ms_tophat_noSatu_membrane
    Measure the intensity only from areas enclosed by objects?:No
    Select the input objects:None
    Select the image to measure:lipid_3ms_100ms_tophat_noSatu_membrane
    Measure the intensity only from areas enclosed by objects?:No
    Select the input objects:None
    Select the image to measure:protein_3ms_100ms_tophat_noSatu_membrane
    Measure the intensity only from areas enclosed by objects?:No
    Select the input objects:None
    Select the image to measure:lipid_3ms_1ms_tophat_noSatu_membrane
    Measure the intensity only from areas enclosed by objects?:No
    Select the input objects:None
    Select the image to measure:protein_3ms_1ms_tophat_noSatu_membrane
    Measure the intensity only from areas enclosed by objects?:No
    Select the input objects:None
    Select the image to measure:lipid_3ms_50ms_tophat_noSatu_membrane
    Measure the intensity only from areas enclosed by objects?:No
    Select the input objects:None
    Select the image to measure:protein_3ms_50ms_tophat_noSatu_membrane
    Measure the intensity only from areas enclosed by objects?:No
    Select the input objects:None
    Select the image to measure:lipid_3ms_75ms_tophat_noSatu_membrane
    Measure the intensity only from areas enclosed by objects?:No
    Select the input objects:None
    Select the image to measure:protein_3ms_75ms_tophat_noSatu_membrane
    Measure the intensity only from areas enclosed by objects?:No
    Select the input objects:None
    Select the image to measure:lipid_3ms_200ms_tophat_noSatu_membrane
    Measure the intensity only from areas enclosed by objects?:No
    Select the input objects:None
    Select the image to measure:protein_3ms_200ms_tophat_noSatu_membrane
    Measure the intensity only from areas enclosed by objects?:No
    Select the input objects:None
    Select the image to measure:lipid_3ms_300ms_tophat_noSatu_membrane
    Measure the intensity only from areas enclosed by objects?:No
    Select the input objects:None
    Select the image to measure:protein_3ms_300ms_tophat_noSatu_membrane
    Measure the intensity only from areas enclosed by objects?:No
    Select the input objects:None
    Select the image to measure:lipid_3ms_1000ms_tophat_noSatu_membrane
    Measure the intensity only from areas enclosed by objects?:No
    Select the input objects:None
    Select the image to measure:protein_3ms_1000ms_tophat_noSatu_membrane
    Measure the intensity only from areas enclosed by objects?:No
    Select the input objects:None
    Select the image to measure:lipid_3ms_2000ms_tophat_noSatu_membrane
    Measure the intensity only from areas enclosed by objects?:No
    Select the input objects:None
    Select the image to measure:protein_3ms_2000ms_tophat_noSatu_membrane
    Measure the intensity only from areas enclosed by objects?:No
    Select the input objects:None
    Select the image to measure:lipid_3ms_4000ms_tophat_noSatu_membrane
    Measure the intensity only from areas enclosed by objects?:No
    Select the input objects:None
    Select the image to measure:protein_3ms_4000ms_tophat_noSatu_membrane
    Measure the intensity only from areas enclosed by objects?:No
    Select the input objects:None

CalculateMath:[module_num:231|svn_version:\'11025\'|variable_revision_number:1|show_window:False|notes:\x5B\x5D]
    Name the output measurement:Ratio_3_1
    Operation:Divide
    Select the numerator measurement type:Image
    Select the numerator objects:None
    Select the numerator measurement:Intensity_MeanIntensity_protein_3ms_1ms_tophat_noSatu_membrane
    Multiply the above operand by:1
    Raise the power of above operand by:1
    Select the denominator measurement type:Image
    Select the denominator objects:None
    Select the denominator measurement:Intensity_MeanIntensity_lipid_3ms_1ms_tophat_noSatu_membrane
    Multiply the above operand by:1
    Raise the power of above operand by:1
    Take log10 of result?:No
    Multiply the result by:1
    Raise the power of result by:1

CalculateMath:[module_num:232|svn_version:\'11025\'|variable_revision_number:1|show_window:False|notes:\x5B\x5D]
    Name the output measurement:Ratio_3_5
    Operation:Divide
    Select the numerator measurement type:Image
    Select the numerator objects:None
    Select the numerator measurement:Intensity_MeanIntensity_protein_3ms_5ms_tophat_noSatu_membrane
    Multiply the above operand by:0.2
    Raise the power of above operand by:1
    Select the denominator measurement type:Image
    Select the denominator objects:None
    Select the denominator measurement:Intensity_MeanIntensity_lipid_3ms_5ms_tophat_noSatu_membrane
    Multiply the above operand by:1
    Raise the power of above operand by:1
    Take log10 of result?:No
    Multiply the result by:1
    Raise the power of result by:1

CalculateMath:[module_num:233|svn_version:\'11025\'|variable_revision_number:1|show_window:False|notes:\x5B\x5D]
    Name the output measurement:Ratio_3_10
    Operation:Divide
    Select the numerator measurement type:Image
    Select the numerator objects:None
    Select the numerator measurement:Intensity_MeanIntensity_protein_3ms_10ms_tophat_noSatu_membrane
    Multiply the above operand by:0.1
    Raise the power of above operand by:1
    Select the denominator measurement type:Image
    Select the denominator objects:None
    Select the denominator measurement:Intensity_MeanIntensity_lipid_3ms_10ms_tophat_noSatu_membrane
    Multiply the above operand by:1
    Raise the power of above operand by:1
    Take log10 of result?:No
    Multiply the result by:1
    Raise the power of result by:1

CalculateMath:[module_num:234|svn_version:\'11025\'|variable_revision_number:1|show_window:False|notes:\x5B\x5D]
    Name the output measurement:Ratio_3_30
    Operation:Divide
    Select the numerator measurement type:Image
    Select the numerator objects:None
    Select the numerator measurement:Intensity_MeanIntensity_protein_3ms_30ms_tophat_noSatu_membrane
    Multiply the above operand by:0.03333333333333333333333333
    Raise the power of above operand by:1
    Select the denominator measurement type:Image
    Select the denominator objects:None
    Select the denominator measurement:Intensity_MeanIntensity_lipid_3ms_30ms_tophat_noSatu_membrane
    Multiply the above operand by:1
    Raise the power of above operand by:1
    Take log10 of result?:No
    Multiply the result by:1
    Raise the power of result by:1

CalculateMath:[module_num:235|svn_version:\'11025\'|variable_revision_number:1|show_window:False|notes:\x5B\x5D]
    Name the output measurement:Ratio_3_50
    Operation:Divide
    Select the numerator measurement type:Image
    Select the numerator objects:None
    Select the numerator measurement:Intensity_MeanIntensity_protein_3ms_50ms_tophat_noSatu_membrane
    Multiply the above operand by:0.02
    Raise the power of above operand by:1
    Select the denominator measurement type:Image
    Select the denominator objects:None
    Select the denominator measurement:Intensity_MeanIntensity_lipid_3ms_50ms_tophat_noSatu_membrane
    Multiply the above operand by:1
    Raise the power of above operand by:1
    Take log10 of result?:No
    Multiply the result by:1
    Raise the power of result by:1

CalculateMath:[module_num:236|svn_version:\'11025\'|variable_revision_number:1|show_window:False|notes:\x5B\x5D]
    Name the output measurement:Ratio_3_75
    Operation:Divide
    Select the numerator measurement type:Image
    Select the numerator objects:None
    Select the numerator measurement:Intensity_MeanIntensity_protein_3ms_75ms_tophat_noSatu_membrane
    Multiply the above operand by:0.013333333333333333333333333333333
    Raise the power of above operand by:1
    Select the denominator measurement type:Image
    Select the denominator objects:None
    Select the denominator measurement:Intensity_MeanIntensity_lipid_3ms_75ms_tophat_noSatu_membrane
    Multiply the above operand by:1
    Raise the power of above operand by:1
    Take log10 of result?:No
    Multiply the result by:1
    Raise the power of result by:1

CalculateMath:[module_num:237|svn_version:\'11025\'|variable_revision_number:1|show_window:False|notes:\x5B\x5D]
    Name the output measurement:Ratio_3_100
    Operation:Divide
    Select the numerator measurement type:Image
    Select the numerator objects:None
    Select the numerator measurement:Intensity_MeanIntensity_protein_3ms_100ms_tophat_noSatu_membrane
    Multiply the above operand by:0.01
    Raise the power of above operand by:1
    Select the denominator measurement type:Image
    Select the denominator objects:None
    Select the denominator measurement:Intensity_MeanIntensity_lipid_3ms_100ms_tophat_noSatu_membrane
    Multiply the above operand by:1
    Raise the power of above operand by:1
    Take log10 of result?:No
    Multiply the result by:1
    Raise the power of result by:1

CalculateMath:[module_num:238|svn_version:\'11025\'|variable_revision_number:1|show_window:False|notes:\x5B\x5D]
    Name the output measurement:Ratio_3_200
    Operation:Divide
    Select the numerator measurement type:Image
    Select the numerator objects:None
    Select the numerator measurement:Intensity_MeanIntensity_protein_3ms_200ms_tophat_noSatu_membrane
    Multiply the above operand by:0.005
    Raise the power of above operand by:1
    Select the denominator measurement type:Image
    Select the denominator objects:None
    Select the denominator measurement:Intensity_MeanIntensity_lipid_3ms_200ms_tophat_noSatu_membrane
    Multiply the above operand by:1
    Raise the power of above operand by:1
    Take log10 of result?:No
    Multiply the result by:1
    Raise the power of result by:1

CalculateMath:[module_num:239|svn_version:\'11025\'|variable_revision_number:1|show_window:False|notes:\x5B\x5D]
    Name the output measurement:Ratio_3_300
    Operation:Divide
    Select the numerator measurement type:Image
    Select the numerator objects:None
    Select the numerator measurement:Intensity_MeanIntensity_protein_3ms_300ms_tophat_noSatu_membrane
    Multiply the above operand by:0.003333333333333333333333333
    Raise the power of above operand by:1
    Select the denominator measurement type:Image
    Select the denominator objects:None
    Select the denominator measurement:Intensity_MeanIntensity_lipid_3ms_300ms_tophat_noSatu_membrane
    Multiply the above operand by:1
    Raise the power of above operand by:1
    Take log10 of result?:No
    Multiply the result by:1
    Raise the power of result by:1

CalculateMath:[module_num:240|svn_version:\'11025\'|variable_revision_number:1|show_window:False|notes:\x5B\x5D]
    Name the output measurement:Ratio_3_1000
    Operation:Divide
    Select the numerator measurement type:Image
    Select the numerator objects:None
    Select the numerator measurement:Intensity_MeanIntensity_protein_3ms_1000ms_tophat_noSatu_membrane
    Multiply the above operand by:0.001
    Raise the power of above operand by:1
    Select the denominator measurement type:Image
    Select the denominator objects:None
    Select the denominator measurement:Intensity_MeanIntensity_lipid_3ms_1000ms_tophat_noSatu_membrane
    Multiply the above operand by:1
    Raise the power of above operand by:1
    Take log10 of result?:No
    Multiply the result by:1
    Raise the power of result by:1

CalculateMath:[module_num:241|svn_version:\'11025\'|variable_revision_number:1|show_window:False|notes:\x5B\x5D]
    Name the output measurement:Ratio_3_2000
    Operation:Divide
    Select the numerator measurement type:Image
    Select the numerator objects:None
    Select the numerator measurement:Intensity_MeanIntensity_protein_3ms_2000ms_tophat_noSatu_membrane
    Multiply the above operand by:0.001
    Raise the power of above operand by:1
    Select the denominator measurement type:Image
    Select the denominator objects:None
    Select the denominator measurement:Intensity_MeanIntensity_lipid_3ms_2000ms_tophat_noSatu_membrane
    Multiply the above operand by:1
    Raise the power of above operand by:1
    Take log10 of result?:No
    Multiply the result by:1
    Raise the power of result by:1

CalculateMath:[module_num:242|svn_version:\'11025\'|variable_revision_number:1|show_window:False|notes:\x5B\x5D]
    Name the output measurement:Ratio_3_4000
    Operation:Divide
    Select the numerator measurement type:Image
    Select the numerator objects:None
    Select the numerator measurement:Intensity_MeanIntensity_protein_3ms_4000ms_tophat_noSatu_membrane
    Multiply the above operand by:0.001
    Raise the power of above operand by:1
    Select the denominator measurement type:Image
    Select the denominator objects:None
    Select the denominator measurement:Intensity_MeanIntensity_lipid_3ms_4000ms_tophat_noSatu_membrane
    Multiply the above operand by:1
    Raise the power of above operand by:1
    Take log10 of result?:No
    Multiply the result by:1
    Raise the power of result by:1

ExportToSpreadsheet:[module_num:243|svn_version:\'11042\'|variable_revision_number:7|show_window:False|notes:\x5B\'\'\x5D]
    Select or enter the column delimiter:Comma (",")
    Prepend the output file name to the data file names?:No
    Add image metadata columns to your object data file?:No
    Limit output to a size that is allowed in Excel?:No
    Select the columns of measurements to export?:Yes
    Calculate the per-image mean values for object measurements?:No
    Calculate the per-image median values for object measurements?:No
    Calculate the per-image standard deviation values for object measurements?:No
    Output file location:Elsewhere...\x7C\\g<rootPath>/\\g<runPath>--cellprofiler/\\g<wellPath>
    Create a GenePattern GCT file?:No
    Select source of sample row name:Metadata
    Select the image to use as the identifier:None
    Select the metadata to use as the identifier:None
    Export all measurements, using default file names?:No
    Press button to select measurements to export:Image\x7CCount_boundaries,Image\x7CCount_liposomes,Image\x7CCount_membranes,Image\x7CCount_liposomeCenters,Image\x7CImageQuality_TotalIntensity_protein_raw_75ms,Image\x7CImageQuality_TotalIntensity_protein_raw_1000ms,Image\x7CImageQuality_TotalIntensity_protein_raw_100ms,Image\x7CImageQuality_TotalIntensity_protein_raw_5ms,Image\x7CImageQuality_TotalIntensity_protein_raw_1ms,Image\x7CImageQuality_TotalIntensity_protein_raw_200ms,Image\x7CImageQuality_TotalIntensity_protein_raw_300ms,Image\x7CImageQuality_TotalIntensity_protein_raw_30ms,Image\x7CImageQuality_TotalIntensity_protein_raw_50ms,Image\x7CImageQuality_TotalIntensity_protein_raw_10ms,Image\x7CImageQuality_TotalIntensity_lipid_raw_3ms,Image\x7CImageQuality_TotalArea_protein_raw_75ms,Image\x7CImageQuality_TotalArea_protein_raw_1000ms,Image\x7CImageQuality_TotalArea_protein_raw_100ms,Image\x7CImageQuality_TotalArea_protein_raw_5ms,Image\x7CImageQuality_TotalArea_protein_raw_1ms,Image\x7CImageQuality_TotalArea_protein_raw_200ms,Image\x7CImageQuality_TotalArea_protein_raw_300ms,Image\x7CImageQuality_TotalArea_protein_raw_30ms,Image\x7CImageQuality_TotalArea_protein_raw_50ms,Image\x7CImageQuality_TotalArea_protein_raw_10ms,Image\x7CImageQuality_TotalArea_lipid_raw_3ms,Image\x7CImageQuality_MeanIntensity_protein_raw_75ms,Image\x7CImageQuality_MeanIntensity_protein_raw_1000ms,Image\x7CImageQuality_MeanIntensity_protein_raw_100ms,Image\x7CImageQuality_MeanIntensity_protein_raw_5ms,Image\x7CImageQuality_MeanIntensity_protein_raw_1ms,Image\x7CImageQuality_MeanIntensity_protein_raw_200ms,Image\x7CImageQuality_MeanIntensity_protein_raw_300ms,Image\x7CImageQuality_MeanIntensity_protein_raw_30ms,Image\x7CImageQuality_MeanIntensity_protein_raw_50ms,Image\x7CImageQuality_MeanIntensity_protein_raw_10ms,Image\x7CImageQuality_MeanIntensity_lipid_raw_3ms,Image\x7CImageQuality_PercentMaximal_protein_raw_75ms,Image\x7CImageQuality_PercentMaximal_protein_raw_1000ms,Image\x7CImageQuality_PercentMaximal_protein_raw_100ms,Image\x7CImageQuality_PercentMaximal_protein_raw_5ms,Image\x7CImageQuality_PercentMaximal_protein_raw_1ms,Image\x7CImageQuality_PercentMaximal_protein_raw_200ms,Image\x7CImageQuality_PercentMaximal_protein_raw_300ms,Image\x7CImageQuality_PercentMaximal_protein_raw_30ms,Image\x7CImageQuality_PercentMaximal_protein_raw_50ms,Image\x7CImageQuality_PercentMaximal_protein_raw_10ms,Image\x7CImageQuality_PercentMaximal_lipid_raw_3ms,Image\x7CFileName_mask_membranes,Image\x7CFileName_protein_raw_75ms,Image\x7CFileName_protein_raw_1000ms,Image\x7CFileName_protein_raw_100ms,Image\x7CFileName_protein_raw_5ms,Image\x7CFileName_protein_raw_1ms,Image\x7CFileName_protein_raw_200ms,Image\x7CFileName_protein_raw_300ms,Image\x7CFileName_protein_raw_30ms,Image\x7CFileName_protein_raw_50ms,Image\x7CFileName_protein_raw_10ms,Image\x7CFileName_lipid_raw_3ms,Image\x7CFileName_lipid_3ms_liposomCenter,Image\x7CIntensity_StdIntensity_protein_75ms_saturated,Image\x7CIntensity_StdIntensity_protein_1000ms_saturated,Image\x7CIntensity_StdIntensity_protein_100ms_saturated,Image\x7CIntensity_StdIntensity_protein_5ms_saturated,Image\x7CIntensity_StdIntensity_protein_3ms_75ms_tophat_noSatu_membrane,Image\x7CIntensity_StdIntensity_protein_3ms_1000ms_tophat_noSatu_membrane,Image\x7CIntensity_StdIntensity_protein_3ms_100ms_tophat_noSatu_membrane,Image\x7CIntensity_StdIntensity_protein_3ms_5ms_tophat_noSatu_membrane,Image\x7CIntensity_StdIntensity_protein_3ms_1ms_tophat_noSatu_membrane,Image\x7CIntensity_StdIntensity_protein_3ms_50ms_tophat_noSatu_membrane,Image\x7CIntensity_StdIntensity_protein_3ms_300ms_tophat_noSatu_membrane,Image\x7CIntensity_StdIntensity_protein_3ms_30ms_tophat_noSatu_membrane,Image\x7CIntensity_StdIntensity_protein_3ms_200ms_tophat_noSatu_membrane,Image\x7CIntensity_StdIntensity_protein_3ms_10ms_tophat_noSatu_membrane,Image\x7CIntensity_StdIntensity_protein_1ms_saturated,Image\x7CIntensity_StdIntensity_protein_50ms_saturated,Image\x7CIntensity_StdIntensity_protein_300ms_saturated,Image\x7CIntensity_StdIntensity_protein_30ms_saturated,Image\x7CIntensity_StdIntensity_protein_200ms_saturated,Image\x7CIntensity_StdIntensity_protein_10ms_saturated,Image\x7CIntensity_StdIntensity_lipid_3ms_75ms_tophat_noSatu_membrane,Image\x7CIntensity_StdIntensity_lipid_3ms_1000ms_tophat_noSatu_membrane,Image\x7CIntensity_StdIntensity_lipid_3ms_saturated,Image\x7CIntensity_StdIntensity_lipid_3ms_5ms_tophat_noSatu_membrane,Image\x7CIntensity_StdIntensity_lipid_3ms_1ms_tophat_noSatu_membrane,Image\x7CIntensity_StdIntensity_lipid_3ms_50ms_tophat_noSatu_membrane,Image\x7CIntensity_StdIntensity_lipid_3ms_300ms_tophat_noSatu_membrane,Image\x7CIntensity_StdIntensity_lipid_3ms_30ms_tophat_noSatu_membrane,Image\x7CIntensity_StdIntensity_lipid_3ms_200ms_tophat_noSatu_membrane,Image\x7CIntensity_StdIntensity_lipid_3ms_100ms_tophat_noSatu_membrane,Image\x7CIntensity_StdIntensity_lipid_3ms_10ms_tophat_noSatu_membrane,Image\x7CIntensity_TotalIntensity_protein_75ms_saturated,Image\x7CIntensity_TotalIntensity_protein_1000ms_saturated,Image\x7CIntensity_TotalIntensity_protein_100ms_saturated,Image\x7CIntensity_TotalIntensity_protein_5ms_saturated,Image\x7CIntensity_TotalIntensity_protein_3ms_75ms_tophat_noSatu_membrane,Image\x7CIntensity_TotalIntensity_protein_3ms_1000ms_tophat_noSatu_membrane,Image\x7CIntensity_TotalIntensity_protein_3ms_100ms_tophat_noSatu_membrane,Image\x7CIntensity_TotalIntensity_protein_3ms_5ms_tophat_noSatu_membrane,Image\x7CIntensity_TotalIntensity_protein_3ms_1ms_tophat_noSatu_membrane,Image\x7CIntensity_TotalIntensity_protein_3ms_50ms_tophat_noSatu_membrane,Image\x7CIntensity_TotalIntensity_protein_3ms_300ms_tophat_noSatu_membrane,Image\x7CIntensity_TotalIntensity_protein_3ms_30ms_tophat_noSatu_membrane,Image\x7CIntensity_TotalIntensity_protein_3ms_200ms_tophat_noSatu_membrane,Image\x7CIntensity_TotalIntensity_protein_3ms_10ms_tophat_noSatu_membrane,Image\x7CIntensity_TotalIntensity_protein_1ms_saturated,Image\x7CIntensity_TotalIntensity_protein_50ms_saturated,Image\x7CIntensity_TotalIntensity_protein_300ms_saturated,Image\x7CIntensity_TotalIntensity_protein_30ms_saturated,Image\x7CIntensity_TotalIntensity_protein_200ms_saturated,Image\x7CIntensity_TotalIntensity_protein_10ms_saturated,Image\x7CIntensity_TotalIntensity_lipid_3ms_75ms_tophat_noSatu_membrane,Image\x7CIntensity_TotalIntensity_lipid_3ms_1000ms_tophat_noSatu_membrane,Image\x7CIntensity_TotalIntensity_lipid_3ms_saturated,Image\x7CIntensity_TotalIntensity_lipid_3ms_5ms_tophat_noSatu_membrane,Image\x7CIntensity_TotalIntensity_lipid_3ms_1ms_tophat_noSatu_membrane,Image\x7CIntensity_TotalIntensity_lipid_3ms_50ms_tophat_noSatu_membrane,Image\x7CIntensity_TotalIntensity_lipid_3ms_300ms_tophat_noSatu_membrane,Image\x7CIntensity_TotalIntensity_lipid_3ms_30ms_tophat_noSatu_membrane,Image\x7CIntensity_TotalIntensity_lipid_3ms_200ms_tophat_noSatu_membrane,Image\x7CIntensity_TotalIntensity_lipid_3ms_100ms_tophat_noSatu_membrane,Image\x7CIntensity_TotalIntensity_lipid_3ms_10ms_tophat_noSatu_membrane,Image\x7CIntensity_TotalArea_protein_75ms_saturated,Image\x7CIntensity_TotalArea_protein_1000ms_saturated,Image\x7CIntensity_TotalArea_protein_100ms_saturated,Image\x7CIntensity_TotalArea_protein_5ms_saturated,Image\x7CIntensity_TotalArea_protein_3ms_75ms_tophat_noSatu_membrane,Image\x7CIntensity_TotalArea_protein_3ms_1000ms_tophat_noSatu_membrane,Image\x7CIntensity_TotalArea_protein_3ms_100ms_tophat_noSatu_membrane,Image\x7CIntensity_TotalArea_protein_3ms_5ms_tophat_noSatu_membrane,Image\x7CIntensity_TotalArea_protein_3ms_1ms_tophat_noSatu_membrane,Image\x7CIntensity_TotalArea_protein_3ms_50ms_tophat_noSatu_membrane,Image\x7CIntensity_TotalArea_protein_3ms_300ms_tophat_noSatu_membrane,Image\x7CIntensity_TotalArea_protein_3ms_30ms_tophat_noSatu_membrane,Image\x7CIntensity_TotalArea_protein_3ms_200ms_tophat_noSatu_membrane,Image\x7CIntensity_TotalArea_protein_3ms_10ms_tophat_noSatu_membrane,Image\x7CIntensity_TotalArea_protein_1ms_saturated,Image\x7CIntensity_TotalArea_protein_50ms_saturated,Image\x7CIntensity_TotalArea_protein_300ms_saturated,Image\x7CIntensity_TotalArea_protein_30ms_saturated,Image\x7CIntensity_TotalArea_protein_200ms_saturated,Image\x7CIntensity_TotalArea_protein_10ms_saturated,Image\x7CIntensity_TotalArea_lipid_3ms_75ms_tophat_noSatu_membrane,Image\x7CIntensity_TotalArea_lipid_3ms_1000ms_tophat_noSatu_membrane,Image\x7CIntensity_TotalArea_lipid_3ms_saturated,Image\x7CIntensity_TotalArea_lipid_3ms_5ms_tophat_noSatu_membrane,Image\x7CIntensity_TotalArea_lipid_3ms_1ms_tophat_noSatu_membrane,Image\x7CIntensity_TotalArea_lipid_3ms_50ms_tophat_noSatu_membrane,Image\x7CIntensity_TotalArea_lipid_3ms_300ms_tophat_noSatu_membrane,Image\x7CIntensity_TotalArea_lipid_3ms_30ms_tophat_noSatu_membrane,Image\x7CIntensity_TotalArea_lipid_3ms_200ms_tophat_noSatu_membrane,Image\x7CIntensity_TotalArea_lipid_3ms_100ms_tophat_noSatu_membrane,Image\x7CIntensity_TotalArea_lipid_3ms_10ms_tophat_noSatu_membrane,Image\x7CIntensity_MADIntensity_protein_75ms_saturated,Image\x7CIntensity_MADIntensity_protein_1000ms_saturated,Image\x7CIntensity_MADIntensity_protein_100ms_saturated,Image\x7CIntensity_MADIntensity_protein_5ms_saturated,Image\x7CIntensity_MADIntensity_protein_3ms_75ms_tophat_noSatu_membrane,Image\x7CIntensity_MADIntensity_protein_3ms_1000ms_tophat_noSatu_membrane,Image\x7CIntensity_MADIntensity_protein_3ms_100ms_tophat_noSatu_membrane,Image\x7CIntensity_MADIntensity_protein_3ms_5ms_tophat_noSatu_membrane,Image\x7CIntensity_MADIntensity_protein_3ms_1ms_tophat_noSatu_membrane,Image\x7CIntensity_MADIntensity_protein_3ms_50ms_tophat_noSatu_membrane,Image\x7CIntensity_MADIntensity_protein_3ms_300ms_tophat_noSatu_membrane,Image\x7CIntensity_MADIntensity_protein_3ms_30ms_tophat_noSatu_membrane,Image\x7CIntensity_MADIntensity_protein_3ms_200ms_tophat_noSatu_membrane,Image\x7CIntensity_MADIntensity_protein_3ms_10ms_tophat_noSatu_membrane,Image\x7CIntensity_MADIntensity_protein_1ms_saturated,Image\x7CIntensity_MADIntensity_protein_50ms_saturated,Image\x7CIntensity_MADIntensity_protein_300ms_saturated,Image\x7CIntensity_MADIntensity_protein_30ms_saturated,Image\x7CIntensity_MADIntensity_protein_200ms_saturated,Image\x7CIntensity_MADIntensity_protein_10ms_saturated,Image\x7CIntensity_MADIntensity_lipid_3ms_75ms_tophat_noSatu_membrane,Image\x7CIntensity_MADIntensity_lipid_3ms_1000ms_tophat_noSatu_membrane,Image\x7CIntensity_MADIntensity_lipid_3ms_saturated,Image\x7CIntensity_MADIntensity_lipid_3ms_5ms_tophat_noSatu_membrane,Image\x7CIntensity_MADIntensity_lipid_3ms_1ms_tophat_noSatu_membrane,Image\x7CIntensity_MADIntensity_lipid_3ms_50ms_tophat_noSatu_membrane,Image\x7CIntensity_MADIntensity_lipid_3ms_300ms_tophat_noSatu_membrane,Image\x7CIntensity_MADIntensity_lipid_3ms_30ms_tophat_noSatu_membrane,Image\x7CIntensity_MADIntensity_lipid_3ms_200ms_tophat_noSatu_membrane,Image\x7CIntensity_MADIntensity_lipid_3ms_100ms_tophat_noSatu_membrane,Image\x7CIntensity_MADIntensity_lipid_3ms_10ms_tophat_noSatu_membrane,Image\x7CIntensity_MeanIntensity_protein_75ms_saturated,Image\x7CIntensity_MeanIntensity_protein_1000ms_saturated,Image\x7CIntensity_MeanIntensity_protein_100ms_saturated,Image\x7CIntensity_MeanIntensity_protein_5ms_saturated,Image\x7CIntensity_MeanIntensity_protein_3ms_75ms_tophat_noSatu_membrane,Image\x7CIntensity_MeanIntensity_protein_3ms_1000ms_tophat_noSatu_membrane,Image\x7CIntensity_MeanIntensity_protein_3ms_100ms_tophat_noSatu_membrane,Image\x7CIntensity_MeanIntensity_protein_3ms_5ms_tophat_noSatu_membrane,Image\x7CIntensity_MeanIntensity_protein_3ms_1ms_tophat_noSatu_membrane,Image\x7CIntensity_MeanIntensity_protein_3ms_50ms_tophat_noSatu_membrane,Image\x7CIntensity_MeanIntensity_protein_3ms_300ms_tophat_noSatu_membrane,Image\x7CIntensity_MeanIntensity_protein_3ms_30ms_tophat_noSatu_membrane,Image\x7CIntensity_MeanIntensity_protein_3ms_200ms_tophat_noSatu_membrane,Image\x7CIntensity_MeanIntensity_protein_3ms_10ms_tophat_noSatu_membrane,Image\x7CIntensity_MeanIntensity_protein_1ms_saturated,Image\x7CIntensity_MeanIntensity_protein_50ms_saturated,Image\x7CIntensity_MeanIntensity_protein_300ms_saturated,Image\x7CIntensity_MeanIntensity_protein_30ms_saturated,Image\x7CIntensity_MeanIntensity_protein_200ms_saturated,Image\x7CIntensity_MeanIntensity_protein_10ms_saturated,Image\x7CIntensity_MeanIntensity_lipid_3ms_75ms_tophat_noSatu_membrane,Image\x7CIntensity_MeanIntensity_lipid_3ms_1000ms_tophat_noSatu_membrane,Image\x7CIntensity_MeanIntensity_lipid_3ms_saturated,Image\x7CIntensity_MeanIntensity_lipid_3ms_5ms_tophat_noSatu_membrane,Image\x7CIntensity_MeanIntensity_lipid_3ms_1ms_tophat_noSatu_membrane,Image\x7CIntensity_MeanIntensity_lipid_3ms_50ms_tophat_noSatu_membrane,Image\x7CIntensity_MeanIntensity_lipid_3ms_300ms_tophat_noSatu_membrane,Image\x7CIntensity_MeanIntensity_lipid_3ms_30ms_tophat_noSatu_membrane,Image\x7CIntensity_MeanIntensity_lipid_3ms_200ms_tophat_noSatu_membrane,Image\x7CIntensity_MeanIntensity_lipid_3ms_100ms_tophat_noSatu_membrane,Image\x7CIntensity_MeanIntensity_lipid_3ms_10ms_tophat_noSatu_membrane,Image\x7CIntensity_MedianIntensity_protein_75ms_saturated,Image\x7CIntensity_MedianIntensity_protein_1000ms_saturated,Image\x7CIntensity_MedianIntensity_protein_100ms_saturated,Image\x7CIntensity_MedianIntensity_protein_5ms_saturated,Image\x7CIntensity_MedianIntensity_protein_3ms_75ms_tophat_noSatu_membrane,Image\x7CIntensity_MedianIntensity_protein_3ms_1000ms_tophat_noSatu_membrane,Image\x7CIntensity_MedianIntensity_protein_3ms_100ms_tophat_noSatu_membrane,Image\x7CIntensity_MedianIntensity_protein_3ms_5ms_tophat_noSatu_membrane,Image\x7CIntensity_MedianIntensity_protein_3ms_1ms_tophat_noSatu_membrane,Image\x7CIntensity_MedianIntensity_protein_3ms_50ms_tophat_noSatu_membrane,Image\x7CIntensity_MedianIntensity_protein_3ms_300ms_tophat_noSatu_membrane,Image\x7CIntensity_MedianIntensity_protein_3ms_30ms_tophat_noSatu_membrane,Image\x7CIntensity_MedianIntensity_protein_3ms_200ms_tophat_noSatu_membrane,Image\x7CIntensity_MedianIntensity_protein_3ms_10ms_tophat_noSatu_membrane,Image\x7CIntensity_MedianIntensity_protein_1ms_saturated,Image\x7CIntensity_MedianIntensity_protein_50ms_saturated,Image\x7CIntensity_MedianIntensity_protein_300ms_saturated,Image\x7CIntensity_MedianIntensity_protein_30ms_saturated,Image\x7CIntensity_MedianIntensity_protein_200ms_saturated,Image\x7CIntensity_MedianIntensity_protein_10ms_saturated,Image\x7CIntensity_MedianIntensity_lipid_3ms_75ms_tophat_noSatu_membrane,Image\x7CIntensity_MedianIntensity_lipid_3ms_1000ms_tophat_noSatu_membrane,Image\x7CIntensity_MedianIntensity_lipid_3ms_saturated,Image\x7CIntensity_MedianIntensity_lipid_3ms_5ms_tophat_noSatu_membrane,Image\x7CIntensity_MedianIntensity_lipid_3ms_1ms_tophat_noSatu_membrane,Image\x7CIntensity_MedianIntensity_lipid_3ms_50ms_tophat_noSatu_membrane,Image\x7CIntensity_MedianIntensity_lipid_3ms_300ms_tophat_noSatu_membrane,Image\x7CIntensity_MedianIntensity_lipid_3ms_30ms_tophat_noSatu_membrane,Image\x7CIntensity_MedianIntensity_lipid_3ms_200ms_tophat_noSatu_membrane,Image\x7CIntensity_MedianIntensity_lipid_3ms_100ms_tophat_noSatu_membrane,Image\x7CIntensity_MedianIntensity_lipid_3ms_10ms_tophat_noSatu_membrane,Image\x7CPathName_mask_membranes,Image\x7CPathName_protein_raw_75ms,Image\x7CPathName_protein_raw_1000ms,Image\x7CPathName_protein_raw_100ms,Image\x7CPathName_protein_raw_5ms,Image\x7CPathName_protein_raw_1ms,Image\x7CPathName_protein_raw_200ms,Image\x7CPathName_protein_raw_300ms,Image\x7CPathName_protein_raw_30ms,Image\x7CPathName_protein_raw_50ms,Image\x7CPathName_protein_raw_10ms,Image\x7CPathName_lipid_raw_3ms,Image\x7CPathName_lipid_3ms_liposomCenter,Image\x7CMath_Ratio_3_10,Image\x7CMath_Ratio_3_200,Image\x7CMath_Ratio_3_300,Image\x7CMath_Ratio_3_30,Image\x7CMath_Ratio_3_50,Image\x7CMath_Ratio_3_1,Image\x7CMath_Ratio_3_75,Image\x7CMath_Ratio_3_5,Image\x7CMath_Ratio_3_100,Image\x7CMath_Ratio_3_1000,Image\x7CMetadata_plateRepl,Image\x7CMetadata_rootPath,Image\x7CMetadata_plateName,Image\x7CMetadata_lipid,Image\x7CMetadata_pos,Image\x7CMetadata_wellNum,Image\x7CMetadata_runPath,Image\x7CMetadata_time,Image\x7CMetadata_posPath,Image\x7CMetadata_protein,Image\x7CMetadata_z,Image\x7CMetadata_wellPath,Image\x7CMetadata_channel,liposomeCenters\x7CLocation_Center_Y,liposomeCenters\x7CLocation_Center_X,liposomeCenters\x7CNumber_Object_Number,liposomes\x7CLocation_Center_Y,liposomes\x7CLocation_Center_X,liposomes\x7CNumber_Object_Number
    Data to export:Image
    Combine these object measurements with those of the previous object?:No
    File name:image.csv
    Use the object name for the file name?:No
    Data to export:liposomes
    Combine these object measurements with those of the previous object?:No
    File name:objects.csv
    Use the object name for the file name?:No
    Data to export:liposomeCenters
    Combine these object measurements with those of the previous object?:Yes
    File name:DATA.csv
    Use the object name for the file name?:Yes

CreateBatchFiles:[module_num:244|svn_version:\'11025\'|variable_revision_number:4|show_window:False|notes:\x5B\x5D]
    Store batch files in default output folder?:No
    Output folder path:/g/gavin/projects/Liposome_screen
    Are the cluster computers running Windows?:No
    Hidden\x3A in batch mode:No
    Hidden\x3A default input folder at time of save:/home/vonkova
    Hidden\x3A SVN revision number:0
    Local root path:/home/vonkova
    Cluster root path:/home/vonkova
