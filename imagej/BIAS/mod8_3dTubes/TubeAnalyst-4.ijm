//////////////////////////////////////////////////////
// Skeletonization/analysis of tubular network (4) //
//////////////////////////////////////////////////////

// Work on the label mask
selectImage("LabelMask.tif");

// Parameters
VisualisationDilation = 2 // units: pixels

// Make binary image
run("Duplicate...", "title=BinarizedTubes.tif duplicate"); // work on duplicate
run("8-bit");
setThreshold(1,255);
run("Convert to Mask", "method=Default background=Dark");

// Skeletonize
run("Duplicate...", "title=Skeleton duplicate"); // work on duplicate
run("Skeletonize (2D/3D)");
rename("Skeleton.tif");

// Remove end-point branches by pruning
if(PruneEnds) run("Analyze Skeleton (2D/3D)", "prune=none prune"); // no circular pruning, but end-point pruning
else run("Analyze Skeleton (2D/3D)", "prune=none"); // no circular pruning, no end-point pruning
IJ.renameResults("Results","Skeleton Results"); // rename results table for preventing it from being overwritten by other "Results"

// Beautify the visualisation:
// 1. Change analyzed skeleton colors
run("Macro...", "code=v=(v==127)*127+(v==30)*192+(v==70)*255 stack");
// 2. Thicken analyzed skeleton
run("3D Fast Filters","filter=Maximum radius_x_pix="+d2s(VisualisationDilation,0)+" radius_y_pix="+d2s(VisualisationDilation,0)+" radius_z_pix="+d2s(VisualisationDilation,0)+" Nb_cpus="+d2s(Nthreads,0));
// 3. Change the LUT
run("Fire");
rename("ThickSkeleton.tif"); 