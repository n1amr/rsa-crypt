#include <iostream>
#include <bits/stdc++.h>
#include "DecimalStringHelpers.h"
using namespace std;

string doubleDecimalString(const string &s) {
  stringstream ss;

  int remainder = 0;

  for (auto it = s.rbegin(); it != s.rend(); ++it) {
    int d = 2 * (*it - '0') + remainder;
    ss << (char) ('0' + (d % 10));
    remainder = d / 10;
  }
  if (remainder)
    ss << (char) ('0' + (remainder % 10));

  string ans = ss.str();
  REVERSE(ans);
  return ans;
}

string addToDecimalString(const string &s, char d) {
  stringstream ss;

  int remainder = d - '0';

  for (auto it = s.rbegin(); it != s.rend(); ++it) {
    int x = (*it - '0') + remainder;
    ss << (char) ('0' + (x % 10));
    remainder = x / 10;
  }
  if (remainder)
    ss << (char) ('0' + (remainder % 10));

  string ans = ss.str();
  REVERSE(ans);
  return ans;
}

string halveDecimalString(const string &s) {
  stringstream ss;

  int x, remainder = 0;
  for (auto it = s.begin(); it != s.end(); ++it) {
    x = 10 * remainder + (*it - '0');
    remainder = x % 2;
    ss << ((char) ('0' + x / 2));
  }

  string ans = ss.str();
  TRIM_ZEROS(ans);
  return ans;
}

bool isDecimalStringOdd(const string &s) {
  return (bool) ((s[s.length() - 1] - '0') & 1);
}

string decimalStringToBitsString(const string &s) {
  stringstream ss;

  string tmp = s;
  while (!tmp.empty() && !(tmp.length() == 1 && tmp == "0")) {
    ss << isDecimalStringOdd(tmp);
    tmp = halveDecimalString(tmp);
  }

  string ans = ss.str();
  if (ans.empty())
    ans = "0";
  REVERSE(ans);
  return ans;
}
