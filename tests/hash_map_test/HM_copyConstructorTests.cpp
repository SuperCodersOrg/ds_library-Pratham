#include <gtest/gtest.h>
#include "../include/hash_map.h"

TEST(HashMapCopyConstructorTest, EmptyMap)
{
    HashMap<int, int> original;

    HashMap<int, int> copy(original);

    EXPECT_TRUE(copy.isEmpty());
    EXPECT_EQ(copy.size(), 0);
    EXPECT_EQ(copy.capacity(), original.capacity());
}

TEST(HashMapCopyConstructorTest, CopySingleElement)
{
    HashMap<int, int> original;
    original.insert(1, 10);

    HashMap<int, int> copy(original);

    EXPECT_EQ(copy.size(), 1);
    EXPECT_TRUE(copy.contains(1));
    EXPECT_EQ(copy.get(1), 10);
}

TEST(HashMapCopyConstructorTest, CopyMultipleElements)
{
    HashMap<int, int> original;

    original.insert(1, 10);
    original.insert(2, 20);
    original.insert(3, 30);

    HashMap<int, int> copy(original);

    EXPECT_EQ(copy.size(), original.size());

    EXPECT_EQ(copy.get(1), 10);
    EXPECT_EQ(copy.get(2), 20);
    EXPECT_EQ(copy.get(3), 30);
}

TEST(HashMapCopyConstructorTest, DeepCopy)
{
    HashMap<int, int> original;

    original.insert(1, 10);
    original.insert(2, 20);

    HashMap<int, int> copy(original);

    copy.remove(1);
    copy.insert(3, 30);

    EXPECT_TRUE(original.contains(1));
    EXPECT_TRUE(original.contains(2));
    EXPECT_FALSE(original.contains(3));

    EXPECT_FALSE(copy.contains(1));
    EXPECT_TRUE(copy.contains(2));
    EXPECT_TRUE(copy.contains(3));
}

TEST(HashMapCopyConstructorTest, CopyAfterRehash)
{
    HashMap<int, int> original;

    for (int i = 0; i < 10; i++)
    {
        original.insert(i, i * 10);
    }

    HashMap<int, int> copy(original);

    EXPECT_EQ(copy.size(), original.size());
    EXPECT_EQ(copy.capacity(), original.capacity());

    for (int i = 0; i < 10; i++)
    {
        EXPECT_EQ(copy.get(i), i * 10);
    }
}

TEST(HashMapCopyConstructorTest, UpdateCopyOnly)
{
    HashMap<int, int> original;

    original.insert(1, 10);

    HashMap<int, int> copy(original);

    copy.insert(1, 100);

    EXPECT_EQ(original.get(1), 10);
    EXPECT_EQ(copy.get(1), 100);
}