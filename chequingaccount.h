#ifndef CHEQUINGACCOUNT_H
#define CHEQUINGACCOUNT_H

#include "account.h"

using namespace std;

class ChequingAccount : public Account{

public:
    ChequingAccount(double balance):Account(balance){
        ChequingAccount::balance = balance;
    }

    ChequingAccount(double balance) : Account(){
        ChequingAccount::balance = 0;
    }

    virtual int Withdrawl(double amount);


private:
    void get_input(double amount);

};

#endif // CHEQUINGACCOUNT_H
