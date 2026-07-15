#include <gtest/gtest.h>
#include "../include/linked_list.h"

class LinkedListDeleteFrontTest : public ::testing::Test
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

TEST_F(LinkedListDeleteFrontTest, EmptyList)
{
    LinkedList<int> temp;

    EXPECT_THROW(temp.deleteFront(), const char*);
}

TEST_F(LinkedListDeleteFrontTest, DeleteFirst)
{
    list.deleteFront();

    EXPECT_EQ(list.size(), 2);
    EXPECT_FALSE(list.search(10));
    EXPECT_TRUE(list.search(20));
    EXPECT_TRUE(list.search(30));
}

TEST_F(LinkedListDeleteFrontTest, DeleteSingleElement)
{
    LinkedList<int> temp(10);

    temp.deleteFront();

    EXPECT_TRUE(temp.isEmpty());
    EXPECT_EQ(temp.size(), 0);
}

TEST_F(LinkedListDeleteFrontTest, DeleteAll)
{
    list.deleteFront();
    list.deleteFront();
    list.deleteFront();

    EXPECT_TRUE(list.isEmpty());
    EXPECT_EQ(list.size(), 0);
}

TEST_F(LinkedListDeleteFrontTest, MultipleDeletes)
{
    list.deleteFront();
    list.deleteFront();

    EXPECT_EQ(list.size(), 1);
    EXPECT_TRUE(list.search(30));
    EXPECT_FALSE(list.search(10));
    EXPECT_FALSE(list.search(20));
}