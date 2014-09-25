#include "chequingaccount.h"
#include "savingsaccount.h"
#include "fundmovementvalidation.h"
#include "User/user.h"
#include "dispatchloop.h"


#include <iostream>


using namespace std;





int main(){

    FundMovementValidation validator = FundMovementValidation();
    string userName = "patrick" ;

    //test program
    DispatchLoop();


//    ChequingAccount cAccount = ChequingAccount(1200);
//    SavingsAccount sAccount = SavingsAccount(1200);
//    int chequingCheck;

//    cout << "Tests for Chequing Account" << endl
//         << "****************************************************" << endl;


//    cout << "Initial balance of chequing account:" << endl;
//    cout << "balance: " << cAccount.getBalance() << endl << endl;

//    cout << "deposit 300.00 into chequing account:" << endl;
//    chequingCheck = cAccount.deposit(300.00);

//    Logger::log(chequingCheck, userName, 300.00, "chequing account");
//    cout << "balance: " << cAccount.getBalance() << endl << endl;

//    cout << "Withdraw an amount that goes below 600.00:" << endl;
//    chequingCheck = cAccount.withdrawl(600.00);

//    Logger::log(chequingCheck, userName, 600.00, "chequing account");

//    cout << "balance: " << cAccount.getBalance() << endl << endl;

//    cout << "Withdraw an amount that is greater than balance:" << endl;
//    try{
//        chequingCheck = cAccount.withdrawl(2000.00);

//        Logger::log(chequingCheck, userName, 2000.00, "chequing account");
//    }catch(int e){
//        if (e == INSUFFICIENT_FUNDS){
//            Logger::log(INSUFFICIENT_FUNDS_TO_WITHDRAW, userName, 0.0, "chequing account");
//            cout << "Insuffcient Funds" << endl;
//            cout << "balance: " << sAccount.getBalance() << endl << endl;
//        }
//    }

//    cout << "balance: " << cAccount.getBalance() << endl << endl;

//    cout << "Withdraw an acceptable amount:" << endl;
//    chequingCheck = cAccount.withdrawl(5.00);

//    Logger::log(chequingCheck, userName, 5.00, "chequing");
//    cout << "balance: " << cAccount.getBalance() << endl << endl;

//    cout << "Transfer funds from savings to chequing" << endl;
//    cout << "chequing balance: " << cAccount.getBalance()  << endl;
//    cout << "savings balance: " << sAccount.getBalance() << endl;
//    validator.transferFunds(sAccount,cAccount, 200.00);
//    cout << "new chequing balance: " << cAccount.getBalance()  << endl;
//    cout << "new savings balance: " << sAccount.getBalance() << endl;

//    Logger::log(TRANSFER_FUNDS, userName, 200.00, "savings", "savings", "chequing");


//    cout << "****************************************************" << endl;



//    cout << "Tests for Savings Account"  << endl
//         << "**************************************************" << endl;


//    cout << "Initial balance of savings account:" << endl;
//    cout << "balance: " << sAccount.getBalance() << endl << endl;

//    cout << "deposit 300.00 into savings account:" << endl;
//    chequingCheck = sAccount.deposit(300.00);

//    Logger::log(chequingCheck, userName, 300.00, "savings account");
//    cout << "balance: " << sAccount.getBalance() << endl << endl;


//    cout << "Withdraw an amount that goes below 600.00:" << endl;
//    chequingCheck= sAccount.withdrawl(800.00);

//    Logger::log(chequingCheck, userName, 600.00, "savings account");
//    cout << "balance: " << sAccount.getBalance() << endl << endl;
//    //Logger::setLoggingOnOff(0);
//    cout << "Withdraw an amount that is greater than balance:" << endl;
//    try{
//        chequingCheck= sAccount.withdrawl(2000.00);

//        Logger::log(chequingCheck, userName, 2000.00, "savings account");
//    }catch(int e){
//        if(e == INSUFFICIENT_FUNDS)
//            Logger::log(INSUFFICIENT_FUNDS_TO_WITHDRAW, userName, 0.0, "savings account");
//            cout << "Insuffcient Funds" << endl;
//        cout << "balance: " << sAccount.getBalance() << endl << endl;
//    }

//    cout << "Withdraw an acceptable amount:" << endl;
//    //Logger:://Logger::setLoggingOnOff(1);
//    chequingCheck = sAccount.withdrawl(5.00);

//    Logger::log(chequingCheck, userName, 5.00, "savings account");
//    cout << "balance: " << sAccount.getBalance() << endl << endl;


}
