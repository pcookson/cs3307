#include <iostream>

#ifndef USER_H_
#define USER_H_

#define AUTHENTICATION_FAILURE 0x0
#define AUTHENTICATION_SUCCESS 0x1

using namespace std;

class User
{
public:
    string username;
    string password;
    
    User(string username);
    long Authenticate(string password);


private:




};

#endif  // USER_H_
