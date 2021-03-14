#pragma once

class shape {
private:
    double x;
    double y;
public:
    shape();
    shape(double, double);
    virtual double getArea() const = 0; //pure virtualfunction
};