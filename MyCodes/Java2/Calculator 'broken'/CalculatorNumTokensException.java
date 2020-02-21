/**
 * Lab 5 CalculatorNumTokensException template
 * CS 2334 Spring 2020
 * 
 * A custom exception used by Calculator to indicate when an expression has an 
 * invalid number of tokens.
 */
public class CalculatorNumTokensException extends Exception {
	

	// Any class that inherits from Exception will generate a warning if this 
	// field is not initialized. We may discuss its use later in the semester.
	private static final long serialVersionUID = 1L;
	
	public CalculatorNumTokensException(int numTokens) {		
		super(Integer.toString(numTokens));	
	}
}
