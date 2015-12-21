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

#pathData = "C:/Documents and Settings/Christian Tischer/My Documents/Projects/Sandra_Pepperkok/data/VSVG Transport Assay"
pathData = choose.dir(default = pathData, caption = "Select folder")
#pathData = "C:\\Users\\tischer\\Documents\\EMBL\\Sandra"
fileID = ".csv"
tableSep = ","

sepStrings = c("_","--")
iSepString = menu(sepStrings , graphics = TRUE, title = "select separator for filename")
iSplitPos = menu(c("1","2","3","4"), graphics = TRUE, title = "select position for filename separation")

xNormRangeMin = -100000
xNormRangeMax = 100   ### This needs to be adapated to the expression levels (intensities)

xNorm = 1000  ### divide all expression levels by this number

### binning (values AFTER division by xNorm)
xBins = c(xNormRangeMin,xNormRangeMax,200,400,800,1600,3200,6400,12800)

nSkipLines = 1  # lines to skip in the input files

plot2file = FALSE
pathResults = pathData


## *****************************************************************
## read data	
## *****************************************************************

files = list.files(path = pathData)

data = list()

for (file in files) {
	
	if(grepl(fileID ,file)) {	
		sTreatment = paste(unlist(strsplit(file,sepStrings[iSepString]))[1:iSplitPos],collapse="")
		dataTemp = read.table(file.path(pathData, file) , sep=tableSep , skip=nSkipLines, row.names=NULL) 
		data[[sTreatment]][[file]]$x = dataTemp[,1]
 		data[[sTreatment]][[file]]$y = dataTemp[,2]
 	}

}

treats = names(data)


## *****************************************************************
## data normalisation and binning and fitting
## *****************************************************************

		
for (iTreat in 1:length(treats)) {
	exps = names(data[[iTreat]])
	for (iExp in 1:length(exps)) {

		# get data
		datX = data[[iTreat]][[iExp]]$x 
		datY = data[[iTreat]][[iExp]]$y 
			
		# push back the normalised X values
		data[[iTreat]][[iExp]]$x = datX / xNorm	
		
		# normalisation Y
		if(xNormRangeMax > 0) {
			yNorm = mean(datY[which( datX<xNormRangeMax )])
			data[[iTreat]][[iExp]]$y = datY / yNorm		
		}

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
		
	}
}



## *****************************************************************
## save data as Excel Table
## todo:
## - make a function that svaes a table for one specific quantity
## *****************************************************************

## mean
out.table = data.frame()
experiments = list(); i=0
binning = names(data[[iTreat]][[iExp]]$yBinMean)

for (iTreat in 1:length(treats)) {
	exps = names(data[[iTreat]])
	for (iExp in 1:length(exps)) {
		i=i+1
		experiments[i] = exps[iExp]
		out.table = rbind(out.table, round(data[[iTreat]][[iExp]]$yBinMean,2))
	}
}

colnames(out.table) = binning
rownames(out.table) = experiments 
write.table(out.table, file.path(pathResults, paste(Sys.Date(),"--table--yBinMean.txt",sep='')), sep="\t", na="", quote=F) 


## number
out.table = data.frame()
experiments = list(); i=0
binning = names(data[[iTreat]][[iExp]]$yBinMean)

for (iTreat in 1:length(treats)) {
	exps = names(data[[iTreat]])
	for (iExp in 1:length(exps)) {
		i=i+1
		experiments[i] = exps[iExp]
		out.table = rbind(out.table, round(data[[iTreat]][[iExp]]$nDataPoints,2))
	}
}
colnames(out.table) = binning
rownames(out.table) = experiments 
write.table(out.table, file.path(pathResults, paste(Sys.Date(),"--table--nDataPoints.txt",sep='')), sep="\t", na="", quote=F) 


## *****************************************************************
## BELOW OPTIONAL PLAYGROUND FOR SAN DRA
## *****************************************************************




## *****************************************************************
## todo
## *****************************************************************

# - autosave the graphs
# - normalisation options: don't normalise
# - add error bars to curves

## *****************************************************************
## plot the data	
## *****************************************************************



## *****************************************************************
## compute summary statistics per treatment 
## *****************************************************************

if(0) {
dataSummary = list()
xValues = seq(1,length(xBins))

for (iTreat in 1:length(treats)) {
	
	dataSummary[[treats[iTreat]]]$xAvg = xValues
	for (ix in 1:length(xValues)) {	
		values = sapply(data[[iTreat]],function(z) z$yBinMean[ix])
		dataSummary[[treats[iTreat]]]$yAvg[ix] = mean(values, na.rm = TRUE) 
		dataSummary[[treats[iTreat]]]$ySem[ix] = sem(values)
		dataSummary[[treats[iTreat]]]$yMed[ix] = median(values)

	}
}
}



## *****************************************************************
## save treatment summary as table
## *****************************************************************

#out.table = data.frame()

#binning = names(data[[iTreat]][[iExp]]$yBinMean)
#for (iTreat in 1:length(treats))
	out.table = rbind(out.table, round(dataSummary[[iTreat]]$yAvg,2)) #ySem

colnames(out.table) = binning
rownames(out.table) = treats

write.table(out.table, file.path(pathResults, paste(Sys.Date(),"--table--TreatmentSummary.txt",sep='')), sep="\t", na="", quote=F) 



## *****************************************************************
## END OF CODE
## *****************************************************************


