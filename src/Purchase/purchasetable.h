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

	// @brief Creates a new instance of PurchaseTable
	PurchaseTable();

	// @brief Deletes PurchaseTable
	virtual ~PurchaseTable();

	/** @brief Retrieves purchases for all users by month
	 *
	 * @param year the year
	 * @param month the month
	 * @param account the account to retrieve for
	 * @param purchases the container for the purchases
	 */
	static long GetPurchasesByMonth(int const& year, int const& month,
			Account const& account, Purchases& purchases);

	/** @brief Make a purchase on an account
	 * \throws MAKE_PURCHASE_FAILURE
	 *
	 * @param account the account object to make the purchase on
	 * @param amount the amount of the purchase
	 */
	static long MakePurchase(Account const& account, int const& amount);

	/** @brief Imbue the purchase with info from the
	 * @param column_names the names of the columns
	 * @param row the row of data to imbue upon the purchase
	 * @param account the account object to associate with the purchase
	 * @param purchase the purchase object to imbue upon
	 */
	static long ImbuePurchase(std::vector<std::string> const& column_names,
			std::vector<std::string> row, Account const& account, Purchase& purchase);

};


#endif /* PURCHASETABLE_H_ */
