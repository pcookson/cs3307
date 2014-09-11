#include <iostream>

using namespace std;

//Forward declarations
void DispatchLoop();

/**
 * Prits the introduction banner
 */
void PrintBanner() {
	cout << "Assignment 1 by Patrick Cookson and James Baron" << endl << endl;
}

/**
 * Prints instructions for how to run the application
 * 
 * exe_name: the name of the executable
 */
void PrintHelp(const char* exe_name) {
    cout << "Usage:" << endl << '\t' << exe_name << endl << endl;
}


int main(int argc, const char* argv[])
{
    PrintBanner();

    //Validate command line
    if (argc > 1)
    {
        PrintHelp(argv[0]);
	return 1;		
    }
    
    DispatchLoop();

    return 0;
}

