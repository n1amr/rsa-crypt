#ifndef RSA_CRYPT_REPL_H
#define RSA_CRYPT_REPL_H

#ifdef N1AMR_MULTIPLE_FILES
#include "bits/stdc++.h"
using namespace std;

#include "bigint/BigInt.h"
#endif //N1AMR_MULTIPLE_FILES

extern map<char, BigInt> cache;
extern map<char, bool> boolCache;

string eval(string line);

void readNumber(char name, string val);

BigInt &get(char name);
void refreshN();
void refreshPhi();
void refreshD();

string isXPrime(char name);

void startREPL();

#endif //RSA_CRYPT_REPL_H
