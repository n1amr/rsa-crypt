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
  vector<short> v = decimalStringToDecimalVec(s);

  vector<bool> bitVector = decimalVecToBitsVec(v);
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
    digits = doubleDecimalVec(digits);
    digits = addToDecimalVec(digits, *it);
  }

  return decimalVecToDecimalString(digits);
}

BigInt BigInt::add(const BigInt &n) {
  CONTAINER_T<CELL_T> newData;

  const CONTAINER_T<CELL_T> &data1 = this->data;
  const CONTAINER_T<CELL_T> &data2 = n.data;

  CELL_T remainder = 0;
  int i = 0, j = 0;
  while (i < data1.size() || j < data2.size()) {
    CELL_T cell1 = (CELL_T) (i < data1.size() ? data1[i++] : 0);
    CELL_T cell2 = (CELL_T) (j < data2.size() ? data2[j++] : 0);

    CELL_T maxCell = max(cell1, cell2);
    CELL_T resultCell = (CELL_T) (cell1 + cell2 + remainder);

    newData.push_back(resultCell);
    remainder = (CELL_T) ((resultCell < maxCell)
                          || (remainder == 1 && resultCell == cell1 && resultCell == cell2));
  }
  if (remainder)
    newData.push_back(remainder);

  return BigInt(newData);
}

