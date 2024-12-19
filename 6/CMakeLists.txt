cmake_minimum_required(VERSION 3.29)
project(6)

set(CMAKE_CXX_STANDARD 20)
set(SOURCE_FILES Camera.cpp main.cpp Shader.cpp Mesh.cpp Model3D.cpp stb_image.cpp tiny_obj_loader.cpp)


add_executable(6 ${SOURCE_FILES})

target_link_libraries(6  glfw3 GLEW GL)

file(COPY shaders/ DESTINATION ${CMAKE_BINARY_DIR}/shaders)