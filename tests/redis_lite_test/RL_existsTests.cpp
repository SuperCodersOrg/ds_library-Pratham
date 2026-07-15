#include <gtest/gtest.h>
#include <sstream>
#include <string>

#include "../../include/redis_lite.h"

class RedisLiteTest : public ::testing::Test{
protected:
    RedisLite redis;
};

// handleExists Tests

TEST_F(RedisLiteTest, ExistsExistingKey){
    std::stringstream input("name pratham");
    redis.handleSet(input);

    std::stringstream existsInput("name");

    testing::internal::CaptureStdout();
    redis.handleExists(existsInput);
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_EQ(output, "TRUE\n");
}

TEST_F(RedisLiteTest, ExistsNonExistingKey){
    std::stringstream existsInput("name");

    testing::internal::CaptureStdout();
    redis.handleExists(existsInput);
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_EQ(output, "FALSE\n");
}

TEST_F(RedisLiteTest, ExistsWithoutKey){
    std::stringstream existsInput("");

    testing::internal::CaptureStdout();
    redis.handleExists(existsInput);
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_EQ(output, "ERROR: Usage: EXISTS <key>\n");
}

TEST_F(RedisLiteTest, ExistsAfterDelete){
    std::stringstream input("name pratham");
    redis.handleSet(input);

    std::stringstream delInput("name");
    redis.handleDel(delInput);

    std::stringstream existsInput("name");

    testing::internal::CaptureStdout();
    redis.handleExists(existsInput);
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_EQ(output, "FALSE\n");
}

TEST_F(RedisLiteTest, ExistsWithMultipleKeys){
    std::stringstream input1("name pratham");
    std::stringstream input2("city bathinda");
    std::stringstream input3("course cse");

    redis.handleSet(input1);
    redis.handleSet(input2);
    redis.handleSet(input3);

    std::stringstream existsInput("city");

    testing::internal::CaptureStdout();
    redis.handleExists(existsInput);
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_EQ(output, "TRUE\n");
}