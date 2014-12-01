/*
 * accounttable.h
 *
 *  Created on: Sep 23, 2014
 *      Author: james
 */

#ifndef ACCOUNTTABLE_H_
#define ACCOUNTTABLE_H_

#include "../error.h"
#include "../User/user.h"
#include "account.h"
#include <vector>
#include <stdlib.h>

class AccountTable {
public:
	AccountTable();
	virtual ~AccountTable();

	/** @brief Creates a savings or chequing account for a user
	 *
	 * @param user the user for whom to open the account
	 * @param account out parameter for the account
	 */
	static long CreateAccount(User::User& user, long const& account_type);

	/** @brief Subtracts an amount from the account balance
	 *
	 * @param account
	 * @param amount
	 */
    static long Withdraw(Account& account, double amount);

    static long Deposit(Account& account, double amount);

	static long GetAccount(Account& account, int& id);

	static long FreezeAccount(Account& account);

	static long UnFreezeAccount(Account& account);

	/** @brief Fills a the fields of an Account object from a row representing the account
	 *
	 * @param column_names a list of the column names, ordered respectively, for the rows container
	 * @param row a row containing the account fields selected from the database
	 * @param account an out parameter to represent the user
	 */
    static long ImbueAccount(std::vector<std::string> const& column_names, std::vector<std::string> row, Account& account);

    /** @brief Deletes an account from the database
     *
     * @param account the account to delete
     */
    static long DeleteAccount(Account& account);
};


#endif /* ACCOUNTTABLE_H_ */
