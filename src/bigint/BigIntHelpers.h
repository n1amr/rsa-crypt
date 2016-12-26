#ifndef BIG_INT_HELPERS_H
#define BIG_INT_HELPERS_H

#include <bits/stdc++.h>
using namespace std;

#ifdef N1AMR_MULTIPLE_FILES
#include "BigInt.h"
#endif

#define REVERSE(s) reverse((s).begin(), (s).end())

string decimalVecToDecimalString(const vector<short> &v);
vector<short> decimalStringToDecimalVec(const string &s);

vector<short> addToDecimalVec(const vector<short> &s, short d);
vector<short> doubleDecimalVec(const vector<short> &s);
vector<short> halveDecimalVec(const vector<short> &v);
inline bool isDecimalVecOdd(const vector<short> &s);
vector<bool> decimalVecToBitsVec(const vector<short> &s);

void printVectorReversed(CELLS_CONTAINER_T v, string name = "");
void printVector(CELLS_CONTAINER_T v, string name = "");

#endif //BIG_INT_HELPERS_H
