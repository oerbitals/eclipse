#include <colours.h>
#include <logger.h>

Logger* Logger::instance = nullptr;

string Logger::timestamp() {
    auto now = std::chrono::system_clock::now();
    time_t to_time = std::chrono::system_clock::to_time_t(now);
    
    std::stringstream ss;
    ss << std::put_time(std::localtime(&to_time), "%Y-%m-%d %X");

    return Colour::dim("[" + ss.str() + "]");
}

string Logger::padLeft(const string& str, short int num, char paddingChar) {
    if (num > str.size()) {
        return string(num - str.size(), paddingChar) + str;
    }
    return str;
}

string Logger::padRight(const string& str, short int num, char paddingChar) {
    if (num > str.size()) {
        return str + string(num - str.size(), paddingChar);
    }
    return str;
}

string Logger::padBoth(const string& str, short int num, char paddingChar) {
    if (num > str.size()) {
        size_t padSize = num - str.size();
        size_t padStart = padSize / 2;
        size_t padEnd = padSize - padStart;
        return string(padStart, paddingChar) + str + string(padEnd, paddingChar);
    }
    return str;
}

string Logger::getTag(LogLevel& logLevel) {
    switch (logLevel) {
        case LogLevel::SILLY:
            return "Silly";
        case LogLevel::INFO:
            return "Info";
        case LogLevel::WARNING:
            return "Warning";
        case LogLevel::ERROR:
            return "Error";
        case LogLevel::FATAL:
            return "Fatal";
        default:
            return "Unknown";
    }
}

Colour::Code Logger::getColour(LogLevel& logLevel) {
    switch (logLevel) {
        case LogLevel::SILLY:
            return Colour::CYAN;
        case LogLevel::INFO:
            return Colour::GREEN;
        case LogLevel::WARNING:
            return Colour::YELLOW;
        case LogLevel::ERROR:
            return Colour::RED;
        case LogLevel::FATAL:
            return Colour::BRIGHT_MAGENTA;
        default:
            return Colour::WHITE;
    }
}

void Logger::write(string& message, LogLevel logLevel) {
    std::ostringstream oss;
    Colour::Code colour = getColour(logLevel);
    string mainMessage = Colour::colour(message, colour);
    string tag = Colour::colour(getTag(logLevel), colour);
    
    oss << padRight(timestamp(), 30) << padRight("[" + tag + "]:", 18) << mainMessage << " " << std::endl;
    std::cout << oss.str();
}

void Logger::silly(string message) {
    write(message, LogLevel::SILLY);
}

void Logger::info(string message) {
    write(message, LogLevel::INFO);
}

void Logger::warning(string message) {
    write(message, LogLevel::WARNING);
}

void Logger::error(string message) {
    write(message, LogLevel::ERROR);
}

void Logger::fatal(string message) {
    write(message, LogLevel::FATAL);
}

void Logger::debug(string message) {
    write(message, LogLevel::DEBUG);
}