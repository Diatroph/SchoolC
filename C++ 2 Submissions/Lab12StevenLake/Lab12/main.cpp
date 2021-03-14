#include "bstree.h"
#include <cassert>
#include <iostream>
using namespace std;

int main(){
    bstree t1;
    //t1.insert(5);
    //t1.insert(4);
    //t1.insert(7);
    //t1.insert(3);

    const int N = 14;
    int data[] = {15, 20, 6,7,5,19,22,1,3,10,30,2,14,29};
    for(int i = 0; i< N; i++){
        t1.insert(data[i]);
    }


    t1.print();

    int min = t1.find_min();
    t1.erase(6);
    t1.print();

    return 0;
}