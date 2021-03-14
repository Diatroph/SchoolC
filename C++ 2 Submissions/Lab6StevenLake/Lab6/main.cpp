#include <iostream>
#include <cassert>
using namespace std;
#include "fqueue.h"

int main(){
    fqueue q(10);
    assert(q.empty());
    assert(!q.full());
    assert(q.length()==0);

    q.push(20);
    assert(!q.empty());
    assert(q.length() == 1);
    assert(q.front() == 20);
    assert(q.back() == 20);
    q.push(30);
    assert(q.front() == 20);
    assert(q.back() == 30);
    assert(q.length() == 2);

    q.pop();
    assert(q.front() == 30);
    assert(q.back() == 30);
    q.pop();
    assert(q.empty()); 

    return 0;
}