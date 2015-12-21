
imageSources = newArray("LSM780 VB Macro","Single File","All .lsm files in one directory"); 

Dialog.create("Online Spot detection");
Dialog.addChoice("Image source:",imageSources);
Dialog.addCheckbox("Save documentation images", true);
Dialog.addNumber("Area min (pixels)", 5);
Dialog.addNumber("Area max (pixels)", 20);
Dialog.addNumber("Next spot distance min (pixels)", 15);
Dialog.addNumber("Next spot distance max (pixels)", 200);
Dialog.addNumber("Intensity min", 120);
Dialog.addNumber("Intensity max", 230);
Dialog.addNumber("Image center distance min", 0);
Dialog.addNumber("Image center distance max", 220);
Dialog.addNumber("Neighborhood intensity min", 5);
Dialog.addNumber("Neighborhood intensity max", 100);
Dialog.show;

imageSource = Dialog.getChoice();
saveDocu =  Dialog.getCheckbox();
eres_size_min = Dialog.getNumber();
eres_size_max = Dialog.getNumber();
eres_dist_min =  Dialog.getNumber();
eres_dist_max =  Dialog.getNumber();
eres_intens_min = Dialog.getNumber();
eres_intens_max = Dialog.getNumber();
eres_imCenterDist_min = Dialog.getNumber();
eres_imCenterDist_max = Dialog.getNumber();
eres_nb_min = Dialog.getNumber();
eres_nb_max = Dialog.getNumber();


if(imageSource == "Single File") {
	
	// choose 
	path = File.openDialog("Choose image file...") ;

	//open
	run("Close all forced");
	open(path);

	// analyse
	findBestSpot(eres_size_min, eres_size_max, eres_dist_min, eres_dist_max, eres_intens_min, eres_intens_max, eres_imCenterDist_min, eres_imCenterDist_max, eres_nb_min, eres_nb_max);
	
	// save documentation image
	if(saveDocu) {
		saveDocumentationImage(path);
	}
		
}

if(imageSource == "All .lsm files in one directory") {
	dir = getDirectory("");
	list = getFileList(dir);
	for (i = 0; i < list.length; i++) {
		if (endsWith(list[i], ".lsm")) {
			run("Close all forced");
			path = dir+list[i];
			print(path);
			open(path);
			findBestSpot(eres_size_min, eres_size_max, eres_dist_min, eres_dist_max, eres_intens_min, eres_intens_max, eres_imCenterDist_min, eres_imCenterDist_max, eres_nb_min, eres_nb_max);
			if(saveDocu) {
				saveDocumentationImage(path);
			}
		}
	}
	run("Close all forced");
}


if(imageSource == "LSM780 VB Macro") {
	do {
		
		run("Close all forced");
	
		run("Microscope Communicator", "microscope=[LSM780] action=[obtain image] command=[do nothing]");
		path = getInfo("image.directory")+File.separator+getInfo("image.filename");
		findBestSpot(eres_size_min, eres_size_max, eres_dist_min, eres_dist_max, eres_intens_min, eres_intens_max, eres_imCenterDist_min, eres_imCenterDist_max, eres_nb_min, eres_nb_max);
		wait(100);
		
		makeOval(112, 95, 20, 15);
		
		// report result back to microscope
		if (selectionType() > -1) {
			run("Microscope Communicator", "microscope=[LSM780] action=[submit command] command=[image selected particle] object_x=0 object_y=0");
		} else {
			run("Microscope Communicator", "microscope=[LSM780] action=[submit command] command=[do nothing] object_x=0 object_y=0");
		}

		// save documentation image
		if(saveDocu) {
			saveDocumentationImage(path);
		}
		wait(500);
	} while (1);

}

function saveDocumentationImage(path) {

	selectWindow("raw");
	if (selectionType() > -1) {	
		// mark best ERES in the image
		run("Enlarge...", "enlarge=5");
		setForegroundColor(255, 255, 255); run("Line Width...", "line=1"); run("Draw");
	} 

	//run("Make Montage...", "columns=2 rows=1 scale=1 first=1 last=2 increment=1 border=0 font=12");
	saveAs("PNG",path+"--docu.png");

}


function findBestSpot(eres_size_min, eres_size_max, eres_dist_min, eres_dist_max, eres_intens_min, eres_intens_max, eres_imCenterDist_min, eres_imCenterDist_max, eres_nb_min, eres_nb_max) {
	
	//run("Microscope Communicator", "microscope="+microscope+" action=[obtain image] command=[do nothing]");
	run("Properties...", "unit=pix pixel_width=1 pixel_height=1 voxel_depth=1 origin=0,0");
	rename("raw"); 
	
	// extract images
	//selectWindow("raw"); run("Duplicate...", "title=nuclei");
	//selectWindow("raw"); run("Next Slice [>]"); run("Duplicate...", "title=eres");
	
	selectWindow("raw"); run("Duplicate...", "title=eres");
	//selectWindow("raw"); run("Next Slice [>]"); run("Duplicate...", "title=trans");
	
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
	run("Analyze Particles...", "size="+eres_size_min+"-"+eres_size_max+" pixel circularity=0.00-1.00 show=Masks exclude clear add");
	rename("ERES_Masks");
	
	//  eres intensity and center 
	selectWindow("gs");
	run("Set Measurements...", "min center area redirect=None decimal=2");
	roiManager("Deselect"); run("Clear Results"); roiManager("Measure");
	
	// FILTER: minimal neighbor distance
	run("Measure nearest neighbour distance");
	run("Filter particles", "filter=threshold measurement=nn_distance threshold_min="+eres_dist_min+" threshold_max="+eres_dist_max);
	
	// FILTER: intensities
	run("Filter particles", "filter=threshold measurement=Max threshold_min="+eres_intens_min+" threshold_max="+eres_intens_max);
	
	// FILTER: minimal image center distance
	run("Measure image center distance");
	run("Filter particles", "filter=threshold measurement=imCenter_distance threshold_min="+eres_imCenterDist_min+" threshold_max="+eres_imCenterDist_max);
	
	
	// FILTER: unidentified objects in neighbourhood
	// eres max neighborhood intensity
	// determine max ERES neighborhood intensity
	selectWindow("ERES_Masks"); run("Dilate"); run("Dilate"); run("Invert"); run("Divide...", "value=255");
	imageCalculator("Multiply create", "gs","ERES_Masks");
	run("Gray Morphology", "radius="+eres_dist_min+" type=circle operator=[fast dilate]");
	rename("ERES_Neighborhood");
	roiManager("Deselect"); run("Clear Results"); roiManager("Measure");
	
	
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
	
	selectWindow("raw");  //run("Previous Slice [<]"); 
	// todo: run this once with a random, rather than the brightest particle
	//run("Select None"); run("Select best particle", "filter=max measurement=Max threshold_min=0 threshold_max=0");
	run("Select None"); run("Select best particle", "filter=random measurement=Max threshold_min=0 threshold_max=0");

}

