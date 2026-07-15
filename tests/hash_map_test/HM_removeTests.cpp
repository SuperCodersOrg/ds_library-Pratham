#include <gtest/gtest.h>
#include "../include/hash_map.h"

class HashMapRemoveTest : public ::testing::Test
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

TEST_F(HashMapRemoveTest, ExistingKey)
{
    map.remove(2);

    EXPECT_EQ(map.size(), 2);
    EXPECT_FALSE(map.contains(2));
    EXPECT_TRUE(map.contains(1));
    EXPECT_TRUE(map.contains(3));
}

TEST_F(HashMapRemoveTest, MissingKey)
{
    EXPECT_THROW(map.remove(100), std::out_of_range);

    EXPECT_EQ(map.size(), 3);
}

TEST_F(HashMapRemoveTest, RemoveAll)
{
    map.remove(1);
    map.remove(2);
    map.remove(3);

    EXPECT_TRUE(map.isEmpty());
    EXPECT_EQ(map.size(), 0);
}

TEST_F(HashMapRemoveTest, RemoveThenInsert)
{
    map.remove(2);
    map.insert(4, 40);

    EXPECT_EQ(map.size(), 3);

    EXPECT_FALSE(map.contains(2));
    EXPECT_TRUE(map.contains(4));
    EXPECT_EQ(map.get(4), 40);
}

TEST_F(HashMapRemoveTest, RemoveAfterRehash)
{
    for (int i = 4; i <= 10; i++)
    {
        map.insert(i, i * 10);
    }

    map.remove(8);

    EXPECT_FALSE(map.contains(8));
    EXPECT_EQ(map.size(), 9);

    EXPECT_TRUE(map.contains(1));
    EXPECT_TRUE(map.contains(10));
}

TEST_F(HashMapRemoveTest, MultipleRemove)
{
    map.remove(1);
    map.remove(3);

    EXPECT_EQ(map.size(), 1);

    EXPECT_FALSE(map.contains(1));
    EXPECT_TRUE(map.contains(2));
    EXPECT_FALSE(map.contains(3));
}