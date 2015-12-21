//package ij.plugin;
import ij.*;
import ij.io.*;
import ij.gui.*;
import ij.plugin.*;
import ij.plugin.frame.*;
import ij.process.*;

import ij.macro.Functions;
import ij.macro.MacroExtension;
import ij.macro.ExtensionDescriptor;

import java.awt.Color;
import java.awt.image.*;
import java.awt.*;
import java.awt.event.*;
import java.lang.String.*;
import java.util.*;
import java.io.*;
import java.lang.*;

import java.lang.Double;
import java.awt.event.MouseAdapter;


public class AnnotatedHyperstack_MacroExt_2012_03_01 implements PlugIn, MacroExtension {

	// VirtualStack3 attributes
	private static boolean grayscale;
	private static double scale = 100.0;
	private int n;
	private String filter;
	private String info1;
	//

  	static final Color[] colors = {Color.red, Color.green, Color.blue, Color.white, Color.cyan, Color.magenta, Color.yellow};
    	
	public void run(String arg) {
		//IJ.log("installing AnnotatedHyperstack_MacroExt...");	
	 	Functions.registerExtensions(this);
    
	}

	private ExtensionDescriptor[] extensions = {
		ExtensionDescriptor.newDescriptor("loadImagesAsVirtualStack3", this, ARG_STRING, ARG_ARRAY),
		ExtensionDescriptor.newDescriptor("makeAnnotatedHyperStack", this, ARG_STRING, ARG_STRING, ARG_STRING, ARG_STRING)
	};
	
	public ExtensionDescriptor[] getExtensionFunctions() {
		return extensions;
	};

	public String handleExtension(String name, Object[] args) {
   		
		// VirtualStack3 handler
		if (name.equals("loadImagesAsVirtualStack3")) {
			String sHyper = (String)args[0]; 
			Object sFiles[] = (Object[])args[1];
			Integer nW = Integer.parseInt(sHyper.split("-")[3]);
			Integer nH = Integer.parseInt(sHyper.split("-")[4]);
			Integer nTiles = nW*nH;
			loadImagesAsVirtualStack3(sFiles, nW, nH);
		}

		else if (name.equals("makeAnnotatedHyperStack")) {
			String sHyper = (String)args[0]; 
			Integer nC = Integer.parseInt(sHyper.split("-")[0]);
			Integer nZ = Integer.parseInt(sHyper.split("-")[1]);
			Integer nT = Integer.parseInt(sHyper.split("-")[2]);
			Integer nW = Integer.parseInt(sHyper.split("-")[3]);
			Integer nH = Integer.parseInt(sHyper.split("-")[4]);
			Integer vMode = Integer.parseInt(sHyper.split("-")[5]);
			
			String sColors = (String)args[1];
			String sFeatureFile = (String)args[2];
			
			String sFontSizeColor = (String)args[3];
			int FontSize = Integer.parseInt(sFontSizeColor.split("-")[0]);
			String sFontColor = sFontSizeColor.split("-")[1];
			
			ImagePlus imp = IJ.getImage(); imp.hide();
			makeHyperStack(imp, nC, nZ, nT, nW, nH, vMode, sColors);
			imp = IJ.getImage();// in order to update the properties of imp
			
			IJ.log("FeatureFile = "+sFeatureFile);
			if(nC>1||sFeatureFile.contains(".txt")) {
				FeatureOverlay fo = new FeatureOverlay(imp, sFeatureFile, FontSize, sFontColor);
				}

		}
		
	  	return null;
		
	}

	private void loadImagesAsVirtualStack3(Object[] sFiles, Integer nW, Integer nH) {
		
		IJ.log("   ");
		try {
			VirtualStack3 stack = new VirtualStack3(sFiles);
			stack.setTilesWH(nW, nH);
			ImagePlus imp = new ImagePlus("Stack", stack);
			imp.show();
		}  catch (Exception e) {
			IJ.log("Error in VirtualStack3 s \n\""+e.getMessage()+"\"\n");
			ImagePlus imp = IJ.createImage("error", "black", 500, 500, 1);
			imp.show();
			//Overlay overlay = imp.getOverlay();
			Overlay overlay = new Overlay();
			Font font = new Font(null);
			float fontsize = 20; font = font.deriveFont(fontsize);
			Roi roi = new TextRoi(100, 100, "THE LIMS-MAN IS WATCHING YOU!!!!", font);	
			roi.setStrokeColor(new Color(200, 200, 0));
			overlay.add(roi);	
			imp.setOverlay(overlay);
			imp.updateAndDraw();
			throw new RuntimeException(Macro.MACRO_CANCELED); 
		}
		
	}
    

