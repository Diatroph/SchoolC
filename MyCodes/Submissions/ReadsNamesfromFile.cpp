// Student Lineup
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
	ifstream inputFile;
	string name;
	inputFile.open("LineUp.txt");
	int students;

	cout << "How many students do you have in your class?" << endl;
	cin >> students;                // part of the programming challenge 14
	if (students <= 1 || students >= 25) {
		cout << "That is not a vaild entry." << endl;   //covers incorrect entries
	}
	cout << endl;  //I like it neat
	cout << "Their names are:" << endl;  

	while (inputFile >> name)  //uses all the names listed in the list
	{	
			cout << name << endl;	
	}
	inputFile.close();   //closes the inputfile
	system("pause");
	return 0;
}