cmake_minimum_required(VERSION 3.26)

project(RayTracer)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(CMAKE_CXX_STANDARD 11)

# Set up library
add_library(RayTracerLib INTERFACE)
target_include_directories(RayTracerLib INTERFACE "${CMAKE_CURRENT_LIST_DIR}/src")

# Set up main
add_executable(RayTracer "${CMAKE_CURRENT_LIST_DIR}/src/main.cpp")
target_link_libraries(RayTracer RayTracerLib)


# Add executable
add_executable(RayTracer ${SOURCES})
