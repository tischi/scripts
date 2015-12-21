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

check = False;

def makeStitchingLayoutFile(jobdir):
	text = ["# Define the number of dimensions we are working on",
		"dim = 2",
		"",
		"# Define the image coordinates",
		"%s/rescaled_flipped_0001.tif; ; (0.0, 0.0)" % jobdir,
		"%s/rescaled_flipped_0002.tif; ; (1285.8373, 6.911499)" % jobdir,
		"%s/rescaled_flipped_0003.tif; ; (2578.7954, 13.650116)" % jobdir,
		"%s/rescaled_flipped_0004.tif; ; (-3.8151245, 964.0991)" % jobdir,
		"%s/rescaled_flipped_0005.tif; ; (1282.6155, 970.9992)" % jobdir,
		"%s/rescaled_flipped_0006.tif; ; (2573.373, 978.29346)" % jobdir,
		"%s/rescaled_flipped_0007.tif; ; (-7.9190063, 1929.3987)" % jobdir,
		"%s/rescaled_flipped_0008.tif; ; (1277.9832, 1936.6804)" % jobdir,
		"%s/rescaled_flipped_0009.tif; ; (2568.67, 1943.9832)" % jobdir,
		""]
        text = '\n'.join(text)
        text = text + '\n'

        # write the jobs to files
        layoutfilename = os.path.join(jobdir,"mainstitch.txt")
        layoutfile = file(layoutfilename, "w")
        layoutfile.write(text)
        layoutfile.close()
        return layoutfilename
        

def copyStitchingLayoutFile(dirIn,expName,jobdir,p):
	layoutfilename = os.path.join(dirIn,"processed","mainstitch.txt")
	if expName == "Experiment-41-": 
		tmp = "mainstitch"+str(p)+".txt"
		layoutfilename = os.path.join("/g/almfscreen/Gwen/2012-08-16--tifs--mainstitch",tmp)		
		pathOld = "F:/2012-08-16--tifs/Experiment-41-"+str(p)+".tif_files/processed"
	elif expName == "Experiment-28-": 
		tmp = "mainstitch.txt"
		folder = "/g/almfscreen/Gwen/2012-08-14--tifs/Experiment-28-"+str(p)+".tif_files/processed/"
		layoutfilename = os.path.join(folder,tmp)		
		pathOld = "X:/Gwen/2012-08-14--tifs/Experiment-28-"+str(p)+".tif_files/processed"
		
	print "reading: "+layoutfilename
        
	f = open(layoutfilename, 'r')
	lines = f.readlines()
	f.close()
	
	pathNew = jobdir
	for i in range(len(lines)):
		lines[i] = lines[i].replace(pathOld,pathNew)
		#print lines[i]
        	
	# write the jobs to files
	layoutfilename = os.path.join(jobdir,"mainstitch.txt")
	print "writing: "+layoutfilename
	layoutfile = file(layoutfilename, "w")
	for line in lines:
		layoutfile.write(line)
	layoutfile.close()
	return layoutfilename


        
def process(dirIn, dirOut, expName, ps, pe, ts, te):

	
	jobid = commands.getoutput("echo $PBS_JOBID").split('.')[0]
	jobid = jobid.replace("[","_").replace("]","")  # because the jobids look like 2356385[1] which causes problems
	print "job id: "+jobid
	jobdir = os.path.join("/tmp",str(jobid)+"_fiji")
	print "job dir: "+jobdir
	
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
						
						#stats = imp.getStatistics(Measurements.MEAN)
						#IJ.log("stats.mean = "+str(stats.mean)); # this is only the mean of one slice...is this a problem?
						
						print "dividing image stack by FFT stack...";
						ic = ImageCalculator()
						impCorr = ic.run("Divide create 32-bit stack", imp, impFFT);
						#impCorr.show()

						def computeMean(pixels):
  							return sum(pixels) / float(len(pixels))
						
						print "multiplying each image by 128/mean for going back to 8 bit space..."
						stack = impCorr.getStack()
						for i in range(1, impCorr.getNSlices()+1):
							ip = stack.getProcessor(i).convertToFloat()
					 		mean = computeMean(ip.getPixels())
					 		print "multiplying slice "+str(i)+" by "+str(float(128/mean))
	    						ip.multiply(float(128/mean))
	    						
	    					
						IJ.log("converting from 32-bit to 8-bit...")
						IJ.setMinAndMax(impCorr, 0, 255);
						IJ.run(impCorr,"8-bit","");
						#IJ.saveAs(impCorr, "Tiff", "/Users/tischi/Documents/processed.tif");
						#ff
						#impCorr.show()
						
						# save images
						IJ.log("saving bandpass corrected image sequence: "+os.path.join(jobdir,fileOut))
						IJ.run(impCorr, "Image Sequence... ", "format=TIFF name=["+fileOut+"] start=1 digits=4 save=["+jobdir+"]");
						if check:
							IJ.run(impCorr, "Image Sequence... ", "format=TIFF name=["+fileOut+"] start=1 digits=4 save=["+dirOut+"]");
						#impCorr.close(); imp.close(); impFFT.hide();  
						
	
					# stitching
					IJ.log("STITCHING START **********")
					layoutFile = copyStitchingLayoutFile(dirIn,expName,jobdir,ps)
					###layoutFile = makeStitchingLayoutFile(jobdir)
					createPreview = 0
					computeOverlap = 0
					fusion_method="Linear Blending"
					handleRGB = "Red, Green and Blue"
					showImage = 0
					#fusion=1 regression=0.30 max/avg=2.50 absolute=3.50"
					st = Stitch_Image_Collection() 
					st.alpha = 1
					IJ.log("layout file: "+str(layoutFile))
					impStitched = st.work(layoutFile, createPreview, computeOverlap,  fusion_method,  handleRGB,  showImage) 
					stitchedFile = os.path.join(jobdir,tID+zID+"_stitched.tif");
					#impStitched.show()
					IJ.saveAs(impStitched,"Tiff", stitchedFile);
					if check: 
						print os.path.join(dirOut,tID+zID+"_stitched.tif")
						stitchedFile = os.path.join(dirOut,tID+zID+"_stitched.tif");
						IJ.saveAs(impStitched,"Tiff", stitchedFile);
					
					IJ.log("STITCHING END **********")
					
			
			if combine_z:
			
				IJ.log("combine z.....")	
				
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


				# the following normalisation should not be necessary, because they are already all 128/mean normalised
				#IJ.log("-- normalise intensity of all slices...")
				#stats = imp.getStatistics(Measurements.MEAN)
				#IJ.log("stats.mean = "+str(stats.mean)); # this is only the mean of one slice...is this a problem?		
				#stack = imp.getStack()
				#for i in range(1, impFFT.getNSlices()+1):
			 	#	ip = stack.getProcessor(i).convertToFloat()
	    		#	ip.multiply(128/stats.mean)
	    	    #		#stack.setSlice(stack.getSliceLabel(i), ip)
						
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
					IJ.log("EDF: start...")
					parameters = Parameters()
					parameters.setQualitySettings(1)
					parameters.setTopologySettings(0)
					parameters.show3dView = False 
					parameters.showTopology = False
					edfh = ExtendedDepthOfFieldHeadless(imp, parameters)
					imp = edfh.processHeadless()
					IJ.log("EDF: done.")
					#imp.show()
								
					IJ.log("EDF: converting from 32-bit to 8-bit...")
					IJ.setMinAndMax(imp, 0, 255);
					IJ.run(imp,"8-bit","");
							
					edfFile = os.path.join(dirOut,expName+pID+"-"+tID+"_EDOF_noTimeNorm.tif");
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

					