
public class Rectangle extends Polygon{
	
	private double width;
	private double height;
	
	public Rectangle(double width, double height) {		
		super(new double[]{width, height});
		this.width = width;
		this.height = height;
	}
	
	public double getWidth(){
		return width;
	}
	
	public double getHeight(){
		return height;
	}
	
	public String getType(){
		return "Rectangle";
	}
	
	public double getPerimeter(){
		return ((width +height)*2);
	}
	
	public double getArea(){
		return (width * height);
	}
}
