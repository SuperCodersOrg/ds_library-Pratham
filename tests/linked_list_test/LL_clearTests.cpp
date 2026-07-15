#include <gtest/gtest.h>
#include "../include/linked_list.h"

class LinkedListClearTest : public ::testing::Test
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

TEST_F(LinkedListClearTest, ClearList)
{
    list.clear();

    EXPECT_TRUE(list.isEmpty());
    EXPECT_EQ(list.size(), 0);
}

TEST_F(LinkedListClearTest, ClearEmpty)
{
    LinkedList<int> temp;

    temp.clear();

    EXPECT_TRUE(temp.isEmpty());
    EXPECT_EQ(temp.size(), 0);
}

TEST_F(LinkedListClearTest, SearchAfterClear)
{
    list.clear();

    EXPECT_FALSE(list.search(10));
    EXPECT_FALSE(list.search(20));
    EXPECT_FALSE(list.search(30));
}

TEST_F(LinkedListClearTest, ReuseAfterClear)
{
    list.clear();

    list.insertBack(40);

    EXPECT_EQ(list.size(), 1);
    EXPECT_TRUE(list.search(40));
}