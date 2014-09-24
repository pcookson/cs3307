#ifndef USER_H_
#define USER_H_

#include "../error.h"
#include <iostream>
#include "../logger.h"
#include "../Account/chequingaccount.h"
#include "../Account/savingsaccount.h"


namespace User {

class User
{
public:
    User();
    std::string username;
    long permissions;
    
    User(std::string username);
    int id;

    ChequingAccount cAccount;
    SavingsAccount sAccount;

private:

};

} /* namespace User */

#endif  // USER_H_
