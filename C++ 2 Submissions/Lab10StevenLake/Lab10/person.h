#pragma once
#include <string>
using namespace std;

class person{
private:
    string name;
    int age;
public:
    person(string, int);
    bool operator==(const person&) const;

};