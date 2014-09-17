#ifndef LOGGER_H
#define LOGGER_H
#include <iostream>
#include <sstream>
#include <fstream>

#define AUTHENTICATION_FAILURE 0x0
#define AUTHENTICATION_SUCCESS 0x1

#define ACCEPTS_FEE 10
#define DECLINES_FEE 11
#define WITHDRAW_SUCCESSFUL 12
#define WITHDRAW_FAILURE 13
#define DEPOSIT_SUCCESS 14
#define DEPOSIT_FAILURE 15
#define TRANSFER_FUNDS 16

#define ADD_USER 20
#define DELETE_USER 21
#define ADD_CHEQUING_ACCOUNT 22
#define CLOSE_CHEQUING_ACCOUNT 23
#define ADD_SAVINGS_ACCOUNT 24
#define CLOSE_SAVINGS_ACCOUNT 25

#define TURNED_ON_LOGGING 30
#define TURNED_OFF_LOGGING 31

#define INSUFFICIENT_FUNDS_TO_WITHDRAW 100

using namespace std;
class Logger
{

public:
    Logger(){

    }

    static void info(const string& message);

    static void warning(const string& message);

    static void error(const string& message);

    static void setLoggingOnOff(int on);

    static void log(int logInt, string &userName, double amount, const string &accountType,
                const string &fromAccount, const string &toAccount);

    static void log(int logInt, string& userName, double amount, const string& accountType);

    static void log(int logInt, string &userName);

private:
   static string dblToString(double amount);
    static int logginOnOff;

    static void printToFile(const string& message, const string& logLevel);
};

#endif // HTMLLOGGER_H
