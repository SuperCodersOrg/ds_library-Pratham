#include <gtest/gtest.h>
#include "../include/linked_list.h"

class LinkedListSearchTest : public ::testing::Test
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

TEST_F(LinkedListSearchTest, EmptyList)
{
    LinkedList<int> temp;

    EXPECT_FALSE(temp.search(10));
}

TEST_F(LinkedListSearchTest, FirstElement)
{
    EXPECT_TRUE(list.search(10));
}

TEST_F(LinkedListSearchTest, MiddleElement)
{
    EXPECT_TRUE(list.search(20));
}

TEST_F(LinkedListSearchTest, LastElement)
{
    EXPECT_TRUE(list.search(30));
}

TEST_F(LinkedListSearchTest, MissingElement)
{
    EXPECT_FALSE(list.search(40));
}