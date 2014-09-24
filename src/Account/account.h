#ifndef ACCOUNT_H
#define ACCOUNT_H

#include "../logger.h"

#define INSUFFICIENT_FUNDS 0x5

#define ACCEPTS_FEE 10
#define DECLINES_FEE 11
#define WITHDRAW_SUCCESSFUL 12
#define WITHDRAW_FAILURE 13
#define DEPOSIT_SUCCESS 14
#define DEPOSIT_FAILURE 15
#define TRANSFER_FUNDS 16

#define ADD_USER 20
#define DELETE_USER 21
#define ADD_CHEQUING_ACCOUNT 22
#define CLOSE_CHEQUING_ACCOUNT 23
#define ADD_SAVINGS_ACCOUNT 24
#define CLOSE_SAVINGS_ACCOUNT 25

#define TURNED_ON_LOGGING 30
#define TURNED_OFF_LOGGING 31

using namespace std;

class Account
{
public:
    double balance;
    int account_id;



    Account(){
        balance = 0;
    }

    Account(double starting_balance){
        balance = starting_balance;
    }

    int close();

    int deposit(double amount);

    virtual int withdrawl(double amount);

    double getBalance();

private:
    int get_input(double amount);


};

#endif // ACCOUNT_H
