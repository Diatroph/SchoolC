/**
 * @author Steven Lake
 * CS 2334 Spring 2020
 * Project 1 Generation Class
 */
public class Generation{	
	
	private int length = 0;
	Cell[] cell;	
	char F;
	char T;
	public Generation(boolean[] array, char F, char T){
		this.length = array.length;
		cell = new Cell[length];
		this.F = F;
		this.T = T;
		for(int i = 0;i < length;i++){
			cell[i] = new Cell();
			if(array[i] == false){				
				cell[i].setSymbol(this.F); 
			}
			else {				
				cell[i].setSymbol(this.T);    
			}
		}
	}
	
	public boolean[] readStateArray(){
		boolean[] temp = new boolean[this.length];
		for(int i = 0; i < this.length;i++){
			if(this.cell[i].getSymbol() == this.F){   
				temp[i] = false;
			}
			else {
				temp[i] = true;
			}
		}
		return temp;
	}
	
	public String toString(){
		String temp = String.valueOf(cell[0]);
		for(int i = 1; i < this.length;i++){
			temp += String.valueOf(cell[i]);
		}
		return temp;
	}
	
}
