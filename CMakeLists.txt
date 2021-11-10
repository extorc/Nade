cmake_minimum_required(VERSION 3.8)

add_subdirectory(Nade/vendor/glfw)

project(Nade)

set(INC glfw Nade/vendor/glad/include)

add_executable(Nade
Nade/src/Nade.h
Nade/src/Entrypoint.cpp	
Nade/src/Core/Window.h
Nade/src/Core/Window.cpp
Nade/vendor/glad/src/glad.c
Nade/src/Graphics/Components/RawModel.h
Nade/src/Graphics/Loaders/ModelLoader.cpp
Nade/src/Graphics/Loaders/ModelLoader.h
)

target_include_directories(Nade PUBLIC ${INC})
target_link_libraries(Nade PUBLIC glfw)
