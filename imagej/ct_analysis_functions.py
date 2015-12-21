from ij.io import OpenDialog
from ij.io import Opener
from ij.plugin import ZProjector, RGBStackMerge
from ij import IJ, ImagePlus, ImageStack, WindowManager
from ij.plugin import Duplicator, Filters3D, GaussianBlur3D, HyperStackConverter, FolderOpener, ImageCalculator
from ij.process import StackStatistics, ImageProcessor, ImageConverter
from ij.plugin.filter import MaximumFinder
from ij.measure import ResultsTable
from mcib_plugins import Watershed_Split3D
from mcib_plugins.analysis import simpleMeasure

import time
import os


def StepMaker():
  def StepReader(func):
    def MakeStep(*args, **kwargs):
      start_time = time.time()
      output = func(*args, **kwargs)
      elapsed_time = time.time() - start_time
      print func.__name__,"-- time:",round(elapsed_time,3)
      return output
    return MakeStep
  return StepReader



@StepMaker()
def find_maxima_stack(imp, tolerance):
  stack = imp.getImageStack()
  stack_out = ImageStack(imp.width, imp.height)
  for i in range(1, imp.getNSlices() + 1):
    ip = stack.getProcessor(i)
    # findMaxima(ImageProcessor ip, double tolerance, double threshold, int outputType, boolean excludeOnEdges, boolean isEDM)
    ip_max = MaximumFinder().findMaxima(ip, tolerance, ImageProcessor.NO_THRESHOLD, MaximumFinder.IN_TOLERANCE, False, False)
    stack_out.addSlice(str(i), ip_max)
    #segip.invert()
  return ImagePlus("Maxima", stack_out)

@StepMaker()
def close_non_image_window(window_name):
  # forcefully closes one specific non image window
  frames = WindowManager.getNonImageWindows()
  for i in range(len(frames)):
    #IJ.log(frames[i].getTitle())
    if (frames[i].getTitle() == window_name):
      frames[i].dispose()


@StepMaker()
def clear_results_table_if_exists():
  rt = ResultsTable.getResultsTable()
  if rt!=None:
    rt.reset()
  
@StepMaker()
def close_all_image_windows():
  # forcefully closes all open images windows
  ids = WindowManager.getIDList();
  if (ids==None):
    return
  for i in ids:
     imp = WindowManager.getImage(i)
     if (imp!=None):
       win = imp.getWindow()
       if (win!=None):
         imp.changes = False # avoids the "save changes" dialog
         win.close()
         

@StepMaker()
def keepSlices(imp, first, last):
  stack = imp.getImageStack()
  # remove front part
  for i in range(1,first+1):
    stack.deleteSlice(1)
  # remove back part
  n = stack.getSize()
  for i in range(last-first,n+1):
    stack.deleteSlice(last-first)
  imp.setStack(stack)
  return imp


@StepMaker()
def geometrical_measure_3D(imp_label):
  # remove results table if exists:
  close_non_image_window("Results")
  # measure
  #imp_label.show()
  rt = ResultsTable.getResultsTable()
  IJ.run(imp_label, "3D Geometrical Measure", "");
  rt = ResultsTable.getResultsTable()
  return rt


@StepMaker()
def intensity_measure_3D(imp_intens, imp_label):
  imp_intens.show()
  imp_label.show()
  IJ.run(imp_intens, "3D Intensity Measure", "objects=[%s] signal=[%s]" % (imp_label.getTitle(), imp_intens.getTitle()) );
  imp_intens.hide()
  imp_label.hide()
  rt = ResultsTable.getResultsTable()
  return rt


@StepMaker()
def intensity_measure_3D_direct(imp_intens, imp_label):
  # todo: handle the arraylist output
  sm = simpleMeasure(imp_label)
  arraylist = sm.getMeasuresStats(imp_intens)
  for i in arraylist:
    print i
  
