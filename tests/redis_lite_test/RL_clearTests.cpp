#include <gtest/gtest.h>
#include <sstream>
#include <string>

#include "../../include/redis_lite.h"

class RedisLiteTest : public ::testing::Test
{
protected:
    RedisLite redis;
};

// Clear an already empty database
TEST_F(RedisLiteTest, ClearEmptyDatabase)
{
    testing::internal::CaptureStdout();
    redis.handleClear();
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_EQ(output, "OK\n");
    EXPECT_TRUE(redis.getDatabase().isEmpty());
    EXPECT_EQ(redis.getDatabase().size(), 0);
}

// Clear database containing one key
TEST_F(RedisLiteTest, ClearSingleElement)
{
    testing::internal::CaptureStdout();
    std::stringstream input("name pratham");
    redis.handleSet(input);
    testing::internal::GetCapturedStdout();

    testing::internal::CaptureStdout();
    redis.handleClear();
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_EQ(output, "OK\n");
    EXPECT_TRUE(redis.getDatabase().isEmpty());
    EXPECT_EQ(redis.getDatabase().size(), 0);
}

// Clear database containing multiple keys
TEST_F(RedisLiteTest, ClearMultipleElements)
{
    testing::internal::CaptureStdout();

    std::stringstream input1("name pratham");
    std::stringstream input2("city bathinda");
    std::stringstream input3("course cse");

    redis.handleSet(input1);
    redis.handleSet(input2);
    redis.handleSet(input3);

    testing::internal::GetCapturedStdout();

    testing::internal::CaptureStdout();
    redis.handleClear();
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_EQ(output, "OK\n");
    EXPECT_TRUE(redis.getDatabase().isEmpty());
    EXPECT_EQ(redis.getDatabase().size(), 0);
}

// Database should be reusable after CLEAR
TEST_F(RedisLiteTest, ClearThenInsert)
{
    testing::internal::CaptureStdout();

    std::stringstream input1("name pratham");
    redis.handleSet(input1);

    testing::internal::GetCapturedStdout();

    redis.handleClear();

    testing::internal::CaptureStdout();

    std::stringstream input2("city bathinda");
    redis.handleSet(input2);

    testing::internal::GetCapturedStdout();

    EXPECT_EQ(redis.getDatabase().size(), 1);
    EXPECT_FALSE(redis.getDatabase().contains("name"));
    EXPECT_TRUE(redis.getDatabase().contains("city"));
    EXPECT_EQ(redis.getDatabase().get("city"), "bathinda");
}

// Calling CLEAR twice should still succeed
TEST_F(RedisLiteTest, ClearTwice)
{
    testing::internal::CaptureStdout();

    std::stringstream input("name pratham");
    redis.handleSet(input);

    testing::internal::GetCapturedStdout();

    redis.handleClear();

    testing::internal::CaptureStdout();
    redis.handleClear();
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_EQ(output, "OK\n");
    EXPECT_TRUE(redis.getDatabase().isEmpty());
    EXPECT_EQ(redis.getDatabase().size(), 0);
}