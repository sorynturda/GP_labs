cmake_minimum_required(VERSION 3.29)
project(5)

set(CMAKE_CXX_STANDARD 20)
set(SOURCE_FILES Camera.cpp main.cpp Shader.cpp)


add_executable(5 ${SOURCE_FILES})

target_link_libraries(5  glfw3 GLEW GL)

file(COPY shaders/ DESTINATION ${CMAKE_BINARY_DIR}/shaders)