#ifndef RSA_DECIMAL_STRING_HELPERS_H
#define RSA_DECIMAL_STRING_HELPERS_H

#include <bits/stdc++.h>
#include "BigInt.h"
using namespace std;

#define REVERSE(s) reverse((s).begin(), (s).end())

string decimalVecToDecimalString(const vector<short> &v);
vector<short> decimalStringToDecimalVec(const string &s);

vector<short> addToDecimalVec(const vector<short> &s, short d);
vector<short> doubleDecimalVec(const vector<short> &s);
vector<short> halveDecimalVec(const vector<short> &v);
bool isDecimalVecOdd(const vector<short> &s);
vector<bool> decimalVecToBitsVec(const vector<short> &s);

void printVectorReversed(string name, CONTAINER_T<CELL_T> v); // TODO

#endif //RSA_DECIMALSTRINGHELPERS_H