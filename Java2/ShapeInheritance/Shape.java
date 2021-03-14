
public abstract class Shape implements Comparable<Shape>{
	private int id;
	private static int nextID = 0;
	
	public Shape() {
		this.id = nextID;
		nextID++;
	}
	
	public int getID() {
		return id;
	}
	
	public abstract String getType();	
	public abstract double getPerimeter();	
	public abstract double getArea();
	
	public int compareTo(Shape other) {		
		int type;
	
		type = this.getType().compareTo(other.getType());
		if(type == 0) {
			type = myComparison(this.getPerimeter(), other.getPerimeter());	
			if(type == 0) {
				type = myComparison(this.getArea(), other.getArea());						
			}
		}			
		return type;
	}
	
	public String toString() {
		return id + " " + nextID;
	}
	
	private int myComparison(double a1, double a2){
		
		if(a1 < a2){
			return -1;
		}
		else if (a1 > a2) {
			return 1;
		}
		else {
			return 0;
		}
	}
}