@StepMaker()
def save_hyperstack_as_image_sequence(imp, path):
  # make dir
  if not os.path.isdir(path): 
    os.mkdir(path)
  #imp.show()
  ssize = imp.getStackSize()
  titleext = imp.getTitle()
  #print titleext
  title = os.path.splitext(titleext)[0]
  dimA = imp.getDimensions()
  print "Title",title,"     -----   Dimensions",dimA
  for c in range(dimA[2]):   
    for z in range(dimA[3]):
        for t in range(dimA[4]):
            # imagej is one-based and we save zero-based
            numberedtitle = \
            title + "--C" + IJ.pad(c, 2) + \
            "--Z" + IJ.pad(z, 4) + \
            "--T" + IJ.pad(t, 4) + ".tif"
            stackindex = imp.getStackIndex(c+1, z+1, t+1) # imagej is one-based
            aframe = ImagePlus(numberedtitle, imp.getStack().getProcessor(stackindex))
            IJ.log("saving: " + os.path.join(path, numberedtitle))
            IJ.saveAs(aframe, "TIFF", os.path.join(path, numberedtitle))
            
@StepMaker()
def load_image_sequence_from_path_to_hyperstack(path, nc, nz, nt):
  imp = FolderOpener().openFolder(path)
  imp2 = HyperStackConverter.toHyperStack(imp, nc, nz, nt, "default", "Color");
  return imp2

@StepMaker()
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

 
@StepMaker()
def project_z(imp, method):
  zp = ZProjector(imp)
  if method=="max":
    zp.setMethod(ZProjector.MAX_METHOD)
  if method=="sum":
    zp.setMethod(ZProjector.SUM_METHOD)
    
  zp.setStopSlice(imp.getNSlices())
  zp.doHyperStackProjection(True)
  zpimp = zp.getProjection()
  
  #IJ.run(imp, "Z Project...", "projection=[Max Intensity] all");
  #impout = IJ.getImage()
  
  return zpimp

@StepMaker()
def make_16bit_using_minmax(_imp):
  # ????? this does not make sense, or ???
  imp = _imp.duplicate()
  stats = StackStatistics(imp)
  IJ.setMinAndMax(imp, stats.min, stats.max)
  IJ.run(imp, "16-bit", "")
  IJ.setMinAndMax(imp, 0, 65535)
  return imp


@StepMaker()
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

@StepMaker()
def openCroppedImageUsingBF(filepath,x,y,xw,yw,zs,ze, crop):
  # read in and display ImagePlus(es) with arguments
  options = ImporterOptions()
  options.setColorMode(ImporterOptions.COLOR_MODE_GRAYSCALE)
  if crop:
    options.setCrop(True)
    options.setCropRegion(0, Region(x,y,xw,yw))
    options.setTBegin(0, zs)
    options.setTEnd(0, ze)
  options.setId(filepath)
  imps = BF.openImagePlus(options)
  return imps[0]

@StepMaker()
def scale(imp,x,y,z):
  #imp = _imp.duplicate()
  #impout.setTitle("scaled")
  IJ.run(imp, "Scale...", "x=%s y=%s z=%s interpolation=Bilinear average process create" % (x, y, z));
  imp_out = IJ.getImage(); imp_out.setTitle("Scaled"); imp_out.hide()
  return imp_out


@StepMaker()
def make_outline_image(imp):
  
  imp.show() # one needs to display it, otherwise below function cannot find it
  IJ.run("3D Fast Filters","filter=Minimum radius_x_pix=1.0 radius_y_pix=1.0 radius_z_pix=1.0");
  imp.hide()
  
  imp_minimum = WindowManager.getImage("3D_Minimum")
  imp_outlines = imp.duplicate()
  calc = ImageCalculator()
  calc.calculate("Subtract stack", imp_outlines, imp_minimum)
  # clean up
  imp_minimum.close()
  imp_outlines.setTitle("Outlines")  
  return imp_outlines
  
@StepMaker()
def merge_images(_imp1, _imp2, force_same_bit_depth):
  imp1 = _imp1.duplicate()
  imp2 = _imp2.duplicate()
  imp1.show(); imp2.show();
  if(force_same_bit_depth):
    bd = max(imp1.getBitDepth(),imp2.getBitDepth())
    if bd==16:
      convert_to_16bit(imp1)
      convert_to_16bit(imp2)
    if bd==32:
      convert_to_32bit(imp1)
      convert_to_32bit(imp2)
  IJ.run(imp1, "Merge Channels...", "c1=[%s] c2=[%s] create" % (imp1.getTitle(), imp2.getTitle()))
  imp_out = WindowManager.getImage("Composite"); imp_out.hide()
  imp1.hide(); imp2.hide()
  return imp_out


