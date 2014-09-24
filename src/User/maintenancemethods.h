#ifndef MAINTENANCEMETHODS_H
#define MAINTENANCEMETHODS_H

#include "user.h"
class MaintenanceMethods
{
public:
    MaintenanceMethods();

    /** @brief turns on or off logging
     *
     * @param user passes maintenance user through
     */
    static void turnOnLogging(User::User &user);

    /** @brief turns off logging
     *
     * @param user passes maintenance user through
     */
    static void turnOffLogging(User::User &user);

    /** @brief the selection list for maintenance user
     *
     * @param user passes user through
     */
    static void maintenanceCommandSelect(User::User &user);

    /** @brief the list of commands available
     *
     */
    static void maintenanceCommandList();

private:
   static void pressEnter();

    static void clearScreen();
};

#endif // MAINTENANCEMETHODS_H
