#ifndef MAINTENANCEMETHODS_H
#define MAINTENANCEMETHODS_H

#include "user.h"
class MaintenanceMethods
{
public:
    MaintenanceMethods();

    static void turnOnLogging(User::User &user);

    static void turnOffLogging(User::User &user);

    static void maintenanceCommandSelect(User::User &user);

    static void maintenanceCommandList();

private:
   static void pressEnter();

    static void clearScreen();
};

#endif // MAINTENANCEMETHODS_H
