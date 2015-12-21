from ij.io import OpenDialog, DirectoryChooser
from ij.gui import GenericDialog
from ij.io import Opener
from ij.plugin import ZProjector, RGBStackMerge
from ij import IJ, ImagePlus, ImageStack
from ij.plugin import Duplicator
from ij.process import StackStatistics
from ij.plugin import ImageCalculator
from ij import WindowManager
from ij.measure import ResultsTable

import os
from jarray import array

def closeAllImageWindows():
  w = WindowManager
  print(w.getImageTitles())
  #print(w.getNonImageTitles())
  if w.getIDList():
    for id in w.getIDList():
      img = w.getImage(id)
      img.changes = False
      win = img.getWindow()
      win.close()

def closeAllNoneImageWindows():
  w = WindowManager
  print(w.getNonImageTitles())
  #print(w.getNonImageTitles())
  if w.getNonImageWindows():
    for win in w.getNonImageWindows():
      win.close()

def extractChannel(imp, nChannel, nFrame):
  """ Extract a stack for a specific color channel and time frame """
  stack = imp.getImageStack()
  ch = ImageStack(imp.width, imp.height)
  for i in range(1, imp.getNSlices() + 1):
    index = imp.getStackIndex(nChannel, i, nFrame)
    ch.addSlice(str(i), stack.getProcessor(index))
  return ImagePlus("Channel " + str(nChannel), ch)

def measureSumIntensity3D(imp):
  stats = StackStatistics(imp)
  return stats.mean * stats.pixelCount

def autoThreshold(imp, method):
  impout = imp.duplicate() 
  IJ.run(impout, "Auto Threshold", "method=" + method + " white stack use_stack_histogram");
  impout.setTitle("Auto Threshold")
  return impout

def threshold(_img, threshold):
  imp = Duplicator().run(_img)
  #imp.show(); time.sleep(0.2)
  #IJ.setThreshold(imp, mpar['lthr'], mpar['uthr'])
  IJ.setThreshold(imp, threshold, 1000000000)
  IJ.run(imp, "Convert to Mask", "stack")
  imp.setTitle("Threshold");
  #IJ.run(imp, "Divide...", "value=255 stack");
  #IJ.setMinAndMax(imp, 0, 1);
  return imp


def analyse(imp, root, filename, thresholds):
  closeAllImageWindows() 
  imp.show()
  print ""
  print(imp.getTitle())
  print "**********************************"

  IJ.run("Set Measurements...", "integrated redirect=None decimal=2");
  # get image calibration info
  IJ.run(imp, "Properties...", "unit=pixel pixel_width=1 pixel_height=1");
  
  # convert to 8-bit
  IJ.setMinAndMax(imp, 0, 65535);
  IJ.run(imp, "8-bit", "");
  thresholds = [(x / 65535 * 255) for x in thresholds]

  # Nuclei
  #closeAllNoneImageWindows()
  iChannel = 1
  imp.setSlice(iChannel)
  IJ.run(imp, "Gaussian Blur...", "sigma=2 slice");
  IJ.setThreshold(imp, thresholds[iChannel-1], 1000000000)
  IJ.run(imp, "Convert to Mask", "method=Default background=Dark only black");
  IJ.run(imp, "Measure", "");
  rt = ResultsTable.getResultsTable()
  values = rt.getColumnAsDoubles(rt.getColumnIndex("RawIntDen"))
  print("Area Nuclei (pixel^2) =",values[-1]/255)
  
  
  # Dots
  #closeAllNoneImageWindows()
  iChannel = 3
  imp.setSlice(iChannel)
  IJ.run(imp, "Gaussian Blur...", "sigma=1 slice");
  IJ.run(imp, "Find Maxima...", "noise="+str(thresholds[iChannel-1])+" output=Count");
  rt = ResultsTable.getResultsTable()
  values = rt.getColumnAsDoubles(rt.getColumnIndex("Count"))
  print("Number of Dots =",values[-1])
  
  
# obtains the files and sends them to the analyse function
# todo: give the name of the analysis function as an argument!
def getFilesAndAnalyze(folder, thresholds, crop):
  for root, directories, filenames in os.walk(folder):
    print directories
    for filename in filenames:
      #print filename
      #print filename.split("--")[-1]
      if ( ("segmented.tif" == filename.split("--")[-1]) or (filename=="Thumbs.db") ):
        #print "file no good"
        continue
      else:
        #print root
        #print directories
        #print filename
        if filename.split(".")[-1] == "lsm":
          cmd = "open="+root+filename+" color_mode=Default crop view=[Standard ImageJ] stack_order=Default x_coordinate_1="+str(crop[0])+" y_coordinate_1="+str(crop[1])+" width_1="+str(crop[2])+" height_1="+str(crop[3])
          IJ.run("Bio-Formats Importer", cmd);
          imp = IJ.getImage()
          analyse(imp, root, filename, thresholds)
        else: 
          imp = Opener().openImage(root, filename)
          analyse(imp, root, filename, thresholds)
        
          
if __name__ == '__main__':
  srcDir = DirectoryChooser("Choose directory").getDirectory()
  #od = OpenDialog("Click on one of the image files in the folder to be analysed", None	)
  #filename = od.getFileName()
  #foldername = od.getDirectory()
  #foldername = "Z:/Tischi/projects/CellZome/2015-04-27--3D_Tissue/data"
  gd = GenericDialog("3D Tissue analysis");
  gd.addNumericField("Threshold Nuclei: ", 4000, 0);
  gd.addNumericField("Threshold Ch2: ", 1000, 0);
  gd.addNumericField("Threshold Dots: ", 3000, 0);
  gd.addNumericField("x: ", 4000, 0);
  gd.addNumericField("y: ", 4000, 0);
  gd.addNumericField("width: ", 3000, 0);
  gd.addNumericField("height: ", 3000, 0);
  gd.showDialog();
  #if (gd.wasCanceled()):
  #  return
  thresholds = []
  thresholds.append(gd.getNextNumber())
  thresholds.append(gd.getNextNumber())
  thresholds.append(gd.getNextNumber())
  crop = []
  crop.append(gd.getNextNumber())
  crop.append(gd.getNextNumber())
  crop.append(gd.getNextNumber())
  crop.append(gd.getNextNumber())
  #foldername = "Z:/Tischi/projects/CellZome/2015-04-29--3D_Tissue/subset"

  if None != srcDir:
    closeAllNoneImageWindows()
    print "\n\n\n\nfoldername = "+srcDir
    getFilesAndAnalyze(srcDir, thresholds, crop)