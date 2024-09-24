#include <iostream>
#include <logger.h>

int main() {
    Logger log = Logger(Logger::LogLevel::INFO);

    log.warning("Hello, Warning!", __FILE__, __LINE__);
    log.silly("Hello, Silly!", __FILE__, __LINE__);
    log.error("Hello, Error!", __FILE__, __LINE__);
    log.fatal("Hello, Fatal!", __FILE__, __LINE__);
    log.info("Hello, Info!", __FILE__, __LINE__);
    
    return 0;
}