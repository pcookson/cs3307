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
