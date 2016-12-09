#ifndef RSA_DECIMALSTRINGHELPERS_H
#define RSA_DECIMALSTRINGHELPERS_H

#include <bits/stdc++.h>
using namespace std;

#define REVERSE(s) reverse((s).begin(), (s).end())

string decimalVectorToDecimalString(const vector<short> &v);
vector<short> decimalStringToDecimalVector(const string &s);

vector<short> addToDecimalVector(const vector<short> &s, short d);
vector<short> doubleDecimalVector(const vector<short> &s);
vector<short> halveDecimalVector(const vector<short> &v);
bool isDecimalVectorOdd(const vector<short> &s);
vector<bool> decimalVectorToBitsVector(const vector<short> &s);

#endif //RSA_DECIMALSTRINGHELPERS_H
