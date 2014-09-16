#ifndef ACCOUNT_H
#define ACCOUNT_H

#define INSUFFICIENT_FUNDS 0x5


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

    int close();

    long deposit(double amount);

    virtual long withdrawl(double amount);

    double getBalance();

private:


};

#endif // ACCOUNT_H
