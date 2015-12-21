from ij import ImagePlus
from ij.gui import ImageWindow
from ij.gui import NonBlockingGenericDialog

def showTup(temp_output):
	if (not isinstance(temp_output,tuple)):
		print "Output is not a tuple and therefore can not be displayed correctly"
		return False
	size = 300
	x = 50
	y = 300
	d = 50
	for el in temp_output:
		if (isinstance(el,ImagePlus)):
			print el.title
			iw = ImageWindow("")
			iw.setNextLocation(x,y) # todo: how to also fix the size?
			el.show()
			#iw = ImageWindow(el)
			#iw.setLocationAndSize(x,y,size,size)
			x = x + size + d
			
def hideTup(temp_output):
	if (not isinstance(temp_output,tuple)):
		print "Output is not a tuple"
		return False
	for el in temp_output:
		if (isinstance(el,ImagePlus)):
			print el.title
			el.hide()

def closeTup(temp_output):
	if (not isinstance(temp_output,tuple)):
		print "Output is not a tuple"
		return False
	for el in temp_output:
		if (isinstance(el,ImagePlus)):
			el.changes=False
			el.close()

def showGui(par,title):
	'''Updated version discriminates between string and numeric outputs to treat them accordingly'''
	numflags={}
	
	gd = NonBlockingGenericDialog(title)
	s_keys=sorted(par.keys())
	for nm in s_keys:
		if (isinstance(par[nm], (int,float, long))):
			gd.addNumericField(nm,par[nm],1)
			numflags[nm]=True
		else:
			gd.addStringField(nm,par[nm])
			numflags[nm]=False
	gd.setOKLabel("Go on!")
	gd.setCancelLabel("Recompute..")
	gd.centerDialog(False)
	gd.setLocation(50, 100) 
	gd.showDialog()

	if gd.wasCanceled():
		rep=True
	else:
		rep=False

	for nm in s_keys:
		if (numflags[nm]):
			par[nm] = gd.getNextNumber()
		else:
			par[nm] = gd.getNextString().encode('ascii','replace')
	return par,rep

def version():
	print "version"

def RunInteractive(func,kwargs):
	print "RunInteractive"
	
	if 'mpar' in kwargs:
		cpar=kwargs['mpar']
	else:
		cpar=func.func_defaults[0]
	
	while True:
		# execute function
		print func.__name__, cpar
		kwargs['mpar']=cpar
		
		temp_out=func(**kwargs)         #This line is actually one that runs the analysis

		# repetition handling
		showTup(temp_out)
		cpar, repeat = showGui(par=cpar,title=func.__name__)
		if repeat:
			closeTup(temp_out)
		else:
			hideTup(temp_out)
			return temp_out

def StepMaker():
	def StepReader(func):		
		def MakeStep(*args, **kwargs):
			if '_gui' in kwargs:
				gui = kwargs['_gui']
			else: 
				gui = False
			
			if (gui == True):
				return RunInteractive(func,kwargs)
			else:	
				return func(**kwargs)
				
		return MakeStep
	return StepReader


# interesting commands:
#from ij import WindowManager as WM
#volume = WM.getImage("stack.tif")
#mask = WM.getImage("mask.tif")
#mask2 = mask.duplicate() 

from ij import IJ, ImagePlus, ImageStack
from ij.plugin import Duplicator
from ij.process import StackStatistics
from ij.plugin import ImageCalculator
#from InteractiveWorkflowGenerator_20150305 import StepMaker
import time

gui = True
 
def extractChannel(imp, nChannel, nFrame):
  """ Extract a stack for a specific color channel and time frame """
  stack = imp.getImageStack()
  ch = ImageStack(imp.width, imp.height)
  for i in range(1, imp.getNSlices() + 1):
    index = imp.getStackIndex(nChannel, i, nFrame)
    ch.addSlice(str(i), stack.getProcessor(index))
  return ImagePlus("Channel " + str(nChannel), ch)

