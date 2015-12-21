from ij.io import OpenDialog, DirectoryChooser
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

# import my analysis function collection
import os, sys, inspect
this_folder = os.path.realpath(os.path.abspath(os.path.split(inspect.getfile( inspect.currentframe() ))[0]))
if this_folder not in sys.path:
  print this_folder
  sys.path.insert(0, this_folder)
import ct_analysis_functions as af
reload(af)


def analyze(path, nc, nz, nt):

  # load
  imp = af.load_image_sequence_from_path_to_hyperstack(path, nc, nz, nt)
  #imp.show()
  # analyze
  imp = af.project_z(imp, "sum")
  #imp2.show()
  # save
  path_out = os.path.join(path,"sum_projection")
  af.save_hyperstack_as_image_sequence(imp, path_out)
  asdfds
  return 0
   
 
# obtains the files and sends them to the analyse function
# todo: give the name of the analysis function as an argument!
def get_files_and_analyze(folder):

  count = 0
  timeseries = []
  for root, directories, filenames in os.walk(folder):
    #print directories
    for directory in sorted(directories):
      #print directory
      if not (("field" in directory)): # "field is specific to the folder where the image files are"
        continue
      else:
        print os.path.join(root, directory)
        analyze(os.path.join(root, directory), 3, 7, 1)

  
          
if __name__ == '__main__':
  dc = DirectoryChooser("Choose top directory containing all Matrix Screener images")
  foldername = dc.getDirectory()
  #od = OpenDialog("Click on one of the image files in the folder to be analysed", None	)
  #filename = od.getFileName()
  #foldername = od.getDirectory()
  #print foldername
  
  print "\n\n\n\n\n\n"
  
  #foldername = "/g/almf/software/scripts/imagej/Data_MatrixScreenerImport"
  
  if None != foldername:
    print "foldername = "+foldername
    get_files_and_analyze(foldername)