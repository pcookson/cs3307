#include "account.h"
#include <iostream>

using namespace std;

int Account::deposit(double amount) {

	return DEPOSIT_SUCCESS;
}

int Account::withdrawl(double amount) {
	return 0;
}

double Account::getBalance() {
	return balance;
}

int Account::get_input(double amount) {
	return 0;
}
