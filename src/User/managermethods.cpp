#include "managermethods.h"
#include "../Utilities.h"
#include"../logger.h"
#include "../Account/fundmovementvalidation.h"
#include <vector>

using namespace std;

ManagerMethods::ManagerMethods()
{
}

void ManagerMethods::createUser(){
	string username;
	string password;
	string permissionString;
	long permissions;
	User::User user;

	cout << "Username: ";
	cin >> username;
	cout << endl;

	cout << "User password: ";
	cin >> password;
	cout << endl;

	cout << "User Permissions: " << endl;
	cout << "u - User" << endl;
	cout << "a - Manager" << endl;
	cout << "j - Maintenance" << endl;
	cout << ">";
	cin >> permissionString;
	cout << endl;

	switch(permissionString[0]){
	case 'u':
		permissions = USER_PERMISSION_USER;
		break;
	case 'a':
		permissions = USER_PERMISSION_ADMIN;
		break;
	case 'j':
		permissions = USER_PERMISSION_MAINTENANCE;
		break;
	default:
		cout << "Unknown command";
	}

	Db::Db::Connect();
	try{
		User::UserTable::CreateUser(username, password, permissions, false, user);
	}catch(int e){
		cout << "User already exists" << endl;
		Utilities::pressEnter();
		return;
	}
	Db::Db::Disconnect();

	Utilities::pressEnter();

}

void ManagerMethods::deleteUser(){
	string username;
	User::User user;

	cout << "Username to delete: ";
	cin >> username;
	cout << endl;

	Db::Db::Connect();
	try{
		User::UserTable::GetUser(username, user);
	}catch (int e){
		if(e == USER_NOT_EXIST){
			cout << "User does not exist" << endl;
			Utilities::pressEnter();
			return;
		}
	}
	Db::Db::Disconnect();

	if(user.id == 0){
		cout << "User does not exist" << endl;
		Utilities::pressEnter();
		return;
	}

	if(user.cAccount.id && !user.cAccount.balance){
		cout << "Chequing account balance not 0. Cannot delete user" << endl;
		Utilities::pressEnter();
		return;
	}else if(user.sAccount.id && !user.sAccount.balance){
		cout << "Chequing account balance not 0. Cannot delete user" << endl;
		Utilities::pressEnter();
		return;

	}else{

		Db::Db::Connect();
		try{
			User::UserTable::DeleteUser(username);
		}catch (int e){
			cout << "User likely doesn't exist" << endl;
			Utilities::pressEnter();
			return;
		}
		Db::Db::Disconnect();

		cout << username + " has been deleted" << endl;
		Logger::info("Bank Manager deleted " + user.username);
		Utilities::pressEnter();
		return;
	}

}

void ManagerMethods::monthEndCreditPayment(){
	vector<User::User> users;
	Db::Db::Connect();
	try{
		User::UserTable::GetAllUsers(users);
	}catch(int e){
		cout << "database is disconnected. See admin" << endl;
		Utilities::pressEnter();
		return;
	}
	Db::Db::Disconnect();

	for(vector<User::User>::iterator it = users.begin(); it != users.end(); ++it){
		//logic for making payment from users chequing account to credit account
		if((*it).permissions == USER_PERMISSION_USER){


			double amount;

			if((*it).fullPayment){
				amount = (*it).credAccount.balance;
			}else{
				amount = (0.1) * (*it).credAccount.balance;
			}

			cout << "credit balance is " << amount;
			cout << "chequing account id is " << (*it).cAccount.id;
			cout << "cred account is id " << (*it).credAccount.id;
			cout << "name is " << (*it).username;
			FundMovementValidation::endOfMonthCreditPayment((*it), (*it).cAccount, (*it).credAccount, amount);
		}else{

		}

	}
}


