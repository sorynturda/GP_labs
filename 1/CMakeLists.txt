cmake_minimum_required(VERSION 3.29)
project(1)

set(CMAKE_CXX_STANDARD 20)
set(SOURCE_FILES main.cpp GPSLab1.cpp)

add_subdirectory(lib)
add_executable(1 ${SOURCE_FILES})

#add_executable(1 main.cpp)
target_link_libraries(1 glm ncurses)
