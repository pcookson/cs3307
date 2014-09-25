#ifndef CHEQUINGACCOUNT_H
#define CHEQUINGACCOUNT_H

#include "account.h"

using namespace std;

class ChequingAccount: public Account {

public:

	/** @brief constructor that sets a starting balance
	 *
	 * @param balance
	 */
	ChequingAccount(double balance) :
			Account(balance) {
		ChequingAccount::balance = balance;
	}

	/** @brief default constructor. Balance is 0
	 *
	 */
	ChequingAccount() :
			Account() {
		ChequingAccount::balance = 0;
	}

	/** @brief virtual method implementation of withdrawl
	 *
	 * @param amount to withdraw
	 * @return int
	 */
	virtual int withdrawl(double amount);

private:
	int get_input(double amount);

};

#endif // CHEQUINGACCOUNT_H
