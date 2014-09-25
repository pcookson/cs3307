#include "chequingaccount.h"
#include <iostream>

using namespace std;

int ChequingAccount::withdrawl(double amount) {

	int inputContinue;

	if ((balance > 1000.00) && (balance - amount < 1000)
			&& (balance - amount > 0)) {
		cout
				<< "WARNING: This transaction will cause balance to drop below $1000.00."
				<< endl
				<< "This transaction, and every subsequent transaction will be subject to"
				<< endl << "a $2.00 service fee." << endl << "Current balance: "
				<< balance << endl
				<< "Do you wish to continue with transaction? (y/n)" << endl;

		do {
			inputContinue = get_input(amount);
		} while (inputContinue == 1);
		return inputContinue;

	} else if ((balance < 1000.00) && (balance - amount > 0)) {
		cout
				<< "WARNING: Balance is below $1000.00. This transaction will be subject to"
				<< endl << "a $2.00 service fee." << endl << "Current balance: "
				<< balance << endl
				<< "Do you wish to continue with transaction? (y/n)" << endl;

		do {
			inputContinue = get_input(amount);
		} while (inputContinue == 1);
		return inputContinue; //returns either ACCEPTS_FEE or DECLINES_FEE

	} else if (balance - amount < 0) {
		throw INSUFFICIENT_FUNDS;

	} else {

		return WITHDRAW_SUCCESSFUL;
	}
}
//private method
int ChequingAccount::get_input(double amount) {
	string decision;

	cout << ">"; //cursor
	cin >> decision;

	if (decision.size() != 1) {
		cout << "y or n only" << endl << endl;
		return 1;
	}

	switch (decision[0]) {
	case 'n':
		return DECLINES_FEE;
		break;

	case 'y':

		return ACCEPTS_FEE;
		break;

	default:
		cout << "Unknown Command" << endl << endl;
		throw 0;
	}
}
