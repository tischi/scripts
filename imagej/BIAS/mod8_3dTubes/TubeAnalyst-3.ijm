////////////////////////////////////////////
// Segmentation of tubular structures (3) //
////////////////////////////////////////////

// Work on the image after tubeness filtering
selectImage("Tubeness.tif");

// Parameters
VesselThreshold = 8 // units: gray values
VesselVolumeThreshold = 1000 // units: voxels

// Convert the 32-bit Tubeness image to 8-bit for thresholding
Stack.getStatistics(voxelCount, mean, min, max);
setMinAndMax(min,max);
run("8-bit");

// Threshold
setThreshold(VesselThreshold,255);
run("Convert to Mask", "method=Default background=Dark"); 
setSlice(nSlices/2); // move to central slices (only for nice viewing)

// Find connected components, remove too small objects and apply Random LUT
run("3D Objects Counter", "threshold=128 min.="+d2s(VesselVolumeThreshold,2)+" max.="+d2s(nSlices*getWidth()*getHeight(),0)+" objects statistics summary");
run("Random"); // change LUT
