#pragma once


#include "noncopyable.h"
#include <string>

#define LOG_SIZE 1024

// LOG_INFO("%s %d", arg1, arg2)
#define LOG_INFO(LogmsgFormat, ...) \
    do \
    { \
        Logger &logger = Logger::instance(); \
        logger.setLogLevel(INFO); \
        char buf[LOG_SIZE] ={0}; \
        snprintf(buf, LOG_SIZE, LogmsgFormat, ##__VA_ARGS__); \
        logger.log(buf); \
    }while(0)

#define LOG_ERROR(LogmsgFormat, ...) \
    do \
    { \
        Logger &logger = Logger::instance(); \
        logger.setLogLevel(ERROR); \
        char buf[LOG_SIZE] ={0}; \
        snprintf(buf, LOG_SIZE, LogmsgFormat, ##__VA_ARGS__); \
        logger.log(buf); \
    }while(0)

#define LOG_FATAL(LogmsgFormat, ...) \
    do \
    { \
        Logger &logger = Logger::instance(); \
        logger.setLogLevel(FATAL); \
        char buf[LOG_SIZE] ={0}; \
        snprintf(buf, LOG_SIZE, LogmsgFormat, ##__VA_ARGS__); \
        logger.log(buf); \
        exit(-1); \
    }while(0)

#ifdef MUDEBUG
#define LOG_DEBUG(LogmsgFormat, ...) \
    do \
    { \
        Logger &logger = Logger::instance(); \
        logger.setLogLevel(DEBUG); \
        char buf[LOG_SIZE] ={0}; \
        snprintf(buf, LOG_SIZE, LogmsgFormat, ##__VA_ARGS__); \
        logger.log(buf); \
    }while(0)
#else
#define LOG_DEBUG(LogmsgFormat, ...)
#endif


enum LogLevel {
    INFO, //pu tong xin xi
    ERROR, //
    FATAL, //
    DEBUG, //
};


class Logger : noncopyable {
public:
    static Logger &instance();

    void setLogLevel(int level);

    void log(std::string);

private:
    int loglevel_;
};