#include "chequingaccount.h"
#include "savingsaccount.h"
#include "fundmovementvalidation.h"
#include "user.h"
#include <iostream>


using namespace std;


void logger(int logInt){
    string username = "patrick";
    User user = User(username);
    switch(logInt){
    case ACCEPTS_FEE:
        Logger::info(user.username + " accepted fee for withdrawl");
        break;
    case DECLINES_FEE:
        Logger::warning(user.username + " declines fee for withdrawl");
    case WITHDRAW_SUCCESSFUL:
        Logger::info("successfully withdrew money from account");
        break;
    case WITHDRAW_FAILURE:
        Logger::info("failed to withdraw money");
        break;

    case DEPOSIT_FAILURE:
        Logger::info("failed to deposit money");
        break;
    case DEPOSIT_SUCCESS:
        Logger::info("successfully deposited money");
        break;
    default:
        Logger::info("No logging for this situation");
    }
}

int main(){
    FundMovementValidation validator = FundMovementValidation();

    ChequingAccount cAccount = ChequingAccount(1200);
    SavingsAccount sAccount = SavingsAccount(1200);
    int chequingCheck;

    cout << "Tests for Chequing Account" << endl
         << "****************************************************" << endl;


    cout << "Initial balance of chequing account:" << endl;
    cout << "balance: " << cAccount.getBalance() << endl << endl;

    cout << "deposit 300.00 into chequing account:" << endl;
    chequingCheck = cAccount.deposit(300.00);
    logger(chequingCheck);
    cout << "balance: " << cAccount.getBalance() << endl << endl;

    cout << "Withdraw an amount that goes below 600.00:" << endl;
    chequingCheck = cAccount.withdrawl(600.00);
    logger(chequingCheck);

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
    chequingCheck = cAccount.withdrawl(5.00);
    logger(chequingCheck);
    cout << "balance: " << cAccount.getBalance() << endl << endl;

    cout << "Transfer funds from savings to chequing" << endl;
    cout << "chequing balance: " << cAccount.getBalance()  << endl;
    cout << "savings balance: " << sAccount.getBalance() << endl;
    validator.transferFunds(cAccount,sAccount, 200.00);
    cout << "new chequing balance: " << cAccount.getBalance()  << endl;
    cout << "new savings balance: " << sAccount.getBalance() << endl;


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
    Logger::setLoggingOnOff(0);
    cout << "Withdraw an amount that is greater than balance:" << endl;
    try{
        sAccount.withdrawl(2000.00);
    }catch(int e){
        if(e == INSUFFICIENT_FUNDS)
            cout << "Insuffcient Funds" << endl;
        cout << "balance: " << sAccount.getBalance() << endl << endl;
    }

    cout << "Withdraw an acceptable amount:" << endl;
    Logger::setLoggingOnOff(1);
    sAccount.withdrawl(5.00);
    cout << "balance: " << sAccount.getBalance() << endl << endl;


}
