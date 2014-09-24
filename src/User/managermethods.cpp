#include "managermethods.h"
#include"../logger.h"

ManagerMethods::ManagerMethods()
{
}

void ManagerMethods::clearScreen()
{
    cout << "\033[2J\033[1;1H";
    //see http://stackoverflow.com/questions/4062045/clearing-terminal-in-linux-with-c-code

}


void  ManagerMethods::pressEnter(){
    cout << "Press Enter to Continue";
    cin.get();
    cin.get();
}


void ManagerMethods::createUser(){
    string username;
    string password;
    string permissionString;
    long permissions;
    User::User user;

    cout << "Username: ";
    cin >> username;
    cout << endl;

    cout << "User password: ";
    cin >> password;
    cout << endl;

    cout << "User Permissions: " << endl;
    cout << "u - User" << endl;
    cout << "a - Manager" << endl;
    cout << "j - Maintenance" << endl;
    cout << ">";
    cin >> permissionString;
    cout << endl;

    switch(permissionString[0]){
    case 'u':
        permissions = USER_PERMISSION_USER;
        break;
    case 'a':
        permissions = USER_PERMISSION_ADMIN;
        break;
    case 'j':
        permissions = USER_PERMISSION_MAINTENANCE;
        break;
    default:
        cout << "Unknown command";
    }

    Db::Db::Connect();
    User::UserTable::CreateUser(username, password, permissions, user);
    Db::Db::Disconnect();

    pressEnter();

}

void ManagerMethods::deleteUser(){
    string username;
    User::User user;

    cout << "Username to delete";
    cin >> username;

    //db stuff here

    cout << username + " has been deleted" << endl;
    Logger::info("Bank Manager deleted " + user.username);
    pressEnter();
    return;

}

void ManagerMethods::openAccount(){

    string username;
    string accountType;
    User::User user;
    cout << "Username: ";
    cin >> username;
    cout << endl;

    Db::Db::Connect();
    try{
        User::UserTable::GetUser(username, user);
    }catch(int e){
        if(e == USER_NOT_EXIST){
            cout << "User does not exist" << endl;
            pressEnter();
            return;
        }
    }

    Db::Db::Disconnect();

    cout << "Create chequing or savings account? (c or s): ";
    cin >> accountType;
    cout << endl;

    if(accountType == "c"){
        user.cAccountExists=1;
        Db::Db::Connect();
        AccountTable::CreateAccount(user, user.cAccount);
        Db::Db::Disconnect();
        Logger::info("Bank Manager open chequing account for " +user.username);


    }else if(accountType == "s"){
        user.sAccountExists == 1;
        Db::Db::Connect();
        AccountTable::CreateAccount(user, user.sAccount);
        Db::Db::Disconnect();
        Logger::info("Bank Manager open savings account for " +user.username);
    }else {
        cout << "Improper input" << endl;
        return;
    }


}

void ManagerMethods::closeAccount(){
    string username;
    string accountType;
    User::User user;

    cout << "Username: ";
    cin >> username;
    cout << endl;

    Db::Db::Connect();
    try{
        User::UserTable::GetUser(username, user);
    }catch (int e){
        if(e == USER_NOT_EXIST){
            cout << "User does not exist" << endl;
            pressEnter();
            return;
        }
    }

    Db::Db::Disconnect();

    cout << "Close chequing or savings account? (c or s): ";
    cin >> accountType;
    cout << endl;

    if(accountType == "c"){
        if(user.cAccountExists == 0){
            cout << "Chequing account does not exist" << endl;
            pressEnter();
            return;
        }else if(user.cAccount.balance!=0){
            cout << "balance not 0. Cannot close" << endl;
            pressEnter();
            return;
        }else{
            user.cAccountExists = 0;
            //db stuff here;
            cout << "Chequing account closed" << endl;
            Logger::info("Bank Manager closed chequing account for " + user.username);
            pressEnter();
            return;
        }
    }else if(accountType == "s"){
        if(user.sAccountExists == 0){
            cout << "Savings account does not exist" << endl;
            pressEnter();
            return;

        }else if(user.sAccount.balance!=0){
            cout << "balance not 0. Cannot close" << endl;
            pressEnter();
            return;
        }else{
            user.sAccountExists = 0;
            //db stuff here;
            cout << "Savings account closed" << endl;
            Logger::info("Bank Manager closed savings account for " + user.username);
            pressEnter();
            return;
        }
    }else{
        cout << "Improper input" << endl;
        pressEnter();
        return;
    }

    return;

}

void ManagerMethods::getUserDetails(){
    string username;
    User::User user;

    cout << "Username: ";
    cin >> username;
    cout << endl;

    Db::Db::Connect();
    try{
        User::UserTable::GetUser(username, user);
    }catch (int e){
        if (e == USER_NOT_EXIST){
            cout << "User does not exist" << endl;
            pressEnter();
            return;
        }
    }

    Db::Db::Disconnect();

    cout << "user id: " ;
    cout << user.id << endl;
    cout << "username: " + user.username << endl;

    if(user.permissions == USER_PERMISSION_USER){
        if(user.cAccountExists){
            cout << "Chequing Balance: ";
            cout<< user.cAccount.balance << endl;
        }else{
            cout << "No Chequing Account" << endl;
        }
        if(user.sAccountExists){
            cout << "Savings Balance: ";
            cout << user.sAccount.balance << endl;
        }else{
            cout << "No Savings Account" << endl;
        }
    }else if(user.permissions == USER_PERMISSION_ADMIN){
        cout << "Bank Manager" << endl;
    }else if(user.permissions == USER_PERMISSION_MAINTENANCE){
        cout << "Bank Maintenance" << endl;
    }else{
        cout << "No Permissions Set" << endl;
    }

    pressEnter();

}

void ManagerMethods::getAllUserDetails(){

}

void ManagerMethods::managerCommandList(){
    cout << "Enter a command" <<endl;
    cout << "\tu.   Create User" <<endl;
    cout << "\td.   Delete User" <<endl;
    cout << "\to.   Open Account" <<endl;
    cout << "\tc.   Close Account" <<endl;
    cout << "\tg.   Get User Details" <<endl;
    cout << "\ta.   Get All User Details" << endl;
    cout<<  "\tq.   Exit" <<endl <<endl;

    cout<< "> ";
}

void ManagerMethods::managerCommandSelect(User::User &user){
    while(true){
        clearScreen();
        managerCommandList();

        string command;
        cin >> command;

        //Prevent multiple characters from being entered
        if (command.size() != 1) {
            cout << "Unknown command" << endl << endl;
            continue;
        }

        switch(command[0])
        {
        case 'u':
            clearScreen();
            createUser();
            break;


        case 'd':
            clearScreen();
            deleteUser();
            break;

        case 'o':
            clearScreen();
            openAccount();
            break;

        case 'c':
            clearScreen();
            closeAccount();
            break;

        case 'g':
            clearScreen();
            getUserDetails();
            break;

        case 'a':
            clearScreen();
            getAllUserDetails();
            break;

        case 'q':
            return;
            break;
        default:
            cout << "Unknown command" << endl << endl;
        }
    }
}


