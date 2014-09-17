#ifndef HTMLLOGGER_H
#define HTMLLOGGER_H
#include <iostream>
#include <fstream>

using namespace std;
class HtmlLogger
{

public:
    HtmlLogger(){

    }

    static void info(const string& message);

    void warning(const string& message);

    void error(const string& message);

    static void setLoggingOnOff(int on);

private:
    static int logginOnOff;
};

#endif // HTMLLOGGER_H
