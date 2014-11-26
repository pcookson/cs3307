#include <iostream>
#include "usermethods.h"
#include "dispatchloop.h"
#include "../User/user.h"
#include "../User/usertable.h"
#include "../logger.h"
#include "../Utilities.h"
#include <stdlib.h>

using namespace std;


/*
 * Login function for users
 */

void login(){
    Db::Db::Connect();
    User::User user;
    while (true){

        cout << "Username > ";
        string username;
        cin >> username;

        cout << "Password > ";
        string password;
        cin >> password;


        //authenticate user

        try{
            User::UserTable::Authenticate(username, password, user);
        }catch(int e){
            if(e == AUTHENTICATION_FAILURE){
                cout << "Username or Password incorrect." << endl;
                return;
            }else{
                cout << "An exception has occurred. Please contact the admin." <<endl;
                return;
            }
        }
        Db::Db::Disconnect();

        //see permissions and call correct method for that user
        if(user.permissions == USER_PERMISSION_USER){
            usermethods::userCommandSelect(user);
        }else if(user.permissions == USER_PERMISSION_ADMIN){
            return;
        }else if(user.permissions == USER_PERMISSION_MAINTENANCE){
            return;
        }else{
            //throw no permissions error here
        }

        return;
    }

}



/*
 * Prints a list of available commands
 */
void CommandList() {
    cout << "Enter a command: " << endl;
    cout << "\tq.  Exit" << endl << endl;
    cout << "\tl.  Login" << endl << endl;

    //Command prompt character
    cout << "> ";
}

/**
 * Command loop for input and dispatching to the appropriate path
 */
void DispatchLoop() {

    while(true)
    {
        CommandList();

        string command;
        cin >> command;

        //Prevent multiple characters from being entered
        if (command.size() != 1) {
            cout << "Unknown command" << endl << endl;
            continue;
        }

        switch(command[0])
        {

        case 'l':
            Utilities::clearScreen();
            login();
            break;

        case 'q':
            return;
            break;




        default:
            cout << "Unknown command" << endl << endl;
        }



    }

}

