#ifndef LOGGER_H
#define LOGGER_H
#include <iostream>
#include <fstream>


using namespace std;
class Logger
{

public:
    Logger(){

    }

    static void info(const string& message);

    static void warning(const string& message);

    static void error(const string& message);

    static void setLoggingOnOff(int on);

private:
    static int logginOnOff;

    static void printToFile(const string& message, const string& logLevel);
};

#endif // HTMLLOGGER_H
