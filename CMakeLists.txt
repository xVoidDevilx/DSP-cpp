# Minimum required CMake version
cmake_minimum_required(VERSION 3.10)

# Project name
project(DSPProject)

# Set the C++ standard to C++11 (or later)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Optionally, specify whether the build is Debug or Release
set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_FLAGS_DEBUG "-g")

# Define the source files for the shared library (libDSP.so)
set(SOURCES
    DSP.cpp
)

# Create a shared library from the source files
add_library(DSP SHARED ${SOURCES})

# Specify include directories (for DSP.hpp)
target_include_directories(DSP PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

# Define the source files for the executable (DSP-tester.exe)
add_executable(DSP-tester main.cpp)

# Link the executable with the shared library
target_link_libraries(DSP-tester DSP)
