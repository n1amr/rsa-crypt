#ifndef BIG_INT_HELPERS_H
#define BIG_INT_HELPERS_H

#ifdef N1AMR_MULTIPLE_FILES
#include <bits/stdc++.h>
using namespace std;

#include "BigInt.h"
#endif //N1AMR_MULTIPLE_FILES

#define REVERSE(s) reverse((s).begin(), (s).end())

#define ZERO_TRIMMED_VECTOR(v) ( \
  ((v).size() > 1 && (v).back() != 0) || \
  (v).size() == 1)

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
