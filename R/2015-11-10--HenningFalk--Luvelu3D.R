#
# Libraries
#
# install.packages("rgl")
# install.packages("sphereplot")
# install.packages("RSEIS")


library(rgl)
library(sphereplot)
library(RSEIS)


#
#  Read Table
#

pathTable = file.choose()


IMARIS = 1
TRACKMATE = 0

if(TRACKMATE) {
  ## read tab delimited
  d = read.table(file=pathTable, header=T, skip=0, sep="\t", stringsAsFactors=F, check.names=T)
  cx = "POSITION_X"
  cy = "POSITION_Y"
  cz = "POSITION_Z"
  ct = "POSITION_T"
  ci = "MEAN_INTENSITY01"
}

if(IMARIS) {
  ## read csv delimited
  d = read.table(file=pathTable, header=T, skip=2, sep=",", stringsAsFactors=F, check.names=T)
  cx = "Position.X"
  cy = "Position.Y"
  cz = "Position.Z"
  ct = "Time"
  ci = "Mean.Ch1"
}

colnames(d)


#
# functions
#


fit_sphere <- function(x,y,z,r0) {
      
  ## function to minimize
  costfunc <- function(pars) {
    x.center <- pars[1]
    y.center <- pars[2]
    z.center <- pars[3]
    rhat <- pars[4]
    
    r <- sqrt( (x-x.center)^2 + (y-y.center)^2 + (z-z.center)^2 )
    cost = sum( (r-rhat)^2 )
    #print(cost)
  
    return(cost)
  }
  
  ## run optim
  out <- optim( c(mean(x),mean(y),mean(z),r0), method="BFGS", costfunc)
  
  s = list()
  s$radius = out$par[4]
  s$center = c(out$par[1],out$par[2],out$par[3])
  return(s)  
} 


fit_plane <- function(x,y,z,nx0,ny0,nz0) {
      
  ## function to minimize
  costfunc <- function(pars) {
    nx <- pars[1]
    ny <- pars[2]
    nz <- pars[3]
    sz <- pars[4]
    
    d <- (x*nx) + (y*ny) + ((z-sz)*nz)
    cost = sum( d^2 )
    #print(cost)
  
    return(cost)
  }
  
  ## run optim
  out <- optim( c(nx0,ny0,nz0,mean(z)), method="BFGS", costfunc)
  
  s = list()
  s$support = c(0,0,out$par[4])
  s$normal = c(out$par[1],out$par[2],out$par[3])
  return(s)  
} 

fit_minimal_projection <- function(x,y,z,theta0,phi0) {
      
  ## function to minimize
  costfunc <- function(pars) {
    theta <- pars[1]
    phi <- pars[2]

    nx = cos(theta)*sin(phi)
    ny = sin(theta)*sin(phi)
    nz = cos(phi)
    
    proj_z <- (x*nx) + (y*ny) + (z*nz)
    cost = sd( proj_z )
    #print(cost)
  
    return(cost)
  }
  
  ## run optim
  out <- optim( c(theta0,phi0), method="BFGS", costfunc)
  
  nx = cos(out$par[1])*sin(out$par[2])
  ny = sin(out$par[1])*sin(out$par[2])
  nz = cos(out$par[2])
 
  s = list()
  s$norm_vector = c(nx,ny,nz)
  return(s)  
} 



fit_3D_two_clusters_kmeans <- function(x,y,z){
  
  dxyz = data.frame(x=x,y=y,z=z)
  fit <- kmeans(dxyz,2)
  # get cluster means 
  cc <- aggregate(dxyz,by=list(fit$cluster),FUN=mean)
  l=list()
  l$x1 = c(cc[1,2],cc[1,3],cc[1,4])
  l$x2 = c(cc[2,2],cc[2,3],cc[2,4])
  return(l)
  
}

plot_lat_long <- function(x,y,z,.col,.xlim,.ylim,center=c(0,0,0),scale=1) {
  
  s <- car2sph(x-center[1], y-center[2], z-center[3], deg = TRUE)
  par(bg = "gray")
  plot(x=scale*s[,1],y=scale*s[,2],col=.col, pch=16, cex=0.3, xlim=.xlim, ylim=.ylim)
}

plot_mercator <- function(x,y,z,.col,center=c(0,0,0), radius) {
  
  # radius = sqrt(x^2 + y^2 + z^2)
  # long = atan2(y, x)
  # lat = asin(z/radius)
  s <- car2sph(x-center[1], y-center[2], z-center[3], deg = FALSE)
  
  # x = R * longitude
  # y = R * log( tan( (latitude + pi/2)/2 ) )
  
  x = radius * s[,1]
  y = radius * log( tan( (s[,2] + pi/2)/2 ) )
  
  par(bg = "gray")
  plot(x=s[,1], y=s[,2], col=.col, pch=16, cex=0.3,
       xlim=c(-1,1), ylim=c(-1,1)) # fix this, the d$Col

}

