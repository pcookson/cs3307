#ifndef FUNDMOVEMENTVALIDATION_H
#define FUNDMOVEMENTVALIDATION_H

#include "savingsaccount.h"
#include "chequingaccount.h"
#include "account.h"
#include "../User/user.h"
#include "../logger.h"

class FundMovementValidation
{
public:
    FundMovementValidation(){

    }

    static int transferFunds(Account &fromAccount, Account &toAccount, double amount);

    static int withdraw(Account &fromAccount, double amount);

    static int deposit(Account &toAccount, double amount);

private:
    static SavingsAccount castToSavings(Account &sAccount);

    static ChequingAccount castToChequing (Account &cAccount);


};


#endif // FUNDMOVEMENTVALIDATION_H
