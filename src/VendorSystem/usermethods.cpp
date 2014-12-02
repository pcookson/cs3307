/*
 * usermethods.cpp
 *
 *  Created on: Nov 25, 2014
 *      Author: patrick
 */

#include "usermethods.h"
#include "../Utilities.h"
#include "../Purchase/purchase.h"
#include "../Purchase/purchasetable.h"
#include "../Account/accounttable.h"
#include <stdlib.h>
#include <time.h>



usermethods::usermethods() {
	// TODO Auto-generated constructor stub

}

void usermethods::processPurchase(User::User &user, int amount){
	if((amount + user.credAccount.balance) > user.creditLimit){
		cout << "Cannot process transaction. Purchase would go above credit limit." << endl;
		Utilities::pressEnter();
		return;
	}
	Db::Db::Connect();
	PurchaseTable::MakePurchase(user.credAccount, amount);
	AccountTable::Deposit(user.credAccount, double(amount));
	Db::Db::Disconnect();
}

void usermethods::makePurchase(User::User &user){
	int randNumPurchase;
	string decision;
	//initialize random seed
	srand(time(NULL));

	randNumPurchase = rand() % 100 + 1;

	cout << "Do you wish to purchase item for $";
	cout << Utilities::int_to_string(randNumPurchase) << " (y or n)" << endl;

	while(true){
		cout << "> ";

		cin >> decision;

		//Prevent multiple characters from being entered
		if (decision.size() != 1) {
			cout << "Unknown command" << endl << endl;
			continue;
		}

		switch(decision[0]){
		case 'y':
			if(!user.frozen){
				processPurchase(user, randNumPurchase);
			}else{
				cout << "Your credit card is frozen. Please reduce balance to $0" << endl;
				Utilities::pressEnter();

			}
			return;
			break;
		case 'n':
			Utilities::clearScreen();
			return;
			break;

		default:
			cout << "Unknown command" << endl << endl;
		}
	}
}

void usermethods::userCommandList(){
	cout << "Enter a command" << endl;
	cout << "\tp.   Make Purchase" << endl;
	cout << "\tq.   Exit" << endl << endl;

	cout << "> ";

}


void usermethods::userCommandSelect(User::User &user){
	while(true){
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
		case 'p':
			Utilities::clearScreen();
			makePurchase(user);
			return;
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


usermethods::~usermethods() {
	// TODO Auto-generated destructor stub
}

