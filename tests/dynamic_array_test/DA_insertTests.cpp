#include <gtest/gtest.h>
#include "dynamic_array.h"

class DynamicArrayTest : public ::testing::Test {
protected:
    DynamicArray<int> arr;

    void SetUp() override
    {
        for(int i = 1; i <= 5; i++)
            arr.push(i);
    }
};

TEST_F(DynamicArrayTest, InsertFront)
{
    arr.insert(0, 100);

    EXPECT_EQ(arr.size(), 6);
    EXPECT_EQ(arr[0], 100);

    for(int i = 1; i < 6; i++)
        EXPECT_EQ(arr[i], i);
}

TEST_F(DynamicArrayTest, InsertMiddle)
{
    arr.insert(2, 99);

    EXPECT_EQ(arr.size(), 6);

    EXPECT_EQ(arr[0], 1);
    EXPECT_EQ(arr[1], 2);
    EXPECT_EQ(arr[2], 99);
    EXPECT_EQ(arr[3], 3);
    EXPECT_EQ(arr[4], 4);
    EXPECT_EQ(arr[5], 5);
}

TEST_F(DynamicArrayTest, InsertEnd)
{
    arr.insert(arr.size(), 200);

    EXPECT_EQ(arr.size(), 6);
    EXPECT_EQ(arr[5], 200);
}

TEST_F(DynamicArrayTest, InsertResize)
{
    DynamicArray<int> temp(2);

    temp.push(1);
    temp.push(2);

    int oldCap = temp.capacity();

    temp.insert(1, 99);

    EXPECT_GT(temp.capacity(), oldCap);
    EXPECT_EQ(temp.size(), 3);

    EXPECT_EQ(temp[0], 1);
    EXPECT_EQ(temp[1], 99);
    EXPECT_EQ(temp[2], 2);
}

TEST_F(DynamicArrayTest, InsertInvalidIndex)
{
    EXPECT_THROW(arr.insert(-1, 10), std::out_of_range);
    EXPECT_THROW(arr.insert(arr.size() + 1, 10), std::out_of_range);
}