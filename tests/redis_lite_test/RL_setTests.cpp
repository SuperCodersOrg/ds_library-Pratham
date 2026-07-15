#include <gtest/gtest.h>
#include <sstream>
#include <string>

#include "../../include/redis_lite.h"

class RedisLiteTest : public ::testing::Test{
protected:
    RedisLite redis;
};

// handleSet Tests

TEST_F(RedisLiteTest, SetValidKeyValue){
    std::stringstream input("name pratham");

    testing::internal::CaptureStdout();
    redis.handleSet(input);
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_EQ(output, "OK\n");
    EXPECT_TRUE(redis.getDatabase().contains("name"));
    EXPECT_EQ(redis.getDatabase().get("name"), "pratham");
}

TEST_F(RedisLiteTest, SetWithoutArguments){
    std::stringstream input("");

    testing::internal::CaptureStdout();
    redis.handleSet(input);
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_EQ(output, "ERROR: Usage: SET <key> <value>\n");
    EXPECT_TRUE(redis.getDatabase().isEmpty());
}

TEST_F(RedisLiteTest, SetWithoutValue){
    std::stringstream input("name");

    testing::internal::CaptureStdout();
    redis.handleSet(input);
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_EQ(output, "ERROR: Usage: SET <key> <value>\n");
    EXPECT_TRUE(redis.getDatabase().isEmpty());
}

TEST_F(RedisLiteTest, SetOverwriteExistingKey){
    std::stringstream input1("name pratham");
    std::stringstream input2("name niklaus");

    redis.handleSet(input1);

    testing::internal::CaptureStdout();
    redis.handleSet(input2);
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_EQ(output, "OK\n");
    EXPECT_EQ(redis.getDatabase().size(), 1);
    EXPECT_EQ(redis.getDatabase().get("name"), "niklaus");
}

TEST_F(RedisLiteTest, SetMultipleKeyValuePairs){
    std::stringstream input1("name pratham");
    std::stringstream input2("city bathinda");
    std::stringstream input3("course cse");

    redis.handleSet(input1);
    redis.handleSet(input2);
    redis.handleSet(input3);

    EXPECT_EQ(redis.getDatabase().size(), 3);
    EXPECT_EQ(redis.getDatabase().get("name"), "pratham");
    EXPECT_EQ(redis.getDatabase().get("city"), "bathinda");
    EXPECT_EQ(redis.getDatabase().get("course"), "cse");
}