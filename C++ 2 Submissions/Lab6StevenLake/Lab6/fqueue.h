#pragma once

class fqueue {
private:
    int* parray;
    int size;
    int ifront;
    int iback;
    int count;
public:
    fqueue(int);
    ~fqueue();
    bool empty() const;
    bool full() const;
    int length() const;
    void push(int);
    void pop();
    int front() const;
    int back() const;
};