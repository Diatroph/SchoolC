// Winning Division Programming Challenge
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

double getSales(double &);  //function protype meant to accept data for the variables
void findHighest(double, double, double, double);//function protype meant to find the highest score of the divisions

int main()
{
	double ne = 0;         //base variables for each vision
	double se = 0;
	double nw = 0;
	double sw = 0;
	int quarter;      // variable for quarters, cannot be less than 1, or more than 4
	string company;   // variable to display whichever company name is present. 
	company = "Chuingum Miner's Inc"; //a made up company name, none was mentioned in the Q&A

	cout << "Which sales quarter is being entered? ";
	cin >> quarter;
	while (quarter < 1 || quarter > 4) {  //see int quarter. 
		cout << "That is not a valid entry. Please enter a number between 1 and 4. ";
			cin >> quarter;
	}


	cout << "For quarter " << quarter << ", what is the total sales for the Northeast quadrant? $";
	getSales(ne);
	cout << "For quarter " << quarter << ", what is the total sales for the Southeast quadrant? $";
	getSales(se);
	cout << "For quarter " << quarter << ", what is the total sales for the Northwest quadrant? $";
	getSales(nw);
	cout << "For quarter " << quarter << ", what is the total sales for the Southwest quadrant? $";
	getSales(sw);
	cout << company << " had a total sales of $" << setprecision(2) << fixed << (se + nw + ne + sw) << " for quarter " << quarter << "." << endl;
	findHighest(ne, se, nw, sw);

	system("pause");
	return 0;
}

double getSales(double & num) // asks users for the sales. loops until you give it a valid entry. 
{
	cin >> num;
	while (num < 0) {
		cout << "That is not a valid entry. Try again" << endl;
		cin >> num;
	}
	return num;
}

void findHighest(double ne, double se, double nw, double sw)
{
	double high = 0;   //variable to hold the highest value
	string division = "";   // variable to put a name to the highest value. 
	
	if (ne > se && ne > nw && ne > sw) {
		high = ne;
			division = "Northeast";
	}
	if (se > ne && se > nw && se > sw) {
		high = se;
			division = "Southeast";
	}
	if (nw > se && nw > ne && nw > sw) {
		high = nw;
			division = "Northwest";
	}
	if (sw > se && sw > nw && sw > ne) {
		high = sw;
			division = "Southwest";
	}
	cout << "The " << division << " quadrant had the highest sales for this quarter with a total" << endl;
	cout << "sales of $" << setprecision(2) << fixed << high << "." << endl;
}

