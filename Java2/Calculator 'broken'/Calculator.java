/**
 * Lab 5 Calculator template
 * CS 2334 Spring 2020
 * 
 * This utility class is used by Driver to parse user input and calculate the 
 * results of calculator expressions.
 */
public class Calculator {

	/**
	 * This is the only method called by the Driver class. If the given 
	 * expression is valid, it returns the result. Otherwise, it returns an 
	 * error message that describes the problem.
	 */
	public static String calculate(String expression) {

		// TODO: Pass the given expression to parseAndCalc() and return the 
		// result as a String. If parseAndCalc() throws an exception, catch it 
		// and return an error message. The message should correspond to the 
		// exception type and have the format shown in the sample run in the 
		// README.
		//
		// parseAndCalc() can throw three types of exceptions:
		// 1. CalculatorNumTokensException
		// 2. CalculatorOperatorException
		// 3. NumberFormatException
		
		
		
		// The third type is thrown if an operand in the expression cannot be 
		// parsed as a double.
		String temp = Double.toString(parseAndCalc(expression));
		
		
		
				
		return temp;
	}
	
	/**
	 * Given a NumberFormatException caused by a String that cannot be parsed 
	 * as a double, return the String that caused the exception.
	 * Note: You do not need to change this method. It is intended to help you 
	 * create the corresponding error message in calculate().
	 */
	private static String getOperand(NumberFormatException exception) {
		String message = exception.getMessage();
		String[] tokens = message.split(" ");
		return tokens[tokens.length - 1];
	}
	
	/**
	 * Parse a given calculator expression and return the result.
	 */
	public static double parseAndCalc(String expression) {

		String[] tokens = expression.split("\\s+");		
		
		try {
			if(tokens.length == 2){
				if(!(tokens[0].equals("cos") || tokens[0].equals("sin") || tokens[0].equals("tan") || tokens[0].equals("log"))){					
					throw new CalculatorOperatorException(tokens[0]);
				}
				return calcTwoTokens(tokens);
			}		
			else if(tokens.length == 3){			
				if(!(tokens[1].equals("/") || tokens[1].equals("+") || tokens[1].equals("-") || tokens[1].equals("*") || tokens[1].equals("^"))){				
					throw new CalculatorOperatorException(tokens[1]);
				}	
				return calcThreeTokens(tokens);
			}
			else {
				throw new CalculatorNumTokensException(tokens.length);		
			}		
		}
		catch(CalculatorNumTokensException e) {			
			System.out.println("Invalid number of tokens: " + e.getMessage());			
		}
		catch(CalculatorOperatorException e){
			System.out.println("Invalid operator: " + e.getMessage());
		}	
		catch(NumberFormatException e){
			System.out.println("Cannot parse " + getOperand(e) + " as a double");			
		}
		return 0;
	}
	
	/**
	 * Given the tokens from a two-token expression, return the result. The 
	 * operator is stored at index 0, and the operand is stored at index 1.
	 * The possible operators are log, sin, cos, and tan.
	 */
	public static double calcTwoTokens(String[] tokens) {
		
		// TODO: Parse the operand as a double and return the result of the 
		// expression. If the operator is not "log", "sin", "cos", or "tan", 
		// throw a CalculatorOperatorException.
		
		double num1 = Double.parseDouble(tokens[1]);			
				
			if(tokens[0].equals("log")){
				return Math.log(num1);
			}
			if(tokens[0].equals("cos")){
				return Math.cos(num1);
			}
			if(tokens[0].equals("sin")){
				return Math.sin(num1);
			}
			if(tokens[0].equals("tan")){
				return Math.tan(num1);
			}		
		return 0;
	}

	/**
	 * Given the tokens from a three-token expression, return the result. The 
	 * operator is stored at index 1, and the operands are stored at indices 0 
	 * and 2. The possible operators are +, -, *, /, and ^.
	 */
	public static double calcThreeTokens(String[] tokens) {
		
		// TODO: Parse the operands as doubles and return the result of the 
		// expression. If the operator is not "+", "-", "*", "/", or "^", 
		// throw a CalculatorOperatorException.
		//
		// Note: The operator "^" stands for exponentiation. For instance, the 
		// result of the expression "3 ^ 2" is 9.
		
		
		double num2 = Double.parseDouble(tokens[2]);
		double num1 = Double.parseDouble(tokens[0]); 
		
		
			if(tokens[1].equals("/")){				
				return num1/num2;
			}
			if(tokens[1].equals("*")){
				return num1*num2;
			}
			if(tokens[1].equals("+")){
				return (num1+num2);
			}
			if(tokens[1].equals("-")){
				return num1-num2;
			}
			if(tokens[1].equals("^")){
				return Math.pow(num1, num2);
			}		
		return 0.0;
	}
}
