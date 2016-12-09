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
  vector<short> v = decimalStringToDecimalVector(s);

  vector<bool> bitVector = decimalVectorToBitsVector(v);
  while (bitVector.size() % CELL_TYPE_LENGTH != 0)
    bitVector.push_back(0);

  int nBits = (int) bitVector.size();
  int nCells = (nBits + CELL_TYPE_LENGTH - 1) / CELL_TYPE_LENGTH;

  for (int i = 0; i < nCells; i++) {
    int p = CELL_TYPE_LENGTH * i;

    CELL_T cell = 0;
    for (int j = CELL_TYPE_LENGTH - 1; j >= 0; --j) {
      cell = (CELL_T) ((cell << 1) + bitVector[p + j]);
    }
    data.push_back(cell);
  }
}

string BigInt::toCellsString() const {
  stringstream ss;
  ss << "BigInt({";
  for (auto it = data.rbegin(); it != data.rend(); ++it)
    ss << ((unsigned long long int) *it) << ", ";
  ss << "})";
  return ss.str();
}

string BigInt::toBitsString() const {
  auto v = toBitsVector();

  stringstream ss;
  for (auto it = v.rbegin(); it != v.rend(); ++it)
    ss << (*it);
  return ss.str();
}

vector<bool> BigInt::toBitsVector() const {
  vector<bool> v;

  for (auto it = data.begin(); it != data.end(); ++it) {
    CELL_T cell = *it;
    for (int i = 0; i < CELL_TYPE_LENGTH; ++i) {
      v.push_back((bool) (cell % 2));
      cell /= 2;
    }
  }

  while (v.size() > 1 && v.back() == 0)
    v.pop_back();
  return v;
}


string BigInt::toDecimalString() const {
  auto bits = toBitsVector();
  vector<short> digits;
  digits.push_back(0);

  for (auto it = bits.rbegin(); it != bits.rend(); ++it) {
    digits = doubleDecimalVector(digits);
    digits = addToDecimalVector(digits, *it);
  }

  return decimalVectorToDecimalString(digits);
}

BigInt BigInt::add(const BigInt &n) {
  return BigInt("1234");
}

