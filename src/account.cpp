#include "account.h"
#include <iostream>

using namespace std;



int Account::close(){
    //not yet implemented
    return 0;
}

int Account::deposit(double amount){
    balance = balance + amount;
    return DEPOSIT_SUCCESS;
}

int Account::withdrawl(double amount){
    return 0;
}

double Account::getBalance(){
    return balance;
}
