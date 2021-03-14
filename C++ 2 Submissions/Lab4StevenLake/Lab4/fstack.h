class fstack {
private:
    int* parray;
    int size;
    int tos; //top of stack
public:
    fstack(int);
    ~fstack();
    bool empty() const;
    bool full() const;
    void push(int);
    int top() const;
    void pop();
};