cmake_minimum_required(VERSION 3.13)

project(TorusGenerator)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -mavx")
add_library(gentorus SHARED TorusGenerator.cpp)
