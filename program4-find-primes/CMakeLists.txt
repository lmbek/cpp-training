cmake_minimum_required(VERSION 3.26)
project(program4-find-primes)

# Set the C++ standard to the latest version
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Define the source files for your project
set(SOURCE_FILES program4-find-primes/main.cpp)

# Specify the output directory for the executable
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR})

add_executable(program4 ${SOURCE_FILES/program4-find-primes} main.cpp)
