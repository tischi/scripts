rename("raw");

selectWindow("raw");
run("Duplicate...", "title=2Photon_zStack_GFP_01-1.lsm duplicate range=1-175");
run("Gaussian Blur 3D...", "x=1.5 y=1.5 z=3");
rename("gaussblurrsmall");

selectWindow("raw");
run("Duplicate...", "title=2Photon_zStack_GFP_01-1.lsm duplicate range=1-175");
run("Gaussian Blur 3D...", "x=4.5 y=4.5 z=9");
rename("gaussblurrlarge");
