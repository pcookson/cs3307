#include "chequingaccount.h"
#include <iostream>
#define CURSOR = ">"
using namespace std;

int ChequingAccount::Withdrawl(double amount){
    int inputContinue;

    if((balance > 1000.00) && (balance - amount < 1000)){
        cout << "WARNING: This transaction will cause balance to drop below $1000.00.\n"
             << "This transaction, and every subsequent transaction will be subject to\n"
             <<"a $2.00 service fee.\n"
            <<"Do you wish to continue with transaction? (y/n)";

        do{
            inputContinue = get_input(amount);
        }while(inputContinue);


    }else if(balance < 1000.00){
        cout << "WARNING: Balance is below $1000.00. This transaction will be subject to\n"
             << "a $2.00 service fee.\n"
             <<"Do you wish to continue with transaction? (y/n)";

        do{
            inputContinue = get_input(amount);
        }while(inputContinue);


    }

}

int ChequingAccount::get_input(double amount){
    string decision;

    cout << ">"; //cursor
    cin >> decision;

    if(decision.size() != 1){
        cout << "y or n only" << endl << endl;
        return 1;
    }

    switch(decision[0])
    {
    case 'n':
        return 0;
        break;

    case 'y':
        balance = balance - amount - 2.00;
        return 0;
        break;

    default:
        cout << "Unknown Command" << endl << endl;
    }
}
