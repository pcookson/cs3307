#include <iostream>
#include "../Account/chequingaccount.h"
#include "../Account/savingsaccount.h"
#include "usermethods.h"
#include "../Account/fundmovementvalidation.h"
#include "usertable.h"
#include "../logger.h"
#include "../Utilities.h"
#include <stdlib.h>


void UserMethods::clearScreen(){
    {
        cout << "\033[2J\033[1;1H";
        //see http://stackoverflow.com/questions/4062045/clearing-terminal-in-linux-with-c-code

    }
}

void  UserMethods::pressEnter(){
    cout << "Press Enter to Continue";
    cin.get();
    cin.get();
}

void UserMethods::balance(User::User &user){
    Logger::info(user.username +"\tchecked balance");

    cout << "Chequing Balance: ";
    cout << user.cAccount.balance << endl <<endl;

    cout << "Savings Balance: ";
    cout << user.sAccount.balance << endl << endl;
    pressEnter();

}

void UserMethods::deposit(User::User &user){


    string accountDeposit;
    double amount;
    string amountString;

    do{
        cout << "Which account to depost to?" << endl;
        cout << "Chequing (c) or Savings (s)?" <<endl;
        cout << "> ";

        cin >> accountDeposit;
    }while(accountDeposit!= "c" && accountDeposit!= "s");

    if(accountDeposit == "c"){
        if (user.cAccountExists == 0){
            cout << "Warning: Chequing account does not exist. Request account from a manager" << endl;
            pressEnter();
            return;
        }
    }else if(accountDeposit == "s"){
        if(user.sAccountExists == 0){
            cout << "Warning: Savings account does not exist. Request account from manager" << endl;
            pressEnter();
            return;
        }else if(accountDeposit == "q"){
            return;
        }
    }
    cout << "How much to deposit?" << endl;
    cout << "> ";
    cin >> amount;

    switch(accountDeposit[0]){
    case 'c':
        amountString = Utilities::double_to_string(amount);

        try{
        FundMovementValidation::deposit(user.cAccount, amount);
    }catch (int e){
            Logger::log(DEPOSIT_FAILURE, user.username, amount, "chequing");
        }
        Logger::log(DEPOSIT_SUCCESS, user.username, amount, "chequing");
        return;
        break;
    case 's':
        amountString = Utilities::double_to_string(amount);

        try{
        FundMovementValidation::deposit(user.sAccount, amount);
    }catch (int e){
            Logger::log(DEPOSIT_FAILURE, user.username, amount, "chequing");
        }
        Logger::log(DEPOSIT_SUCCESS, user.username, amount, "savings");

        return;
        break;
    default:
        cout <<"Unknown command" << endl;
    }
}

void UserMethods::withdraw(User::User &user){
    string accountWithdraw;
    string amountString;

    double amount;

    do{
        cout << "Which account to withdraw from?" << endl;
        cout << "Chequing (c) or Savings (s)?" <<endl;
        cout << "> ";

        cin >> accountWithdraw;
    }while(accountWithdraw != "c" && accountWithdraw != "s");

    if(accountWithdraw == "c"){
        if (user.cAccountExists == 0){
            cout << "Warning: Chequing account does not exist. Request account from a manager" << endl;
            pressEnter();
            return;
        }
    }else if(accountWithdraw == "s"){
        if(user.sAccountExists == 0){
            cout << "Warning: Savings account does not exist. Request account from manager" << endl;
            pressEnter();
            return;
        }else if(accountWithdraw == "q"){
            return;
        }
    }
    cout << "How much to withdraw?" << endl;
    cout << "> ";
    cin >> amount;




    switch(accountWithdraw[0]){
    case 'c':
        amountString = Utilities::double_to_string(amount);

        try{
        FundMovementValidation::withdraw(user.cAccount, amount);
    }catch (int e){
            Logger::log(WITHDRAW_FAILURE, user.username, amount, "chequing");
        }

        Logger::log(WITHDRAW_SUCCESSFUL, user.username, amount, "chequing");
        return;
        break;
    case 's':
        amountString = Utilities::double_to_string(amount);
        try{
        FundMovementValidation::withdraw(user.sAccount, amount);
    }catch (int e){
            Logger::log(WITHDRAW_FAILURE, user.username, amount, "savings");
        }
        Logger::log(WITHDRAW_SUCCESSFUL, user.username, amount, "savings");
        return;
        break;
    default:
        cout <<"Unknown command" << endl;
    }




}

