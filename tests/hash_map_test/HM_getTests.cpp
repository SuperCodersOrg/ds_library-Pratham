#include <gtest/gtest.h>
#include "../include/hash_map.h"

class HashMapGetTest : public ::testing::Test
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

TEST_F(HashMapGetTest, ExistingKey)
{
    EXPECT_EQ(map.get(1), 10);
    EXPECT_EQ(map.get(2), 20);
    EXPECT_EQ(map.get(3), 30);
}

TEST_F(HashMapGetTest, MissingKey)
{
    EXPECT_THROW(map.get(100), std::out_of_range);
}

TEST_F(HashMapGetTest, UpdatedValue)
{
    map.insert(2, 200);

    EXPECT_EQ(map.get(2), 200);
}

TEST_F(HashMapGetTest, AfterRemove)
{
    map.remove(2);

    EXPECT_THROW(map.get(2), std::out_of_range);

    EXPECT_EQ(map.get(1), 10);
    EXPECT_EQ(map.get(3), 30);
}

TEST_F(HashMapGetTest, AfterClear)
{
    map.clear();

    EXPECT_THROW(map.get(1), std::out_of_range);
    EXPECT_THROW(map.get(2), std::out_of_range);
    EXPECT_THROW(map.get(3), std::out_of_range);
}

TEST_F(HashMapGetTest, AfterRehash)
{
    for (int i = 4; i <= 10; i++)
    {
        map.insert(i, i * 10);
    }

    EXPECT_EQ(map.get(1), 10);
    EXPECT_EQ(map.get(2), 20);
    EXPECT_EQ(map.get(3), 30);

    for (int i = 4; i <= 10; i++)
    {
        EXPECT_EQ(map.get(i), i * 10);
    }
}