make_colormap <- function(values, vmin, vmax) {
  
  rbPal = colorRampPalette(c("white","red"))
  v = round( 100 * (values - vmin) / (vmax - vmin) )
  v[which(v>100)] = 100
  v[which(v<1)] = 1
  colors = rbPal(100)[v]
  return(colors)
  
}

coordinate_transform_01 <- function(x,y,z,center,v1,v2,rotY=0,rotZ=0) {
  
  # compute base vectors for new coordinate system
  
  # new (0,0,0)
  x0 = center
  # base vector x1 in the middle of v1 and v2
  x1 = (v1-x0+v2-x0)/2
  # base vector x2 perpendicular to v1 and v2
  x3 = xprod(v1-x0, v2-x0) / sqrt((v1-x0) %*% (v1-x0))
  if((x3[3]-x0[3])<0) x3 = -x3 
  # base vector x3 perpendicular to x1 and x2
  x2 = xprod(x1,x3) / sqrt(x1 %*% x1)
  
  ## add new coordinates to plot3d
  plot3d(x1[1]+x0[1],x1[2]+x0[2],x1[3]+x0[3], col="red", add=T, size=10, type="p")
  plot3d(x2[1]+x0[1],x2[2]+x0[2],x2[3]+x0[3], col="red", add=T, size=10, type="p")
  plot3d(x3[1]+x0[1],x3[2]+x0[2],x3[3]+x0[3], col="red", add=T, size=10, type="p")
  

  ## normalise new base vectors
  ax = x1 / sqrt(x1 %*% x1)
  ay = x2 / sqrt(x2 %*% x2)
  az = x3 / sqrt(x3 %*% x3)
  
  
  ## compute transfromed coordinates bx,by,bz
  N = length(ds[[cx]])
  bx = vector(length=N)
  by = bx
  bz = by
  for (j in 1:N) {
    
    ## transformation according to new base vectors
    v = c(x[j]-x0[1], y[j]-x0[2], z[j]-x0[3])
    bx[j] = ax %*% v
    by[j] = ay %*% v
    bz[j] = az %*% v    
    
    ## rotate around y-axis to reset north pole
    theta = rotY
    tx = c(cos(theta), 0,sin(theta)) %*% c(bx[j],by[j],bz[j])
    ty = c(       0  , 1,         0) %*% c(bx[j],by[j],bz[j])
    tz = c(-sin(theta),0,cos(theta)) %*% c(bx[j],by[j],bz[j])
    bx[j] = tx
    by[j] = ty
    bz[j] = tz    
    
    ## around z-axis to set the latitude
    theta = rotZ
    tx = c(cos(theta),  -sin(theta), 0) %*% c(bx[j],by[j],bz[j])
    ty = c(sin(theta),  cos(theta), 0) %*% c(bx[j],by[j],bz[j])
    tz = c(0,0,1) %*% c(bx[j],by[j],bz[j])
    bx[j] = tx
    by[j] = ty
    bz[j] = tz      
  }
  
  l = list()
  l$x = bx
  l$y = by
  l$z = bz
  return(l)
  
}

#
# Analyze time series
#

d$col <- make_colormap(d[[ci]],20,150)

