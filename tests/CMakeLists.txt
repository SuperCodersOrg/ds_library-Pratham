include(GoogleTest)

add_executable(runTests

    #==========================
    # Dynamic Array
    #==========================

    dynamic_array_test/DA_getTests.cpp
    dynamic_array_test/DA_constructorTests.cpp
    dynamic_array_test/DA_pushTests.cpp
    dynamic_array_test/DA_insertTests.cpp
    dynamic_array_test/DA_removeTests.cpp
    dynamic_array_test/DA_sizeTests.cpp
    dynamic_array_test/DA_isemptyTests.cpp
    dynamic_array_test/DA_capacityTests.cpp
    dynamic_array_test/DA_clearTests.cpp
    dynamic_array_test/DA_operator[]Tests.cpp
    dynamic_array_test/DA_resizeTests.cpp
    dynamic_array_test/DA_assignmentOpOverloadingTests.cpp
    dynamic_array_test/DA_copyconstructorTests.cpp

    #==========================
    # Linked List
    #==========================

    linked_list_test/LL_constructorTest.cpp
    linked_list_test/LL_deletefrontTests.cpp
    linked_list_test/LL_findTests.cpp
    linked_list_test/LL_inserIndexTests.cpp
    linked_list_test/LL_insert_back_Tests.cpp
    linked_list_test/LL_isemptyTests.cpp
    linked_list_test/LL_printTests.cpp
    linked_list_test/LL_searchTests.cpp
    linked_list_test/LL_sizeTests.cpp
    linked_list_test/LL_assignmentOpOverloadingTests.cpp
    linked_list_test/LL_clearTests.cpp
    linked_list_test/LL_copyConstructorTests.cpp
    linked_list_test/LL_removeTests.cpp
    linked_list_test/LL_insertFrontTest.cpp

    #==========================
    # HashMap
    #==========================

    hash_map_test/HM_constructorTests.cpp
    hash_map_test/HM_isemptyTests.cpp
    hash_map_test/HM_loadfactorTests.cpp
    hash_map_test/HM_assignOpTests.cpp
    hash_map_test/HM_capacityTests.cpp
    hash_map_test/HM_clearTests.cpp
    hash_map_test/HM_containTests.cpp
    hash_map_test/HM_copyConstructorTests.cpp
    hash_map_test/HM_getTests.cpp
    hash_map_test/HM_insertTests.cpp
    hash_map_test/HM_removeTests.cpp
    hash_map_test/HM_sizeTests.cpp

    #==========================
    # Redis Lite
    #==========================

    ../src/redis_lite/redis_lite.cpp
    redis_lite_test/RL_clearTests.cpp
    redis_lite_test/RL_constructorTests.cpp
    redis_lite_test/RL_countTests.cpp
    redis_lite_test/RL_delTests.cpp
    redis_lite_test/RL_existsTests.cpp
    redis_lite_test/RL_getTests.cpp
    redis_lite_test/RL_setTests.cpp
)

target_include_directories(runTests PRIVATE
    ${PROJECT_SOURCE_DIR}/include
)

target_link_libraries(runTests
    GTest::gtest_main
)

gtest_discover_tests(runTests)