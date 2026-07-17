
# cmake_minimum_required(VERSION 3.16)
# cmake_policy(SET CMP0135 NEW)

# project(DS_LIBRARY)

# set(CMAKE_CXX_STANDARD 17)

# include(FetchContent)

# FetchContent_Declare(
#     googletest
#     URL https://github.com/google/googletest/archive/refs/heads/main.zip
# )

# FetchContent_MakeAvailable(googletest)

# enable_testing()

# include_directories(include)

# add_executable(runTests

# # DA
#     # tests/dynamic_array_test/DA_constructorTests.cpp
#     # tests/dynamic_array_test/DA_pushTests.cpp 
#     # tests/dynamic_array_test/DA_insertTests.cpp 
#     # tests/dynamic_array_test/DA_removeTests.cpp 
#     # tests/dynamic_array_test/DA_sizeTests.cpp
#     # tests/dynamic_array_test/DA_isemptyTests.cpp
#     # tests/dynamic_array_test/DA_capacityTests.cpp
#     tests/dynamic_array_test/DA_getTests.cpp 
#     # tests/dynamic_array_test/DA_clearTests.cpp
#     # tests/dynamic_array_test/DA_operator[]Tests.cpp 
#     # tests/dynamic_array_test/DA_resizeTests.cpp
#     # tests/dynamic_array_test/DA_assignmentOpOverloadingTests.cpp 
#     # tests/dynamic_array_test/DA_copyconstructorTests.cpp

# # # LL
# #     tests/linked_list_test/LL_constructorTest.cpp
# #     tests/linked_list_test/LL_deletefrontTests.cpp
# #     tests/linked_list_test/LL_findTests.cpp
# #     tests/linked_list_test/LL_inserIndexTests.cpp
# #     tests/linked_list_test/LL_insert_back_Tests.cpp
# #     tests/linked_list_test/LL_isemptyTests.cpp
# #     tests/linked_list_test/LL_printTests.cpp
# #     tests/linked_list_test/LL_searchTests.cpp
# #     tests/linked_list_test/LL_sizeTests.cpp
# #     tests/linked_list_test/LL_assignmentOpOverloadingTests.cpp
# #     tests/linked_list_test/LL_clearTests.cpp
# #     tests/linked_list_test/LL_copyConstructorTests.cpp
# #     tests/linked_list_test/LL_removeTests.cpp  
# #     tests/linked_list_test/LL_insertFrontTest.cpp
# # # HP
# #     tests/hash_map_test/HM_constructorTests.cpp 
# #     tests/hash_map_test/HM_isemptyTests.cpp
# #     tests/hash_map_test/HM_loadfactorTests.cpp
# #     tests/hash_map_test/HM_assignOpTests.cpp
# #     tests/hash_map_test/HM_capacityTests.cpp
# #     tests/hash_map_test/HM_clearTests.cpp
# #     tests/hash_map_test/HM_containTests.cpp
# #     tests/hash_map_test/HM_copyConstructorTests.cpp
# #     tests/hash_map_test/HM_getTests.cpp
# #     tests/hash_map_test/HM_insertTests.cpp
# #     tests/hash_map_test/HM_removeTests.cpp
# #     tests/hash_map_test/HM_sizeTests.cpp

# # #RL
# #     src/redis_lite/redis_lite.cpp
# #     tests/redis_lite_test/RL_clearTests.cpp
# #     tests/redis_lite_test/RL_constructorTests.cpp
# #     tests/redis_lite_test/RL_countTests.cpp
# #     tests/redis_lite_test/RL_delTests.cpp
# #     tests/redis_lite_test/RL_existsTests.cpp
# #     tests/redis_lite_test/RL_getTests.cpp
# #     tests/redis_lite_test/RL_setTests.cpp
# # 
# )

# target_include_directories(runTests PRIVATE include)

# target_link_libraries(runTests
#     GTest::gtest_main
# )

# include(GoogleTest)
# gtest_discover_tests(runTests)


cmake_minimum_required(VERSION 3.16)
cmake_policy(SET CMP0135 NEW)

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

# Build tests
add_subdirectory(tests)