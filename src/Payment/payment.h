/*
 * payment.h
 *
 *  Created on: Nov 23, 2014
 *      Author: james
 */

#ifndef PAYMENT_H_
#define PAYMENT_H_

#include <string>
#include "../Account/account.h"
#include "../User/user.h"
#include "../Db/db.h"
#include "../User/user.h"


class Payment {
public:
	Payment();
	virtual ~Payment();

	std::string date_time;

	// An integer of the amount including cents with no decimal places.  Divide by 100 for human readability.
	int amount;

	std::string id;

	Account account;

	User::User user;


};

typedef std::vector<Payment> Payments;

#endif /* PAYMENT_H_ */
