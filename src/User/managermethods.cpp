#include "managermethods.h"
#include"../logger.h"
#include <vector>

using namespace std;

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

    cout << "Username to delete: ";
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

    if(user.id == 0){
        cout << "User does not exist" << endl;
        pressEnter();
        return;
    }

    if(user.cAccount.id && !user.cAccount.balance){
        cout << "Chequing account balance not 0. Cannot delete user" << endl;
        pressEnter();
        return;
    }else if(user.sAccount.id && !user.sAccount.balance){
        cout << "Chequing account balance not 0. Cannot delete user" << endl;
        pressEnter();
        return;

    }else{

        Db::Db::Connect();
        User::UserTable::DeleteUser(username);
        Db::Db::Disconnect();

        cout << username + " has been deleted" << endl;
        Logger::info("Bank Manager deleted " + user.username);
        pressEnter();
        return;
    }

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
        }else{
            //do nothing all is well
        }
    }

    if(user.id == 0){
        cout << "User does not exist" << endl;
        pressEnter();
        return;
    }

    if(user.permissions != USER_PERMISSION_USER){
        cout << "This user is not a customer" << endl;
        pressEnter();
        return;
    }

    Db::Db::Disconnect();

    cout << "Create chequing or savings account? (c or s): ";
    cin >> accountType;
    cout << endl;

    if(accountType == "c"){

        Db::Db::Connect();
        try{
            AccountTable::CreateAccount(user, CHEQUING_ACCOUNT);
        }catch(int e){
            cout << "An error occurred ";
            cout << e;
            pressEnter();

            return;
        }

        Db::Db::Disconnect();
        Logger::info("Bank Manager open chequing account for " +user.username);
        cout << "Chequing account created for " << user.username << endl;
        pressEnter();
        return;

    }else if(accountType == "s"){

        Db::Db::Connect();
        try{
            AccountTable::CreateAccount(user, SAVINGS_ACCOUNT);
        }catch(int e){
            cout << "An error occurred ";
            cout << e;
            pressEnter();

            return;
        }

        Db::Db::Disconnect();
        Logger::info("Bank Manager open savings account for " +user.username);
        cout << "Savings account created for " << user.username << endl;
        pressEnter();
        return;
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

    if (user.permissions != USER_PERMISSION_USER){
        cout << "This user is not a customer and has no accounts" << endl;
        pressEnter();
        return;
    }

    if(user.id == 0){
        cout << "User does not exist" << endl;
        pressEnter();
        return;
    }

    Db::Db::Disconnect();

    cout << "Close chequing or savings account? (c or s): ";
    cin >> accountType;
    cout << endl;

    if(accountType == "c"){
        if(!user.cAccount.id){
            cout << "Chequing account does not exist" << endl;
            pressEnter();
            return;
        }else if(user.cAccount.balance!=0){
            cout << "balance not 0. Cannot close" << endl;
            pressEnter();
            return;
        }else{
            Db::Db::Connect();
            AccountTable::DeleteAccount(user.cAccount);
            Db::Db::Disconnect();
            cout << "Chequing account closed" << endl;
            Logger::info("Bank Manager closed chequing account for " + user.username);
            pressEnter();
            return;
        }
    }else if(accountType == "s"){
        if(!user.sAccount.id){
            cout << "Savings account does not exist" << endl;
            pressEnter();
            return;

        }else if(user.sAccount.balance!=0){
            cout << "balance not 0. Cannot close" << endl;
            pressEnter();
            return;
        }else{
            Db::Db::Connect();
            AccountTable::DeleteAccount(user.sAccount);
            Db::Db::Disconnect();

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


    if(user.id == 0){
        cout << "User does not exist" << endl;
        pressEnter();
        return;
    }

    Db::Db::Disconnect();

    cout << "user id: " ;
    cout << user.id << endl;
    cout << "username: " + user.username << endl;


    if(user.permissions == USER_PERMISSION_USER){
        cout << "bank customer" << endl;
        if(user.cAccount.id){

            cout << "Chequing Balance: ";
            cout<< user.cAccount.balance << endl;
        }else{
            cout << "No Chequing Account" << endl;
        }
        if(user.sAccount.id){

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
    vector<User::User> users;
    Db::Db::Connect();
    User::UserTable::GetAllUsers(users);
    Db::Db::Disconnect();


    for(vector<User::User>::iterator it = users.begin(); it != users.end(); ++it){
        string role;
        if ((*it).permissions == USER_PERMISSION_USER){
            role = "bank customer";
        }else if ((*it).permissions == USER_PERMISSION_ADMIN){
            role = "Bank Manager";
        }else if((*it).permissions == USER_PERMISSION_MAINTENANCE){
            role = "Maintenance";
        }else{
            role = "undefined";
        }


        cout << "**************************************************" << endl;
        cout << "username: " << (*it).username << endl;
        cout << "user id: " << (*it).id << endl;
        cout << "role: " << role <<endl;
        if (!(*it).cAccount.id){
            cout << "Chequing Balance: No chequing account" << endl;
        }else{
            cout << "Chequing Balance: " << (*it).cAccount.balance << endl;
        }

        if (!(*it).sAccount.id){
            cout << "Savings Balance: No savings account" << endl;
        }else{
            cout << "Savings Balance: " << (*it).sAccount.balance << endl;
        }

    }

    pressEnter();
    return;

}

void ManagerMethods::managerCommandList(){
    cout << "Enter a command" <<endl;
    cout << "\tu.   Create User" <<endl;
    cout << "\td.   Delete User" <<endl;
    cout << "\to.   Open Account" <<endl;
    cout << "\tc.   Close Account" <<endl;
    cout << "\tg.   Get User Details" <<endl;
    cout << "\ta.   Get Details Of All Users" << endl;
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


