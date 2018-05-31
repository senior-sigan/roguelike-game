cmake_minimum_required(VERSION 3.11)
project(roguelike)

set(CMAKE_CXX_STANDARD 17)
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Werror -Wextra -Wno-register -fPIC -march=native")
set(CMAKE_CXX_FLAGS_RELEASE "-O3")
set(TARGET roguelike)

add_subdirectory(src/EntityComponentSystem)
add_subdirectory(src/game)