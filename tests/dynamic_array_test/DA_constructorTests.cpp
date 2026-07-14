#include <gtest/gtest.h>
#include "../include/dynamic_array.h"

class DynamicArrayTest : public ::testing::Test {
protected:
    DynamicArray<int> arr;
    void SetUp() override {
        // Empty by default.
        // Individual tests can push elements if needed.
    }

};

// TEST_F(DynamicArrayTest, Default)
// {
//     EXPECT_EQ(arr.size(), 0);
//     EXPECT_EQ(arr.capacity(), 4);
//     EXPECT_TRUE(arr.isEmpty());
// }

// TEST_F(DynamicArrayTest, SmallCapacity)
// {
//     DynamicArray<int> temp(1);

//     EXPECT_EQ(temp.size(), 0);
//     EXPECT_EQ(temp.capacity(), 1);
//     EXPECT_TRUE(temp.isEmpty());
// }

// TEST_F(DynamicArrayTest, CustomCapacity)
// {
//     DynamicArray<int> temp(10);

//     EXPECT_EQ(temp.size(), 0);
//     EXPECT_EQ(temp.capacity(), 10);
//     EXPECT_TRUE(temp.isEmpty());
// }

// TEST_F(DynamicArrayTest, ZeroCapacity)
// {
//     EXPECT_THROW(DynamicArray<int> temp(0), std::invalid_argument);
// }

// TEST_F(DynamicArrayTest, NegativeCapacity)
// {
//     EXPECT_THROW(DynamicArray<int> temp(-5), std::invalid_argument);
// }



TEST(DynamicArrayTest, DefaultConstructor)
{
    DynamicArray<int> arr;

    EXPECT_EQ(arr.size(), 0);
    EXPECT_EQ(arr.capacity(), 4);
}

TEST(DynamicArrayTest, CapacityValueConstructor)
{
    DynamicArray<int> arr(5, 100);

    EXPECT_EQ(arr.size(), 5);
    EXPECT_EQ(arr.capacity(), 5);

    for(int i = 0; i < arr.size(); i++)
    {
        EXPECT_EQ(arr[i], 100);
    }
}

TEST(DynamicArrayTest, CapacityOne)
{
    DynamicArray<int> arr(1, 7);

    EXPECT_EQ(arr.size(), 1);
    EXPECT_EQ(arr[0], 7);
}
