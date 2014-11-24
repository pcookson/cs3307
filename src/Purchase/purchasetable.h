/*
 * accounttable.h
 *
 *  Created on: Sep 23, 2014
 *      Author: james
 */

#ifndef PURCHASETABLE_H_
#define PURCHASETABLE_H_

#include "../Db/db.h"
#include "../Account/account.h"
#include "purchase.h"
#include <stdlib.h>

class PurchaseTable {
public:
	PurchaseTable();
	virtual ~PurchaseTable();

	static long GetPurchasesByMonth(int const& year, int const& month,
			Account const& account, Purchases& purchases);
	static long MakePurchase(Account const& account, int const& amount);
	static long ImbuePurchase(std::vector<std::string> const& column_names,
			std::vector<std::string> row, Account const& account, Purchase& purchase);

};


#endif /* PURCHASETABLE_H_ */
