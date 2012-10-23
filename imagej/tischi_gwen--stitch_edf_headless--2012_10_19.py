from ij import IJ
from ij import ImageStack
from ij import ImagePlus
from ij.plugin import Duplicator
from ij.plugin import ImageCalculator
from ij.measure import Measurements

import Stitch_Image_Collection			
from edfgui import ExtendedDepthOfFieldHeadless
from edfgui import Parameters

import os, sys, shutil, commands

# /g/almf/software/bin2/fiji --headless -cp /g/almf/software/fiji_tischi/plugins/ /g/almf/software/scripts/imagej/tischi_gwen--stitch_edf_headless--2012_10_19.py /g/almf/group/ALMFstuff/Tischi/projects/GwendolynEich/data /g/almf/group/ALMFstuff/Tischi/projects/GwendolynEich/data--fiji-out Experiment-41- 7 7 18 18

#dirInRoot = "/Users/tischi/Documents/gwen/data/"
#dirInRoot = "/g/almf/group/ALMFstuff/Tischi/projects/GwendolynEich/data/"
#dirInRoot = "/Volumes/almf/group/ALMFstuff/Tischi/projects/GwendolynEich/data/"
#dirInRoot = "Z:/Tischi/projects/GwendolynEich/data/"


#def import_image_sequence_headless:
#stack = ImageStack()
#filelist = (get file name list, java File.getList or something )
#for file in filelist:
#   ip = IJ.openImage(file)
#   stack.addSlice(ip)
#imp = ImagePlus("imported", stack)
# return imp

	

#ps = 7; pe = 7;
#ts = 18; te = 18;

zs = 0; ze = 10;
stitching = 1; bandpass = 1;
combine_z = 1;
normalise_intensity_over_time = 0;

# cropping
xs = 50;
ys = 70; 
xe = 3600;
ye = 2600;
# ***************


def makeStitchingLayoutFile(jobdir):
	text = ["# Define the number of dimensions we are working on",
		"dim = 2",
		"",
		"# Define the image coordinates",
		"%s/rescaled_flipped_0001.tif; ; (0.0, 0.0)" % jobdir,
		"%s/rescaled_flipped_0002.tif; ; (-2.7149572, 848.9615)" % jobdir,
		"%s/rescaled_flipped_0003.tif; ; (1143.0209, 5.956549)" % jobdir,
		"%s/rescaled_flipped_0004.tif; ; (-19.02124, 1696.8993)" % jobdir,
		"%s/rescaled_flipped_0005.tif; ; (2283.501, 10.802994)" % jobdir,
		"%s/rescaled_flipped_0006.tif; ; (1134.7283, 854.1822)" % jobdir,
		"%s/rescaled_flipped_0007.tif; ; (1126.4774, 1703.0598)" % jobdir,
		"%s/rescaled_flipped_0008.tif; ; (2272.0295, 1709.6473)" % jobdir,
		"%s/rescaled_flipped_0009.tif; ; (2278.7786, 860.52997)" % jobdir,
		""]
        text = '\n'.join(text)
        text = text + '\n'

        # write the jobs to files
        layoutfilename = os.path.join(jobdir,"mainstitch.txt")
        layoutfile = file(layoutfilename, "w")
        layoutfile.write(text)
        layoutfile.close()
        return layoutfilename
        
        
