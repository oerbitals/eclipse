# Eclipse
Eclipse is a minimal logger for the rest of my projects. It supports different log levels such as info, warning, and error. The logger includes features like colored output for better readability and timestamps to track when each log entry was created.

# Todo
- [ ] Remove the __FILE__ and __LINE__ and automatically grab the file/line itself.
- [ ] Add singleton design or std::atomic to prevent threads raising undefined behaviour


# Usage
```cpp
#include "logger.h"

int main() {
    Logger log = Logger(Logger::LogLevel::INFO);

    log.warning("Hello, Warning!", __FILE__, __LINE__);
    log.silly("Hello, Silly!", __FILE__, __LINE__);
    log.error("Hello, Error!", __FILE__, __LINE__);
    log.fatal("Hello, Fatal!", __FILE__, __LINE__);
    log.info("Hello, Info!", __FILE__, __LINE__);
    return 0;
}
```