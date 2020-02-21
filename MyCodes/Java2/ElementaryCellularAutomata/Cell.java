/**
 * @author Steven Lake
 * CS 2334 Spring 2020
 * Project 1 Cell Class
 */
public class Cell {
	
	private char symbol;
	
	public Cell(){
		
	}
	
	public char getSymbol(){
		return symbol;
	}
	
	public void setSymbol(char symbol){
		this.symbol = symbol;
	}
	
	public String toString(){		
		return Character.toString(symbol);
	}
}
