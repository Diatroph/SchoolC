#include "istack.h"
#include <iostream>
#include <cassert>
using namespace std;

istack::istack() : ptop(nullptr){

}
istack::~istack() {
    while(!empty()){
        pop();
    }
}

void istack::push(int data){
    node* new_node = new node(data);
    if(ptop == nullptr){
        ptop = new_node;
    }
    else {
        new_node->link = ptop;
        ptop = new_node;
    }
}

void istack::pop(){
    assert(!empty());
    if(ptop->link == nullptr){
        delete ptop;
        ptop = nullptr;
    }
    else {
        node* discard = ptop;
        ptop = ptop->link;
        delete discard;
    }
}

int istack::top() const{
    assert(!empty());
    return ptop->data;
}

bool istack::empty() const {
    return ptop == nullptr;
}

bool istack::full() const {
    return false;
}