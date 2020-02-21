// Star Search Programming Challenge
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

double JudgeData(double &);  //function protype meant to accept data from the judges
double findHighest (double, double, double, double, double);//function finds the highest score of the judges
double findLowest(double, double, double, double, double);//function finds the lowest score of the judges
void calcScore(double, double, double, double, double, double, double, double); //calculates the average minus the highest&lowest scores. 
void getName(string &); //function to gather name of performer
int main()
{
	double Judge1 = 0;         //base scores for the judges. 
	double Judge2 = 0;
	double Judge3 = 0;
	double Judge4 = 0;
	double Judge5 = 0;
	double Final = 0; //final average minus the highest/lowest value
	string performer;
	
	getName(performer); //base string for performer's name
	JudgeData(Judge1);	
	JudgeData(Judge2);	
	JudgeData(Judge3);	
	JudgeData(Judge4);	
	JudgeData(Judge5);

	double low = findLowest(Judge1, Judge2, Judge3, Judge4, Judge5);   //variable to hold the lowest value
	double high = findHighest(Judge1, Judge2, Judge3, Judge4, Judge5);   //variable to hold the highest value

	cout << performer << " scored an average of ";
	calcScore(Judge1, Judge2, Judge3, Judge4, Judge5, high, low, Final);
	cout << "." << endl;



	system("pause");
	return 0;
}

double JudgeData(double & num) // asks judge's for their votes loops until you give it a valid entry. 
{
	cout << "What is the score you would like to give to the performer? ";
	cin >> num;
	while (num < 0 || num > 10) {
		cout << "That is not a valid entry. Try a number from 1 to 10" << endl;
		cin >> num;
	}
	return num;
}

double findHighest(double Judge1, double Judge2, double Judge3, double Judge4, double Judge5) // finds the highest value from the judges
{
		if (Judge1 > Judge2 && Judge1 > Judge3 && Judge1 > Judge4 && Judge1 > Judge5)
			return Judge1;
		else if (Judge2 > Judge1 && Judge2 > Judge3 && Judge2 > Judge4 && Judge2 > Judge5)
			return Judge2;
		else if (Judge3 > Judge2 && Judge3 > Judge1 && Judge3 > Judge4 && Judge3 > Judge5)
			return Judge3;
		else if (Judge4 > Judge2 && Judge4 > Judge3 && Judge4 > Judge1 && Judge4 > Judge5)
			return Judge4;
		else if	(Judge5 > Judge2 && Judge5 > Judge3 && Judge5 > Judge4 && Judge5 > Judge1)
			return Judge5;
}

double findLowest(double Judge1, double Judge2, double Judge3, double Judge4, double Judge5)  // finds the lowest value from the judges
{
	
		if (Judge1 < Judge2 && Judge1 < Judge3 && Judge1 < Judge4 && Judge1 < Judge5)
			return Judge1;
		else if (Judge2 < Judge1 && Judge2 < Judge3 && Judge2 < Judge4 && Judge2 < Judge5)
			return Judge2;
		else if (Judge3 < Judge2 && Judge3 < Judge1 && Judge3 < Judge4 && Judge3 < Judge5)
			return Judge3;
		else if (Judge4 < Judge2 && Judge4 < Judge3 && Judge4 < Judge1 && Judge1 < Judge5)
			return Judge4;
		else if (Judge5 < Judge2 && Judge5 < Judge3 && Judge5 < Judge4 && Judge5 < Judge1)
			return Judge5;
	
}

void calcScore(double Judge1, double Judge2, double Judge3, double Judge4, double Judge5, double low, double high, double Final)  // calculates the average minus the highest and lowest. 
{
	Final = (((Judge1+Judge2+Judge3+Judge4+Judge5)-(low +high))/3);
	cout << setprecision(1) << fixed << Final;
}

void getName(string & performer)
{
	cout << "What is the name of the performer? ";
	cin >> performer;
	}