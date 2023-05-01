cmake_minimum_required(VERSION 3.5)
project(MyProject)

# Set C++ standard to C++11
set(CMAKE_CXX_STANDARD 11)

# Add source files
file(GLOB SOURCES "src/*.cpp")

# Add executable
add_executable(RayTracer ${SOURCES})
