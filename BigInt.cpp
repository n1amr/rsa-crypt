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

