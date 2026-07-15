#include <gtest/gtest.h>
#include "../include/hash_map.h"

TEST(HashMapSizeTest, EmptyMap)
{
    HashMap<int, int> map;

    EXPECT_EQ(map.size(), 0);
}

TEST(HashMapSizeTest, SingleInsert)
{
    HashMap<int, int> map;

    map.insert(1, 10);

    EXPECT_EQ(map.size(), 1);
}

TEST(HashMapSizeTest, MultipleInsert)
{
    HashMap<int, int> map;

    map.insert(1, 10);
    map.insert(2, 20);
    map.insert(3, 30);

    EXPECT_EQ(map.size(), 3);
}

TEST(HashMapSizeTest, DuplicateKey)
{
    HashMap<int, int> map;

    map.insert(1, 10);
    map.insert(1, 50);

    EXPECT_EQ(map.size(), 1);
}

TEST(HashMapSizeTest, AfterRemove)
{
    HashMap<int, int> map;

    map.insert(1, 10);
    map.insert(2, 20);

    map.remove(1);

    EXPECT_EQ(map.size(), 1);
}

TEST(HashMapSizeTest, AfterClear)
{
    HashMap<int, int> map;

    map.insert(1, 10);
    map.insert(2, 20);

    map.clear();

    EXPECT_EQ(map.size(), 0);
}