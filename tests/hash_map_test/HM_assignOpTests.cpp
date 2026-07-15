#include <gtest/gtest.h>
#include "../include/hash_map.h"

TEST(HashMapAssignmentOperatorTest, EmptyMap)
{
    HashMap<int, int> original;
    HashMap<int, int> copy;

    copy = original;

    EXPECT_TRUE(copy.isEmpty());
    EXPECT_EQ(copy.size(), 0);
    EXPECT_EQ(copy.capacity(), original.capacity());
}

TEST(HashMapAssignmentOperatorTest, SingleElement)
{
    HashMap<int, int> original;
    HashMap<int, int> copy;

    original.insert(1, 10);

    copy = original;

    EXPECT_EQ(copy.size(), 1);
    EXPECT_TRUE(copy.contains(1));
    EXPECT_EQ(copy.get(1), 10);
}

TEST(HashMapAssignmentOperatorTest, MultipleElements)
{
    HashMap<int, int> original;
    HashMap<int, int> copy;

    original.insert(1, 10);
    original.insert(2, 20);
    original.insert(3, 30);

    copy = original;

    EXPECT_EQ(copy.size(), original.size());

    EXPECT_EQ(copy.get(1), 10);
    EXPECT_EQ(copy.get(2), 20);
    EXPECT_EQ(copy.get(3), 30);
}

TEST(HashMapAssignmentOperatorTest, DeepCopy)
{
    HashMap<int, int> original;
    HashMap<int, int> copy;

    original.insert(1, 10);
    original.insert(2, 20);

    copy = original;

    copy.remove(1);
    copy.insert(3, 30);

    EXPECT_TRUE(original.contains(1));
    EXPECT_TRUE(original.contains(2));
    EXPECT_FALSE(original.contains(3));

    EXPECT_FALSE(copy.contains(1));
    EXPECT_TRUE(copy.contains(2));
    EXPECT_TRUE(copy.contains(3));
}

TEST(HashMapAssignmentOperatorTest, SelfAssignment)
{
    HashMap<int, int> map;

    map.insert(1, 10);
    map.insert(2, 20);

    map = map;

    EXPECT_EQ(map.size(), 2);
    EXPECT_TRUE(map.contains(1));
    EXPECT_TRUE(map.contains(2));

    EXPECT_EQ(map.get(1), 10);
    EXPECT_EQ(map.get(2), 20);
}

TEST(HashMapAssignmentOperatorTest, AssignmentAfterRehash)
{
    HashMap<int, int> original;
    HashMap<int, int> copy;

    for (int i = 0; i < 10; i++)
    {
        original.insert(i, i * 10);
    }

    copy = original;

    EXPECT_EQ(copy.size(), original.size());
    EXPECT_EQ(copy.capacity(), original.capacity());

    for (int i = 0; i < 10; i++)
    {
        EXPECT_EQ(copy.get(i), i * 10);
    }
}