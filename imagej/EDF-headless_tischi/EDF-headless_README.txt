add the edfgui folder into your plugins directory


--- usage in jython:


from edfgui import ExtendedDepthOfFieldHeadless
from edfgui import Parameters

IJ.log("EDF...start")
parameters = Parameters()
parameters.setQualitySettings(1)
parameters.setTopologySettings(0)
parameters.show3dView = False 
parameters.showTopology = False
edfh = ExtendedDepthOfFieldHeadless(imp, parameters)
imp = edfh.processHeadless()
IJ.log("EDF...done")