from ij.io import OpenDialog
from ij.io import Opener
from ij.plugin import ZProjector, RGBStackMerge
from ij import IJ, ImagePlus, ImageStack
from ij.plugin import Duplicator
from ij.process import StackStatistics
from ij.plugin import ImageCalculator
from ij.measure import ResultsTable

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
