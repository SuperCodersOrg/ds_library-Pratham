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

TEST_F(DynamicArrayTest, GetFirst)
{
    EXPECT_EQ(arr.get(0), 1);
}

TEST_F(DynamicArrayTest, GetMiddle)
{
    EXPECT_EQ(arr.get(2), 3);
}

TEST_F(DynamicArrayTest, GetLast)
{
    EXPECT_EQ(arr.get(arr.size() - 1), 5);
}

TEST_F(DynamicArrayTest, GetInvalidIndex)
{
    EXPECT_THROW(arr.get(-1), std::out_of_range);
    EXPECT_THROW(arr.get(arr.size()), std::out_of_range);
}

TEST_F(DynamicArrayTest, GetChar)
{
    DynamicArray<char> temp;

    temp.push('A');
    temp.push('B');

    EXPECT_EQ(temp.get(0), 'A');
    EXPECT_EQ(temp.get(1), 'B');
}

TEST_F(DynamicArrayTest, GetString)
{
    DynamicArray<std::string> temp;

    temp.push("Hello");
    temp.push("World");

    EXPECT_EQ(temp.get(0), "Hello");
    EXPECT_EQ(temp.get(1), "World");
}