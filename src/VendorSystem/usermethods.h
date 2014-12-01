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

	static void userCommandSelect(User::User &user);

private:
	static void processPurchase(User::User &user, int amount);

	static void makePurchase(User::User &user);

	static void userCommandList();


};

#endif /* USERMETHODS_H_ */
