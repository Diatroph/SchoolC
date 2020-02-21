import java.io.IOException;

/**
 * Lab 3 Tests template
 * CS 2334 Spring 2020
 */
public class Tests {

	public static void main(String[] args) throws IOException {	
		
		
		String info = "Vital Signs,Rush,4:43";
		Song song = new Song(info);
		
		// Check that the fields were initialized correctly.
		if (!song.getTitle().equals("Vital Signs")) {
			System.out.println("Incorrect title");
		}
		if (!song.getArtist().equals("Rush")) {
			System.out.println("Incorrect artist");
		}
		if (song.getMinutes() != 4) {
			System.out.println("Incorrect minutes");
		}
		if (song.getSeconds() != 43) {
			System.out.println("Incorrect seconds");
		}
		if (song.getNumPlays() != 0) {
			System.out.println("Incorrect numPlays");
		}
		
		// If the number of plays is not changed, toString should return a
		// String that is identical to the one used to construct the object.
		if (!song.toString().equals(info)) {
			System.out.println("Incorrect String returned by toString");
		}
		
		// Increment the number of plays a bunch of times.
		for (int count = 0; count < 42; ++count) {
			song.incrementPlays();
		}
		
		// Check that the number of plays changed.
		if (song.getNumPlays() != 42) {
			System.out.println("incrementPlays incorrectly updated numPlays");
		}
		
		// The String output by toString now includes an optional fourth value 
		// that specifies the number of plays.
		String newInfo = "Vital Signs,Rush,4:43,42";
		if (!song.toString().equals(newInfo)) {
			System.out.println("Incorrect String returned by toString");
		}
		
		// Create a Playlist from a file of info Strings.
		Playlist playlist = new Playlist("example-playlist.csv");
		System.out.println(playlist);
		System.out.println(playlist.favoriteArtist());		
		
		// Check the Playlist methods favoriteArtist and totalPlaytime.
		String favArtist = "Bill Withers";
		String playtime = "22:04";
		if (!playlist.favoriteArtist().equals(favArtist)) {
			System.out.println("Incorrect favorite artist");
		}
		if (!playlist.totalPlaytime().equals(playtime)) {
			System.out.println("Incorrect total playtime");
		}
		
		// Add the same songs to the Playlist two more times and check that the 
		// new total playtime is correct.
		playlist.addSongs("example-playlist.csv");
		playlist.addSongs("example-playlist.csv");
		playtime = "1:06:12";
		if (!playlist.totalPlaytime().equals(playtime)) {
			System.out.println("Incorrect total playtime");
		}
		
	}
}
