/**
 *  * @category Class
 * @author Steven Lake *
 * This class creates a Euclidean distance class, it extends from Distance, and uses the same fields and methods from Distance
 */
public class Euclidean extends Distance {
	/**
	 * This creates a Euclidean distance class. It then takes the given variables and finds the distances between them. 
	 */
	public Euclidean(int x1, int y1, int x2, int y2) {						
		description = "Euclidean distance between ("+ x1 + ", " + y1 +") and ("+ x2 + ", " + y2 + ")";		
		double x = (Math.pow((x2-x1),2));
		double y = (Math.pow((y2-y1),2));
		double temp = Math.sqrt(x+y);
		distance = Double.toString(temp);		
	}
}
