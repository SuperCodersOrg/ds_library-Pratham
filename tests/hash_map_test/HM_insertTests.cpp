#include <gtest/gtest.h>
#include "../include/hash_map.h"

class HashMapInsertTest : public ::testing::Test
{
protected:
    HashMap<int, int> map;
};

TEST_F(HashMapInsertTest, SingleInsert)
{
    map.insert(1, 10);

    EXPECT_EQ(map.size(), 1);
    EXPECT_TRUE(map.contains(1));
    EXPECT_EQ(map.get(1), 10);
}

TEST_F(HashMapInsertTest, MultipleInsert)
{
    map.insert(1, 10);
    map.insert(2, 20);
    map.insert(3, 30);

    EXPECT_EQ(map.size(), 3);

    EXPECT_TRUE(map.contains(1));
    EXPECT_TRUE(map.contains(2));
    EXPECT_TRUE(map.contains(3));

    EXPECT_EQ(map.get(1), 10);
    EXPECT_EQ(map.get(2), 20);
    EXPECT_EQ(map.get(3), 30);
}

TEST_F(HashMapInsertTest, DuplicateKey)
{
    map.insert(1, 10);
    map.insert(1, 100);

    EXPECT_EQ(map.size(), 1);
    EXPECT_EQ(map.get(1), 100);
}

TEST_F(HashMapInsertTest, TriggerRehash)
{
    for (int i = 0; i < 7; i++)
    {
        map.insert(i, i * 10);
    }

    EXPECT_EQ(map.capacity(), 16);
    EXPECT_EQ(map.size(), 7);

    for (int i = 0; i < 7; i++)
    {
        EXPECT_TRUE(map.contains(i));
        EXPECT_EQ(map.get(i), i * 10);
    }
}

TEST_F(HashMapInsertTest, InsertAfterRemove)
{
    map.insert(1, 10);
    map.insert(2, 20);

    map.remove(1);
    map.insert(3, 30);

    EXPECT_EQ(map.size(), 2);

    EXPECT_FALSE(map.contains(1));
    EXPECT_TRUE(map.contains(2));
    EXPECT_TRUE(map.contains(3));

    EXPECT_EQ(map.get(3), 30);
}

TEST_F(HashMapInsertTest, ManyInsert)
{
    for (int i = 0; i < 50; i++)
    {
        map.insert(i, i + 100);
    }

    EXPECT_EQ(map.size(), 50);

    for (int i = 0; i < 50; i++)
    {
        EXPECT_TRUE(map.contains(i));
        EXPECT_EQ(map.get(i), i + 100);
    }
}