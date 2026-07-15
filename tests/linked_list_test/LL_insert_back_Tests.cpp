#include <gtest/gtest.h>
#include "../include/linked_list.h"

class LinkedListInsertBackTest : public ::testing::Test
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

TEST_F(LinkedListInsertBackTest, InsertIntoEmpty)
{
    LinkedList<int> temp;

    temp.insertBack(5);

    EXPECT_EQ(temp.size(), 1);
    EXPECT_TRUE(temp.search(5));
}

TEST_F(LinkedListInsertBackTest, InsertSingle)
{
    list.insertBack(40);

    EXPECT_EQ(list.size(), 4);
    EXPECT_TRUE(list.search(40));
}

TEST_F(LinkedListInsertBackTest, InsertMultiple)
{
    list.insertBack(40);
    list.insertBack(50);

    EXPECT_EQ(list.size(), 5);
    EXPECT_TRUE(list.search(40));
    EXPECT_TRUE(list.search(50));
}

TEST_F(LinkedListInsertBackTest, DuplicateValues)
{
    list.insertBack(20);

    EXPECT_EQ(list.size(), 4);
    EXPECT_TRUE(list.search(20));
}

TEST_F(LinkedListInsertBackTest, PreserveElements)
{
    list.insertBack(40);

    EXPECT_TRUE(list.search(10));
    EXPECT_TRUE(list.search(20));
    EXPECT_TRUE(list.search(30));
    EXPECT_TRUE(list.search(40));
    EXPECT_EQ(list.size(), 4);
}