"""
COSC413 Assignment 1
Jamie McCloskey
RSA encryption, decryption, and authentication
Reads plaintext from the file text.txt and performs a demonstration of RSA with random key pairs
"""

import random

""" Number of times we run the composite-checking algorithm
We have about (1/4)^100 chance of false positives
"""
PRIME_TRIALS = 100


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


def modular_inverse(n, mod):
    gcd, d, y = euclid(n, mod)
    while d < 0:
        d += mod
    return d


def encrypt(m, e, n):
    return modular_pow(m, e, n) % n


p, q, e, n, phi, d = None, None, None, None, None, None


def refresh(p_, q_, e_):
    global p, q, e, n, phi, d
    if not all([p_, q_, e_]):
        return
    p, q, e = p_, q_, e_
    n = p * q
    phi = (p - 1) * (q - 1) if p != q else p * (p - 1)
    d = modular_inverse(e, phi)


def main():
    global p, q, e, n, phi, d

    cmd = ""
    while cmd != "Quit".lower():
        cmd = input().lower()
        if cmd.startswith("P=".lower()):
            p = int(cmd[2:])
            refresh(p, q, e)
        elif cmd.startswith("Q=".lower()):
            q = int(cmd[2:])
            refresh(p, q, e)
        elif cmd.startswith("E=".lower()):
            e = int(cmd[2:])
            refresh(p, q, e)

        elif cmd.startswith("IsPPrime".lower()):
            print("Yes") if is_prime(p) else print("No")
        elif cmd.startswith("IsQPrime".lower()):
            print("Yes") if is_prime(q) else print("No")

        elif cmd == "PrintP".lower():
            print(p)
        elif cmd == "PrintQ".lower():
            print(q)
        elif cmd == "PrintE".lower():
            print(e)

        elif cmd.startswith("PrintN".lower()):
            print(n)
        elif cmd.startswith("PrintPhi".lower()):
            print(phi)
        elif cmd.startswith("PrintD".lower()):
            print(d)

        elif cmd.startswith("EncryptPublic=".lower()):
            m = int(cmd[14:])
            print(encrypt(m, e, n))
        elif cmd.startswith("EncryptPrivate=".lower()):
            m = int(cmd[15:])
            print(encrypt(m, d, n))


if __name__ == '__main__':
    main()
