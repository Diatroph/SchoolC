#include "car.h"
#include <cassert>
using namespace std;

int car::sn_gen = 0;


car::car():mpg(0),gas(0), odometer(0),make(company("n/a", "n/a", 0)){
    sn = sn_gen;
    ++sn_gen;
}

car::car(string name, string address, long phone)
    : mpg(0), gas(0), odometer(0), make(company(name, address, phone))
{
        sn = sn_gen;
        ++sn_gen;
}

void car::set_mpg(double mpg){
    this->mpg = mpg;
}
void car::set_gas(double gas){
    this->gas = gas;
}
void car::set_odometer(int odometer){
    this->odometer = odometer;
}
double car::getMpg() const{
    return this->mpg;
}
double car::getGas() const{
    return this->gas;
}
int car::getOdo() const{
    return this->odometer;
}
void car::drive(int miles){
    assert(mpg > 1.0);   
    double gas_needed = miles/mpg;
    assert(gas_needed <= gas);
    odometer += miles;
    gas -= gas_needed;
}