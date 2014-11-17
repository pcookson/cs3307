#ifndef CREDIT_ACCOUNT.H
#define CREDIT_ACCOUNT.H

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

	virtual int withdrawl(double balance);
};





