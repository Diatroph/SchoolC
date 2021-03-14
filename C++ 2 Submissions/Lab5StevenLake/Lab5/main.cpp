#include "node.h"
#include "istack.h"
#include <iostream>
#include <cassert>
using namespace std;

int main(){

    istack s1;
    /*
    s1.push(5);
    int n = s1.top();
    s1.push(6);
    n = s1.top();
    s1.pop();    
    n = s1.top();
    s1.pop();
    */

   const int N = 5000;
   assert(s1.empty());
   assert(!s1.full());

   for (int i = 0; i<N;i++){
       s1.push(i);
       assert(!s1.empty());
   }
   assert(!s1.full());

    for (int i = N-1; i>=0; i--){
        assert(s1.top() == i);
        s1.pop();
    }
    assert(s1.empty());
    
    return 0;
}