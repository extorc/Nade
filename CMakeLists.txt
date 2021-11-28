cmake_minimum_required(VERSION 3.14)
project(Nade)

set(CMAKE_CXX_STANDARD_REQUIRED 17)
set(ASSIMP_BUILD_TESTS OFF)
set(ASSIMP_BUILD_DOCS OFF)
set(ASSIMP_NO_EXPORT ON)
set(ASSIMP_BUILD_ALL_EXPORTERS_BY_DEFAULT OFF)
set(ASSIMP_BUILD_ALL_IMPORTERS_BY_DEFAULT OFF)
set(-DASSIMP_BUILD_OBJ_IMPORTER ON)

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
    Nade/src/*.h 
    Nade/src/*/*.h
    Nade/src/*/*/*.h
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
    Nade/src/Core/Events
    Nade/src/Core/Input
    Nade/src/Core/Physics
    Nade/src/Components
    Nade/vendor/glm
    Nade/vendor/stb_image
)
target_precompile_headers(Nade PUBLIC "Nade/src/Core/pch.h")

# Engine Sandbox
add_executable(Sandbox Sandbox/Main.cpp Sandbox/Main.h)
set_property(TARGET Sandbox PROPERTY VS_DEBUGGER_WORKING_DIRECTORY "${CMAKE_SOURCE_DIR}/build/debug")
target_include_directories(Sandbox PUBLIC Sandbox/)
target_link_libraries(Sandbox Nade)