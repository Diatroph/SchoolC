#include <String>
#include <iostream>
using namespace std;
#include "fstack.h"
#include <cassert>

int main(){
    
    fstack s1(5);
    assert(s1.empty());
    assert(!s1.full());

    s1.push(10);
    assert(!s1.empty());
    assert(!s1.full());

    assert(s1.top() == 10);
    s1.pop();
    assert(s1.empty());   

    return 0;
}


