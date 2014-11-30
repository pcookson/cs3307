/*
 * accounttable.cpp
 *
 *  Created on: Sep 23, 2014
 *      Author: james
 */

#include "../User/user.h"
#include "paymenttable.h"
#include "../Db/db.h"
#include "../Utilities.h"
#include "payment.h"
#include "../Account/account.h"
#include <vector>
#include <string>

using namespace User;
using namespace std;

PaymentTable::PaymentTable() {
}

PaymentTable::~PaymentTable() {
}

long PaymentTable::MakePayment(Account const& account,
		int const& amount) {
	if (!account.id)
		throw ACCOUNT_NOT_EXIST;

	vector<string> values;
	values.push_back(Utilities::int_to_string(amount));
	values.push_back(Utilities::int_to_string(account.id));

	int id;

	Db::Db::Insert(
			Db::Db::ParamertizedQuery(
					"INSERT INTO payment(amount,account_id,date_time) VALUES (?,?,NOW())",
					values), id);

	if (id < 1)
		throw MAKE_PURCHASE_FAILURE;

	return SUCCESS;
}

long PaymentTable::ImbuePayment(vector<string> const& column_names,
		vector<string> row, Account const& account,
		Payment& payment) {
	//Load the properties needed into the account object
	payment.id = atoi(
			Db::Db::GetElementByName("id", column_names, row).c_str());
	payment.amount = atoi(
			Db::Db::GetElementByName("amount", column_names, row).c_str());
	payment.date_time = Db::Db::GetElementByName("date_time", column_names,
			row).c_str();
	payment.account = account;

	return SUCCESS;
}

long PaymentTable::GetPaymentsByMonth(int const& year,
		int const& month, Account const& account,
		Payments& payments) {
	payments.clear();
	Db::db_rows rows;

	Db::Db::Select(
			"SELECT * FROM payment WHERE date_time >= '"
					+ Utilities::int_to_string(year) + "-"
					+ (month > 9 ? "0" : "") + Utilities::int_to_string(month)
					+ "-01 00:00:00'", rows);

	for (vector<vector<string> >::iterator rit = rows.rows.begin();
			rit != rows.rows.end(); ++rit) {
		Payment payment;

		ImbuePayment(rows.column_names, *rit, account, payment);


		payments.push_back(payment);
	}

	return SUCCESS;
}
