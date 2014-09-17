#include "logger.h"
#include <time.h>


int Logger::logginOnOff = 1;

void Logger::info(const string& message){
    printToFile(message, "INFO");

}

void Logger::warning(const string& message){
    printToFile(message, "WARNING");
}

void Logger::error(const string& message){
    printToFile(message, "ERROR");
}

void Logger::printToFile(const string& message, const string& logLevel){
    if(logginOnOff){//default is on
        time_t timer = time(NULL);
        ofstream logfile("report.txt", std::ios_base::app | std::ios_base::out);

        logfile << timer << "\t" << logLevel << "\t" << message << endl;
    }

}

void Logger::setLoggingOnOff(int on){
    logginOnOff = on;
}
