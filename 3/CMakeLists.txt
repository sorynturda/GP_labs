cmake_minimum_required(VERSION 3.29)
project(3)

set(CMAKE_CXX_STANDARD 20)
set(SOURCE_FILES main.cpp)

add_executable(3 ${SOURCE_FILES})


target_link_libraries(3 GLEW GL glfw3)

file(COPY shaders/ DESTINATION ${CMAKE_BINARY_DIR}/shaders)
