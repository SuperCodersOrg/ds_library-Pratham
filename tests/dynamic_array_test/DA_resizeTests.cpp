#include <gtest/gtest.h>
#include "dynamic_array.h"

class DynamicArrayTest : public ::testing::Test {
protected:
    DynamicArray<int> arr;
};

TEST_F(DynamicArrayTest, ResizeOnce)
{
    int oldCap = arr.capacity();

    for(int i = 0; i <= oldCap; i++)
        arr.push(i);

    EXPECT_EQ(arr.capacity(), oldCap * 2);
    EXPECT_EQ(arr.size(), oldCap + 1);

    for(int i = 0; i <= oldCap; i++)
        EXPECT_EQ(arr[i], i);
}

TEST_F(DynamicArrayTest, ResizeMultipleTimes)
{
    int expectedCap = arr.capacity();

    while(expectedCap < 128)
        expectedCap *= 2;

    for(int i = 0; i < 100; i++)
        arr.push(i);

    EXPECT_EQ(arr.capacity(), expectedCap);
    EXPECT_EQ(arr.size(), 100);

    for(int i = 0; i < 100; i++)
        EXPECT_EQ(arr[i], i);
}

TEST_F(DynamicArrayTest, ResizeUsingInsert)
{
    DynamicArray<int> temp(2);

    temp.push(1);
    temp.push(2);

    int oldCap = temp.capacity();

    temp.insert(1, 100);

    EXPECT_EQ(temp.capacity(), oldCap * 2);

    EXPECT_EQ(temp[0], 1);
    EXPECT_EQ(temp[1], 100);
    EXPECT_EQ(temp[2], 2);
}

TEST_F(DynamicArrayTest, PushAfterResize)
{
    for(int i = 0; i < 20; i++)
        arr.push(i);

    int cap = arr.capacity();

    arr.push(100);

    EXPECT_EQ(arr[20], 100);
    EXPECT_EQ(arr.size(), 21);
    EXPECT_EQ(arr.capacity(), cap);
}

TEST_F(DynamicArrayTest, ResizeWithString)
{
    DynamicArray<std::string> temp(2);

    temp.push("A");
    temp.push("B");
    temp.push("C");

    EXPECT_EQ(temp.capacity(), 4);

    EXPECT_EQ(temp[0], "A");
    EXPECT_EQ(temp[1], "B");
    EXPECT_EQ(temp[2], "C");
}