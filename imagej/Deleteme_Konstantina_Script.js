imp = IJ.getImage();
IJ.run(imp, "Scale...", "x=0.25 y=0.25 z=1.0 interpolation=Bilinear average process create");
IJ.run("3D Fast Filters","filter=Median radius_x_pix=7.0 radius_y_pix=7.0 radius_z_pix=0.0 Nb_cpus=32");
IJ.run(imp, "3D Iterative Thresholding", "min_vol_pix=1000 max_vol_pix=15000 min_threshold=0 criteria=VOLUME threshold=STEP value=3 starts");
