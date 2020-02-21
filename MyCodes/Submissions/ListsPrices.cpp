// Total Sales Tax Program
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main()
{
	int year;
	string month;
	double totalsales;
	double notax, county, state;
	
	cout << "Enter the year. ";
	cin >> year;
	cout << "Enter the month. ";
	cin >> month;
	cout << "Enter the total amount collected. ";
	cin >> totalsales;
	cout << "" << endl;
	cout << month << " " << year << endl;
	cout << "-------------------" << endl;
	cout << setprecision(2) << fixed;
	notax = totalsales / 1.06;
	county = notax*0.02;
	state = notax*0.04;
	cout << "Total Collected: " << setw(8) << "$ " << setw(9) << totalsales << endl;
	cout << "Sales:           " << setw(8) << "$ " << setw(9) << notax << endl;
	cout << "County Sales Tax:" << setw(8) << "$ " << setw(9) << county << endl;
	cout << "State Sales Tax: " << setw(8) << "$ " << setw(9) << state << endl;
	cout << "Total Sales Tax: " << setw(8) << "$ " << setw(9) << county+state << endl;
	system("pause");
	return 0;
}