@StepMaker()
def MakeIsotropic(_imp, mpar={'method':'reduce_xy'}, _gui=False):
  print "MakeIsotropic:"
  print "input image:",_imp.title
  dx = _imp.getCalibration().pixelWidth
  dy = _imp.getCalibration().pixelHeight
  dz = _imp.getCalibration().pixelDepth
  
  if mpar['method'] == 'reduce_xy':
    scale = dx/dz
    print "scale:",scale
    IJ.run(_imp, "Scale...", "x=%s y=%s z=1.0 interpolation=Bilinear average create title=[isotropic]" % (scale,scale));
  
  impIso = IJ.getImage()
  print "Input image calibration:",_imp.getCalibration()
  print "Isotropic image calibration:",impIso.getCalibration()
  impIso.hide()
  return impIso,
    

@StepMaker()
def Smooth(_img, mpar={'width':1}, _gui=False):
  imp = Duplicator().run(_img)
  #imp.show()
  print "sigma=%s" % mpar['width']
  IJ.run(imp, "Gaussian Blur...", "sigma=%s stack" % mpar['width'])
  #imp = IJ.getImage();
  imp.setTitle("Smooth"); 
  #imp.hide()
  return imp,

@StepMaker()
def Threshold(_img, mpar={'threshold':15}, _gui=False):
  print "Threshold"
  imp = Duplicator().run(_img)
  #imp.show(); time.sleep(0.2)
  #IJ.setThreshold(imp, mpar['lthr'], mpar['uthr'])
  IJ.setThreshold(imp, mpar['threshold'], 1000000000)
  IJ.run(imp, "Convert to Mask", "stack")
  imp.setTitle("Threshold");
  #IJ.run(imp, "Divide...", "value=255 stack");
  #IJ.setMinAndMax(imp, 0, 1);
  return imp,_img.duplicate()

@StepMaker()
def DistanceMap(_img, mpar={}, _gui=False):
  imp = Duplicator().run(_img)
  IJ.run(imp, "Exact Euclidean Distance Transform (3D)", "");
  imp = IJ.getImage();
  IJ.setMinAndMax(imp, 0, 65535);
  IJ.run(imp, "16-bit", "");
  imp.setTitle("DistanceMap") 
  imp.hide()
  return imp,

def Make16bit_UsingMinMax(_imp):
  imp = _imp.duplicate()
  stats = StackStatistics(imp)
  IJ.setMinAndMax(imp, stats.min, stats.max);
  IJ.run(imp, "16-bit", "");
  IJ.setMinAndMax(imp, 0, 65535);
  return imp


def Make8bit_UsingMinMax(_imp):
  imp = _imp.duplicate()
  stats = StackStatistics(imp)
  IJ.setMinAndMax(imp, stats.min, stats.max);
  IJ.run(imp, "8-bit", "");
  IJ.setMinAndMax(imp, 0, 255);
  return imp


@StepMaker()
def Laplacian(_img, mpar={'scale':2}, _gui=False):
  _img.show(); time.sleep(0.2)
  IJ.run("FeatureJ Laplacian", "compute smoothing=%s" % str(mpar['scale']))
  imp = IJ.getImage()
  IJ.run(imp, "Multiply...", "value=-1 stack")
  imp.setTitle("Laplacian")
  imp.hide()
  _img.hide()
  return imp,

@StepMaker()
def Objects3D(_img, impRedirect, mpar={'vmin':2,'vmax':100000}, _gui=False):
  print "Objects3D:"
  _img.show(); 
  impRedirect.show()
  options = "mean_gray_value centroid dots_size=5 font_size=10 show_numbers white_numbers store_results_within_a_table_named_after_the_image_(macro_friendly) redirect_to=[%s]" % impRedirect.title
  #print options
  print "image: " + _img.title
  print "redirect to: " + impRedirect.title
  IJ.run("3D OC Options",  options)
  IJ.run(_img, "3D Objects Counter", "threshold=128 slice=35 min.=%s max.=%s surfaces statistics summary" % (mpar['vmin'],mpar['vmax']));
  impObjects = IJ.getImage()
  IJ.run(impObjects, "16 colors", "")
  # somehow find the number of objects detected and set the LUT
  IJ.setMinAndMax(impObjects, 0, 2)
  impObjects.hide()
  _img.hide()
  impRedirect.hide()
  return impObjects,

def showTogether(imp1, imp2):
  imp1.show()
  imp2.show()
  imp = imp1.duplicate()
  IJ.run(imp, "Merge Channels...", "c1=[%s] c2=[%s] create" % (imp1.title, imp2.title));
  #IJ.run("Channels Tool...", "");
  imp1.hide()
  imp2.hide()


