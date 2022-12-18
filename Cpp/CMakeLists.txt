cmake_minimum_required(VERSION 3.13)

project(TorusGenerator)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -mavx -O3")

add_library(gentorus SHARED TorusGenerator.cpp)
