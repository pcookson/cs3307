#ifndef CREDIT_ACCOUNT_H
#define CREDIT_ACCOUNT_H

#include "account.h";

using namespace std;

class CreditAccount: public Account{

public:

	CreditAccount(double balance): Account(balance){
		CreditAccount::balance = balance;
	}


	CreditAccount(): Account(){
		CreditAccount::balance = 0;
	}

    /** @brief performs end of month balances of credit account.
    *
    *
    */
    void endOfMonth();

	virtual int withdrawl(double balance);
};




