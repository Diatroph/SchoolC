#pragma once
#include "company.h"

class car{
private:
    double mpg;
    double gas;
    int odometer;
    company make;
    int sn;
    static int sn_gen;
public:
    car();
    car(string, string, long);
    void set_mpg(double);
    void set_gas(double);
    void set_odometer(int);
    double getMpg() const;
    double getGas() const;
    int getOdo() const;
    void drive(int);
};