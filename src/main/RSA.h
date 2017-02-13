#ifndef RSA_CRYPT_RSA_H
#define RSA_CRYPT_RSA_H

#ifdef N1AMR_MULTIPLE_FILES
#include "bits/stdc++.h"
using namespace std;

#include "bigint/BigInt.h"
#endif //N1AMR_MULTIPLE_FILES

#define MAX_MILLER_RABIN_TRIALS_COUNT 5
#define COMPOSITE 0
#define INCLUSIVE 1

BigInt random(const BigInt &from, const BigInt &to);
bool millerRabinTest(const BigInt &n);
bool isPrime(const BigInt &n);
BigInt inverse(const BigInt &a, const BigInt &mod);

#endif //RSA_CRYPT_RSA_H
