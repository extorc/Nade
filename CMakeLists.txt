cmake_minimum_required(VERSION 3.8)

add_subdirectory(Nade/vendor/glfw)
add_subdirectory(Nade/vendor/assimp)

project(Nade)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /std:c++17")

set(INC 
glfw
Nade/vendor/glad/include
Nade/vendor/stb_image
Nade/vendor/glm/glm
Nade/src
assimp
)

set(LIBS glfw assimp)

file(GLOB_RECURSE SRC Nade/src/*.cpp Nade/src/*.h Nade/src/*/*.cpp Nade/src/*/*.h Nade/vendor/glad/src/glad.c)
add_executable(Nade ${SRC})

target_include_directories(Nade PUBLIC ${INC})
target_link_libraries(Nade PUBLIC ${LIBS})