from ij.io import OpenDialog
from ij.io import Opener
from ij.plugin import ZProjector, RGBStackMerge
from ij import IJ, ImagePlus, ImageStack
from ij.plugin import Duplicator
from ij.process import StackStatistics
from ij.plugin import ImageCalculator
from ij.measure import ResultsTable
from jarray import array


# import my analysis function collection
import os, sys, inspect
this_folder = os.path.realpath(os.path.abspath(os.path.split(inspect.getfile( inspect.currentframe() ))[0]))
if this_folder not in sys.path:
  print this_folder
  sys.path.insert(0, this_folder)
import ct_analysis_functions as af
reload(af)

  
def analyse(root, filename, output_folder):
  # input
  dx = 1
  dy = 1
  dz = 1 
  
  # loading
  print "opening",root,filename
  imp = Opener().openImage(root, filename)      

  # processing
  #imp.show()
  print "processing.."
  imp = af.convert_to_32bit(imp)
  imp = af.blur_3D_gauss(imp,dx,dy,dz)
  imp_max = af.project_z(imp, "max")
  imp_sum = af.project_z(imp, "sum")
  
  #imp_sum = af.project_z_sum(imp)
  #imp_max.show()
  
  # saving
  af.save_hyperstack_as_image_sequence(imp_max, output_folder)
  af.save_hyperstack_as_image_sequence(imp_sum, output_folder)
  
  return None

  
# obtains the files and sends them to the analyse function
# todo: give the name of the analysis function as an argument!
def getFilesAndAnalyze(input_folder, output_folder):
  if not os.path.exists(input_folder):
    print input_folder,"does not exist"
  else:
    for root, directories, filenames in os.walk(input_folder):
      print "sub folders:", directories
      for filename in filenames:
        print filename
        if not ("cropped.lsm" in filename):
          continue
        else:
          #print root
          #print directories
          #print filename
          analyse(root, filename, output_folder)

          
if __name__ == '__main__':
  od = OpenDialog("Click on one of the image files in the folder to be analysed", None	)
  #filename = od.getFileName()
  input_folder = od.getDirectory()
  #print input_folder
  
  #input_folder = "/g/almf/group/ALMFstuff/Tischi/projects/AleksandarNecakov_deRenzis/2015-10-28--SIM_Live/4percent laser power"
  output_folder = input_folder+"fiji_out"
  #print output_folder
  
  
  print ""
  print ""
  print ""
  print ""
  print ""

  if not os.path.exists(output_folder):
    os.mkdir(output_folder)
  print "Storing files in",output_folder
  
  if input_folder != None:
    print "Analyzing files in",input_folder
    getFilesAndAnalyze(input_folder, output_folder)

  print "done."