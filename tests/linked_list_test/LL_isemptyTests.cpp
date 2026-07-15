#include <gtest/gtest.h>
#include "../include/linked_list.h"

class LinkedListIsEmptyTest : public ::testing::Test
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

TEST_F(LinkedListIsEmptyTest, EmptyList)
{
    LinkedList<int> temp;

    EXPECT_TRUE(temp.isEmpty());
}

TEST_F(LinkedListIsEmptyTest, NonEmptyList)
{
    EXPECT_FALSE(list.isEmpty());
}

TEST_F(LinkedListIsEmptyTest, AfterInsert)
{
    list.insertBack(40);

    EXPECT_FALSE(list.isEmpty());
}

TEST_F(LinkedListIsEmptyTest, AfterDelete)
{
    list.deleteFront();
    list.deleteFront();
    list.deleteFront();

    EXPECT_TRUE(list.isEmpty());
}

TEST_F(LinkedListIsEmptyTest, AfterRemove)
{
    list.remove(10);
    list.remove(20);
    list.remove(30);

    EXPECT_TRUE(list.isEmpty());
}