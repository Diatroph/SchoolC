import greenfoot.*;  // (World, Actor, GreenfootImage, Greenfoot and MouseInfo)

/**
 * Displays bar value of the volume from the song in MPBase
 * 
 * @author Steven Lake
 * @version 5/2/19
 */
public class VolumeBar extends Actor
{
    private GreenfootImage volumeBar = new GreenfootImage(13,100); 
    private int currentVolume;
    public VolumeBar(){        
        volumeBar.drawRect(0,0,12,99);        
        volumeBar.fill();
        volumeBar.setColor(Color.RED);        
        volumeBar.fillRect(1,1,11,currentVolume);
        this.setRotation(180);
        setImage(volumeBar);        
    }
    
    public void act() {
        if(((MPBase)getWorld()).getCurrent() != currentVolume){            
            setVolume(((MPBase)getWorld()).getCurrent());                     
        }
    }
    
    /*I do not like this method, but I did not want a memory leak and the
     * bar would not empty...it stayed full when lower values were given.
     */
    public void setVolume(int currentVolume){
        this.currentVolume = currentVolume;      
        volumeBar = null;
        volumeBar = new GreenfootImage(13,100);        
        volumeBar.drawRect(0,0,12,99);
        volumeBar.setColor(Color.BLACK);
        volumeBar.fill();
        volumeBar.setColor(Color.RED);
        volumeBar.fillRect(1,1,11,currentVolume);
        setImage(volumeBar); 
    }    
}

