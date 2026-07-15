#include <gtest/gtest.h>
#include "../include/linked_list.h"

class LinkedListCopyTest : public ::testing::Test
{
protected:
    LinkedList<int> list;

    void SetUp() override
    {
        list.insertBack(10);
        list.insertBack(20);
        list.insertBack(30);
    }
};

TEST_F(LinkedListCopyTest, CopyConstructor)
{
    LinkedList<int> copy(list);

    EXPECT_EQ(copy.size(), list.size());
    EXPECT_TRUE(copy.search(10));
    EXPECT_TRUE(copy.search(20));
    EXPECT_TRUE(copy.search(30));
}

TEST_F(LinkedListCopyTest, CopyEmpty)
{
    LinkedList<int> empty;
    LinkedList<int> copy(empty);

    EXPECT_TRUE(copy.isEmpty());
    EXPECT_EQ(copy.size(), 0);
}

TEST_F(LinkedListCopyTest, DeepCopyInsert)
{
    LinkedList<int> copy(list);

    copy.insertBack(40);

    EXPECT_EQ(copy.size(), 4);
    EXPECT_EQ(list.size(), 3);
    EXPECT_FALSE(list.search(40));
}

TEST_F(LinkedListCopyTest, DeepCopyRemove)
{
    LinkedList<int> copy(list);

    copy.remove(20);

    EXPECT_EQ(copy.size(), 2);
    EXPECT_EQ(list.size(), 3);

    EXPECT_TRUE(list.search(20));
    EXPECT_FALSE(copy.search(20));
}