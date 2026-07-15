#include <gtest/gtest.h>
#include "../include/hash_map.h"

TEST(HashMapConstructorTest, DefaultConstructor)
{
    HashMap<int, int> map;

    EXPECT_TRUE(map.isEmpty());
    EXPECT_EQ(map.size(), 0);
    EXPECT_EQ(map.capacity(), 8);
    EXPECT_FLOAT_EQ(map.loadFactor(), 0.0f);
}

TEST(HashMapConstructorTest, CustomConstructor)
{
    HashMap<int, int> map(16);

    EXPECT_TRUE(map.isEmpty());
    EXPECT_EQ(map.size(), 0);
    EXPECT_EQ(map.capacity(), 16);
    EXPECT_FLOAT_EQ(map.loadFactor(), 0.0f);
}

TEST(HashMapConstructorTest, CapacityOne)
{
    HashMap<int, int> map(1);

    EXPECT_TRUE(map.isEmpty());
    EXPECT_EQ(map.size(), 0);
    EXPECT_EQ(map.capacity(), 1);
}

TEST(HashMapConstructorTest, ZeroCapacity)
{
    // EXPECT_THROW(HashMap<int, int> map(0), std::invalid_argument);
    EXPECT_THROW((HashMap<int,int>(0)), std::invalid_argument);
}

TEST(HashMapConstructorTest, NegativeCapacity)
{
    // EXPECT_THROW(HashMap<int, int> map(-5), std::invalid_argument);
    EXPECT_THROW((HashMap<int,int>(-5)), std::invalid_argument);
}