from ij import IJ
from ij.plugin import Converter
from trainableSegmentation import WekaSegmentation
from fiji.threshold import Auto_Local_Threshold
from ij import IJ, ImagePlus, ImageStack
from ij.plugin import Duplicator
from ij.process import StackStatistics
from ij.plugin import ImageCalculator
from ij.plugin.filter import Analyzer

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


def analyse(imp, root, filename):
	#
	# classification
	#
	classifierPath = "//almf/almf/software/scripts/imagej/2015-10-14--Tischi--ShaneMorley--MTnetworkAnalysis/classifier.model"
	ws = WekaSegmentation(imp)  # create an instance
	ws.loadClassifier(classifierPath) # load classifier
	impProb = ws.applyClassifier(imp, 0, True)
	#impProb.show()
	impMetaProb = extractChannel(impProb,1,1)
	impMetaProb.setTitle("MetaProb")
	
	#
	# segmentation
	#
	impBW = threshold(impMetaProb,0.75)
	impMetaProb.show()
	impBW.show()
	
	#
	# skeletonization
	#
	run("Skeletonize (2D/3D)");
	run("Analyze Skeleton (2D/3D)", "prune=[shortest branch] show display");

# obtains the files and sends them to the analyse function
# todo: give the name of the analysis function as an argument!
def getFilesAndAnalyze(folder):
  for root, directories, filenames in os.walk(folder):
    print directories
    for filename in filenames:
      if not (".tif"==os.path.splitext(filename)[1]):
        continue
      else:
        #print root
        #print directories
        #print filename
        imp = Opener().openImage(root, filename)
        analyse(imp, root, filename)

          
if __name__ == '__main__':
  #od = OpenDialog("Click on one of the image files in the folder to be analysed", None	)
  #filename = od.getFileName()
  #foldername = od.getDirectory()
  #foldername = "Z:/Tischi/projects/CellZome/2015-04-27--3D_Tissue/data"

  print ""
  print ""
  print ""
  print ""
  print ""
  
  foldername = "Z:/Tischi/projects/CellZome/2015-04-29--3D_Tissue/subset"

  
  if None != foldername:
    print "foldername = "+foldername
    getFilesAndAnalyze(foldername)
