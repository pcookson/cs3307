#include "savingsaccount.h"

using namespace std;

int SavingsAccount::Withdraw(double amount){
    if(balance < amount){
        return 1;
    }
    balance = balance - amount;
    return 0;

}
