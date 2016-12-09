#include <bits/stdc++.h>
#include "BigInt.h"


string shiftRightDecimal(string s);

string addToDecimalString(string s, char d);

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
  stringstream nss;
  queue<CELL_T> tmp(data);
  tmp.push((CELL_T) 0);

  while (!tmp.empty()) {
    CELL_T cell = tmp.front();
    tmp.pop();
    for (int i = 0; i < CELL_TYPE_LENGTH; ++i) {
      nss << cell % 2;
      cell /= 2;
    }
  }
  string bitString = nss.str();
  reverse(bitString.begin(), bitString.end());
  unsigned long firstOneIndex = bitString.find('1');
  bitString = bitString.substr(min(firstOneIndex, bitString.length() - 1));
  return bitString;
}

string BigInt::toDecimalString() const {
  stringstream nss;
  string bitString = toBitsString();
  string n = "0";
  while (!bitString.empty()) {
    n = shiftRightDecimal(n);
    n = addToDecimalString(n, bitString.back());
    bitString.pop_back();
  }
  nss << n;
  return nss.str();
}

string shiftRightDecimal(string s) {
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
  reverse(ans.begin(), ans.end());
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
  reverse(ans.begin(), ans.end());
  return ans;
}
