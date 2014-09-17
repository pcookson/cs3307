#include "savingsaccount.h"
#include <iostream>

using namespace std;



long SavingsAccount::withdrawl(double amount){

    HtmlLogger::info("Attempting to withdraw money from savings");
    if(balance < amount){
        throw INSUFFICIENT_FUNDS;
    }else{
        HtmlLogger::info("Successfully withdrew money from saving account");
        balance = balance - amount;
        cout << "Current balance: " << balance << endl;
    }



}
