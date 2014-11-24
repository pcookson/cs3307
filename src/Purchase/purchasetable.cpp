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
#include "purchasetable.h"
#include "../Db/db.h"
#include "../User/usertable.h"
#include "../Utilities.h"
#include <typeinfo>
#include <stdlib.h>
#include "purchase.h"

using namespace User;

AccountTable::AccountTable() {
}

AccountTable::~AccountTable() {
}

long PurchaseTable::MakePurchase(Account::Account const& account,
		int const& amount) {
	if (!account.id)
		throw ACCOUNT_NOT_EXIST;

	vector<string> values;
	values.push_back(Utilities::int_to_string(amount));
	values.push_back(Utilities::int_to_string(account.id));

	int id;

	Db::Db::Insert(
			Db::Db::ParamertizedQuery(
					"INSERT INTO purchase(amount,account_id,date_time) VALUES (?,?,NOW())",
					values), id);

	if (id < 1)
		throw MAKE_PURCHASE_FAILURE;

	return SUCCESS;
}

long PurchaseTable::ImbuePurchase(vector<string> const& column_names,
		vector<string> row, Account::Account const& account,
		Purchase& purchase) {
	//Load the properties needed into the account object
	purchase.id = atoi(
			Db::Db::GetElementByName("id", column_names, row).c_str());
	purchase.amount = atoi(
			Db::Db::GetElementByName("balance", column_names, row).c_str());
	purchase.date_time = Db::Db::GetElementByName("date_time", column_names,
			row).c_str();
	purchase.account = account;

	return SUCCESS;
}

long PurchaseTable::GetPurchasesByMonth(int const& year,
		int const& month, Account::Account const& account,
		Purchases& purchases) {
	purchases.clear();
	Db::db_rows& rows;

	Db::Db::Select(
			"SELECT * FROM purchase WHERE date_time >= "
					+ Utilities::int_to_string(year) + "-"
					+ (month > 9 ? "0" : "") + Utilities::int_to_string(month)
					+ "-01 00:00:00", rows);

	for (vector<vector<string> >::iterator rit = rows.rows.begin();
			rit != rows.rows.end(); ++rit) {
		Purchase purchase;

		ImbuePurchase(rows.column_names, *rit, account, purchase);


		purchases.push_back(purchase);
	}

	return SUCCESS;
}