def process(dirIn, dirOut, expName, ps, pe, ts, te):

	jobid = commands.getoutput("echo $PBS_JOBID").split('.')[0]
	print "job id: "+jobid
	jobdir = os.path.join("/tmp",str(jobid)+"_fiji")
	
	for p in range(ps,pe+1):
		
		pID = str(p);
		
		for t in range(ts,te+1):
			
			print "TIMEPOINT STARTING ***************"
				
			tID = "t"+str(t);
			print "time-point: "+tID;

			if os.path.isdir(jobdir):
				print "removing "+jobdir
				shutil.rmtree(jobdir)                
			print "creating "+jobdir
			os.mkdir(jobdir)
		
			if stitching:
				
				fileOut = "rescaled_flipped_";
					
				for z in range(zs,ze+1):
				
					zID = "z"+str(z);
					print "z-plane: "+zID;
					
					if bandpass:
		
						IJ.log("bandpass....")
				
						# load all images from same time point and same z-position
						fileID = expName+pID+"_b0"+tID+zID+"m.*";
						IJ.log("opening images: "+os.path.join(dirIn,fileID))
						IJ.run("Image Sequence...", "open=["+dirIn+"] starting=1 increment=1 scale=100 file=[] or=["+fileID+"] sort");
						#selectWindow("im-2012-0007_Position35.tif_Files");
						imp = IJ.getImage();
						#imp.show();
						
						
						imp.setTitle("Stack");
						
						# illumination correction
						IJ.log("computing FFT...");
						# run("Flip Horizontally", "stack");
						impFFT = Duplicator().run(imp);
						for i in range(1, impFFT.getNSlices()+1):
							print "FFT of slice "+str(i)
							impFFT.setSlice(i)
							IJ.run(impFFT, "Bandpass Filter...", "filter_large=10000 filter_small=200 suppress=None tolerance=5 ");
						#impFFT.show()
						
						stats = imp.getStatistics(Measurements.MEAN)
						IJ.log("stats.mean = "+str(stats.mean)); # this is only the mean of one slice...is this a problem?
						
						print "dividing image stack by FFT stack...";
						ic = ImageCalculator()
						impCorr = ic.run("Divide create 32-bit stack", imp, impFFT);
						#impCorr.show()
						
						print "multiplying by stats.mean for going back to 8 bit space..."
						stack = impCorr.getStack()
						for i in range(1, impFFT.getNSlices()+1):
							ip = stack.getProcessor(i).convertToFloat()
	    						ip.multiply(stats.mean)
	    						#stack.setSlice(stack.getSliceLabel(i), ip)
						
						IJ.log("converting from 32-bit to 8-bit...")
						IJ.setMinAndMax(impCorr, 0, 255);
						IJ.run(impCorr,"8-bit","");
						#IJ.saveAs(impCorr, "Tiff", "/Users/tischi/Documents/processed.tif");
						#ff
						#impCorr.show()
						
						# save images
						IJ.log("saving bandpass corrected image sequence: "+os.path.join(jobdir,fileOut))
						IJ.run(impCorr, "Image Sequence... ", "format=TIFF name=["+fileOut+"] start=1 digits=4 save=["+jobdir+"]");
						#impCorr.close(); imp.close(); impFFT.hide();
						
	
					# stitching
					IJ.log("STITCHING START **********")
					layoutFile = makeStitchingLayoutFile(jobdir)
					createPreview = 0
					computeOverlap = 0
					fusion_method="Linear Blending"
					handleRGB = "Red, Green and Blue"
					showImage = 0
					#fusion=1 regression=0.30 max/avg=2.50 absolute=3.50"
					st = Stitch_Image_Collection() 
					st.alpha = 1
					IJ.log("layout file ="+str(layoutFile))
					impStitched = st.work(layoutFile, createPreview, computeOverlap,  fusion_method,  handleRGB,  showImage) 
					stitchedFile = os.path.join(jobdir,tID+zID+"_stitched.tif");
					#impStitched.show()
					IJ.saveAs(impStitched,"Tiff", stitchedFile);
					IJ.log("STITCHING END **********")
					
			
			if combine_z:
			
				IJ.log("combine z.....")	
				
				#IJ.log("process id ="+subprocess.check_output("echo $$").strip())
				#IJ.run("Image Sequence...", "open=["+dirOut+"] file=[] or=.*flipped.* sort");
				#imp = IJ.getImage()
	
				#########
				IJ.log("load stitched images into a stack...")
				for z in range(zs,ze+1):
					zID = "z"+str(z);	
					stitchedFile = os.path.join(jobdir,tID+zID+"_stitched.tif");
					IJ.log("opening "+stitchedFile)
					imp = IJ.openImage(stitchedFile)
					if z==zs:
						stack = ImageStack(imp.width,imp.height)
					stack.addSlice(imp.getProcessor())
				imp = ImagePlus("stack", stack)
				#imp.show()
				########
				
				########
				IJ.log("cropping...")
				imp.setRoi(xs, ys, xe, ye);
				IJ.run(imp, "Crop", "");	
				#imp.show()
				########
				
				#IJ.log("normalise intensity of all slices...")
				
				#run("Set Slice...", "slice="+1);
		        	#run("Set Measurements...", "  mean redirect=None decimal=9");
				#run("Select None");
				#setBatchMode(true);
				#setMinAndMax(0, 255); run("32-bit");				
				#for(l=0; l<nSlices+1; l++) {
				##	run("Select All");
				#	run("Clear Results");
				#	run("Measure");
				#	picsum=getResult("Mean",0);
				#	//if(l==0){picsum1=picsum;}
				#	//int_ratio=picsum1/picsum;
				#	int_ratio=128/picsum;
				#	run("Select None");
				#	IJ.log("ratio ="+int_ratio);
				#	run("Multiply...", "slice value="+int_ratio);
				#	run("Next Slice [>]");
				#}
				#setBatchMode(false);
			
				# stop here and try by hand
				#...
				#dfgfd
				
				#//stack-reg
				#//IJ.log("register xy...")
				#//run("StackReg", "transformation=Translation");
				
				#// project into 1 plane ....
				#// run("Extended Depth of Field (Easy mode)...");
				#//run("Z Project...", "start=["+1+"] stop=["+ze+"] projection=[Standard Deviation]");
		
	
				doEDF = True
				if doEDF:
					IJ.log("EDF...start")
					parameters = Parameters()
					parameters.setQualitySettings(1)
					parameters.setTopologySettings(0)
					parameters.show3dView = False 
					parameters.showTopology = False
					edfh = ExtendedDepthOfFieldHeadless(imp, parameters)
					imp = edfh.processHeadless()
					IJ.log("EDF...done")
					#imp.show()
				
				
				#IJ.run(imp,"Extended Depth of Field (Easy mode)...", "quality='1' topology='0' show-view='on' show-topology='off'");
				#s=split(getImageInfo(),'\n'); IJ.log("current image: "+s[1]);
				#while(s[1]!="Title: Output") {
				#	wait(10000);
				#		s=split(getImageInfo(),'\n'); 
				#	IJ.log("waiting for Output Image EDOF; current image: "+s[1]);
				#}
				#
				#
				#
				
				edfFile = os.path.join(dirOut,expName+tID+"_EDOF_noTimeNorm.tif");
				IJ.log("EDF save: "+edfFile)			
				IJ.saveAs(imp,"Tiff", edfFile);
				IJ.log("EDF save: done.")
				#close(); // projection
				#close(); // stack

				print "TIMEPOINT FINISHED ***************"
				if os.path.isdir(jobdir):
					print "removing "+jobdir
					shutil.rmtree(jobdir)                
	

if __name__ == '__main__':

	if len(sys.argv) < 7:
		print "Usage: <dirIn> <dirOut> <expName> <ps> <pe> <ts> <te>"
		sys.exit(1)

	i = 1
	dirIn = sys.argv[i]; i=i+1
	dirOut = sys.argv[i]; i=i+1
	expName = sys.argv[i]; i=i+1
	ps = sys.argv[i]; i=i+1
	pe = sys.argv[i]; i=i+1
	ts = sys.argv[i]; i=i+1
	te = sys.argv[i]; i=i+1
	
	print "dirIn = "+dirIn
	print "dirOut = "+dirOut
	print "expName = "+expName
	print "ps = "+ps
	print "pe = "+pe
	print "ts = "+ts
	print "te = "+te
	
	process(dirIn, dirOut, expName, int(ps), int(pe), int(ts), int(te))

					