void UserMethods::transferFunds(User::User &user){
    string amountString;
    string accountTransfer;
    string otherUserName;

    string otherAccount;

    double amount;

    do{
        cout << "Which account to transfer from?" << endl;
        cout << "Chequing (c) or Savings (s)?" <<endl;
        cout << "> ";

        cin >> accountTransfer;
    }while(accountTransfer!= "c" && accountTransfer!= "s");

    if(accountTransfer == "c"){
        if (user.cAccountExists == 0){
            cout << "Warning: Chequing account does not exist. Request account from a manager" << endl;
            pressEnter();
            return;
        }
    }else if(accountTransfer == "s"){
        if(user.sAccountExists == 0){
            cout << "Warning: Savings account does not exist. Request account from manager" << endl;
            pressEnter();
            return;
        }else if(accountTransfer == "q"){
            return;
        }
    }
    cout << "How much to transfer?" << endl;
    cout << "> ";
    cin >> amount;

    cout<< "Username of person to transfer to?" << endl;
    cout << "> ";
    cin >> otherUserName;

    User::User otherUser;
    Db::Db::Connect();
    User::UserTable::GetUser(otherUserName, otherUser);
    if(otherUser.username != otherUserName){
        cout << otherUserName + " does not exist" << endl;
        pressEnter();
        return;
    }
    Db::Db::Disconnect();
    cout << "Account to transfer to?" << endl;
    cout << "> ";
    cin >> otherAccount;



    switch(accountTransfer[0]){
    case 'c':
        if(otherAccount == "c"){
            amountString = Utilities::double_to_string(amount);
            Logger::info(user.username + "\ttransferred " + amountString + " from chequing account to " + otherUserName + " "+ otherAccount );
            FundMovementValidation::transferFunds(user.cAccount, otherUser.cAccount, amount);
        }else{
            amountString = Utilities::double_to_string(amount);
            Logger::info(user.username + "\ttransferred " + amountString + " from chequing account to " + otherUserName + " "+ otherAccount );
            FundMovementValidation::transferFunds(user.cAccount, otherUser.sAccount, amount);
        }
        return;
        break;
    case 's':
        if(otherAccount == "c"){
            amountString = Utilities::double_to_string(amount);
            Logger::info(user.username + "\ttransferred " + amountString + " from saving account to " + otherUserName + " "+ otherAccount );
            FundMovementValidation::transferFunds(user.sAccount, otherUser.cAccount, amount);
        }else{
            amountString = Utilities::double_to_string(amount);
            Logger::info(user.username + "\ttransferred " + amountString + " from saving account to " + otherUserName + " "+ otherAccount );
            FundMovementValidation::transferFunds(user.sAccount, otherUser.sAccount, amount);
        }

        return;
        break;
    default:
        cout <<"Unknown command" << endl;
        pressEnter();
        return;
    }



}

void UserMethods::userCommandList(){
    cout << "Enter a command" <<endl;
    cout << "\tb.   Balances" <<endl;
    cout << "\tw.   Withdraw" <<endl;
    cout << "\td.   Deposit" <<endl;
    cout << "\tt.   Transfer" <<endl;
    cout<<  "\tq.   Exit" <<endl <<endl;

    cout<< "> ";

}

void UserMethods::userCommandSelect(User::User &user){
    Logger::info(user.username + " successfully logged in");
    while(true){
        clearScreen();
        userCommandList();

        string command;
        cin >> command;

        //Prevent multiple characters from being entered
        if (command.size() != 1) {
            cout << "Unknown command" << endl << endl;
            continue;
        }

        switch(command[0])
        {
        case 'b':
            clearScreen();
            balance(user);
            break;


        case 'w':
            clearScreen();
            withdraw(user);
            break;

        case 'd':
            clearScreen();
            deposit(user);
            break;

        case 't':
            clearScreen();
            transferFunds(user);
            break;

        case 'q':
            clearScreen();
            return;
            break;
        default:
            cout << "Unknown command" << endl << endl;
        }
    }
}
