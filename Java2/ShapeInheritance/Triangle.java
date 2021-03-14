
public abstract class Triangle extends Polygon{
	private double sideA;
	private double sideB;
	private double sideC;
	
	public Triangle(double sideA, double sideB, double sideC) {		
		super(checkLengths(sideA, sideB, sideC));		
		this.sideA = sideA;
		this.sideB = sideB;
		this.sideC = sideC;		
	}
	/**
	 * reference material
	 * https://www.geeksforgeeks.org/python-checking-triangular-inequality-on-list-of-lists/
	 * @param a
	 * @param b
	 * @param c
	 * @return
	 */
	private static double[] checkLengths(double a, double b, double c){
		
		if(c > a + b || a > c + b || b > a + c){
			throw new IllegalArgumentException("The third line cannot exceed the sum of the other two lines.");
		}
		double[] temp = new double[]{a, b, c};
				
		
		return temp;
	}
	
	public double getSideA(){
		return sideA;
	}
	
	public double getSideB(){
		return sideB;
	}
	
	public double getSideC(){
		return sideC;
	}
	
	public double getPerimeter(){
		return (sideA + sideB + sideC);
	}
}
