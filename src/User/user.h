#ifndef USER_H_
#define USER_H_


#define USER_PERMISSION_USER 0X0
#define USER_PERMISSION_MAINTENANCE 0X1
#define USER_PERMISSION_ADMIN 0X2


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
