#include "logger.h"
#include <time.h>

int Logger::logginOnOff = 1;

void Logger::info(const string& message) {
	printToFile(message, "INFO");

}

void Logger::warning(const string& message) {
	printToFile(message, "WARNING");
}

void Logger::error(const string& message) {
	printToFile(message, "ERROR");
}

void Logger::printToFile(const string& message, const string& logLevel) {
	if (logginOnOff) { //default is on
		time_t timer = time(NULL);
		struct tm *tm = localtime(&timer);
		char date[20];
		strftime(date, sizeof(date), "%Y-%m-%d", tm);
		ofstream logfile("report.txt", std::ios_base::app | std::ios_base::out);

		logfile << date << "\t" << logLevel << "\t" << message << endl;
	}

}

/*
 * Overloaded log methods allows for varying levels of information
 *
 */
void Logger::log(int logInt, string& userName, double amnt,
		const string &accountType, const string& fromAccount,
		const string &toAccount) {
	string amount = dblToString(amnt);

	switch (logInt) {
	case ACCEPTS_FEE:
		Logger::info(
				userName + " accepted fee for withdrawl. Successfully withdrew "
						+ amount + " from " + accountType);
		break;
	case DECLINES_FEE:
		Logger::warning(userName + " declined fee for withdrawl");
	case WITHDRAW_SUCCESSFUL:
		Logger::info(
				userName + " successfully withdrew " + amount + " from "
						+ accountType);
		break;
	case WITHDRAW_FAILURE:
		Logger::info(userName + " failed to withdraw money");
		break;

	case DEPOSIT_FAILURE:
		Logger::info(userName + " failed to deposit money");
		break;
	case DEPOSIT_SUCCESS:
		Logger::info(
				userName + " successfully deposited " + amount + " into "
						+ accountType);
		break;
	case TRANSFER_FUNDS:
		Logger::info(
				userName + " transferred " + amount + " from " + fromAccount
						+ " to " + toAccount);
		break;
	case INSUFFICIENT_FUNDS_TO_WITHDRAW:
		Logger::info(
				userName + " attempted to withdraw funds " + accountType
						+ ". Insufficient funds to process transaction");
		break;
	default:
		Logger::info("No logging for this situation");
	}
}

void Logger::log(int logInt, string& userName, double amnt,
		const string& accountType) {
	string amount = dblToString(amnt);
	switch (logInt) {
	case ACCEPTS_FEE:
		Logger::info(
				userName + " accepted fee for withdrawl. Successfully withdrew "
						+ amount + " from " + accountType);
		break;
	case DECLINES_FEE:
		Logger::warning(userName + " declined fee for withdrawl");

	case WITHDRAW_SUCCESSFUL:
		Logger::info(
				userName + " successfully withdrew " + amount + " from "
						+ accountType);
		break;
	case WITHDRAW_FAILURE:
		Logger::info(userName + " failed to withdraw money");
		break;

	case DEPOSIT_FAILURE:
		Logger::info(userName + " failed to deposit money");
		break;
	case DEPOSIT_SUCCESS:
		Logger::info(
				userName + " successfully deposited " + amount + " into "
						+ accountType);
		break;
	case INSUFFICIENT_FUNDS_TO_WITHDRAW:
		Logger::info(
				userName + " attempted to withdraw funds from " + accountType
						+ ". Insufficient funds to process transaction");
		break;
	default:
		Logger::info("No logging for this situation");
	}
}

void Logger::log(int logInt, string& userName) {
	switch (logInt) {
	case ACCEPTS_FEE:
		Logger::info(userName + " accepted fee for withdrawl");
		break;
	case DECLINES_FEE:
		Logger::warning(userName + " declined fee for withdrawl");
		break;
	case WITHDRAW_FAILURE:
		Logger::info(userName + " failed to withdraw money");
		break;

	case DEPOSIT_FAILURE:
		Logger::info(userName + " failed to deposit money");
		break;
	case INSUFFICIENT_FUNDS_TO_WITHDRAW:
		Logger::info(
				userName
						+ " attempted to withdraw funds. Insufficient funds to process transaction");
		break;
	default:
		Logger::info("No logging for this situation");
	}
}

string Logger::dblToString(double amount) {
	ostringstream strs;
	strs << amount;
	string str = strs.str();
	return str;
}
void Logger::setLoggingOnOff(int on) {
	logginOnOff = on;
}
