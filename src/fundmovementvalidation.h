#ifndef FUNDMOVEMENTVALIDATION_H
#define FUNDMOVEMENTVALIDATION_H

#include "savingsaccount.h"
#include "chequingaccount.h"
#include "account.h"
#include "user.h"
#include "logger.h"

class FundMovementValidation
{
public:
    FundMovementValidation(){

    }

    int transferFunds(Account &fromAccount, Account &toAccount, double amount);

private:
    SavingsAccount castToSavings(Account &sAccount);

    ChequingAccount castToChequing (Account &cAccount);


};


#endif // FUNDMOVEMENTVALIDATION_H
