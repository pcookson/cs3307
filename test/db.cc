#include "../src/Db/db.h"
#include <gtest/gtest.h>
#include "../src/User/user.h"
#include "../src/User/usertable.h"
#include <mysql/mysql.h>
#include <iostream>
#include <string>
#include "../src/Utilities.h"
#include "../src/config.h"

using namespace Db;
using namespace std;

TEST(DbTest, CreateUser)
{
	Db::Db::Connect();

	User::User user;

	EXPECT_NO_THROW(User::UserTable::CreateUser("notauser", "notapassword", USER_PERMISSION_USER, false, user));
	EXPECT_NO_THROW(User::UserTable::DeleteUser("notauser"));

	Db::Db::Disconnect();
}

TEST(DbTest, DeleteNonExistentUser)
{
	Db::Db::Connect();
	int status;
	try {
		status = User::UserTable::DeleteUser("notauser");
	}
	catch(int e)
	{
		status = e;
	}

	EXPECT_EQ(DELETE_USER_FAILURE, status);
	Db::Db::Disconnect();
}

TEST(DbTest, Authenticate)
{
	Db::Db::Connect();
	User::User user;

	EXPECT_NO_THROW(User::UserTable::CreateUser("notauser", "notapassword", USER_PERMISSION_USER, false, user));
	EXPECT_NO_THROW(User::UserTable::Authenticate("notauser", "notapassword", user));
	EXPECT_NO_THROW(User::UserTable::DeleteUser("notauser"));

	EXPECT_GT(user.id, 0);
	Db::Db::Disconnect();
}

TEST(DbTest, AuthenticateFail)
{
	Db::Db::Connect();

	User::User user;

	EXPECT_NO_THROW(User::UserTable::CreateUser("notauser", "notapassword", USER_PERMISSION_USER, false, user));

	try {
		User::UserTable::Authenticate("notauser", "notacorrectpassword", user);
	}
	catch(int e)
	{
		EXPECT_EQ(AUTHENTICATION_FAILURE, e);
	}

	EXPECT_NO_THROW(User::UserTable::DeleteUser("notauser"));

	Db::Db::Disconnect();
}