    	void makeHyperStack(ImagePlus imp, int nC, int nZ, int nT, int nW, int nH, int vMode, String sColors) {
     
            	IJ.log("*** makeHyperStack ***");
		
		String[] cls = sColors.split("-");
		
		VirtualStack3 stack = (VirtualStack3)imp.getImageStack();
		IJ.log("data = "+stack);
		
		imp = new ImagePlus("",stack); // calls ip.getprocessor for 1st channel
		imp.setDimensions(nC, nZ, nT);
		IJ.log("channels = "+nC);
		IJ.log("slices = "+nZ);
		IJ.log("frames = "+nT);
		
		// set colors
		if(nC>1) {
			// vMode: 1=composite, 2=color, 3=grayscale
			CompositeImage ci = new CompositeImage(imp, vMode); // calls ip.getprocessor for 1st channel
			ci.setOpenAsHyperStack(true);
		
			LUT[] luts = ci.getLuts();
			for (int i=0; i<nC ; i++) {
				String[] cl = cls[i].split("\\.");
				int red = Integer.parseInt(cl[0]);
				int green = Integer.parseInt(cl[1]);
				int blue = Integer.parseInt(cl[2]);
				//int alpha = Integer.parseInt(cl[3]);
				luts[i] = ci.createLutFromColor(new Color(red, green, blue));	
				IJ.log("channel color "+cls[i]);
				ci.updatePosition(i+1, 1, 1);
				ci.setChannelLut(luts[i]);
			}	
			
			ci.updatePosition(1, 1, 1);
			ci.resetDisplayRanges();  // calls ip.getprocessor for all channels
			ci.show();
						
		} else {
			//imp.setProcessor(ip);
			imp.setOpenAsHyperStack(true);
			imp.show();
		}
		
	}
   
}




class FeatureOverlay extends PlugInFrame implements PlugIn, ItemListener, ImageListener, ActionListener {

    private Choice choice;
    private Checkbox[] checkbox;
    private Button flattenButton;
    private static String flattenLabel = "Flatten";
    private static Frame instance;
    private int id;
    private static Point location;
    private PopupMenu pm;
    private String[] sFeatureNames;
    private String sTable;
    private int currentFeature = 0;
    private int xFeatNum;
    private int yFeatNum;
    private int currentFrame = 1;
    private boolean featureTableExits = false;
    private int fontSize;
    private String fontColor;
    private ImagePlus impFO;
    private String sTableFileName;
    
