#include <String>
#include <iostream>
using namespace std;
#include "fstack.h"
#include <cassert>

int main(){
    
    fstack f1(5);
    f1.push(5);
    f1.push(6);
    f1.push(7);
    
    fstack f2(10);
    f2.push(10);
    f2.push(11);
    f2.push(12);
    f2.push(13);
    f2.push(14);
    f2.push(15);

    fstack f3(7);

    //f3 = f2 = f1;

    //copy constructor
    fstack f4 = f1;

    //2, 3 copy called
    f3 = f2 = f1;

    if(f2 == f3){
        cout << "f2 == f3" << endl;

    }

    f3.push(22);

     if(f2 != f3){
        cout << "f2 != f3" << endl;
    }

    fstack t1(10);
    for(int i = 0; i < 10; i++){
        t1.push(i);
    }
    for(int i = 0; i < 10; i++){
        //cout << t1[i] << endl;
        assert(i == t1[i]);
    }
    t1[0] = 99;
    cout << t1[0] << endl;






    return 0;
}


