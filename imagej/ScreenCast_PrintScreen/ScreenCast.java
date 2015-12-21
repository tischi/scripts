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


public class ScreenCast {

    public static void main(String[] args) throws AWTException, IOException {
    	IJ.log("Hello");

    	PointerInfo a = MouseInfo.getPointerInfo();
		Point b = a.getLocation();
		int x = (int) b.getX();
		int y = (int) b.getY();
        IJ.log("x y "+ x +" "+ y);
        // capture the whole screen
        // determine current screen size
		Toolkit toolkit = Toolkit.getDefaultToolkit();
		Dimension screenSize = toolkit.getScreenSize();
		IJ.log(""+screenSize);
		Rectangle screenRect = new Rectangle(screenSize);
		IJ.log("aaa");
		IJ.log("rect "+screenRect);
		Robot robot = new Robot();
		robot.mouseMove(183, 1038);
		IJ.log("2");
		//BufferedImage image = robot.createScreenCapture(screenRect);
		//ImagePlus imp = new ImagePlus("screencast",image);
		//imp.show();
        //File file = new File("C:/Users/Christian Tischer/Desktop/screencapture.jpg");
        //Boolean worked = ImageIO.write(image, "jpg", file);
        //IJ.log("3");
        //IJ.log("worked: "+worked); 
     	//IJ.log(""+ Toolkit.getDefaultToolkit().getScreenSize());
        //BufferedImage screencapture = new Robot().createScreenCapture(new Rectangle(Toolkit.getDefaultToolkit().getScreenSize()) );

    }

}