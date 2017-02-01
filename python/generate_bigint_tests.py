import random


def generate_addition_and_subtraction_test(id, a_bits, b_bits):
    x = random.randint(1 << a_bits, 1 << (a_bits + 1))
    y = random.randint(1 << b_bits, 1 << (b_bits + 1))

    return f'''
TEST_F(BigIntGeneratedTest, test_addition_and_subtraction_of_{a_bits}_bit_number_and_{b_bits}_bit_number_{id}) {{
  BigInt x("{x}");
  BigInt y("{y}");
  string expected_sum_1 = "{x + y}";
  string expected_sum_2 = "{x - y}";
  string expected_sum_3 = "{-x + y}";
  string expected_sum_4 = "{-x - y}";
  BigInt sum_1 = x + y;
  BigInt sum_2 = x - y;
  BigInt sum_3 = -x + y;
  BigInt sum_4 = -x - y;
  ASSERT_EQ(expected_sum_1, sum_1.toDecimalString());
  ASSERT_EQ(expected_sum_2, sum_2.toDecimalString());
  ASSERT_EQ(expected_sum_3, sum_3.toDecimalString());
  ASSERT_EQ(expected_sum_4, sum_4.toDecimalString());
}}'''


def generate_multiplication_test(id, a_bits, b_bits):
    x = random.randint(1 << a_bits, 1 << (a_bits + 1))
    y = random.randint(1 << b_bits, 1 << (b_bits + 1))

    return f'''
TEST_F(BigIntGeneratedTest, test_multiplication_of_{a_bits}_bit_number_by_{b_bits}_bit_number_{id}) {{
  BigInt x("{x}");
  BigInt y("{y}");
  string expected_prod = "{x * y}";
  BigInt prod = x * y;
  ASSERT_EQ(expected_prod, prod.toDecimalString());
}}'''


def generate_division_test(id, a_bits, b_bits):
    x = random.randint(1 << a_bits, 1 << (a_bits + 1))
    y = random.randint(1 << b_bits, 1 << (b_bits + 1))

    return f'''
TEST_F(BigIntGeneratedTest, test_division_of_{a_bits}_bit_number_over_{b_bits}_bit_number_{id}) {{
  {{
    BigInt x("{x}");
    BigInt y("{y}");
    string expected_q = "{x // y}";
    string expected_r = "{x % y}";
    BigInt q = x / y;
    BigInt r = x % y;
    ASSERT_EQ(expected_q, q.toDecimalString());
    ASSERT_EQ(expected_r, r.toDecimalString());
  }}
  {{
    BigInt x("{x}");
    BigInt y("{-y}");
    string expected_q = "{x // -y}";
    string expected_r = "{x % -y}";
    BigInt q = x / y;
    BigInt r = x % y;
    ASSERT_EQ(expected_q, q.toDecimalString());
    ASSERT_EQ(expected_r, r.toDecimalString());
  }}
  {{
    BigInt x("{-x}");
    BigInt y("{y}");
    string expected_q = "{-x // y}";
    string expected_r = "{-x % y}";
    BigInt q = x / y;
    BigInt r = x % y;
    ASSERT_EQ(expected_q, q.toDecimalString());
    ASSERT_EQ(expected_r, r.toDecimalString());
  }}
  {{
    BigInt x("{-x}");
    BigInt y("{-y}");
    string expected_q = "{-x // -y}";
    string expected_r = "{-x % -y}";
    BigInt q = x / y;
    BigInt r = x % y;
    ASSERT_EQ(expected_q, q.toDecimalString());
    ASSERT_EQ(expected_r, r.toDecimalString());
  }}
  {{
    BigInt x("{y}");
    BigInt y("{x}");
    string expected_q = "{y // x}";
    string expected_r = "{y % x}";
    BigInt q = x / y;
    BigInt r = x % y;
    ASSERT_EQ(expected_q, q.toDecimalString());
    ASSERT_EQ(expected_r, r.toDecimalString());
  }}
}}
'''


def main():
    with open('../src/test/bigint/BigIntGeneratedTest.cpp', 'w') as f:
        header = '''\
#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "../../main/bigint/BigInt.h"
#include "../../main/bigint/BigIntHelpers.h"

#include <string>

using namespace std;

class BigIntGeneratedTest : public ::testing::Test {

};
'''
        print(header, file=f)
        # for a_bits in [2048, 1024, 512, 256, 64, 32, 16, 8]:
        #     for b_bits in [2048, 1024, 512, 256, 64, 32, 16, 8]:
        for a_bits in [2048, 1024, 32, 16, 8]:
            for b_bits in [2048, 1024, 32, 16, 8]:
                if a_bits < b_bits:
                    continue

                for i in range(1, 21):
                    print(generate_addition_and_subtraction_test(i, a_bits, b_bits), file=f)
                    print(generate_multiplication_test(i, a_bits, b_bits), file=f)
                    print(generate_division_test(i, a_bits, b_bits), file=f)


if __name__ == '__main__':
    main()
