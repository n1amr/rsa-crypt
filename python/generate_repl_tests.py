"""
COSC413 Assignment 1
Jamie McCloskey
RSA encryption, decryption, and authentication
Reads plaintext from the file text.txt and performs a demonstration of RSA with random key pairs
"""
import os
import sys
import math
import random

PRIME_TRIALS = 100  # number of times we run the composite-checking algorithm
# We have about (1/4)^100 chance of false positives
BLOCK_SIZE = 1024  # The plaintext message will be split into chunks of this size before encryption
MAX_CHAR = 1024  # Number of different characters that we can encrypt
DIGITS = 1024  # Number of decimal digits to use for p and q


def modular_pow(base, p, mod):
    """ Computes base^p mod mod using repeated squaring
    """
    ans = 1
    index = 0
    while 1 << index <= p:
        if p & (1 << index):
            ans = (ans * base) % mod
        index += 1
        base = (base * base) % mod
    return ans


def euclid(a, b):
    """ Finds x and y such that ax + by = gcd(a,b)
        Returns the tuple (gcd(a,b), x, y)
    """
    last_b1, b1 = 1, 0
    last_b2, b2 = 0, 1
    last_b3, b3 = a, b
    while b3 != 0:
        q = last_b3 // b3
        last_b1, b1 = b1, last_b1 - q * b1
        last_b2, b2 = b2, last_b2 - q * b2
        last_b3, b3 = b3, last_b3 - q * b3

    return last_b3, last_b1, last_b2


def is_witness(a, k, q, n):
    """ Is a a Miller-Rabin witness to the compositeness of n?
    """
    x = modular_pow(a, q, n)
    if x == 1 or x == n - 1:
        return False
    for r in range(k):
        x = (x * x) % n
        if x == 1:
            return True
        if x == n - 1:
            return False
    return True


def is_prime(n):
    """ Determines if a number n is probably prime, using the Miller-Rabin test.
    """
    if n < 2:
        return False
    if n == 2 or n == 3:
        return True
    if n % 2 == 0:
        return False

    k = 0
    q = n - 1
    while q % 2 == 0:
        q //= 2
        k += 1
    for i in range(PRIME_TRIALS):
        a = random.randint(2, n - 2)
        if is_witness(a, k, q, n):
            return False
    return True


def is_prime_slow(n):
    """ Slow trial division primality testing algorithm
        (Always correct)
    """
    if n <= 1:
        return False
    x = 2
    while x * x <= n:
        if n % x == 0:
            return False
        x += 1
    return True


def get_prime(bits):
    """ Returns a randomly chosen prime number with a specified number of decimal digits
    """
    while True:
        x = random.randint(2 ** (bits - 1), (2 ** bits) - 1)
        if is_prime(x):
            return x


def find_d(e, phi):
    gcd, d, y = euclid(e, phi)
    while d < 0:
        d += phi
    return d


def encrypt(m, e, n):
    return modular_pow(m, e, n)


p, q, e, n, phi, d = None, None, None, None, None, None


def refresh(p_, q_, e_):
    global p, q, e, n, phi, d
    if not all([p_, q_, e_]):
        return
    p, q, e = p_, q_, e_
    n = p * q
    phi = (p - 1) * (q - 1) if p != q else p * (p - 1)
    d = find_d(e, phi)


