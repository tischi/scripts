
#source("//almf/almf/software/scripts/R/Tischi--Tischi--FRAP-batch-curve-analysis--2012-11-28.R")


library(tcltk)
require(gWidgets)
require(gWidgetstcltk)
require(ggplot2)
#require(grid)
guiToolkit("tcltk")

summariseTraces <- function(d,measurement,factor,fC,fS) {
	#print(measurement)
	#print(head(d))
	#print(levels(d$m))
	dd=subset(d,d$m==measurement)
	#print(head(dd))
	#print(levels(dd$m))
	tc=tapply(dd$y,dd[c("x",factor)],fC)
	ts=tapply(dd$y,dd[c("x",factor)],fS)
	#print(table)
	# convert to data frame in order to be able to use qplot
	ds = data.frame(f=character(0),x=character(0),c=character(0),s=character(0))
	for (t in colnames(tc)) {
 		for (x in rownames(ts)) {
 			if(!is.na(tc[x,t])) {
 				ds = rbind(ds,data.frame(f=t,x=as.numeric(x),c=tc[x,t],s=ts[x,t]))
 			}	
 		}
 	}
    #qplot(x=ds$x, y=ds$y, ylim=c(0,max(ds$y)), colour=factor(ds$treat))	 
    return(ds)	
}



## *****************************************************************
## read data
## *****************************************************************


handler_concatData <- function(h,...) {
  concatData()  
}

pathData = ""

concatData <- function() {

#  pathData <<- tk_choose.dir(default = pathData, caption = "Select data folder")
  pathData <<- "//almf/almf/group/ALMFstuff/ALMF_poster/ASCB2012_Tischi/ERES_FRAP/2012-11-26--LSM780--FRAP/tmp"
  fileID = ".*metadata.csv"
  files <<- list.files(path = pathData, pattern=fileID, recursive=T)
  print(paste("number of files =",length(files)))
  print("first files:")
  print(head(files))
  sepString = "--"
                                                                                                       
    
    #d <<- data.frame(treat=character(0),exp=character(0),repl=character(0),treat_repl=character(0),m=character(0),x=character(0),y=character(0))
    #df.exp <<- data.frame()
    
    #pb <- txtProgressBar(min = 0, max = length(files), style = 3);
    
    #files = head(files)
    
    measurements = c("intensBleach","intensCtrl","numParticlesBleach","numParticlesCtrl")
    
    l.data = list()
    l.exp = list()
    
    ifile = 0
    nfiles = length(files)
    print(files)
    for (x in files) {
      ifile = ifile + 1
	print(x)
      # todo: handle cases where one directly clicks on the data folder
      folder = unlist(strsplit(x,"/"))[[1]]
      filename = unlist(strsplit(x,"/"))[[2]]
      path = file.path(pathData,folder)
      
      print(paste(ifile,nfiles,sep="/"))
      print(paste("folder =",folder))
      print(paste("filename =",filename))
      filenameBase = paste(unlist(strsplit(filename,sepString ))[1:4],collapse=sepString)
    	t = read.table(file = file.path(path,filename), header = TRUE, sep=",")
    	exp = paste(t[["replicate"]],filenameBase,sep="__")
      repl = t[["replicate"]]
    	t[["exp"]] = exp
    	l.exp[[length(l.exp)+1]] = t
      treat = t[["well"]]
      
    	for(m in measurements) {
        filenameMeasurement = paste(filenameBase, "FRAP.lsm", m, sep=sepString)
    		filenameMeasurement = paste(filenameMeasurement, ".csv", sep="")
    
    		t = read.table(file = file.path(path, filenameMeasurement), header = TRUE, sep=",")
    		x = t[,1]  
    	 	y = t[,2]
    		n = nrow(t)
    		l.data[[length(l.data)+1]] = data.frame(treat=rep(treat,n),exp=rep(exp,n),repl=rep(repl,n),treat_repl=rep(paste(treat,repl,sep="_")),m=rep(m,n),x=x,y=y)
    		#d <<- rbind(d, data.frame(treat=rep(treat,n),exp=rep(exp,n),repl=rep(repl,n),treat_repl=rep(paste(treat,repl,sep="_")),m=rep(m,n),x=x,y=y) )
    	  
    	}
      
    }
    
    d <<- as.data.frame(do.call(rbind, l.data))
    df.exp <<- as.data.frame(do.call(rbind, l.exp))


    # todo: change to .csv files
    save(d, file=file.path(pathData,"concat--measurements--R.rda"))
    save(df.exp, file=file.path(pathData,"concat--experiments--R.rda"))

      
}

               
  
