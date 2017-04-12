cmake_minimum_required(VERSION 3.7)
project(ringTest)

set(CMAKE_CXX_STANDARD 14)
include_directories( ../SG14/SG14 )
option( USE_CLANG ON )
set(SOURCE_FILES main.cpp)
add_executable(ringTest ${SOURCE_FILES})