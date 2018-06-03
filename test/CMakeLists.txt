## Set compiler flags to turn off optimization and enable coverage
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -O0 -fprofile-arcs -ftest-coverage")
SET(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -g -O0 -fprofile-arcs -ftest-coverage")

SET(TEST_BIN ${PROJECT_NAME}-unittests)
ADD_EXECUTABLE(${TEST_BIN} ${TESTS} ${SOURCES} ${HEADERS})

target_link_libraries(${TEST_BIN} ${CURSES_LIBRARY} ${LOG4CXX_LIBRARIES})