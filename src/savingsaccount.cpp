#include "savingsaccount.h"
#include <iostream>

using namespace std;



int SavingsAccount::withdrawl(double amount){

    if(balance < amount){
        throw INSUFFICIENT_FUNDS;
    }else{

        balance = balance - amount;
        return WITHDRAW_SUCCESSFUL;
    }



}
