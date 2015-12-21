

# source("//almf/almf/software/scripts/R/Tischi--Tischi--FRAP-batch-curve-analysis--2012-12-05.R")



## specify libraries
libs = list("gWidgets","gWidgetstcltk","ggplot2")

## install libraries
# sapply(libs, biocLite) 

## load libraries
sapply(libs, function(x) do.call("library", list(x))) 

guiToolkit("tcltk")

# todo: make an install file

convertPath <-function(path) {
  if ( .Platform$OS.type == "unix" ) {
    path = gsub("\\\\" ,"/", path)
  } else if ( .Platform$OS.type == "windows" ) {
    path = gsub("/", "\\\\", path)
  }
  path
}

convertPathToRstyle <-function(path) {
  path = gsub("\\\\" ,"/", path)
  return(path)
}



## *****************************************************************
## read data
## *****************************************************************


handler_concatData <- function(h,...) {
  concatData()  
}

pathData = ""

concatData <- function() {
  
  pathData <<- tk_choose.dir(default = pathData, caption = "Select data folder")
  
  tableFolder <<- pathData
  
  fileID = ".*metadata.csv"
  print("looking for files...")
  files <<- list.files(path = pathData, pattern=fileID, recursive=T)
  print(paste("done! Number of files =",length(files)))
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
  for (x in files) {  # files = all tables ending on metadata.csv
    
    ifile = ifile + 1
    folder= unlist(strsplit(x,"/"))[[1]]
    filename = unlist(strsplit(x,"/"))[[2]]
    path = file.path(pathData,folder)
    
    print(paste(ifile,nfiles,sep="/"))
    print(paste("folder =",folder))
    print(paste("filename =",filename))
    
    # read table
    t = read.table(file = file.path(path,filename), header = TRUE, sep=",")
    
    # extract metadata from metadata table and filename
    filenameBase = paste(unlist(strsplit(filename,sepString ))[1:4],collapse=sepString) # cuts off the ends of filenames
    
    # experiment = replicate__filename
    exp = paste(t[["replicate"]],filenameBase,sep="__") 
    repl = t[["replicate"]]
    t[["exp"]] = exp
    l.exp[[length(l.exp)+1]] = t
    treat = t[["well"]]
    
    # read the other (additional to metadata.csv) tables of this experiment
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
  
  print("converting list to data frame...")
  d <<- as.data.frame(do.call(rbind, l.data))
  df.exp <<- as.data.frame(do.call(rbind, l.exp))
  print("done.")
  
}

handler_loadTables <- function(h,...) {
  loadTables()    
}

loadTables <- function() {
  
  filenames = tk_choose.files(default = pathData, caption = "Select .rda table files")
  
  print("loading...")
  for (filename in filenames) {
    load(filename)  
    #read.table(file=filename, header=T, sep=",", stringsAsFactors=F, check.names=T)
  }
  
  tmp =  unlist(strsplit(filename,"/"))
  tableFolder <<- paste(tmp[1:length(tmp)-1],collapse="/")
  pathData <<- tableFolder
  
  d <<- d
  df.exp <<- df.exp
  print("done.")
  
}


## ***************************************
## save data 
## ***************************************


handler_saveTables <- function(h,...) {
  saveTables()  
} 

saveTables <- function() {
  
  
  folder = tk_choose.dir(default = pathData, caption = "Select output folder")
  
  if(is.na(folder)) {
    print("data not saved");
    return()
    
  } else {
    
    print("saving tables...")
    #write.table(d, file=file.path(folder,paste(saveTables.prefix,"--measurements.csv",sep="")), sep = ",", col.names = TRUE, row.names = FALSE)
    write.table(df.exp, file=file.path(folder,paste(saveTables.prefix,"--experiments.csv",sep="")), sep = ",", col.names = TRUE, row.names = FALSE)
    
    save(d, file=file.path(folder,paste(saveTables.prefix,"--measurements.rda",sep="")))
    save(df.exp, file=file.path(folder,paste(saveTables.prefix,"--experiments.rda",sep="")))
    print("done!")
    
  } 
  
}

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

## *********************************************
## normalise and point-wise QC
##
##
##


normalise <- function() {
  
  print ("normalising...")
  
  ## *******************************************
  cm = "intensBleach" # = mean integrated intensity of all particles inside bleach region
  cmn = "intensCtrl" # = mean integrated intensity of all particles outside bleach region
  cmqc = "numParticlesBleach" # 
  cmqc2 = "numParticlesCtrl" # 
  
  cBleachNorm= "intensBleachNormQC" # output
  cCtrlNorm = "intensCtrlNormQC" # output
  ## *******************************************
  
  
  # average all intensity measurements outside bleach roi of each replicate (=folder)
  # todo: one could also try again to normalise individually for each measurement
  # todo: make this as an option
  print ("computing acquisition bleaching correction for each replicate...")
  dd = subset(d,d$m=="intensCtrl")
  ddd = subset(dd,dd$y>0)
  icMeanRepl = tapply(ddd$y,ddd[c("x","repl")], mean)
  #a = tapply(ddd$y,ddd[c("x","repl")], function(z) {sum(z/z)})
  print ("done.")
  
  i = 0; n = length(levels(d$exp))
  l.data = list()
  
  for (iexp in levels(d$exp)) { # split by experiment
    
    i = i + 1
    print(paste(i,n,iexp))
    flush.console()
    
    #if(i>5){break}
    
    if(1) {
      
      tmp = subset(d, d$exp==iexp )
      ib = subset(tmp, tmp$m==cm )
      ic = subset(tmp, tmp$m==cmn ) 
      nb = subset(tmp, tmp$m==cmqc ) 
      nc = subset(tmp, tmp$m==cmqc2 ) 
      
      # divide by ctrl
      #ib$y = ib$y/ic$y
      
      ## point-wise quality control
      #ib$y = ifelse( nb$y>0, ib$y, NA) # at least 1 particle
      ib$y = ifelse( nb$y==1, ib$y, NA) # exactly 1 particle
      ic$y = ifelse( nc$y>0, ic$y, NA) # at least 1 particle
      
      # for inside bleach ROI get the total
      # ib$y = ib$y*nb$y  # not necessary if QC is nb$y==1
      
      # normalise inside bleach region for acquisition bleaching
      repl = tmp$repl[1]
      ii = which(!is.na(icMeanRepl[,repl]))
      icNorm = icMeanRepl[ii,repl]
      
      if(length(ib$y)!=length(icNorm)) {
        print ("unequal length of ctrl and data. skipping this experiment!")
        next
      }
      
      ib$y = ib$y/icNorm
      
      # for outside bleach ROI keep the mean
      #ic$y = ic$y*nc$y
      
      # shift x (=time) to zero at first postbleach
      xShift = ib$x[iNormEnd+1]
      ib$x = ib$x - xShift
      ic$x = ic$x - xShift
    
      # subtract first postbleach of intensities in bleached region
      postbleach = ib$y[iNormEnd+1]
      ib$y = ib$y - postbleach
      
      # normalise both outside and inside bleach region to mean of before bleaching
      norm = mean(ib$y[iNormStart:iNormEnd],na.rm=T)
      ib$y = ib$y/norm
      
      norm = mean(ic$y[iNormStart:iNormEnd],na.rm=T)
      ic$y = ic$y/norm
      
      # change measurement name
      ib$m = cBleachNorm
      ic$m = cCtrlNorm
      
      # store in a list
      l.data[[length(l.data)+1]] = ib
      l.data[[length(l.data)+1]] = ic
      
    }  
    
  }
  print ("done.")
  
  print("converting list to data frame...")
  dnew = as.data.frame(do.call(rbind, l.data))
  print("add normalised curves to data frame...")
  d <<- rbind(d,dnew)
  print("done.")
  
}

## ***************************************
## summarise traces
## ***************************************

subsets.list = list()

handler_summaryGUI <- function(h,...){
  summaryGUI() 
}

summaryGUI <- function() {
  
  summarise.methods <<- c("mean","median")
  summarise.mode <<- summarise.methods[1]
  summarise.measurement <<- levels(factor((d$m)))[1]
  summarise.factor <<- colnames(d)[1]
  summarise.plottype <<- c("errorbar","lines","symbols")
  
  w <- gwindow("Summarise", visible = F)
  gp <- ggroup(horizontal = FALSE, container=w)
  
  glabel("Method:", container=gp)
  obj <- gcombobox(summarise.methods, container = gp, handler=function(h,...) {summarise.mode <<- svalue(h$obj)})
  glabel("Measurement:", container=gp)
  obj <- gcombobox(levels(factor((d$m))), container = gp, handler=function(h,...) {summarise.measurement <<- svalue(h$obj)})
  glabel("Factor:", container=gp)
  obj <- gcombobox(colnames(d), container = gp, handler=function(h,...) {summarise.factor <<- svalue(h$obj)})
  glabel("Plot Type:", container=gp)
  obj <- gcombobox( summarise.plottype, container = gp, handler=function(h,...) {summarise.plottype<<- svalue(h$obj)})
  obj <- gbutton("Do it!", container = gp, handler = handler_makeSummary )  
  glabel("----SUBSETS-----------", container=gp)
  obj <- gcombobox(colnames(d), container = gp, handler = function(h,...) {subsets.currentCol <<- svalue(h$obj)})
  obj <- gbutton("Add/Change subsets for above column", container = gp, handler = handler_changeSubset )  
  obj <- gbutton("Reset all subsets", container = gp, handler = function(h,...) {subsets.list <<- list()})  
  glabel("----Add Analysis-----------", container=gp)
  summarise.analyses = c("do nothing","add fit")
  obj <- gcombobox(summarise.analyses, container = gp, handler = function(h,...) {summarise.analysis <<- svalue(h$obj)})
  
  visible(w) <- T
  
}

handler_changeSubset <- function(h,..) {
  changeSubset()
}

changeSubset <- function() {
  
  selection = levels(factor(d[[subsets.currentCol]]))
  if(length(selection) < 30) {
    subsets.list[[subsets.currentCol]] <<- vector()
    w <- gwindow("select")
    gp <- ggroup(container=w)
    cbg <- gcheckboxgroup(levels(factor(d[[subsets.currentCol]])), container=gp, handler=function(h,...) {
      subsets.list[[subsets.currentCol]] <<- svalue(cbg)
      print(subsets.list)
    })
  } else {
    print ("too many items.")
  }
  
}

handler_makeSummary <- function(h,...) {
  makeSummary()
}

makeSummary <- function() {
  
  print("making summary..")
  
  if(summarise.mode == "median") {
    ds = summariseTraces(d, summarise.measurement, summarise.factor, function(z) {median(z,na.rm=T)}, function(z) {mad(z,na.rm=T)/sqrt(sum(z>0,na.rm=T))}  )
  } else if(summarise.mode == "mean") {    
    ds = summariseTraces(d, summarise.measurement, summarise.factor, function(z) {mean(z,na.rm=T)}, function(z) {sd(z,na.rm=T)/sqrt(sum(z>0,na.rm=T))}  )
  }
  
  print("plotting summary..")
  
  if(0) {
    
    if(summarise.plottype == "errorbar") {
      p = ggplot(ds, aes(x=x, y=c, colour=f), xlab="time [s]") + 
        geom_errorbar(aes(ymin=c-s, ymax=c+s), width=1) +
        geom_point() + 
        xlab("time [s]") +
        ylab(summarise.measurement)
      print(p)    
    } else if (summarise.plottype=="lines") {
      p = ggplot(ds, aes(x=x, y=c, colour=f), xlab="time [s]") + 
        #geom_errorbar(aes(ymin=c-s, ymax=c+s), width=1) +
        geom_line() + 
        xlab("time [s]") +
        ylab(summarise.measurement)
      print(p)    
    } else if (summarise.plottype=="symbols") {
      p = ggplot(ds, aes(x=x, y=c), xlab="time [s]") + 
        #geom_errorbar(aes(ymin=c-s, ymax=c+s), width=1) +
        #geom_line() + 
        geom_point( aes(shape = f) ) +
        scale_shape_manual(values=1:20) + geom_point(size=2) +
        xlab("time [s]") +
        ylab(summarise.measurement)
      print(p)         
    }
    
  }
  
  if(summarise.analysis=="add fit") {
    
    id = ds$f
    s = split(1:nrow(ds), id)
    
    
    i = 0
    for(si in s) {
      i=i+1
      print(paste("fitting:",ds$f[si[1]]))
      x = ds$x[si]
      y = ds$c[si]
      fit.list = curveAnalysis_fitOneCurve(x,y)
      lines(x=fit.list$x, y=fit.list$y, col=i)
      text(0,fit.list$legend, adj = c(0, 0) )
      
    }
    
  }
  
}  

summariseTraces <- function(d,measurement,myfactor,fC,fS) {
  
  # subsetting
  print("selecting subsets...")
  dsub = subset(d,d$m==summarise.measurement)
  #print(nrow(dsub))
  # subsets selection
  
  print(paste("subsets list = ",subsets.list))
  
  for(col in names(subsets.list)) {
    
    iisel = vector()
    for(sel in subsets.list[[col]]) {
      ii = which(dsub[[col]]==sel)
      iisel = c(iisel,ii)
    }
    dsub = dsub[iisel,]
    print(paste(col,nrow(dsub)))
    
  }
  
  dsub[[summarise.factor]] = factor(dsub[[summarise.factor]]) # update the currently existing levels
  tc=tapply(dsub$y,dsub[c("x",summarise.factor)],fC)
  ts=tapply(dsub$y,dsub[c("x",summarise.factor)],fS)
  tn=tapply(dsub$y,dsub[c("x",summarise.factor)],function(z){sum((z+1)/(z+1),na.rm=T)})
  
  if(1) {
    # rebinning
    
    tcb = list()
    # timepoints before bleaching:
    # ignore them!
    x = as.numeric(rownames(tc))
    dt = 0.7
    ts = 0
    te = max(x)+dt
   
    tcb = list()
    for (col in colnames(tc)) {
      # timepoint at bleaching
      ix = which(x==0)
      tcb[[col]]$x[1] = 0 
      tcb[[col]]$y[1] = 0 
      tcb[[col]]$n[1] = tn[ix,col]
      
      # timepoints after bleaching
      i = 1
      for( t in seq(ts,te,dt)) {
        i = i + 1
        tcb[[col]]$x[i]=t+dt/2
        iix = which((x>t) & (x<=t+dt))  
        tcb[[col]]$n[i] = 0
        tcb[[col]]$y[i] = 0
        for(ix in iix) {
          #print(tc[ix,col])
          #print(tn[ix,col])
          tcb[[col]]$n[i] = tcb[[col]]$n[i] + tn[ix,col]
          tcb[[col]]$y[i] = tcb[[col]]$y[i] + tc[ix,col]*tn[ix,col]
        }
        if(tcb[[col]]$n[i]>0) {
          tcb[[col]]$y[i] = tcb[[col]]$y[i] / tcb[[col]]$n[i]
        } else {
          tcb[[col]]$y[i] = NA
        }
      }
    
    }
    
  } # rebinning
  
  if(0) { # without rebinning
    print("")
    print("curves:")
    #print(palette())
    for (i in 1:length(colnames(tc))) {
      col = colnames(tc)[i]
      x = as.numeric(rownames(tc))
      y = tc[,col]
      s = ts[,col]
      print(paste(LETTERS[i],col,min(tn[,col]),max(tn[,col])))
      if (i==1) {
        #plot(x,y,cex=0.5,pch=LETTERS[i],ylim=c(min(tc,na.rm=T),max(tc,na.rm=T)))
        plot(x,y,cex=1,pch=i,col=i,ylim=c(min(tc,na.rm=T),max(tc,na.rm=T)))
      } else {
        #points(x,y,cex=0.5,pch=LETTERS[i])
        points(x,y,cex=1,pch=i,col=i)
        #print(p)
      }
      # error bars
      barwidth = 0.1
      segments(x,y-s,x,y+s,col=i)
      segments(x-barwidth,y+s,x+barwidth,y+s,col=i)
      segments(x-barwidth,y-s,x+barwidth,y-s,col=i)
    }
  } # plotting without rebinning
      
  if(1) { # with rebinning
    print("")
    print("curves:")
    #print(palette())
    
    for (i in 1:length(names(tcb))) {
      item = names(tcb)[i]
      x = tcb[[item]]$x
      y = tcb[[item]]$y
      n = tcb[[item]]$n
      #s = ts[,col]
      print(paste(LETTERS[i],item,min(n),max(n)))
      if (i==1) {
        plot(x,y,cex=0.5,pch=LETTERS[i],ylim=c(0,1.1))
        #plot(x,y,cex=1,pch=i,col=i,ylim=c(-0.1,1.1))
      } else {
        points(x,y,cex=0.5,pch=LETTERS[i])
        #points(x,y,cex=1,pch=i,col=i)
        #print(p)
      }
      # error bars
      #barwidth = 0.1
      #segments(x,y-s,x,y+s,col=i)
      #segments(x-barwidth,y+s,x+barwidth,y+s,col=i)
      #segments(x-barwidth,y-s,x+barwidth,y-s,col=i)
    }
  } # plotting with rebinning
  
  if(0) {  # convert to dataframe
    #print(table)
    # convert to data frame in order to be able to use qplot
    ds = data.frame(f=character(0),x=character(0),c=character(0),s=character(0))
    for (t in colnames(tc)) {
      for (x in rownames(ts)) {
        if(!is.na(tc[x,t])) {
          ds = rbind(ds,data.frame(f=t,x=as.numeric(x),c=tc[x,t],s=ts[x,t],n=tn[x,t]))
        }	
      }
    }
    #qplot(x=ds$x, y=ds$y, ylim=c(0,max(ds$y)), colour=factor(ds$treat))	 
    return(ds)	
  } # convert to data frame
  
}

## ***************************************
## curve Analysis
## ***************************************

handler_curveAnalysisGUI <- function (h,...){
  
  curveAnalysis.methods <<- c("fitting","nothing")
  curveAnalysis.fitStart <<- 6
  curveAnalysis.fitEnd <<- 30
  curveAnalysis.fitStartExp <<- 1
  curveAnalysis.fitEndExp <<- 1000000000
  
  #summarise.mode <<- summarise.methods[1]
  #summarise.measurement <<- levels(factor((d$m)))[1]
  #summarise.factor <<- colnames(d)[1]
  #summarise.plottype <<- c("dots+error","lines")
  
  w <- gwindow("Curve Analysis")
  gp <- ggroup(horizontal = FALSE, container=w)
  
  #glabel("Method:", container=gp)
  #obj <- gcombobox(curveAnalysis.methods, container = gp, handler=function(h,...) {curveAnalysis.method <<- svalue(h$obj)})
  obj <- glabel("Measurement:", container=gp)
  obj <- gcombobox(levels(factor((d$m))), container = gp, handler=function(h,...) {curveAnalysis.measurement <<- svalue(h$obj)})
  obj <- glabel("--------------------", container=gp)
  obj <- glabel("fitStart (datapoint)", container=gp)
  obj <- gedit(curveAnalysis.fitStart, container=gp, handler = function(h,...) {curveAnalysis.fitStart <<- as.numeric(svalue(h$obj))})
  obj <- glabel("fitEnd (time after bleach)", container=gp)
  obj <- gedit(curveAnalysis.fitEnd, container=gp, handler = function(h,...) {curveAnalysis.fitEnd <<- as.numeric(svalue(h$obj))})
  obj <- glabel("--------------------", container=gp)
  obj <- glabel("fitStart (experiment)", container=gp)
  obj <- gedit(curveAnalysis.fitStartExp, container=gp, handler = function(h,...) {curveAnalysis.fitStartExp <<- as.numeric(svalue(h$obj))})
  obj <- glabel("fitEnd (experiment)", container=gp)
  obj <- gedit(curveAnalysis.fitEndExp, container=gp, handler = function(h,...) {curveAnalysis.fitEndExp <<- as.numeric(svalue(h$obj))})
  obj <- gbutton("Fit them!", container = gp, handler = handler_curveAnalysis_fitting )  
  glabel("--------------------", container=gp)
  
  #glabel("Factor:", container=gp)
  #obj <- gcombobox(colnames(d), container = gp, handler=function(h,...) {summarise.factor <<- svalue(h$obj)})
  #glabel("Plot Type:", container=gp)
  #obj <- gcombobox( summarise.plottype, container = gp, handler=function(h,...) {summarise.factor <<- svalue(h$obj)})
  
}

handler_curveAnalysis_fitting <- function(h,...) {
  
  curveAnalysis_fitting()
  
}

curveAnalysis_fitting <- function() {
  
  print("CURVE FITTING")
  
  iFitStart = curveAnalysis.fitStart
  
  iExpStart = curveAnalysis.fitStartExp
  iExpEnd = curveAnalysis.fitEndExp
  
  id = d$exp
  s = split(1:nrow(d), id)
  
  iExpEnd = min(iExpEnd,length(s))
  s = s[iExpStart:iExpEnd]
  
  n = length(s)
  
  print(paste("Number of experiments =",n))
          
  # intialise
  if(is.null(df.exp$pathFit)) {df.exp$pathFit=NA}
  if(is.null(df.exp$fit_tau)) {df.exp$fit_tau=NA}
  if(is.null(df.exp$fit_imf)) {df.exp$fit_imf=NA}
  if(is.null(df.exp$fit_status)) {df.exp$fit_status=NA}
  if(is.null(df.exp$fit_deviation)) {df.exp$fit_deviation=NA}
  if(is.null(df.exp$tRec1)) {df.exp$tRec1=NA}
  if(is.null(df.exp$fracRec1)) {df.exp$fracRec1=NA}
  if(is.null(df.exp$tRec2)) {df.exp$tRec2=NA}
  if(is.null(df.exp$fracRec2)) {df.exp$fracRec2=NA}
  if(is.null(df.exp$intensCtrl)) {df.exp$intensCtrl=NA}
  if(is.null(df.exp$numCtrl)) {df.exp$numCtrl=NA}
  
  
  # loop through the experiments
  for (si in s) {
    
    # get the experiment subset
    dd = d[si,]
    experiment = dd$exp[1]
    treat = dd$treat[1]
    
    print(experiment)
        
    iexp = which(df.exp$exp==experiment)
    
    # OTHER INTERESTING VALUES
    ii = which(dd$m=="numParticlesCtrl")
    nc_mean = mean(dd$y[ii],na.rm=T)
    ii = which(dd$m=="intensCtrl")
    ic_mean = mean(dd$y[ii],na.rm=T)
    
    # FITTING
    
    # get the fitting data subset
    cm = curveAnalysis.measurement
    cmi = which(dd$m==cm)
    x = dd$x[cmi]
    y = dd$y[cmi]
    
    if(length(x)<6) {
      print(paste(iexp,nrow(df.exp),"not enough data points, skipping!"))
      next
    }
    
    yRange = c(-0.1,1.1)
		
    plot(x, y, ylim=yRange, xlab="time", ylab=cm)
    lines(x, y) #, ylim=yRange, xlab="time", ylab=cm)
    #title(main = paste(treat,experiment,sep="  "), cex.main=0.7)
    fit = NULL
    
    # convert fit end time to datapoint
    iFitEnd = min(min(which(x>curveAnalysis.fitEnd)),length(x))
    print(paste("x[iFitStart]",x[iFitStart]))
    
    x2 = x[iFitStart:iFitEnd]  - x[iFitStart]
    y2 = y[iFitStart:iFitEnd]
    
    # recovery analysis
    
    tRec1s = 3 #[s]
    tRec1e = 4 #[s]
    
    tRec2s = 12 #[s]
    tRec2e = 17 #[s]
    
    
    datapoints = which((x2>tRec1s) & (x2<tRec1e))
    if(length(datapoints)) {
      fracRec1 = mean(y2[datapoints],na.rm=T)
      tRec1 = mean(x2[datapoints],na.rm=T)
    } else {
      fracRec1 = NA
      tRec1 = NA
    }
    #print(paste(tRec1,fracRec1))
    
    datapoints = which((x2>tRec2s) & (x2<tRec2e))
    if(length(datapoints)) {
      fracRec2 = mean(y2[datapoints],na.rm=T)
      tRec2 = mean(x2[datapoints],na.rm=T)
    } else {
      fracRec2 = NA
      tRec2 = NA
    }
    
    
    #print(paste(tRec2,fracRec2))
    #legend2 = sprintf("rec(%.1f)=%.2f; rec(%.1f)=%.2f ", tRec1, fracRec1, tRec2, fracRec2)
    
    # fitting parameters
    tauStart = 5
    bdStart = 0.5
    imfStart = 0
    #tauMax = x2[length(x2)]
    
    # weights (what is the best here?)
    #w = 1/seq(length(x2))
    #w = 1/x2
    w = rep(1,length(x2))
    tau = NA
    immfrac = NA
    fitStatus = 0
    
    # free bleach depth
    #try(fit <- nls(y2~(1-imf-(bd-imf)*exp(-x2/tau)), 
    #           weights = w, start = c(tau=tauStart, bd=bdStart, imf=imfStart), 
    #           #upper = c(tau=tauMax, bd=1, imf=1),
    #           #lower = c(tau=0, bd=0, imf=0),
    #           trace=F,na.action=na.exclude), 
    #           silent = TRUE)
    
    # fixed bleach depth
    try(fit <- nls(y2~(1-immfrac-(1-immfrac)*exp(-x2/tau)), 
                   weights = w, start = c(tau=tauStart, immfrac=imfStart), 
                   #upper = c(tau=tauMax, bd=1, immfrac=1),
                   #lower = c(tau=0, bd=0, immfrac=0),
                   trace=F,na.action=na.exclude), 
        silent = TRUE)
    
    
    #,lower = c(tau=0, bd=0, imf=0),
    #upper = c(tau=tauMax, bd=1, imf=1),
    #algorithm = "port" )
    
    
    if(!is.null(fit)){
      y2fit = predict(fit, list(x2=x2)) # needs to be the same name than in the fitting!!!
      x2 = x2 + x[iFitStart]
      
      # add the fit
      lines(x2, y2fit, lty = 2, col="red", lwd=3)  
      
      # add fit parameters 
      pfit = fit$m$getPars()
      legend = ""
      fitQuality = mean( residuals(fit)^2 , na.rm=T)
      comment = ""
      fitValid = TRUE
      for (c in names(pfit)) { 
        legend = sprintf("%s%s=%.2f; ",legend,c,pfit[c])
        #if(pfit[c]<0) {
        #	comment = paste(comment,c, "<0; ", sep='') 
        #	fitValid = FALSE
        #		}
      }
      #if(pfit["bd"]>1) {
      #  comment = paste(comment,"!!! bd>1;") 
      #		fitValid = FALSE	
      #		}
      #if(pfit["imf"]<(-0.1)) {
      #  comment = paste(comment,"imf<-0.1;") 
      #  fitValid = FALSE	
      #}	
      
      fracNA = sum(is.na(y2))/length(y2)
      #print( paste("fracNA",fracNA ) ) 
      
      if(fracNA >0.3) {
        fitValid = 0
        legend = sprintf("%s %s",legend,"too few data!")
      }
      
      legend = sprintf("%s mean(res^2)=%.3f; %s",legend,fitQuality,comment)
      
      if(fitValid) {
        #dm = rbind(dm,data.frame(treat=treat,exp=experiment,m="tau",x=1,y=pfit["tau"]))
        fitStatus = 1
      }
      
      tau = pfit["tau"]
      immfrac = pfit["immfrac"]
      
    } else {
      
      legend = "fitting failed!" 	
      fitValid = F
      fitQuality = NA
      
    }
    
  
    # add legend
    text(-0.4,legend, adj = c(0, 0) )
    print(legend)
    #text(-0.5,legend2, adj = c(0, 0) )
    
    
    ## ***************************************
    ## save plot
    ## ***************************************
    
    # todo: make this more general
    
    path = convertPathToRstyle(df.exp[iexp,4])  
    tmp = unlist(strsplit(path,"/"))
    subfolder = tmp[length(tmp)-1]
    basefolder = paste(tmp[1:(length(tmp)-2)],collapse="/")
    filename = unlist(strsplit(as.character(experiment),"__"))[2]
    filename = paste(filename,'--fit','.pdf',sep="")
    #print(file.path(tableFolder,subfolder,filename))
    dev.copy(pdf,file.path(tableFolder,subfolder,filename))  # save it in the actual current folder, but store the general "basepath"
    dev.off()
    
    print(paste(iexp,nrow(df.exp),tau,immfrac,fitStatus,filename))
    
    
    # add values
    df.exp$pathFit[iexp] = file.path(basefolder,subfolder,filename)
    df.exp$fit_tau[iexp] = tau
    df.exp$fit_imf[iexp] = immfrac
    df.exp$fit_status[iexp] = fitStatus
    df.exp$fit_deviation[iexp] = fitQuality  
    
    df.exp$tRec1[iexp] = tRec1
    df.exp$fracRec1[iexp] = fracRec1
    df.exp$tRec2[iexp] = tRec2
    df.exp$fracRec2[iexp] = fracRec2
    
    df.exp$intensCtrl[iexp] = ic_mean
    df.exp$numCtrl[iexp] = nc_mean
    
    
  }
  
  df.exp <<- df.exp
  
}


curveAnalysis_fitOneCurve <- function(x,y) {
  
  iFitStart = curveAnalysis.fitStart
  iFitEnd = min(curveAnalysis.fitEnd,length(x))
  
  # FITTING
  
  #dev.new()
  #plot(x, y, ylim=c(-0.5,1.5), xlab="time", ylab=cm)
  #lines(x, y) #, ylim=c(-0.5,1.5), xlab="time", ylab=cm)
  
  fit = NULL
  
  x2 = x[iFitStart:iFitEnd]  - x[iFitStart]
  y2 = y[iFitStart:iFitEnd]
  
  # fitting parameters
  tauStart = 5
  bdStart = 0.5
  imfStart = 0
  
  # weights (what is the best here?)
  w = 1/seq(length(x2))
  #w = 1/x2
  #w = rep(1,length(x2))
  tau = NA
  imf = NA
  fitStatus = 0
  
  # free bleach depth
  #try(fit <- nls(y2~(1-imf-(bd-imf)*exp(-x2/tau)), 
  #           weights = w, start = c(tau=tauStart, bd=bdStart, imf=imfStart), 
  #           #upper = c(tau=tauMax, bd=1, imf=1),
  #           #lower = c(tau=0, bd=0, imf=0),
  #           trace=F,na.action=na.exclude), 
  #           silent = TRUE)
  
  # fixed bleach depth
  try(fit <- nls(y2~(1-imf-(1-imf)*exp(-x2/tau)), 
                 weights = w, start = c(tau=tauStart, imf=imfStart), 
                 #upper = c(tau=tauMax, bd=1, imf=1),
                 #lower = c(tau=0, bd=0, imf=0),
                 trace=F,na.action=na.exclude), 
      silent = TRUE)
  
  
  #,lower = c(tau=0, bd=0, imf=0),
  #upper = c(tau=tauMax, bd=1, imf=1),
  #algorithm = "port" )
  
  
  fit.list = list()
  
  if(!is.null(fit)){
    y2fit = predict(fit, list(x2=x2)) # needs to be the same name than in the fitting!!!
    x2 = x2 + x[iFitStart]
    
    # add the fit
    #lines(x2, y2fit, lty = 2, col="red", lwd=3)  
    fit.list$x = x2
    fit.list$y = y2fit
    
    
    # add fit parameters 
    pfit = fit$m$getPars()
    legend = ""
    fitQuality = mean( residuals(fit)^2 , na.rm=T)
    comment = ""
    fitValid = TRUE
    for (c in names(pfit)) { 
      legend = sprintf("%s%s=%.2f; ",legend,c,pfit[c])
      #if(pfit[c]<0) {
      #	comment = paste(comment,c, "<0; ", sep='') 
      #	fitValid = FALSE
      #		}
    }
    #if(pfit["bd"]>1) {
    #  comment = paste(comment,"!!! bd>1;") 
    #		fitValid = FALSE	
    #		}
    if(pfit["imf"]<(-0.1)) {
      comment = paste(comment,"imf<-0.1;") 
      fitValid = FALSE	
    }	
    
    legend = sprintf("%s mean(res^2)=%.3f; %s",legend,fitQuality,comment)
    
    if(fitValid) {
      #dm = rbind(dm,data.frame(treat=treat,exp=experiment,m="tau",x=1,y=pfit["tau"]))
      fitStatus = 1
    }
    
    tau = pfit["tau"]
    imf = pfit["imf"]
    
    
  } else {
    
    legend = "fitting failed!" 	
    fitValid = F
    fitQuality = NA
    
  }
  
  print(legend)
  fit.list$legend = legend
  return(fit.list)
  
}


## *********************
## annotate
## *********************

handler_addTreatReplColumn <- function(h,...){
  
  print("adding annotation...")
  df.exp$treat_repl = NA
  for (i in 1:nrow(df.exp)) {
    repl = unlist(strsplit(as.character(df.exp[["replicate"]][i]),"--"))[[1]]
    treat = df.exp[["well"]][i]
    df.exp$treat_repl[i]  = paste(treat,repl,sep="__")
  }
  print("done!")
  df.exp <<- df.exp
  
}

handler_addTreatDateColumn <- function(h,...){
  
  addTreatDateColumn()
  
}

addTreatDateColumn <- function() {
  
  
  print("adding treat_date annotation to experiment table...")
  df.exp$date = NA
  df.exp$date = apply(df.exp, 1, function(z) {unlist(strsplit(as.character(z[["replicate"]]),"--"))[[1]]})
  df.exp$treat_date = paste(df.exp$well,df.exp$date,sep="__")
  df.exp <<- df.exp
  print("done.")
  
  d$treat_date = NA
  print("adding treat_date annotation to data table...")
  d$date = apply(d, 1, function(z) {unlist(strsplit(as.character(z[["repl"]]),"--"))[[1]]})
  d$treat_date = paste(d$treat,d$date,sep="__")
  d <<- d
  print("done.")
  
}


## *********************
## stuff
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

## *********************
## main GUI
## *********************

iNormStart = 1
iNormEnd = 5

curveAnalyzerGUI <- function() {
  
  w <- gwindow("Curve Analyzer", visible=F)
  gp <- ggroup(horizontal = FALSE, container=w)
  
  glabel("Curve Analyzer", container=gp)
  glabel("(c) Christian.Tischer@EMBL.DE", container=gp)
  glabel("version: 2011-11-28", container=gp)
  glabel("very beta!", container=gp)
  glabel("------------------------------------", container=gp)
  obj <- gbutton("Load tables", container = gp, handler = handler_loadTables)
  obj <- gedit("prefix for saving", container=gp, handler = function(h,...) {saveTables.prefix <<- svalue(h$obj)})
  obj <- gbutton("Save tables", container = gp, handler = handler_saveTables)
  obj <- gbutton("Concat data", container = gp, handler = handler_concatData)  
  glabel("------------------------------------", container=gp)
  obj <- gbutton("View experiment table", container = gp, handler = function(h,...) { edit(df.exp) } )  
  obj <- gbutton("View data table", container = gp, handler = function(h,...) { edit(d) } )  
  glabel("---NORMALISE---------------------------------", container=gp)
  # todo: add labels of what to enter
  obj <- gedit(iNormStart, container=gp, handler=function(h,...) {iNormStart <<- as.numeric(svalue(h$obj))})
  obj <- gedit(iNormEnd, container=gp, handler=function(h,...) {iNormEnd <<- as.numeric(svalue(h$obj))})
  obj <- gbutton("Normalise and point-wise QC", container = gp, handler = handler_normalisation )  
  glabel("----ANALYSE-------------------------------", container=gp)
  obj <- gbutton("Summarise Curves", container = gp, handler = handler_summaryGUI )  
  obj <- gbutton("Curve Analysis", container = gp, handler = handler_curveAnalysisGUI )  
  glabel("----ANNOTATE-------------------------------", container=gp)
  #obj <- gbutton("Add treat_repl column", container = gp, handler = handler_addTreatReplColumn )  
  obj <- gbutton("Add treat_date column", container = gp, handler = handler_addTreatDateColumn )  
  
  visible(w) <- T
  
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

## *********************
## run
## *********************

curveAnalyzerGUI()