    public FeatureOverlay(ImagePlus imp, String aTableFileName, int aFontSize, String aFontColor) {
	    
	    super("Select"); 
	    if (instance!=null) {
		    instance.toFront();
		    return;
	    }
	    
	    sTableFileName = aTableFileName;
	    fontSize = aFontSize;
	    fontColor = aFontColor;
	
	    IJ.log(" ");
	    IJ.log("*** FeatureOverlay ***");
	    
	    //IJ.log("isComposite3 "+imp.isComposite());
	    impFO = imp;
  
		// adding mouselistener
 		ML listener = new ML();			
		impFO.getWindow().getCanvas().addMouseListener(listener);


	    IJ.log("init Selection Window.."); 
	    ImagePlus.addImageListener(this);
	    WindowManager.addWindow(instance);

	    GridBagLayout gridbag = new GridBagLayout();
	    GridBagConstraints c = new GridBagConstraints();
	    setLayout(gridbag);
	    int y = 0;
	    c.gridx = 0;
	    c.gridy = y++;
	    c.gridwidth = 1;
	    c.fill = GridBagConstraints.BOTH;
	    c.anchor = GridBagConstraints.CENTER;
	    int margin = 32;
	    if (IJ.isVista())
		    margin = 40;
	    else if (IJ.isMacOSX())
		    margin = 18;
	    c.insets = new Insets(10, margin, 10, margin);
	    
	    if( sTableFileName.contains(".txt") ) {
		    IJ.log("There is a feature table.");
		    if( sTableFileName.contains("http://") ) {
			    sTable = IJ.openUrlAsString(sTableFileName);
		    } else {
			   sTable = this.openAsString(sTableFileName);
		    }
			    
		    featureTableExits = true;
		    choice = new Choice();
	 	    
	 	    // get table header
	 	    sFeatureNames = sTable.split("\n")[0].split("\t");
		    sFeatureNames[0] = "no label";
		    
		    int iFeature = 0;
		    for (String sFeatureName : sFeatureNames) {
			    
			    if(sFeatureName.equals("X")) {
				    xFeatNum = iFeature; 
				    IJ.log("x feat num = "+iFeature);
			    }
			    
			    if(sFeatureName.equals("Y")) {
				    yFeatNum =iFeature; 
				    IJ.log("y feat num = "+iFeature);
			    }
			    
			    choice.addItem(sFeatureName);
			    
			    iFeature += 1;
		    }
		    
		    choice.select(0);
		    choice.addItemListener(this);
		    add(choice, c);
		    
		    //ImagePlus imp = WindowManager.getCurrentImage();
		    
	    }
	

	    // create the header for the clicking table
	    	String sHeader = "table_filename";
		for (int iFeature = 1; iFeature<sFeatureNames.length; iFeature++) {
			//listValues.add(sRows[iCellRow].split("\t")[iFeature]);
			sHeader = sHeader.concat(",").concat(sFeatureNames[iFeature]);
			//	IJ.write(","+sRows[iCellRow].split("\t")[iFeature]);
		}
		IJ.write(sHeader);
	
	    
	    // add the channel checkboxes if approriate
	    
	    CompositeImage ci = getImage();
	    if (ci!=null && ci.getNChannels()>1) {	    
		    IJ.log("This data set has "+ci.getNChannels()+" channels");
		    IJ.log("Initialising channel checkboxes...");
		    //get the EventManager of the current Image
		    //getCurrentSlice()
		    int nCheckBoxes = ci.getNChannels();
		    if (nCheckBoxes>CompositeImage.MAX_CHANNELS)
			    nCheckBoxes = CompositeImage.MAX_CHANNELS;
		    checkbox = new Checkbox[nCheckBoxes];
		    for (int i=0; i<nCheckBoxes; i++) {
			    checkbox[i] = new Checkbox("Channel "+(i+1), true);
			    c.insets = new Insets(0, 25, i<nCheckBoxes-1?0:10, 5);
			    c.gridy = y++;
			    add(checkbox[i], c);
			    checkbox[i].addItemListener(this);
		    }
	    }
		    
	    c.insets = new Insets(0, 15, 10, 15);
	    c.fill = GridBagConstraints.NONE;
	    c.gridy = y++;
	    
	    flattenButton = new Button(flattenLabel);
	    flattenButton.addActionListener(this);
	    add(flattenButton, c);
	   
	    
	    update();
	    addKeyListener(IJ.getInstance());  // ImageJ handles keyboard shortcuts
	    setResizable(true);
	    pack();
	    if (location==null) {
		    GUI.center(this);
		    location = getLocation();
	    } else
            setLocation(location);
	    setVisible(true);

    }
    
    
    public void respondToMouseClick(){
 		Point p = impFO.getCanvas().getCursorLoc();
 		IJ.log("clicked " + Double.toString(p.x) + ", " + Double.toString(p.y)); //+ str(imp))
 		getAllValuesForClosestCell(p.x, p.y) ;
	}
	
   
   class ML extends MouseAdapter {
	public void mousePressed(MouseEvent event){
		//ImageCanvas canvas = (ImageCanvas) event.getSource();
		//imp = canvas.getImage();
		// TODO: check whether this is the correct image
		respondToMouseClick();
		}
	}


    
    private String openAsString(String path) {
		int max = 5000;
		
		String str = "";
		File file = new File(path);
		if (!file.exists())
			IJ.log("File not found");
		try {
			StringBuffer sb = new StringBuffer(5000);
			if (false) {
				//int len = (int)file.length();
				//if (max>len || (path.endsWith(".txt")&&!specifiedMax))
			//		max = len;
			//	InputStream in = new BufferedInputStream(new FileInputStream(path));
			//	DataInputStream dis = new DataInputStream(in);
			//	byte[] buffer = new byte[max];
			//	dis.readFully(buffer);
			//	dis.close();
			//	char[] buffer2 = new char[buffer.length];
			//	for (int i=0; i<buffer.length; i++)
			//		buffer2[i] = (char)(buffer[i]&255);
			//	str = new String(buffer2);
			} else {
				BufferedReader r = new BufferedReader(new FileReader(file));
				while (true) {
					String s=r.readLine();
					if (s==null)
						break;
					else
						sb.append(s+"\n");
				}
				r.close();
				str = new String(sb);
			}
		}
		catch (Exception e) {
			IJ.log("File open error \n\""+e.getMessage()+"\"\n");
		}
		return str;
	}

    
    public void update() {
        CompositeImage ci = getImage();
        if (ci==null) return;
        int n = checkbox.length;
        int nChannels = ci.getNChannels();
        if (nChannels!=n && nChannels<=CompositeImage.MAX_CHANNELS) {
            instance = null;
            location = getLocation();
            close();
            // new FeatureOverlay("hallo");
            return;
        }
        boolean[] active = ci.getActiveChannels();
        for (int i=0; i<checkbox.length; i++)
            checkbox[i].setState(active[i]);
    }
    

