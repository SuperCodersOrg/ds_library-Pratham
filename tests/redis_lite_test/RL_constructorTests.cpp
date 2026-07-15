#include <gtest/gtest.h>
#include <sstream>
#include <string>

#include "../../include/redis_lite.h"

class RedisLiteTest : public ::testing::Test{
protected:
    RedisLite redis;
};

// Constructor Tests

TEST_F(RedisLiteTest, DefaultConstructor){
    EXPECT_TRUE(redis.getDatabase().isEmpty());
    EXPECT_EQ(redis.getDatabase().size(), 0);
}

TEST_F(RedisLiteTest, ConstructorCreatesValidDatabase){
    std::stringstream input("name pratham");
    redis.handleSet(input);

    EXPECT_FALSE(redis.getDatabase().isEmpty());
    EXPECT_EQ(redis.getDatabase().size(), 1);
    EXPECT_TRUE(redis.getDatabase().contains("name"));
}