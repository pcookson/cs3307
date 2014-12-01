#ifndef USER_H_
#define USER_H_

#include "../error.h"
#include <iostream>
#include "../logger.h"
#include "../Account/chequingaccount.h"
#include "../Account/savingsaccount.h"
#include "../Account/creditaccount.h"

#define USER_PERMISSION_USER 0X0
#define USER_PERMISSION_MAINTENANCE 0X1
#define USER_PERMISSION_ADMIN 0X2



namespace User {

class User
{
public:
    User();
    std::string username;
    long permissions;
    
    User(std::string username);
    int id;

    bool fullPayment;

    ChequingAccount cAccount;
    SavingsAccount sAccount;
    CreditAccount credAccount;
    bool frozen;
    int creditLimit;

private:

};

} /* namespace User */

#endif  // USER_H_
