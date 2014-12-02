#ifndef USERMETHODS_H
#define USERMETHODS_H
#include "user.h"

class UserMethods {
public:
	UserMethods() {
	}

    /** brief allows user to select a command
    *
    * @param user
    */
    static void userCommandSelect(User::User &user);


private:

    /** @brief gets the balance of an account
    * @param user
    */
    static void balance(User::User &user);

    /** @brief withdraw from an account
    *
    * @param user
    */
    static void withdraw(User::User &user);

    /** @brief deposit into an account
    *
    * @param user
    */
    static void deposit(User::User &user);

    /** @brief transfer funds between accounts
    *
    * @param user
    */
    static void transferFunds(User::User &user);

    /** @brief allows a user to make a payment from chequing to credit
     *
     * @param user
     */
    static void makeCreditPayment(User::User &user);
    /** @brief allows a user to see their purchases in the month
     *
     */
    static void purchasesInMonth(User::User &user);


    /** @brief presents a list of commands to user
    *
    */
    static void userCommandList();



};

#endif // USERMETHODS_H
