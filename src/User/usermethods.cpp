#include <iostream>
#include "../Account/chequingaccount.h"
#include "../Account/savingsaccount.h"
#include "usermethods.h"
#include "../Account/fundmovementvalidation.h"
#include "usertable.h"
#include "../logger.h"
#include "../Utilities.h"
#include <stdlib.h>



void UserMethods::balance(User::User &user) {
	Logger::info(user.username + "\tchecked balance");

	if (user.cAccount.id) {
		cout << "Chequing Balance: ";
		cout << user.cAccount.balance << endl << endl;
	} else {
		cout << "No chequing account." << endl;
	}

	if (user.sAccount.id) {
		cout << "Savings Balance: ";
		cout << user.sAccount.balance << endl << endl;
	} else {
		cout << "No savings account" << endl;
	}
    Utilities::pressEnter();

}

void UserMethods::deposit(User::User &user) {

	string accountDeposit;
	double amount;
	string amountString;

	do {
		cout << "Which account to depost to?" << endl;
		cout << "Chequing (c) or Savings (s)?" << endl;
		cout << "> ";

		cin >> accountDeposit;
	} while (accountDeposit != "c" && accountDeposit != "s");

	//checks to see if savings or checking account exists
	if (accountDeposit == "c") {
		if (!user.cAccount.id) {
			cout
					<< "Warning: Chequing account does not exist. Request account from a manager"
					<< endl;
            Utilities::pressEnter();
			return;
		}
	} else if (accountDeposit == "s") {
		if (!user.sAccount.id) {
			cout
					<< "Warning: Savings account does not exist. Request account from manager"
					<< endl;
            Utilities::pressEnter();
			return;
		} else if (accountDeposit == "q") {
			return;
		}
	}
	cout << "How much to deposit?" << endl;
	cout << "> ";
	cin >> amount;

	//switched between chequing and savings accounts
	switch (accountDeposit[0]) {
	case 'c':
		amountString = Utilities::double_to_string(amount);

		try {
			FundMovementValidation::deposit(user.cAccount, amount);
		} catch (int e) {
			Logger::log(DEPOSIT_FAILURE, user.username, amount, "chequing");
		}
		Logger::log(DEPOSIT_SUCCESS, user.username, amount, "chequing");
		return;
		break;
	case 's':
		amountString = Utilities::double_to_string(amount);

		try {
			FundMovementValidation::deposit(user.sAccount, amount);
		} catch (int e) {
			Logger::log(DEPOSIT_FAILURE, user.username, amount, "chequing");
		}
		Logger::log(DEPOSIT_SUCCESS, user.username, amount, "savings");

		return;
		break;
	default:
		cout << "Unknown command" << endl;
	}
}

void UserMethods::withdraw(User::User &user) {
	string accountWithdraw;
	string amountString;

	double amount;

	do {
		cout << "Which account to withdraw from?" << endl;
		cout << "Chequing (c) or Savings (s)?" << endl;
		cout << "> ";

		cin >> accountWithdraw;
	} while (accountWithdraw != "c" && accountWithdraw != "s");

	if (accountWithdraw == "c") {
		if (!user.cAccount.id) {
			cout
					<< "Warning: Chequing account does not exist. Request account from a manager"
					<< endl;
            Utilities::pressEnter();
			return;
		}
	} else if (accountWithdraw == "s") {
		if (!user.sAccount.id) {
			cout
					<< "Warning: Savings account does not exist. Request account from manager"
					<< endl;
            Utilities::pressEnter();
			return;
		} else if (accountWithdraw == "q") {
			return;
		}
	}
	cout << "How much to withdraw?" << endl;
	cout << "> ";
	cin >> amount;

	switch (accountWithdraw[0]) {
	case 'c':
		// amountString = Utilities::double_to_string(amount);

		try {
			FundMovementValidation::withdraw(user.cAccount, amount);
		} catch (int e) {
			if (e == INSUFFICIENT_FUNDS) {
				cout << "Insufficient funds" << endl;
                Utilities::pressEnter();
				Logger::log(WITHDRAW_FAILURE, user.username, amount,
						"chequing");
			}
		}

		Logger::log(WITHDRAW_SUCCESSFUL, user.username, amount, "chequing");
		return;
		break;
	case 's':
		amountString = Utilities::double_to_string(amount);
		try {
			FundMovementValidation::withdraw(user.sAccount, amount);
		} catch (int e) {
			if (e == INSUFFICIENT_FUNDS) {
				cout << "Insufficient funds" << endl;
                Utilities::pressEnter();
				Logger::log(WITHDRAW_FAILURE, user.username, amount, "savings");
			}
		}
		Logger::log(WITHDRAW_SUCCESSFUL, user.username, amount, "savings");
		return;
		break;
	default:
		cout << "Unknown command" << endl;
	}

}

