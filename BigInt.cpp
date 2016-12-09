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

BigInt::BigInt(const string &s) {
  string bitString = decimalStringToBitsString(s);
  int nBits = (int) bitString.length();
  int nCells = (nBits + CELL_TYPE_LENGTH - 1) / CELL_TYPE_LENGTH;
  REVERSE_STRING(bitString);

  for (int cellNum = 0; cellNum < nCells; cellNum++) {
    string cellBits = bitString.substr(cellNum * CELL_TYPE_LENGTH, CELL_TYPE_LENGTH);
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
  REVERSE_STRING(ans);
  ans = ans.substr(min((unsigned long) ans.find_first_not_of('0'), ans.length() - 1));
  return ans;
}

string BigInt::toDecimalString() const {
  stringstream ss;
  string bitString = toBitsString();
  REVERSE_STRING(bitString);

  string s = "0";
  while (!bitString.empty()) {
    s = doubleDecimalString(s);
    s = addToDecimalString(s, bitString.back());
    bitString.pop_back();
  }
  ss << s;
  return ss.str();
}