def generate(file_in, file_out, bits, name, prime):
    p, q, e, n, phi, d, e, m, c = [None] * 9

    # Generate keys
    while True:
        if prime:
            p = get_prime(bits)
            q = get_prime(bits)
        else:
            p = get_prime(bits // 2) * get_prime(bits // 2)
            q = get_prime(bits // 2) * get_prime(bits // 2)

        e = get_prime(2 * bits)
        p_prime = is_prime(p)
        q_prime = is_prime(q)

        if prime:
            n = p * q
            phi = (p - 1) * (q - 1) if p != q else p * (p - 1)
            d = find_d(e, phi)

            m = random.randint(2 ** (2 * bits - 1), (2 ** (2 * bits)) - 1) % n
            c = encrypt(m, e, n)
            c_inv = encrypt(c, d, n)

            if m == c_inv and euclid(e, phi)[0] == 1 and euclid(d, phi)[
                0] == 1 and euclid(e, n)[0] == 1 and euclid(d, n)[0] == 1:
                assert m == c_inv
                break
        else:
            break

    code = get_test_case_code(name, p, q, e, p_prime, q_prime, n, phi, d, m, c,
                              prime)

    def print_input(file, line):
        file.write(f"{line}\n")
        print(f'>>> {line}')

    def print_output(file, line):
        file.write(f"{line}\n")
        print(f'{line}')

    print_input(file_in, f'P={p}')
    print_input(file_in, f'Q={q}')
    print_input(file_in, f'E={e}')

    print_input(file_in, 'IsPPrime')
    print_output(file_out, 'Yes' if p_prime else 'No')
    print_input(file_in, 'IsQPrime')
    print_output(file_out, 'Yes' if q_prime else 'No')

    if p_prime and q_prime:
        print_input(file_in, 'PrintN')
        print_output(file_out, n)

        print_input(file_in, 'PrintPhi')
        print_output(file_out, phi)

        print_input(file_in, 'PrintD')
        print_output(file_out, d)

        print_input(file_in, f'EncryptPublic={m}')
        print_output(file_out, c)

        print_input(file_in, f'EncryptPrivate={c}')
        print_output(file_out, c_inv)

    print_input(file_in, 'Quit')

    return code


CODE_HEADER = '''
#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "../main/bigint/BigInt.h"
#include "../main/REPL.h"

class REPLTest : public ::testing::Test {

};
'''


def get_test_case_code(name, p, q, e, p_prime, q_prime, n, phi, d, m, c, prime):
    code = f'''
TEST_F(REPLTest, {name}) {{
  eval("P={p}");
  eval("Q={q}");
  eval("E={e}");
  EXPECT_EQ("{'Yes' if p_prime else 'No'}", eval("IsPPrime"));
  EXPECT_EQ("{'Yes' if p_prime else 'No'}", eval("IsQPrime"));
  '''
    if prime:
        code += f'''EXPECT_EQ("{n}", eval("PrintN"));
  EXPECT_EQ("{phi}", eval("PrintPhi"));
  EXPECT_EQ("{d}", eval("PrintD"));
  EXPECT_EQ("{c}", eval("EncryptPublic={m}"));
  EXPECT_EQ("{m}", eval("EncryptPrivate={c}"));
  EXPECT_EQ("{m}", eval("EncryptPrivate={c}"));
  EXPECT_EQ("{c}", eval("EncryptPublic={m}"));
  '''
    code += f'''
  eval("Quit");
}}
'''
    return code


def main(*args):
    if len(args) != 4:
        print(f'Usage: python generate_repl_tests.py '
              f'<cpp file> <generated dir> <count>')
        return

    file = open(args[1], 'w')
    dir = args[2]
    count = int(args[3])
    pad = math.floor(math.log10(count)) + 1

    code = CODE_HEADER

    for bits in [4, 8, 16, 64, 128, 256, 512]:
        for i in range(1, count + 1):
            path_in = f'{dir}/test_{bits}_bits_{i:0{pad}}.in'
            path_out = f'{dir}/test_{bits}_bits_{i:0{pad}}.out'

            if not os.path.exists(dir):
                os.makedirs(dir)

            file_in = open(path_in, 'w')
            file_out = open(path_out, 'w')

            prime = (i % 2 == 0)
            code += generate(file_in, file_out, bits,
                             f'test_encryption_{bits}_bits_'
                             f'example_{i:0{pad}}', prime)

            file_in.close()
            file_out.close()

    print(code, file=file)
    file.close()


if __name__ == '__main__':
    main(*sys.argv)
