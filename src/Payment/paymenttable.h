/*
 * accounttable.h
 *
 *  Created on: Sep 23, 2014
 *      Author: james
 */

#ifndef PAYMENTTABLE_H_
#define PAYMENTTABLE_H_

#include "../Db/db.h"
#include "../Account/account.h"
#include "payment.h"
#include <stdlib.h>

class PaymentTable {
public:
	// @brief Creates a new instance of PaymentTable
	PaymentTable();

	// @brief Deletes PaymentTable
	virtual ~PaymentTable();

	/** @brief Retrieves payments for all users by month
	 *
	 * @param year the year
	 * @param month the month
	 * @param account the account to retrieve for
	 * @param payments the container for the payments
	 */
	static long GetPaymentsByMonth(int const& year, int const& month,
			Account const& account, Payments& payments);

	/** @brief Make a payment on an account
	 * \throws MAKE_PURCHASE_FAILURE
	 *
	 * @param account the account object to make the payment on
	 * @param amount the amount of the payment
	 */
	static long MakePayment(Account const& account, int const& amount);

	/** @brief Imbue the payment with info from the
	 * @param column_names the names of the columns
	 * @param row the row of data to imbue upon the payment
	 * @param account the account object to associate with the payment
	 * @param payment the payment object to imbue upon
	 */
	static long ImbuePayment(std::vector<std::string> const& column_names,
			std::vector<std::string> row, Account const& account, Payment& payment);

};


#endif /* PAYMENTTABLE_H_ */
