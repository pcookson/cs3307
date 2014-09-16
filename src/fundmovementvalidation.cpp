#include "fundmovementvalidation.h"
#include "iostream"

using namespace std;

long FundMovementValidation::transferFunds(ChequingAccount &fromAccount, ChequingAccount &toAccount, double amount){
    fromAccount.withdrawl(amount);
    toAccount.deposit(amount);
}


long FundMovementValidation::transferFunds(ChequingAccount &fromAccount, SavingsAccount &toAccount, double amount){
    fromAccount.withdrawl(amount);
    toAccount.deposit(amount);
}

long FundMovementValidation::transferFunds(SavingsAccount &fromAccount, ChequingAccount &toAccount, double amount){
    fromAccount.withdrawl(amount);
    toAccount.deposit(amount);
}

long FundMovementValidation::transferFunds(SavingsAccount &fromAccount, SavingsAccount &toAccount, double amount){
    fromAccount.withdrawl(amount);
    toAccount.deposit(amount);
}
