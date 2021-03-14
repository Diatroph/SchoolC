import java.util.ArrayList;
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.FileWriter;
import java.io.FileReader;

public class Playlist {
	
	private ArrayList<Song> songs = new ArrayList<Song>();
	
	public Playlist(){
		
	}
	
	public Playlist(String filename)throws IOException {
		load(filename);		
	}
	
	private void load(String filename)throws IOException{
		BufferedReader reader = new BufferedReader(new FileReader(filename));
		
		String line = reader.readLine();
		while (line != null){			 
			songs.add(new Song(line));
			line = reader.readLine();
		}
		reader.close();
	}
	
	public void save(String filename)throws IOException{
		BufferedWriter writer = new BufferedWriter(new FileWriter(filename));
		
		for(int i = 0; i < songs.size(); i++){
			writer.write(songs.get(i).toString());
		}
		writer.close();
	}
	
	public void addSong(Song song){
		songs.add(new Song(song));
	}
	
	public void addSong(int index, Song song){
		songs.add(index, new Song(song));
	}
	
	public void addSongs(String filename)throws IOException{		
		load(filename);
	}
	
	public Song getSong(int index){
		return songs.get(index);
	}
	
	public int numSongs(){
		return songs.size();
	}
	
	public void playSong(int index){
		songs.get(index).incrementPlays();
	}
	
	public Song removeSong(int index){
		return songs.remove(index);
	}
	
	public String toString(){	
		if(songs.size() == 0) {
			return null;
		}
		
		String temp = (songs.get(0).getArtist() + "\n");
		for(int i = 1; i < songs.size();i++){			
			temp += (songs.get(i).toString()+"\n");
		}	
		
		return temp;
	}
	
	public String favoriteArtist(){
		//TODO
		String a = null;
		int b = 0;
		int c = 0; 
		for(int i = 0; i < songs.size();i++){			
			for(int j = 0; j < songs.size();j++){			
				if(songs.get(i).getArtist() == songs.get(j).getArtist()){
					//System.out.println(songs.get(j).getArtist());
					b++;					
				}				
			}
			//System.out.println(songs.get(i).getArtist());
			//System.out.println(String.format("%d", b));
			//System.out.println(String.format("%d", c));
			if(b > c){
				
				a = songs.get(i).getArtist();
				c = b;	
				b = 0;
				a = songs.get(i).getArtist();
			}		
		}
		return a;
	}
	
	public String totalPlaytime(){
		
		int min = 0;
		int sec = 0;
		int hour = 0;
		for(int i = 0; i < songs.size();i++){			
			min+=songs.get(i).getMinutes();
		}
		for(int i = 0; i < songs.size();i++){
			sec+=songs.get(i).getSeconds();
		}	
		if(sec >= 60){
			min += (sec/60);
			sec = sec%60;
		}
		if(min >= 60){
			hour += (min/60);
			min =  min%60;
		}		
		if(hour > 0){
			String returnValue = hour + ":" + String.format("%02d", min) + ":" + String.format("%02d", sec);
			return returnValue;
		}
		else{
			String returnValue = String.format("%02d", min) + ":" + String.format("%02d", sec);
			return returnValue;
		}		
	}		
}
