#include "fundmovementvalidation.h"
#include "../Db/db.h"
#include "../User/usertable.h"
#include "../Account/accounttable.h"
#include <iostream>
#include <typeinfo>

using namespace std;

int FundMovementValidation::transferFunds(Account &fromAccount,
		Account &toAccount, double amount) {

	withdraw(fromAccount, amount);

	deposit(toAccount, amount);

	return 0;
}

int FundMovementValidation::withdraw(Account &fromAccount, double amount) {

	int callback;
	try {
		ChequingAccount &fAccount = dynamic_cast<ChequingAccount&>(fromAccount);
		try {
			callback = fAccount.withdrawl(amount);
		} catch (int e) {
			if (e == INSUFFICIENT_FUNDS) {
				throw INSUFFICIENT_FUNDS;
			}
		}

		if (callback == ACCEPTS_FEE) {
			Db::Db::Connect();
			amount = amount + 2.00;
			AccountTable::Withdraw(fAccount, amount);
			Db::Db::Disconnect();

		} else if (callback == DECLINES_FEE) {
			//do nothing... those cheap bas****
		} else if (callback == WITHDRAW_SUCCESSFUL) {
			Db::Db::Connect();
			AccountTable::Withdraw(fAccount, amount);
			Db::Db::Disconnect();
		}

	} catch (bad_cast& bc1) {
		try{
			SavingsAccount &fAccount = dynamic_cast<SavingsAccount&>(fromAccount);
			try {
				fAccount.withdrawl(amount);
			} catch (int e) {
				if (e == INSUFFICIENT_FUNDS) {
					throw INSUFFICIENT_FUNDS;
				}
			}
			Db::Db::Connect();
			AccountTable::Withdraw(fAccount, amount);
			Db::Db::Disconnect();
		}catch (bad_cast& bc2){
			CreditAccount &fAccount = dynamic_cast<CreditAccount&>(fromAccount);
			try {
				fAccount.withdrawl(amount);
			} catch (int e) {
				if (e == INSUFFICIENT_FUNDS) {
					throw INSUFFICIENT_FUNDS;
				}
			}
			Db::Db::Connect();
			AccountTable::Withdraw(fAccount, amount);
			Db::Db::Disconnect();
		}

	}

	return 0;
}

int FundMovementValidation::deposit(Account &toAccount, double amount) {
	try {

		SavingsAccount &tAccount = dynamic_cast<SavingsAccount&>(toAccount);
		tAccount.deposit(amount);
		Db::Db::Connect();
		AccountTable::Deposit(tAccount, amount);
		Db::Db::Disconnect();
	} catch (bad_cast& bc) {
		ChequingAccount &tAccount = dynamic_cast<ChequingAccount&>(toAccount);
		tAccount.deposit(amount);
		Db::Db::Connect();
		AccountTable::Deposit(tAccount, amount);
		Db::Db::Disconnect();
	}

	return 0;
}

int FundMovementValidation::endOfMonthCreditPayment(User::User &user, Account &cAccount, Account &credAccount, double amount){
	try{
		ChequingAccount &chequingAccount = dynamic_cast<ChequingAccount&>(cAccount);
		//chequingAccount.withdrawl(amount);
		CreditAccount &creditAccount = dynamic_cast<CreditAccount&>(credAccount);
		if(chequingAccount.balance < amount){
			if(!user.frozen){
				Db::Db::Connect();
				User::UserTable::FreezeCredit(user);
				AccountTable::Deposit(creditAccount, 0.02 * creditAccount.balance);
				Db::Db::Disconnect();
			}
			return 0;
		}

		Db::Db::Connect();
		AccountTable::Withdraw(chequingAccount, amount);
		Db::Db::Disconnect();
	}catch (bad_cast& bc){
		//if this happens, must have passed in wrong account type
	}

	try{
		CreditAccount &creditAccount = dynamic_cast<CreditAccount&>(credAccount);
		creditAccount.deposit(amount);
		Db::Db::Connect();
		//reducing credit card is the same as withdrawing funds
		AccountTable::Withdraw(creditAccount, amount);

		// add interest to card if there is a remaining balance
		if(creditAccount.balance != 0){
			AccountTable::Deposit(creditAccount, 0.02 * creditAccount.balance);
		}

		Db::Db::Disconnect();
	}catch (bad_cast& bc){
		//if this happens, must have passed in wrong account type
	}
	return 0;
}
