#include "account.h"
#include "htmllogger.h"
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

    virtual long withdrawl(double amount);

private:

};

#endif // SAVINGSACCOUNT_H
