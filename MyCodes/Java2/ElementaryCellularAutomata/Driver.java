import java.io.IOException;
/**
 * @author Steven Lake
 * CS 2334 Spring 2020
 * Project 1 Automaton Class
 */

public class Driver {

	public static void main(String[] args) throws IOException {		
		char True = '2';
		char False = '1';	
		
		String test = "000000000000000010000000000000000";
		boolean[] array = new boolean[test.length()];
		for(int i = 0;i < test.length();i++){
			if(test.charAt(i)== '1'){
				array[i] = true;
			}
			else{
				array[i] = false;
			}
		}
					
		
		Automaton jive = new Automaton(222, array);
		jive.setFalseSymbol(False);
		jive.setTrueSymbol(True);
		jive.evolve(30);
		jive.toString();
		
		System.out.println("\n");
		
		Automaton Filejive = new Automaton("rule22-15cells-input.txt");
		Filejive.evolve(8);
		Filejive.toString();
		jive.save("test1.txt");
		Filejive.save("test2.txt");
		
		
	}	
}
