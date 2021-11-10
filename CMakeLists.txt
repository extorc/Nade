cmake_minimum_required(VERSION 3.8)

add_subdirectory(Nade/vendor/glfw)

project(Nade)

add_executable(Nade
Nade/src/Nade.h
Nade/src/Entrypoint.cpp	
Nade/src/Core/Window.h
Nade/src/Core/Window.cpp
)

target_include_directories(Nade PUBLIC glfw)
target_link_libraries(Nade PUBLIC glfw)
