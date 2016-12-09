#ifndef RSA_DECIMALSTRINGHELPERS_H
#define RSA_DECIMALSTRINGHELPERS_H

#include <bits/stdc++.h>
using namespace std;

#define REVERSE(s) reverse((s).begin(), (s).end())
#define TRIM_ZEROS(s) (s) = (s).substr(min((unsigned long) (s).find_first_not_of('0'), (s).length() - 1))

string addToDecimalString(const string &s, char d);
string doubleDecimalString(const string &s) ;
string halveDecimalString(const string &s);
bool isDecimalStringOdd(const string &s);
string decimalStringToBitsString(const string &s);

#endif //RSA_DECIMALSTRINGHELPERS_H
