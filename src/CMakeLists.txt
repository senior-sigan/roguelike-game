add_executable(${PROJECT_NAME} game/main.cxx ${SOURCES} ${HEADERS})

target_link_libraries(${PROJECT_NAME} ${CURSES_LIBRARY} ${LOG4CXX_LIBRARIES})