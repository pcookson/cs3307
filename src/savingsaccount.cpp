#include "savingsaccount.h"
#include <iostream>

using namespace std;

long SavingsAccount::withdrawl(double amount){
    if(balance < amount){
        throw INSUFFICIENT_FUNDS;
    }else{
        balance = balance - amount;
        cout << "Current balance: " << balance << endl;
    }



}
