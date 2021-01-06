/*
PianoTiles object class
Written by Linus Chen, Andrew Li, Jack Lee
Classic piano tiles game
controls: 1, 2, 3, 4
!!! DOES NOT CONTAIN MAIN METHOD, DO NOT RUN THIS CLASS !!!
*/
import java.awt.Color;
import java.awt.Container;
import java.awt.Dimension;
import java.awt.Font;
import java.awt.Graphics;
import java.awt.Graphics2D;
import java.awt.event.KeyAdapter;
import java.awt.event.KeyEvent;
import javax.swing.JFrame;
import javax.swing.JPanel;
import java.text.DecimalFormat;
import java.util.*;
import javax.sound.sampled.AudioInputStream;
import javax.sound.sampled.AudioSystem;
import javax.sound.sampled.Clip;
import java.io.*;

public class PianoTiles extends JPanel
{
    // DECLARE ALL THE VARIABLES
    private PianoTiles game;
    private final int HEIGHT = 520;
    private final int WIDTH = 650;
    private final int TILE_SIZE = 100;
    private static int GAME_LENGTH = 100;
    private static Tile[][] board = new Tile[GAME_LENGTH][4];
    private static JFrame frame;
    private static int direct = -1;
    private static int counter = 0;
    private static boolean pressed = false;
    private static boolean wrongtile = false;
    private static long start = -1;
    private static int missclick = 0;
    private static long starttime;
    private static long timeelapsed;
    private static int combo = 0;
    private static int highestcombo = 0;
    private static int[] keys = new int[]
    {
        KeyEvent.VK_1,
        KeyEvent.VK_2,
        KeyEvent.VK_3,
        KeyEvent.VK_4
    };

    // Object constructor
    public PianoTiles()
    {
        // Pre set tile positions
        for(int i=0; i<board.length; i++)
        {
            for(int j=0; j<board[i].length; j++)
            {
                board[i][j] = new Tile(j*TILE_SIZE,-1*TILE_SIZE*i+400,j);
                board[i][j].setTileColor(false);
            }
            //Choose the tiles to be black
            int rand = (int) (Math.random() * 4);
            board[i][rand].setTileColor(true);
        }
    }

    // load audio method
    public void loadSound (String name)
    {
        try {
            String soundName = name;
            AudioInputStream audioInputStream = AudioSystem.getAudioInputStream(new File(soundName).getAbsoluteFile());
            Clip clip = AudioSystem.getClip();
            clip.open(audioInputStream);
            clip.start();
        } catch (Exception a) {}
    }

    // paint method
    @Override
    public void paint(Graphics g) 
    {
        //use super class method
        super.paint(g);
        Graphics2D g2 = (Graphics2D) g;

        // draw out the board
        for(int i=0; i<board.length; i++)
        {
            for(int j=0; j<board[i].length; j++)
            {
                g.setColor(board[i][j].getColor());
                g.fillRect(board[i][j].getX(), board[i][j].getY(), TILE_SIZE, TILE_SIZE);
            }
        }
        g.setColor(Color.BLACK);
        for(int j=1; j<5; j++) //Lines
            g.drawLine(j*100,0,j*100,500);

        g.setColor(Color.BLUE);
        Font f = new Font("Arial", Font.BOLD, 52);
        Font f2 = new Font("Impact", Font.BOLD, 30);
        Font f3 = new Font("Comic Sans MS", Font.BOLD, 30);
        Font f4 = new Font("Courier", Font.BOLD, 25);
        Font f5 = new Font("Impact", Font.BOLD, 50);

        //Display time
        g.setFont(f);
        DecimalFormat df = new DecimalFormat("#.###");
        g.drawString(start == -1 ? "0.000s": df.format((double) (System.nanoTime() - start) /1000000000) + "s", 430, 75);

        g.setColor(Color.BLACK);
        g.setFont(f4);
        g.drawString("Tiles left: "+(GAME_LENGTH-counter), 420, 150);

        // Do this if wrong tiles is selected
        if(wrongtile)
        {
            if(direct==0||direct==1||direct==2||direct==3)
            {
                g.setColor(Color.RED);
                g.fillRect(board[counter][direct].getX(), board[counter][direct].getY(), 100, 100);
            }
            g.setColor(Color.RED);
            g.setFont(f2);
            g.drawString("WHY ARE YOU", 450,300);
            g.drawString("    SO BAD?", 450,350);
        }
        //Combos 
        if(combo >= 5)
        {
            Color color = new Color(255, 0, 180);
            g.setFont(f5);
            g.setColor(color);   
            g.drawString("COMBO x"+combo, 410, 300);
        }
        //Do this when game ends
        if(counter==GAME_LENGTH)
        {
            timeelapsed = System.nanoTime() - starttime;
            g.setFont(f3);
            g.setColor(Color.WHITE);
            g.fillRect(0,0,WIDTH,HEIGHT);
            g.setColor(Color.ORANGE);
            g.drawString("CONGRATULATIONS!!!", 160, 100);
            g.setColor(Color.BLACK);
            g.drawString("Time spent: ", 10, 220);
            g.drawString(df.format((double)timeelapsed/1000000000) + " seconds", 200, 220);
            g.drawString("Wrong tiles pressed: " + missclick, 10, 290);
            g.drawString("Highest Combo: " + highestcombo, 10, 340);
            g.drawString("Thanks for playing!", 160, 400);
        }
    }

