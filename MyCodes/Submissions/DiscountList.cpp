// 
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	int quantity;
	const double price = 99.00;
	double discountA;
	double discountB;
	double discountC;
	double discountD;
	double discount0;

	discountA = (price*.20);
	discountB = (price*.30);
	discountC = (price*.40);
	discountD = (price*.50);
	discount0 = (price * 0);


	cout << "~Music for your Ears~" << endl;
	cout << "How mamy copies would you like to purchase?" << endl;
	cin >> quantity;

	if (quantity != 0 && quantity < 10) {
		cout << "Normal Price   " << fixed << setprecision(2) << setw(8) << "$ " << setw(8) << (price * quantity) << endl;
		cout << "Discount Amount" << fixed << setprecision(2) << setw(8) << "$ " << setw(8) << (discount0*quantity) << endl;
		cout << "New Price    " << fixed << setprecision(2) << setw(8) << "$ " << setw(8) << ((price - discount0)*quantity) << endl;
	}
	else if (quantity >= 10 && quantity <= 19) {
		cout << "Normal Price   " << fixed << setprecision(2) << setw(8) << "$ " << setw(8) << (price * quantity) << endl;
		cout << "Discount Amount" << fixed << setprecision(2) << setw(8) << "$ " << setw(8) << (discountA*quantity) << endl;
		cout << "New Price    " << fixed << setprecision(2) << setw(8) << "$ " << setw(8) << ((price - discountA)*quantity) << endl;
	}
	else if (quantity >= 20 && quantity <= 49) {
		cout << "Normal Price   " << fixed << setprecision(2) << setw(8) << "$ " << setw(8) << (price * quantity) << endl;
		cout << "Discount Amount" << fixed << setprecision(2) << setw(8) << "$ " << setw(8) << (discountB*quantity) << endl;
		cout << "New Price    " << fixed << setprecision(2) << setw(8) << "$ " << setw(8) << ((price - discountB)*quantity) << endl;
	}
	else if (quantity >= 50 && quantity <= 99) {
		cout << "Normal Price   " << fixed << setprecision(2) << setw(8) << "$ " << setw(8) << (price * quantity) << endl;
		cout << "Discount Amount" << fixed << setprecision(2) << setw(8) << "$ " << setw(8) << (discountC*quantity) << endl;
		cout << "New Price    " << fixed << setprecision(2) << setw(8) << "$ " << setw(8) << ((price - discountC)*quantity) << endl;
	}
	else if (quantity >= 100) {
		cout << "Normal Price   " << fixed << setprecision(2) << setw(8) << "$ " << setw(8) << (price * quantity) << endl;
		cout << "Discount Amount" << fixed << setprecision(2) << setw(8) << "$ " << setw(8) << (discountD*quantity) << endl;
		cout << "New Price    " << fixed << setprecision(2) << setw(8) << "$ " << setw(8) << ((price - discountD)*quantity) << endl;
	}
	else
		cout << "Invalid Entry" << endl;
	system("pause");
	return 0;
}