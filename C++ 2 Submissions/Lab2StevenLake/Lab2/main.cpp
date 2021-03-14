#include <iostream>
#include <string>
using namespace std;
#include "bankAccount.h"


int main(){


    int n;

    bankAccount b1; 

    n = 20;
    b1.set_id(2);
    b1.setName("Steve");
    b1.setBalance(0.10);


    cout << b1.get_id() << endl;
    cout << b1.getName() << endl;


    return 0;
}