/**
 * @author Steven Lake
 * CS 2334 Spring 2020
 * Project 1 Generation Class
 */
public class Generation{	
	/**
	 * Variables in this class, is length, cell array. 
	 */
	private int length = 0;
	Cell[] cell;		
	/**
	 * This is the constructor for the generation class, it will build an array of cells and assign them a character.
	 * @param array
	 */
	public Generation(boolean[] array){
		this.length = array.length;
		cell = new Cell[length];		
		for(int i = 0;i < length;i++){
			cell[i] = new Cell();
			if(array[i] == false){				
				this.cell[i].setStatus(false); 
			}
			else {				
				this.cell[i].setStatus(true);    
			}
		}
	}
	/**
	 * This method will read the array and return a boolean array based on the results. 
	 * @return
	 */	
	public boolean[] readStateArray(){
		boolean[] temp = new boolean[this.length];
		for(int i = 0; i < this.length;i++){
			if(this.cell[i].getStatus() == false){   
				temp[i] = false;
			}
			else {
				temp[i] = true;
			}
		}
		return temp;
	}
	/**
	 * This output gathers all of the Cell array's toString's a
	 */
	public String toString(){
		String temp = String.valueOf(cell[0]);
		for(int i = 1; i < this.length;i++){
			temp += String.valueOf(cell[i]);
		}
		return temp;
	}
	
}
