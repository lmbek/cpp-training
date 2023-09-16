cmake_minimum_required(VERSION 3.26)
project(program1)

# Set the C++ standard to the latest version
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Define the source files for your project
set(SOURCE_FILES program1/main.cpp)

# Specify the output directory for the executable
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR})

add_executable(program1 ${SOURCE_FILES/program1} main.cpp)
