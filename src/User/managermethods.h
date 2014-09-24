#ifndef MANAGERMETHODS_H
#define MANAGERMETHODS_H

#define C_ACCOUNT = 10
#define S_ACCOUNT = 11

#include "../User/user.h"
#include <iostream>
#include "../Account/chequingaccount.h"
#include "../Account/savingsaccount.h"
#include "usermethods.h"
#include "../Account/fundmovementvalidation.h"
#include "usertable.h"
#include "../Account/accounttable.h"
#include <stdlib.h>

class ManagerMethods
{
public:
    ManagerMethods();

    static void getUserDetails();

    static void getAllUserDetails();

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
