cmake_minimum_required(VERSION 3.0.0)

project(opengltemplate)

set(OpenGL_GL_PREFERENCE GLVND)
find_package(OpenGL REQUIRED)

add_executable(
    triangle 
    src/triangle.cpp
    src/glad.h
    src/glad.c    
)

target_link_libraries(triangle glfw)