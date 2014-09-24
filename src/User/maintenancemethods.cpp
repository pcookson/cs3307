#include "maintenancemethods.h"
#include "../logger.h"


MaintenanceMethods::MaintenanceMethods()
{


}

void MaintenanceMethods::clearScreen(){
    cout << "\033[2J\033[1;1H";
    //see http://stackoverflow.com/questions/4062045/clearing-terminal-in-linux-with-c-code
}

void MaintenanceMethods::pressEnter(){

    cout << "Press Enter to Continue";
    cin.get();
    cin.get();
}

void MaintenanceMethods::turnOffLogging(){
    string confirm;
    cout << "Are you sure you want to turn off logging? (y or n): ";
    cin >> confirm;
    cout << endl;

    if(confirm == "y"){
        Logger::setLoggingOnOff(0);
        cout << "Logging turned off" << endl;
        pressEnter();
        return;
    }else if(confirm == "n"){
        cout << "Logging unaffected" << endl;
        pressEnter();
        return;
    }



}

void MaintenanceMethods::turnOnLogging(){
    string confirm;
    cout << "Are you sure you want to turn on logging? (y or n): ";
    cin >> confirm;
    cout << endl;

    if(confirm == "y"){
        Logger::setLoggingOnOff(1);
        cout << "Logging turned on" << endl;
        pressEnter();
        return;
    }else if(confirm == "n"){
        cout << "Logging unaffected" << endl;
        pressEnter();
        return;
    }
}

void MaintenanceMethods::maintenanceCommandList(){
    cout << "Enter a command" <<endl;
    cout << "\ti.   Turn on logging" << endl;
    cout << "\to.   Turn off logging" << endl;
    cout<<  "\tq.   Exit" <<endl <<endl;

    cout << "> ";


}

void MaintenanceMethods::maintenanceCommandSelect(User::User &user){
    while(true){
        clearScreen();
        maintenanceCommandList();
        string command;
        cin >> command;

        //Prevent multiple characters from being entered
        if (command.size() != 1) {
            cout << "Unknown command" << endl << endl;
            continue;
        }

        switch(command[0])
        {

        case 'i':
            turnOnLogging();
            break;

        case 'o':
            turnOffLogging();
            break;
        case 'q':
            return;
            break;

        default:
            cout << "Unknown command" << endl << endl;
        }

    }
}
