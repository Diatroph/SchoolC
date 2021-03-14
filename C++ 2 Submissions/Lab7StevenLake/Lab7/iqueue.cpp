#include "iqueue.h"
#include <iostream>
#include <cassert>
using namespace std;

iqueue::iqueue()
    :pfront(nullptr), pback(nullptr), count(0)
{}

iqueue::~iqueue(){
    while(!empty()){
        pop();
    }
}

int iqueue::length() const {
    return count;
}
    
bool iqueue::empty() const{
    return count == 0;
}

bool iqueue::full() const{
    return false;
}

int iqueue::front() const{
    assert(!empty());
    return pfront->data;
}

int iqueue::back() const{
    assert(!empty());
    return pback->data;
}

void iqueue::push(int data){
    node* p = new node(data);
    if(count == 0){
        pfront = pback = p;
    }
    else{
        pback->link = p;
        pback = p;
    }
    count++;
}

void iqueue::pop(){
    assert(!empty());
    if(count == 1){
        delete pfront;
        pfront = pback = nullptr;
    }else{
        node* discard = pfront;
        pfront = pfront->link;
        delete discard;
    }
    count--;
}