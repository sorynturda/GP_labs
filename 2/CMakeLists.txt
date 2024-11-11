cmake_minimum_required(VERSION 3.29)
project(2)

set(CMAKE_CXX_STANDARD 20)
set(SOURCE_FILES main.cpp)

add_executable(2 ${SOURCE_FILES})


target_link_libraries(2 GLEW GL glfw3)
