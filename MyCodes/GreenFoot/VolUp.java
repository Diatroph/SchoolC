import greenfoot.*;  // (World, Actor, GreenfootImage, Greenfoot and MouseInfo)

/**
 * Increases the volume on the music from MPBase
 * 
 * @author Steven Lake
 * @version 5/2/19
 */
public class VolUp extends Actor
{
    private GreenfootImage up;
    private int volume;
    public VolUp(){
        up = new GreenfootImage("Up.png");
        setImage(up);
        
    }    
    /**
     * Act - do whatever the VolUp wants to do. This method is called whenever
     * the 'Act' or 'Run' button gets pressed in the environment.
     */
    public void act() 
    {
        if(Greenfoot.mouseClicked(this)){
            volume = ((MPBase)getWorld()).getCurrent();
            if(volume<100){
                ((MPBase)getWorld()).setCurrent(volume+5);
            }            
        }
    }    
}