handler_loadTables <- function(h,...) {
    loadTables()  
}
  

loadTables <- function() {
  
  # todo: change to .csv files  
  filenames = tk_choose.files(default = "", caption = "Select table files")
  for (filename in filenames) {
    load(filename)
    d <<- d 
  }
      
}
      
  
#close(pb)

## ***************************************
## save data 
## ***************************************


# todo: make GUI





## ***************************************
## show raw data
## ***************************************


showRaw <- function () {
  library(ggplot2)
  
  # select measurement
  cm = select.list(levels(d$m), title="measurement")
  dm = subset(d,d$m==cm)
  # plot all in one graph
  qplot(x=d$x, y=d$y, colour=factor(d$treat))
}

## ***************************************
## compute derived readouts
## ***************************************


handler_normalisation <- function (h,...){

  normalise()

}


normalise <- function() {
  
  #iNormStart = readline("enter starting timepoint for normalisation (1):")
  iNormStart
  #iNormEnd = readline("enter ending timepoint for normalisation (20):")
  iNormEnd
  #
  tFitEnd = 30
  
  ## *******************************************
  cm = "intensBleach" # raw
  cmn = "intensCtrl" # normalisation
  cmqc = "numParticlesBleach" # QC
  cmqc2 = "numParticlesCtrl" # QC
  
  cmout = "intensBleachNormQC" # output
  ## *******************************************
  
  
  d2=d
  pb <- txtProgressBar(min = 0, max = length(files), style = 3);
  
  for (iexp in levels(d$exp)) { # split by experiment
      
      ib = subset(d, (d$exp==iexp) & (d$m==cm) & (d$x<tFitEnd))
      ic = subset(d, (d$exp==iexp) & (d$m==cmn) & (d$x<tFitEnd))
      nb = subset(d, (d$exp==iexp) & (d$m==cmqc) & (d$x<tFitEnd))
      
      # divide by ctrl
      ib$y = ib$y/ic$y
  
      # point-wise quality control: take subset with 1 particle in ib and non-zero in ctrl
      ib$y = ifelse((nb$y==1) & (ic$y>0), ib$y, NA)
      #ib = subset(ib, (nb$y==1) & (ic$y>0)); 
      
      # normalise to prebleach
      norm = mean(ib$y[iNormStart:iNormEnd])
      
      # add to dataframe
      ib$m = cmout
      ib$y = ib$y/norm
     
      # add to data frame
      d2 = rbind(d2,ib)
      	
      #} else {
      #	print("failed QC")
      #}
      
      
      setTxtProgressBar(pb, iexp);
     
    	}; close(pb)
  
    d <<- d2
  
    #save(d2, file=file.path(pathData,"concatenated_normalised--R.rda"))
    #load(file.path(pathData,"concatenated_normalised--R.rda"))
  
}


		
## ***************************************
## average traces
## ***************************************


#obj <- gcombobox(c("mean","median"), container = gp, handler=function(h,...) {summary.mode <<- svalue(h$obj)})
#obj <- gbutton("Summarise Treatments", container = gp, handler = handler_summary )  



