cmake_minimum_required(VERSION 3.5)
project(ringTest)

set(CMAKE_CXX_STANDARD 14)
include_directories( ../SG14/SG14 )

option( USE_CLANG ON )
set( CMAKE_EXPORT_COMPILE_COMMANDS ON )
set( CMAKE_CXX_FLAGS "-O2 ${CMAKE_CXX_FLAGS}" )
add_definitions( -D_USE_MATH_DEFINES )

set(SOURCE_FILES main.cpp signalTest.cpp signalTest.hpp)
add_executable(ringTest ${SOURCE_FILES})