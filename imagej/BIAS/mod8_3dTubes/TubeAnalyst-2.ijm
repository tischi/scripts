/////////////////////////////////////////////////////
// Prefiltering to enhance filamentous voxels (2)  //
/////////////////////////////////////////////////////

// Work on the closed image
selectImage("Closed.tif");

// Parameters
VesselRadius = 8 // units: micrometer

run("Tubeness", "sigma="+d2s(VesselRadius,2)+" use");
rename("Tubeness.tif");
