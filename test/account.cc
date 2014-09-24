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



	cout << user.sAccount.id << endl;

	EXPECT_NO_THROW(UserTable::DeleteUser("notauser"));

	Db::Db::Disconnect();

}

TEST(Account, SelectAll)
{
	Db::Db::Connect();

	User::User user1;
	User::User user2;
	User::User user3;
	User::User user4;
	User::User user5;
	User::User user6;
	User::User user7;

	EXPECT_NO_THROW(UserTable::CreateUser("notauser1", "notapassword", USER_PERMISSION_USER, user1));
	EXPECT_NO_THROW(UserTable::CreateUser("notauser2", "notapassword", USER_PERMISSION_USER, user2));
	EXPECT_NO_THROW(UserTable::CreateUser("notauser3", "notapassword", USER_PERMISSION_USER, user3));
	EXPECT_NO_THROW(UserTable::CreateUser("notauser4", "notapassword", USER_PERMISSION_USER, user4));
	EXPECT_NO_THROW(UserTable::CreateUser("notauser5", "notapassword", USER_PERMISSION_USER, user5));
	EXPECT_NO_THROW(UserTable::CreateUser("notauser6", "notapassword", USER_PERMISSION_USER, user6));
	EXPECT_NO_THROW(UserTable::CreateUser("notauser7", "notapassword", USER_PERMISSION_USER, user7));

	EXPECT_EQ(SUCCESS, AccountTable::CreateAccount(user1, SAVINGS_ACCOUNT));
	EXPECT_EQ(SUCCESS, AccountTable::CreateAccount(user2, SAVINGS_ACCOUNT));
	EXPECT_EQ(SUCCESS, AccountTable::CreateAccount(user3, SAVINGS_ACCOUNT));
	EXPECT_EQ(SUCCESS, AccountTable::CreateAccount(user4, SAVINGS_ACCOUNT));
	EXPECT_EQ(SUCCESS, AccountTable::CreateAccount(user5, SAVINGS_ACCOUNT));
	EXPECT_EQ(SUCCESS, AccountTable::CreateAccount(user6, SAVINGS_ACCOUNT));
	EXPECT_EQ(SUCCESS, AccountTable::CreateAccount(user7, SAVINGS_ACCOUNT));

	EXPECT_EQ(SUCCESS, AccountTable::CreateAccount(user1, CHEQUING_ACCOUNT));
	EXPECT_EQ(SUCCESS, AccountTable::CreateAccount(user2, CHEQUING_ACCOUNT));
	EXPECT_EQ(SUCCESS, AccountTable::CreateAccount(user3, CHEQUING_ACCOUNT));
	EXPECT_EQ(SUCCESS, AccountTable::CreateAccount(user4, CHEQUING_ACCOUNT));
	EXPECT_EQ(SUCCESS, AccountTable::CreateAccount(user5, CHEQUING_ACCOUNT));
	EXPECT_EQ(SUCCESS, AccountTable::CreateAccount(user6, CHEQUING_ACCOUNT));
	EXPECT_EQ(SUCCESS, AccountTable::CreateAccount(user7, CHEQUING_ACCOUNT));

	vector<User::User> users;

	UserTable::GetAllUsers(users);

	for(vector<User::User>::iterator it = users.begin(); it != users.end(); ++it)
	{
		cout << it->username << endl;
	}

	AccountTable::DeleteAccount(user1.sAccount);
	AccountTable::DeleteAccount(user2.sAccount);
	AccountTable::DeleteAccount(user3.sAccount);
	AccountTable::DeleteAccount(user4.sAccount);
	AccountTable::DeleteAccount(user5.sAccount);
	AccountTable::DeleteAccount(user6.sAccount);
	AccountTable::DeleteAccount(user7.sAccount);

	EXPECT_EQ(SUCCESS, UserTable::DeleteUser(user1.username));
	EXPECT_EQ(SUCCESS, UserTable::DeleteUser(user2.username));
	EXPECT_EQ(SUCCESS, UserTable::DeleteUser(user3.username));
	EXPECT_EQ(SUCCESS, UserTable::DeleteUser(user4.username));
	EXPECT_EQ(SUCCESS, UserTable::DeleteUser(user5.username));
	EXPECT_EQ(SUCCESS, UserTable::DeleteUser(user6.username));
	EXPECT_EQ(SUCCESS, UserTable::DeleteUser(user7.username));

	Db::Db::Disconnect();

}

