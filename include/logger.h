#pragma once

#include <iostream>
#include <chrono>
#include <ctime>
#include <iomanip>
#include <sstream>
#include "colours.h"

enum LogLevel {
        FATAL,
        ERROR,
        WARNING,
        INFO,
        DEBUG,
        SILLY,
};

class Logger {
public:

    Logger() {}
    Logger(LogLevel logLevel) : logLevel(logLevel) {}
    ~Logger() { delete instance; }

    LogLevel getLogLevel() { return logLevel; }
    void setLogLevel(LogLevel logLevel) { this->logLevel = logLevel; }

    static Logger* get() {
        if (instance == nullptr) {
            instance = new Logger();
        }
        return instance;
    }

    static void destroy() {
        if (instance != nullptr) {
            delete instance;
            instance = nullptr;
        }
    }

    string padLeft(const string& str, short int num, char paddingChar = ' ');
    string padRight(const string& str, short int num, char paddingChar = ' ');
    string padBoth(const string& str, short int num, char paddingChar = ' ');

    string getTag(LogLevel& logLevel);
    Colour::Code  getColour(LogLevel& logLevel);

    void fatal(string message);
    void error(string message);
    void warning(string message);
    void info(string message);
    void debug(string message);
    void silly(string message);

private:
    LogLevel logLevel = LogLevel::INFO;
    static Logger* instance;
    string timestamp();

    void write(string& message, LogLevel loglevel);

};

extern Logger* logger;