#ifdef N1AMR_MULTIPLE_FILES
#include <bits/stdc++.h>
using namespace std;

#include "BigIntHelpers.h"
#endif //N1AMR_MULTIPLE_FILES

string decimalVecToDecimalString(const vector<short> &v) {
  stringstream ss;
  for (auto it = v.rbegin(); it != v.rend(); it++)
    ss << (*it);
  return ss.str();
}

vector<short> decimalStringToDecimalVec(const string &s) {
  vector<short> v;
  v.reserve(s.size());

  short d;
  for (auto it = s.rbegin(); it != s.rend(); it++) {
    d = *it - '0';
    if (d >= 0 && d < 10)
      v.push_back(d);
  }
  return v;
}

vector<short> doubleDecimalVec(const vector<short> &v) {
  vector<short> ans;
  ans.reserve(v.size() + 1);

  short d, remainder = 0;
  for (auto it = v.begin(); it != v.end(); it++) {
    d = (short) (2 * (*it) + remainder);
    ans.push_back((short) (d % 10));
    remainder = (short) (d / 10);
  }
  if (remainder)
    ans.push_back((short) (remainder % 10));

  return ans;
}

vector<short> addToDecimalVec(const vector<short> &v, short d) {
  vector<short> ans;
  ans.reserve(v.size() + 1);

  short remainder = d;
  for (auto it = v.begin(); it != v.end(); it++) {
    int x = (*it) + remainder;
    ans.push_back((short) (x % 10));
    remainder = (short) (x / 10);
  }
  if (remainder)
    ans.push_back((short) (remainder % 10));

  return ans;
}

vector<short> halveDecimalVec(const vector<short> &v) {
  vector<short> ans;
  ans.reserve(v.size());

  short x, remainder = 0;
  for (auto it = v.rbegin(); it != v.rend(); it++) {
    x = (short) (10 * remainder + (*it));
    remainder = (short) (x % 2);
    ans.push_back((short) (x / 2));
  }

  REVERSE(ans);
  while (ans.size() > 1 && ans.back() == 0)
    ans.pop_back();

  return ans;
}

bool isDecimalVecOdd(const vector<short> &v) {
  return (bool) (v.front() % 2);
}

vector<bool> decimalVecToBitsVec(const vector<short> &v) {
  vector<bool> ans;
  ans.reserve(v.size() * 4);

  vector<short> tmp = v;

  while (!tmp.empty() && !(tmp.size() == 1 && tmp.back() == 0)) {
    bool x = isDecimalVecOdd(tmp);
    ans.push_back(x);
    tmp = halveDecimalVec(tmp);
  }

  if (ans.empty())
    ans.push_back(0);
  return ans;
}

void printVectorReversed(CELLS_CONTAINER_T v, string name) {
  cout << name << " = ";
  for (auto it = v.rbegin(); it != v.rend(); it++)
    cout << ((long long) *it) << " ";
  cout << endl;
}

void printVector(CELLS_CONTAINER_T v, string name) {
  REVERSE(v);
  printVectorReversed(v, name);
  REVERSE(v);
}
