cmake_minimum_required(VERSION 3.10)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
PROJECT(Project1)

find_package(X11 REQUIRED)

link_libraries(${X11_LIBRARIES})
include_directories(${X11_INCLUDE_DIR})

find_package(OpenGL REQUIRED)

include_directories(${PROJECT_SOURCE_DIR}/glfw-3.3.8/include/)
include_directories(${PROJECT_SOURCE_DIR}/glad/include/)
include_directories(${PROJECT_SOURCE_DIR}/glm/)


link_libraries(${PROJECT_SOURCE_DIR}/glfw-3.3.8/build/src/libglfw3.a)

file(GLOB SOURCES Shaders/* Model/* Camera/* MeshLoader/* RenderingContext/* Scene/* App/* ImGui/*)

add_executable(Project1 main.cpp glad/src/glad.c ${SOURCES})
