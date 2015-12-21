// global variables
var saveDocu = true;
var eres_size_min = 5;
var eres_size_max = 20;
var eres_dist_min =  15;
var eres_dist_max =  200;
var eres_intens_min = 120;
var eres_intens_max = 230;
var eres_imCenterDist_min = 0;
var eres_imCenterDist_max = 220;
var eres_nb_min = 5;
var eres_nb_max = 100;
	
var imageSource;
var imgpath;


// find out whether we are called from the Microscope Communicator or directly
arg = getArgument();
print(arg);
if (lengthOf(arg)<2) {
	//gui
	print("gui");
	gui();
} else if ( endsWith(arg, ".lsm") && indexOf(arg,"HR")<0 ){
	print("auto");
	imageSource = "Microscope";
	imgpath = arg;
} else {
	imageSource = "None"; // do nothing
}


if(imageSource == "Single File") {
	
	// choose 
	imgpath = File.openDialog("Choose image file...") ;

	//open
	run("Close all forced");
	open(imgpath);

	// analyse
	findBestSpot(eres_size_min, eres_size_max, eres_dist_min, eres_dist_max, eres_intens_min, eres_intens_max, eres_imCenterDist_min, eres_imCenterDist_max, eres_nb_min, eres_nb_max);

	// print coordinates of best particle
	if (selectionType() > -1) {
		run("Measure"); // the selected particle is now the last in the results table
		print("measured position of best particle at:");
		print("x="+getResult("XM", nResults-1));
		print("y="+getResult("YM", nResults-1));
	} else {
		print("no particle found.")		
	}


	// save documentation image
	if(saveDocu) {
		createDocumentationImage(imgpath);
	}
		
}

if(imageSource == "All .lsm files in one directory") {
	dir = getDirectory("");
	list = getFileList(dir);
	for (i = 0; i < list.length; i++) {
		if (endsWith(list[i], ".lsm")) {
			run("Close all forced");
			imgpath = dir+list[i];
			print(imgpath);
			open(imgpath);
			findBestSpot(eres_size_min, eres_size_max, eres_dist_min, eres_dist_max, eres_intens_min, eres_intens_max, eres_imCenterDist_min, eres_imCenterDist_max, eres_nb_min, eres_nb_max);
			if(saveDocu) {
				createDocumentationImage(imgpath);
			}
		}
	}
	run("Close all forced");
}


if(imageSource == "Microscope") {	
	run("Close all forced");
	imgpath = arg;
	open(imgpath);
	findBestSpot(eres_size_min, eres_size_max, eres_dist_min, eres_dist_max, eres_intens_min, eres_intens_max, eres_imCenterDist_min, eres_imCenterDist_max, eres_nb_min, eres_nb_max);
	wait(100);
	
	// report result back to microscope  (bleach, nothing, image)
	if (selectionType() > -1) {
		submitCommandsToMicroscope("image");
	} else {
		submitCommandsToMicroscope("nothing");
	}

	// save documentation image
	if(saveDocu) {
		createDocumentationImage(imgpath);
	}
}



function gui() {

	imageSources = newArray("Single File","All .lsm files in one directory"); 
	
	Dialog.create("Online Spot detection");
	Dialog.addChoice("Image source:",imageSources);
	Dialog.addCheckbox("Save documentation images", true);
	Dialog.addNumber("Area min (pixels)", eres_size_min);
	Dialog.addNumber("Area max (pixels)", eres_size_max);
	Dialog.addNumber("Next spot distance min (pixels)", eres_dist_min);
	Dialog.addNumber("Next spot distance max (pixels)", eres_dist_max);
	Dialog.addNumber("IntensityMax min", eres_intens_min );
	Dialog.addNumber("IntensityMax max", eres_intens_max);
	Dialog.addNumber("Image center distance min", eres_imCenterDist_min);
	Dialog.addNumber("Image center distance max", eres_imCenterDist_max);
	Dialog.addNumber("Neighborhood intensity min", eres_nb_min);
	Dialog.addNumber("Neighborhood intensity max", eres_nb_max);
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
	
}


function submitCommandsToMicroscope(code) {

	run("Measure"); // the selected particle is now the last in the results table
	
	unit = "px";
	offsetX = round(getResult("XM", nResults-1));
	offsetY = round(getResult("YM", nResults-1));
	offsetZ = 0;
	
	run("Read Write Windows Registry", "action=write location=[HKCU\\SOFTWARE\\VB and VBA Program Settings\\OnlineImageAnalysis\\macro] key=unit value=["+ unit +"] windows=REG_SZ");
	run("Read Write Windows Registry", "action=write location=[HKCU\\SOFTWARE\\VB and VBA Program Settings\\OnlineImageAnalysis\\macro] key=offsetx value=["+ offsetX +"] windows=REG_SZ");
	run("Read Write Windows Registry", "action=write location=[HKCU\\SOFTWARE\\VB and VBA Program Settings\\OnlineImageAnalysis\\macro] key=offsety value=["+ offsetY +"] windows=REG_SZ");
	run("Read Write Windows Registry", "action=write location=[HKCU\\SOFTWARE\\VB and VBA Program Settings\\OnlineImageAnalysis\\macro] key=offsetz value=["+ offsetZ +"] windows=REG_SZ");
	run("Read Write Windows Registry", "action=write location=[HKCU\\SOFTWARE\\VB and VBA Program Settings\\OnlineImageAnalysis\\macro] key=fileAnalyzed value=["+ imgpath +"] windows=REG_SZ");
	run("Read Write Windows Registry", "action=write location=[HKCU\\SOFTWARE\\VB and VBA Program Settings\\OnlineImageAnalysis\\macro] key=roitype value=[circle] windows=REG_SZ");
	run("Read Write Windows Registry", "action=write location=[HKCU\\SOFTWARE\\VB and VBA Program Settings\\OnlineImageAnalysis\\macro] key=roiaim value=[bleach] windows=REG_SZ");
	run("Read Write Windows Registry", "action=write location=[HKCU\\SOFTWARE\\VB and VBA Program Settings\\OnlineImageAnalysis\\macro] key=roix value=[64, 68] windows=REG_SZ");
       	run("Read Write Windows Registry", "action=write location=[HKCU\\SOFTWARE\\VB and VBA Program Settings\\OnlineImageAnalysis\\macro] key=roiy value=[64, 68] windows=REG_SZ");
       	run("Read Write Windows Registry", "action=write location=[HKCU\\SOFTWARE\\VB and VBA Program Settings\\OnlineImageAnalysis\\macro] key=code value=["+ code +"] windows=REG_SZ");
	
}


function createDocumentationImage(path) {

	selectWindow("raw");
	if (selectionType() > -1) {	
		// mark best ERES in the image
		run("Enlarge...", "enlarge=5");
		setForegroundColor(255, 255, 255); run("Line Width...", "line=1"); run("Draw", "stack");
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
	
	//  eres intensity and center 
	selectWindow("gs");
	run("Set Measurements...", "min center area redirect=None decimal=2");
	roiManager("Deselect"); run("Clear Results"); roiManager("Measure");
	
	selectWindow("raw"); 
	// todo: run this once with a random, rather than the brightest particle
	//run("Select None"); run("Select best particle", "filter=max measurement=Max threshold_min=0 threshold_max=0");
	run("Select None"); run("Select best particle", "filter=random measurement=Max threshold_min=0 threshold_max=0");

}

