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
#include "../src/Purchase/purchase.h"
#include "../src/Purchase/purchasetable.h"

using namespace User;

TEST(Account, Purchase)
{
	Db::Db::Connect();

	User::User user;

	EXPECT_NO_THROW(UserTable::CreateUser("notauser", "notapassword", USER_PERMISSION_USER, true, user));

	EXPECT_EQ(SUCCESS, AccountTable::CreateAccount(user, SAVINGS_ACCOUNT));

	EXPECT_EQ(SUCCESS, AccountTable::Deposit(user.sAccount, 425.2));
	EXPECT_EQ((double)425.2, user.sAccount.balance);

	PurchaseTable::MakePurchase(user.sAccount, 100);
	PurchaseTable::MakePurchase(user.sAccount, 100);
	PurchaseTable::MakePurchase(user.sAccount, 100);
	PurchaseTable::MakePurchase(user.sAccount, 100);

	Purchases purchases;
	PurchaseTable::GetPurchasesByMonth(2014, 11, user.sAccount, purchases);

	for (Purchases::iterator pit = purchases.begin(); pit != purchases.end(); ++pit)
	{
		cout << "Amount: " << pit->amount << "  Date: " << pit->date_time << endl;
	}

	AccountTable::DeleteAccount(user.sAccount);
	UserTable::DeleteUser("notauser");
}

TEST(Account, Freeze)
{
	Db::Db::Connect();

	User::User user;

	EXPECT_NO_THROW(UserTable::CreateUser("notauser", "notapassword", USER_PERMISSION_USER, true, user));

	EXPECT_EQ(SUCCESS, AccountTable::CreateAccount(user, SAVINGS_ACCOUNT));

	AccountTable::FreezeAccount(user.sAccount);

	Account vAccount;
	AccountTable::GetAccount(vAccount, user.sAccount.id);

	EXPECT_TRUE(user.sAccount.frozen);
	EXPECT_TRUE(vAccount.frozen);

	AccountTable::UnFreezeAccount(user.sAccount);
	AccountTable::GetAccount(vAccount, user.sAccount.id);

	EXPECT_FALSE(user.sAccount.frozen);
	EXPECT_FALSE(vAccount.frozen);

	AccountTable::DeleteAccount(user.sAccount);

	EXPECT_NO_THROW(UserTable::DeleteUser("notauser"));

	Db::Db::Disconnect();
}

TEST(Account, Create)
{
	Db::Db::Connect();

	User::User user;

	EXPECT_NO_THROW(UserTable::CreateUser("notauser", "notapassword", USER_PERMISSION_USER, true, user));

	EXPECT_EQ(SUCCESS, AccountTable::CreateAccount(user, SAVINGS_ACCOUNT));
	AccountTable::DeleteAccount(user.sAccount);

	EXPECT_NO_THROW(UserTable::DeleteUser("notauser"));

	Db::Db::Disconnect();

}

TEST(Account, DepositWithdrawl)
{
	Db::Db::Connect();

	User::User user;

	EXPECT_NO_THROW(UserTable::CreateUser("notauser", "notapassword", USER_PERMISSION_USER, true, user));

	EXPECT_EQ(SUCCESS, AccountTable::CreateAccount(user, SAVINGS_ACCOUNT));

	EXPECT_EQ(SUCCESS, AccountTable::Deposit(user.sAccount, 425.2));
	EXPECT_EQ((double)425.2, user.sAccount.balance);
	EXPECT_EQ(SUCCESS, AccountTable::Withdraw(user.sAccount, 56.42));
	EXPECT_EQ((double)368.78, user.sAccount.balance);

	AccountTable::DeleteAccount(user.sAccount);
	UserTable::DeleteUser("notauser");
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

	EXPECT_NO_THROW(UserTable::CreateUser("notauser1", "notapassword", USER_PERMISSION_USER, true, user1));
	EXPECT_NO_THROW(UserTable::CreateUser("notauser2", "notapassword", USER_PERMISSION_USER, true, user2));
	EXPECT_NO_THROW(UserTable::CreateUser("notauser3", "notapassword", USER_PERMISSION_USER, true, user3));
	EXPECT_NO_THROW(UserTable::CreateUser("notauser4", "notapassword", USER_PERMISSION_USER, true, user4));
	EXPECT_NO_THROW(UserTable::CreateUser("notauser5", "notapassword", USER_PERMISSION_USER, true, user5));
	EXPECT_NO_THROW(UserTable::CreateUser("notauser6", "notapassword", USER_PERMISSION_USER, true, user6));
	EXPECT_NO_THROW(UserTable::CreateUser("notauser7", "notapassword", USER_PERMISSION_USER, true, user7));

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

