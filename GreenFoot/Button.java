import greenfoot.*;  // (World, Actor, GreenfootImage, Greenfoot and MouseInfo)

/**
 * Plays and pauses the music that was selected in MPBase
 * 
 * @author Steven Lake
 * @version 5/2/19
 */
public class Button extends Actor
{
    private GreenfootImage play = new GreenfootImage("Play.png");
    private GreenfootImage pause = new GreenfootImage("Pause.png");
    private GreenfootSound music;    
    public Button(){
        setImage(play); 
    }
    
    public Button(GreenfootSound music){
        this.music = music;        
        
    }    
    
   public void act() 
    {
        if(Greenfoot.mouseClicked(this)){
            swaparoo();
        }
        
        if(!music.isPlaying()){ //this statement converts the image back if the mp3 file ends.
            setImage(play);
        }
    }
    
    public void swaparoo(){
        if(music.isPlaying()){
           setImage(play);
           music.pause();
        }        
        else{
           setImage(pause);
           music.play();
        }   
    }
  
}

