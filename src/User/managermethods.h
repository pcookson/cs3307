#ifndef MANAGERMETHODS_H
#define MANAGERMETHODS_H

#include "../User/user.h"
#include <iostream>
#include "../Account/chequingaccount.h"
#include "../Account/savingsaccount.h"
#include "usermethods.h"
#include "../Account/fundmovementvalidation.h"
#include "usertable.h"
#include "../Account/accounttable.h"
#include <stdlib.h>

class ManagerMethods {
public:
	ManagerMethods();

	/** @brief gets user details
	 *
	 */
	static void getUserDetails();

	/** @brief gets details for all users
	 *
	 */
	static void getAllUserDetails();

	/** @brief closes an account
	 *
	 */
	static void closeAccount();

	/** @brief opens an account
	 *
	 */
	static void openAccount();

	/** @brief creates a user
	 *
	 */
	static void createUser();

	/** @brief deletes a user
	 *
	 */
	static void deleteUser();

	/** @brief allows manager user to select a list of commands
	 *
	 * @param user
	 */
	static void managerCommandSelect(User::User &user);

	/** @brief a list of commands for the manager
	 *
	 */
	static void managerCommandList();

private:
	static void pressEnter();

	static void clearScreen();
};

#endif // MANAGERMETHODS_H
