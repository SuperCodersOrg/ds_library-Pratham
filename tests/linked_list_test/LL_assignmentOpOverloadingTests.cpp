#include <gtest/gtest.h>
#include "../include/linked_list.h"

class LinkedListAssignmentTest : public ::testing::Test
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

TEST_F(LinkedListAssignmentTest, AssignmentOperator)
{
    LinkedList<int> copy;

    copy = list;

    EXPECT_EQ(copy.size(), list.size());
    EXPECT_TRUE(copy.search(10));
    EXPECT_TRUE(copy.search(20));
    EXPECT_TRUE(copy.search(30));
}

TEST_F(LinkedListAssignmentTest, AssignEmpty)
{
    LinkedList<int> empty;
    LinkedList<int> copy;

    copy = empty;

    EXPECT_TRUE(copy.isEmpty());
    EXPECT_EQ(copy.size(), 0);
}

TEST_F(LinkedListAssignmentTest, DeepCopy)
{
    LinkedList<int> copy;

    copy = list;
    copy.insertBack(40);

    EXPECT_EQ(copy.size(), 4);
    EXPECT_EQ(list.size(), 3);

    EXPECT_FALSE(list.search(40));
    EXPECT_TRUE(copy.search(40));
}

TEST_F(LinkedListAssignmentTest, SelfAssignment)
{
    list = list;

    EXPECT_EQ(list.size(), 3);
    EXPECT_TRUE(list.search(10));
    EXPECT_TRUE(list.search(20));
    EXPECT_TRUE(list.search(30));
}