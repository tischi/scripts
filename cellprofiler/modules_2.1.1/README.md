# CellProfiler Modules

This repository contains modules for the free and open-source image analysis software CellProfiler (www.cellprofiler.org). 

If you have comments or questions please contact me:

Christian "Tischi" Tischer (tischitischer@gmail.com)


## Installation

- Start CellProfiler, go to "Preferences…" and change the "CellProfiler plugin directory" to an arbitrary folder on your computer (e.g. C:\myCellProfilerPlugins)
- Download the CellProfiler module that you like from this website and put it into above folder (you should download the file ending on __.py__ and not the one ending on __.pyc__)
- Now if you restart CellProfiler the module should appear in the list of modules that you can add to your pipeline


## Modules

### DisplayDataAndSaveAsPdf

Current version has been tested with CellProfiler 2.1.1.

This module appears in the "Data Tools" group of the CellProfiler modules.

The module is a simple extension of the original DisplayDataOnImage module. The additional feature is that it saves the displayed image as a pdf file. The issue is that if you paint numbers in an image they might not be well visible if there are not enough pixels (this becomes relevant if you want to save an image with numbers later using "SaveImages"). The pdf format solves this problem because it handles the text as vector graphics and thus can display it with much higher resolution than the underlying image.

Note that ImageJ will __not__ display the numbers in the pdf images; so you have to open it with another viewer.

### EnhanceEdgesPlus

Current version has been tested with CellProfiler 2.1.1.

This module appears in the "Image Processing" group of the CellProfiler modules.

The module is a simple extension of the original EnhanceEdges module. The additional feature is a Gaussian variance filter, which gives a high response if there is a lot of intensity fluctuations around the given pixel. The motivation to implement this filter was in fact not to find edges but because background regions of an image typically show a low variance. Thus, one can threshold the Gaussian variance image (keeping the low values) to automatically find image background regions, which are important to have for automatically measuring the background intensity in an given image.







