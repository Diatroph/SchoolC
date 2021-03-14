class fstack {
private:
    int* parray;
    int size;
    int tos; //top of stack
public:
    fstack(int);
    fstack(const fstack&);
    ~fstack();
    bool empty() const;
    bool full() const;
    void push(int);
    int top() const;
    void pop();
    fstack operator = (const fstack&);
    bool operator == (const fstack&) const;
    bool operator != (const fstack&) const ;
    int operator[](int i) const;
    int& operator[](int j);
};