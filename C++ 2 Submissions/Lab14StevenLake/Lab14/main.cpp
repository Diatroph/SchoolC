#include "circle.h"
#include <cassert>
#include "rect.h"

int main(){
    circle c1(1, 2, 3.6);
    rect r1(3,0,10,50);
    double a;
    a = c1.getArea();
    a = r1.getArea();

    circle c2;
    circle c3(5);

    rect r2;
    rect r3(2,6);

    //shape s1;
    //shape s2(2,3);
    //double area = s2.getArea();
    double area;
    area = r2.getArea();
    area = c3.getArea();

    //s1 = r2; //super to sub
    shape* sp; //= new shape(3,5);
    //area = sp->getArea();
    circle* cp = new circle(2, 2, 10);
    area = cp->getArea();

    sp = cp; //sub to super
    area = sp->getArea();
    //cp = sp; //error

    rect* rp = new rect(1,2,5,6);
    area = rp->getArea();
    sp = rp;
    area = sp->getArea();

    shape* shapes[6];

    shapes[0] = new rect;
    shapes[1] = new rect(3, 3);
    shapes[2] = new circle(3);
    shapes[3] = new circle();
    shapes[4] = new circle(1,2,10);
    shapes[5] = new rect(1,2,10,10);

    for(int i = 0; i < 6; i++){
        area = shapes[i]->getArea();
    }

    return 0;
}