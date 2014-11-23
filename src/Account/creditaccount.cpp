#include "creditaccount.h"
#include <iostream>

using namespace std;

int CreditAccount::withdrawl(double amount){
	if(balance < amount){
	        throw INSUFFICIENT_FUNDS;
	}else{
			return WITHDRAW_SUCCESSFUL;
	}
}
