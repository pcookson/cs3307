#ifndef FUNDMOVEMENTVALIDATION_H
#define FUNDMOVEMENTVALIDATION_H

#include "savingsaccount.h"
#include "chequingaccount.h"
#include "account.h"
#include "../User/user.h"
#include "../logger.h"

class FundMovementValidation {
public:
	/** @brief default constructor
	 *
	 */
	FundMovementValidation() {

	}

	/** @brief Transfers funds from one account to another
	 *
	 * @param fromAccount the account to withdraw from
	 * @param toAccount the account to deposit to
	 * @param amount the amount to transfer
	 * @return int
	 */
	static int transferFunds(Account &fromAccount, Account &toAccount,
			double amount);

	/** @brief withdraws money from an account
	 *
	 * @param fromAccount
	 * @param amount
	 * @return
	 */
	static int withdraw(Account &fromAccount, double amount);

	/** @brief deposits money to an account
	 *
	 * @param toAccount
	 * @param amount
	 * @return
	 */
	static int deposit(Account &toAccount, double amount);

	static int endOfMonthCreditPayment(User::User &user, Account &chequingAccount, Account &creditAccount, double amount);

private:
	static SavingsAccount castToSavings(Account &sAccount);

	static ChequingAccount castToChequing(Account &cAccount);

};

#endif // FUNDMOVEMENTVALIDATION_H