    void addPopupItem(String s) {
        MenuItem mi=new MenuItem(s);
        mi.addActionListener(this);
        pm.add(mi);
    }


    CompositeImage getImage() {
        //ImagePlus imp = WindowManager.getCurrentImage();
        ImagePlus imp = impFO;
	if (imp==null || !imp.isComposite())
            return null;
        else
            return (CompositeImage)imp;
    }


    public void itemStateChanged(ItemEvent e) {
        
	//ImagePlus imp = WindowManager.getCurrentImage();
        ImagePlus imp = impFO;
	if (imp==null) return;
	//IJ.log("item changed.");
	
	Object source = e.getSource();

	//if (source==choice) {
	if (source instanceof Choice) {
		IJ.log("selected feature changed.");
		currentFeature = ((Choice)source).getSelectedIndex();
		drawOverlay(impFO);
	} 
	else if (source instanceof Checkbox)
	{
            CompositeImage ci = (CompositeImage)imp;
	    for (int i=0; i<checkbox.length; i++) {
                Checkbox cb = (Checkbox)source;
                if (cb==checkbox[i]) {
                    if (ci.getMode()==CompositeImage.COMPOSITE) {
                        boolean[] active = ci.getActiveChannels();
                        active[i] = cb.getState();
                        if (Recorder.record) {
                            String str = "";
                            for (int c=0; c<ci.getNChannels(); c++)
                                str += active[c]?"1":"0";
                            Recorder.record("Stack.setActiveChannels", str);
                        }
                    } else {
                        imp.setPosition(i+1, imp.getSlice(), imp.getFrame());
                        if (Recorder.record)
                            Recorder.record("Stack.setChannel", i+1);
                    }
                    ci.updateAndDraw();
		    drawOverlay(impFO);
                    return;
                }
            }
        }
    }
    

    private void drawOverlay(ImagePlus imp) {
	
	    if(featureTableExits) {
		
		 // delete old overlay
		Overlay overlay = imp.getOverlay();
		if (overlay != null)
			imp.setOverlay(null); 
		
		// determine new overlay
		if(currentFeature>0) {
		
			IJ.log("getting values for feature #"+currentFeature+" ...");
			String[] X = getValues(sTable, xFeatNum, currentFrame, subsetColumnHeader, subsetColumnValue);  // add subset criterium as header value pair 
			String[] Y = getValues(sTable, yFeatNum, currentFrame);
			String[] vFeature = getValues(sTable, currentFeature, currentFrame);
			IJ.log("...done");
			
			int nCells = X.length;
			IJ.log("iFrame=" + currentFrame +"; nCells=" + nCells);
			
			// Font appearence
			//Font font = imp.getProcessor().getFont().deriveFont(100.0); 
			Font font = new Font(null);
			font = font.deriveFont((float)fontSize);
			String[] cl = fontColor.split("\\.");
			int red = Integer.parseInt(cl[0]);
			int green = Integer.parseInt(cl[1]);
			int blue = Integer.parseInt(cl[2]);
							
			// populate new overlay
			overlay = new Overlay();
			
			for (int iCell=0; iCell<nCells; iCell++) {
				Double xpos = Double.parseDouble(X[iCell]); 
				Double ypos = Double.parseDouble(Y[iCell]); 
				Roi roi = new TextRoi( xpos.intValue(), ypos.intValue(), vFeature[iCell], font);	
				roi.setStrokeColor(new Color(red, green, blue));
				overlay.add(roi);
				}
				
			imp.setOverlay(overlay);
		}
		//CompositeImage ci = (CompositeImage)imp;	
		//ci.updateAndDraw();
		imp.updateAndDraw();
		
	    }
    } 


