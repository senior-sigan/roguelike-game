# - Try to find BearLibTerminal
# Once done this will define
#  BLT_FOUND - System has BearLibTerminal
#  BLT_INCLUDE_DIRS - The BearLibTerminal include directories
#  BLT_LIBRARIES - The libraries needed to use BearLibTerminal
#  BLT_DEFINITIONS - Compiler switches required for using BearLibTerminal

# Find out if this is a 32 or 64 bit build
if( CMAKE_SIZEOF_VOID_P EQUAL 8)
    MESSAGE(STATUS "64 bit system detected.")
    SET( EX_PLATFORM 64)
    SET( EX_PLATFORM_NAME "x64")
else ()
    MESSAGE(STATUS "32 bit system detected.")
    SET( EX_PLATFORM 32)
    SET( EX_PLATFORM_NAME "x86")
endif ()

# Set the proper directory
if(${CMAKE_SYSTEM_NAME} MATCHES "Darwin")
    set(LIB_PATHS "${CMAKE_SOURCE_DIR}/lib/BearLibTerminal/OSX")
elseif (${CMAKE_SYSTEM_NAME} MATCHES "Windows")
    set(LIB_PATHS "${CMAKE_SOURCE_DIR}/lib/BearLibTerminal/Windows${EX_PLATFORM}")
else ()
    set(LIB_PATHS "${CMAKE_SOURCE_DIR}/lib/BearLibTerminal/Linux${EX_PLATFORM}")
endif ()

# Find the headers
find_path(BLT_INCLUDE_DIR BearLibTerminal.h
        PATHS "${CMAKE_SOURCE_DIR}/lib/BearLibTerminal/include")

# Find the library
if (${CMAKE_SYSTEM_NAME} MATCHES "Windows")
    # Windows doesn't automatically include both .lib and .dll
    #if (MSVC)
    set(CMAKE_FIND_LIBRARY_SUFFIXES ".lib")
    #else ()
    #    set(CMAKE_FIND_LIBRARY_SUFFIXES ".dll")
    #endif ()
    find_library(BLT_LIBRARY NAME BearLibTerminal PATHS ${LIB_PATHS})
else (${CMAKE_SYSTEM_NAME} MATCHES "Windows")
    find_library(BLT_LIBRARY NAME BearLibTerminal PATHS ${LIB_PATHS})
endif (${CMAKE_SYSTEM_NAME} MATCHES "Windows")

# No compiler switches necessary
set(BLT_DEFINITIONS "")

# Handle _FOUND tags and print success/failure
include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(BLT DEFAULT_MSG BLT_LIBRARY BLT_INCLUDE_DIR)

# Don't display in GUI
mark_as_advanced(BLT_LIBRARY BLT_INCLUDE_DIR)

# No dependencies, so proceed.
set(BLT_INCLUDE_DIRS ${BLT_INCLUDE_DIR})
set(BLT_LIBRARIES ${BLT_LIBRARY})
set(BLT_DLL "${LIB_PATHS}/BearLibTerminal.dll")