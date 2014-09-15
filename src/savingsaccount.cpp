#include "savingsaccount.h"
#include <iostream>

using namespace std;

int SavingsAccount::Withdrawl(double amount){
    if(balance < amount){
        cout << "WARNING: Insufficient funds. Cannot continue with transaction" << endl
             << "Current balance: " << balance << endl;
    }else{
        balance = balance - amount;
        cout << "Current balance: " << balance << endl;
    }



}
