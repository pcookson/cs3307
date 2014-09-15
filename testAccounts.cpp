#include "chequingaccount.h"
#include "savingsaccount.h"
#include <iostream>

using namespace std;



void transfer_funds(ChequingAccount &cAccount, SavingsAccount &sAccount, double amount){
    cAccount.Deposit(amount);
    sAccount.Withdrawl(amount);

}

int main(){
    ChequingAccount cAccount = ChequingAccount(1200);
    SavingsAccount sAccount = SavingsAccount(1200);

    cout << "Tests for Chequing Account" << endl
         << "****************************************************" << endl;

    cout << "Initial balance of chequing account:" << endl;
    cout << "balance: " << cAccount.Get_Balance() << endl << endl;

    cout << "Deposit 300.00 into chequing account:" << endl;
    cAccount.Deposit(300.00);
    cout << "balance: " << cAccount.Get_Balance() << endl << endl;

    cout << "Withdraw an amount that goes below 600.00:" << endl;
    cAccount.Withdrawl(600.00);
    cout << "balance: " << cAccount.Get_Balance() << endl << endl;

    cout << "Withdraw an amount that is greater than balance:" << endl;
    cAccount.Withdrawl(2000.00);
    cout << "balance: " << cAccount.Get_Balance() << endl << endl;

    cout << "Withdraw an acceptable amount:" << endl;
    cAccount.Withdrawl(5.00);
    cout << "balance: " << cAccount.Get_Balance() << endl << endl;

    cout << "Transfer funds from savings to chequing" << endl;
    cout << "chequing balance: " << cAccount.Get_Balance()  << endl;
    cout << "savings balance: " << sAccount.Get_Balance() << endl;
    transfer_funds(cAccount,sAccount, 200.00);
    cout << "chequing balance: " << cAccount.Get_Balance()  << endl;
    cout << "savings balance: " << sAccount.Get_Balance() << endl;


    cout << "****************************************************" << endl;



    cout << "Tests for Savings Account"  << endl
         << "**************************************************" << endl;

    cout << "Initial balance of savings account:" << endl;
    cout << "balance: " << sAccount.Get_Balance() << endl << endl;

    cout << "Deposit 300.00 into savings account:" << endl;
    sAccount.Deposit(300.00);
    cout << "balance: " << sAccount.Get_Balance() << endl << endl;

    cout << "Withdraw an amount that goes below 600.00:" << endl;
    sAccount.Withdrawl(600.00);
    cout << "balance: " << sAccount.Get_Balance() << endl << endl;

    cout << "Withdraw an amount that is greater than balance:" << endl;
    sAccount.Withdrawl(2000.00);
    cout << "balance: " << sAccount.Get_Balance() << endl << endl;

    cout << "Withdraw an acceptable amount:" << endl;
    sAccount.Withdrawl(5.00);
    cout << "balance: " << sAccount.Get_Balance() << endl << endl;


}


