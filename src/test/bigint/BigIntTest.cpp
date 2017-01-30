#include "gtest/gtest.h"
#include "gmock/gmock.h"

class BigIntTest : public ::testing::Test {

};

TEST_F(BigIntTest, assert_true) {
  ASSERT_TRUE(true);
}
