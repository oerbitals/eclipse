#pragma once

#include <string>
#include <iostream>
#include <chrono>
#include <ctime>
#include <iomanip>
#include <sstream>
#include <colours.h>

using std::string;

enum LogLevel {
        SILLY,
        INFO,
        WARNING,
        ERROR,
        FATAL,
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
    Colour::Code getColour(LogLevel& logLevel);

    void silly(string message);
    void info(string message);
    void warning(string message);
    void error(string message);
    void fatal(string message);

private:
    LogLevel logLevel = LogLevel::ERROR;
    static Logger* instance;
    string timestamp();

    void write(string& message, LogLevel loglevel);

};

extern Logger* logger;