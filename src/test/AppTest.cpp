#include "gtest/gtest.h"
#include "gmock/gmock.h"

class AppTest : public ::testing::Test {

};

TEST_F(AppTest, assert_true) {
  ASSERT_TRUE(true);
}