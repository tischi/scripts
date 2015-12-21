## setwd("C:/Documents and Settings/Christian Tischer/My Documents/Projects/Sandra_Pepperkok/code")
## source("C:/Documents and Settings/Christian Tischer/My Documents/Projects/Sandra_Pepperkok/code/batch_curve_fitting.R")
## source("C:\\Users\\tischer\\Documents\\EMBL\\Sandra\\batch_curve_fitting.R")


library(gplots)
library(RColorBrewer)

sem <- function(z) {
	v = sd(z, na.rm=T)/sqrt(sum(!is.na(z)))
}


meanPMsem <- function(data,digits) {
	out = paste(round(mean(data, na.rm=T),digits=digits),'(',round(sem(data),digits=digits),')',sep='')
}


## *****************************************************************
## set up parameters ***********************************************
## *****************************************************************

fileID = "objects.csv"
tableSep = ","

sepStrings = c("--","_")

GUI = TRUE

# initial GUI
if (GUI) {
	pathData = choose.dir(caption = "Select folder")
	iSepString = menu(sepStrings , graphics = TRUE, title = "select separator for filename")
	iSplitPosTreat = menu(c("1","2","3","4"), graphics = TRUE, title = "select treatment position")
	iSplitPosRepl = menu(c("1","2","3","4"), graphics = TRUE, title = "select replicate position")
}


xNormRangeMin = -100000
xNormRangeMax = -50   ### This needs to be adapated to the expression levels (intensities)
xNorm = 1  ### divide all expression levels by this number

### binning (values AFTER division by xNorm)
xBins = c(xNormRangeMin,xNormRangeMax,200,400,800,1600,3200,6400,12800)
#xBins = c(xNormRangeMin,xNormRangeMax,1000000)


nSkipLines = 1  # lines to skip in the input files

plot2file = FALSE
pathResults = pathData


## *****************************************************************
## read data	
## *****************************************************************

files = list.files(path = pathData)

data = list()

firstFile = TRUE

for (file in files) {
	
	if(grepl(fileID ,file)) {	
		sTreatment = paste(unlist(strsplit(file,sepStrings[iSepString]))[iSplitPosTreat],collapse="")
		sReplicate = paste(unlist(strsplit(file,sepStrings[iSepString]))[iSplitPosRepl],collapse="")

		dataTemp = read.table(file.path(pathData, file), header = TRUE, sep=tableSep , skip=nSkipLines, row.names=NULL) 
		if (firstFile) {
			if (GUI) {
				cX = menu(colnames(dataTemp), graphics = TRUE, title = "select x column")
				cY = menu(colnames(dataTemp), graphics = TRUE, title = "select y column")
			}
			firstFile = FALSE
		} 
		data[[sTreatment]][[sReplicate]]$x = dataTemp[[cX]]
 		data[[sTreatment]][[sReplicate]]$y = dataTemp[[cY]]
 		data[[sTreatment]][[sReplicate]]$treat = sTreatment
 		data[[sTreatment]][[sReplicate]]$repl = sReplicate
 		data[[sTreatment]][[sReplicate]]$exp = paste(sTreatment,sReplicate,sep="_")

 	}
}

treats = names(data)



## *****************************************************************
## data normalisation plotting and binning and fitting
## *****************************************************************



pdf(file = file.path( pathResults, paste( Sys.Date(), "--analysis.pdf", sep='') ) )

normalisation = TRUE
		
for (iTreat in 1:length(treats)) {
	exps = names(data[[iTreat]])
	for (iExp in 1:length(exps)) {

		# get data
		datX = data[[iTreat]][[iExp]]$x 
		datY = data[[iTreat]][[iExp]]$y 
		treat = data[[iTreat]][[iExp]]$treat 
		repl = data[[iTreat]][[iExp]]$repl

		plot(datX,datY,main=paste(treat,repl),xlab="protein [YFP fluo]",ylab="VSVG ratio")

		if(normalisation) {

			# push back the normalised X values
			data[[iTreat]][[iExp]]$x = datX / xNorm	
		
			# normalisation Y
			yNorm = mean(datY[which( datX<xNormRangeMax )])
			data[[iTreat]][[iExp]]$y = datY / yNorm		
			
			# get the normalised data
			datX = data[[iTreat]][[iExp]]$x 
			datY = data[[iTreat]][[iExp]]$y 

			# binning
			binning = cut(datX,xBins)
			datYbinned = split(datY,binning)
			datXbinned = split(datX,binning)

			# median per bin
			data[[iTreat]][[iExp]]$xBinMedian = sapply(datXbinned,median) 		
			data[[iTreat]][[iExp]]$yBinMedian = sapply(datYbinned,median) 		
			# http://www.ats.ucla.edu/stat/r/library/bootstrap.htm
		
			# mean and sem per bin
			data[[iTreat]][[iExp]]$xBinMean = sapply(datXbinned,mean) 		
			data[[iTreat]][[iExp]]$yBinMean = sapply(datYbinned,mean) 		
			data[[iTreat]][[iExp]]$yBinSEM = sapply(datYbinned,sem) 		
			data[[iTreat]][[iExp]]$nDataPoints = sapply(datYbinned,length)

			# annotation
			data[[iTreat]][[iExp]]$xNormRangeMax = xNormRangeMax 		
			data[[iTreat]][[iExp]]$xNorm = xNorm
			data[[iTreat]][[iExp]]$yNorm = yNorm 		

			# make normalised annotated plot	
			plot(datX,datY,main=paste(treat,repl),xlab="protein [norm]",ylab="VSVG ratio [norm]")
			lines(x=c(min(datX),max(datX)),y=c(data[[iTreat]][[iExp]]$yBinMean[1],data[[iTreat]][[iExp]]$yBinMean[1]))
			for (xbin in xBins) {
				lines( x=c(xbin,xbin), y = c( min(datY), max(datY) ) )
			}

		}

		
	}
}

dev.off()


## *****************************************************************
## save data as Excel Table
## *****************************************************************

out.table = data.frame()
treatments = names(data)
mycolnames = names(data[[iTreat]][[iExp]]$yBinMean)
myrownames = list(); iRow=0;

for (treat in treatments) {
	replicates = names(data[[treat]])
	for (repl in replicates) {
		myrownames[length(myrownames) + 1] = paste(data[[treat]][[repl]]$exp,"mean",sep="_")
		out.table = rbind(out.table, round(data[[treat]][[repl]]$yBinMean,2))
		myrownames[length(myrownames) + 1]  = paste(data[[treat]][[repl]]$exp,"sem",sep="_")
		out.table = rbind(out.table, round(data[[treat]][[repl]]$yBinSEM,2))
		myrownames[length(myrownames) + 1]  = paste(data[[treat]][[repl]]$exp,"n",sep="_")
		out.table = rbind(out.table, round(data[[treat]][[repl]]$nDataPoints ,2))
	}
}

colnames(out.table) = mycolnames 
rownames(out.table) = myrownames 
write.table(out.table, file.path(pathResults, paste(Sys.Date(),"--table.txt",sep='')), sep="\t", na="", quote=F) 

