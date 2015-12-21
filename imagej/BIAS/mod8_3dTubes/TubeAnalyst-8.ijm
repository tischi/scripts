///////////////////////////////////
// 3-D results visualisation (8) //
///////////////////////////////////

// Merge original stack and skeleton 
selectImage("Skeleton.tif");
run("Invert LUT");
run("Merge Channels...", "c1=*None* c2=Skeleton.tif c3="+OriginalTitle+" create keep");
run("Channels Tool...");

// Load original stack, label mask and analyzed skeleton in 3D viewer
run("3D Viewer");
call("ij3d.ImageJ3DViewer.setCoordinateSystem", "false");
call("ij3d.ImageJ3DViewer.add", OriginalTitle, "None", OriginalTitle, "0", "true", "true", "true", "2", "0");
call("ij3d.ImageJ3DViewer.add", "LabelMask.tif", "None", "LabelMask.tif", "0", "true", "true", "true", "2", "0");
call("ij3d.ImageJ3DViewer.add", "ThickSkeleton.tif", "None", "ThickSkeleton.tif", "0", "true", "true", "true", "2", "0");
call("ij3d.ImageJ3DViewer.startAnimate");