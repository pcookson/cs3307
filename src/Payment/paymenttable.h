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
	PaymentTable();
	virtual ~PaymentTable();

	static long GetPaymentsByMonth(int const& year, int const& month,
			Account const& account, Payments& payments);
	static long MakePayment(Account const& account, int const& amount);
	static long ImbuePayment(std::vector<std::string> const& column_names,
			std::vector<std::string> row, Account const& account, Payment& payment);

};


#endif /* PAYMENTTABLE_H_ */
