cmake_minimum_required(VERSION 3.14)

project(eclipse VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(SRC_DIR src)
set(INCLUDE_DIR include)

file(GLOB_RECURSE CPP_FILES "${SRC_DIR}/*.cpp")
file(GLOB_RECURSE HPP_FILES "${INCLUDE_DIR}/*.h")

include_directories(${INCLUDE_DIR})
include_directories(${SRC_DIR})

add_executable(${PROJECT_NAME} ${CPP_FILES} ${HPP_FILES})