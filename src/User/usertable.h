/*
 * usertable.h
 *
 *  Created on: Sep 18, 2014
 *      Author: james
 */

#ifndef USERTABLE_H_
#define USERTABLE_H_

#include <iostream>
#include "user.h"
#include "../Db/db.h"
#include "../error.h"

namespace User {

/** @brief A list of static methods that access to the database for the User class */
class UserTable {
public:
	UserTable();
	virtual ~UserTable();


	/** @brief Compares a users credentials against the database and returns a User object if successful and throws an error otherwise.
	 *
	 * \throws int AUTHENTICATION_FAILURE
	 * @param username the username of the user to authenticate
	 * @param password the password of the user to authenticate
	 * @param user an out parameter to represent the user
	 */
	static long Authenticate(std::string const& username, std::string const& password, User& user);

	/** @brief Fills a the fields of a User object from a row representing the user
	 *
	 * @param column_names a list of the column names, ordered respectively, for the rows container
	 * @param row a row containing the user fields selected from the database
	 * @param user an out parameter to represent the user
	 */
    static long ImbueUser(std::vector<std::string> const& column_names, std::vector<std::string> row, User& user);

    /** @brief Retrieves all users in the database for the admin
     *
     * @param users an out param for the users in the database
     */
    static long GetAllUsers(std::vector<User>& users);

    /** @brief Retrieves a single user's information by username
     *
     * @param username the username of the user to retrieve
     * @param user the out param for the user
     */
    static long GetUser(std::string const& username, User& user);

    /** @brief Creates a user and adds it to the database
     *
     * \throws int CREATE_USER_FAILURE or CREATE_USER_FAILURE_USER_EXISTS
     * @param username the user username
     * @param password the user password
     * @param permissions a bitwise value of the permissions based on the bit joining of permission constants
     * @param user an out parameter to represent the user
     */
    static long CreateUser(std::string const& username, std::string const& password, long permissions,
    		bool fullPayment, User& user);

    /** @brief Deletes a user from the database
     *
     * \throws int DELETE_USER_FAILURE
     * @param username the user username
     */
    static long DeleteUser(std::string const& username);

    static long FreezeCredit(User& user);


    static long UnFreezeCredit(User& user);

    static long SetCreditLimit(User& user, int const& credit_limit);

};

} /* namespace User */

#endif /* USERTABLE_H_ */