void ManagerMethods::openAccount(){

	string username;
	string accountType;
	User::User user;
	cout << "Username: ";
	cin >> username;
	cout << endl;

	Db::Db::Connect();
	try{
		User::UserTable::GetUser(username, user);
	}catch(int e){
		if(e == USER_NOT_EXIST){
			cout << "User does not exist" << endl;
			Utilities::pressEnter();
			return;
		}else{
			//do nothing all is well
		}
	}

	if(user.id == 0){
		cout << "User does not exist" << endl;
		Utilities::pressEnter();
		return;
	}

	if(user.permissions != USER_PERMISSION_USER){
		cout << "This user is not a customer" << endl;
		Utilities::pressEnter();
		return;
	}

	Db::Db::Disconnect();

	cout << "Create chequing, savings, or credit account? (c, s, cr): ";
	cin >> accountType;
	cout << endl;

	if(accountType == "c"){

		Db::Db::Connect();
		try{
			AccountTable::CreateAccount(user, CHEQUING_ACCOUNT);
		}catch(int e){
			cout << "An error occurred ";
			cout << e;
			Utilities::pressEnter();

			return;
		}

		Db::Db::Disconnect();
		Logger::info("Bank Manager open chequing account for " +user.username);
		cout << "Chequing account created for " << user.username << endl;
		Utilities::pressEnter();
		return;

	}else if(accountType == "s"){

		Db::Db::Connect();
		try{
			AccountTable::CreateAccount(user, SAVINGS_ACCOUNT);
		}catch(int e){
			cout << "An error occurred ";
			cout << e;
			Utilities::pressEnter();

			return;
		}

		Db::Db::Disconnect();
		Logger::info("Bank Manager open savings account for " +user.username);
		cout << "Savings account created for " << user.username << endl;
		Utilities::pressEnter();
		return;
	}else if (accountType == "cr"){
		int creditLimit = 0;

		cout << "Set credit limit for this account:" << endl;
		cout << "> ";
		cin >> creditLimit;

		Db::Db::Connect();
		try{
			AccountTable::CreateAccount(user, CREDIT_ACCOUNT);
		}catch(int e){
			cout << "An error occurred ";
			cout << e;
			Utilities::pressEnter();

			return;
		}

		User::UserTable::SetCreditLimit(user, creditLimit);
		Db::Db::Disconnect();
		Logger::info("Bank Manager open credit account for " +user.username);
		cout << "credit account created for " << user.username << endl;
		Utilities::pressEnter();
		return;
	}else {
		cout << "Improper input" << endl;
		return;
	}

}

void ManagerMethods::closeAccount(){
	string username;
	string accountType;
	User::User user;

	cout << "Username: ";
	cin >> username;
	cout << endl;

	Db::Db::Connect();
	try{
		User::UserTable::GetUser(username, user);
	}catch (int e){
		if(e == USER_NOT_EXIST){
			cout << "User does not exist" << endl;
			Utilities::pressEnter();
			return;
		}
	}

	if (user.permissions != USER_PERMISSION_USER){
		cout << "This user is not a customer and has no accounts" << endl;
		Utilities::pressEnter();
		return;
	}

	if(user.id == 0){
		cout << "User does not exist" << endl;
		Utilities::pressEnter();
		return;
	}

	Db::Db::Disconnect();

	cout << "Close chequing, savings, or credit account? (c, s, cr): ";
	cin >> accountType;
	cout << endl;

	if(accountType == "c"){
		if(!user.cAccount.id){
			cout << "Chequing account does not exist" << endl;
			Utilities::pressEnter();
			return;
		}else if(user.cAccount.balance!=0){
			cout << "balance not 0. Cannot close" << endl;
			Utilities::pressEnter();
			return;
		}else{
			Db::Db::Connect();
			try{
				AccountTable::DeleteAccount(user.cAccount);
			}catch(int e){
				Db::Db::Disconnect();
				cout << "cannot delete user" << endl;
				Utilities::pressEnter();
				return;
			}
			Db::Db::Disconnect();
			cout << "Chequing account closed" << endl;
			Logger::info("Bank Manager closed chequing account for " + user.username);
			Utilities::pressEnter();
			return;
		}
	}else if(accountType == "s"){
		if(!user.sAccount.id){
			cout << "Savings account does not exist" << endl;
			Utilities::pressEnter();
			return;

		}else if(user.sAccount.balance!=0){
			cout << "balance not 0. Cannot close" << endl;
			Utilities::pressEnter();
			return;
		}else{
			Db::Db::Connect();
			try{
				AccountTable::DeleteAccount(user.sAccount);
			}catch (int e){
				Db::Db::Disconnect();
				cout << "cannot delete account" << endl;
				Utilities::pressEnter();
				return;
			}
			Db::Db::Disconnect();

			cout << "Savings account closed" << endl;
			Logger::info("Bank Manager closed savings account for " + user.username);
			Utilities::pressEnter();
			return;
		}
	}else if(accountType == "cr"){
		if(!user.credAccount.id){
			cout << "Credit account does not exist" << endl;
			Utilities::pressEnter();
			return;

		}else if(user.credAccount.balance!=0){
			cout << "balance not 0. Cannot close" << endl;
			Utilities::pressEnter();
			return;
		}else{
			Db::Db::Connect();
			try{
				AccountTable::DeleteAccount(user.credAccount);
			}catch (int e){
				Db::Db::Disconnect();
				cout << "cannot delete account" << endl;
				Utilities::pressEnter();
				return;
			}
			Db::Db::Disconnect();

			cout << "Credit account closed" << endl;
			Logger::info("Bank Manager closed credit account for " + user.username);
			Utilities::pressEnter();
			return;
		}
	}else{
		cout << "Improper input" << endl;
		Utilities::pressEnter();
		return;
	}

	return;

}

