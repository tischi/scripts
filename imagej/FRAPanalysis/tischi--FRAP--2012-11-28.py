from ij import IJ
from ij.plugin import Converter
from ij.gui import Plot
from loci.plugins import BF
from loci.plugins.in import ImporterOptions as IO

import time, os, shutil

# /g/almf/software/bin2/fiji --headless /g/almf/software/scripts/imagej/tischi--FRAP--2012-11-28.py

def txt_out(text):
	IJ.log(""+text)
	#IJ.log("\\Update"+line_number":"+text)
	

def getImps(fpath):
	opt = IO()
	opt.setId(fpath)
	opt.setOpenAllSeries(True) 
	impA = BF.openImagePlus(opt)
	print "Series number: " + str(len(impA))
	#impA = BF.openImagePlus()
	return impA

def splitLastFolder( path ):
  path,folder=os.path.split(path)
  if folder=="": # this is necessary when it was a 'direct' path, ending with /
    path,folder=os.path.split(path)
  return path,folder
  

def writeXYfile(x,y,filename,sep):
   f = open(filename, 'w')
   f.write("x%sy\n" % sep) # header
   for i in range(len(x)):
     text = "%f%s%f\n" % (float(x[i]),sep,float(y[i]))
     f.write(text)
   f.close()   
    


# todo: 
# -cluster!
# -multicore?

# issues: 
# the run away
# they split in two
# loss of focus in the last frames

# possible solutions: 
# concentrate on early recovery?


