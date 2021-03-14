#pragma once
#include "shape.h"

class rect : public shape{
private:
    //double x;
    //double y;
    double width;
    double height;
public:
    rect();
    rect(double, double);
    rect(double, double, double, double);
    double getArea() const;
    virtual double getArea() const;   --SQUARE
};