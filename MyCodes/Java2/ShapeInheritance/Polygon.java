
public abstract class Polygon extends Shape{	
	
	public Polygon(double[] sideLengths){		
		for(int i = 0; i < sideLengths.length; i++){
			if(sideLengths[i] < 0){
				throw new IllegalArgumentException("Side lengths must be greater than zero.");
			}
		}
		
	}
}
