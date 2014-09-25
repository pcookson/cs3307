#ifndef LOGGER_H
#define LOGGER_H
#include <iostream>
#include <sstream>
#include <fstream>
#include "error.h"

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
/** @brief parameters are string - the message to send to file
 *
 * @param message the message to print as info
 */
    static void info(const string& message);

    /** @brief parameters are string - the message to send to file
     *
     * @param message the message to print out as a warning
     */

    static void warning(const string& message);

    /** @brief parameters are string - the message to send to file
     *
     * @param message - the message to print out as an error
     */

    static void error(const string& message);

    /** @brief parameters are string - the message to send to file
     *
     * @param message
     */

    /** @brief takes an int 1 or 0 to turn on or off the logging
     *
     * @param on the int, 1 or 0, to turn on or off the logging
     */
    static void setLoggingOnOff(int on);

    /** @brief used logInt to switch between multiple premade messages
     *
     * @param logInt the integer value - defined in logger
     * @param userName - username of the logged in user
     * @param amount - amount of money in this transaction
     * @param accountType - the account type in this transaction
     * @param fromAccount - the from account - used for withdraws and transfers
     * @param toAccount - the to account - used for deposits and transfers
     */
    static void log(int logInt, string &userName, double amount, const string &accountType,
                    const string &fromAccount, const string &toAccount);

    /** @brief uses logInt to switch between multiple premade messages
     *
     * @param logInt the interger value defined in logger
     * @param userName logged in user
     * @param amount amount of money in transaction
     * @param accountType the account type in the transaction
     */
    static void log(int logInt, string& userName, double amount, const string& accountType);

    /** @brief logs premade messages using logInt as the switch parameter
     *
     * @param logInt defined in logger
     * @param userName user currently logged in
     */
    static void log(int logInt, string &userName);

private:
    static string dblToString(double amount);
    static int logginOnOff;

    static void printToFile(const string& message, const string& logLevel);
};

#endif // HTMLLOGGER_H
