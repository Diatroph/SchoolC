#include "car.h"
#include <cassert>
#include <cmath>
#include <iostream>
using namespace std;


int main(){
    car c1;
    assert(c1.getGas() == 0.0);
    assert(c1.getOdo() == 0);

    
    //c1.set_gas(10 + .01 + .01 + .01 + .01 + .01);
    c1.set_gas(10.05);
    c1.set_odometer(1000);
    c1.set_mpg(18);    
    assert(fabs(c1.getGas() - 10.05) < 0.000000001);
    assert(c1.getOdo() == 1000);
    assert(c1.getMpg() == 18);
    c1.drive(40);

    car c2("Subaru", "Japan", 18009998888);

    c2.set_mpg(20);

    



    return 0;
}