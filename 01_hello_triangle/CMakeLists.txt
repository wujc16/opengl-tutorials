cmake_minimum_required(VERSION 3.1)
project(demo)

include_directories(/usr/local/Cellar/glfw/3.3.6/include)
include_directories(../glad/include)

add_executable(demo main.cpp glad.c)

target_link_libraries(
  demo
  /usr/local/Cellar/glfw/3.3.6/lib/libglfw.3.3.dylib
)
