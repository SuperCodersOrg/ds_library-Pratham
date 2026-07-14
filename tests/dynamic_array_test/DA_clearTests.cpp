#include <gtest/gtest.h>
#include <string>
#include "../include/dynamic_array.h"

class DynamicArrayTest : public ::testing::Test {
protected:
    DynamicArray<int> arr;

    void SetUp() override
    {
        for(int i = 1; i <= 5; i++)
            arr.push(i);
    }
};

TEST_F(DynamicArrayTest, ClearArray)
{
    arr.clear();

    EXPECT_TRUE(arr.isEmpty());
    EXPECT_EQ(arr.size(), 0);
}

TEST_F(DynamicArrayTest, ClearTwice)
{
    arr.clear();
    arr.clear();

    EXPECT_TRUE(arr.isEmpty());
    EXPECT_EQ(arr.size(), 0);
}

TEST_F(DynamicArrayTest, PushAfterClear)
{
    arr.clear();

    arr.push(100);

    EXPECT_EQ(arr.size(), 1);
    EXPECT_EQ(arr[0], 100);
}

TEST_F(DynamicArrayTest, ClearChar)
{
    DynamicArray<char> temp;

    temp.push('A');
    temp.push('B');

    temp.clear();

    EXPECT_TRUE(temp.isEmpty());
    EXPECT_EQ(temp.size(), 0);
}

TEST_F(DynamicArrayTest, ClearString)
{
    DynamicArray<std::string> temp;

    temp.push("One");
    temp.push("Two");

    temp.clear();

    EXPECT_TRUE(temp.isEmpty());
    EXPECT_EQ(temp.size(), 0);
}

TEST_F(DynamicArrayTest, ClearDefaultCapacity)
{
    DynamicArray<int> temp;

    int initialCap = temp.capacity();

    for(int i = 0; i < 20; i++)
        temp.push(i);

    EXPECT_GT(temp.capacity(), initialCap);

    temp.clear();

    EXPECT_EQ(temp.size(), 0);
    EXPECT_TRUE(temp.isEmpty());
    EXPECT_EQ(temp.capacity(), initialCap);
}

TEST_F(DynamicArrayTest, ClearCustomCapacity)
{
    DynamicArray<int> temp(10);

    int initialCap = temp.capacity();

    for(int i = 0; i < 25; i++)
        temp.push(i);

    EXPECT_GT(temp.capacity(), initialCap);

    temp.clear();

    EXPECT_EQ(temp.size(), 0);
    EXPECT_TRUE(temp.isEmpty());
    EXPECT_EQ(temp.capacity(), initialCap);
}