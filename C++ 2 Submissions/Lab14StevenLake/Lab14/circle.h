#pragma once
#include "shape.h"

class circle : public shape{
private:
    //double x;
    //double y;
    double radius;


public:
    circle();
    circle(double);
    circle(double, double, double);
    virtual double getArea() const;
};