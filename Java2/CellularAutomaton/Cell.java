/**
 * @author Steven Lake
 * CS 2334 Spring 2020
 * Project 1 Cell Class
 * This class is filled into each slot of the generation array. 
 */
public class Cell {
	/**
	 * Private variable to hold the value of the given symbol to represent the class
	 */
	private boolean status;
	/**
	 * This constructor is empty, it is only used to make a new cell
	 */
	public Cell(){
		
	}
	/**
	 * This method retrieves the symbol of the given class.
	 * @return
	 */
	public boolean getStatus(){
		return status;
	}
	/**
	 * This method sets the symbol for the class. 
	 * @param symbol
	 */
	public void setStatus(boolean status){
		this.status = status;
	}
	/**
	 * This method is the output of the symbol.
	 */
	public String toString(){		
		return String.valueOf(status);
	}
}
