#include <gtest/gtest.h>
#include "../include/hash_map.h"

TEST(HashMapCapacityTest, DefaultCapacity)
{
    HashMap<int, int> map;

    EXPECT_EQ(map.capacity(), 8);
}

TEST(HashMapCapacityTest, CustomCapacity)
{
    HashMap<int, int> map(16);

    EXPECT_EQ(map.capacity(), 16);
}

TEST(HashMapCapacityTest, CapacityOne)
{
    HashMap<int, int> map(1);

    EXPECT_EQ(map.capacity(), 1);
}

TEST(HashMapCapacityTest, CapacityAfterInsert)
{
    HashMap<int, int> map;

    map.insert(1, 10);
    map.insert(2, 20);

    EXPECT_EQ(map.capacity(), 8);
}

TEST(HashMapCapacityTest, CapacityAfterClear)
{
    HashMap<int, int> map;

    map.insert(1, 10);
    map.insert(2, 20);

    map.clear();

    EXPECT_EQ(map.capacity(), 8);
}

TEST(HashMapCapacityTest, CapacityAfterRehash)
{
    HashMap<int, int> map;

    for (int i = 0; i < 7; i++)
    {
        map.insert(i, i * 10);
    }

    EXPECT_EQ(map.capacity(), 16);
}