cmake_minimum_required(VERSION 3.29)
project(2)

set(CMAKE_CXX_STANDARD 20)
set(SOURCE_FILES main.cpp)

include_directories(/usr/local/include)
link_directories(/usr/local/lib)

add_subdirectory(lib)
add_executable(2 ${SOURCE_FILES})


target_link_libraries(2 glm ncurses OpenGL glfw "-pthread -lGLEW -lGLU -lGL -lrt -lXrandr -lXxf86vm -lXi -lXinerama -lX11")
