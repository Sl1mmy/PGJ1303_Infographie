cmake_minimum_required(VERSION 3.12)

project(pgj1303)

# Path to the repo root and shared deps folder
set(REPO_ROOT ${CMAKE_SOURCE_DIR}/..)
set(DEPS_DIR ${REPO_ROOT}/Deps)

# Add GLFW from shared Deps folder (must specify binary dir if outside source dir)
add_subdirectory(${DEPS_DIR}/glfw ${CMAKE_BINARY_DIR}/_deps/glfw-build)

# Add glad manually (it's a single-file lib, so no need for subdirectory)
add_library(glad ${DEPS_DIR}/glad/src/gl.c)
target_include_directories(glad PUBLIC ${DEPS_DIR}/glad/include)

# Define the main executable
add_executable(pgj1303 
    ./src/main.cpp
)

# C++20 standard
set_property(TARGET pgj1303 PROPERTY CXX_STANDARD 20)

# Include directories (glad headers used directly in your project)
target_include_directories(pgj1303 PRIVATE ${DEPS_DIR}/glad/include)

# Link against the libraries
target_link_libraries(pgj1303 glad glfw)