for (i in unique(d[[ct]])) {
  
  # subset time-point
  dt = subset(d, d[[ct]]==i)
  
  # plot3d data
  ds = subset(dt, dt[[ci]]>10)
  plot3d(ds[[cx]], ds[[cy]], ds[[cz]], col=ds$col, size=4, aspect=F, axes=T, expand=1.3, xlab="x", ylab="y", zlab="z"); bg3d("grey")
  
  # fit sphere
  ds = subset(dt, dt[[ci]]>20)
  s <- fit_sphere(ds[[cx]],ds[[cy]],ds[[cz]], 430)
  print(paste("time point",i,"radius",round(s$radius),"center",round(s$center[1]),round(s$center[2]),round(s$center[3])))  
  ## refresh point cloud
  plot3d(ds[[cx]], ds[[cy]], ds[[cz]], col=ds$col, size=4, aspect=F, axes=T, expand=1.3, xlab="x", ylab="y", zlab="z"); bg3d("grey")
  ## add sphere center to plot
  plot3d(s$center[1],s$center[2],s$center[3], col="blue", add=T, size=10, type="p")
  ## add sphere to plot3d
  plot3d(s$center[1],s$center[2],s$center[3], col="blue", add=T, size=10, type="s",radius=s$radius, alpha=0.3)
  
  # fit plane to bright points
  ds = subset(dt, dt[[ci]]>300)
  plot3d(ds[[cx]], ds[[cy]], ds[[cz]], col=ds$col, size=4, aspect=F, axes=T, expand=1.3, xlab="x", ylab="y", zlab="z"); bg3d("grey")
  fit_plane <- function(x,y,z,nx0,ny0,nz0)

  # fit direction of north-pole to bright points
  ds = subset(dt, dt[[ci]]>300)
  mp <- fit_minimal_projection(ds[[cx]]-s$center[1], ds[[cy]]-s$center[2], ds[[cz]]-s$center[3], theta0 = 0, phi0 = 0.1) 
  ## add north pole to plot
  np = (mp$norm_vector*s$radius)+s$center
  plot3d(np[1],np[2],np[3], col="black", add=T, size=10, type="p")
  
  # fit two clusters
  ds = subset(dt, dt[[ci]]>20)
  cm <- fit_3D_two_clusters_kmeans(ds[[cx]],ds[[cy]],ds[[cz]])
  ## add cluster centers to plot 
  plot3d(cm$x1[1], cm$x1[2], cm$x1[3], col="black", add=T, size=10, type="p")
  plot3d(cm$x2[1], cm$x2[2], cm$x2[3], col="black", add=T, size=10, type="p")
  
  # coordinate transformation
  ds = subset(dt, dt[[ci]]>10)
  ct <- coordinate_transform_01(ds[[cx]],ds[[cy]],ds[[cz]],s$center,cm$x1,cm$x2,rotY=0,rotZ=0) 
  ## plot3d transformed data 
  plot3d(ct$x, ct$y, ct$z, col=ds$col, size=4, aspect=F, axes=T, expand=1.3, 
         xlab="x", ylab="y", zlab="z", box=F); bg3d("grey")
  

  # compute and plot 2D projections
  #ds = subset(dt, dt[[ci]]>20)
  #jpeg(paste0("Y:\\tischer\\Henning\\jpeg_out2\\",i,".jpeg"), quality=100)
  plot_lat_long(ct$x, ct$y, ct$z, ds$col,.xlim=c(-180,180),.ylim=c(-180,180),center=c(0,0,0),scale=s$radius/437)
  #plot_mercator(bx,by,bz,ds$Col,center=c(0,0,0), radius=s$radius)
  #dev.off()
}
#dev.off()




# TODO: 
## - find the Northpole



#
# STUFF
#





# subset spots
d = draw
d = subset(d, d[[ci]]>10)



# plot
i = 40; ds = subset(d, d[[ct]]==i);  plot3d(ds[[cx]], ds[[cy]], ds[[cz]], col=ds$Col, size=4, aspect=F, axes=T, expand=1.3, xlab="x", ylab="y", zlab="z"); bg3d("grey")

# cluster
dclust = subset(ds,select=c(POSITION_X,POSITION_Y,POSITION_Z,MEAN_INTENSITY01 ))
fit <- kmeans(dclust,2)
# get cluster means 
cc <- aggregate(dclust,by=list(fit$cluster),FUN=mean)
# add cluster means to plot 
plot3d(cc[1,2],cc[1,3],cc[1,4], col="black", add=T, size=20)
plot3d(cc[2,2],cc[2,3],cc[2,4], col="black", add=T, size=20)

# show clusters
i = 19; ds = subset(d, d[[ct]]==i);  plot3d(ds[[cx]], ds[[cy]], ds[[cz]], col=fit$cluster, size=4, aspect=F, axes=T, expand=1.3, xlab="x", ylab="y", zlab="z"); bg3d("grey")

# plot
i=18; ds = subset(d, d[[ct]]==i);  plot3d(ds[[cx]], ds[[cy]], ds[[cz]], col=ds$Col, size=4, aspect=F, axes=T, expand=1.3, xlab="x", ylab="y", zlab="z"); bg3d("grey")


# process time series
#pathPdf = paste0(pathTable,"--plot_lat_long--id",round(runif(1,1,10),2),".pdf")
#pdf(file=paste(pathPdf))



out
plot3d(out$par[1],out$par[2],out$par[3],col=rgb(0.3,0.3,0.3),alpha=0.5, add=T, type="s",radius=out$par[4])
#plot3d(mean(x),mean(y),mean(z),col=rgb(0,1,0.3),alpha=0.5, add=T,type="s",radius=diff(range(x))/2) 


# convert to spherical coordinates
library(sphereplot)
s <- car2sph(x-out$par[1], y-out$par[2], z-out$par[3], deg = TRUE)
m <- ds[[ci]]
par(bg = "gray")
plot(x=s[,1],y=s[,2],col=ds$Col, pch=16, cex=0.5)


# plot as movie
for (i in range) {
  Sys.sleep(0.5)
  ds = subset(d, d[[ct]]==i)
  print(mean(ds[[ci]]))
  plot3d(ds[[cx]], ds[[cy]], ds[[cz]], col=ds$Col, size=4, aspect=F); bg3d("grey")
}
