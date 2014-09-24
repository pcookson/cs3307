#include "fundmovementvalidation.h"
#include <iostream>
#include <typeinfo>

using namespace std;


int FundMovementValidation::transferFunds(Account &fromAccount, Account &toAccount, double amount){

    withdraw(fromAccount, amount);

    deposit(toAccount, amount);

    return 0;
}

int FundMovementValidation::withdraw(Account &fromAccount, double amount){

    try{
        ChequingAccount &fAccount = dynamic_cast<ChequingAccount&> (fromAccount);
        fAccount.withdrawl(amount);
        //pass account to DB

    }catch(bad_cast& bc1)
    {
        SavingsAccount &fAccount = dynamic_cast<SavingsAccount&> (fromAccount);
        fAccount.withdrawl(amount);
        //pass account to DB
    }

}

int FundMovementValidation::deposit(Account &toAccount, double amount){
    try{

        SavingsAccount &tAccount = dynamic_cast<SavingsAccount&> (toAccount);
        tAccount.deposit(amount);
        //pass account to DB
    }catch(bad_cast& bc)
    {
        ChequingAccount &tAccount = dynamic_cast<ChequingAccount&> (toAccount);
        tAccount.deposit(amount);
        //pass account to DB
    }
}
