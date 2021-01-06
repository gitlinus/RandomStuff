/*
Run class
Written by Linus Chen and Janani Satkunarajah
This is the running class used to run all objects we have coded
//Graphics by Jack Lee
//Flowcharts and report summary by Janani Satkunarajah and Sarah Hicks
//Don't move any files in the directory please
*/

import java.awt.*;
import hsa.Console;
import javax.imageio.*;
import java.io.*;
import java.awt.image.BufferedImage;
import javax.swing.*;
import java.io.BufferedReader;
import java.util.Random;
import java.util.Timer;

public class Run 
{
    //Console and Graphics2D
    static Console c;
    static Graphics2D g;
    //Main
    public static void main(String[] args) throws Exception
    {
        c = new Console(40,155);

        //New titlescreen object
        TitleScreen intro = new TitleScreen(c , g); 
        intro.Introduction();
        c.getChar();
        c.clear();

        intro.Menu();
        char ch = c.getChar();
        //loop for the menu and choice selections
        while(ch!='q')
        {
            if(ch=='c')
            {
                //Open up README.txt file, contains instructions
                Console c2 = new Console();
                try {
                    BufferedReader br = new BufferedReader(new FileReader("README.txt")); //used to read input
                    String line;
                    while((line = br.readLine()) != null)
                    {
                        c2.println(line);
                    }   
                    br.close();
                } catch (Exception e) {
                    c.println("ERROR IN READING FILE");
                }
                c2.println("Press any key to quit");
                c2.getChar();
                c2.close();
            }

            if(ch=='b')
            {
                c.close();
                //Make new Match class
                Match m = new Match();
                m.Play();
            }

            if(ch=='a')
            {
                c.close();
                //Make new PianoTiles object
                PianoTiles pt = new PianoTiles();
                pt.Run();
            }
            ch = c.getChar();
        }
        c.close();
    }
}