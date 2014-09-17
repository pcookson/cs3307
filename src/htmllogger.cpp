#include "htmllogger.h"
#include <time.h>


int HtmlLogger::logginOnOff = 1;

void HtmlLogger::info(const string& message){
    if(logginOnOff){//default is on
        time_t timer = time(NULL);
        ofstream logfile("report.txt", std::ios_base::app | std::ios_base::out);
        //logfile.open("report.txt");

        logfile << timer << " INFO " << message << endl;
    }

}

void HtmlLogger::setLoggingOnOff(int on){
    logginOnOff = on;
}
