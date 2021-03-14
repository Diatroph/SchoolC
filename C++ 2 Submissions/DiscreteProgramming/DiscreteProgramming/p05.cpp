/*
Author:	Steven Lake
Student ID:	*20502948
E-Mail:	Slake2@uco.edu
CRN:	15441 IVE
Course:	CMSC 2123 � Discrete Structures
Assignment:	p03
Due:	October 5, 2020
*/
#include <iostream>
#include <array>
#include <fstream>
#include <iomanip>
#include <cstring>
#include <cstdlib>
#include <cmath>
using namespace std;

struct FileException {
    FileException(char* filename){
        cout << endl;
        cout << "File " << filename << " could not be opened." << endl;
    }
};

struct CommandLineException{
    CommandLineException(int permitted, int entered){
        cout << endl;
        cout << "Too many file names were entered on the command line."<< endl;
        cout << "Only " << permitted << " file names are permitted" << endl;
        cout << entered << " file names were entered." << endl;
    }
};

double log2(double x);
int analytical(int n); //TODO
int empiricial(int n);
void print(ostream& output, int n, int emp, int an);
void title(ostream& output);
void fragmentManager(istream& input, ostream& output);
void print2( int n, int emp, int an);
void fragmentManager2(istream& input);

int main(int argc, char* argv[]){       
  
    try {
        char inputFileName[255];        
        char outputFileName[255];

        switch(argc) {
            case 1:
                cout << "Enter the first file name. ";
                cin >> inputFileName;                
                cout << "Enter the output file name. ";
                cin >> outputFileName;
                break;
            case 2:
                strcpy(inputFileName, argv[1]);
                cout << "Enter the output file name. ";                
                cin >> outputFileName;
                break;            
            case 3:
                strcpy(inputFileName, argv[1]);               
                strcpy(outputFileName, argv[2]);
                break;
            default:
                throw CommandLineException(2, argc-1);
        }     
        ifstream input(inputFileName); if (!input) throw FileException(inputFileName);          
        ofstream output(outputFileName); if (!output) throw FileException(outputFileName);

        fragmentManager(input, output);
            
        input.close();       
        output.close();
    }
    catch(...) {
        cout << endl;
        cout << "The program has experienced a problem, closing the program" << endl;
        exit(EXIT_FAILURE);
    }
    return 0;
}

int analytical(int n){      
    return 3*(((pow(n, 2)-n))/2) + (4*n) + 3;
    
}

int empiricial(int n){
   int total = 0;
   int sum = 0;             total++; //1
   int i = 0;               total++; //1 
   while(i<n){              total++; //j   
        int j = 0;          total++; //j
        while(j<i){         total++; //k
            sum++;          total++; //k
            j++;            total++; //k 
        }                   total++; //j
        i++;                total++; //j       
   }                        total++; //1
   return total;                    //3k + 4j + 3
}

void print(ostream& output, int n, int an, int emp){ 
    output << endl;
    output << setw(5) << right << n;
    output << " ";
    output << setw(10) << right << an;
    output << " ";
    output << setw(10) << right << emp;
}

void title(ostream& output, int fn){
    output << endl;
    output << "Code Fragment " << fn;
    output << endl;
    output << setw(5) << right << "n";
    output << " ";
    output << setw(10) << right << "analytical";
    output << " ";
    output << setw(10) << right << "empirical";
}

void fragmentManager(istream& input, ostream& output){
    title(output, 5);
    for(;;){
        int n;
        input >> n;
        if(input.eof()){            
            break;
        }
        print(output, n, analytical(n), empiricial(n));
    }
}
