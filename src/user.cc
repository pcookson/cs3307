#include <iostream>
#include "user.h"

using namespace std;

User::User(string username) {
    User::username = username;
}

long User::Authenticate(string password) {
    if (password.compare(User::password) != 0) {
        throw AUTHENTICATION_FAILURE;
    }
      
    return AUTHENTICATION_SUCCESS;
}

void logger(int logInt){
    string username = "patrick";
    User user = User(username);
    switch(logInt){
    case ACCEPTS_FEE:
        Logger::info(user.username + " accepted fee for withdrawl");
        break;
    case DECLINES_FEE:
        Logger::warning(user.username + " declines fee for withdrawl");
    case WITHDRAW_SUCCESSFUL:
        Logger::info("successfully withdrew money from account");
        break;
    case WITHDRAW_FAILURE:
        Logger::info("failed to withdraw money");
        break;

    case DEPOSIT_FAILURE:
        Logger::info("failed to deposit money");
        break;
    case DEPOSIT_SUCCESS:
        Logger::info("successfully deposited money");
        break;
    default:
        Logger::error("fell through logging switch statement");
    }
}
