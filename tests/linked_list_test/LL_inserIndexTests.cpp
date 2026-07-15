#include <gtest/gtest.h>
#include "../include/linked_list.h"

class LinkedListInsertTest : public ::testing::Test
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

TEST_F(LinkedListInsertTest, InsertBeginning)
{
    list.insert(0, 5);

    EXPECT_EQ(list.size(), 4);
    EXPECT_TRUE(list.search(5));
    EXPECT_TRUE(list.search(10));
}

TEST_F(LinkedListInsertTest, InsertMiddle)
{
    list.insert(1, 15);

    EXPECT_EQ(list.size(), 4);
    EXPECT_TRUE(list.search(15));
}

TEST_F(LinkedListInsertTest, InsertEnd)
{
    list.insert(3, 40);

    EXPECT_EQ(list.size(), 4);
    EXPECT_TRUE(list.search(40));
}

TEST_F(LinkedListInsertTest, InsertEmpty)
{
    LinkedList<int> temp;

    temp.insert(0, 10);

    EXPECT_EQ(temp.size(), 1);
    EXPECT_TRUE(temp.search(10));
}

TEST_F(LinkedListInsertTest, NegativeIndex)
{
    EXPECT_THROW(list.insert(-1, 5), const char*);
}

TEST_F(LinkedListInsertTest, InvalidIndex)
{
    EXPECT_THROW(list.insert(4, 5), const char*);
}