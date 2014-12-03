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

/**
 * Container for the information of a single payment
 */
class Payment {
public:
	// @brief Creates a new Payment object
	Payment();

	// @brief Deletes a Payment object
	virtual ~Payment();

	// the date and time transaction occurred
	std::string date_time;

	// the amount of the payment
	int amount;

	// the id of the payment
	std::string id;

	// the account the payment was made on
	Account account;

	// the user that owns the account the payment was made on
	User::User user;
};

// @brief A collection container for multiple payments
typedef std::vector<Payment> Payments;

#endif /* PAYMENT_H_ */
