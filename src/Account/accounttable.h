/*
 * accounttable.h
 *
 *  Created on: Sep 23, 2014
 *      Author: james
 */

#ifndef ACCOUNTTABLE_H_
#define ACCOUNTTABLE_H_

#define CREATE_ACCOUNT_FAILURE 0X1
#define CREATE_ACOCUNT_FAILURE_INVALID_USER 0X2




class AccountTable {
public:
	AccountTable();
	virtual ~AccountTable();

	static long CreateAccount(User& user, Account& account);
};


#endif /* ACCOUNTTABLE_H_ */
