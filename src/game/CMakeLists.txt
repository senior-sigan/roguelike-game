set(PROJECT_NAME game)
set(HEADERS_DIR include)
set(SOURCE_DIR src)

file(GLOB_RECURSE HEADERS ${HEADERS_DIR} *.h)
file(GLOB_RECURSE SOURCES ${SOURCE_DIR} *.cpp)

project(${PROJECT_NAME})

find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIR})

add_executable(${PROJECT_NAME} ${HEADERS} ${SOURCES})

target_include_directories(
    ${PROJECT_NAME} PRIVATE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include/${PROJECT_NAME}>
    $<INSTALL_INTERFACE:include/game>
)

target_include_directories(
    ${PROJECT_NAME} PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
)

target_link_libraries(${PROJECT_NAME} ${CURSES_LIBRARY} ECS)

add_subdirectory(test)