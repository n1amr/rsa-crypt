#ifndef RSA_APP_H
#define RSA_APP_H

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
void appLoop();

#endif //RSA_APP_H
