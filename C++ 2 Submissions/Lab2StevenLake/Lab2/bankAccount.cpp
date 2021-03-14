#include "bankAccount.h"
    

    void bankAccount::set_id(int n){
        id = n;
    }
    int bankAccount::get_id(){
        return id;
    }
    double bankAccount::get_balance(){
        return balance;
    }
    void bankAccount::setName(string j){
        name = j;
    }
    string bankAccount::getName(){
        return name;
    }
    void bankAccount::setBalance(double y){
        balance = y;
    }
