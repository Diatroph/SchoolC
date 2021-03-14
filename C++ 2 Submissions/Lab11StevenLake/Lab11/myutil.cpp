#include "myutil.h"
#include <cassert>
#include <algorithm>
#include <iostream>
using namespace std;


int myutil::sum(int n){
    assert(n >= 0);
    if(n == 0) return 0;
    else{
        return sum(n-1) + n;
    }
}

int myutil::fact(int n){//factorial
    assert(n >=0);
    if(n == 0) return 1;
    else{
        return fact(n-1)*n;
    }
}

int myutil::pow(int base, int exp){
    if(exp == 0) return 1;
    else return pow(base, exp-1)* base;
}

int myutil::fib(int n){
    if(n == 0) return 0;
    else if (n==1) return 1;
    return fib(n-1) + fib(n-2);
}

int myutil::sum(int values[], int size){
    assert(size > 0);
    if(size == 1) return values[0];
    else{
        return sum(values, size-1) + values[size -1];
    }
}

int myutil::largest(int data[], int size){
    assert(size > 0);
    if(size == 1) return data[0];
    else{
        int large = largest(data, size-1);
        return max(large, data[size-1]);        
    }
}

void myutil::hanoi(int ndisks){
    rhanoi(ndisks, 1, 3, 2);
}

void myutil::rhanoi(int ndisks, int s, int d, int t){
    assert(ndisks > 0);
    if(ndisks == 1){
        cout << "move from " << s << " to " << d << endl;
    } else {
        rhanoi(ndisks -1, s, t, d);
        cout << "move from " << s << " to " << d << endl;
        rhanoi(ndisks -1, t, d, s);
    }
}