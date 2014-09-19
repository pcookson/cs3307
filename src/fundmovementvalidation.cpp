#include "fundmovementvalidation.h"
#include "iostream"
#include <typeinfo>

using namespace std;


int FundMovementValidation::transferFunds(Account &fromAccount, Account &toAccount, double amount){

    try{
        ChequingAccount &fAccount = dynamic_cast<ChequingAccount&> (fromAccount);
        fAccount.withdrawl(amount);

    }catch(bad_cast& bc1)
    {
        SavingsAccount &fAccount = dynamic_cast<SavingsAccount&> (fromAccount);
        fAccount.withdrawl(amount);
    }

    try{

        SavingsAccount &tAccount = dynamic_cast<SavingsAccount&> (toAccount);
        tAccount.deposit(amount);
    }catch(bad_cast& bc)
    {
        ChequingAccount &tAccount = dynamic_cast<ChequingAccount&> (toAccount);
        tAccount.deposit(amount);
    }


    return 0;
}
