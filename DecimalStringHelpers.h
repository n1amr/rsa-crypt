#ifndef RSA_DECIMALSTRINGHELPERS_H
#define RSA_DECIMALSTRINGHELPERS_H

#include <bits/stdc++.h>
using namespace std;

#define REVERSE_STRING(s) reverse((s).begin(), (s).end())

string addToDecimalString(string s, char d);
string doubleDecimalString(string s);
string halveDecimalString(string s);
bool isDecimalStringOdd(string s);
string decimalStringToBitsString(string s);

#endif //RSA_DECIMALSTRINGHELPERS_H
