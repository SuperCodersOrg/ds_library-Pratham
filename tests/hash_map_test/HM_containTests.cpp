#include <gtest/gtest.h>
#include "../include/hash_map.h"

class HashMapContainsTest : public ::testing::Test
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

TEST_F(HashMapContainsTest, ExistingKey)
{
    EXPECT_TRUE(map.contains(1));
    EXPECT_TRUE(map.contains(2));
    EXPECT_TRUE(map.contains(3));
}

TEST_F(HashMapContainsTest, MissingKey)
{
    EXPECT_FALSE(map.contains(100));
}

TEST_F(HashMapContainsTest, AfterRemove)
{
    map.remove(2);

    EXPECT_FALSE(map.contains(2));
    EXPECT_TRUE(map.contains(1));
    EXPECT_TRUE(map.contains(3));
}

TEST_F(HashMapContainsTest, AfterUpdate)
{
    map.insert(2, 200);

    EXPECT_TRUE(map.contains(2));
    EXPECT_EQ(map.get(2), 200);
}

TEST_F(HashMapContainsTest, AfterClear)
{
    map.clear();

    EXPECT_FALSE(map.contains(1));
    EXPECT_FALSE(map.contains(2));
    EXPECT_FALSE(map.contains(3));
}

TEST_F(HashMapContainsTest, AfterRehash)
{
    for (int i = 4; i <= 10; i++)
    {
        map.insert(i, i * 10);
    }

    EXPECT_TRUE(map.contains(1));
    EXPECT_TRUE(map.contains(2));
    EXPECT_TRUE(map.contains(3));

    for (int i = 4; i <= 10; i++)
    {
        EXPECT_TRUE(map.contains(i));
    }
}