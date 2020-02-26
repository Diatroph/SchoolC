import java.util.Comparator;

/* This class implements the [Comparator interface](https://docs.oracle.com/javase/8/docs/api/java/util/Comparator.html).
Comparator objects can be used by methods like those in the [Collections class](https://docs.oracle.com/javase/8/docs/api/java/util/Collections.html) to define alternative orderings for objects.
The sort method, for instance, has two versions: one that takes only a List and one that takes a List and a Comparator.
The first method sorts objects in the List using their compareTo method, which defines the default ordering.
The second method sorts the objects using the compare method of the Comparator.
Write the compare method of this class so that it sorts Shapes by their ID number.
*/


public class ShapeIDComparator implements Comparator<Shape>{
	
	public int compare(Shape primary, Shape other) {
		if(primary.getID() > other.getID()) {
			return 1;
		}
		else if(primary.getID() < other.getID()) {
			return -1;
		}
		else return 0;		
	}
}
