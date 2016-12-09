#include <iostream>
#include <bits/stdc++.h>
#include "DecimalStringHelpers.h"
using namespace std;

string doubleDecimalString(string s) {
  stringstream ss;

  int remainder = 0;

  for (int i = (int) (s.length() - 1); i >= 0; --i) {
    int d = 2 * (s[i] - '0') + remainder;
    ss << (char) ('0' + (d % 10));
    remainder = d / 10;
  }
  if (remainder)
    ss << (char) ('0' + (remainder % 10));

  string ans = ss.str();
  REVERSE_STRING(ans);
  return ans;
}

string addToDecimalString(string s, char d) {
  stringstream ss;

  int remainder = d - '0';

  for (int i = (int) (s.length() - 1); i >= 0; --i) {
    int x = (s[i] - '0');
    int y = x + remainder;
    ss << (char) ('0' + (y % 10));
    remainder = y / 10;
  }
  if (remainder)
    ss << (char) ('0' + (remainder % 10));

  string ans = ss.str();
  REVERSE_STRING(ans);
  return ans;
}

string halveDecimalString(string s) {
  stringstream ss;
  REVERSE_STRING(s);

  int remainder = 0;
  while (!s.empty()) {
    int x = s.back() - '0' + 10 * remainder;
    s.pop_back();
    int y = x / 2;
    remainder = x % 2;
    ss << ((char) ('0' + y));
  }
  string ans = ss.str();
  ans = ans.substr(min((unsigned long) ans.find_first_not_of('0'), ans.length() - 1));
  return ans;
}

bool isDecimalStringOdd(string s) {
  return (bool) ((s[s.length() - 1] - '0') & 1);
}

string decimalStringToBitsString(string s) {
  stringstream ss;

  while (!s.empty() && !(s.length() == 1 && s == "0")) {
    ss << isDecimalStringOdd(s);
    s = halveDecimalString(s);
  }

  string ans = ss.str();
  REVERSE_STRING(ans);
  return ans;
}
