#include "rect.h"


rect::rect()
    : shape(), width(0), height(0)
    {}    
    
rect::rect(double w, double h)
    : shape(), width(w), height(h)
    {}

rect::rect(double xx, double yy, double w, double h)
    : shape(xx, yy), width(w), height(h)
{}    
    
double rect::getArea() const{
    return width * height;
}