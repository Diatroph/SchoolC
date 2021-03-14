#include "fstack.h"
#include <cassert>
#include <iostream>
using namespace std;

fstack::fstack(int s) : size(s), tos(-1) {
    parray = new int[size];
    cout << "constr:" << size << " " << parray << endl;
}

fstack::fstack(const fstack& right){
    size = right.size;
    tos = right.tos;
    parray = new int [size];
    for(int i = 0; i<= tos; i++){
        parray[i] = right.parray[i];
    }
    cout << "copy constr:" << size << " " << parray << endl;
}

fstack::~fstack(){
    delete [] parray;
    cout << "destr:" << size << " " << parray << endl;
}

bool fstack::empty() const {
    return tos == -1;
}

bool fstack::full() const {
    return tos == size - 1;
}

void fstack::push(int data){
    assert(!full());
    ++tos;
    parray[tos] = data;
}

int fstack::top() const{
    assert(!empty());
    return parray[tos];
}

void fstack::pop(){
    assert(!empty());
    --tos;
}

fstack fstack::operator = (const fstack& right){
     if(size != right.size){
         cout << "(del)" << size << " " << parray << endl;
         delete [] parray;
         size = right.size;
         parray = new int[size];
         cout << "(new)" << size << " " << parray << endl;
     }
     tos = right.tos;
     for(int i = 0; i<=tos; i++){
         parray[i] = right.parray[i];
     }
    return *this;
 }

 bool fstack::operator == (const fstack& right) const{
     if(size != right.size){
         return false;
     }
     if(tos != right.tos){
         return false;
     }
     for(int i = 0; i<= tos; i++){
         if(parray[i] != right.parray[i]){
             return false;
         }
     }
     return true;
 }

 bool fstack::operator != (const fstack& right) const{
    return !operator==(right);
 }

 int fstack::operator[](int i)const{
     assert(0 <= i && i <= tos);
     return parray[i];
 }

 int& fstack::operator[](int j){
    assert(0 <= j && j <= tos);
    return parray[j];
 }