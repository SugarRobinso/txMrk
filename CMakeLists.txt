cmake_minimum_required(VERSION 3.18)

project(marktext)

set(CMAKE_CXX_STANDARD 14)
set(EXECUTABLE_OUTPUT_PATH bin)

add_executable(marktext src/md_parser.cpp src/head.cpp)