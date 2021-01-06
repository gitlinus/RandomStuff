/*
Tile class object
- used in the pianotiles class object
Written by Linus Chen
*/

import java.awt.Color;
import java.awt.Font;
import java.awt.Graphics2D;
import java.awt.event.KeyEvent;

public class Tile 
{
    //Declare variables
    private int x;
    private int y;
    private boolean black;
    private Color color;
    private int direction;

    //Tile constructor
    public Tile(int x, int y, int direction) 
    {
        this.x = x;
        this.y = y;
        this.direction = direction;
    }

    public Color getColor()
    {
        return color;
    }

    public int getX()
    {
        return x;
    }

    public int getY()
    {
        return y;
    }

    public boolean isBlack()
    {
        if(black)
            return true;
        else
            return false;
    }

    public void setTileColor(boolean black)
    {
        this.black = black;
        this.color = black ? Color.BLACK: Color.WHITE;
    }

    public void updateY()
    {
        y += 100;
    }
}