void UserMethods::transferFunds(User::User &user) {
	string amountString;
	string accountTransfer;
	string otherUserName;

	string otherAccount;

	double amount;

	do {
		cout << "Which account to transfer from?" << endl;
		cout << "Chequing (c) or Savings (s)?" << endl;
		cout << "> ";

		cin >> accountTransfer;
	} while (accountTransfer != "c" && accountTransfer != "s");

	if (accountTransfer == "c") {
		if (!user.cAccount.id) {
			cout
					<< "Warning: Chequing account does not exist. Request account from a manager"
					<< endl;
            Utilities::pressEnter();
			return;
		}
	} else if (accountTransfer == "s") {
		if (!user.sAccount.id) {
			cout
					<< "Warning: Savings account does not exist. Request account from manager"
					<< endl;
            Utilities::pressEnter();
			return;
		} else if (accountTransfer == "q") {
			return;
		}
	}
	cout << "How much to transfer?" << endl;
	cout << "> ";
	cin >> amount;

	cout << "Username of person to transfer to?" << endl;
	cout << "> ";
	cin >> otherUserName;

	User::User otherUser;
	Db::Db::Connect();
	try{
	User::UserTable::GetUser(otherUserName, otherUser);
	}catch(int e){
		Db::Db::Disconnect();
		cout << "user does not exist" << endl;
        Utilities::pressEnter();
		return;
	}
	if (otherUser.username != otherUserName) {
		cout << otherUserName + " does not exist" << endl;
        Utilities::pressEnter();
		return;
	}
	Db::Db::Disconnect();
	cout << "Account to transfer to? (c or s)" << endl;
	cout << "> ";
	cin >> otherAccount;

	if (otherAccount == "c") {
		if (!otherUser.cAccount.id) {
			cout << otherUser.username << " does not have a chequing account"
					<< endl;
            Utilities::pressEnter();
			return;
		}
	} else {
		if (!otherUser.sAccount.id) {
			cout << otherUser.username << " does not have a savings account:"
					<< endl;
            Utilities::pressEnter();
			return;
		}
	}

	switch (accountTransfer[0]) {
	case 'c':
		if (otherAccount == "c") {
			amountString = Utilities::double_to_string(amount);
			Logger::info(
					user.username + "\ttransferred " + amountString
							+ " from chequing account to " + otherUserName + " "
							+ otherAccount);
			FundMovementValidation::transferFunds(user.cAccount,
					otherUser.cAccount, amount);
		} else {
			amountString = Utilities::double_to_string(amount);
			Logger::info(
					user.username + "\ttransferred " + amountString
							+ " from chequing account to " + otherUserName + " "
							+ otherAccount);
			FundMovementValidation::transferFunds(user.cAccount,
					otherUser.sAccount, amount);
		}
		return;
		break;
	case 's':
		if (otherAccount == "c") {
			amountString = Utilities::double_to_string(amount);
			Logger::info(
					user.username + "\ttransferred " + amountString
							+ " from saving account to " + otherUserName + " "
							+ otherAccount);
			FundMovementValidation::transferFunds(user.sAccount,
					otherUser.cAccount, amount);
		} else {
			amountString = Utilities::double_to_string(amount);
			Logger::info(
					user.username + "\ttransferred " + amountString
							+ " from saving account to " + otherUserName + " "
							+ otherAccount);
			FundMovementValidation::transferFunds(user.sAccount,
					otherUser.sAccount, amount);
		}

		return;
		break;
	default:
		cout << "Unknown command" << endl;
            Utilities::pressEnter();
		return;
	}
}

void UserMethods::userCommandList() {
	cout << "Enter a command" << endl;
	cout << "\tb.   Balances" << endl;
	cout << "\tw.   Withdraw" << endl;
	cout << "\td.   Deposit" << endl;
	cout << "\tt.   Transfer" << endl;
	cout << "\tq.   Exit" << endl << endl;

	cout << "> ";

}

void UserMethods::userCommandSelect(User::User &user) {
	Logger::info(user.username + " successfully logged in");
	while (true) {
        Utilities::clearScreen();
		userCommandList();

		string command;
		cin >> command;

		//Prevent multiple characters from being entered
		if (command.size() != 1) {
			cout << "Unknown command" << endl << endl;
			continue;
		}

		switch (command[0]) {
		case 'b':
            Utilities::clearScreen();
			balance(user);
			break;

		case 'w':
            Utilities::clearScreen();
			withdraw(user);
			break;

		case 'd':
            Utilities::clearScreen();
			deposit(user);
			break;

		case 't':
            Utilities::clearScreen();
			transferFunds(user);
			break;

		case 'q':
            Utilities::clearScreen();
			return;
			break;
		default:
			cout << "Unknown command" << endl << endl;
		}
	}
}