    private String[] getValues(String sTable, int iFeature, int iFrame) {
	
	String[] sRows = sTable.split("\n");
	int nRows = sRows.length;
	
	//IJ.log("nCols "+sRows[1].split("\t").length); 
	//IJ.log("nRows "+nRows); 
	
	int nCells = 0;
	final int iFrameCol = 0;
	final int iCellCol = 1;
	int iCell;

	ArrayList<String> listValues = new ArrayList<String>(); 
	for (int i = 1; i<nRows; i++) {  
		// only parse correct movie or z-stack frame:
		if( iFrame == Integer.parseInt(sRows[i].split("\t")[iFrameCol])  ) {
			// only use data matching the subsetting
			
			// only parse numbered cells:
			if ( isNumeric(sRows[i].split("\t")[iCellCol]) ) { 
				listValues.add(sRows[i].split("\t")[iFeature]);
				//listValues.add(Double.parseDouble(sRows[i].split("\t")[iFeature]));
				//IJ.log(""+iFrame+":"+listValues.size());
			} 
		}
	}
	
	// convert ArrayList to normal Array
	String[] values = new String[listValues.size()];
	listValues.toArray(values);
	return values;

    }

    
  private String[] getAllValuesForClosestCell(double xClick, double yClick) {
	
	String[] sRows = sTable.split("\n");
	int nRows = sRows.length;
	
	//IJ.log("nCols "+sRows[1].split("\t").length); 
	//IJ.log("nRows "+nRows); 
	
	int nCells = 0;
	
	final int iFrameCol = 0;
	final int iCellCol = 1;
	Double xCell, yCell, distance, distance_min;
	int iCellRow = 0;

	String sValues = sTableFileName;
		
	IJ.log("getting values for selected cell...");
	distance_min = 0.0; distance_min = distance_min.MAX_VALUE;

	ArrayList<String> listValues = new ArrayList<String>(); 
	for (int i = 1; i<nRows; i++) {  
		// only parse current frame:
		if( currentFrame == Integer.parseInt(sRows[i].split("\t")[iFrameCol])  ) {
			//IJ.log("correct frame."); // only parse numbered cells:	
			if ( isNumeric(sRows[i].split("\t")[iCellCol]) ) { 
				// compute distance of cell to clicked position
				xCell = Double.parseDouble(sRows[i].split("\t")[xFeatNum]);
				yCell = Double.parseDouble(sRows[i].split("\t")[yFeatNum]);
				distance = (xCell-xClick)*(xCell-xClick) + (yCell-yClick)*(yCell-yClick);
				if(distance < distance_min) {
					distance_min = distance;
					iCellRow = i;
				}
				IJ.log("cell number "+sRows[i].split("\t")[iCellCol]+" distanceSquare "+distance + " distanceMin "+distance_min);
				/*if( Integer.parseInt(sRows[i].split("\t")[iCellCol]) == 53 ) {
		  			IJ.log("correct cell with "+sFeatureNames.length + " features.");
		  			  }*/
				//listValues.add(Double.parseDouble(sRows[i].split("\t")[iFeature]));
				//IJ.log(""+iFrame+":"+listValues.size());
			} 
		}
	}
	
	IJ.log("closests cell found in row #" + iCellRow);
	for (int iFeature = 1; iFeature<sFeatureNames.length; iFeature++) {
		//listValues.add(sRows[iCellRow].split("\t")[iFeature]);
		sValues = sValues.concat(",").concat(sRows[iCellRow].split("\t")[iFeature]);
	//	IJ.write(","+sRows[iCellRow].split("\t")[iFeature]);
	}
	
	IJ.write(""+sValues);
	
	// convert ArrayList to normal Array
	String[] values = new String[listValues.size()];
	listValues.toArray(values);
	return values;

    }

	

    private static final boolean isNumeric(final String s) {
	final char[] numbers = s.toCharArray();
	for (int x = 0; x < numbers.length; x++) {      
		final char c = numbers[x];
		if ((c >= '0') && (c <= '9')) continue;
		return false; // invalid
	}
	return true; // valid
    }



