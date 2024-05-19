cmake_minimum_required(VERSION 3.10)
project(AlgorithmicTradingPlatform)

# Set the C++ standard to C++17
set(CMAKE_CXX_STANDARD 17)

# Include directories
include_directories(include)

# Add source files
file(GLOB SOURCES "src/*.cpp")

# Create the executable
add_executable(trading_platform ${SOURCES})

# Enable testing
enable_testing()
add_subdirectory(tests)
