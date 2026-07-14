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

TEST_F(DynamicArrayTest, AssignValues)
{
    DynamicArray<int> temp;
    DynamicArray<int> copy;

    for(int i = 1; i <= 5; i++)
        temp.push(i);

    copy = temp;

    EXPECT_EQ(copy.size(), temp.size());
    EXPECT_EQ(copy.capacity(), temp.capacity());

    for(int i = 0; i < temp.size(); i++)
        EXPECT_EQ(copy[i], temp[i]);
}

TEST_F(DynamicArrayTest, DeepCopy)
{
    DynamicArray<int> temp;
    DynamicArray<int> copy;

    for(int i = 1; i <= 5; i++)
        temp.push(i);

    copy = temp;

    copy[0] = 100;

    EXPECT_EQ(temp[0], 1);
    EXPECT_EQ(copy[0], 100);
}

TEST_F(DynamicArrayTest, AssignEmpty)
{
    DynamicArray<int> temp;
    DynamicArray<int> copy;

    copy.push(10);
    copy.push(20);

    copy = temp;

    EXPECT_TRUE(copy.isEmpty());
    EXPECT_EQ(copy.size(), 0);
    EXPECT_EQ(copy.capacity(), temp.capacity());
}

TEST_F(DynamicArrayTest, AssignAfterResize)
{
    DynamicArray<int> temp;
    DynamicArray<int> copy;

    for(int i = 0; i < 20; i++)
        temp.push(i);

    copy = temp;

    EXPECT_EQ(copy.size(), temp.size());
    EXPECT_EQ(copy.capacity(), temp.capacity());

    for(int i = 0; i < temp.size(); i++)
        EXPECT_EQ(copy[i], temp[i]);
}

TEST_F(DynamicArrayTest, SelfAssignment)
{
    arr = arr;

    EXPECT_EQ(arr.size(), 5);

    for(int i = 0; i < 5; i++)
        EXPECT_EQ(arr[i], i + 1);
}