    public void actionPerformed(ActionEvent e) {
        String command = e.getActionCommand();
        if (command==null) return;
        if (command.equals(flattenLabel)) {
		 IJ.log("Flatten");
		 //ImagePlus imp = WindowManager.getCurrentImage();
		 ImagePlus imp = impFO;
		 if (imp==null) return;
		 //imp.setPosition(1,1,50);
		 //imp.updateAndDraw();
		 //ImagePlus imp1 = IJ.getImage();
 		 //ImagePlus imp2 = imp.flatten();
		 //imp2.setTitle(WindowManager.getUniqueName(imp.getTitle()));
		 //imp2.show();
		 ImageStack stackFlat = new ImageStack(imp.getWidth(), imp.getHeight());//, imp.getNFrames());
		 //IJ.log(""+imp.getNFrames());
		 for (int i=1; i<=imp.getNFrames(); i++) { //
			imp.setPosition(1,1,i);
			imp.updateAndDraw();
			//ImageProcessor ip = imp.flatten().getProcessor();
			stackFlat.addSlice(" ", imp.flatten().getProcessor());
			//IJ.log(""+i);
		 }
		 ImagePlus impFlat = new ImagePlus("flatten", stackFlat);
		 impFlat.show();
		 //IJ.log(""+impFlat.getImageStackSize());
		 //ImageStack(int width, int height, int size) 
	 }	 
        //} else if (command.equals("Convert to RGB"))
            // IJ.doCommand("Stack to RGB");
        // else
	//IJ.doCommand(command);
	
    }
    
    public static Frame getInstance() {
        return instance;
    }
        
    public void close() {
        super.close();
        instance = null;
        location = getLocation();
    }
    
   	
    // Window Listener
    public void windowClosing(WindowEvent e) {
	ImagePlus.removeImageListener(this);
	close();
    }

    // called when an image is opened
    public void imageOpened(ImagePlus imp) {
		//IJ.log(imp.getTitle() + " opened");
    }

    // Called when an image is closed
    public void imageClosed(ImagePlus imp) {
	    IJ.log("upon closing:"+IJ.freeMemory());
	    IJ.log(imp.getTitle() + "stack closed -----------------------");
	    // try to also close automatically the channel and feature selection box 
	    // ...
    }

    // Called when an image's pixel data is updated
    public void imageUpdated(ImagePlus imp) {
	// IJ.log(imp.getTitle() + " frame is now " + imp.getFrame() );
		
	//IJ.log("draw update FeatureOverlay");
			
	// only call this if the current frame number changed!
	if (currentFrame != impFO.getFrame()) {
		currentFrame = impFO.getFrame();
		drawOverlay(impFO);
	}

    }

}

class VirtualStack3 extends ImageStack {
	//static final int INITIAL_SIZE = 100;
	FileInfo[] info;
	int nSlices;
	int nTiles,nTilesW,nTilesH;
	
	private int width;
	private int height;
	private int basewidth;
	private int baseheight;
	private boolean isStack=false;
	private int iLastProcessor;
	private ImageProcessor ipLast;
	
