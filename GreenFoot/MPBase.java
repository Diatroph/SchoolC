import greenfoot.*;  // (World, Actor, GreenfootImage, Greenfoot and MouseInfo)

/**
 * MPBase is the base "world" of the mp3 player. 
 * 
 * @author Steven Lake
 * @version 5/2/19
 */
public class MPBase extends World
{
    GreenfootSound music = new GreenfootSound("HotStuff.mp3"); 
    private int currentVolume;
    private int initVol = 50;    
    /**
     * Constructor for objects of class MPBase.
     * 
     */
    public MPBase()
    {            
        super(500, 200, 1);
        GreenfootImage background = getBackground();
        background.setColor(Color.LIGHT_GRAY);
        background.fill();        
        
        initialVolume(initVol);
        currentVolume = initVol;
        
        setButtons();       
    }
    
    public void setButtons(){
        Button button = new Button(music);        
        addObject (button, getWidth()/2, getHeight()/2);
        VolUp up = new VolUp();
        addObject (up, 57, 20);        
        VolDown down = new VolDown();
        addObject (down, 57, 87);
        VolumeBar bar = new VolumeBar();  
        addObject (bar, 11, 52);
        Volume volume = new Volume();
        addObject (volume, 57, 53); 
    }   
    
    public void act(){      
       //no acting
    }        
    
    public void initialVolume(int volume){
        music.setVolume(volume);        
    }    
    
    public int getCurrent(){
        return currentVolume;
    }
    
    public void setCurrent(int currentVolume){
        this.currentVolume = currentVolume;
        music.setVolume(currentVolume);
    }    
}
