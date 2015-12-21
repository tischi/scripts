# Walk recursively through an user-selected directory
# and add all found filenames that end with ".tif"
# to a VirtualStack, which is then shown.
#
# It is assumed that all images are of the same type
# and have the same dimensions.
 
import os
import time
from ij.io import OpenDialog, DirectoryChooser
from ij import IJ, ImagePlus, ImageStack

fileID = "--Cy5_3ms.ome--rawimage.jpeg" # enter unique string for the files you want to process
method = "contrast" # contrast   # select method: scale OR contrast
 
def run():
  srcDir = DirectoryChooser("Choose!").getDirectory()
  if not srcDir:
    # user canceled dialog
    return
  
  for root, directories, filenames in os.walk(srcDir):
    for filename in filenames:
      # Skip non-TIFF files
      if not filename.endswith(fileID):
        continue
      path = os.path.join(root, filename)
      print path
      imp = IJ.openImage(path)
      imp.show()
      if method=="contrast":
        IJ.run(imp,"Enhance Contrast", "saturated=0.35");
        time.sleep(0.2)
        IJ.save(imp,path + "_auto.jpeg")
        imp.changes = False
        imp.getWindow().close()
      elif method=="scale":
        IJ.run(imp, "Scale...", "x=0.2 y=0.2 interpolation=None create title=small");      
        impScale = IJ.getImage()
        time.sleep(0.2)
        IJ.save(impScale,path + "_thumb.jpeg")
        imp.changes = False
        imp.getWindow().close()
        impScale.changes = False
        impScale.getWindow().close()
      
      
run()