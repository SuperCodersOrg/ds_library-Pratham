#include <gtest/gtest.h>
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

TEST_F(DynamicArrayTest, RemoveFront)
{
    arr.remove(0);

    EXPECT_EQ(arr.size(), 4);

    EXPECT_EQ(arr[0], 2);
    EXPECT_EQ(arr[1], 3);
    EXPECT_EQ(arr[2], 4);
    EXPECT_EQ(arr[3], 5);
}

TEST_F(DynamicArrayTest, RemoveMiddle)
{
    arr.remove(2);

    EXPECT_EQ(arr.size(), 4);

    EXPECT_EQ(arr[0], 1);
    EXPECT_EQ(arr[1], 2);
    EXPECT_EQ(arr[2], 4);
    EXPECT_EQ(arr[3], 5);
}

TEST_F(DynamicArrayTest, RemoveEnd)
{
    arr.remove(arr.size() - 1);

    EXPECT_EQ(arr.size(), 4);

    EXPECT_EQ(arr[0], 1);
    EXPECT_EQ(arr[1], 2);
    EXPECT_EQ(arr[2], 3);
    EXPECT_EQ(arr[3], 4);
}

TEST_F(DynamicArrayTest, RemoveInvalidIndex)
{
    EXPECT_THROW(arr.remove(-1), std::out_of_range);
    EXPECT_THROW(arr.remove(arr.size()), std::out_of_range);
}

TEST_F(DynamicArrayTest, RemoveUntilEmpty)
{
    DynamicArray<int> arr;

    for(int i = 1; i <= 5; i++)
        arr.push(i);

    while(!arr.isEmpty())
        arr.remove(0);

    EXPECT_TRUE(arr.isEmpty());
    EXPECT_EQ(arr.size(), 0);
}

TEST_F(DynamicArrayTest, RemoveSingleElement)
{
    DynamicArray<int> arr;

    arr.push(100);
    arr.remove(0);

    EXPECT_TRUE(arr.isEmpty());
    EXPECT_EQ(arr.size(), 0);
}

TEST_F(DynamicArrayTest, RemoveFromEmpty)
{
    DynamicArray<int> arr;

    EXPECT_THROW(arr.remove(0), std::out_of_range);
}
