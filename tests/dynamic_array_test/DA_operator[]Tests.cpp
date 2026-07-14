#include <gtest/gtest.h>
#include <string>
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

TEST_F(DynamicArrayTest, AccessFirst)
{
    EXPECT_EQ(arr[0], 1);
}

TEST_F(DynamicArrayTest, AccessMiddle)
{
    EXPECT_EQ(arr[2], 3);
}

TEST_F(DynamicArrayTest, AccessLast)
{
    EXPECT_EQ(arr[arr.size() - 1], 5);
}

TEST_F(DynamicArrayTest, ModifyValue)
{
    arr[2] = 100;

    EXPECT_EQ(arr[2], 100);
}

TEST_F(DynamicArrayTest, InvalidIndex)
{
    EXPECT_THROW(arr[-1], std::out_of_range);
    EXPECT_THROW(arr[arr.size()], std::out_of_range);
}

TEST_F(DynamicArrayTest, ConstAccess)
{
    const DynamicArray<int> temp = arr;

    EXPECT_EQ(temp[0], 1);
    EXPECT_EQ(temp[2], 3);
    EXPECT_EQ(temp[4], 5);
}

TEST_F(DynamicArrayTest, ConstInvalidIndex)
{
    const DynamicArray<int> temp = arr;

    EXPECT_THROW(temp[-1], std::out_of_range);
    EXPECT_THROW(temp[temp.size()], std::out_of_range);
}

TEST_F(DynamicArrayTest, CharArray)
{
    DynamicArray<char> temp;

    temp.push('A');
    temp.push('B');

    EXPECT_EQ(temp[0], 'A');

    temp[1] = 'Z';

    EXPECT_EQ(temp[1], 'Z');
}

TEST_F(DynamicArrayTest, StringArray)
{
    DynamicArray<std::string> temp;

    temp.push("Hello");
    temp.push("World");

    EXPECT_EQ(temp[0], "Hello");

    temp[1] = "SuperCoders";

    EXPECT_EQ(temp[1], "SuperCoders");
}
