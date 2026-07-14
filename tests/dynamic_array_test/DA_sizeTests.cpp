#include <gtest/gtest.h>
#include <string>
#include "../include/dynamic_array.h"

TEST(Size, EmptyArray)
{
    DynamicArray<int> arr;

    EXPECT_EQ(arr.size(), 0);
}

TEST(Size, AfterPush)
{
    DynamicArray<int> arr;

    arr.push(10);
    arr.push(20);
    arr.push(30);

    EXPECT_EQ(arr.size(), 3);
}

TEST(Size, AfterRemove)
{
    DynamicArray<int> arr;

    arr.push(1);
    arr.push(2);
    arr.push(3);

    arr.remove(1);

    EXPECT_EQ(arr.size(), 2);
}

TEST(Size, CharArray)
{
    DynamicArray<char> arr;

    arr.push('A');
    arr.push('B');

    EXPECT_EQ(arr.size(), 2);
}

TEST(Size, StringArray)
{
    DynamicArray<std::string> arr;

    arr.push("Hello");
    arr.push("World");

    EXPECT_EQ(arr.size(), 2);
}