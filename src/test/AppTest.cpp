#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "../main/bigint/BigInt.h"
#include "../main/App.h"

class AppTest : public ::testing::Test {

};

TEST_F(AppTest, test_is_prime_small) {
  const int max = 10000;
  bool isNotPrime[max] = {1, 1, 0};
  for (int i = 2; i < max; ++i)
    if (!isNotPrime[i])
      for (int j = i * 2; j < max; j += i)
        isNotPrime[j] = true;

  for (int i = 0; i < max; i++)
    EXPECT_EQ(!isNotPrime[i], isPrime(BigInt(i)));
}

TEST_F(AppTest, test_is_prime_598_bit) {
  BigInt p1 = BigInt(
      "1797693134862315907729305190789024733617976978942306572734300811577326758055009631327084773224075360211201138798713933576587897688144166224928474306394741243777678934248654852763217");
  BigInt p2 = BigInt(
      "1797693134862315907729305190789024733617976978942306572734300811577326758055009631327084773224075360211201138798713933576587897688144166224928474306394741243777678934248654852763229");
  EXPECT_EQ(1, isPrime(p1));
  for (BigInt i = p1 + 1; i < p2; i++)
    EXPECT_EQ(0, isPrime(i));
  EXPECT_EQ(1, isPrime(p2));
}

TEST_F(AppTest, test_inverse) {
  BigInt p("8209");
  for (BigInt i = 1; i < p; i++) {
    BigInt j = inverse(i, p);
    EXPECT_EQ("1", ((i * j) % p).toDecimalString());
  }
}
