cmake_minimum_required(VERSION 3.10)
project(AlgorithmicTradingPlatform)

set(CMAKE_CXX_STANDARD 17)

include_directories(include)

find_package(spdlog REQUIRED)

file(GLOB SOURCES "src/*.cpp")

add_executable(trading_platform ${SOURCES})
target_link_libraries(trading_platform spdlog::spdlog)

enable_testing()
add_subdirectory(tests)

