#include <gtest/gtest.h>
#include "../include/linked_list.h"

TEST(LinkedListConstructorTest, DefaultConstructor)
{
    LinkedList<int> list;

    EXPECT_TRUE(list.isEmpty());
    EXPECT_EQ(list.size(), 0);
}

TEST(LinkedListConstructorTest, SearchEmpty)
{
    LinkedList<int> list;

    EXPECT_FALSE(list.search(10));
}

TEST(LinkedListConstructorTest, FindEmpty)
{
    LinkedList<int> list;

    EXPECT_EQ(list.find(10), nullptr);
}

TEST(LinkedListConstructorTest, RemoveEmpty)
{
    LinkedList<int> list;

    EXPECT_FALSE(list.remove(10));
}

TEST(LinkedListConstructorTest, DeleteFrontEmpty)
{
    LinkedList<int> list;

    EXPECT_THROW(list.deleteFront(), const char*);
}

TEST(LinkedListConstructorTest, ParameterizedConstructor)
{
    LinkedList<int> list(10);

    EXPECT_FALSE(list.isEmpty());
    EXPECT_EQ(list.size(), 1);
    EXPECT_TRUE(list.search(10));
}

TEST(LinkedListConstructorTest, FindElement)
{
    LinkedList<int> list(20);

    int* ptr = list.find(20);

    ASSERT_NE(ptr, nullptr);
    EXPECT_EQ(*ptr, 20);
}

TEST(LinkedListConstructorTest, SearchMissing)
{
    LinkedList<int> list(30);

    EXPECT_FALSE(list.search(100));
}

TEST(LinkedListConstructorTest, RemoveElement)
{
    LinkedList<int> list(40);

    EXPECT_TRUE(list.remove(40));
    EXPECT_TRUE(list.isEmpty());
    EXPECT_EQ(list.size(), 0);
}

TEST(LinkedListConstructorTest, DeleteFront)
{
    LinkedList<int> list(50);

    list.deleteFront();

    EXPECT_TRUE(list.isEmpty());
    EXPECT_EQ(list.size(), 0);
}