
public class Circle extends Shape {
	
	private double radius;
	
	public Circle(double radius) {
		if(radius < 0){
			throw new IllegalArgumentException("Radius must be a positive number.");
		}
		this.radius = radius;
	}
	
	public double getRadius(){
		return radius;
	}
	
	public String getType(){
		return "Circle";
	}
	public double getPerimeter(){
		return (Math.PI * (radius * 2)); 
	}
	
	public double getArea(){
		return (Math.PI * Math.pow(radius, 2)); 
	}
}
