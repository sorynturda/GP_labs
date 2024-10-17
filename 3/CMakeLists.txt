cmake_minimum_required(VERSION 3.29)
project(3)

set(CMAKE_CXX_STANDARD 20)
set(SOURCE_FILES main.cpp)

include_directories(/usr/local/include)
link_directories(/usr/local/lib)

add_subdirectory(lib)
add_executable(3 ${SOURCE_FILES})


target_link_libraries(3 glm ncurses OpenGL glfw "-lglfw3 -pthread -lGLEW -lGLU -lGL -lrt -lXrandr -lXxf86vm -lXi -lXinerama -lX11")

file(COPY shaders/ DESTINATION ${CMAKE_BINARY_DIR}/shaders)
