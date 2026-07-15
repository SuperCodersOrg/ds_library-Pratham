#include <gtest/gtest.h>
#include "../include/linked_list.h"

class LinkedListSizeTest : public ::testing::Test
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

TEST_F(LinkedListSizeTest, EmptyList)
{
    LinkedList<int> temp;

    EXPECT_EQ(temp.size(), 0);
}

TEST_F(LinkedListSizeTest, InitialSize)
{
    EXPECT_EQ(list.size(), 3);
}

TEST_F(LinkedListSizeTest, AfterInsert)
{
    list.insertBack(40);

    EXPECT_EQ(list.size(), 4);
}

TEST_F(LinkedListSizeTest, AfterDelete)
{
    list.deleteFront();

    EXPECT_EQ(list.size(), 2);
}

TEST_F(LinkedListSizeTest, AfterRemove)
{
    list.remove(20);

    EXPECT_EQ(list.size(), 2);
}