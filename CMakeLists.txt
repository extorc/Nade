cmake_minimum_required(VERSION 3.8)

add_subdirectory(Nade/vendor/glfw)

project(Nade)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /std:c++17")
set(INC glfw Nade/vendor/glad/include)

add_executable(Nade
Nade/src/Nade.h
Nade/src/Entrypoint.cpp	
Nade/src/Core/Window.h
Nade/src/Core/Application.h
Nade/src/Core/Main.h
Nade/src/Core/Window.cpp
Nade/vendor/glad/src/glad.c
Nade/src/Graphics/Components/RawModel.h
Nade/src/Graphics/Components/Shader.h
Nade/src/Graphics/Components/Shader.cpp
Nade/src/Graphics/Components/Renderer.h
Nade/src/Graphics/Components/Renderer.cpp
Nade/src/Graphics/Loaders/ModelLoader.cpp
Nade/src/Graphics/Loaders/ModelLoader.h
)

target_include_directories(Nade PUBLIC ${INC})
target_link_libraries(Nade PUBLIC glfw)
