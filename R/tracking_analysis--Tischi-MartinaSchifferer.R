#########################
## functions ("source" once at the beginning!)
#########################


## filter tracks
# returns new dataframe which only contains the tracks that survived the selection
filterTracks = function(d, label, measurement, minimum, maximum, summaryFunction) {
  
  t = tapply(d[[measurement]],d[[label]],FUN=summaryFunction)
  print(paste("# tracks",length(t)))
  ids = as.numeric(names(t[which((t>=minimum) & (t<=maximum))]))
  print(paste("# tracks after filtering",length(ids)))
  filteredTable = d[which(d[[cLabel]] %in% ids),]
  return(filteredTable)
  
}

## make new array where each entry is one track
# names are the track labels, values are the summaries along the track
summaryPerTrack = function(d, label, m, func, funcName) {
  t1 = tapply(d[[m]],d[[cLabel]],func)
  ds = data.frame(objectLabel = as.numeric(names(t1)), m1 = t1)
  names(ds)[2] = paste(m, funcName, sep="__")
  print(paste("# tracks",nrow(ds)))
  return(ds)  
}


summaryPerTrack2 = function(d, label, m1, func1, fname1, m2, func2, fname2) {
  t1 = tapply(d[[m1]],d[[cLabel]],func1)
  t2 = tapply(d[[m2]],d[[cLabel]],func2)
  ds = data.frame(objectLabel = as.numeric(names(t1)), m1 = t1, m2 = t2)
  names(ds)[2] = paste(m1,fname1,sep="__")
  names(ds)[3] = paste(m2,fname2,sep="__")
  print(paste("# tracks",nrow(ds)))
  return(ds)  
}


#summariesOfTracks = function(d, label, sl) {
#  
#  t1 = tapply(d[[cLabel]],d[[cLabel]],mean)
#  ds = data.frame(objectLabel = t1)
#  
#  for i in len
#  t2 = tapply(d[[m2]],d[[cLabel]],func2)
#  ds = data.frame(objectLabel = as.numeric(names(t1)), m1 = t1, m2 = t2)
#  names(ds)[2] = paste(m1,fname1,sep="__")
#  names(ds)[3] = paste(m2,fname2,sep="__")
#  return(ds)  
#}


## plotting functions

multipagepdf = function(d, cLabel, cX, cY, path) {
  
  pathPdf = paste0(path,"--plots--",cX,"--",cY,"--id",round(runif(1,1,10),2),".pdf")
  
  pdf(file=paste(pathPdf))
  
  for (iObject in unique(d[[cLabel]])) {
    ds = subset(d, d[[cLabel]]==iObject)
    plot(ds[[cX]],ds[[cY]],xlab=cX,ylab=cY)
    title(paste0("object label:", iObject))
  }
  
  dev.off()

}

#########################
## FUNCTIONS: END
#########################




#########################
## USER INPUT: START
#########################

pathTable = "//almf/almf/group/ALMFstuff/Tischi/projects/MartinaSchifferer/2015-01-19--SpotDetection_Tracking_IntensityMeasurement/data_example_tifStacks/movie01--cp-out/m1.csv"
pathTable = "C:/Users/Christian Tischer/Downloads/m1 (1).csv"
#pathTable = file.choose()

## obligatory columns 
cLabel = "TrackObjects_Label"

#########################
## USER INPUT: END
#########################


## read table
d = read.table(file=pathTable, header=T, skip=1, sep=",", stringsAsFactors=F, check.names=T)
colnames(d)

## view table
#edit(d)

## filter tracks
df = filterTracks(d, cLabel, measurement = "TrackObjects_Lifetime", minimum = 3, maximum = 1000, function(z) max(z,na.rm=T))


## multipage pdf of individual tracks
multipagepdf(df, cLabel, cX = "Metadata_TimeFrame", cY = "Intensity_MeanIntensity_m2SmoothTophat", pathTable)


## histograms of one feature per track: (1) make new table where each row is a feature of one track (2) plot using hist
ds = summaryPerTrack(df, cLabel, "TrackObjects_Lifetime", max, "max") 
hist(ds[["TrackObjects_Lifetime__max"]], breaks=20)


## summary of two features per track
ds2 = summaryPerTrack2(df, cLabel, 
                       m1 = "TrackObjects_Lifetime", max, "max", 
                       m2 = "Intensity_MeanIntensity_m2SmoothTophat", max, "max")
plot(ds2[["TrackObjects_Lifetime__max"]], ds2[["Intensity_MeanIntensity_m2SmoothTophat__max"]])

#t = tapply(ds2[["Intensity_MeanIntensity_m2SmoothTophat__mean"]],ds2[["TrackObjects_Lifetime__max"]],mean)

#################################################################### OLD STUFF



df = filterTracks(d,cLabel, cLifetime,1,1000, function(z) max(z,na.rm=T))
hist(df[[cTrackLength]],breaks=20)

intensity = summaryPerTrack(d,cLabel,cIntensity,max)
hist(intensity,breaks=20)

df = filterTracks(d, cLabel, cIntensity,0.04,1000, function(z) max(z,na.rm=T))
#p <- ggplot(d, aes(x=d[[cX]], y=d[[cY]], group=d[[cLabel]], colour=d[[color]])); p + geom_line()


hist(df[[cIntensity]],breaks=20)

## plot tracks
# all tracks in one plot
# x = x
# y = y
# color = measurement

color =  cIntensity

library(ggplot2)
p <- ggplot(d, aes(x=d[[cX]], y=d[[cY]], group=d[[cLabel]], colour=d[[color]])); p + geom_line()


## plot tracks 
# each track in one plot (multipage pdf)
# x = ...
# y = ...


