/*
 * main.cpp

 *
 *  Created on: Nov 25, 2014
 *      Author: patrick
 */

#include "dispatchloop.h"
int main(int argc, const char* argv[])
{
    //Validate command line
    if (argc > 1)
    {
        PrintHelp(argv[0]);
	return 1;
    }

    //Loop for input and dispatch to the appropriate functions
    //All main logic here
    DispatchLoop();

    return 0;
}



