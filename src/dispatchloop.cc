#include <iostream>
#include "User/user.h"
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

        clearScreen();
        return;
    }
    //authenticate user
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

