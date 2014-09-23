#ifndef USERMETHODS_H
#define USERMETHODS_H
#include "user.h"


class UserMethods{
public:
    UserMethods(){}

    static void pressEnter();

    static void clearScreen();

    static void balance(User::User &user);
    static void withdraw(User::User &user);

    static void deposit(User::User &user);

    static void transferFunds(User::User &user);

    static void userCommandSelect(User::User &user);

    static void userCommandList();

};

#endif // USERMETHODS_H
