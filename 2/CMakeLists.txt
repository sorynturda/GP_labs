cmake_minimum_required(VERSION 3.29)
project(2)

set(CMAKE_CXX_STANDARD 20)
set(SOURCE_FILES main.cpp)

add_subdirectory(lib)
add_executable(2 ${SOURCE_FILES})

#set(GXX_COVERAGE_COMPILE_FLAGS "-pthread -lGLEW -lGLU -lGL -lrt -lXrandr -lXxf86vm -lXi -lXinerama -lX11")
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${GXX_COVERAGE_COMPILE_FLAGS}" )
#add_compile_options("")

target_link_libraries(2 glm glfw ncurses)
