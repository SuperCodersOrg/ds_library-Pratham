#include <gtest/gtest.h>
#include <sstream>
#include <string>

#include "../../include/redis_lite.h"

class RedisLiteTest : public ::testing::Test{
protected:
    RedisLite redis;
};

// handleGet Tests

TEST_F(RedisLiteTest, GetExistingKey){
    std::stringstream setInput("name pratham");
    redis.handleSet(setInput);

    std::stringstream getInput("name");

    testing::internal::CaptureStdout();
    redis.handleGet(getInput);
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_EQ(output, "pratham\n");
}

TEST_F(RedisLiteTest, GetNonExistingKey){
    std::stringstream getInput("name");

    testing::internal::CaptureStdout();
    redis.handleGet(getInput);
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_EQ(output, "ERROR: Key not found.\n");
}

TEST_F(RedisLiteTest, GetWithoutKey){
    std::stringstream getInput("");

    testing::internal::CaptureStdout();
    redis.handleGet(getInput);
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_EQ(output, "ERROR: Usage: GET <key>\n");
}

TEST_F(RedisLiteTest, GetAfterOverwrite){
    std::stringstream input1("name pratham");
    std::stringstream input2("name niklaus");

    redis.handleSet(input1);
    redis.handleSet(input2);

    std::stringstream getInput("name");

    testing::internal::CaptureStdout();
    redis.handleGet(getInput);
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_EQ(output, "niklaus\n");
}

TEST_F(RedisLiteTest, GetFromMultipleKeys){
    std::stringstream input1("name pratham");
    std::stringstream input2("city bathinda");
    std::stringstream input3("course cse");

    redis.handleSet(input1);
    redis.handleSet(input2);
    redis.handleSet(input3);

    std::stringstream getInput("city");

    testing::internal::CaptureStdout();
    redis.handleGet(getInput);
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_EQ(output, "bathinda\n");
}