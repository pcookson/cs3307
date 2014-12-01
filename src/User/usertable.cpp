/*
 * usertable.cpp
 *
 *  Created on: Sep 18, 2014
 *      Author: james
 */

#include "usertable.h"
#include "user.h"
#include "../Db/db.h"
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <stdlib.h>
#include "../Utilities.h"
#include "../Account/accounttable.h"

using namespace std;
using namespace Db;

namespace User {

UserTable::UserTable() {
}

UserTable::~UserTable() {
}

long UserTable::ImbueUser(std::vector<std::string> const& column_names,
		std::vector<std::string> row, User& user) {
	//Load the properties needed into the user object
	user.username = Db::Db::GetElementByName("username", column_names, row);
	user.permissions = atol(
			Db::Db::GetElementByName("permissions", column_names, row).c_str());
	user.fullPayment = Db::Db::GetElementByName("full_payment", column_names, row).at(0) == '1';
	user.frozen = Db::Db::GetElementByName("frozen", column_names, row).at(0) == '1';
	user.creditLimit = atoi(Db::Db::GetElementByName("credit_limit", column_names, row).c_str());
	user.id = atoi(Db::Db::GetElementByName("id", column_names, row).c_str());

	if (user.id < 0)
		throw USER_NOT_EXIST;

	vector<string> values;
	db_rows rows;

	values.push_back(Utilities::long_to_string(user.id));

	Db::Db::Select(
			Db::Db::ParamertizedQuery("SELECT * FROM account WHERE user_id=?",
					values), rows);

	for (vector<vector<string> >::iterator it = rows.rows.begin(); it != rows.rows.end(); ++it) {
		long account_type = atol(
				Db::Db::GetElementByName("account_type", rows.column_names, *it).c_str());

		if (account_type == CHEQUING_ACCOUNT) {
			AccountTable::ImbueAccount(rows.column_names, *it, user.cAccount);
		} else if (account_type == SAVINGS_ACCOUNT) {
			AccountTable::ImbueAccount(rows.column_names, *it, user.sAccount);
		}else if (account_type == CREDIT_ACCOUNT){
			AccountTable::ImbueAccount(rows.column_names, *it, user.credAccount);
		}
	}

	return SUCCESS;
}

long UserTable::GetAllUsers(vector<User>& users) {
	users.clear();
	db_rows rows;

	Db::Db::Select("SELECT * FROM user", rows);

	for (vector<vector<string> >::iterator it = rows.rows.begin(); it != rows.rows.end(); ++it) {
		User user;

		ImbueUser(rows.column_names, *it, user);
		users.push_back(user);
	}

	return SUCCESS;
}

long UserTable::CreateUser(string const& username, string const& password,
		long permissions, bool fullPayment, User& user) {
	if (username.empty() || password.empty())
		throw CREATE_USER_FAILURE;

	vector<string> values;

	values.push_back(username);
	values.push_back(password);
	values.push_back(Utilities::long_to_string(permissions));
	values.push_back(fullPayment ? "1" : "0");

	int id;
	long err;
	db_rows rows;

	//Check to see if the user exists in the database already
	string query = Db::Db::ParamertizedQuery(
			"SELECT * FROM user WHERE username=?", values);

	try {
		err = Db::Db::Select(query, rows);

		//At least one row should've been returned to represent the user
		if (rows.rows.size() > 0)
			throw CREATE_USER_FAILURE_USER_EXISTS;
	} catch (int) {
		throw CREATE_USER_FAILURE;
	}

	query =
			Db::Db::ParamertizedQuery(
					"INSERT INTO user(username,password,permissions,full_payment) VALUES (?,password(?),?,?)",
					values);

	try {
		err = Db::Db::Insert(query, id);
	} catch (int) {
		throw CREATE_USER_FAILURE;
	}

	//Make sure there was no error and that an ID was returned
	if (id < 1 || err != SUCCESS)
		throw CREATE_USER_FAILURE;

	try {
		//Get the new user object
		err = Authenticate(username, password, user);
	} catch (int) {
		throw CREATE_USER_FAILURE;
	}

	if (err != SUCCESS)
		throw CREATE_USER_FAILURE;

	return SUCCESS;
}

long UserTable::GetUser(const std::string &username, User& user) {
	db_rows rows;

	vector<string> values;
	values.reserve(2);

	values.push_back(username);

	//Authentication is successful if at least one row is returned by selecting
	//a user by username and password
	Db::Db::Select(
			Db::Db::ParamertizedQuery("SELECT * FROM user WHERE username=?",
					values), rows);

	//Load the User object
	ImbueUser(rows.column_names, rows.rows[0], user);

	return SUCCESS;
}

long UserTable::Authenticate(std::string const& username,
		std::string const& password, User& user) {
	db_rows rows;

	vector<string> values;
	values.reserve(2);

	values.push_back(username);
	values.push_back(password);

	//Authentication is successful if at least one row is returned by selecting
	//a user by username and password
	Db::Db::Select(
			Db::Db::ParamertizedQuery(
					"SELECT * FROM user WHERE username=? AND password=password(?)",
					values), rows);

	if (rows.rows.size() == 0)
		throw AUTHENTICATION_FAILURE;

	//Load the User object
	ImbueUser(rows.column_names, rows.rows[0], user);

	return SUCCESS;
}

long UserTable::DeleteUser(string const& username) {
	vector<string> values;
	int err, rows_affected;
	values.push_back(username);

	try {

		string query = Db::Db::ParamertizedQuery(
				"DELETE FROM account WHERE user_id=?", values);

		//Exactly one row should be affected or failure
		err = Db::Db::ExecuteNonQuery(query, rows_affected);
		if (err != SUCCESS)
			throw DELETE_USER_FAILURE;

		query = Db::Db::ParamertizedQuery("DELETE FROM user WHERE username=?", values);
		err = Db::Db::ExecuteNonQuery(query, rows_affected);

		if (rows_affected != 1 || err != SUCCESS)
			throw DELETE_USER_FAILURE;


	} catch (int) {
		throw DELETE_USER_FAILURE;
	}

	return SUCCESS;
}


long UserTable::UnFreezeCredit(User& user)
{
	int rows_affected;
	Db::Db::ExecuteNonQuery("UPDATE user SET frozen=0 WHERE id=" + Utilities::long_to_string(user.id),
			rows_affected);

	if (rows_affected != 1)
		throw FREEZE_ERROR;

	user.frozen = false;

	return SUCCESS;
}

long UserTable::FreezeCredit(User& user)
{
	int rows_affected;
	Db::Db::ExecuteNonQuery("UPDATE user SET frozen=1 WHERE id=" + Utilities::long_to_string(user.id),
			rows_affected);

	if (rows_affected != 1)
		throw FREEZE_ERROR;

	user.frozen = true;

	return SUCCESS;
}

long UserTable::SetCreditLimit(User& user, int const& credit_limit)
{
	int rows_affected;

	Db::Db::ExecuteNonQuery("UPDATE user SET credit_limit=" + Utilities::int_to_string(credit_limit) +
			" WHERE id=" + Utilities::long_to_string(user.id),
			rows_affected);

	if (rows_affected != 1)
		throw FREEZE_ERROR;

	user.creditLimit = credit_limit;

	return SUCCESS;
}

} /* namespace User */
