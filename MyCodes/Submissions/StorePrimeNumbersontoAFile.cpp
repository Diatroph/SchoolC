// Prime Number Programming Challenge
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

bool isPrime(int); //determines whether or not a number is prime. 
void storePrime(int);  // Prompt's the user to store a prime number and asks for a file. 

int main()
{

	int num = 0; //starter variable to be checked if prime.
		cout << "A negative number will close the prime number program." << endl;  //lets user know when it ends.
	do {
		cout << "Please enter a number: ";
		cin >> num;
		if (isPrime(num))
		storePrime(num);
		else
		cout << num << " is not a prime number." << endl;
		} while (num > 0);
	
	system("pause");
	return 0;
}

bool isPrime(int num)
{
	for (int rem = 2; rem < num - 1; rem++)  // rem stands for remainder, local variable only
	{
		if (num%rem == 0)
			return false;
	}
	return true;
}

void storePrime(int num)
{
	ofstream outputFile;
	string filename;
	cout << "Enter the file name for prime number storage ";
	cin >> filename;
	outputFile.open(filename);
	if (outputFile) {
		outputFile << num << endl;
		outputFile.close();
		cout << "Prime number " << num << " is stored." << endl;
	}
	else
		cout << "Error opening the file." << endl;
}