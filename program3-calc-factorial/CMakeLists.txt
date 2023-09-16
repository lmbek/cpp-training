cmake_minimum_required(VERSION 3.26)
project(program3-calc-factorial)

# Set the C++ standard to the latest version
set(CMAKE_CXX_STANDARD 20)

# Define the source files for your project
set(SOURCE_FILES program3-calc-factorial/main.cpp)

# Specify the output directory for the executable
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR})

# Define the source files for your project
add_executable(program3 main.cpp)
