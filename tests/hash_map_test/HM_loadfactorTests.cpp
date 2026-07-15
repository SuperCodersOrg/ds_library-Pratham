#include <gtest/gtest.h>
#include "../include/hash_map.h"

TEST(HashMapLoadFactorTest, EmptyMap)
{
    HashMap<int, int> map;

    EXPECT_FLOAT_EQ(map.loadFactor(), 0.0f);
}

TEST(HashMapLoadFactorTest, SingleInsert)
{
    HashMap<int, int> map;

    map.insert(1, 10);

    EXPECT_FLOAT_EQ(map.loadFactor(), 1.0f / 8.0f);
}

TEST(HashMapLoadFactorTest, MultipleInsert)
{
    HashMap<int, int> map;

    map.insert(1, 10);
    map.insert(2, 20);
    map.insert(3, 30);

    EXPECT_FLOAT_EQ(map.loadFactor(), 3.0f / 8.0f);
}

TEST(HashMapLoadFactorTest, DuplicateKey)
{
    HashMap<int, int> map;

    map.insert(1, 10);
    map.insert(1, 50);

    EXPECT_FLOAT_EQ(map.loadFactor(), 1.0f / 8.0f);
}

TEST(HashMapLoadFactorTest, AfterRemove)
{
    HashMap<int, int> map;

    map.insert(1, 10);
    map.insert(2, 20);

    map.remove(1);

    EXPECT_FLOAT_EQ(map.loadFactor(), 1.0f / 8.0f);
}

TEST(HashMapLoadFactorTest, AfterRehash)
{
    HashMap<int, int> map;

    for (int i = 0; i < 7; i++)
    {
        map.insert(i, i * 10);
    }

    EXPECT_FLOAT_EQ(map.loadFactor(), 7.0f / 16.0f);
}