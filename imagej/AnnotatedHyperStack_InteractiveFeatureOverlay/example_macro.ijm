sDir = ""
sFiles = newArray(
"\\\\almf\\almf\\software\\scripts\\imagej\\AnnotatedHyperStack_InterativeFeatureOverlay\\example--C01.ome.tif",
"\\\\almf\\almf\\software\\scripts\\imagej\\AnnotatedHyperStack_InterativeFeatureOverlay\\example--C02.ome.tif",
"\\\\almf\\almf\\software\\scripts\\imagej\\AnnotatedHyperStack_InterativeFeatureOverlay\\example--C03.ome.tif"
);
sCZTWHM = "3-1-1-1-1-1"
sColors = "0.0.255-255.0.0-0.255.0-255.255.255-255.255.255"
sFontSizeColor = "16-255.0.0"
sTable  = "\\\\almf\\almf\\software\\scripts\\imagej\\AnnotatedHyperStack_InterativeFeatureOverlay\\example_table.txt"
Ext.install("AnnotatedHyperstack_MacroExt_2012_03_01")
Ext.loadImagesAsVirtualStack3(sCZTWHM, sFiles)
Ext.makeAnnotatedHyperStack(sCZTWHM,sColors,sTable,sFontSizeColor)
