
public class Song {
	private static final int IDX_TITLE = 0;
	private static final int IDX_ARTIST = 1;
	private static final int IDX_LENGTH = 2;
	private static final int IDX_NUM_PLAYS = 3;
	
	private String title;
	private String artist;
	private int minutes;
	private int seconds;
	private int numPlays;
	
	public Song(String info){		
		String[] temp1 = info.split(",");
		String[] temp2 = temp1[2].split(":");
 		
		this.title = temp1[IDX_TITLE];
		this.artist = temp1[IDX_ARTIST];
		this.minutes = Integer.parseInt(temp2[0]);
		this.seconds = Integer.parseInt(temp2[1]);
		if(temp1.length == 4) {
			this.numPlays = Integer.parseInt(temp1[IDX_NUM_PLAYS]);
		}
	}
	
	public Song(Song other){
		this.title = other.getTitle();	
		this.artist = other.getArtist();
		this.minutes = other.getMinutes();
		this.seconds = other.getSeconds();
		this.numPlays = other.getNumPlays();		
	}
	
	public String getTitle(){
		return this.title;
	}
	
	public String getArtist(){
		return this.artist;
	}
	
	public int getMinutes(){
		return this.minutes;
	}
	
	public int getSeconds(){
		return this.seconds;
	}
	
	public String getLength(){
		String tempString = Integer.toString(minutes)+ ":" + Integer.toString(seconds);
		return tempString;
	}
	
	public int getNumPlays(){
		return numPlays;
	}
	
	public void incrementPlays(){
		numPlays++;
	}
	
	public String toString(){
		String temp;
		if(numPlays == 0){
			temp = title + "," + artist + "," + getLength();
		}
		else {
			temp = title + "," + artist + "," + getLength() + "," + numPlays;
		}			
		return temp;
	}
}
