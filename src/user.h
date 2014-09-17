#include <iostream>
#include "htmllogger.h"

#ifndef USER_H_
#define USER_H_

#define AUTHENTICATION_FAILURE 0x0
#define AUTHENTICATION_SUCCESS 0x1

class User
{
public:
	User() {
	}

    std::string username;
    std::string password;
    
    User(std::string username);
    long Authenticate(std::string password);


private:




};

#endif  // USER_H_
