/*
 * purchase.h
 *
 *  Created on: Nov 23, 2014
 *      Author: james
 */

#ifndef PURCHASE_H_
#define PURCHASE_H_

#include <string>
#include "../Account/account.h"
#include "../User/user.h"
#include "../Db/db.h"
#include "../User/user.h"

/**
 * Container for the information of a single purchase
 */
class Purchase {
public:
	// @brief Creates a new Purchase object
	Purchase();

	// @brief Deletes a Purchase object
	virtual ~Purchase();

	// the date and time transaction occurred
	std::string date_time;

	// the id of the purchase
	int amount;

	// the id of the purchase
	std::string id;

	// the account the purchase was made on
	Account account;

	// the user that owns the account the purchase was made on
	User::User user;
};

// @brief A collection container for multiple purchases
typedef std::vector<Purchase> Purchases;

#endif /* PURCHASE_H_ */
