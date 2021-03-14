#pragma once
#include "node.h"

class bstree{
private:
    node* rootp;
    node* insert(node*, int);
    void print(node*) const;
    int find_min(node*) const;
    node* erase(node*, int);
public:
    bstree();
    void insert(int);
    void print() const;
    int find_min() const;
    void erase(int);
};