def process(dirIn, es, ee):

  
  roi_w = 30
  roi_h = 30
  iStart = 6-1
  
  #srcDir = DirectoryChooser("Choose directory").getDirectory()
  srcDir=dirIn
  
  if not srcDir:
    return

  destDir = srcDir+"--analysis"
  print "creating: "+destDir
  # destDir = srcDir
  if os.path.exists(destDir):
    shutil.rmtree(destDir)
    time.sleep(1)
  os.mkdir(destDir)
    
  # fileId = IJ.getString("filenames MUST contain:", "FRAP.lsm");
  fileId = "FRAP.lsm"
  iFile = 0
  sOut = []

  print "starting analysis in folder: "+srcDir
  for root, directories, filenames in os.walk(srcDir):
    print "sadsdfs"
    print directories
    for filename in filenames:
      print filename
      if not (fileId in filename):
        continue
      iFile = iFile + 1
      if iFile < es:
        continue  
      if iFile > ee:
        f.close()
        return()


      # extract information from file and foldernames
      print "root = %s" % root
      (tmp,folder2) = splitLastFolder(root)
      tmp = folder2.split("--")[4]
      replicate = folder2
      print replicate
      wells = tmp.split("-")
      print wells 
      tmp = filename.split("--")[1]
      tmp = tmp.split("W")[1]
      wellNum = int(tmp)
      print wellNum
      well = wells[wellNum-1]
      print well
      tmp = filename.split("--")[0:4]
      tmp = '--'.join(tmp)
      filenameDocu = tmp+".lsm--docu.png"
      filenameLSM = tmp+".lsm"
      pathFRAP = os.path.join(root,filename)
      pathDocu = os.path.join(root,filenameDocu)
      pathLSM = os.path.join(root,filenameLSM)
	      
      pathFRAPandSEG = os.path.join(destDir,filename+"--raw+seg.tif")
      print pathFRAP
      print pathFRAPandSEG
      print pathDocu
      print pathLSM
      
  
      f = open(os.path.join(destDir, filename+"--metadata.csv"), 'w')
      f.write("well,replicate,pathFRAP,pathFRAPandSEG,pathDocu,pathLSM\n")
      f.write(well+","+replicate+","+pathFRAP+","+pathFRAPandSEG+","+pathDocu+","+pathLSM+"\n")
      f.close()   
      
      #IJ.run("Close all forced", "")
      
      # load data (possible headless)
      path = os.path.join(root, filename)
      #imp = IJ.openImage(path)
      impA = getImps(path)
      imp = impA[0]
      imp.show()
      
      #IJ.run("Bio-Formats Importer","open="+path+" color_mode=Default split_channels view=Hyperstack stack_order=XYCZT")
      # remove transmisson channel
      IJ.run("Slice Remover", "first=2 last=100000 increment=2");
      imp = IJ.getImage()
      #imp.show()
      
      imp.setTitle("raw")
      IJ.run("Properties...", "unit=pixels pixel_width=1 pixel_height=1");

      dt = imp.getFileInfo().frameInterval
      print "dt = %f" % dt
      if dt==0:
        dt=0.28 
      print "dt = %f" % dt
      # todo: can i get the real time-stamps?
    
      im_w = imp.getWidth()
      im_h = imp.getHeight()
      print "im_w ="+str(im_w)
      print "im_h ="+str(im_h)
      
      nt = max(imp.getNSlices(),imp.getNFrames())
      print "nt = %f" % nt
      roi_x = im_w/2 - roi_w/2
      roi_y = im_h/2 - roi_h/2
      roi_x2 = roi_x + roi_w
      roi_y2 = roi_y + roi_h
      

      # preprocessing
      IJ.run("Duplicate...","title=gb duplicate stack")
      # smooth
      IJ.run("Gaussian Blur...", "sigma=2 stack"); 
      # tophat
      IJ.run("3D Fast Filters","filter=TopHat radius_x_pix=10 radius_y_pix=10 radius_z_pix=0 Nb_cpus=4");
      IJ.getImage().setTitle("gb_th")
      
      # threshold
      IJ.run("Duplicate...","title=bw duplicate stack") 
      # maybe global TH now, because there is already a tophat?
      #IJ.run("Auto Threshold", "method=Default white stack use_stack_histogram");
      IJ.run("Auto Local Threshold", "method=Niblack radius=40 parameter_1=3 parameter_2=0 white stack");
      
      # segment particles
      #IJ.getImage().setRoi(roi_x, roi_y, roi_w, roi_h)
      IJ.run("Set Measurements...", " mean min integrated center stack redirect=gb_th decimal=2");
      IJ.run("Analyze Particles...", "size=10-10000 pixel circularity=0.00-1.00 show=Masks display exclude clear stack");
      IJ.getImage().setTitle("particles")
      
      
      # measure particles
      rt = Analyzer.getResultsTable()

      # todo: add the particles that are actually analyzed (size filter, see above)

      # combine for documentation
      IJ.run("Combine...", "stack1=raw stack2=bw");
      IJ.getImage().setTitle("combine_raw_bw")
      IJ.run("Combine...", "stack1=combine_raw_bw stack2=particles");
      IJ.getImage().setTitle("combine_raw_bw_particles")
      
      impFRAPandSEG = IJ.getImage()
      IJ.saveAs(impFRAPandSEG, "Tiff", pathFRAPandSEG)


      # extract intensity informations
      nb = [0 for i in range(nt)]
      nc = [0 for i in range(nt)]
      ib = [0 for i in range(nt)]
      ic = [0 for i in range(nt)]
      fb = [0 for i in range(nt)]
      fc = [0 for i in range(nt)]
      
      t = [i*dt for i in range(nt)]
      
      if(rt.getColumnIndex("Slice")==-1):
        state = "no particles at all"
      else:
        Slice = rt.getColumn(rt.getColumnIndex("Slice"))
        Mean = rt.getColumn(rt.getColumnIndex("Mean"))
        Max = rt.getColumn(rt.getColumnIndex("Max"))
        X = rt.getColumn(rt.getColumnIndex("XM"))
        Y = rt.getColumn(rt.getColumnIndex("YM"))
        IntDen = rt.getColumn(rt.getColumnIndex("IntDen"))
        for i in range(len(Slice)):
          # inside bleach roi?!
          it = int(Slice[i])-1
          # todo: maybe use a dictionary instead (one can remove items and have differnt t
          if ( (X[i]>roi_x) & (X[i]<roi_x2) & (Y[i]>roi_y) & (Y[i]<roi_y2) ):
            nb[it] = nb[it]+1
            ib[it] = ib[it]+IntDen[i]  # the IntDen copes best with in and out of focus motions as well as shape changes
            fb[it] = fb[it]+Max[i]
          else:
            nc[it] = nc[it]+1
            ic[it] = ic[it]+IntDen[i]  
            fc[it] = fc[it]+Max[i]
            
        # compute mean values per particle
        for i in range(len(t)):
          if nb[i]>0:
            fb[i] = fb[i]/ib[i]   
            ib[i] = ib[i]/nb[i]
          if nc[i]>0:
            fc[i] = fc[i]/ic[i]
            ic[i] = ic[i]/nc[i]
            
          
      nb1 = [(0,1)[i==1] for i in nb]
     
      iShortlyAfter = iStart+10
      if( sum(nb1[0:iStart]) < 0.5*iStart ):
        state = "not enough pre-bleach measurements"
      elif( sum(nb1[iStart:iShortlyAfter]) < 0.5*10 ):
        state = "not enough short term measurements"
      elif( sum(nb1[iShortlyAfter+1:len(nb1)-1]) < 0.5*(len(nb1)-(iShortlyAfter+1)) ):
        state = "not enough long term measurements"
        

      plot_size_x = 500
      plot_size_y = 500
      
      # plot number of particles
      plotParticles = Plot( "Particles", "time", "number of particles", t, nb )
      plotParticles.setFrameSize(plot_size_x,plot_size_y)
      plotParticles.setSize(plot_size_x,plot_size_y)
      plotParticles.setLimits(min(t),max(t),0,1.2*max(max(nb),max(nc)))
      plotParticles.addPoints( t, nb, 3 )
      plotParticles.addPoints( t, nc, 4 )
      plotParticles.show()
      # plot raw intensities
      plotIntensities = Plot( "Intensities", "time", "gray values in particles", t, ib )
      plotIntensities.setFrameSize(plot_size_x,plot_size_y)
      plotIntensities.setSize(plot_size_x,plot_size_y)
      plotIntensities.setLimits(min(t),max(t),0,1.2*max(max(ic),max(ib)))
      plotIntensities.addPoints( t, ib, 3 )
      plotIntensities.addPoints( t, ic, 4 )
      #plotIntensities.show()
      # plot sharpness
      plotSharpness = Plot( "Sharpness", "time", "Max/IntDen", t, fb )
      plotSharpness.setFrameSize(plot_size_x,plot_size_y)
      plotSharpness.setSize(plot_size_x,plot_size_y)
      plotSharpness.setLimits(min(t),max(t),0,1.2*max(max(fc),max(fb)))
      plotSharpness.addPoints( t, fb, 3 )
      plotSharpness.addPoints( t, fc, 4 )
      #plotSharpness.show()



      # FITTING
      state = "ok"
      
      # extract all time points relevant to the fitting
      xTmp = []
      yTmp = []
      #print len(t) 
      #print range(iStart,len(t))
      ipb = ib[0:iStart-1]
      yTmpNorm = max(1,sum(ipb)/len(ipb))  # in order to avoid division by zero
      #print ib[iStart-1]
      for i in range(iStart,len(t)):
        if nb1[i]==1: # only time-point with 1 particle
          xTmp.append(float(t[i]-t[iStart])) 
          yTmp.append(float(ib[i]/yTmpNorm))

      # do the fitting  
      # todo: how to add initial guesses??
      imFrac = 0
      tau = 0
      xFit = []
      yFit = []
      if(len(yTmp)>20):
        cf = CurveFitter( xTmp, yTmp )
        cf.doFit(cf.EXP_RECOVERY)
        print cf.getFormula()
        p = cf.getParams()
        for i in p:
          print i
        imFrac = (1-p[2]-p[0])
        tau = (1/p[1])
        for i in range(len(xTmp)):
          xFit.append(float(xTmp[i])) 
          yFit.append(float(cf.f(cf.getParams(),xTmp[i])))
      else:
        state = "not enough data points for fitting"

      # shift the fitting curves back to the original bleaching time point
      #for i in range(len(xTmp)):
      #  xFit[i]=xFit[i]+t[iStart]
      #  xTmp[i]=xTmp[i]+t[iStart]
        
      
      # plot fitting
      plotFit = Plot( "Fitting", "time after bleach", "normalised intensity of bleached particle", xFit, yFit )
      plotFit.setFrameSize(plot_size_x,plot_size_y)
      plotFit.setSize(plot_size_x,plot_size_y)
      if(len(xTmp)>0): 
        plotFit.setLimits(min(xTmp),max(xTmp),0,1.2*max(yTmp))
        plotFit.addPoints( xTmp, yTmp, 3 )
      #plotFit.addPoints( xFit, yFit, 4 )
      
   
      plotFit.addLabel(0.1, 0.95, "imm_frac=%.2f tau[s]=%.2f" % (imFrac,tau))
      plotFit.addLabel(0.1, 0.9, state)
      

      # show the plots
      IJ.run("Close all forced", "")
      plotIntensities.show()
      plotParticles.show()
      plotSharpness.show()
      plotFit.show()
      
      # make one figure from the plots
      IJ.run("Images to Stack", "name=Stack title=[] use");
      IJ.run("Make Montage...", "columns=4 rows=1 scale=1 first=1 last=4 increment=1 border=0 font=12");
      
      imp = IJ.getImage()
      print "saving image: "+os.path.join(destDir, filename+"--IJ_graphs.png")
      dest = os.path.join(destDir, filename+"--IJ_graphs.png")
      IJ.saveAs(imp,"PNG", dest)
      
      # write text files    
      dest = os.path.join(destDir, filename+"--intensBleach.csv")
      writeXYfile(t,ib,dest,",")
      dest = os.path.join(destDir, filename+"--intensCtrl.csv")
      writeXYfile(t,ic,dest,",")
      dest = os.path.join(destDir, filename+"--numParticlesBleach.csv")
      writeXYfile(t,nb,dest,",")
      dest = os.path.join(destDir, filename+"--numParticlesCtrl.csv")
      writeXYfile(t,nc,dest,",")
  
      IJ.run("Close all forced", "")
  
        
  return()


	
