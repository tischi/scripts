/////////////////////////////////////////////////////////
// Extraction of biologically relevant parameters (6) //
//////////////////////////////////////////////////////////

// Needs the following tables and images:
// Table: Skeleton Results
// Image: BinarizedTubes.tif

um = getInfo("micrometer.abbreviation");

// Total vessel length
IJ.renameResults("Skeleton Results", "Results"); // make table accessible
totalLength = 0;
nBranches = 0;
for(i=0; i<nResults; i++) {
	totalLength = totalLength + getResult("# Branches", i)*getResult("Average Branch Length", i);
	nBranches = nBranches + getResult("# Branches", i);	
}
IJ.renameResults("Results","Skeleton Results"); // prevent table from being overwritten 

// Total imaged volume
selectWindow("BinarizedTubes.tif"); // image containing the segmented vessels
getVoxelSize(width, height, depth, unit);
totalImagedVolume = getWidth()*width*getHeight()*height*nSlices*depth;

// Total vessel volume
selectWindow("BinarizedTubes.tif"); // select the image containing the segmented vessels
run("3D Objects Counter", "threshold=128 min.=0 max.=4000000 statistics summary");
IJ.renameResults("Statistics for BinarizedTubes.tif", "Results");
for(i=0; i<nResults; i++) totalVolume = totalVolume + getResult("Volume ("+um+"^3)", i);
IJ.renameResults("Results","Binarized Tubes Results"); // store it

// Mean vessel x-section and diameter
meanCrosssection = totalVolume / totalLength;
meanDiameter = 2*sqrt(meanCrosssection/PI);

print("");
print("");
print("Results");
print("----------");
print("Pruning = " + d2s(PruneEnds,0));
print("Total length = " + d2s(totalLength,2) + " " + um);
print("Number of branches = " + d2s(nBranches,0) ); 
print("Average branch length = " + d2s(totalLength/nBranches,2) + " " + um); 
print("Mean vessel cross-section = " + d2s(meanCrosssection,2) + " " + um + "^2");
print("Mean vessel diameter = " + d2s(meanDiameter,2) + " " + um);
print("Total vessel volume = " + d2s(totalVolume,2) + " " + um + "^3" );
print("Total imaged volume = " + d2s(totalImagedVolume,2) + " " + um + "^3");
print("Volume fraction occupied by vessels = " + d2s(totalVolume/totalImagedVolume,2) );

