#pragma once
#include "tnode.h"
#include <iostream>
#include <cassert>
using namespace std;

template<typename T>

class tlist {
private:
    tnode<T>* head;
    tnode<T>* tail;
    int count;
public:
    tlist();
    ~tlist();
    void append(T);
    int size() const;
    T get(int) const;
    void insert(int, T); //position and data
    void remove(int);
    int index_of(T) const;
};




template<typename T>
tlist<T>::tlist(): head(nullptr), tail(nullptr), count(0){

}
template<typename T>
tlist<T>::~tlist(){
    //
}

template<typename T>
void tlist<T>::append(T data){
    tnode<T>* p = new tnode<T>(data);
    if(count == 0){
        //empty list
        head = tail = p;
    } else {
        tail->link = p;
        tail = p;
    }
    count++;
}

template<typename T>
int tlist<T>::size() const{
    return count;
}

template<typename T>
T tlist<T>::get(int pos) const{
    assert(0 <= pos && pos < count);
    tnode<T>* n = head;
    for(int i = 0; i<pos; i++){
        n = n->link;
    }
    return n->data;
}

template<typename T>
void tlist<T>::insert(int pos, T data){
    assert(0 <= pos && pos <= count);
    if(pos == count || count == 0){
        append(data);
    }else if(pos == 0){
        //pushing of stack
        tnode<T>* p = new tnode<T>(data);
        p->link = head;
        head = p;
        count++;
    }else{
        tnode<T>* p = new tnode<T>(data);
        tnode<T>* left = head;
        for(int i = 0; i <pos -1; i++){
            left = left->link;
        }

        p->link = left->link;
        left->link = p;
        count++;
    }

}

template<typename T>
void tlist<T>::remove(int pos){
    assert(0 <= pos && pos < count);
    if (count == 1){
        delete head;
        head = tail = nullptr;
    }else if(pos == 0){
        tnode<T>* discard = head;
        head = head->link;
        delete discard;
    } else if(0 < pos && pos < (count-1)){
        tnode<T>* left = head;
        for(int i = 0; i <(pos-1); i++){
            left = left->link;
        }
        tnode<T>* discard = left->link;
        left->link = left->link->link;
        delete discard;
    }else{
        //tail
        tnode<T>* left = head;
        for(int i = 0; i <(count-2); i++){
            left = left->link;
        }
        delete tail;
        left->link = nullptr;
        tail = left;
    }
    count--;
}

template<typename T>
int tlist<T>::index_of(T data) const{
    assert(count > 0);
    tnode<T>* n = head;
    int pos = 0;

    while (n != nullptr){
        if(n->data == data){
            break;
        }
        pos++;
        n=n->link;
    }
    if(n == nullptr) return -1;
    return pos;
}