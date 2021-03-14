#include "slist.h"
#include <iostream>
#include <cassert>
using namespace std;

slist::slist(): head(nullptr), tail(nullptr), count(0){

}
slist::~slist(){
    //
}

void slist::append(int data){
    node* p = new node(data);
    if(count == 0){
        //empty list
        head = tail = p;
    } else {
        tail->link = p;
        tail = p;
    }
    count++;
}

int slist::size() const{
    return count;
}

int slist::get(int pos) const{
    assert(0 <= pos && pos < count);
    node* n = head;
    for(int i = 0; i<pos; i++){
        n = n->link;
    }
    return n->data;
}

void slist::insert(int pos, int data){
    assert(0 <= pos && pos <= count);
    if(pos == count || count == 0){
        append(data);
    }else if(pos == 0){
        //pushing of stack
        node* p = new node(data);
        p->link = head;
        head = p;
        count++;
    }else{
        node* p = new node(data);
        node* left = head;
        for(int i = 0; i <pos -1; i++){
            left = left->link;
        }

        p->link = left->link;
        left->link = p;
        count++;
    }

}

void slist::remove(int pos){
    assert(0 <= pos && pos < count);
    if (count == 1){
        delete head;
        head = tail = nullptr;
    }else if(pos == 0){
        node* discard = head;
        head = head->link;
        delete discard;
    } else if(0 < pos && pos < (count-1)){
        node* left = head;
        for(int i = 0; i <(pos-1); i++){
            left = left->link;
        }
        node* discard = left->link;
        left->link = left->link->link;
        delete discard;
    }else{
        //tail
        node* left = head;
        for(int i = 0; i <(count-2); i++){
            left = left->link;
        }
        delete tail;
        left->link = nullptr;
        tail = left;
    }
    count--;
}

int slist::index_of(int data) const{
    assert(count > 0);
    node* n = head;
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