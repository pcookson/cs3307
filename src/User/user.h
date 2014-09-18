#include <iostream>
#include "logger.h"

#ifndef USER_H_
#define USER_H_



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

#endif  // USER_H_
