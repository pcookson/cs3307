/*
 * accounttable.cpp
 *
 *  Created on: Sep 23, 2014
 *      Author: james
 */

#include "../User/user.h"
#include "account.h"
#include "chequingaccount.h"
#include "savingsaccount.h"
#include "accounttable.h"
#include "../Db/db.h"
#include "../User/usertable.h"
#include "../Utilities.h"
#include <typeinfo>
#include <stdlib.h>

using namespace User;

AccountTable::AccountTable() {
}

AccountTable::~AccountTable() {
}

long AccountTable::ImbueAccount(std::vector<std::string> const& column_names,
		std::vector<std::string> row, Account& account) {
	//Load the properties needed into the account object
	account.id = atoi(
			Db::Db::GetElementByName("id", column_names, row).c_str());
	account.balance = atoi(
			Db::Db::GetElementByName("balance", column_names, row).c_str());

	return SUCCESS;
}

long AccountTable::Withdraw(Account& account, double amount) {
	double new_balance = account.balance - amount;
	int rows_affected;

	string new_balance_string = Utilities::double_to_string(new_balance);

	Db::Db::ExecuteNonQuery(
			"UPDATE account SET balance=" + new_balance_string + " WHERE id="
			+ Utilities::long_to_string(account.id), rows_affected);

	if (rows_affected != 1)
		throw WITHDRAW_ERROR;

	account.balance = new_balance;
	return SUCCESS;
}

long AccountTable::Deposit(Account& account, double amount) {
	double new_balance = account.balance + amount;
	int rows_affected;

	string new_balance_string = Utilities::double_to_string(new_balance);

	Db::Db::ExecuteNonQuery(
			"UPDATE account SET balance=" + new_balance_string + " WHERE id="
			+ Utilities::long_to_string(account.id), rows_affected);

	if (rows_affected != 1)
		throw WITHDRAW_ERROR;

	account.balance = new_balance;

	return SUCCESS;
}

long AccountTable::GetAccount(Account& account, int& id) {
	vector<string> values;
	values.push_back(Utilities::long_to_string(id));
	Db::db_rows rows;

	Db::Db::Select(
			Db::Db::ParamertizedQuery("SELECT * FROM account WHERE id=?",
					values), rows);

	if (rows.rows.size() == 0)
		throw INVALID_ACCOUNT_ID;

	ImbueAccount(rows.column_names, rows.rows[0], account);

	return SUCCESS;
}

long AccountTable::DeleteAccount(Account& account) {

	vector<string> values;
	values.push_back(Utilities::long_to_string(account.id));

	int rows_affected = 0;

	Db::Db::ExecuteNonQuery(
			Db::Db::ParamertizedQuery("DELETE FROM account WHERE id=?", values),
			rows_affected);

	if (rows_affected != 1)
		throw DELETE_ACCOUNT_FAILURE;

	return SUCCESS;
}

long AccountTable::CreateAccount(User::User& user, long const& account_type) {

	if (!user.id)
		throw USER_NOT_EXIST;

	if ((account_type == SAVINGS_ACCOUNT && user.sAccount.id != 0)
			|| (account_type == CHEQUING_ACCOUNT && user.cAccount.id != 0)
			||(account_type == CREDIT_ACCOUNT && user.credAccount.id !=0))
		throw CREATE_ACCOUNT_FAILURE_EXISTS;

	vector<string> values;
	values.push_back(Utilities::long_to_string(user.id));
	values.push_back(Utilities::long_to_string(account_type));

	int id;

	Db::Db::Insert(
			Db::Db::ParamertizedQuery(
					"INSERT INTO account(user_id,account_type) VALUES (?,?)",
					values), id);

	if (id < 1)
		throw CREATE_ACCOUNT_FAILURE;

	if (account_type == SAVINGS_ACCOUNT) {
		GetAccount(user.sAccount, id);
	} else if (account_type == CHEQUING_ACCOUNT) {
		GetAccount(user.cAccount, id);
	}else if (account_type == CREDIT_ACCOUNT){
		GetAccount(user.credAccount, id);
	}

	return SUCCESS;
}
