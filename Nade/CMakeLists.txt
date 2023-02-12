cmake_minimum_required(VERSION 3.14)
project(Nade)

set(CMAKE_CXX_STANDARD_REQUIRED 17)

add_subdirectory(vendor/glfw)
add_subdirectory(vendor/fast_obj)
add_subdirectory(vendor/glad)

# Engine Library
set(ENGINE_LIBS 
    glfw
    fast_obj_lib
    GLAD
)
file(GLOB NADE_SRC 
    src/*.cpp 
    src/*/*.cpp
    src/*/*/*.cpp
)

add_library(Nade STATIC ${NADE_SRC})
target_link_libraries(Nade PUBLIC ${ENGINE_LIBS})
target_include_directories(Nade PUBLIC
# Fix this later
    src/
    src/Graphics
    src/Graphics/Components
    src/Graphics/Loaders
    src/Core
    src/Core/Events
    src/Core/Input
    src/Core/Physics
    src/Components
    vendor/glm
    vendor/stb_image
)
target_precompile_headers(Nade PUBLIC "src/Core/pch.h")
