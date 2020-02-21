// 
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	double CelBeg, CelEnd;

	cout << "Enter the initial temperature you would like to convert." << endl;
	cin >> CelBeg;
	cout << "Enter the final temperature you would like to convert." << endl;
	cin >> CelEnd;
	cout << setw(6) << "Celsius" << setw(12) << "Fahrenheit" << endl;
	cout << fixed << setprecision(2) << right << setw(6) << CelBeg << setw(12) << (CelBeg*1.8) + 32 << endl;
	while (CelBeg < CelEnd) {
		cout << fixed << setprecision(2) << right << setw(6) << ++CelBeg << setw(12) << (CelBeg*1.8) + 32 << endl;
	}
	while (CelBeg > CelEnd) {
		cout << fixed << setprecision(2) << right << setw(6) << --CelBeg << setw(12) << (CelBeg*1.8) + 32 << endl;
	}
	system("pause");
	return 0;
}