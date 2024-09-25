# Eclipse
Eclipse is a minimal logger for the rest of my projects. It supports different log levels such as info, warning, and error. The logger includes features like colored output for better readability and timestamps to track when each log entry was created.

# Features possibily to add
These are somethings that I may add to it in the future, though very unlikely.

- [ ] = Not Implemented
- [x] = Implemented

___

- [ ] File and line
- [ ] Get backtrace for errors and print them
- [ ] Customise the logger itself (remove timestamp, customise the timestamp)

# Build
If you'd like to build the project yourself, you'll just need to do the following:

1) clone the repo e.g (git clone https://github.com/oerbitals/eclipse.git)
2) Create a build folder `mkdir build`
3) Change directory to the build dir `cd build`
4) Build the library using cmake `cmake ..`
5) and then run `cmake --build .` to actually build the project

### If you would like to globally install eclipse to use in your projects
### Complete the build steps above and move onto these additional steps:

1) run `sudo cmake --install .`
2) Inside of your CMakeLists.txt, find the package using:

```cmake
cmake_minimum_required(VERSION 3.10)
project(OtherProject)

find_package(eclipse REQUIRED)

target_link_libraries(${PROJECT_NAME} PRIVATE eclipse)
```

# Usage

You can either use the logger like so:
```cpp
#include <eclipse/logger.h>

int main() {
    Logger logger = Logger(LogLevel::INFO); // LogLevel::INFO is optional, default is ERROR

    logger.warning("Hello, Warning!");
    logger.silly("Hello, Silly!");
    logger.error("Hello, Error!");
    logger.fatal("Hello, Fatal!");
    logger.info("Hello, Info!");

    return 0;
}
```

Or create a singleton and not need to create an instance each time:

**main.cpp**
```cpp
#include <eclipse/logger.h>

Logger* logger = logger::get();

int main() {

    logger->warning("Hello, Warning!");
    logger->silly("Hello, Silly!");
    logger->error("Hello, Error!");
    logger->fatal("Hello, Fatal!");
    logger->info("Hello, Info!");

    return 0;
}
```

**somefile.cpp**
```cpp
#include <eclipse/logger.h>

void randomFunction() {

    logger->info("This still works!");
}
```