handler_summary <- function(h,...){
  

  summarise.methods <<- c("mean","median")
  summarise.mode <<- summarise.methods[1]
  summarise.measurement <<- levels(factor((d$m)))[1]
  summarise.factor <<- colnames(d)[1]
  
  w <- gwindow("Summarise")
  gp <- ggroup(horizontal = FALSE, container=w)
  
  glabel("Method:", container=gp)
  obj <- gcombobox(summarise.methods, container = gp, handler=function(h,...) {summarise.mode <<- svalue(h$obj)})
  glabel("Measurement:", container=gp)
  obj <- gcombobox(levels(factor((d$m))), container = gp, handler=function(h,...) {summarise.measurement <<- svalue(h$obj)})
  glabel("Factor:", container=gp)
  obj <- gcombobox(colnames(d), container = gp, handler=function(h,...) {summarise.factor <<- svalue(h$obj)})
  obj <- gbutton("Do it!", container = gp, handler = handler_makeSummary )  
  
   
}


handler_makeSummary <- function(h,...) {
  makeSummary()
}

makeSummary <- function() {
  
  print("making summary..")
  if(summarise.mode == "median") {
    ds = summariseTraces(d, summarise.measurement, summarise.factor, function(z) {median(z,na.rm=T)}, function(z) {mad(z,na.rm=T)/sqrt(sum(z>0,na.rm=T))}  )
  } else if(summarise.mode == "mean") {    
    ds = summariseTraces(d, summarise.measurement, summarise.factor, function(z) {median(z,na.rm=T)}, function(z) {mad(z,na.rm=T)/sqrt(sum(z>0,na.rm=T))}  )
  }
  
  print("plotting summary..")
  p = ggplot(ds, aes(x=x, y=c, colour=f), xlab="time [s]") + 
      geom_errorbar(aes(ymin=c-s, ymax=c+s), width=1) +
      geom_point() + 
      xlab("time [s]") +
      ylab(summary.measurement)
  print(p)    
  
}  
  
  
  
if(0){
  qplot(x=ds$x, y=ds$y, ylim=c(0,max(ds$y)), colour=factor(ds$treat))	
  
  ds=summariseTraces(d2,"numParticlesBleach",function(z) {sum(z==1,na.rm=T)})
  qplot(x=ds$x, y=ds$y, ylim=c(0,max(ds$y)), colour=factor(ds$treat))	
  
  
  ds=summariseTraces(d2,"intensBleachNormP1",function(z) {sum(z>0,na.rm=T)})
  qplot(x=ds$x, y=ds$y, ylim=c(0,max(ds$y)), colour=factor(ds$treat))	
  
  
  ds=summariseTraces(d2,"intensCtrlNorm",function(z) {median(z,na.rm=T)})
  qplot(x=ds$x, y=ds$y, ylim=c(0,max(ds$y)), colour=factor(ds$treat))	
  
  ds=summariseTraces(d2,"intensBleachNorm",function(z) {sum(z>0,na.rm=T)})
  qplot(x=ds$x, y=ds$y, ylim=c(0,max(ds$y)), colour=factor(ds$treat))	
  
  ds=summariseTraces(d2,"intensCtrl",function(z) {sum(z>0,na.rm=T)})
  qplot(x=ds$x, y=ds$y, ylim=c(0,max(ds$y)), colour=factor(ds$treat))	
  
  
  # count number of data points in each time step
  da = summariseTraces(dn,cm,function(z) {sum(z>0,na.rm=T)})
  }
  


## ***************************************
## analyze individual traces
## ***************************************

