cmake_minimum_required(VERSION 3.14)
project(Nade)

set(CMAKE_CXX_STANDARD_REQUIRED 17)

add_subdirectory(Nade/vendor/glfw)
add_subdirectory(Nade/vendor/assimp)

# GLAD
add_library(GLAD Nade/vendor/glad/src/glad.c)
target_include_directories(GLAD PUBLIC Nade/vendor/glad/include)

# Engine Library
set(ENGINE_LIBS 
    glfw
    assimp
    GLAD
)
file(GLOB NADE_SRC 
    Nade/src/*.cpp 
    Nade/src/*/*.cpp
    Nade/src/*/*/*.cpp
)
add_library(Nade STATIC ${NADE_SRC})
target_link_libraries(Nade PUBLIC ${ENGINE_LIBS})
target_include_directories(Nade PUBLIC
# Fix this later
    Sandbox/
    Nade/src
    Nade/src/Graphics
    Nade/src/Graphics/Components
    Nade/src/Graphics/Loaders
    Nade/src/Core
    Nade/Components
    Nade/vendor/glm
    Nade/vendor/stb_image
)

# Engine Sandbox
add_executable(Sandbox Sandbox/Main.cpp Sandbox/Main.h)
target_include_directories(Sandbox PUBLIC Sandbox/)
target_link_libraries(Sandbox Nade)
