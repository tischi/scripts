from ij import IJ
from ij.io import OpenDialog
from loci.formats import ImageReader
from loci.formats import MetadataTools

# open file
od = OpenDialog("Choose a file");
filepath = od.getPath()
print("Image path: " + filepath);

# use bio-formats to extract information
reader = ImageReader()
omeMeta = MetadataTools.createOMEXMLMetadata()
reader.setMetadataStore(omeMeta)
reader.setId(filepath)

seriesCount = reader.getSeriesCount()
print "Series count:",seriesCount
reader.close()


