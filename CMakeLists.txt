cmake_minimum_required(VERSION 3.16)
project(readini)

set(CMAKE_CXX_STANDARD 14)

include_directories(iniconfig)

add_executable(readini src/main.cpp iniconfig/iniconfig.h iniconfig/iniconfig.cpp iniconfig/inielement.cpp iniconfig/inielement.h)