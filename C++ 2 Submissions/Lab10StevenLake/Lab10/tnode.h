#pragma once
#include <iostream>
using namespace std;

template<typename T>
class tnode {
private:    
    //int data;
    T data;
    tnode<T>* link;
public:
    tnode(T);
    
    template<typename U> friend class tlist;
};




template<typename T>
tnode<T>::tnode(T d) : data(d), link(nullptr){
    
}