#include <gtest/gtest.h>
#include "../include/linked_list.h"

class LinkedListPrintTest : public ::testing::Test
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

TEST_F(LinkedListPrintTest, PrintList)
{
    testing::internal::CaptureStdout();

    list.print();

    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_EQ(output, "10 -> 20 -> 30 -> nullptr\n");
}

TEST_F(LinkedListPrintTest, PrintEmpty)
{
    LinkedList<int> temp;

    testing::internal::CaptureStdout();

    temp.print();

    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_EQ(output, "nullptr\n");
}

TEST_F(LinkedListPrintTest, PrintSingle)
{
    LinkedList<int> temp(10);

    testing::internal::CaptureStdout();

    temp.print();

    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_EQ(output, "10 -> nullptr\n");
}