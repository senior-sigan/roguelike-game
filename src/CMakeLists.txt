add_executable(${PROJECT_NAME} game/main.cxx ${HEADERS} ${SOURCES})

target_link_libraries(${PROJECT_NAME} ${CURSES_LIBRARY} ${LOG4CXX_LIBRARIES})