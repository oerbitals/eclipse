cmake_minimum_required(VERSION 3.14)
project(eclipse VERSION 0.1.0)

set(PROJECT_VERSION_MAJOR 1)
set(PROJECT_VERSION_MINOR 0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

include_directories(include)

set(SOURCES
    src/logger.cpp
    src/colours.cpp
)

# Create the shared library
add_library(${PROJECT_NAME} SHARED ${SOURCES})
target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_SOURCE_DIR}/include)

# Set the version of the library
set_target_properties(${PROJECT_NAME} PROPERTIES
    VERSION ${PROJECT_VERSION}
    SOVERSION ${PROJECT_VERSION_MAJOR}
)

# Install the library
install(TARGETS ${PROJECT_NAME} DESTINATION lib)
install(DIRECTORY ${PROJECT_SOURCE_DIR}/include/ DESTINATION include/${PROJECT_NAME})

# Generate pkg-config file
configure_file(eclipse.pc.in eclipse.pc @ONLY)
install(FILES ${CMAKE_BINARY_DIR}/eclipse.pc DESTINATION /usr/lib/pkgconfig)