fitting <- function() {
  
  cm = select.list(levels(factor(d2$m)), title="measurement")
  
  cm = "intensBleachNormP1"
  dm = subset(d2,d2$m==cm)
  
  iFitStart = 21
  
  id = dm$exp
  s = split(1:nrow(dm), id)
  
  i=0
  for (si in s) {
  
  	experiment = dm$exp[si[1]]
  	treat = dm$treat[si[1]]
   	
  	x = dm$x[si]			
  	y = dm$y[si]
  
   
      plot(x, y, ylim=c(0,1.5), main = paste(experiment,sep=""), xlab="time", ylab=cm)
      
      fit = NULL
  	
  	# trace-wise quality control: 
      #n1Pre = (nb$y[iNormStart:iNormEnd]==1)
      #n1Post = (nb$y[(iNormEnd+1):length(nb$y)]==1)
      #f1Pre = sum(n1Pre)/length(n1Pre)
      #f1Post = sum(n1Post)/length(n1Post)
      #print(paste(f1Pre,f1Post))
     
      # FITTING
  	x2 = x[iFitStart:length(x)]	- x[iFitStart]
  	y2 = y[iFitStart:length(y)]
      
      # fitting parameters
      tauStart = 5
      bdStart = 0.5
      imfStart = 0
      tauMax = x2[length(x2)]
      
      # weights (what is the best here?)
      w = 1/seq(length(x2))
  	
  	try(fit <- nls(y2~(1-imf-(bd-imf)*exp(-x2/tau)), 
  	           weights = w, start = c(tau=tauStart, bd=bdStart, imf=imfStart), 
  	           #upper = c(tau=tauMax, bd=1, imf=1),
  	           #lower = c(tau=0, bd=0, imf=0),
  	           trace=F,na.action=na.exclude), 
  	           silent = TRUE)
  	
  		#,lower = c(tau=0, bd=0, imf=0),
  		#upper = c(tau=tauMax, bd=1, imf=1),
  		#algorithm = "port" )
      
     
      if(!is.null(fit)){
      	y2fit = predict(fit, list(x2=x2)) # needs to be the same name than in the fitting!!!
  		x2 = x2 + x[iFitStart]
  		lines(x2, y2fit, lty = 1)  
  	
      	# add fit parameters 
      	pfit = fit$m$getPars()
      	legend = ""
      	fitQuality = mean(abs(residuals(fit))/y2, na.rm=T)
      	comment = ""
      	fitValid = TRUE
      	for (c in names(pfit)) { 
      		legend = sprintf("%s%s=%.2f; ",legend,c,pfit[c])
      		#if(pfit[c]<0) {
      		#	comment = paste(comment,c, "<0; ", sep='') 
      		#	fitValid = FALSE
      	    #		}
  			}
  		if(pfit["bd"]>1) {
  			comment = paste(comment,"!!! bd>1;") 
      		fitValid = FALSE	
  				}
      	if(pfit["imf"]<(-0.1)) {
  			comment = paste(comment,"!!! imf<-0.1;") 
      		fitValid = FALSE	
  				}	
  	
  		legend = sprintf("%s mean(abs(res)/y)=%.3f; %s ",legend,fitQuality,comment)
  	    if(fitValid) {
  	    	dm = rbind(dm,data.frame(treat=treat,exp=experiment,m="tau",x=1,y=pfit["tau"]))
  			}
  				
      } else {
      	legend = "fitting failed!" 	
      	fitValid = F
      }
      text(0,legend, adj = c(0, 0) )
     
      ## ***************************************
  	## store whether fitting worked
  	## ***************************************
  	
  	i=i+1
  	print(i)
  	dm = rbind(dm,data.frame(treat=treat,exp=experiment,m="fitValid",x=1,y=fitValid))
  				
  	## ***************************************
  	## save plot
  	## ***************************************
  	
  	dev.copy(pdf,file.path(pathData,paste(experiment,'--R','.pdf',sep="")))
  	dev.off()
  }

}


## *********************
## summarise the fitting
## *********************

