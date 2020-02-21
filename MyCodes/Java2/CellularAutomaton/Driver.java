import java.io.IOException;
/**
 * @author Steven Lake
 * CS 2334 Spring 2020
 * Project 1 Driver Class
 * This class is simply to test and execute the given information
 */

public class Driver {

	public static void main(String[] args) throws IOException {				
		
		
		String test = "..OO.O..OO..O.O.";
		boolean[] array = new boolean[test.length()];
		for(int i = 0;i < test.length();i++){
			if(test.charAt(i)== 'O'){
				array[i] = true;
			}
			else{
				array[i] = false;
			}
		}	
		
					
		
		Automaton jive = new Automaton(92, array);
		jive.setFalseSymbol('.');
		jive.setTrueSymbol('O');
		jive.evolve(3);
		System.out.println(jive.toString());
		
		System.out.println("\n");
		
		/*
		Automaton Filejive = new Automaton("rule22-15cells-input.txt");
		Automaton Filejive2= new Automaton("rule22-63cells-input.txt");
		Automaton Filejive3= new Automaton("rule30-79cells-input.txt");
		
		//Filejive.evolve(8);
		Filejive.toString();
		Filejive.evolve(1);
		Filejive.toString();
		Filejive2.toString();
		Filejive2.evolve(1);
		Filejive2.toString();
		Filejive3.toString();
		Filejive3.evolve(1);
		Filejive3.toString();
		*/
		 
		
		
	}	
}