void ManagerMethods::getUserDetails(){
	string username;
	User::User user;

	cout << "Username: ";
	cin >> username;
	cout << endl;

	Db::Db::Connect();
	try{
		User::UserTable::GetUser(username, user);
	}catch (int e){
		if (e == USER_NOT_EXIST){
			cout << "User does not exist" << endl;
			Utilities::pressEnter();
			return;
		}
	}


	if(user.id == 0){
		cout << "User does not exist" << endl;
		Utilities::pressEnter();
		return;
	}

	Db::Db::Disconnect();

	cout << "user id: " ;
	cout << user.id << endl;
	cout << "username: " + user.username << endl;


	if(user.permissions == USER_PERMISSION_USER){
		cout << "bank customer" << endl;
		if(user.cAccount.id){

			cout << "Chequing Balance: ";
			cout<< user.cAccount.balance << endl;
		}else{
			cout << "No Chequing Account" << endl;
		}
		if(user.sAccount.id){

			cout << "Savings Balance: ";
			cout << user.sAccount.balance << endl;
		}else{
			cout << "No Savings Account" << endl;
		}
	}else if(user.permissions == USER_PERMISSION_ADMIN){
		cout << "Bank Manager" << endl;
	}else if(user.permissions == USER_PERMISSION_MAINTENANCE){
		cout << "Bank Maintenance" << endl;
	}else{
		cout << "No Permissions Set" << endl;
	}

	Utilities::pressEnter();

}

void ManagerMethods::getAllUserDetails(){
	vector<User::User> users;
	Db::Db::Connect();
	try{
		User::UserTable::GetAllUsers(users);
	}catch(int e){
		cout << "database is disconnected. See admin" << endl;
		Utilities::pressEnter();
		return;
	}
	Db::Db::Disconnect();


	for(vector<User::User>::iterator it = users.begin(); it != users.end(); ++it){
		string role;
		if ((*it).permissions == USER_PERMISSION_USER){
			role = "bank customer";
		}else if ((*it).permissions == USER_PERMISSION_ADMIN){
			role = "Bank Manager";
		}else if((*it).permissions == USER_PERMISSION_MAINTENANCE){
			role = "Maintenance";
		}else{
			role = "undefined";
		}


		cout << "**************************************************" << endl;
		cout << "username: " << (*it).username << endl;
		cout << "user id: " << (*it).id << endl;
		cout << "role: " << role <<endl;
		if (!(*it).cAccount.id){
			cout << "Chequing Balance: No chequing account" << endl;
		}else{
			cout << "Chequing Balance: " << (*it).cAccount.balance << endl;
		}

		if (!(*it).sAccount.id){
			cout << "Savings Balance: No savings account" << endl;
		}else{
			cout << "Savings Balance: " << (*it).sAccount.balance << endl;
		}

		if(!(*it).credAccount.id){
			cout << "Credit Balance: No credit account" << endl;
		}else{
			cout << "Credit Balance: " << (*it).credAccount.balance << endl;
		}

	}

	Utilities::pressEnter();
	return;
}

void ManagerMethods::getFrozenCards(){
	vector<User::User> users;
	Db::Db::Connect();
	try{
		User::UserTable::GetAllUsers(users);
	}catch(int e){
		cout << "database is disconnected. See admin" << endl;
		Utilities::pressEnter();
		return;
	}
	Db::Db::Disconnect();

	cout << "List of users with frozen accounts" << endl;
	cout << "User \tCredit Balance " << endl;
	for(vector<User::User>::iterator it = users.begin(); it != users.end(); ++it){
		if((*it).frozen){
			cout << (*it).username << "\t" << (*it).credAccount.balance	<< endl;
		}
	}

	Utilities::pressEnter();
}

void ManagerMethods::managerCommandList(){
	cout << "Enter a command" <<endl;
	cout << "\tu.   Create User" <<endl;
	cout << "\td.   Delete User" <<endl;
	cout << "\to.   Open Account" <<endl;
	cout << "\tc.   Close Account" <<endl;
	cout << "\tg.   Get User Details" <<endl;
	cout << "\ta.   Get Details of All Users" << endl;
	cout << "\tm.   Run Month End Payments" << endl;
	cout << "\tf.   Get List of Users With Frozen Cards" << endl;
	cout<<  "\tq.   Exit" <<endl <<endl;

	cout<< "> ";
}

void ManagerMethods::managerCommandSelect(User::User &user){
	while(true){
		Utilities::clearScreen();
		managerCommandList();

		string command;
		cin >> command;

		//Prevent multiple characters from being entered
		if (command.size() != 1) {
			cout << "Unknown command" << endl << endl;
			continue;
		}

		switch(command[0])
		{
		case 'u':
			Utilities::clearScreen();
			createUser();
			break;


		case 'd':
			Utilities::clearScreen();
			deleteUser();
			break;

		case 'o':
			Utilities::clearScreen();
			openAccount();
			break;

		case 'c':
			Utilities::clearScreen();
			closeAccount();
			break;

		case 'g':
			Utilities::clearScreen();
			getUserDetails();
			break;

		case 'a':
			Utilities::clearScreen();
			getAllUserDetails();
			break;

		case 'm':
			Utilities::clearScreen();
			monthEndCreditPayment();
			break;

		case 'f':
			Utilities::clearScreen();
			getFrozenCards();
			break;

		case 'q':
			return;
			break;
		default:
			cout << "Unknown command" << endl << endl;
		}
	}
}


