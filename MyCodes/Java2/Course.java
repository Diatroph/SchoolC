
public class Course {
	private static final int MAX_SECTION_SIZE = 50;
	private String[] code = new String[2];
	private String name;
	private int numStudents;
	private int numSections = 0;	
	
	public Course(String info) {
		String temp = "";
		String[] tempArray1 = info.split(",");
		for (int i = 0; i < tempArray1.length; i++) {
			temp = tempArray1[0];
			this.name = tempArray1[1];
			this.numStudents = Integer.parseInt(tempArray1[2]);			
		}
		this.code = temp.split(" ");
		this.numSections = calcNumSections(this.numStudents);
	}
	
	private int calcNumSections(int numStudents) {		
		int dupe = numStudents;
		while(dupe > MAX_SECTION_SIZE) {
			numSections+=1;
			dupe-=MAX_SECTION_SIZE;
		}		
		return numSections+1;
	}
	
	public String[] getCode() {					
		return code.clone();
	}
	
	public String getName() {
		return name;
	}
	
	public int getNumStudents() {
		return numStudents;
	}
	
	public int getNumSections() {		
		return numSections;
	}
	
	public String toString() {
		String text = ("CODE: " + code[0] + " " + code[1] + ", NAME: " + name + ", STUDENTS: " + numStudents + ", SECTIONS: "
				+ numSections);
		return text;
		
		//System.out.println("CODE: " + code[0] + ", " + code[1] + ", NAME: " + name + ", STUDENTS: " + numStudents + ", SECTIONS: "
				//+ numSections);
		
		//System.out.printf("CODE: %s %s, NAME: %s, STUDENTS: %d, SECTIONS: %d", code[0],code[1],name,numStudents,numSections);
	}	
	
	
}
