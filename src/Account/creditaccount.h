#ifndef CREDIT_ACCOUNT_H
#define CREDIT_ACCOUNT_H

#include "account.h"

using namespace std;

class CreditAccount: public Account{

public:

	CreditAccount(double balance): Account(balance){
		CreditAccount::balance = balance;
	}


	CreditAccount(): Account(){
		CreditAccount::balance = 0;
	}

	/** @brief virtual method implementation of withdrawl
	*
	* @param amount of money to put onto credit card
	* @return int
	*/
	virtual int withdrawl(double amount);

    /** @brief performs end of month balances of credit account.
    *
    *
    */
    void endOfMonth();
};
#endif //CREDIT_ACCOUNT_H




