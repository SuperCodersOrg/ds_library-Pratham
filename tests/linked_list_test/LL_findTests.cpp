#include <gtest/gtest.h>
#include "../include/linked_list.h"

class LinkedListFindTest : public ::testing::Test
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

TEST_F(LinkedListFindTest, FindExisting)
{
    int* ptr = list.find(20);

    ASSERT_NE(ptr, nullptr);
    EXPECT_EQ(*ptr, 20);
}

TEST_F(LinkedListFindTest, FindMissing)
{
    EXPECT_EQ(list.find(40), nullptr);
}

TEST_F(LinkedListFindTest, FindEmpty)
{
    LinkedList<int> temp;

    EXPECT_EQ(temp.find(10), nullptr);
}

TEST_F(LinkedListFindTest, ModifyThroughPointer)
{
    int* ptr = list.find(20);

    ASSERT_NE(ptr, nullptr);

    *ptr = 25;

    EXPECT_FALSE(list.search(20));
    EXPECT_TRUE(list.search(25));
}

TEST_F(LinkedListFindTest, ConstFind)
{
    const LinkedList<int> list(10);

    const int* ptr = list.find(10);

    ASSERT_NE(ptr, nullptr);
    EXPECT_EQ(*ptr, 10);
}
