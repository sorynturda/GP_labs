cmake_minimum_required(VERSION 3.29)
project(4)

set(CMAKE_CXX_STANDARD 20)
set(SOURCE_FILES main.cpp Shader.cpp)

add_executable(4 ${SOURCE_FILES})


target_link_libraries(4 GL glfw3 GLEW)

file(COPY shaders/ DESTINATION ${CMAKE_BINARY_DIR}/shaders)