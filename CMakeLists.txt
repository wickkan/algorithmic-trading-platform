cmake_minimum_required(VERSION 3.10)
project(AlgorithmicTradingPlatform)

set(CMAKE_CXX_STANDARD 17)

include_directories(include)
file(GLOB SOURCES "src/*.cpp")

find_package(ZeroMQ REQUIRED)

add_executable(trading_platform ${SOURCES})
target_link_libraries(trading_platform zmq)

enable_testing()
add_subdirectory(tests)

