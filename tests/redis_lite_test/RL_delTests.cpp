#include <gtest/gtest.h>
#include <sstream>
#include <string>

#include "../../include/redis_lite.h"

class RedisLiteTest : public ::testing::Test{
protected:
    RedisLite redis;
};

// handleDel Tests

TEST_F(RedisLiteTest, DelExistingKey){
    std::stringstream setInput("name pratham");
    redis.handleSet(setInput);

    std::stringstream delInput("name");

    testing::internal::CaptureStdout();
    redis.handleDel(delInput);
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_EQ(output, "OK\n");
    EXPECT_FALSE(redis.getDatabase().contains("name"));
    EXPECT_TRUE(redis.getDatabase().isEmpty());
}

TEST_F(RedisLiteTest, DelNonExistingKey){
    std::stringstream delInput("name");

    testing::internal::CaptureStdout();
    redis.handleDel(delInput);
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_EQ(output, "ERROR: Key not found.\n");
    EXPECT_TRUE(redis.getDatabase().isEmpty());
}

TEST_F(RedisLiteTest, DelWithoutKey){
    std::stringstream delInput("");

    testing::internal::CaptureStdout();
    redis.handleDel(delInput);
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_EQ(output, "ERROR: Usage: DEL <key>\n");
    EXPECT_TRUE(redis.getDatabase().isEmpty());
}

TEST_F(RedisLiteTest, DelOneKeyFromMultiple){
    std::stringstream input1("name pratham");
    std::stringstream input2("city bathinda");
    std::stringstream input3("course cse");

    redis.handleSet(input1);
    redis.handleSet(input2);
    redis.handleSet(input3);

    std::stringstream delInput("city");

    testing::internal::CaptureStdout();
    redis.handleDel(delInput);
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_EQ(output, "OK\n");
    EXPECT_EQ(redis.getDatabase().size(), 2);
    EXPECT_TRUE(redis.getDatabase().contains("name"));
    EXPECT_FALSE(redis.getDatabase().contains("city"));
    EXPECT_TRUE(redis.getDatabase().contains("course"));
}

TEST_F(RedisLiteTest, DelSameKeyTwice){
    std::stringstream setInput("name pratham");
    redis.handleSet(setInput);

    std::stringstream delInput1("name");
    redis.handleDel(delInput1);

    std::stringstream delInput2("name");

    testing::internal::CaptureStdout();
    redis.handleDel(delInput2);
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_EQ(output, "ERROR: Key not found.\n");
    EXPECT_TRUE(redis.getDatabase().isEmpty());
}