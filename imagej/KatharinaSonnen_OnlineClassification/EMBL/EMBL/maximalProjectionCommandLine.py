import os, sys
from ij import IJ
from ij.io import FileSaver
from loci.plugins import BF
from subprocess import call
from ij.plugin import ZProjector 

try:
	filepath = getArgument()
except Exception, e:
	sys.exit(" no file " + e)
try:
	imp = BF.openImagePlus(filepath)
	image = imp[0]
	zProj = ZProjector(image)
	zProj.setMethod(zProj.MAX_METHOD)
	zProj.doProjection()
	imgMax = zProj.getProjection()
	#imgMax.show()
	FileSaver(imgMax).saveAsTiff(os.path.splitext(filepath)[0] + "_MAX.tif")
except Exception, e:
	sys.exit(e)
except Exception, e:
	sys.exit(e)
