#include "chequingaccount.h"
#include "savingsaccount.h"
#include "fundmovementvalidation.h"
#include "htmllogger.h"
#include <iostream>

using namespace std;

int main(){
    FundMovementValidation validator = FundMovementValidation();

    ChequingAccount cAccount = ChequingAccount(1200);
    SavingsAccount sAccount = SavingsAccount(1200);

    cout << "Tests for Chequing Account" << endl
         << "****************************************************" << endl;


    cout << "Initial balance of chequing account:" << endl;
    cout << "balance: " << cAccount.getBalance() << endl << endl;

    cout << "deposit 300.00 into chequing account:" << endl;
    cAccount.deposit(300.00);
    cout << "balance: " << cAccount.getBalance() << endl << endl;

    cout << "Withdraw an amount that goes below 600.00:" << endl;
    cAccount.withdrawl(600.00);
    cout << "balance: " << cAccount.getBalance() << endl << endl;

    cout << "Withdraw an amount that is greater than balance:" << endl;
    try{
        cAccount.withdrawl(2000.00);
    }catch(int e){
        if (e == INSUFFICIENT_FUNDS){
            cout << "Insuffcient Funds" << endl;
            cout << "balance: " << sAccount.getBalance() << endl << endl;
        }
    }

    cout << "balance: " << cAccount.getBalance() << endl << endl;

    cout << "Withdraw an acceptable amount:" << endl;
    cAccount.withdrawl(5.00);
    cout << "balance: " << cAccount.getBalance() << endl << endl;

    cout << "Transfer funds from savings to chequing" << endl;
    cout << "chequing balance: " << cAccount.getBalance()  << endl;
    cout << "savings balance: " << sAccount.getBalance() << endl;
    validator.transferFunds(cAccount,sAccount, 200.00);
    cout << "chequing balance: " << cAccount.getBalance()  << endl;
    cout << "savings balance: " << sAccount.getBalance() << endl;


    cout << "****************************************************" << endl;



    cout << "Tests for Savings Account"  << endl
         << "**************************************************" << endl;

    cout << "Initial balance of savings account:" << endl;
    cout << "balance: " << sAccount.getBalance() << endl << endl;

    cout << "deposit 300.00 into savings account:" << endl;
    sAccount.deposit(300.00);
    cout << "balance: " << sAccount.getBalance() << endl << endl;


    cout << "Withdraw an amount that goes below 600.00:" << endl;
    sAccount.withdrawl(600.00);
    cout << "balance: " << sAccount.getBalance() << endl << endl;
    HtmlLogger::setLoggingOnOff(0);
    cout << "Withdraw an amount that is greater than balance:" << endl;
    try{
        sAccount.withdrawl(2000.00);
    }catch(int e){
        if(e == INSUFFICIENT_FUNDS)
            cout << "Insuffcient Funds" << endl;
        cout << "balance: " << sAccount.getBalance() << endl << endl;
    }

    cout << "Withdraw an acceptable amount:" << endl;
    HtmlLogger::setLoggingOnOff(1);
    sAccount.withdrawl(5.00);
    cout << "balance: " << sAccount.getBalance() << endl << endl;


}


