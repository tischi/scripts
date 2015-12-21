tablename = "Z:/microscopes/Olympus_TIRF/2014-21-10--ScanR--StabilityTest/TischiTest__DimaSetup_001/AcquisitionLog2.dat"
x = read.table(tablename)
x$s = unlist(lapply(x$V9, function(x) toString(x)))
x$time = unlist(lapply(x$s, function(x) as.numeric(strsplit(x,"=")[[1]][2])))

dt = diff(x$time)
plot(x$time)
plot(dt)
