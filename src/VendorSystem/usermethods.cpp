/*
 * usermethods.cpp
 *
 *  Created on: Nov 25, 2014
 *      Author: patrick
 */

#include "usermethods.h"
#include "../Utilities.h"
#include <stdlib.h>
#include <time.h>



usermethods::usermethods() {
	// TODO Auto-generated constructor stub

}

void usermethods::processPurchase(User::User &user){

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
			processPurchase(user);
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

