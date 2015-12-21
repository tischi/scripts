// LSM780 1024x1024 zoom1 63x
microscope = "LSM780"; //"File system" //"LSM780"
nuc_size_min = "8000";
cell_intens_min = "5";
cell_intens_max = "20";
// LSM510


do {

//dir = getDirectory("Choose a Directory ");
//list = getFileList(dir);
//for (i = 0; i < list.length; i++) {
	//print(list[i]);

//if (endsWith(list[i], ".lsm")) {	

run("Close all forced");

//open(dir+list[i]);
//run("Microscope Communicator", "microscope=[File system] action=[obtain image] command=[do nothing] choose=Z:/ALMF_poster/ASCB2011_Tischi/ERES_FRAP/2012-11-21--63x-oil--96well_11wells_4x4pos--FRAP--noTreat/noTreat--W00001--P00016--T00001.lsm");
run("Microscope Communicator", "microscope=["+microscope+"] action=[obtain image] command=[do nothing]");
path = getInfo("image.directory")+File.separator+getInfo("image.filename");

//run("Microscope Communicator", "microscope="+microscope+" action=[obtain image] command=[do nothing]");
run("Properties...", "unit=pix pixel_width=1 pixel_height=1 voxel_depth=1 origin=0,0");
rename("raw"); 

// extract images
//selectWindow("raw"); run("Duplicate...", "title=nuclei");
//selectWindow("raw"); run("Next Slice [>]"); run("Duplicate...", "title=eres");

selectWindow("raw"); run("Duplicate...", "title=eres");
selectWindow("raw"); run("Next Slice [>]"); run("Duplicate...", "title=trans");

// enhance ERES
selectWindow("eres");
run("Duplicate...", "title=gs");
run("Gaussian Blur...", "sigma=0.5 scaled");
//selectWindow("eres");
//run("Duplicate...", "title=gb");
//run("Gaussian Blur...", "sigma=10 scaled");
//imageCalculator("Subtract", "gs","gb"); rename("gaussian diff");

// threshold ERES
selectWindow("gs"); run("Duplicate...", "title=gs_bw");
run("Auto Local Threshold", "method=Niblack radius=20 parameter_1=5.0 parameter_2=0 white");
run("Convert to Mask");

// segment ERES
eres_size_min = "5";
eres_size_max = "20";
run("Analyze Particles...", "size="+eres_size_min+"-"+eres_size_max+" pixel circularity=0.00-1.00 show=Masks exclude clear add");
rename("ERES_Masks");

//  eres intensity and center 
selectWindow("gs");
run("Set Measurements...", "min center area redirect=None decimal=2");
roiManager("Deselect"); run("Clear Results"); roiManager("Measure");

// FILTER: minimal neighbor distance
run("Measure nearest neighbour distance");
eres_dist_min =  "15";
eres_dist_max =  "200";
run("Filter particles", "filter=threshold measurement=nn_distance threshold_min="+eres_dist_min+" threshold_max="+eres_dist_max);

// FILTER: intensities
eres_intens_min = "120";
eres_intens_max = "230";
run("Filter particles", "filter=threshold measurement=Max threshold_min="+eres_intens_min+" threshold_max="+eres_intens_max);

// FILTER: minimal image center distance
run("Measure image center distance");
eres_imCenterDist_min = 0;
eres_imCenterDist_max = 220;
run("Filter particles", "filter=threshold measurement=imCenter_distance threshold_min="+eres_imCenterDist_min+" threshold_max="+eres_imCenterDist_max);


// FILTER: unidentified objects in neighbourhood
// eres max neighborhood intensity
// determine max ERES neighborhood intensity
selectWindow("ERES_Masks"); run("Dilate"); run("Dilate"); run("Invert"); run("Divide...", "value=255");
imageCalculator("Multiply create", "gs","ERES_Masks");
run("Gray Morphology", "radius="+eres_dist_min+" type=circle operator=[fast dilate]");
rename("ERES_Neighborhood");
roiManager("Deselect"); run("Clear Results"); roiManager("Measure");

eres_nb_min = "5";
eres_nb_max = "100"; // 25
run("Filter particles", "filter=threshold measurement=Max threshold_min="+eres_nb_min+" threshold_max="+eres_nb_max);


// prepare documentation
//selectWindow("raw"); run("Previous Slice [<]"); 
//run("Make Composite");
//run("Blue");


// select valid eres that is closest to the image center 
//run("Measure image center distance");
//run("Select None"); run("Select best particle", "filter=min measurement=imCenter_distance threshold_min=0 threshold_max=0");

//  eres intensity and center 
selectWindow("gs");
run("Set Measurements...", "min center area redirect=None decimal=2");
roiManager("Deselect"); run("Clear Results"); roiManager("Measure");

selectWindow("raw");  run("Previous Slice [<]"); 
// todo: run this once with a random, rather than the brightest particle
//run("Select None"); run("Select best particle", "filter=max measurement=Max threshold_min=0 threshold_max=0");
run("Select None"); run("Select best particle", "filter=random measurement=Max threshold_min=0 threshold_max=0");

wait(100);


if (selectionType() > -1) {
	run("Microscope Communicator", "microscope=["+microscope+"] action=[submit command] command=[image selected particle] object_x=0 object_y=0");
} else {
	run("Microscope Communicator", "microscope=["+microscope+"] action=[submit command] command=[do nothing] object_x=0 object_y=0");
}

selectWindow("raw");
if (selectionType() > -1) {	
	// mark best ERES in the image
	run("Enlarge...", "enlarge=5");
	setForegroundColor(255, 255, 255); run("Line Width...", "line=1"); run("Draw", "stack");
} 

// save docu also if there is no best particle
run("Make Montage...", "columns=2 rows=1 scale=1 first=1 last=2 increment=1 border=0 font=12");
saveAs("PNG",path+"--docu.png");


wait(500);
//}
//}
	
} while (1);
