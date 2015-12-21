require(Rook)
require(googleVis)

plate.nrow = 32
plate.ncol = 12
plate.nwells = plate.nrow*plate.ncol

plate.wellNumToRow = vector(length=plate.nwells);
plate.wellNumToCol = vector(length=plate.nwells);
iw = 1;
for(ir in 1:plate.nrow) {
  for(ic in 1:plate.ncol) {
    plate.wellNumToRow[iw] = ir;
    plate.wellNumToCol[iw] = ic;
    iw=iw+1;
  }	
}

readImageTable <- function(path) {
  print(paste("reading",path))
  df = read.table(file=path, header=T, sep=",", stringsAsFactors=F, check.names=T)
}

cPlateRepl="Metadata_plateNameRepl"
cWellNum = "Metadata_wellNum"
plate.nrow = 32
plate.ncol = 12
#df = readImageTable("/Users/tischi/Documents/emboHTM2012_focus_per_image_withHeader.csv")
#df = readImageTable("Z:/courses/EMBO_HTM_October_2012/P4_Cellprofiler_CellProfilerAnalyst_cellHTS2_Tischi/final/VSVG_screen_data/emboHTM2012_focus_per_image_withHeader.csv")
plates = unique(df[[cPlateRepl]])
currMeasurement = colnames(df)[1]
currPlateRepl = unique(df[[cPlateRepl]])[1]

df$row = plate.wellNumToRow[df[[cWellNum]]]
df$col = plate.wellNumToCol[df[[cWellNum]]]



newapp = function(env) {
  req = Rook::Request$new(env)
  res = Rook::Response$new()
  
  res$write('<form method="POST">\n')
  res$write('<select name="plate">')
  res$write(paste("<option>", plates , "</option>"))
  res$write('</select>')
  
  res$write('Choose a Binary file to Train:\n')
  res$write('<form method="POST" enctype="multipart/form-data">\n')
  res$write('<input type="file" name="data">\n')
  
  res$write('xdim:\n')
  res$write('<form method="POST">\n')
  res$write('<input type="text" name="xdim" value="12">\n')
  
  res$write('ydim:\n')
  res$write('<form method="POST">\n')
  res$write('<input type="text" name="ydim" value="25">\n')
  
  res$write('ncolors:\n')
  res$write('<form method="POST">\n')
  res$write('<input type="text" name="ncolors" value="8">\n')
  
  res$write('<input type="submit" name="Go!">\n</form>\n<br>')
  
  myNormalize = function (target) {
    return((target - min(target))/(max(target) - min(target)))
  }
  
  if (!is.null(req$POST())) {
    print("User clicked")
    data = req$POST()[["data"]]
    nr = as.integer(req$POST()[["xdim"]])
    nc = as.integer(req$POST()[["ydim"]])
    plate = req$POST()[["plate"]]
    print(plate)
    
    dfSub = subset(df,df[[cPlateRepl]]==currPlateRepl);
    #print(nrow(dfSub))
    dfSub$bubbleSize = rep(10,nrow(dfSub))
    #print(dfSub$bubbleSize)
    #print(dfSub$col)
    dfSub$id = rep('',nrow(dfSub))
    
    bc <- gvisBubbleChart(dfSub, 
                          idvar="id",
                          xvar="col",
                          yvar="row",
                          
                          sizevar="Image_ImageNumber",
                          options = list(
                            width='400', height='800',
                            colorAxis="{colors: ['lightblue', 'blue']}",
                            #colorAxis="{minValue: 0, maxValue: 10, 
                            #            colors: ['lightblue', 'blue'],
                            #            legend={position:'top'}}",
                            sizeAxis="{minValue: 5,  maxSize: 5}",
                            vAxis="{title: 'row',
                            viewWindowMode: 'explicit',
                            viewWindow:{min: 0, max:33}}",
                            hAxis="{title: 'col',
                            viewWindowMode: 'explicit',
                            viewWindow:{min: 0, max:13}}"
                          )
                          )
    
    res$write(bc$html$chart)
    
    #mat = matrix(10,nrow=nr,ncol=nc)
    #hash = "xxx"
    #png(paste("/tmp/", hash, ".png", sep = ""))
    #image(mat)
    #dev.off()
    #res$write(paste("<img src='", s$full_url("pic"), "/", hash, ".png'", " />", sep = ""))
  }
  res$finish()
}


s = Rhttpd$new()
#s$launch(name="myapp", app=app)

s$add(app = newapp, name = "visbin")
s$add(app = File$new("/tmp"), name = "pic")
s$start()
s$browse("visbin")