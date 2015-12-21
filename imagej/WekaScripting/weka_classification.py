from ij import IJ
from ij.plugin import Converter
from trainableSegmentation import WekaSegmentation
from fiji.threshold import Auto_Local_Threshold

classifierPath = "Z:/Tischi/projects/KatharinaSonnen/20150412--Automation_H2B-GFP/Automation_H2B-GFP/classifier.model"
imagePath = "Z:/Tischi/projects/KatharinaSonnen/20150412--Automation_H2B-GFP/Automation_H2B-GFP/H2B-GFP_20x_06zoom_512x512_10min-1.tif"
#imagePath = "Z:/Tischi/projects/KatharinaSonnen/20150412--Automation_H2B-GFP/Automation_H2B-GFP/H2B-GFP_20x_06zoom_512x512_10min--Crop--Substack.tif"

#from trainableSegmentation import Weka_Segmentation
#Weka_Segmentation.loadClassifier("Z:\\Tischi\\projects\\KatharinaSonnen\\20150412--Automation_H2B-GFP\\Automation_H2B-GFP\\classifier.model")
#Weka_Segmentation.applyClassifier("Z:\\Tischi\\projects\\KatharinaSonnen\\20150412--Automation_H2B-GFP\\Automation_H2B-GFP", "H2B-GFP_20x_06zoom_512x512_10min-1.tif", "showResults=true", "storeResults=false", "probabilityMaps=true", "")

imp = IJ.openImage(imagePath)
ws = WekaSegmentation(imp)  # create an instance
ws.loadClassifier(classifierPath) # load classifier
impProbabilities = ws.applyClassifier(imp, 0, True)
impProbabilities.show()
					
# show the classification results and rename the images in the stack to show the class names
#stack = imp_probabilities.getStack()
#for iClass in range(0, imp_probabilities.getImageStackSize()):
#  stack.setSliceLabel(ws.getClassLabel(iClass), iClass+1) 
#  imp_probabilities.setStack(stack)
#  imp_probabilities.setSlice(myClassNumber+1) 
#imp_probabilities.show()
				
