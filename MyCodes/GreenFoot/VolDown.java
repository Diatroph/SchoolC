import greenfoot.*;  // (World, Actor, GreenfootImage, Greenfoot and MouseInfo)

/**
 * Decreases the volume on the music from MPBase
 * 
 * @author Steven Lake
 * @version 5/2/19
 */
public class VolDown extends Actor
{
    private GreenfootImage down;  
    private int volume;
    public VolDown(){
        down = new GreenfootImage("Down.png");   
        
        setImage(down);        
    }    
    
    public void act() 
    {
        if(Greenfoot.mouseClicked(this)){
            volume = ((MPBase)getWorld()).getCurrent();
            if(volume>0){
                ((MPBase)getWorld()).setCurrent(volume-5);
            }            
        }
    }    
}
