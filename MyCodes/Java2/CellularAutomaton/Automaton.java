import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.FileWriter;
import java.io.FileReader;
import java.util.ArrayList;
import java.util.Arrays;
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
	private char falseSymbol = '0';
	private char trueSymbol = '1';
	private int counter = 0;
	boolean[] iniState;
	Rule rule;
	ArrayList<Generation> generation = new ArrayList<Generation>();
	/**
	 * @param ruleNum, iniState
	 * This Automaton constructor, takes an int, and a boolean array. It will auto set the default characters to '0' for falase and '1' for true.
	 * It will assign these variables to the private variables of the class. 
	 */
	public Automaton(int ruleNum, boolean[] iniState) {		
		validateRuleNum(ruleNum);
		this.iniState = iniState;		
		this.rule = new Rule(this.ruleNum);	
		generation.add(new Generation(iniState));		
	}
	/**	 * 
	 * @param filename
	 * @throws IOException
	 * This Automaton constructor reads information from a file in format of 
	 * <rule number>
	 * <false><" "><true>
	 * <initial start points "0000001000000">
	 */
	
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
		generation.add(new Generation(iniState));
		reader.close();
	}
	/** 
	 * @return
	 * This method returns the rule number.
	 */
	public int getRuleNum() {
		return ruleNum;
	}
	/**  
	 * @param numSteps
	 * This method takes the number of steps requested creates the generation classes for each step. 
	 */
	public void evolve(int numSteps) {			
		
		for(int i = 0; i < numSteps; i++){
			iniState = rule.nextRow(getState(i));
			generation.add(new Generation(iniState));
			
			counter++;			
		}		
	}
	/**
	 * This method returns the total steps that have taken place
	 * @return
	 */
	public int getTotalSteps() {		
		return (counter);
	}
	/**
	 * This method gets the state of a specific boolean array
	 * @param stepNum
	 * @return
	 */
	public boolean[] getState(int stepNum) {
		boolean[] array = generation.get(stepNum).readStateArray();
		return array;
	}
	/**
	 * This method returns a string of a specific generation array
	 * @param stepNum
	 * @return
	 */
	public String getStateString(int stepNum) {		
		boolean[] array = getState(stepNum); 
		String temp = "";
		for(int i = 0; i < array.length; i++) {
			if(array[i] == false) {
				temp += String.valueOf(getFalseSymbol());
			}
			else {
				temp += String.valueOf(getTrueSymbol());
			}
		}		
		return temp;		
	}
	/**
	 * This method returns the String output of each 
	 */
	public String toString() {	
		StringBuilder temp = new StringBuilder();		
		
		for(int i = 0; i < this.generation.size(); i++) {			
			temp.append(getStateString(i));
			temp.append('\n');
		}
		if (temp.length() > 0) {
			temp.deleteCharAt(temp.length() - 1);
		}
		return temp.toString();
	}
	/**
	 * This method will save the output of the generations to a file
	 * @param filename
	 * @throws IOException
	 */
	public void save(String filename)throws IOException {
		BufferedWriter writer = new BufferedWriter(new FileWriter(filename));
		
		for(int i = 0; i < this.generation.size(); i++){
			writer.write(getStateString(i)+"\n");
		}
		writer.close();
	}
	/**
	 * This method retrieves the false symbol
	 * @return
	 */
	public char getFalseSymbol() {
		return falseSymbol;
	}
	/**
	 * This method sets the false symbol
	 * @param symbol
	 */
	public void setFalseSymbol(char symbol) {
		this.falseSymbol = symbol; 
	}
	/**
	 * This method retrieves the true symbol
	 * @return
	 */
	public char getTrueSymbol() {
		return trueSymbol;
	}
	/**
	 * This method sets the true symbol
	 * @param symbol
	 */
	public void setTrueSymbol(char symbol) {
		this.trueSymbol = symbol;	
	}
	/**
	 * This method is private, it validates the rule number and sets it to 0 or 255 if the number provided goes above or below
	 * @param ruleNum
	 */	
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
	/**
	 * This method will take a string and convert the string into an array of true or false. This is meant to build
	 * the width of the graph and establish a starting point for the rules
	 * @param a
	 * @return
	 */
	private boolean[] convertToArray(String a){
		boolean[] array = new boolean[a.length()];
		for(int i = 0;i < a.length();i++){
			if(a.charAt(i)== getTrueSymbol()){
				array[i] = true;
			}
			else{
				array[i] = false;
			}
		}
		return array;
	}
}
