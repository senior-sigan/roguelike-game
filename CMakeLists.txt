cmake_minimum_required(VERSION 3.11)
project(roguelike LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Werror -Wextra -Wno-register -fPIC -march=native")
set(CMAKE_CXX_FLAGS_RELEASE "-O3")
list(APPEND CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/CMake")

find_package(log4cxx REQUIRED)
include_directories(${LOG4CXX_INCLUDE_DIR})

find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIR})

SET(PROJECT_HEADERS_DIR ${PROJECT_SOURCE_DIR}/include/roguelike)
SET(PROJECT_SOURCES_DIR ${PROJECT_SOURCE_DIR}/src)
SET(PROJECT_TESTS_DIR ${PROJECT_SOURCE_DIR}/test)

FILE(GLOB_RECURSE HEADERS ${PROJECT_HEADERS_DIR}/*.h)
FILE(GLOB_RECURSE SOURCES ${PROJECT_SOURCES_DIR}/*.cpp)
FILE(GLOB_RECURSE TESTS ${PROJECT_TESTS_DIR}/*.cpp)

include_directories(${PROJECT_HEADERS_DIR})

add_subdirectory(src)
#add_subdirectory(test)