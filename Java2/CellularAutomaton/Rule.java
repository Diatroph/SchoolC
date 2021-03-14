/**
 * @author Steven Lake
 * CS 2334 Spring 2020
 * Project 1 Rule Class
 * This class creates the next row, and establishes and enforces rules for the overall project
 */
public class Rule {
	/**
	 * Variables listed here, rule Array, the previous array, the next array, the max of BYTE. The rule
	 */	
	private String ruleTemplate;
	private final static int BYTE = 8;
	char[] ruleArray = new char[BYTE];
	boolean[] previous;
	boolean[] nextRow;

	/**
	 * The Rule constructor takes the rule number and converts it to a char array.
	 * @param ruleNum
	 */
	public Rule(int ruleNum){		
		ruleTemplate = Integer.toBinaryString(ruleNum);	
		
		for(int i = 0; i < BYTE; i++) {
			ruleArray[i] = '0';
		}
		int temp = (ruleTemplate.length()-1);
		for(int j = 0; j <= temp; j++) {		
			ruleArray[(BYTE-1)-j] = ruleTemplate.charAt(temp-j);
		}
	}		
	/**
	 * This method will take the previous row and determine what the next row is based on the rules
	 */
	private void checkPreviousBuildNew(){		
		boolean left;
		boolean right;
		nextRow = new boolean[previous.length];
		for(int i = 0; i < previous.length;i++){
			if((i-1) < 0){
				left = previous[previous.length-1];
			}
			else{
				left = previous[i-1];
			}
			boolean middle = previous[i];
			
			if((i+1) == (previous.length)){
				right = previous[0];
			}
			else{
				right = previous[i+1];	
			}	
			nextRow[i] = initiateRule(left, middle, right);
		}
	}
	/**
	 * This method takes the given array and calculates then returns the next row.
	 * @param array
	 * @return
	 */
	public boolean[] nextRow(boolean[] array){		
		this.previous = array;
		checkPreviousBuildNew();		
		return nextRow;
	}
	/**
	 * This method takes the previous row and verifies whether a rule is active/inactive, then states the next line
	 * @param left
	 * @param middle
	 * @param right
	 * @return
	 */
	private boolean initiateRule(boolean left, boolean middle, boolean right){		
		if(this.ruleArray[0] == '1'){
			if(left == true && middle == true && right == true){
				return true;
			}
		}
		if(this.ruleArray[1] == '1'){
			if(left == true && middle == true && right == false){
				return true;
			}
		}
		if(this.ruleArray[2] == '1'){
			if(left == true && middle == false && right == true){
				return true;
			}
		}
		if(this.ruleArray[3] == '1'){
			if(left == true && middle == false && right == false){
				return true;
			}
		}
		if(this.ruleArray[4] == '1'){
			if(left == false && middle == true && right == true){
				return true;
			}
		}
		if(this.ruleArray[5] == '1'){
			if(left == false && middle == true && right == false){
				return true;
			}
		}
		if(this.ruleArray[6] == '1'){
			if(left == false && middle == false && right == true){
				return true;
			}
		}	
		if(this.ruleArray[7] == '1'){
			if(left == false && middle == false && right == false){
				return true;
			}
		}		
		return false;
	}		
}
