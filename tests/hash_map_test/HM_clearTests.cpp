#include <gtest/gtest.h>
#include "../include/hash_map.h"

class HashMapClearTest : public ::testing::Test
{
protected:
    HashMap<int, int> map;

    void SetUp() override
    {
        map.insert(1, 10);
        map.insert(2, 20);
        map.insert(3, 30);
    }
};

TEST_F(HashMapClearTest, ClearMap)
{
    map.clear();

    EXPECT_TRUE(map.isEmpty());
    EXPECT_EQ(map.size(), 0);
}

TEST_F(HashMapClearTest, ContainsAfterClear)
{
    map.clear();

    EXPECT_FALSE(map.contains(1));
    EXPECT_FALSE(map.contains(2));
    EXPECT_FALSE(map.contains(3));
}

TEST_F(HashMapClearTest, GetAfterClear)
{
    map.clear();

    EXPECT_THROW(map.get(1), std::out_of_range);
    EXPECT_THROW(map.get(2), std::out_of_range);
    EXPECT_THROW(map.get(3), std::out_of_range);
}

TEST_F(HashMapClearTest, InsertAfterClear)
{
    map.clear();

    map.insert(4, 40);

    EXPECT_EQ(map.size(), 1);
    EXPECT_TRUE(map.contains(4));
    EXPECT_EQ(map.get(4), 40);
}

TEST_F(HashMapClearTest, CapacityAfterClear)
{
    map.clear();

    EXPECT_EQ(map.capacity(), 8);
    EXPECT_FLOAT_EQ(map.loadFactor(), 0.0f);
}

TEST_F(HashMapClearTest, MultipleClear)
{
    map.clear();
    map.clear();

    EXPECT_TRUE(map.isEmpty());
    EXPECT_EQ(map.size(), 0);
    EXPECT_EQ(map.capacity(), 8);
}