public class School {
	private Fish[] fishArray;
	private int numFish;
	private final static int DEFAULT_CAPACITY = 3;
	
	public School() {
		fishArray = new Fish[DEFAULT_CAPACITY];
	}
	
	public School(int capacity) {
		if(capacity <= 0){
			capacity = 1;
			fishArray = new Fish[1];				
		}
		else {
			fishArray = new Fish[capacity];
		}		
	}
	
	public int getNumFish() {				
		return numFish;
	}
	
	public int getCapacity() {		
		return fishArray.length;
	}
	
	private void doubleCapacity() {			
		Fish[] tempArray = new Fish[(getCapacity()*2)];	
		
		for(int i = 0; i < fishArray.length; i++){
			tempArray[i]=fishArray[i];
		}				
		fishArray = tempArray;
	}
	
	public void addFish(Fish fish) {
		if(getCapacity() == numFish) {
			doubleCapacity();
		}
		fishArray[numFish]=fish;
		this.numFish+=1;		
			
	}
	
	public Fish removeFish(int index) {
		if(index < 0 || fishArray[index]==null) {
			return null;
		}	
		Fish temp = fishArray[index];
		Fish[] tempArray = new Fish[getCapacity()];		
		fishArray[index] = null;
		int j = 0;
		for(int i = 0;i<fishArray.length;i++) {
			if(fishArray[i] != null) {				
				tempArray[j] = fishArray[i];
				j++;
			}		
		}		
		fishArray = tempArray;
		this.numFish-=1;
		return temp;
	}
	
	public Fish getFish(int index) {
		if (index < 0 || index >= numFish) {
			return null;
		}		
		return fishArray[index];
	}
	
	public Fish[] getFish() {
		Fish[] tempArray = new Fish[numFish];
		for(int i = 0;i<numFish;i++) {
			tempArray[i] = fishArray[i];
		}		
		return tempArray;	
	}
	
	public Fish[] getFish(String species) {
		int totalFishOfSpecies = 0;
		for(int i = 0;i<numFish;i++) {
			if(fishArray[i].getSpecies() == species) {
				totalFishOfSpecies++;
			}
		}			
		Fish[] tempArray = new Fish[totalFishOfSpecies];
		int j = 0;
		for(int i = 0;i<numFish;i++) {
			if(fishArray[i].getSpecies() == species) {
				tempArray[j] = fishArray[i];
				j++;
			}
		}		
		return tempArray;	
	}
	
	public Fish getBiggestFish() {
		if(numFish == 0) {
			return null;
		}
		Fish tempFish = fishArray[0];	
		double tempWeight = 0;		
		for(int i = 0;i<numFish;i++) {			
			if(fishArray[i].getWeight()>tempWeight) {
				tempWeight = fishArray[i].getWeight();
				tempFish = fishArray[i];
			}
		}
		return tempFish;
	}
	
	public double getWeight() {
		double tempDouble = 0;
		for(int i = 0;i<numFish;i++) {
			tempDouble += fishArray[i].getWeight();
		}		
		return tempDouble;		
	}
	
public String toString() {
		
		StringBuilder schoolInfo = new StringBuilder();
		
		// For each fish, append its number, info, and a newline character.
		for (int idx = 0; idx < numFish; ++idx) {
			Fish fish = fishArray[idx];
			schoolInfo.append(idx + 1 + ". ");
			schoolInfo.append(fish.toString());
			schoolInfo.append('\n');
		}
		
		// Remove the final newline character so an extra line is not printed 
		// to the console when printing the String with System.out.println.
		if (schoolInfo.length() > 0) {
			schoolInfo.deleteCharAt(schoolInfo.length() - 1);
		}
		
		return schoolInfo.toString();
	}
}
