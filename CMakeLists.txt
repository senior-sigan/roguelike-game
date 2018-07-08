cmake_minimum_required(VERSION 3.11)
project(roguelike LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O0 -Wall -Werror -Wextra -Wno-unused-parameter -fPIC -march=native")
#set(CMAKE_CXX_FLAGS_RELEASE "-O3")

# флаги добавления дебажных символов.
# TODO: унести это в отдельный target, чтобы делать релизные сборки без флагов
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -g")

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

include(CppLint)
ADD_STYLE_CHECK_TARGET(lint ${PROJECT_HEADERS_DIR} ${PROJECT_SOURCES_DIR})