#ifndef ACCOUNT_H
#define ACCOUNT_H

#include "../logger.h"
#include "../error.h"

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

#define SAVINGS_ACCOUNT 0X1
#define CHEQUING_ACCOUNT 0x2
#define CREDIT_ACCOUNT 0x4

using namespace std;

class Account
{
public:
    double balance;
    int id;


    /** @brief Empty account constructor.
     * Sets balance and id to 0
     */
    Account(){
        balance = 0;
        id=0;
    }

    /** @brief constructor that sets a starting balance
     *
     * @param starting_balance the amount of money to start with in an account
     */
    Account(double starting_balance){
        id=0;
    	balance = starting_balance;
    }

    /** @brief deposits money into the particular class
     *
     * @param amount the amount to deposit
     * @return integer for success or failure
     */
    int deposit(double amount);

    /** @brief virtual withdrawl method.
     * Accounts that inherit from Account must implement withdrawl
     * @param amount to withdraw
     * @return int for success or failure
     */
    virtual int withdrawl(double amount);

    /** @brief gets balance of the account
     *
     * @return int
     */
    double getBalance();

private:
    int get_input(double amount);

};

#endif // ACCOUNT_H
