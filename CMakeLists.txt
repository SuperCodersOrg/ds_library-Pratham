# cmake_minimum_required(VERSION 3.28)

# project(CollectionsLibrary)

# set(CMAKE_CXX_STANDARD 17)
# set(CMAKE_CXX_STANDARD_REQUIRED ON)
# set(CMAKE_BUILD_TYPE Debug)
# set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# enable_testing()

# find_package(GTest REQUIRED)

# add_executable(
#     CollectionsLibrary
#     main.cpp
# )

# target_include_directories(CollectionsLibrary PRIVATE include)

# add_executable(
#     runTests
#     tests/dynamic_array_test/DA_constructorTests.cpp
# )

# target_include_directories(runTests PRIVATE include)

# target_link_libraries(
#     runTests
#     PRIVATE
#     GTest::gtest
#     GTest::gtest_main
#     pthread
# )

# include(GoogleTest)
# gtest_discover_tests(runTests)

cmake_minimum_required(VERSION 3.16)

cmake_minimum_required(VERSION 3.16)

cmake_policy(SET CMP0135 NEW)

project(DS_LIBRARY)

project(DS_LIBRARY)

set(CMAKE_CXX_STANDARD 17)

include(FetchContent)

FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/refs/heads/main.zip
)

FetchContent_MakeAvailable(googletest)

enable_testing()

include_directories(include)

add_executable(runTests
    # tests/dynamic_array_test/DA_constructorTests.cpp
    # tests/dynamic_array_test/DA_pushTests.cpp
    # tests/dynamic_array_test/DA_insertTests.cpp
    # tests/dynamic_array_test/DA_removeTests.cpp 
    # tests/dynamic_array_test/DA_sizeTests.cpp
    # tests/dynamic_array_test/DA_isemptyTests.cpp
    # tests/dynamic_array_test/DA_capacityTests.cpp
    # tests/dynamic_array_test/DA_getTests.cpp
    # tests/dynamic_array_test/DA_clearTests.cpp
    # tests/dynamic_array_test/DA_operator[]Tests.cpp
    # tests/dynamic_array_test/DA_resizeTests.cpp
    tests/dynamic_array_test/DA_assignmentOpOverloadingTests.cpp
    # tests/dynamic_array_test/DA_copyconstructorTests.cpp

)

target_include_directories(runTests PRIVATE include)

target_link_libraries(runTests
    GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(runTests)