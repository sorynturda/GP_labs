cmake_minimum_required(VERSION 3.29)
project(7)

set(CMAKE_CXX_STANDARD 20)
set(SOURCE_FILES main.cpp Shader.cpp Model3D.cpp Mesh.cpp stb_image.cpp tiny_obj_loader.cpp Camera.cpp)


add_executable(7 ${SOURCE_FILES})


target_link_libraries(7  glfw3 GLEW GL)

file(COPY shaders/ DESTINATION ${CMAKE_BINARY_DIR}/shaders)