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


class Purchase {
public:
	Purchase();
	virtual ~Purchase();

	std::string date_time;

	// An integer of the amount including cents with no decimal places.  Divide by 100 for human readability.
	int amount;

	std::string id;

	Account account;

	User::User user;


};

typedef std::vector<Purchase> Purchases;

#endif /* PURCHASE_H_ */