if __name__ == '__main__':

	
	cluster = False
	if cluster: 
		if len(sys.argv) < 3:
			#print "Usage: <dirIn> <dirOut> <expName> <ps> <pe> <ts> <te>"
			print "Usage: <dirIn> <es> <ee>"
			sys.exit(1)

		i = 1
		dirIn = sys.argv[i]; i=i+1
		#dirOut = sys.argv[i]; i=i+1
		#expName = sys.argv[i]; i=i+1
		#ps = sys.argv[i]; i=i+1
		#pe = sys.argv[i]; i=i+1
		ts = sys.argv[i]; i=i+1
		te = sys.argv[i]; i=i+1
	else:
		dirIn = "Z:/ALMF_poster/ASCB2011_Tischi/ERES_FRAP/test2012-11-26--LSM780--FRAP--siRNA--d5-d4-c4-c5"
		dirIn = "//almf/almf/group/ALMFstuff/ALMF_poster/ASCB2011_Tischi/ERES_FRAP/test2012-11-26--LSM780--FRAP--siRNA--d5-d4-c4-c5"
		dirIn = "//almf/almf/group/ALMFstuff/ALMF_poster/ASCB2011_Tischi/ERES_FRAP/2012-11-26--LSM780--FRAP--siRNA--d5-d4-c4-c5"
	
		dirIn = "//almf/almf/group/ALMFstuff/ALMF_poster/ASCB2011_Tischi/ERES_FRAP/2012-11-26--LSM780--FRAP/2012-11-26--LSM780--FRAP--siRNA--c8-c7-c6-c5-d5-d4-c4"
		dirIn = "//almf/almf/group/ALMFstuff/ALMF_poster/ASCB2012_Tischi/ERES_FRAP/2012-11-26--LSM780--FRAP/2012-12-07--LSM780--FRAP--siRNA--d5-c5-c4-d4"
		
		#dirIn = "/g/almf/group/ALMFstuff/ALMF_poster/ASCB2011_Tischi/ERES_FRAP/test2012-11-26--LSM780--FRAP--siRNA--d5-d4-c4-c5"
		es=1
		ee=10000000000000000
		
		
	print "dirIn = "+dirIn
	#print "dirOut = "+dirOut
	#print "expName = "+expName
	#print "ps = "+ps
	#print "pe = "+pe
	print "es = "+str(es)
	print "ee = "+str(ee)

	IJ.run("Close all forced", "")
  	
	process(dirIn, int(es), int(ee))

		
