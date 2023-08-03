#include "Logger.h"
#include "Timestamp.h"
#include <iostream>

 Logger &Logger::instance(){
    static Logger Log;
    return Log;
 }

void  Logger::setLogLevel(int level){
    loglevel_ = level;
}

void Logger::log(std::string msg){
    switch(loglevel_){
        case INFO  : 
            std::cout << "[INFO]" << std::endl; 
            break;
        case ERROR :
            std::cout << "[ERROR]" << std::endl; 
            break;
        case FATAL : 
            std::cout << "[FATAL]" << std::endl; 
            break;
        case DEBUG :
            std::cout << "[DEBUG]" << std::endl; 
            break;

    }

    std::cout << Timestamp::now().ToString() << " : " << msg << std::endl;
}
