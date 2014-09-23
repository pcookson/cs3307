#ifndef MANAGERMETHODS_H
#define MANAGERMETHODS_H

#define CHEQUING_ACCOUNT = 1
#define SAVINGS_ACCOUNT = 2

#include "User/user.h"
#include <iostream>
#include "chequingaccount.h"
#include "savingsaccount.h"
#include "usermethods.h"
#include "fundmovementvalidation.h"
#include "User/usertable.h"
#include <stdlib.h>

class ManagerMethods
{
public:
    ManagerMethods();

    static void getUserDetails();

    static void closeAccount();

    static void openAccount();

    static void createUser();

    static void deleteUser();

    static void managerCommandSelect(User::User &user);

    static void managerCommandList();

private:
   static void pressEnter();

    static void clearScreen();
};

#endif // MANAGERMETHODS_H
