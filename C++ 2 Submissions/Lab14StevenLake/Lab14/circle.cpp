#include "circle.h"
#include <cmath>
#define _USE_MATH_DEFINES


circle::circle()
    : shape(), radius(0)
{}
    
circle::circle(double r)
    : shape(), radius(r)
{}

circle::circle(double xx, double yy, double r)
    : shape(xx, yy), radius(r)
{}
    
    
double circle::getArea() const{
    return M_PI * radius *radius;
}