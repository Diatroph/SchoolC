#include <iostream>
using namespace std;

void f1(){
    cout << "Module 1" << endl;

    int p;
    double d = 3.14;
    char c = 'A';
    bool b = false;

    p = 10;
    int* x;  //pointer 'valueOf'
    x = &p; 

    *x = 20; //dereference - same as p variable
    int* y;
    y = x;
    *y = 30;

    double* x2;
    x2 = &d;

    char* x3;
    x3 = &c;

    bool* x4;
    x4 = &b;
}