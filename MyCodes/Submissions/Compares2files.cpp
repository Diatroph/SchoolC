// Exam Grader pt 1
#include <iostream>
#include <fstream>
using namespace std;

double checkAnswers(double &);
void printGrades();

int main()
{
	double grade = 0;
	checkAnswers(grade);
	if (grade > 70)
		cout << "Congratulations, you passed! You scored " << grade << "%" << endl;
	else
		cout << "You scored " << grade << "%, you will have to retake the test." << endl;

	printGrades();




	cout << endl;
	system("pause");
	return 0;
}

double checkAnswers(double & grade) //checks answers sends back grade
{
	const int Questions = 20;
	double truecount = 0, falsecount = 0;
	ifstream inputFile;    //variable for student's answers file
	ifstream inFile;       //variable for correct answers file.
	char correct[Questions] = {};
	char studentAns[Questions] = {};
	
	inputFile.open("StudentAnswers.txt");
	inFile.open("CorrectAnswers.txt");
	if (!inFile || !inputFile)
		cout << "Error finding the correct files" << endl;
	else
	{
		for (int count = 0; count < Questions; count++)
		{
			while (inputFile >> studentAns[count] && inFile >> correct[count]) {

				if (studentAns[count] == correct[count]) 
					truecount += 1;
				else if (studentAns[count] != correct[count]) 
					falsecount += 1;
			}
		}
		
	}	
	grade = ((20 - falsecount) / 20) * 100;
	inputFile.close();
	inFile.close();
	return grade;
}



void printGrades()  //displays number of questions missed, and percentage of correctness, displays all questions
{
	ifstream inputFile;    //variable for student's answers file
	ifstream inFile;       //variable for correct answers file.
	inputFile.open("StudentAnswers.txt");
	inFile.open("CorrectAnswers.txt");
	int count = 1;

	char letterx;
	char lettery;

	cout << "Question\t" << "Your Answer\t" << "Correct Answer\t" << endl;
	while (inputFile >> letterx && inFile >> lettery)
		{
			cout << count << "\t\t" << letterx << "\t\t" << lettery << endl;
			++count;
			
	}


	inputFile.close();
	inFile.close();
}
