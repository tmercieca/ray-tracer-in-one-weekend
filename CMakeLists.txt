cmake_minimum_required(VERSION 3.26)

project(RayTracer)

include(CTest)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(CMAKE_CXX_STANDARD 11)

# Set up library
add_library(RayTracerLib INTERFACE)
target_include_directories(RayTracerLib INTERFACE "${CMAKE_CURRENT_LIST_DIR}/src")

# Set up main
add_executable(RayTracer "${CMAKE_CURRENT_LIST_DIR}/src/main.cpp")
target_link_libraries(RayTracer RayTracerLib)

# Set up tests
find_package(Catch2 3 REQUIRED)
include(Catch)

add_executable(Tests "${CMAKE_CURRENT_LIST_DIR}/test/test.cpp")
target_link_libraries(Tests RayTracerLib Catch2::Catch2WithMain)
catch_discover_tests(Tests)
