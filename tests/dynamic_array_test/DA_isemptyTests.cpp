#include <gtest/gtest.h>
#include <string>
#include "../include/dynamic_array.h"

TEST(IsEmpty, NewArray)
{
    DynamicArray<int> arr;

    EXPECT_TRUE(arr.isEmpty());
}

TEST(IsEmpty, AfterPush)
{
    DynamicArray<int> arr;

    arr.push(100);

    EXPECT_FALSE(arr.isEmpty());
}

TEST(IsEmpty, AfterRemove)
{
    DynamicArray<int> arr;

    arr.push(10);

    arr.remove(0);

    EXPECT_TRUE(arr.isEmpty());
}

TEST(IsEmpty, CharArray)
{
    DynamicArray<char> arr;

    EXPECT_TRUE(arr.isEmpty());

    arr.push('X');

    EXPECT_FALSE(arr.isEmpty());
}

TEST(IsEmpty, StringArray)
{
    DynamicArray<std::string> arr;

    EXPECT_TRUE(arr.isEmpty());

    arr.push("SuperCoders");

    EXPECT_FALSE(arr.isEmpty());
}