#include <iostream>
#include <bits/stdc++.h>
#include "DecimalStringHelpers.h"
using namespace std;

string decimalVectorToDecimalString(const vector<short> &v) {
  stringstream ss;
  for (auto it = v.rbegin(); it != v.rend(); ++it)
    ss << (*it);
  return ss.str();
}

vector<short> decimalStringToDecimalVector(const string &s) {
  vector<short> v;
  for (auto it = s.rbegin(); it != s.rend(); ++it)
    v.push_back(*it - '0');
  return v;
}

vector<short> doubleDecimalVector(const vector<short> &v) {
  vector<short> ans;

  short d, remainder = 0;
  for (auto it = v.begin(); it != v.end(); ++it) {
    d = (short) (2 * (*it) + remainder);
    ans.push_back((short) (d % 10));
    remainder = (short) (d / 10);
  }
  if (remainder)
    ans.push_back((short) (remainder % 10));

  return ans;
}

vector<short> addToDecimalVector(const vector<short> &v, short d) {
  vector<short> ans;

  short remainder = d;
  for (auto it = v.begin(); it != v.end(); ++it) {
    int x = (*it) + remainder;
    ans.push_back((short) (x % 10));
    remainder = (short) (x / 10);
  }
  if (remainder)
    ans.push_back((short) (remainder % 10));

  return ans;
}

vector<short> halveDecimalVector(const vector<short> &v) {
  vector<short> ans;

  short x, remainder = 0;
  for (auto it = v.rbegin(); it != v.rend(); ++it) {
    x = (short) (10 * remainder + (*it));
    remainder = (short) (x % 2);
    ans.push_back((short) (x / 2));
  }

  REVERSE(ans);
  while (ans.size() > 1 && ans.back() == 0)
    ans.pop_back();

  return ans;
}

bool isDecimalVectorOdd(const vector<short> &v) {
  return (bool) (v.front() % 2);
}

vector<bool> decimalVectorToBitsVector(const vector<short> &v) {
  vector<bool> ans;

  vector<short> tmp = v;

  while (!tmp.empty() && !(tmp.size() == 1 && tmp.back() == 0)) {
    bool x = isDecimalVectorOdd(tmp);
    ans.push_back(x);
    tmp = halveDecimalVector(tmp);
  }

  if (ans.empty())
    ans.push_back(0);
  return ans;
}

