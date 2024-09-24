#pragma once

#include <string>
#include <iostream>
#include <chrono>
#include <ctime>
#include <iomanip>
#include <sstream>
#include <colours.h>

using std::string;

class Logger {
public:
    enum LogLevel {
        SILLY,
        INFO,
        WARNING,
        ERROR,
        FATAL,
    };

    Logger() {}
    Logger(LogLevel logLevel) : logLevel(logLevel) {}
    ~Logger() {}

    LogLevel getLogLevel() { return logLevel; }
    void setLogLevel(LogLevel logLevel) { this->logLevel = logLevel; }

    string padLeft(const string& str, short int num, char paddingChar = ' ');
    string padRight(const string& str, short int num, char paddingChar = ' ');
    string padBoth(const string& str, short int num, char paddingChar = ' ');

    string getTag(LogLevel& logLevel);
    Colour::Code getColour(LogLevel& logLevel);

    void silly(string message, string file, int line);
    void info(string message, string file, int line);
    void warning(string message, string file, int line);
    void error(string message, string file, int line);
    void fatal(string message, string file, int line);

private:
    LogLevel logLevel = LogLevel::ERROR;
    string timestamp();
    string fileInformation(string file, int line);

    void write(string& message, LogLevel loglevel, string file, int line);

};