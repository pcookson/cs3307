#include "maintenancemethods.h"
#include "../Utilities.h"
#include "../logger.h"


MaintenanceMethods::MaintenanceMethods()
{


}

void MaintenanceMethods::turnOffLogging(User::User& user){
    string confirm;
    cout << "Are you sure you want to turn off logging? (y or n): ";
    cin >> confirm;
    cout << endl;

    if(confirm == "y"){
        Logger::info(user.username + "\tturned off logging");
        Logger::setLoggingOnOff(0);
        cout << "Logging turned off" << endl;
        Utilities::pressEnter();
        return;
    }else if(confirm == "n"){
        cout << "Logging unaffected" << endl;
        Utilities::pressEnter();
        return;
    }



}

void MaintenanceMethods::turnOnLogging(User::User &user){
    string confirm;
    cout << "Are you sure you want to turn on logging? (y or n): ";
    cin >> confirm;
    cout << endl;

    if(confirm == "y"){
        Logger::setLoggingOnOff(1);
        cout << "Logging turned on" << endl;
        Logger::info(user.username + "\tturned on logging");
        Utilities::pressEnter();
        return;
    }else if(confirm == "n"){
        cout << "Logging unaffected" << endl;
        Utilities::pressEnter();
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
        Utilities::clearScreen();
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
            turnOnLogging(user);
            break;

        case 'o':
            turnOffLogging(user);
            break;
        case 'q':
            return;
            break;

        default:
            cout << "Unknown command" << endl << endl;
        }

    }
}
