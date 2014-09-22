#include <iostream>
#include "User/user.h"
#include "User/usertable.h"
#include "logger.h"
#include <stdlib.h>

using namespace std;

void clearScreen(){
    {
        cout << "\033[2J\033[1;1H";
        //see http://stackoverflow.com/questions/4062045/clearing-terminal-in-linux-with-c-code

    }
}



/*
 * Login function for users
 */

void login(){
    while (true){
        //Command prompt character
        cout << "Username > ";
        string username;
        cin >> username;

        cout << "Password > ";
        string password;
        cin >> password;

        //authenticate user
        User user = User::User();
        try{
            User::UserTable::Authenticate(username, password, user);
        }catch(int e){
            if(e == AUTHENTICATION_FAILURE){
                Logger::warning(username + " attempted to log in. Wrong password or username");
                cout << "Username or Password incorrect. Please try again.";
            }else{
                cout << "An exception has occurred. Please contact the admin.";
            }
        }
        //case user to correct usertype and call correct method for that user
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
            clearScreen();
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

