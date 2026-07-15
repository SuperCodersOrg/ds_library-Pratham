#include <gtest/gtest.h>
#include "../include/linked_list.h"

class LinkedListInsertFrontTest : public ::testing::Test
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

TEST_F(LinkedListInsertFrontTest, InsertEmpty)
{
    LinkedList<int> temp;

    temp.insertFront(5);

    EXPECT_EQ(temp.size(), 1);
    EXPECT_TRUE(temp.search(5));
}

TEST_F(LinkedListInsertFrontTest, InsertSingle)
{
    list.insertFront(5);

    EXPECT_EQ(list.size(), 4);
    EXPECT_TRUE(list.search(5));
}

TEST_F(LinkedListInsertFrontTest, InsertMultiple)
{
    list.insertFront(5);
    list.insertFront(1);

    EXPECT_EQ(list.size(), 5);
    EXPECT_TRUE(list.search(1));
    EXPECT_TRUE(list.search(5));
}

TEST_F(LinkedListInsertFrontTest, DuplicateValues)
{
    list.insertFront(10);

    EXPECT_EQ(list.size(), 4);
    EXPECT_TRUE(list.search(10));
}

TEST_F(LinkedListInsertFrontTest, PreserveElements)
{
    list.insertFront(5);

    EXPECT_EQ(list.size(), 4);
    EXPECT_TRUE(list.search(5));
    EXPECT_TRUE(list.search(10));
    EXPECT_TRUE(list.search(20));
    EXPECT_TRUE(list.search(30));
}