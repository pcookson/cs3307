#ifndef ACCOUNT_H
#define ACCOUNT_H

using namespace std;

class Account
{
public:
    double balance;


    Account(){
        balance = 0;
    }

    Account(double starting_balance){
        balance = starting_balance;
    }

    int Close();

    int Deposit(double amount);

    virtual int Withdrawl(double amount);

    double Get_Balance();



private:


};

#endif // ACCOUNT_H
