#include "account.h"
#ifndef SAVINGSACCOUNT_H
#define SAVINGSACCOUNT_H

using namespace std;

class SavingsAccount : public Account
{
public:
    SavingsAccount(double balance):Account(balance){
        SavingsAccount::balance = balance;
    }

    SavingsAccount():Account(){
        SavingsAccount::balance = 0;
    }

    virtual int Withdrawl(double amount);

private:

};

#endif // SAVINGSACCOUNT_H
