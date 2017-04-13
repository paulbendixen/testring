cmake_minimum_required(VERSION 3.5)
project(ringTest)

set(CMAKE_CXX_STANDARD 14)
include_directories( ../SG14/SG14 )

option( USE_CLANG ON )
set( CMAKE_EXPORT_COMPILE_COMMANDS ON )

set(SOURCE_FILES main.cpp)
add_executable(ringTest ${SOURCE_FILES})
