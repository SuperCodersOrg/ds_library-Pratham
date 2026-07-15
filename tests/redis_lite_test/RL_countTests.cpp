#include <gtest/gtest.h>
#include <sstream>
#include <string>

#include "../../include/redis_lite.h"

class RedisLiteTest : public ::testing::Test{
protected:
    RedisLite redis;
};

// handleCount Tests

TEST_F(RedisLiteTest, CountEmptyDatabase){
    testing::internal::CaptureStdout();
    redis.handleCount();
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_EQ(output, "0\n");
}

TEST_F(RedisLiteTest, CountAfterSingleInsert){
    std::stringstream input("name pratham");
    redis.handleSet(input);

    testing::internal::CaptureStdout();
    redis.handleCount();
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_EQ(output, "1\n");
}

TEST_F(RedisLiteTest, CountAfterMultipleInserts){
    std::stringstream input1("name pratham");
    std::stringstream input2("city bathinda");
    std::stringstream input3("course cse");

    redis.handleSet(input1);
    redis.handleSet(input2);
    redis.handleSet(input3);

    testing::internal::CaptureStdout();
    redis.handleCount();
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_EQ(output, "3\n");
}

TEST_F(RedisLiteTest, CountAfterDelete){
    std::stringstream input1("name pratham");
    std::stringstream input2("city bathinda");

    redis.handleSet(input1);
    redis.handleSet(input2);

    std::stringstream delInput("name");
    redis.handleDel(delInput);

    testing::internal::CaptureStdout();
    redis.handleCount();
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_EQ(output, "1\n");
}

TEST_F(RedisLiteTest, CountAfterClear){
    std::stringstream input1("name pratham");
    std::stringstream input2("city bathinda");

    redis.handleSet(input1);
    redis.handleSet(input2);
    redis.handleClear();

    testing::internal::CaptureStdout();
    redis.handleCount();
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_EQ(output, "0\n");
}