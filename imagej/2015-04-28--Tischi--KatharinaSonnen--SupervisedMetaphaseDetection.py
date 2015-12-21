from ij import IJ
from ij.plugin import Converter
from trainableSegmentation import WekaSegmentation
from fiji.threshold import Auto_Local_Threshold
from ij import IJ, ImagePlus, ImageStack
from ij.plugin import Duplicator
from ij.process import StackStatistics
from ij.plugin import ImageCalculator
from ij.plugin.filter import Analyzer

# functions 

def extractChannel(imp, nChannel, nFrame):
  """ Extract a stack for a specific color channel and time frame """
  stack = imp.getImageStack()
  ch = ImageStack(imp.width, imp.height)
  for i in range(1, imp.getNSlices() + 1):
    index = imp.getStackIndex(nChannel, i, nFrame)
    ch.addSlice(str(i), stack.getProcessor(index))
  return ImagePlus("Channel " + str(nChannel), ch)


def threshold(imp, threshold):
  impout = Duplicator().run(imp)
  #imp.show(); time.sleep(0.2)
  #IJ.setThreshold(imp, mpar['lthr'], mpar['uthr'])
  IJ.setThreshold(impout, threshold, 1000000000)
  IJ.run(impout, "Convert to Mask", "stack")
  impout.setTitle("Threshold");
  #IJ.run(imp, "Divide...", "value=255 stack");
  #IJ.setMinAndMax(imp, 0, 1);
  return impout

  
######################
# get image from ZEN #
######################




# get image
imagePath = "Z:/Tischi/projects/KatharinaSonnen/20150412--Automation_H2B-GFP/Automation_H2B-GFP/TestImage_1024.tif"
imp = IJ.openImage(imagePath)
imp.show()

# classification
classifierPath = "Z:/Tischi/projects/KatharinaSonnen/20150412--Automation_H2B-GFP/Automation_H2B-GFP/classifier.model"
ws = WekaSegmentation(imp)  # create an instance
ws.loadClassifier(classifierPath) # load classifier
impProb = ws.applyClassifier(imp, 0, True)
#impProb.show()
impMetaProb = extractChannel(impProb,1,1)
impMetaProb.setTitle("MetaProb")

# segmentation
impBW = threshold(impMetaProb,0.6)
impMetaProb.show()
IJ.run("Set Measurements...", " mean center shape area redirect=MetaProb decimal=2");
impBW.show()

# particle analysis
IJ.run("Analyze Particles...", "size=10-10000 pixel area circularity=0.00-1.00 display exclude clear stack add");
rt = Analyzer.getResultsTable()
validParticles = []
if(rt.getColumnIndex("XM")==-1):
  print "# particles = 0"
else:
  X = rt.getColumn(rt.getColumnIndex("XM"))
  Y = rt.getColumn(rt.getColumnIndex("YM"))
  Mean = rt.getColumn(rt.getColumnIndex("Mean"))
  Circ = rt.getColumn(rt.getColumnIndex("Circ."))
  Area = rt.getColumn(rt.getColumnIndex("Area"))
  print "# particles = " + str(len(Mean))
  for i in range(len(Mean)):
    valid = (Mean[i]>0.8) and (Circ[i]<0.8)   # filter particles post detection
    if(valid):
      validParticles.append(i)

nValid = len(validParticles)
print "# valid particles = "+str(nValid)
for x in validParticles: print x + 1   # IJ starts at 1, while python starts at 0

#######################
# send command to ZEN #
#######################



