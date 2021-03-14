#include <string>
using namespace std;

class bankAccount {//Interface? 
private:
    int id;
    string name;
    double balance;
public:
    void set_id(int n);
    int get_id();
    double get_balance();
    void setName(string j);
    string getName();
    void setBalance(double y);
};