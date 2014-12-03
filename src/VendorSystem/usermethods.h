/*
 * usermethods.h
 *
 *  Created on: Nov 25, 2014
 *      Author: patrick
 */

#ifndef USERMETHODS_H_
#define USERMETHODS_H_

#include "../User/user.h"

class usermethods {
public:
	usermethods();
	virtual ~usermethods();

	/** @brief presents user with methods to run
	 *
	 * @param user object
	 */
	static void userCommandSelect(User::User &user);

private:
	/** @brief processes the purchase
	 *
	 * @param user
	 * @param amount
	 */
	static void processPurchase(User::User &user, int amount);

	/** @brief gives user random number to purchase
	 *
	 * @param user
	 */
	static void makePurchase(User::User &user);

	/** @brief holds list of commands
	 *
	 */
	static void userCommandList();


};

#endif /* USERMETHODS_H_ */