   	 /* Constructs a VirtualStack3 object. */
	public VirtualStack3(Object[] sFiles) {
	
		IJ.log("*** VirtualStack3 ***");
		
		int nFiles = sFiles.length;
		// todo: what happens if this is a huge file?
		// ImagePlus imp = new Opener().openImage(sDir.concat(sFiles[0].toString()));
		String sFirstFile = sFiles[0].toString();
		//ImagePlus imp = new ImagePlus(sFirstFile);
		ImagePlus imp = new ImagePlus(sFirstFile);
		// TODO: file not found exception!!!
		IJ.log("reading information from: "+sFirstFile);
		FileInfo fi = imp.getOriginalFileInfo();
		IJ.log("width:"+fi.width);
		IJ.log("height:"+fi.height);
		width = fi.width;
		height = fi.height;
		basewidth = fi.width;
		baseheight = fi.height;
		
		
		iLastProcessor = 0;
		int nSlicesInFirstFile = imp.getImageStackSize();
		IJ.log("slices: "+nSlicesInFirstFile);
		
		int nt = 1;
	
			
		// IJ.log("slices: "+imp.getNSlices());
		
		// fi.url = "http://localhost/images/";
		// fi.fileName = "Pos1_Z1-0001.tif";
		// FileOpener fo = new FileOpener(fi);
	        // ImagePlus imp2 = fo.open(false);
		// imp2.show();
		// if the images come from an url, i have to set info[i].url!!
		
		// examine the files and construct the appropriate FileInfo array
			
		if ( nSlicesInFirstFile > 1) {  // stacks (works only for local files)
			
			IJ.log("opening "+nFiles+" stacks...");
			
			nSlices = nSlicesInFirstFile*nFiles;
			
			info = new FileInfo[nSlices];
			isStack = true;
			
			FileInfo[] infoOrig = new FileInfo[nFiles];
			for (int iFile = 0; iFile < nFiles; iFile++) {
				// TODO: file not found exception!!!
				IJ.log("reading information from: "+sFiles[iFile].toString());
				imp = new ImagePlus(sFiles[iFile].toString());
				infoOrig[iFile] = imp.getOriginalFileInfo();
				
				//TiffDecoder td = new TiffDecoder(getDir(sFiles[iFile].toString()), getName(sFiles[iFile].toString()));
				//FileInfo[] infoTemp=null;
				//try {infoTemp = td.getTiffInfo();}
				//catch (IOException e) {
				//	String msg = e.getMessage();
				//	if (msg==null||msg.equals("")) msg =""+e;
				//	IJ.error("TiffDecoder", msg);
				//	return;
				//}
				//infoOrig[iFile] = infoTemp[0];
			}
			
			int iImage = 0;
			for (int iSlice=0; iSlice<nSlicesInFirstFile; iSlice++) {
			    for (int iFile = 0; iFile < nFiles; iFile++) {
				fi = infoOrig[iFile];
	      		        info[iImage] = (FileInfo)fi.clone();
				info[iImage].nImages = 1;
				//long size = fi.width*fi.height*fi.getBytesPerPixel();
				//IJ.log("gapBetweenImages "+fi.gapBetweenImages);
				//info[iImage].longOffset = fi.getOffset() + iSlice*(size + fi.gapBetweenImages);
				//info[iImage].longOffset =  fi.getOffset() + iSlice*(size + fi.gapBetweenImages);
				info[iImage].offset = iSlice+1;
				//IJ.log("longOffset "+info[iImage].longOffset);
				info[iImage].fileName = sFiles[iFile].toString(); 
				//info[iImage].iSlice = iSlice; 
				//info[iImage].directory = sDir;
				iImage++;
				
			    }
			}
		
		} else {  // no stacks but individual images		
		
			IJ.log("opening "+nFiles+" individual images...");
			nSlices = nFiles;
			info = new FileInfo[nFiles];
			for (int i = 0; i < nFiles; i++) {
				info[i] = (FileInfo)fi.clone();
				info[i].nImages = 1;
				info[i].fileName = sFiles[i].toString();  // put the different filenames	                      			
				//info[i].directory = sDir;
				//if(sDir.contains("http://")) {
				//	//info[i].url = sDir;
				//	info[i].directory = sDir;
				//}
			}
		}
		
		
	}

	public String getName(String path) {
	        int i = path.lastIndexOf('/');
	        if (i==-1)
	            i = path.lastIndexOf('\\');
	        if (i>0)
	            return path.substring(i+1);
	        else
	            return path;
	}
    
	public String getDir(String path) {
		int i = path.lastIndexOf('/');
		if (i==-1)
			i = path.lastIndexOf('\\');
		if (i>0)
			return path.substring(0, i+1);
		else
			return "";
	}

	/** Deletes the specified image, were 1<=n<=nImages. */
	public void deleteSlice(int n) {
		if (n<1 || n>nSlices)
			throw new IllegalArgumentException("Argument out of range: "+n);
		if (nSlices<1) return;
		for (int i=n; i<nSlices; i++)
			info[i-1] = info[i];
		info[nSlices-1] = null;
		nSlices--;
	}

	/** Deletes the last slice in the stack. */
	public void deleteLastSlice() {
		if (nSlices>0)
			deleteSlice(nSlices);
	}

