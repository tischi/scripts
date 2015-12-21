import java.awt.AWTException;
import java.awt.Robot;
import java.awt.Rectangle;
import java.awt.Toolkit;
import java.awt.image.BufferedImage;
import java.io.*;
import javax.imageio.ImageIO;
import ij.*;
import java.awt.*;
import java.awt.image.*;
import java.io.*;
import javax.imageio.*;
import java.awt.MouseInfo;
import ij.plugin.ImageCalculator;
import ij.plugin.Duplicator;


public class ijRobot {

    public static void main(String[] args) throws AWTException, IOException {
  
    	// get current mouse location
    	// - these functions could be used to "teach" the software where to click
    	PointerInfo a = MouseInfo.getPointerInfo();
		Point b = a.getLocation();
		int x = (int) b.getX();
		int y = (int) b.getY();
        IJ.log("current mouse position:  "+ x +" "+ y);

		// move mouse somewhere
        Robot robot = new Robot();
		robot.mouseMove(183, 1038);
		
		// determine current screen size
		Toolkit toolkit = Toolkit.getDefaultToolkit();
		Dimension screenSize = toolkit.getScreenSize();
		//Rectangle screenRect = new Rectangle(screenSize);
		IJ.log(""+screenSize);

		Rectangle screenRect = new Rectangle(0,0,512,512);
		IJ.log("rect "+screenRect);

		ImageCalculator ic = new ImageCalculator();
        ImagePlus impOLD = new ImagePlus();

        long start = System.currentTimeMillis();
			
		for(int i=1; i<101; i++){
			//try {
 			//    Thread.sleep(1000);                 //1000 milliseconds is one second.
			//} catch(InterruptedException ex) {
    		//	Thread.currentThread().interrupt();
			//}
			// capture part of the screen and make it an imp
			
			BufferedImage image = robot.createScreenCapture(screenRect);
			ImagePlus imp = new ImagePlus("screencast",image);
			IJ.run(imp, "8-bit", "");
			IJ.run(imp, "Auto Threshold", "method=Default white");
				
			if (i > 1) {
				ImagePlus impDIFF = ic.run("Subtract create", imp, impOLD);
			}
			
			impOLD = new Duplicator().run(imp);
			
			//IJ.run(imp, "Auto Local Threshold", "method=Niblack radius=%s parameter_1=%s parameter_2=0 white stack" % (mpar['radius'], mpar['threshold']));
			
			//IJ.log(""+duration);
		}
	    long end = System.currentTimeMillis();
	    long duration = end - start;
		IJ.log(""+duration);
		
		//imp.show();
		
    }

}