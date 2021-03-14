#include "iqueue.h"
#include <cassert>
using namespace std;

int main() {
    iqueue m;
    assert(m.length() == 0);
    assert(m.empty());
    assert(!m.full());


    m.push(5);
    assert(m.front() == 5);
    assert(m.back() == 5);
    assert(m.length() == 1);
    m.push(6);
    assert(m.front()== 5);
    assert(m.back() == 6);
    assert(m.length() == 2);


    m.pop();
    assert(m.front() == 6);
    assert(m.back() == 6);
    assert(m.length() == 1);
    m.pop();    
    assert(m.length() == 0);

    m.push(99);

    return 0;
}