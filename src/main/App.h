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

extern map<char, BigInt> cache;
extern map<char, bool> boolCache;

string eval(string line);

void readNumber(char name, string val);

BigInt &get(char name);
void refreshN();
void refreshPhi();
void refreshD();

string isXPrime(char name);

void appLoop();

#endif //RSA_APP_H
