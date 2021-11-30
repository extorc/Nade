cmake_minimum_required(VERSION 3.14)

project(Sandbox)

set(CMAKE_BUILD_TYPE Debug)

set(ASSIMP_BUILD_TESTS OFF)
set(ASSIMP_BUILD_DOCS OFF)
set(ASSIMP_NO_EXPORT ON)
set(ASSIMP_BUILD_ALL_EXPORTERS_BY_DEFAULT OFF)
set(ASSIMP_BUILD_ALL_IMPORTERS_BY_DEFAULT OFF)
set(ASSIMP_BUILD_OBJ_IMPORTER ON)

add_subdirectory(Nade/)

add_executable(Sandbox Sandbox/Main.cpp Sandbox/Main.h)
set_property(TARGET Sandbox PROPERTY VS_DEBUGGER_WORKING_DIRECTORY "${CMAKE_SOURCE_DIR}/build/debug")
target_include_directories(Sandbox PUBLIC Nade)
target_link_libraries(Sandbox Nade)