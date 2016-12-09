#include <bits/stdc++.h>
#include "BigInt.h"
#include "DecimalStringHelpers.h"
using namespace std;

BigInt::BigInt() {
  // TODO
}

BigInt::BigInt(const CONTAINER_T<CELL_T> &init) {
  // TODO
  data = CONTAINER_T<CELL_T>(init);
}

string BigInt::toCellsString() const {
  stringstream ss;
  ss << "BigInt({";
  for (CELL_T cell : data)
    ss << ((long long int) cell) << ", ";
  ss << "})";
  return ss.str();
}

string BigInt::toBitsString() const {
  stringstream ss;
  queue<CELL_T> tmp(data);
  tmp.push((CELL_T) 0);

  while (!tmp.empty()) {
    CELL_T cell = tmp.front();
    tmp.pop();
    for (int i = 0; i < CELL_TYPE_LENGTH; ++i) {
      ss << cell % 2;
      cell /= 2;
    }
  }

  string ans = ss.str();
  reverse(ans.begin(), ans.end());
  ans = ans.substr(min((unsigned long) ans.find_first_not_of('0'), ans.length() - 1));
  return ans;
}

string BigInt::toDecimalString() const {
  stringstream ss;
  string bitString = toBitsString();
  string n = "0";
  while (!bitString.empty()) {
    n = doubleDecimalString(n);
    n = addToDecimalString(n, bitString.back());
    bitString.pop_back();
  }
  ss << n;
  return ss.str();
}
