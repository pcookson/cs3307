#ifndef SAVINGSACCOUNT_H
#define SAVINGSACCOUNT_H

#include "account.h"

using namespace std;

class SavingsAccount: public Account {
public:
	/** @brief constructor with starting balance
	 *
	 * @param balance
	 */
	SavingsAccount(double balance) :
			Account(balance) {
		SavingsAccount::balance = balance;
	}

	/** @brief default constructor. Sets balance to0
	 *
	 */
	SavingsAccount() :
			Account() {
		SavingsAccount::balance = 0;
	}

	/** @brief virtual method implementation.
	 *
	 * @param amount
	 * @return
	 */
	virtual int withdrawl(double amount);

private:

};

#endif // SAVINGSACCOUNT_H
