#include <bits/stdc++.h>
#include "BigInt.h"
#include "DecimalStringHelpers.h"
using namespace std;

BigInt::BigInt() {
  data.push_back((CELL_T) 0);
}

BigInt::BigInt(const CONTAINER_T<CELL_T> &init) {
  data = CONTAINER_T<CELL_T>(init);
}

BigInt::BigInt(const string &s) {
  string bitString = decimalStringToBitsString(s);
  REVERSE(bitString);

  int nBits = (int) bitString.length();
  int nCells = (nBits + CELL_TYPE_LENGTH - 1) / CELL_TYPE_LENGTH;

  for (int i = 0; i < nCells; i++) {
    string cellBits = bitString.substr(i * CELL_TYPE_LENGTH, CELL_TYPE_LENGTH);
    CELL_T cell = 0;
    while (!cellBits.empty()) {
      cell = (CELL_T) ((cell << 1) + ((int) cellBits.back() - '0'));
      cellBits.pop_back();
    }
    data.push_back(cell);
  }
}

string BigInt::toCellsString() const {
  stringstream ss;
  ss << "BigInt({";
  for (auto it = data.begin(); it != data.end(); ++it)
    ss << ((unsigned long long int) *it) << ", ";
  ss << "})";
  return ss.str();
}

string BigInt::toBitsString() const {
  stringstream ss;
  for (auto it = data.begin(); it != data.end(); ++it) {
    CELL_T cell = *it;
    for (int i = 0; i < CELL_TYPE_LENGTH; ++i) {
      ss << cell % 2;
      cell /= 2;
    }
  }

  string ans = ss.str();
  REVERSE(ans);
  TRIM_ZEROS(ans);
  return ans;
}

string BigInt::toDecimalString() const {
  stringstream ss;
  string bitString = toBitsString();
  REVERSE(bitString);

  string s = "0";
  while (!bitString.empty()) {
    s = doubleDecimalString(s);
    s = addToDecimalString(s, bitString.back());
    bitString.pop_back();
  }
  ss << s;
  return ss.str();
}

BigInt BigInt::add(const BigInt &n) {
  return BigInt("1234");
}

