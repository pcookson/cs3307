/*
 * accounttable.h
 *
 *  Created on: Sep 23, 2014
 *      Author: james
 */

#ifndef ACCOUNTTABLE_H_
#define ACCOUNTTABLE_H_

#define CREATE_ACCOUNT_FAILURE 0X1
#define CREATE_ACCOUNT_FAILURE_INVALID_USER 0X2
#define CREATE_ACCOUNT_FAILURE_EXISTS 0X4

#define DELETE_ACCOUNT_FAILURE 0X4
#define INVALID_ACCOUNT_ID 0X8
#define WITHDRAW_ERROR 0X1
#define DEPOSIT_ERROR 0X1


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
