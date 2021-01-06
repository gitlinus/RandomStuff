/*
TitleScreen object class
Written by Linus Chen
//Graphics by Jack Lee
Contains methods to be run by Run class during the introduction of the program
*/

import java.awt.*;
import hsa.Console;
import javax.imageio.*;
import java.io.*;
import java.awt.image.BufferedImage;
import javax.swing.*;
import java.util.Random;

public class TitleScreen 
{
    private Console c;
    private Graphics2D g;

    //********************************TitleScreen constructor************************
    public TitleScreen(Console console, Graphics2D graphics)
    {
        c = console;
        g = graphics;
    }

    //*******************************Image Loading Method****************************
    public Image loadImage (String name) throws Exception
    {
		Image img = ImageIO.read (new File (name));
		return img;
    }

    public void Introduction() throws Exception
    {
        BufferedImage image = new BufferedImage (1280, 960, BufferedImage.TYPE_INT_ARGB); //BufferedImage
		g = image.createGraphics (); //Graphics2D

        Image background = loadImage("Title.png");
        g.drawImage(background,0,0,null);
        c.drawImage(image,0,0,null);
    }

    public void Menu() throws Exception
    {
        c.clear();
        BufferedImage image = new BufferedImage (1280, 960, BufferedImage.TYPE_INT_ARGB); //BufferedImage
		g = image.createGraphics (); //Graphics2D
        Image background = loadImage("Menu.png");
        g.drawImage(background,0,0,null);
        c.drawImage(image,0,0,null);
    }
}