@StepMaker()
def objects_counter_3d(imp_bw, imp_intens, measurements, threshold, vol_min, vol_max):
  # set options
  options = "%s dots_size=5 font_size=10 show_numbers white_numbers redirect_to=%s" % (measurements, imp_intens.getTitle())
  IJ.run("3D OC Options", options);
  # make sure the output image does not exist already as this leasds to weird behaviors....
  outlines_title = "Surface map of %s redirect to %s" % (imp_bw.getTitle(),imp_intens.getTitle())
  if WindowManager.getImage(outlines_title) != None: 
    WindowManager.getImage(outlines_title).close()
  # analyze
  imp_bw.show(); imp_intens.show();
  IJ.run(imp_bw, "3D Objects Counter", "threshold=%s min.=%s max.=%s exclude_objects_on_edges surfaces statistics" % (threshold, vol_min, vol_max))
  imp_out = IJ.getImage(); imp_out.setTitle("outlines"); imp_out.hide()
  return imp_out


@StepMaker()
def convert_to_8bit(imp, vmin, vmax):
  IJ.setMinAndMax(imp, vmin, vmax)
  ImageConverter(imp).convertToGray8() 
  return imp

@StepMaker()
def convert_to_16bit(imp):
  ImageConverter(imp).convertToGray16() 
  return imp

@StepMaker()  
def make_8bit_using_min_max(_imp):
  imp = _imp.duplicate()
  stats = StackStatistics(imp)
  IJ.setMinAndMax(imp, stats.min, stats.max)
  IJ.run(imp, "8-bit", "")
  IJ.setMinAndMax(imp, 0, 255)
  return imp

@StepMaker()
def convert_to_32bit(imp):
  IJ.run(imp, "32-bit", "")
  return imp

@StepMaker()
def filter_3D_gauss(imp,dx,dy,dz):
  #stack = imp.getImageStack()
  #f3d = Filters3D() 
  #newStack = f3d.filter(stack, f3d.MEAN, dx, dy, dz)
  #imp_out = ImagePlus("Filtered Stack", newStack)
  #print "Gaussian Blur 3Dedsd..."
  #IJ.run(imp, "Gaussian Blur 3D...", "x="+str(dx)+" y="+str(dy)+" z="+str(dz))
  GaussianBlur3D().blur(imp, dx, dy, dz)
  return imp

@StepMaker()
def extract_channel(imp, nChannel, nFrame):
  """ Extract a stack for a specific color channel and time frame """
  stack = imp.getImageStack()
  ch = ImageStack(imp.width, imp.height)
  for i in range(1, imp.getNSlices() + 1):
    index = imp.getStackIndex(nChannel, i, nFrame)
    ch.addSlice(str(i), stack.getProcessor(index))
  return ImagePlus("Channel " + str(nChannel), ch)

@StepMaker()
def watershed_3d(imp, radius):
  imp.show() # one needs to display it, otherwise below function cannot find it
  IJ.run("3D Watershed Split", "binary=%s seeds=Automatic radius=%s" % (imp.getTitle(), radius))
  imp.hide()
  # get the output image
  imp_out = IJ.getImage()
  imp_out.hide()
  # remove the EDT image, which is also displayed
  WindowManager.getImage("EDT").close()
  return imp_out
    
@StepMaker()  
def attenuation_correction(imp, intensity_zmin, intensity_zmax):
  # check: http://rsb.info.nih.gov/ij/plugins/stack-contrast/index.htm
  stack = imp.getImageStack()
  stack_out = ImageStack(imp.width, imp.height)
  a = intensity_zmin
  b = intensity_zmax
  nz = imp.getNSlices()
  for iz in range(1, nz + 1):
    ip_out = stack.getProcessor(iz).duplicate()
    correction = (a+b)/2 * (1/(a-(a-b)*(iz-1)/(nz-1)))
    #print iz, correction
    ip_out.multiply(correction) 
    stack_out.addSlice(str(iz), ip_out)
    #segip.invert()
  return ImagePlus("Attenuation_corrected", stack_out)

@StepMaker()
def measureSumIntensity3D(imp):
  stats = StackStatistics(imp)
  return stats.mean * stats.pixelCount

@StepMaker()
def auto_threshold(imp, method):
  impout = imp.duplicate() 
  IJ.run(impout, "Auto Threshold", "method=" + method + " white stack use_stack_histogram");
  impout.setTitle("Auto_threshold")
  impout.hide()
  return impout
  
@StepMaker()
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
