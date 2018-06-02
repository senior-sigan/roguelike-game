set(PROJECT_NAME game)

project(${PROJECT_NAME})

find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIR})

add_executable(${PROJECT_NAME} ncurses_example.cpp)
target_link_libraries(${PROJECT_NAME} ${CURSES_LIBRARY})