    // update method
    public void update()
    {
        //call the paint method again
        repaint();

        if(counter==GAME_LENGTH)
            repaint();

        //correct tile pressed
        if(pressed)
        {
            for(int i=0; i<board.length; i++)
                for(int j=0; j<board[i].length; j++)
                    board[i][j].updateY();
            counter++;
            pressed = false;
            //System.out.println(direct);
            if(direct==0)
                loadSound("C.wav");
            if(direct==1)
                loadSound("E.wav");
            if(direct==2)
                loadSound("F.wav");
            if(direct==3)
                loadSound("G.wav");
        }
    }

    // Run all the stuff method
    public void Run() 
    {
        // make new JFrame
        frame = new JFrame("Piano Tiles");
        game = new PianoTiles();

        // set JFrame attributes
        frame.add(game);
        frame.setResizable(false);
        frame.pack();
        frame.setVisible(true);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setSize(650,520);
        //Waits for input from keyboard
        frame.addKeyListener(new KeyAdapter() {
            public void keyPressed(KeyEvent e) 
            {
                int ID = e.getKeyCode();
                if (ID == KeyEvent.VK_1) direct = 0;
                if (ID == KeyEvent.VK_2) direct = 1;
                if (ID == KeyEvent.VK_3) direct = 2;
                if (ID == KeyEvent.VK_4) direct = 3;
                if (ID == KeyEvent.VK_ESCAPE) System.exit(0);

                //start the timer
                for (int i = 0; i < keys.length; i++) 
                {
                    if (keys[i] == ID) {
                        if (start == -1){ starttime = start = System.nanoTime(); }
                        ID = i;
                        break;
                    }
                }

                //makes sure the user pressed 1, 2, 3, or 4
                if(direct!=-1)
                {
                    //correct tile pressed
                    if(board[counter][direct].isBlack()) 
                    {
                        pressed = true;
                        wrongtile = false;
                        combo++;
                    }
                    //wrong tile pressed
                    else
                    {
                        wrongtile = true;
                        missclick++;
                        if(combo >= 5)
                            if(combo > highestcombo)
                                highestcombo = combo;
                        combo = 0;
                    }
                }
            }
            public void keyReleased(KeyEvent e) 
            {
                int ID  = e.getKeyCode();
                if (ID == KeyEvent.VK_1 || ID == KeyEvent.VK_2 || ID == KeyEvent.VK_3 || ID == KeyEvent.VK_4) direct = -1;
            }
        });

        //Keep looping until all tiles are pressed
        while(counter<GAME_LENGTH)
        {
            game.update();
            try{Thread.sleep(1);}catch(InterruptedException ie){ie.printStackTrace();}
        }
    }
}