	/** Returns an ImageProcessor for the specified image,
        	were 1<=n<=nSlices. Returns null if the stack is empty.
		*/
	public ImageProcessor getProcessor(int n) {
      	
		//IJ.log(""+IJ.freeMemory());
		//IJ.log("last Processor = "+iLastProcessor);
		//IJ.log("requested Processor = "+n);
		if (iLastProcessor == n) {
			//IJ.log("returning chached processor");
			return ipLast;
		}
	
		// otherwise load data from disk
		iLastProcessor = n;
		
		if (n<1 || n>nSlices) 
			throw new IllegalArgumentException("Argument out of range: "+n);
	 
		info[n-1].nImages = 1; // why is this needed?
		
		//Color background = Toolbar.getBackgroundColor();
		//IJ.showProgress((double)i/d3);
		//.createProcessor(width, height);;
		//ip3.setColor(background);
		//ip3.fill();
		
		
		ImagePlus imp;
		if(isStack) { //stacks (does not work for URL)
			imp = new Opener().openImage(info[n-1].fileName, info[n-1].offset);
			//info[iImage].offset
			//FileOpener fo = new FileOpener(info[n-1]);
			//imp = fo.open(false);
			//IJ.log("opening...");
		} else { // individual files
			//String sDir = info[n-1].directory;
			String sFile = info[n-1].fileName;
			//IJ.log("getting "+sFile);
			//ImagePlus imp = new Opener().openImage(sDir.concat(sFile.toString()));  
			//imp = new ImagePlus(sDir.concat(sFile.toString()));
			imp = new ImagePlus(sFile.toString());
			//IJ.log("bit depth="+imp.getBitDepth());
		}
		
		ImageProcessor ip = imp.getProcessor();		
		//ImageStack stack3 = new ImageStack(w3, h3, ip.getColorModel());
		//ImageProcessor ip = stack1.getProcessor(1);

		ImageProcessor ip1 = ip.createProcessor(width, height);
		//ColorModel cm = ip.getColorModel();
		//ip1.setColorModel(cm);
		ip1.insert(ip,0,0);
		
		// if there are multiple tiles add those as well
		if(nTiles>1) {
			
			for(int iH=1; iH<=nTilesH; iH++) {
				
				for (int iW=1; iW<=nTilesW; iW++) {
				
					n=n+nSlices/nTiles; // next File
					info[n-1].nImages = 1;;
					IJ.log("n = "+n);
					if(isStack) { //stacks (does not work for URL)
						imp = new Opener().openImage(info[n-1].fileName, info[n-1].offset);
						//info[iImage].offset
						//FileOpener fo = new FileOpener(info[n-1]);
						//imp = fo.open(false);
						//IJ.log("opening...");
					} else { // individual files
						//String sDir = info[n-1].directory;
						String sFile = info[n-1].fileName;
						//IJ.log("getting "+sFile);
						//ImagePlus imp = new Opener().openImage(sDir.concat(sFile.toString()));  
						//imp = new ImagePlus(sDir.concat(sFile.toString()));
						imp = new ImagePlus(sFile.toString());
						//IJ.log("bit depth="+imp.getBitDepth());
					}
					ip = imp.getProcessor();	
					//ip.setColorModel(cm);
					ip1.insert(ip,(iW-1)*basewidth,(iH-1)*baseheight);
				
				}
			
			}
			
				
		}
		
		//IJ.log("nTiles "+nTiles);
		
		ImagePlus imp1 = new ImagePlus("",ip1);
		//imp1.show();
		
		// convert all images to 16 bit 
		new ImageConverter(imp1).convertToGray16();
		
		if (imp1!=null) {
			ipLast = imp1.getProcessor();
			return ipLast;
		} else {
			return null;
		}
		
     }
 
     /** Returns the number of images in this stack. */
     public int getSize() {
         return nSlices;
     }

     
     public void setTilesWH(int nW, int nH) {
	     nTiles = nW*nH;
	     nTilesW = nW;
	     nTilesH = nH;
	     
	     width = nW*basewidth;
	     height = nH*baseheight;
	     
	     nSlices = nSlices/nTiles;
     }
     
     /** Returns the label of the Nth image. */
     public String getSliceLabel(int n) {
         if (n<1 || n>nSlices)
             throw new IllegalArgumentException("Argument out of range: "+n);
         if (info[0].sliceLabels==null || info[0].sliceLabels.length!=nSlices)
             return null;
         else
             return info[0].sliceLabels[n-1];
     }

   	/** Returns the pixel array for the specified slice, were 1<=n<=nslices. */
    	public Object getPixels(int n) {
		ImageProcessor ip = getProcessor(n);
		if (ip!=null)
			return ip.getPixels();
		else
			return null;
   	  	}		
	
    	 /** Assigns a pixel array to the specified slice,
	were 1<=n<=nslices. */
	public void setPixels(Object pixels, int n) {
	}

	public int getWidth() {
		return width;
	}
    
        public int getHeight() {
		return height;
	}

	/** Does nothing. */
	public void addSlice(String sliceLabel, Object pixels) {
	}

	/** Does nothing.. */
	public void addSlice(String sliceLabel, ImageProcessor ip) {
	}
	
	/** Does noting. */
	public void addSlice(String sliceLabel, ImageProcessor ip, int n) {
	}

	/** Always return true. */
	public boolean isVirtual() {
		return true;
	}


	/** Does nothing. */
	public void trim() {
	}
    
}


