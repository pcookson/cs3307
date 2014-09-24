#ifndef SAVINGSACCOUNT_H
#define SAVINGSACCOUNT_H

#include "account.h"

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

    virtual int withdrawl(double amount);

private:

};

#endif // SAVINGSACCOUNT_H
