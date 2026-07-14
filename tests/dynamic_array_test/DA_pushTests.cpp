#include <gtest/gtest.h>
#include "../include/dynamic_array.h"

class DynamicArrayTest : public ::testing::Test {
protected:
    DynamicArray<int> arr;
};

TEST_F(DynamicArrayTest, PushOne)
{
    arr.push(10);

    EXPECT_EQ(arr.size(), 1);
    EXPECT_EQ(arr[0], 10);
}

TEST_F(DynamicArrayTest, PushMany)
{
    for(int i = 1; i <= 5; i++)
        arr.push(i);

    EXPECT_EQ(arr.size(), 5);

    for(int i = 0; i < 5; i++)
        EXPECT_EQ(arr[i], i + 1);
}

TEST_F(DynamicArrayTest, PushResize)
{
    int oldCap = arr.capacity();

    for(int i = 0; i <= oldCap; i++)
        arr.push(i);

    EXPECT_GT(arr.capacity(), oldCap);
    EXPECT_EQ(arr.size(), oldCap + 1);

    for(int i = 0; i <= oldCap; i++)
        EXPECT_EQ(arr[i], i);
}

TEST_F(DynamicArrayTest, PushLarge)
{
    for(int i = 0; i < 1000; i++)
        arr.push(i);

    EXPECT_EQ(arr.size(), 1000);

    EXPECT_EQ(arr[0], 0);
    EXPECT_EQ(arr[499], 499);
    EXPECT_EQ(arr[999], 999);
}

TEST_F(DynamicArrayTest, PushAfterResize)
{
    for(int i = 0; i < 20; i++)
        arr.push(i);

    arr.push(100);

    EXPECT_EQ(arr.size(), 21);
    EXPECT_EQ(arr[20], 100);

    for(int i = 0; i < 20; i++)
        EXPECT_EQ(arr[i], i);
}