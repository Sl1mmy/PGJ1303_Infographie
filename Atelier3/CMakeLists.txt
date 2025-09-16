cmake_minimum_required(VERSION 3.12)

project(pgj1303)

# Set up paths
set(REPO_ROOT ${CMAKE_SOURCE_DIR}/..)
set(DEPS_DIR ${REPO_ROOT}/Deps)

# Add subdirectories with explicit binary dirs (required for external paths)
add_subdirectory(${DEPS_DIR}/glfw ${CMAKE_BINARY_DIR}/_deps/glfw-build)
add_subdirectory(${DEPS_DIR}/glm ${CMAKE_BINARY_DIR}/_deps/glm-build)
add_subdirectory(${DEPS_DIR}/assimp ${CMAKE_BINARY_DIR}/_deps/assimp-build)

# Manually add glad
add_library(glad ${DEPS_DIR}/glad/src/gl.c)
target_include_directories(glad PUBLIC ${DEPS_DIR}/glad/include)

# Your project sources
add_executable(pgj1303
    ./src/main.cpp
    ./src/CubeScene.cpp
    ./src/CubeScene.h
    ./src/MeshScene.cpp
    ./src/MeshScene.h
    ./src/TriangleScene.cpp
    ./src/TriangleScene.h
    ./src/OpenGlDef.h
    ./src/OpenGlProgram.h
    ./src/OpenGlResource.h
    ./src/OpenGlShader.h
)

# Project settings
set_property(TARGET pgj1303 PROPERTY CXX_STANDARD 20)
set_property(TARGET pgj1303 PROPERTY DEBUGGER_WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})

# Link dependencies
target_link_libraries(pgj1303 glfw glm glad assimp)
