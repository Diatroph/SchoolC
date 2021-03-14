import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.FileWriter;
import java.io.FileReader;
import java.util.ArrayList;
/**
 * @author Steven Lake
 * CS 2334 Spring 2020
 * Project 1 Automaton Class
 * This is the main class for the cellular Automaton. It integrates with the Generation, Rule, and Cell classes.
 */
public class Automaton {
	/**
	 * Variables are holding values for the rule number, char characters for true and false values, counter, a boolean array
	 * and new class rule and a generation class array.
	 * Counter variable is initialized at zero.
	 */	
	private int ruleNum;	
	private char falseSymbol;
	private char trueSymbol;
	private int counter = 0;
	boolean[] iniState;
	Rule rule;
	Generation[] generation;
	/**
	 * Automaton constructor, takes an int, and a boolean array. It will auto set the default characters to '0' for falase and '1' for true.
	 * It will assign these variables to the private variables of the class. 
	 */
	public Automaton(int ruleNum, boolean[] iniState) {		
		validateRuleNum(ruleNum);
		this.iniState = iniState;
		this.falseSymbol = '0';
		this.trueSymbol = '1';	
		this.rule = new Rule(this.ruleNum);	
				
	}
	public Automaton(String filename)throws IOException {
		BufferedReader reader = new BufferedReader(new FileReader(filename));
		ArrayList<String> fileArray = new ArrayList<String>();			
		String line = reader.readLine();
		
		
		while(line != null){			 
			fileArray.add(new String(line));		
			line = reader.readLine();		
		}
		validateRuleNum(Integer.parseInt(fileArray.get(0)));
		char[] TFSymbols = fileArray.get(1).toCharArray();
		
		this.falseSymbol = TFSymbols[0];
		this.trueSymbol = TFSymbols[2];
		this.iniState = convertToArray(fileArray.get(2));
		this.rule = new Rule(this.ruleNum);		
		reader.close();
	}
	public int getRuleNum() {
		return ruleNum;
	}
	public void evolve(int numSteps) {
		this.generation = new Generation[numSteps];
		
		
		for(int i = 0; i < numSteps; i++){
			generation[i] = new Generation(iniState, getFalseSymbol(), getTrueSymbol());
			iniState = rule.nextRow(getState(i));
			counter++;			
		}		
	}
	public int getTotalSteps() {		
		return (counter-1);
	}
	public boolean[] getState(int stepNum) {
		boolean[] array = generation[stepNum].readStateArray();
		return array;
	}
	public String getStateString(int stepNum) {		
		return generation[stepNum].toString();
	}
	public String toString() {		
		for(int i = 0;i<this.generation.length;i++){
			System.out.println(generation[i].toString());
		}
		return null;	
	}
	public void save(String filename)throws IOException {
		BufferedWriter writer = new BufferedWriter(new FileWriter(filename));
		
		for(int i = 0; i < this.generation.length; i++){
			writer.write(getStateString(i)+"\n");
		}
		writer.close();
	}
	public char getFalseSymbol() {
		return falseSymbol;
	}
	public void setFalseSymbol(char symbol) {
		this.falseSymbol = symbol; 
	}
	public char getTrueSymbol() {
		return trueSymbol;
	}
	public void setTrueSymbol(char symbol) {
		this.trueSymbol = symbol;	
	}
	
	private void validateRuleNum(int ruleNum){
		if(ruleNum > 255){
			this.ruleNum = 255;
		}
		else if(ruleNum < 0){
			this.ruleNum = 0;
		}
		else {
			this.ruleNum = ruleNum;
		}
	}
	
	private boolean[] convertToArray(String a){
		boolean[] array = new boolean[a.length()];
		for(int i = 0;i < a.length();i++){
			if(a.charAt(i)== '1'){
				array[i] = true;
			}
			else{
				array[i] = false;
			}
		}
		return array;
	}
}
