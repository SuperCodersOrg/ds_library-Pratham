cmake_minimum_required(VERSION 3.28)

project(CollectionsLibrary)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_BUILD_TYPE Debug)

include_directories(include)

# Main executable
add_executable(
    CollectionsLibrary
    main.cpp
)

enable_testing()

find_package(GTest REQUIRED)