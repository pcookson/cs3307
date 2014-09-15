#include <iostream>

using namespace std;

/*
 * Prints a list of available commands
 */
void CommandList() {
    cout << "Enter a command: " << endl;
    cout << "\tq.  Exit" << endl << endl;

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
            case 'q':
                return;

            default:
                cout << "Unknown command" << endl << endl;
        }

	

    }

}

