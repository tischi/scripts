//////////////////////////////////
// Graphical user interface (7) //
//////////////////////////////////

Dialog.create("TubeAnalyst");
Dialog.addNumber("Tube radius (micrometer)", 6);
Dialog.addNumber("Vessel radius (micrometer)", 8);
Dialog.addNumber("Vessel threshold", 8); //-1: man. calibration  
Dialog.addNumber("Minimal Vessel Volume (pixels)", 1000);
Dialog.addNumber("Dilate Skeleton for viewing by (pixels)", 2);
Dialog.addNumber("Number of threads", 8);
Dialog.show;

ClosingRadius = Dialog.getNumber();
VesselRadius = Dialog.getNumber();  
VesselThreshold = Dialog.getNumber();
VesselVolumeThreshold = Dialog.getNumber();
VisualisationDilation = Dialog.getNumber();
