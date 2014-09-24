#include "../src/Db/db.h"
#include <gtest/gtest.h>
#include "../src/User/user.h"
#include "../src/User/usertable.h"
#include <mysql/mysql.h>
#include <iostream>
#include <string>
#include "../src/Utilities.h"
#include "../src/config.h"
#include "../src/Account/account.h"
#include "../src/Account/accounttable.h"

using namespace User;

TEST(Account, Create)
{
	Db::Db::Connect();

	User::User user;

	EXPECT_NO_THROW(UserTable::CreateUser("notauser", "notapassword", USER_PERMISSION_USER, user));

	EXPECT_EQ(SUCCESS, AccountTable::CreateAccount(user, SAVINGS_ACCOUNT));
	AccountTable::DeleteAccount(user.sAccount);

	EXPECT_NO_THROW(UserTable::DeleteUser("notauser"));

	Db::Db::Disconnect();

}
