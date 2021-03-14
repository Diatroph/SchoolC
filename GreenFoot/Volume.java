import greenfoot.*;  // (World, Actor, GreenfootImage, Greenfoot and MouseInfo)

/**
 * Displays numeric value of the volume from the song in MPBase
 * 
 * @author Steven Lake
 * @version 5/2/19
 */
public class Volume extends Actor
{
    private int currentVolume;       
    public Volume(){               
        setImage(new GreenfootImage(""+currentVolume, 25, null, null));         
    }    
    
    public void act() 
    {        
        if(((MPBase)getWorld()).getCurrent() != currentVolume){
            setVolume(((MPBase)getWorld()).getCurrent());
        }
    }
    
    public void setVolume(int currentVolume){
        this.currentVolume = currentVolume;
        setImage(new GreenfootImage(""+currentVolume, 25, null, null));
    }  
}
