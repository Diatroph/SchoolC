
public class Fish {
	
	private String name;
	private String species;
	private double weight;
	
	public Fish(String name, String species, double weight) {
		this.name = name;
		this.species = species;
		this.weight = weight;				
	}
	
	public String getName() {
		return name;
	}
	
	public String getSpecies() {
		return species;
	}
	
	public double getWeight() {
		return weight;
	}
	
	public String toString() {
		return String.format("%s, %s, %.1f lb", name, species, weight);
		
	}
}
