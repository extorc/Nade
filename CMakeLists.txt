cmake_minimum_required(VERSION 3.8)

add_subdirectory(Nade/vendor/glfw)

project(Nade)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /std:c++17")
set(INC glfw Nade/vendor/glad/include Nade/vendor/stb_image)

file(GLOB_RECURSE SRC Nade/src/*.cpp Nade/src/*.h Nade/src/*/*.cpp Nade/src/*/*.h Nade/vendor/glad/src/glad.c)

add_executable(Nade ${SRC})

target_include_directories(Nade PUBLIC ${INC})
target_link_libraries(Nade PUBLIC glfw)
