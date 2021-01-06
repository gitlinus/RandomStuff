/* 
The "Match" class
Written by Linus Chen, Andrew Li, Jack Lee
Match the sound to the instrument
//wav files by Andrew Li
*/

import java.awt.*;
import java.awt.image.BufferedImage;
import javax.swing.*;
import hsa.Console;
import javax.imageio.*;
import java.io.*;
import java.util.Random;
import javax.sound.sampled.AudioInputStream;
import javax.sound.sampled.AudioSystem;
import javax.sound.sampled.Clip;
import java.io.*;

public class Match
{
	private Console c;           // The output console

    //Load Audio
    public void playAudio (String name)
    {
        try {
            String soundName = name;
            AudioInputStream audioInputStream = AudioSystem.getAudioInputStream(new File(soundName).getAbsoluteFile());
            Clip clip = AudioSystem.getClip();
            clip.open(audioInputStream);
            clip.start();
        } catch (Exception a) {}
	}
	
	//LoadImage method
	public Image loadImage (String name) throws Exception
	{
		Image img = ImageIO.read (new File (name));
		return img;
	}
   
    //Main
    public void Play() throws Exception
    {

		c = new Console ();

		char answer;
		int total = 0;
		Image bg = loadImage ("MatchGame.png");
		Font f1 = new Font ("Comic Sans MS", Font.BOLD, 20);
		c.setFont(f1);
		c.drawImage (bg, 0, 0, null);
		c.drawString("Match the sound to the instrument", 0, 50);
		c.drawString("Press any key to continue",0,70);
		c.getChar();
		c.clear();

		//Trumpet
		c.drawImage (bg, 0, 0, null);
		c.drawString ("Which instrument did you hear?",0,50);
		c.drawString ("a) Trumpet",0,70);
		c.drawString ("b) Piano",0,90);
		c.drawString ("c) Cello",0,110);
		c.drawString ("d) Flute",0,130);
		Thread.sleep(100);
		playAudio ("Trumpet.wav");
		c.drawString("Press r to replay audio clip", 0, 240);

		while(true)
		{
			answer = c.getChar ();

			if (answer == 'a')
			{
				c.clear();
				c.setColor(Color.green);
				c.fillRect(0, 0, 700,600);
				c.setColor(Color.white);
				c.drawString ("Correct!",0,50);
				total++;
				c.drawString("Press the space bar to continue",0,70);
				break;
			}
			else if(answer == 'b' || answer == 'c' || answer == 'd')
			{
				c.clear();
				c.setColor(Color.red);
				c.fillRect(0, 0, 700,600);
				c.setColor(Color.white);
				c.drawString ("Why are you so bad?",0,50);
				c.drawString("Press the space bar to continue",0,70);
				break;
			}
			else if(answer == 'r')
			{
				playAudio("Trumpet.wav");
			}
		}

		c.getChar ();
		c.clear();

		//Harpsichord
		c.drawImage (bg, 0, 0, null);
		c.setColor(Color.black);
		c.drawString ("Which instrument did you hear?",0,50);
		c.drawString ("a) Harp",0,70);
		c.drawString ("b) Marimba",0,90);
		c.drawString ("c) Harpsichord",0,110);
		c.drawString ("d) Bells",0,130);
		Thread.sleep(500);
		playAudio ("Harpsichord.wav");
		c.drawString("Press r to replay audio clip", 0, 240);
		
		while(true)
		{
			answer = c.getChar ();

			if (answer == 'c')
			{
				c.clear();
				c.setColor(Color.green);
				c.fillRect(0, 0, 700,600);
				c.setColor(Color.white);
				c.drawString ("Correct!",0,50);
				total++;
				c.drawString("Press the space bar to continue",0,70);
				break;
			}
			else if(answer=='a'||answer=='b'||answer=='d')
			{
				c.clear();
				c.setColor(Color.red);
				c.fillRect(0, 0, 700,600);
				c.setColor(Color.white);
				c.drawString ("Why are you so bad?",0,50);
				c.drawString("Press the space bar to continue",0,70); 
				break;
			}
			else if(answer=='r')
			{
				playAudio("Harpsichord.wav");
			}
		}

		c.getChar();
		c.clear();

		//Clarinet
		c.drawImage (bg, 0, 0, null);
		c.setColor(Color.black);
		c.drawString ("Which instrument did you hear?",0,50);
		c.drawString ("a) Oboe",0,70);
		c.drawString ("b) English Horn",0,90);
		c.drawString ("c) Soprano Saxaphone",0,110);
		c.drawString ("d) Clarinet",0,130);
		Thread.sleep(500);
		playAudio ("Clarinet.wav");
		c.drawString("Press r to replay audio clip", 0, 240);

		while(true)
		{
			answer = c.getChar ();
		
			if(answer == 'd')
			{
				c.clear();
				c.setColor(Color.green);
				c.fillRect(0, 0, 700,600);
				c.setColor(Color.white);
				c.drawString ("Correct!",0,50);
				total++;
				c.drawString("Press the space bar to continue",0,70);
				break;
			}
			else if(answer=='a'||answer=='b'||answer=='c')
			{
				c.clear ();
				c.setColor(Color.red);
				c.fillRect(0, 0, 700,600);
				c.setColor(Color.white);
				c.drawString ("Why are you so bad?",0,50);
				c.drawString("Press the space bar to continue",0,70);
				break;
			}
			else if(answer=='r')
			{
				playAudio("Clarinet.wav");
			}
		}

		c.getChar ();
		c.clear ();

		//Bassoon
		c.setColor (Color.black);
		c.drawImage (bg, 0, 0, null);
		
		c.drawString ("Which instrument did you hear?", 0, 50);
		c.drawString ("Difficulty: Intermediate", 350, 50);
		c.drawString ("a) Tuba", 0, 70);
		c.drawString ("b) Bassoon", 0, 90);
		c.drawString ("c) Baritone", 0, 110);
		c.drawString ("d) Contrabass", 0, 130);
		Thread.sleep (500);
		playAudio ("Bassoon.wav");

		while(true)
		{
			answer = c.getChar ();
			if (answer == 'b')
			{
		
				c.clear ();
				c.setColor (Color.green);
				c.fillRect (0, 0, 700, 600);
				c.setColor (Color.white);
				c.drawString ("Correct!", 0, 50);
				total++;
				c.drawString ("Press the space bar to continue", 0, 70);
				break;
			}
			else if (answer == 'a'|| answer == 'c' || answer == 'd')
			{
				c.clear ();
				c.setColor (Color.red);
				c.fillRect (0, 0, 700, 600);
				c.setColor (Color.white);
				c.drawString ("Why are you so bad?", 0, 50);
				c.drawString ("Press the space bar to continue", 0, 70);
				break;
			}
			else
			{
				playAudio("Bassoon.wav");
			}
		}

		c.getChar();
		c.clear ();

		//Guitar
		c.setColor (Color.black);
		c.drawImage (bg, 0, 0, null);
		c.drawString ("Which instrument did you hear?", 0, 50);
		c.drawString ("Difficulty: Intermediate", 350, 50);
		c.drawString ("a) Guitar", 0, 70);
		c.drawString ("b) Banjo", 0, 90);
		c.drawString ("c) Pizzicato Viola", 0, 110);
		c.drawString ("d) Harp", 0, 130);
		Thread.sleep (500);
		playAudio ("Guitar.wav");

		while(true)
		{
			answer = c.getChar ();
			if (answer == 'a')
			{
				c.clear ();
				c.setColor (Color.green);
				c.fillRect (0, 0, 700, 600);
				c.setColor (Color.white);
				c.drawString ("Correct!", 0, 50);
				total++;
				c.drawString ("Press the space bar to continue", 0, 70);
				break;
			}
			else if(answer=='b'||answer=='c'||answer=='d')
			{
				c.clear ();
				c.setColor (Color.red);
				c.fillRect (0, 0, 700, 600);
				c.setColor (Color.white);
				c.drawString ("Why are you so bad?", 0, 50);
				c.drawString ("Press the space bar to continue", 0, 70);
				break;
			}
			else
			{
				playAudio("Guitar.wav");
			}
		}
		
		c.getChar ();
		c.clear ();

		//Timpani
		c.setColor (Color.black);
		c.drawImage (bg, 0, 0, null);
		c.drawString ("Difficulty: Intermediate", 350, 50);
		c.drawString ("Which instrument did you hear?", 0, 50);
		c.drawString ("a) Bass Drum", 0, 70);
		c.drawString ("b) Low Tom", 0, 90);
		c.drawString ("c) Kick Drum", 0, 110);
		c.drawString ("d) Timpani", 0, 130);	
		Thread.sleep (500);
		playAudio ("Timpani.wav");

		while(true)
		{
			answer = c.getChar ();
			if (answer == 'd')
			{
				c.clear ();
				c.setColor (Color.green);
				c.fillRect (0, 0, 700, 600);
				c.setColor (Color.white);
				c.drawString ("Correct!", 0, 50);
				total++;
				c.drawString ("Press the space bar to continue", 0, 70);
				break;
			}
			else if (answer=='a'||answer=='b'||answer=='c')
			{
				c.clear ();
				c.setColor (Color.red);
				c.fillRect (0, 0, 700, 600);
				c.setColor (Color.white);
				c.drawString ("Why are you so bad?", 0, 50);
				c.drawString ("Press the space bar to continue", 0, 70);
				break;
			}
			else 
			{
				playAudio("Timpani.wav");
			}
		}

		c.getChar ();
		c.clear ();

		//Melodeon
		c.setColor (Color.black);
		c.drawImage (bg, 0, 0, null);
		
		c.drawString ("Which instrument did you hear?", 0, 50);
		c.drawString ("Difficulty: Advanced", 400, 50);
		c.drawString ("a) Accordion", 0, 70);
		c.drawString ("b) Harmonium", 0, 90);
		c.drawString ("c) Melodeon", 0, 110);
		c.drawString ("d) Harmonica", 0, 130);
		Thread.sleep (500);
		playAudio ("Melodeon.wav");

		while(true)
		{
			answer = c.getChar ();
			if (answer == 'c')
			{
				c.clear ();
				c.setColor (Color.green);
				c.fillRect (0, 0, 700, 600);
				c.setColor (Color.white);
				c.drawString ("Correct!", 0, 50);
				total++;
				c.drawString ("Press the space bar to continue", 0, 70);
				break;
			}
			else if(answer=='a'||answer=='b'||answer=='d')
			{
				c.clear ();
				c.setColor (Color.red);
				c.fillRect (0, 0, 700, 600);
				c.setColor (Color.white);
				c.drawString ("Why are you so bad?", 0, 50);
				c.drawString ("Press the space bar to continue", 0, 70);
				break;
			}
			else 
			{
				playAudio("Melodeon.wav");
			}
		}
		
		c.getChar ();
		c.clear ();

		//Duduk
		c.setColor (Color.black);
		c.drawImage (bg, 0, 0, null);
		c.drawString ("Which instrument did you hear?", 0, 50);
		c.drawString ("Difficulty: Even the creators don't know the answer", 0, 20);
		c.drawString ("a) Shehnai", 0, 70);
		c.drawString ("b) Duduk", 0, 90);
		c.drawString ("c) Saxophone", 0, 110);
		c.drawString ("d) Zruna", 0, 130);
		Thread.sleep (500);
		playAudio ("Duduk.wav");

		while(true)
		{
			answer = c.getChar ();
			if (answer == 'b')
			{
				c.clear ();
				c.setColor (Color.green);
				c.fillRect (0, 0, 700, 600);
				c.setColor (Color.white);
				c.drawString ("Correct!", 0, 50);
				total++;
				c.drawString ("Press the space bar to continue", 0, 70);
				break;
			}
			else if(answer=='a'||answer=='c'||answer=='d')
			{
				c.clear ();
				c.setColor (Color.red);
				c.fillRect (0, 0, 700, 600);
				c.setColor (Color.white);
				c.drawString ("Why are you so bad?", 0, 50);
				c.drawString ("Press the space bar to continue", 0, 70);
				break;
			}
			else 
			{
				playAudio("Duduk.wav");
			}
		}
		
		c.getChar ();
		c.clear ();

		c.setColor (Color.black);
		c.drawImage (bg, 0, 0, null);
		//Calculate final score
		if (total < 4)
			c.drawString ("Why are you so bad?", 0, 50);
		if (total >= 4 && total <= 6)
			c.drawString ("Not bad, better luck next time!", 0, 50);
		if (total == 7)
			c.drawString ("So close but so far!", 0, 50);
		if (total == 8)
			c.drawString ("Wow! Very good!", 0, 50);
		c.drawString ("You got " + total + " out of 8 correct!", 0, 70);
		
    } // main method
} // Match class
