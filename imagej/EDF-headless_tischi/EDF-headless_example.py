from edfgui import ExtendedDepthOfFieldHeadless
from edfgui import Parameters

imp = IJ.openImage("http://imagej.nih.gov/ij/images/mri-stack.zip");

imp.show()  # remove for headless

IJ.log("EDF: start...")
parameters = Parameters()
parameters.setQualitySettings(1)
parameters.setTopologySettings(0)
parameters.show3dView = False 
parameters.showTopology = False
edfh = ExtendedDepthOfFieldHeadless(imp, parameters)
impedf = edfh.processHeadless()
IJ.log("EDF: done.")

impedf.show()   # remove for headless