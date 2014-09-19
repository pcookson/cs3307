/*
 * usertable.cpp
 *
 *  Created on: Sep 18, 2014
 *      Author: james
 */

#include "usertable.h"
#include "user.h"
#include <iostream>
#include <vector>





using namespace std;

namespace User {

Db::Db UserTable::Db;

UserTable::UserTable() {
	// TODO Auto-generated constructor stub

}

UserTable::~UserTable() {
	// TODO Auto-generated destructor stub
}

User UserTable::Authenticate(string username, string password) {
	vector<string> values;
	User user;

	//values.push_back(username);
	//values.push_back(password);

	UserTable::Db.Select("SELECT * FROM user WHERE username='bluebaron'", values);

	return user;
}

} /* namespace User */
