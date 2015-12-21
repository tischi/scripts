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


# import my analysis function collection
import os, sys, inspect
this_folder = os.path.realpath(os.path.abspath(os.path.split(inspect.getfile( inspect.currentframe() ))[0]))
if this_folder not in sys.path:
  print this_folder
  sys.path.insert(0, this_folder)
import ct_analysis_functions as af
reload(af)


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
  
 
def analyze(folder_name, file_name):
  # prepare
  af.close_all_image_windows()
  #af.close_non_image_window("Results")
  
  
  # load
  imp = Opener().openImage(folder_name, file_name)
  #imp = IJ.getImage()
        
  # segment
  imp_scaled = af.scale(imp, 0.25, 0.25, 1) #imp_scaled = af.scale(imp, 0.25, 0.25, 1)
  calibration = imp_scaled.getCalibration()
  imp_corr = af.attenuation_correction(imp_scaled, 15.0, 8.0)
  imp_bw = af.auto_threshold(imp_corr, "Yen")
  imp_label = af.watershed_3d(imp_bw, 8)

  # filter objects based on intensity or roughness=surface/volume?
  
  # measure 
  af.clear_results_table_if_exists()
  imp_label.setCalibration(calibration)
  results_table = af.geometrical_measure_3D(imp_label)
  #results_table = af.intensity_measure_3D(imp_scaled, imp_label)
  
  # create images for visual inspection
  imp_outlines = af.make_outline_image(imp_label)
  IJ.run(imp_outlines, "Fire", "")
  imp_merged = af.merge_images(imp_scaled, imp_outlines, force_same_bit_depth=True)
  #imp_merged.show()
  
  # configure and run 3D Objects Counter
  #imp_outlines = af.objects_counter_3d(imp_bw, imp_scaled, "volume nb_of_obj._voxels integrated_density mean_gray_value", threshold=1, vol_min=50, vol_max=100000)
  #imp_merged = af.merge_images(imp_outlines, imp_scaled)

  # save
  file_name_out = file_name + "--fiji-out.tif"
  IJ.saveAs(imp_merged, "TIFF", os.path.join(folder_name, file_name_out))
  file_name_out = file_name + "--fiji-out.csv"
  results_table.save(os.path.join(folder_name, file_name_out))
  

  
# obtains the files and sends them to the analyse function
# todo: give the name of the analysis function as an argument!
def getFilesAndAnalyze(folder):

  count = 0
  timeseries = []
  for root, directories, filenames in os.walk(folder):
    print directories
    for filename in sorted(filenames):
      #print filenames
      if not ((".tif" in filename)):
        continue
      elif (("--fiji-out" in filename)):
        continue
      else:
        #print root
        #print directories
        #print filename
        analyze(root, filename)
        

  
          
if __name__ == '__main__':
  od = OpenDialog("Click on one of the image files in the folder to be analysed", None	)
  #filename = od.getFileName()
  foldername = od.getDirectory()
  print foldername
  
  #print "\n\n\n\n\n\n"
  
  #foldername = "/g/almfscreen/tischer/Henning/2015-11-04--data/2_subset"
  
  #if None != foldername:
  #  print "foldername = "+foldername
  getFilesAndAnalyze(foldername)
  #imp = IJ.getImage()
  #analyze(imp)