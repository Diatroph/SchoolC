
public class Square extends Rectangle{
	private double side;
	public Square(double side) {
		super(side, side);
		this.side = side;
	}
	
	public double getSide(){
		return side;
	}
	
	public String getType(){
		return "Square";
	}
}
