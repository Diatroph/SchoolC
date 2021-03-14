/**
 * Lab 2 Tests template
 * CS 2334 Spring 2020
 */
public class Tests {

	public static void main(String[] args) {
		
		// Construct some friendly fish!
		Fish fish1 = new Fish("Nemo", "clownfish", 0.2);
		Fish fish2 = new Fish("Marlin", "clownfish", 0.5);
		Fish fish3 = new Fish("Dory", "blue tang", 1.3);
		Fish fish4 = new Fish("Gill", "Moorish idol", 2.4);

		// Test the Fish toString method.
		String fish1Info = "Nemo, clownfish, 0.2 lb";
		if (!fish1.toString().equals(fish1Info)) {
			System.out.println("toString error: incorrect String returned");
			System.out.println("toString: " + fish1);
			System.out.println("correct:  " + fish1Info);
		}
		
		// Test the one-argument constructor.
		int initCapacity = 2;
		School school = new School(initCapacity);
		if (school.getCapacity() != initCapacity) {
			System.out.println("School ctor error: incorrect initial capacity");
		}
		if (school.getNumFish() != 0) {
			System.out.println("School ctor error: incorrect initial numFish");
		}

		// Add the fish to the school and print some information about it.
		school.addFish(fish1);
		school.addFish(fish2);
		school.addFish(fish3);
		System.out.println(school);
		System.out.println("capacity: " + school.getCapacity());
		System.out.println("numFish: " + school.getNumFish());
		
		// Test the method getFish(String species).
		Fish[] clownfish = school.getFish("clownfish");
		// Check if both Nemo and Marlin were returned.
		if (clownfish.length != 2) {
			System.out.println("getFish(species) error: incorrect length");
		}
		if (!clownfish[0].getName().equals("Nemo")) {
			System.out.println("getFish(species) error: Nemo is missing!");
		}
		if (!clownfish[1].getName().equals("Marlin")) {
			System.out.println("getFish(species) error: where's Marlin?");
		}
		
		// Add your own tests for the other School methods!
	}
}
