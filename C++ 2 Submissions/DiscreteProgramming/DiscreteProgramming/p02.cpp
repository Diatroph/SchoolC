/*
Author:	Steven Lake
Student ID:	*20502948
E-Mail:	Slake2@uco.edu
CRN:	15441 IVE
Course:	CMSC 2123 – Discrete Structures
Assignment:	p02
Due:	September 21, 2020
*/
#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <iomanip>
#include <cstring>
#include "List02.h"
using namespace std;

void cartesianManager(istream&, istream&, ostream&);
void cartesianProduct(List&, List&, ostream& );

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


int main(int argc, char* argv[]){
    try {
        char inputFileName1[255];        
        char outputFileName[255];

        switch(argc) {
            case 1:
                cout << "Enter the first file name. ";
                cin >> inputFileName1;                
                cout << "Enter the output file name. ";
                cin >> outputFileName;
                break;
            case 2:
                strcpy(inputFileName1, argv[1]);
                cout << "Enter the second file name. ";
                
                cin >> outputFileName;
                break;
            case 3:
                strcpy(inputFileName1, argv[1]);                
                cout << "Enter the output file name. ";
                cin >> outputFileName;
                break;
            case 4:
                strcpy(inputFileName1, argv[1]);
               
                strcpy(outputFileName, argv[3]);
                break;
            default:
                throw CommandLineException(3, argc-1);
        }     
        ifstream input1(inputFileName1); if (!input1) throw FileException(inputFileName1); 
         
        ofstream output(outputFileName); if (!output) throw FileException(outputFileName);
       
        cartesianManager(input1, output);        
        input1.close();       
        output.close();
    }
    catch(...) {
        cout << endl;
        cout << "The program has experienced a problem, closing the program" << endl;
        exit(EXIT_FAILURE);
    }
    return 0;
}

void cartesianManager(istream& input1, istream& input2, ostream& output){
    List list1;
    List list2;     
    list1.Scan(input1);    
    list2.Scan(input2);   
    list1.Print(output, "List 1");
    list2.Print(output, "List 2");
    cartesianProduct(list1, list2, output);
}

void cartesianProduct(List& list1, List& list2, ostream& output){
    List productList;
    
    while(list1.isFirst()  || (list2.hasNext() && list1.hasNext())){ //checks list2 to ensure that this list cannot be longer
        while(list2.isFirst() || (list2.hasNext() && list1.hasNext())){  //checks list1 to ensure that this list cannot be longer
            productList.Insert("(" + list1.getCurrentValue() + ", " + list2.getCurrentValue() + ")");
            list1.increment();
            list2.increment();            
        }
    }   
    productList.Print(output, "(List 1 X List 2)");
}