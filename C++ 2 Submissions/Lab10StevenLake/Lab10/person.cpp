#include "person.h"
#include <string>

person::person(string n, int a)
    : name(n), age(a)
{ }

bool person::operator==(const person& right) const{
    if(name == right.name && age == right.age) return true;
    else return false;
}