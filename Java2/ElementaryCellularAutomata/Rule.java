/**
 * @author Steven Lake
 * CS 2334 Spring 2020
 * Project 1 Rule Class
 */
public class Rule {
	private String ruleTemplate;
	private final static int BYTE = 8;
	char[] ruleArray = new char[BYTE];
	boolean[] previous;
	boolean[] nextRow;
	
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
	
	private void checkPreviousBuildNew(){		
		boolean left;
		boolean right;
		nextRow = new boolean[previous.length];
		for(int i = 0; i < previous.length;i++){
			if((i-1) < 0){
				left = false;
			}
			else{
				left = previous[i-1];
			}
			boolean middle = previous[i];
			
			if((i+1) > (previous.length-1)){
				right = false;
			}
			else{
				right = previous[i+1];	
			}	
			nextRow[i] = initiateRule(left, middle, right);
		}
	}
	
	public boolean[] nextRow(boolean[] array){		
		this.previous = array;
		checkPreviousBuildNew();		
		return nextRow;
	}
	
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