stuff <- function() {
  
  ds = summariseTraces(dm,"tau",function(z) {median(z,na.rm=T)}, function(z) {mad(z,na.rm=T)/sqrt(sum(z>0,na.rm=T))}) 
  
  dt = subset(dm,(dm$m=="tau") & (dm$treat!="pfa"))
  qplot(treat, y, data=dt, geom = c("jitter"), xlab="treatment", ylab="tau [s]", ylim=c(0,20))
  
  
  # number of valid fits and number of total fits
  ds = summariseTraces(dm,"fitValid",function(z) {sum(z==1,na.rm=T)}, function(z) {sum(z>(-1),na.rm=T)}  )
  print(ds)
  
  ds = summariseTraces(dm,"fitValid",function(z) {mean(z==1,na.rm=T)}, function(z) {sum(z>(-1),na.rm=T)}  )
  print(ds)
  
  
  ds = summariseTraces(dm,"fitValid",function(z) {sum(z==1,na.rm=T)}, function(z) {sum(z==0,na.rm=T)}  )
  
  
  
  # select measurement
  cm = select.list(levels(d$m), title="measurement")
  dm = subset(d,d$m==cm)
  # plot all in one graph
  library("ggplot2")
  qplot(x=d$x, y=d$y, colour=factor(d$treat))
  
  
  

  # plot individual
  
  id = data[[colF]]
  s = split(1:nrow(data), id)
  
  pdf(file = file.path( pathData, paste( Sys.Date(), "--analysis.pdf", sep='') ) )
  
  for (si in s) {
  
  	sTitle = data[[colF]][si[1]]
  
  	x = data[[colX]][si]			
  	y = data[[colY]][si]
  
  	x = x * 10
  	y = y / data[[colY]][si[1]]
  
  	plot(x,y, ylim=c(0,1.5), main= paste("Well ",sTitle,sep=""), xlab="asda")
  
  }
  
  dev.off()
  
}  




# todo: button: close all
mainGUI <- function() {
  
  w <- gwindow("FRAPALYZER")
  gp <- ggroup(horizontal = FALSE, container=w)
  
  glabel("FRAPALYZER", container=gp)
  glabel("(c) TISCHER@EMBL.DE", container=gp)
  glabel("version: 2011-11-28", container=gp)
  glabel("very beta!", container=gp)
  glabel("------------------------------------", container=gp)
  obj <- gedit("concat", container=gp, handler = function(h,...) {loadTables.prefix <<- svalue(h$obj)} )
  obj <- gbutton("Load tables", container = gp, handler = handler_loadTables)
  obj <- gbutton("Concat data", container = gp, handler = handler_concatData)  
  glabel("------------------------------------", container=gp)
  obj <- gbutton("View experiment table", container = gp, handler = function(h,...) { edit(df.exp) } )  
  obj <- gbutton("View data table", container = gp, handler = function(h,...) { edit(d) } )  
  glabel("------------------------------------", container=gp)
  obj <- gedit("1", container=gp, handler=function(h,...) {iNormStart <<- svalue(h$obj)})
  obj <- gedit("5", container=gp, handler=function(h,...) {iNormEnd <<- svalue(h$obj)})
  obj <- gbutton("Normalise", container = gp, handler = handler_normalisation )  
  glabel("----SUMMARY-------------------------------", container=gp)
  obj <- gbutton("Summarise", container = gp, handler = handler_summary )  
  
  
#  obj <- gbutton("Plate view", editable=TRUE, container = gp, handler = handler_platePlotGUI )  
#  obj <- gbutton("Scatter plot (not yet)", editable=TRUE, container = gp, handler = handler_scatterPlotGUI )
#  obj <- gbutton("Box plot (not yet)", editable=TRUE, container = gp, handler = handler_boxPlotGUI )
#  obj <- gbutton("Jitter plot", editable=TRUE, container = gp, handler = handler_jitterPlotGUI )
#  glabel("------------------------------------", container=gp)
#  obj <- gbutton("Quality control", editable=TRUE, container = gp, handler = handler_QC ) 
#  obj <- gbutton("Normalisation", editable=TRUE, container = gp, handler = handler_normalisationGUI ) 
#  glabel("------------------------------------", container=gp)
#  glabel("Image channel to be viewed:", container=gp)
#  obj <- gcombobox(imagenames, editable=TRUE, container = gp, handler=function(h,...) {imageforviewing <<- svalue(h$obj)})
#  glabel("------------------------------------", container=gp)
#  obj <- gbutton("Combine columns", editable=FALSE, container = gp, handler = handler_combineColumnsGUI )
  
  
  #svalue(cb) <- df.images[[cPlateRepl]][1]	
  #obj <- gbutton("Select wells", editable=TRUE, container = gp, handler= handler_selectPoints )
  
  
}	


mainGUI()




