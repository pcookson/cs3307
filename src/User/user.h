#include <iostream>
//#include "logger.h"

#ifndef USER_H_
#define USER_H_

#define AUTHENTICATION_FAILURE 0x0
#define AUTHENTICATION_SUCCESS 0x1

namespace User {

class User
{
public:
	User() {
	}

    std::string username;
    std::string password;
    
    User(std::string username);
    long Authenticate(std::string password);
    void logger(int logInt);

private:




};

} /* namespace User */

#endif  // USER_H_
