#ifndef FUNDMOVEMENTVALIDATION_H
#define FUNDMOVEMENTVALIDATION_H

#include "savingsaccount.h"
#include "chequingaccount.h"
#include "htmllogger.h"

class FundMovementValidation
{
public:
    FundMovementValidation(){

    }

    long transferFunds(ChequingAccount &fromAccount, SavingsAccount &toAccount, double amount);

    long transferFunds(ChequingAccount &fromAccount, ChequingAccount &toAccount, double amount);

    long transferFunds(SavingsAccount &fromAccount, ChequingAccount &toAccount, double amount);

    long transferFunds(SavingsAccount &fromAccount, SavingsAccount &toAccount, double amount);

    long withdrawPaymentFromAccount(Account &fromAccount, double amount);

private:


};


#endif // FUNDMOVEMENTVALIDATION_H
