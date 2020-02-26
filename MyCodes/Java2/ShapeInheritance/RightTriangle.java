
public class RightTriangle extends Triangle{
	
	private double base;
	private double height;

	public RightTriangle(double base, double height) {
		super(base, height, calcHypotenuse(base, height));	
		this.base = base;
		this.height = height;
	}
	
	private static double calcHypotenuse(double base, double height){		
		return Math.sqrt((Math.pow(height, 2))+(Math.pow(base, 2))); 
	}
	
	public double getBase(){
		return this.base;
	}
	
	public double getHeight(){
		return this.height;
	}
	
	public double getHypotenuse(){
		return calcHypotenuse(getBase(), getHeight());
	}
	
	public String getType(){
		return "RightTriangle";
	}
	
	public double getArea(){
		return ((height*base)/2); 
	}
}

	
