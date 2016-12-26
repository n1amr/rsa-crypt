#ifndef RSA_APP_H
#define RSA_APP_H

#include <iostream>
#include "bits/stdc++.h"
using namespace std;

#ifdef N1AMR_MULTIPLE_FILES
#include "bigint/BigInt.h"
#endif

#define COMPOSITE 0
#define INCLUSIVE 1

BigInt random(BigInt from, BigInt to);
bool MRTEST(BigInt n);
bool isPrime(BigInt n);
BigInt generate(BigInt p, BigInt q, BigInt e);
BigInt inverse(BigInt a, BigInt mod);
void appLoop();

#endif //RSA_APP_H
