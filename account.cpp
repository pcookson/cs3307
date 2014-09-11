#include "account.h"

using namespace std;



int Account::Close(){
    //not yet implemented
    return 0;
}

int Account::Deposit(double amount){
    balance = balance + amount;
    return 0;
}

int Account::Withdrawl(double amount){
    return 0;
}

double Account::Get_Balance(){
    return balance;
}
