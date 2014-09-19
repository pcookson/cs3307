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

namespace User {

class UserTable {
public:
	UserTable();
	virtual ~UserTable();


	static Db::Db Db;
	static User Authenticate(std::string username, std::string password);
};

} /* namespace User */

#endif /* USERTABLE_H_ */
