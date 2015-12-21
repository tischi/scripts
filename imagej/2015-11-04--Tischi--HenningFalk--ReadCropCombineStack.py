from ij.io import OpenDialog
from ij.io import Opener
from ij.plugin import ZProjector, RGBStackMerge, SubstackMaker, Concatenator
from ij import IJ, ImagePlus, ImageStack
from ij.plugin import Duplicator
from ij.process import StackStatistics
from ij.plugin import ImageCalculator
from ij.measure import ResultsTable
import os
from jarray import array
from ij.process import ImageConverter


from loci.plugins import BF
from loci.common import Region
from loci.plugins.in import ImporterOptions


def appendFileToArray(impA, root, filename):
 
  print os.path.join(root,filename)
  
  if 1:
    x = 30
    y = 64
    xw = 1000
    yw = 900
    zs = 400
    ze = 1030
    gvmin = 0
    gvmax = 777
    imp = openCroppedImageUsingBF(os.path.join(root,filename),x,y,xw,yw,zs,ze, crop=0)
    
    #stats = StackStatistics(imp)
    #print stats.min, stats.max 

    # probably move this out of this loop
    #imp = convertTo8bit(imp,gvmin,gvmax)  #0,777
    #imp = keepSlices(imp,400,800) #200,650

    impA.append(imp)

  return impA
  
 
 
# obtains the files and sends them to the analyse function
# todo: give the name of the analysis function as an argument!
def getFilesAndAnalyze(folder):

  count = 0
  timeseries = []
  for root, directories, filenames in os.walk(folder):
    print directories
    for filename in sorted(filenames):
      #print filenames
      if not (("_1.tif" in filename) and ("2views_2" in filename)):
        continue
      else:
        #print root
        #print directories
        #print filename
        timeseries = appendFileToArray(timeseries, root, filename)
        count = count + 1
      if count>10000:
        break  

  
  calib = timeseries[0].getCalibration()
  jaimp = array(timeseries, ImagePlus)
  
  nc = 1
  nz = timeseries[0].getImageStack().getSize()
  nt = len(timeseries)
  print nc,nz,nt
  
  allimp = Concatenator().concatenate(jaimp, False)
  allimp.setDimensions(nc, nz, nt)
  allimp.setCalibration(calib)
  allimp.setOpenAsHyperStack(True)
  allimp.show()
  
          
if __name__ == '__main__':
  #od = OpenDialog("Click on one of the image files in the folder to be analysed", None	)
  #filename = od.getFileName()
  #foldername = od.getDirectory()
  #print foldername
  
  print "\n\n\n\n\n\n"
  
  foldername = "/g/almfscreen/tischer/Henning/2015-11-04--data/2_subset"
  
  if None != foldername:
    print "foldername = "+foldername
    getFilesAndAnalyze(foldername)