def Multiply(imp1,imp2):
  ic = ImageCalculator();
  imp = ic.run("Multiply create stack", imp1, imp2)
  stats = StackStatistics(imp)
  IJ.setMinAndMax(imp, stats.min, stats.max);
  print stats
  imp.setTitle("Multiply")
  imp.show()
  return imp

def Make16bitMask(_imp):
  imp = _imp.duplicate()
  IJ.run(imp, "16-bit", "");
  stats = StackStatistics(imp)
  IJ.run(imp, "Divide...", "value=%s stack" % stats.max);
  imp.setTitle("16-bit mask")
  imp.show()
  return imp

@StepMaker()
def AutoLocalThreshold(_imp, mpar={'radius':2,'threshold':100000}, _gui=False):
  imp = _imp.duplicate() 
  IJ.run(imp, "Auto Local Threshold", "method=Niblack radius=%s parameter_1=%s parameter_2=0 white stack" % (mpar['radius'], mpar['threshold']));
  imp.setTitle("AutoLocalThreshold")
  return imp, _imp.duplicate()


@StepMaker()
def AutoThreshold(_imp, mpar={'method':'Li'}, _gui=False):
  imp = _imp.duplicate() 
  IJ.run(imp, "Auto Threshold", "method=Li white stack use_stack_histogram");
  imp.setTitle("Auto Threshold")
  return imp, _imp.duplicate()


  
impRaw = IJ.getImage();
dz = impRaw.getCalibration().pixelDepth
impIso, = MakeIsotropic(_imp = impRaw, mpar={'method':'reduce_xy'})

# auto-threshold the nucleus
# 
impNuc = extractChannel(impIso, 2, 1)
impNucSmooth, = Smooth(_img = impNuc, mpar={'width': 1}, _gui=False)
#impNucBW, impTmp = Threshold(_img = impNucSmooth, mpar={'threshold':15}, _gui=True)
impNucBW, impTmp = AutoThreshold(_imp = impNucSmooth, mpar={'method':'Li'}, _gui=False)

impDist, = DistanceMap(_img = impNucBW)
impNucleusOutline, = Objects3D(_img = impNucBW, impRedirect= impDist, mpar={'vmin':500,'vmax':1000000}, _gui=False)

## multiplication of 8-bit with 32-bit?
## conversion of 0,1 8-bit to 32-bit?
impSpots = extractChannel(impIso, 1, 1)
impSpotsLoG, = Laplacian(_img = impSpots, mpar={'scale':1}, _gui=False)
imp8SpotsLoG = Make8bit_UsingMinMax(impSpotsLoG)

impSpotsBW, impTmp = AutoLocalThreshold(_imp = imp8SpotsLoG , mpar = {'radius':11,'threshold':6}, _gui=False)
impSpotsBW = Multiply(impSpotsBW, impNucBW)

# mupltiply with nucleus mask
#imp16NucBW = Make16bitMask(impNucBW)
#imp16SpotsLoGNucMask = Multiply(imp16SpotsLoG, imp16NucBW)

#impSpotsBW, impTmp = Threshold(_img = impSpotsLoG, mpar={'threshold':22}, _gui=True)
impSpotOutlines, = Objects3D(_img = impSpotsBW, impRedirect = impDist, mpar={'vmin':3,'vmax':1000000}, _gui=False)

showTogether(impSpots,impSpotOutlines)
showTogether(impNuc,impNucleusOutline)

print ""
print "*******"
print "Please multiply the Mean values in the table by ", dz
print "*******"

		
# ideas:
# - could get masked image from object counter; threshold it with particle number and set bg pixles NaN
# - ..multiply the thresholded image onto the target image and measure statistics (this will be slow)

# todo:
# - implement making isotropic with two options: enlarge z, shrink xy
# - find a robust way of thresholding the spots (take statistics of LoG filter in nucleus
# - can we tell each function "at runtime", i.e. with a function parameter whether to run with gui or not?

# Talk to Ziggi:
# - papers about robust statistics
# -


# Talk to Jan:
# - quantification of molecules on a small structure
# -

# check papers:
# - A general illumination correction method, Horvath, Nature Mathods

# Peter Horvath:
# - segmentation of overlapping cells (nice algorithm)
# - DIC inverse was already published (the Guy from the US)
# - read his papers
