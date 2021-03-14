/*
Author:	Steven Lake
Student ID:	*20502948
E-Mail:	Slake2@uco.edu
CRN:	15441 IVE
Course:	CMSC 2123 – Discrete Structures
Assignment:	p02
Due:	September 21, 2020
*/
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <string>
#include <fstream>

#include "List02.h"
using namespace std;

struct ListException{
    ListException(const char* message){
        cout << endl;
        cout << "This list is " << message << "." << endl;
    }
};

//Constructors
List::List(int sz) : size(sz), count(0), cursor(0){arrayList=new string[size];}

List::List(istream& input, int sz) : size(sz), count(0), cursor(0){arrayList = new string[size]; Scan(input);}

List::~List(){if (arrayList) delete[] arrayList;}


//Functions
bool List::isFull() {return (count >= (size-1));}

bool List::isEmpty() {return (count <= 0);}

void List::Insert(string lineItem){
    if(isFull()){
        throw ListException("full");
    }
    arrayList[count++]=lineItem;
}

void List::Scan(istream& input){
    for(;;){
        string lineItem;
        input >> lineItem;
        if (input.eof()) {break;}        
        Insert(lineItem);
    }    
}

void List::Print(ostream& output, const char* title){
    output << endl << title;
    output << "={";
    for(int i = 0; i < count; i++){        
        if(i > 0){output << ",";}
        output << arrayList[i];
    }
    output << "}" << endl;
}

bool List::isFirst(){
    if(cursor == 0){
        return true;
    }
    return false;
}

bool List::hasNext(){
    if(cursor < count){        
        return true;
    }
    return false;
}

string List::getCurrentValue(){
    return arrayList[cursor];
}

void List::increment(){
    cursor++;
}

