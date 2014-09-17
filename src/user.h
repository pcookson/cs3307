#include <iostream>
#include "logger.h"

#ifndef USER_H_
#define USER_H_

#define AUTHENTICATION_FAILURE 0x0
#define AUTHENTICATION_SUCCESS 0x1

#define ACCEPTS_FEE 10
#define DECLINES_FEE 11
#define WITHDRAW_SUCCESSFUL 12
#define WITHDRAW_FAILURE 13
#define DEPOSIT_SUCCESS 14
#define DEPOSIT_FAILURE 15
#define TRANSFER_FUNDS 16

#define ADD_USER 20
#define DELETE_USER 21
#define ADD_CHEQUING_ACCOUNT 22
#define CLOSE_CHEQUING_ACCOUNT 23
#define ADD_SAVINGS_ACCOUNT 24
#define CLOSE_SAVINGS_ACCOUNT 25

#define TURNED_ON_LOGGING 30
#define TURNED_OFF_LOGGING 31

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
