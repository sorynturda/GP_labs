cmake_minimum_required(VERSION 3.29)
project(proiect)

set(CMAKE_CXX_STANDARD 20)
set(SOURCE_FILES main.cpp Camera.cpp Mesh.cpp Model3D.cpp Shader.cpp tiny_obj_loader.cpp stb_image.cpp Window.cpp)


add_executable(proiect ${SOURCE_FILES})

target_link_libraries(proiect  glfw3 GLEW GL)

file(COPY shaders/ DESTINATION ${CMAKE_BINARY_DIR}/shaders)