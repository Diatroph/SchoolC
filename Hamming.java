/**  
 * @category Class
 * @author Steven Lake 
 * This class creates a Hamming distance class, which calculates the distance between two strings, or two ints. 
 */
public class Hamming extends Distance {	
	/**
	 * This will create a Hamming class using two strings, then provide description and distance.
	 */
	public Hamming(String s1, String s2) {		
		description = "Hamming distance between " + s1 + " and " + s2;
		calcHammingDistance(s1, s2);
	}
	/**
	 * This will create a Hamming class using two int, then provide description and distance.
	 */
	public Hamming(int x, int y) {		
		String tempx = Integer.toBinaryString(x);
		String tempy = Integer.toBinaryString(y);
		description = "Hamming distance between "+ tempx + " and " + tempy;		
		calcHammingDistance(tempx, tempy);
	}
	/**
	 * This method will compare two given strings and calculate the Hamming distance.
	 */
	public void calcHammingDistance(String s1, String s2) {
		int counter = 0;		
		int diff = 0;
		int temp = 0;		
		int difference = 0;
		
		if(s1.length() != s2.length()) {	
			if(s1.length() > s2.length()){
				diff = s2.length();
				difference = (s1.length()-s2.length());
			}
			else {
				diff = s1.length();
				difference = (s2.length()-s1.length());
			}			
			for(int i = 0; i < diff; i++) {
				if(s1.charAt((s1.length()-1)-i)!= s2.charAt((s2.length()-1)-i)) {
					counter++;
				}
			}			
		}
		else {
			temp = (s1.length()-1);
			for(int i = temp; i > -1; i--){			
				if(s1.charAt(i)!= s2.charAt(i)) {
					counter++;
				}
			}	
		}		
		distance = Integer.toString(counter+difference);
	}
}
