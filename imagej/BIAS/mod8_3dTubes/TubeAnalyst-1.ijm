////////////////////
// Initialization //
////////////////////

run("Options...", "iterations=1 count=1 edm=Overwrite");
OriginalTitle = getTitle();

/////////////////////////////////////////////////////
// Morphological closing of tubular structures (1) //
/////////////////////////////////////////////////////

// Work on the small image "BloodVessels_small.tif";

// Parameters
ClosingRadius = 3 // units: micrometer
Nthreads = 8 // units: count

// Filtering: closing to fill hollow tubes
getPixelSize(unit, px, py, pz);
run("3D Fast Filters","filter=Maximum radius_x_pix="+d2s(ClosingRadius/px,2)+" radius_y_pix="+d2s(ClosingRadius/py,2)+" radius_z_pix="+d2s(ClosingRadius/pz,2)+" Nb_cpus="+d2s(Nthreads,0));
rename("Maximum");
run("3D Fast Filters","filter=Minimum radius_x_pix="+d2s(ClosingRadius/px,2)+" radius_y_pix="+d2s(ClosingRadius/py,2)+" radius_z_pix="+d2s(ClosingRadius/pz,2)+" Nb_cpus="+d2s(Nthreads,0));

// Alternative code: does the same as above but in one step 
// run("3D Fast Filters","filter=CloseGray radius_x_pix="+d2s(ClosingRadius,2)+" radius_y_pix="+d2s(ClosingRadius,2)+" radius_z_pix="+d2s(ClosingRadius,2)+" Nb_cpus="+d2s(Nthreads,0));

rename("Closed.tif"); // we add suffix ".tif" because otherwise ImageJ adds it upon saving resulting in inconsistent image names
