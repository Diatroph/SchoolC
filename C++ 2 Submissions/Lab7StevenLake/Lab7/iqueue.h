#pragma once
#include "node.h"

class iqueue{
private:       
    node* pfront;
    node* pback;
    int count;
public:
    iqueue();
    ~iqueue();
    int length() const;
    bool empty() const;
    bool full() const;
    int front() const;
    int back() const;
    void push(int);
    void pop();
};