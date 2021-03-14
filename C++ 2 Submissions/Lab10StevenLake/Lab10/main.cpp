#include "tlist.h"
#include <cassert>
#include <cmath>
using namespace std;

#include "person.h"

int main(){
    tlist<person> plist;
    person p1("John", 25);
    person p2("Mary", 25);
    plist.append(p1);
    plist.append(p2);

    int posOfMary = plist.index_of(p2);
    

    tlist<double> m;
    assert(m.size() == 0);
    m.append(5.0 + 0.1 + 0.1 + 0.1 + 0.1 + 0.1);
    m.append(6);
    assert(m.size() == 2);
    //assert(m.get(0) == 5.5);
    const double E = 0.000000000001;
    assert(fabs(m.get(0) - 5.5) < E);
    assert(m.get(1) == 6);
    m.append(7);
    assert(m.get(2) == 7);


    tlist<int> mm;
    mm.insert(0, 10);
    mm.insert(1, 20);
    mm.insert(0, 15); //15 10 20
    assert(mm.get(0)==15);
    assert(mm.get(1)==10);
    assert(mm.get(2)==20);
    
    mm.insert(1, 99);//
    assert(mm.get(0) == 15);
    assert(mm.get(1) == 99);
    assert(mm.get(2) == 10);
    assert(mm.get(3) == 20);
    assert(mm.size() == 4);

    mm.insert(2, 77);
    assert(mm.get(0) == 15);
    assert(mm.get(1) == 99);
    assert(mm.get(2) == 77);
    assert(mm.get(3) == 10);
    assert(mm.get(4) == 20);
    assert(mm.size() == 5);

    mm.remove(0);
    assert(mm.get(0) == 99);
    assert(mm.get(1) == 77);
    assert(mm.get(2) == 10);
    assert(mm.get(3) == 20);
    assert(mm.size() == 4);
    mm.remove(0);
    mm.remove(0);
    mm.remove(0);
    assert(mm.get(0) == 20);
    assert(mm.size() == 1);
    mm.remove(0);
    assert(mm.size() == 0);

    tlist<int> a;
    a.append(1);
    a.append(2);
    a.append(3);
    a.append(4);
    a.append(5);
    
    assert(a.index_of(5) == 4);
    assert(a.index_of(4) == 3);
    assert(a.index_of(1) == 0);
    
    a.remove(4);
    a.remove(3);
    
    /*
    a.remove(1);
    assert(a.get(0) == 1);
    assert(a.get(1) == 3);
    assert(a.get(2) == 4);
    assert(a.get(3) == 5);
    assert(a.size() == 4);
    a.remove(2);
    assert(a.get(0) == 1);
    assert(a.get(1) == 3);
    assert(a.get(2) == 5);
    a.remove(1);
    assert(a.get(0) == 1);
    assert(a.get(1) == 5);
    a.remove(1);
    assert(a.get(0) == 1);
    assert(a.size() == 1);
    a.remove(0);
    assert(a.size() == 0);
    */




    return 0;
}