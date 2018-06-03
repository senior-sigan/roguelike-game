set(TEST_PROJECT_NAME ECS_TEST)
file(GLOB_RECURSE LIBRARY_TEST_SOURCE *.cpp)

project(${TEST_PROJECT_NAME})

add_executable(${TEST_PROJECT_NAME} ${LIBRARY_TEST_SOURCE})
target_link_libraries(${TEST_PROJECT_NAME} ${LIBRARY_NAME})

target_link_libraries(${TEST_PROJECT_NAME} log4cxx)