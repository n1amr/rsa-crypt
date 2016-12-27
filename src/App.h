#ifndef RSA_APP_H
#define RSA_APP_H

#include <iostream>

#ifdef N1AMR_MULTIPLE_FILES

#include "bits/stdc++.h"
using namespace std;

#include "bigint/BigInt.h"
#endif

#define MAX_MILLER_RABIN_TRIALS_COUNT 5
#define COMPOSITE 0
#define INCLUSIVE 1

BigInt random(BigInt from, BigInt to);
bool millerRabinTest(BigInt n);
bool isPrime(BigInt n);
BigInt inverse(BigInt a, BigInt mod);
void appLoop();

#endif //RSA_APP_H
