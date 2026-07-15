#include <gtest/gtest.h>
#include "../include/hash_map.h"

TEST(HashMapIsEmptyTest, EmptyMap)
{
    HashMap<int, int> map;

    EXPECT_TRUE(map.isEmpty());
}

TEST(HashMapIsEmptyTest, AfterSingleInsert)
{
    HashMap<int, int> map;

    map.insert(1, 10);

    EXPECT_FALSE(map.isEmpty());
}

TEST(HashMapIsEmptyTest, AfterMultipleInsert)
{
    HashMap<int, int> map;

    map.insert(1, 10);
    map.insert(2, 20);
    map.insert(3, 30);

    EXPECT_FALSE(map.isEmpty());
}

TEST(HashMapIsEmptyTest, AfterRemoveAll)
{
    HashMap<int, int> map;

    map.insert(1, 10);
    map.insert(2, 20);

    map.remove(1);
    map.remove(2);

    EXPECT_TRUE(map.isEmpty());
}

TEST(HashMapIsEmptyTest, AfterClear)
{
    HashMap<int, int> map;

    map.insert(1, 10);
    map.insert(2, 20);

    map.clear();

    EXPECT_TRUE(map.isEmpty());
}

TEST(HashMapIsEmptyTest, DuplicateInsert)
{
    HashMap<int, int> map;

    map.insert(1, 10);
    map.insert(1, 100);

    EXPECT_FALSE(map.isEmpty());
}