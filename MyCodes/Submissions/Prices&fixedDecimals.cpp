// 
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	int weight, distance, pdistance;
	cout << "What is the weight of your package in kg?" << endl;
	cin >> weight;
	cout << "How far, in miles, will your package be traveling?" << endl;
	cin >> distance;

	if (weight <= 0 || weight >= 20) {
		cout << "Items must weight at least 1kg and cannot exceed 20kg." << endl;
	}
	else if (distance < 10 || distance > 3000) {
		cout << "Only distances between 10 miles and 3000 miles can be entered. Anything more or less cannot be delivered." << endl;
	}
	else if (weight <= 2) {
		cout << "Your price is $ " << fixed << setprecision(2) << (1.10*(distance / 500)) << "." << endl;
	}
	else if (weight > 2 && weight <= 6) {
		cout << "Your price is $ " << fixed << setprecision(2) << (2.20*(distance / 500)) << "." << endl;
	}
	else if (weight > 6 && weight <= 10) {
		cout << "Your price is $ " << fixed << setprecision(2) << (3.70*(distance / 500)) << "." << endl;
	}
	else if (weight > 10 && weight <= 20) {
		cout << "Your price is $ " << fixed << setprecision(2) << (4.80*(distance / 500)) << "." << endl;
	}
	else {
		cout << "Invalid Entry." << endl;
	}
	system("pause");
	return 0;
}