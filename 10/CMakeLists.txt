cmake_minimum_required(VERSION 3.29)
project(10)

set(CMAKE_CXX_STANDARD 20)
set(SOURCE_FILES main.cpp SkyBox.cpp Camera.cpp Mesh.cpp Model3D.cpp Shader.cpp stb_image.cpp tiny_obj_loader.cpp)


add_executable(10 ${SOURCE_FILES})

target_link_libraries(10  glfw3 GLEW GL)

file(COPY shaders/ DESTINATION ${CMAKE_BINARY_DIR}/shaders)