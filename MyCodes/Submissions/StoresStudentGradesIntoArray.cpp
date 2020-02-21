// Gradebook
#include <iostream>
#include <string>
using namespace std;


int main()
{
	const int Size = 5;           //Student Array Size
	const int TestSize = 4;             //Test Array Size
	string studentName[Size] = {};        // Variable to hold student names
	int Grade[TestSize] = {};             //Variable to hold student's grades
	int Final[Size] = {};                //variable to hold the final score for each student. 
	
	for (int i = 0; i < Size; i++)  //Sets loop for Array
	{
		int smallest = 0;
		int temp = 0;
		int Total = 0;
		cout << "What is the name of the student number " << (i+1) << "? "  ;
		cin >> studentName[i];
		for (int ScoreCount = 0; ScoreCount < TestSize; ScoreCount++)  //Sets loop for Grades
		{
			cout << "What was the student's score for test " << (ScoreCount + 1) << "? ";
			cin >> Grade[ScoreCount];
			cout << endl;
			
			temp = Grade[ScoreCount];
			
			smallest = Grade[i];             
			if (temp <= smallest)          //finds the smallest
				smallest = temp;

			Total = (Grade[ScoreCount] + Total);              // Running total
			Final[i] = ((Total - smallest) / (TestSize - 1));           //Formula for average minus the smallest
		}	
	}
		for (int studentCount = 0; studentCount < Size; studentCount++)  //displays name, score, and letter grade
		{
			cout << studentName[studentCount] << " scored a grade of " << Final[studentCount] << "%. Letter grade ";
					
				if (Final[studentCount] <= 100 && Final[studentCount] >= 90)
					cout << "A";
				else if (Final[studentCount] <= 89 && Final[studentCount] >= 80)
					cout << "B";
				else if (Final[studentCount] <= 79 && Final[studentCount] >= 70)
					cout << "C";
				else if (Final[studentCount] <= 69 && Final[studentCount] >= 60)
					cout << "D";
				else if (Final[studentCount] <= 59 && Final[studentCount] >= 0)
					cout << "F";
				else
					cout << "not read properly" << endl;
				cout << "." << endl;
		}
	cout << endl;
	system("pause");
	return 0;
}