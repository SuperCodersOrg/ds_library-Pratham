#include <gtest/gtest.h>
#include <string>
#include "../include/dynamic_array.h"

TEST(Capacity, Default)
{
    DynamicArray<int> arr;

    EXPECT_EQ(arr.capacity(), 4);
}

TEST(Capacity, Custom)
{
    DynamicArray<int> arr(10);

    EXPECT_EQ(arr.capacity(), 10);
}

TEST(Capacity, NoResize)
{
    DynamicArray<int> arr;

    arr.push(1);
    arr.push(2);
    arr.push(3);
    arr.push(4);

    EXPECT_EQ(arr.capacity(), 4);
}

TEST(Capacity, AfterResize)
{
    DynamicArray<int> arr;

    int oldCap = arr.capacity();

    for(int i = 0; i <= oldCap; i++)
        arr.push(i);

    EXPECT_GT(arr.capacity(), oldCap);
}

TEST(Capacity, StringArray)
{
    DynamicArray<std::string> arr;

    EXPECT_EQ(arr.capacity(), 4);

    arr.push("A");
    arr.push("B");

    EXPECT_EQ(arr.capacity(), 4);
}