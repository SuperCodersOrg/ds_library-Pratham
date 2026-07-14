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
            //but be carefull with this fixture in cases of checking size and capacity ,
            // answer could vary according to fixture size rather than expected
    }
};

TEST_F(DynamicArrayTest, CopyEmpty)
{
    DynamicArray<int> temp;

    DynamicArray<int> copy(temp);

    EXPECT_TRUE(copy.isEmpty());
    EXPECT_EQ(copy.size(), 0);
    EXPECT_EQ(copy.capacity(), temp.capacity());

}

TEST_F(DynamicArrayTest, CopyValues)
{
    DynamicArray<int> temp;

    for(int i = 1; i <= 5; i++)
        temp.push(i);

    DynamicArray<int> copy(temp);

    EXPECT_EQ(copy.size(), temp.size());
    EXPECT_EQ(copy.capacity(), temp.capacity());

    for(int i = 0; i < temp.size(); i++)
        EXPECT_EQ(copy[i], temp[i]);
}

TEST_F(DynamicArrayTest, DeepCopy)
{
    DynamicArray<int> temp;

    for(int i = 1; i <= 5; i++)
        temp.push(i);

    DynamicArray<int> copy(temp);

    copy[0] = 100;

    EXPECT_EQ(temp[0], 1);
    EXPECT_EQ(copy[0], 100);
}

TEST_F(DynamicArrayTest, CopyString)
{
    DynamicArray<std::string> temp;

    temp.push("Hello");
    temp.push("World");

    DynamicArray<std::string> copy(temp);

    EXPECT_EQ(copy.size(), temp.size());

    EXPECT_EQ(copy[0], "Hello");
    EXPECT_EQ(copy[1], "World");

    copy[0] = "Super";

    EXPECT_EQ(temp[0], "Hello");
    EXPECT_EQ(copy[0], "Super");
}