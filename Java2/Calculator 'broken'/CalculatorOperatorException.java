/**
 * Lab 5 CalculatorOperatorException template
 * CS 2334 Spring 2020
 * 
 * A custom exception used by Calculator to indicate when an expression has an 
 * invalid operator.
 */
public class CalculatorOperatorException extends Exception {	
	
	// Any class that inherits from Exception will generate a warning if this 
	// field is not initialized. We may discuss its use later in the semester.
	private static final long serialVersionUID = 2L;
	
	public CalculatorOperatorException(String operator) {		
		super(operator);
	}
}
