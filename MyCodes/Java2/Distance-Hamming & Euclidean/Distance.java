/** 
 * @category Class
 * @author Steven Lake *
 */
public class Distance {
	/**
	 * Fields are defined as protected to go across to the Hamming and Euclidean classes, but not to be editable by other means. 
	 */
	protected String description;
	protected String distance;
	/**
	 * This creates an empty distance class. It holds only empty values. 
	 */
	public Distance() {		
		description = "No argument";
		distance = "0";	
	}
	/**
	 * This distance class accepts an int variable and converts it to binary, then reads how many 1's are present within the binary string
	 */
	public Distance(int x) {
		
		int counter = 0;
		String bits = Integer.toBinaryString(x);		
		description = "Number of 1s in binary " + x + " (" + bits + ")";		
		for(int i = 0; i < bits.length();i++){
			if(bits.charAt(i) == '1'){
				counter++;
			}
		}
		distance = Integer.toString(counter);
		
	}
	/**
	 * This distance class accepts a string and defines the string in its ASCII value total. 
	 */
	public Distance(String s) {
		
		int counter = 0;
		for(int i = 0; i< s.length();i++){
			counter += s.charAt(i);
		}
		distance = Integer.toString(counter);
		description = "Sum of chars in \"" + s + "\"";		
	}
	/**
	 * This method returns the given description value and distance values afterwards. 
	 */
	@Override
	public String toString() {
		return description + ": " + distance;
	}
}
