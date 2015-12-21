from ij.io import OpenDialog
from ij.io import Opener
from ij.plugin import ZProjector, RGBStackMerge
from ij import IJ, ImagePlus, ImageStack
from ij.plugin import Duplicator
from ij.process import StackStatistics
from ij.plugin import ImageCalculator
from ij.measure import ResultsTable
import os
from jarray import array

def closeEverything():
  IJ.run("Close All", "")
  IJ.selectWindow("Results")
  IJ.run("Close")


def measureSkeletonTotalLength(imp, root):
  IJ.run(imp,"Analyze Skeleton (2D/3D)", "prune=none")
  totalLength = 0
  nBranches = 0
  rt = ResultsTable.getResultsTable()
  avgLengths = rt.getColumn(rt.getColumnIndex("Average Branch Length"))
  for i in range(len(avgLengths)):
    totalLength = totalLength + rt.getValue("# Branches", i) * rt.getValue("Average Branch Length", i)
    nBranches = nBranches + rt.getValue("# Branches", i)	
  print root,",",imp.getTitle(),",",totalLength,",",nBranches

  
def analyse(imp, root, filename):
  imp.show()
  #print ""
  #print(imp.getTitle())
  #print "**********************************"

  measureSkeletonTotalLength(imp, root)
  closeEverything()

 
# obtains the files and sends them to the analyse function
# todo: give the name of the analysis function as an argument!
def getFilesAndAnalyze(folder):
  for root, directories, filenames in os.walk(folder):
    print directories
    for filename in filenames:
      #print filename
      if not ("--skeleton.png" in filename):
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
  
  foldername = "C:/Users/Christian Tischer/Dropbox/Christian For Analysis/MT_SuperRes--cp_out"
  
  if None != foldername:
    print "foldername = "+foldername
    getFilesAndAnalyze(foldername)