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

void addCells(CELL_T cell1, CELL_T cell2, CELL_T remainder, CELL_T &ans, CELL_T &remainder_out) {
  DOUBLE_CELL_T sum = ((DOUBLE_CELL_T) cell1) + cell2 + remainder;
  ans = (CELL_T) sum;
  remainder_out = (CELL_T) (sum >> (CELL_TYPE_LENGTH));
}

BigInt BigInt::add(const BigInt &n) {
  CONTAINER_T<CELL_T> newData;

  const CONTAINER_T<CELL_T> &data1 = this->data;
  const CONTAINER_T<CELL_T> &data2 = n.data;

  CELL_T remainder = 0;
  int i = 0, j = 0;
  while (i < data1.size() || j < data2.size()) {
    CELL_T cell_1 = (CELL_T) (i < data1.size() ? data1[i++] : 0);
    CELL_T cell_2 = (CELL_T) (j < data2.size() ? data2[j++] : 0);

    CELL_T ans;
    addCells(cell_1, cell_2, remainder, ans, remainder);
    newData.push_back(ans);
  }
  if (remainder)
    newData.push_back(remainder);

  return BigInt(newData);
}

BigInt BigInt::shiftCell() {
  REVERSE(data);
  data.push_back(0);
  REVERSE(data);
  BigInt ans(data);
  data.pop_back();
  return ans;
}

void multiplyCells(CELL_T cell1, CELL_T cell2, CELL_T &ans, CELL_T &remainder_out) {
  DOUBLE_CELL_T product = ((DOUBLE_CELL_T) cell1) * cell2;
  ans = (CELL_T) product;
  remainder_out = (CELL_T) (product >> (CELL_TYPE_LENGTH));
}

BigInt BigInt::multiply(const BigInt &n) {
  BigInt sum;

  const CONTAINER_T<CELL_T> &cells_1 = this->data;
  const CONTAINER_T<CELL_T> &cells_2 = n.data;

  CONTAINER_T<CELL_T> shifted_cells = cells_2;
  CONTAINER_T<CELL_T> single_cell_product;
  REVERSE(shifted_cells);

  CELL_T c, c2, old_remainder, mul_remainder, add_remainder, product;
  for (CELL_T c1 : cells_1) {
    single_cell_product.clear();
    old_remainder = mul_remainder = add_remainder = 0;

    for (auto it = shifted_cells.rbegin(); it != shifted_cells.rend(); ++it) {
      c2 = *it;

      multiplyCells(c1, c2, product, mul_remainder);
      addCells(product, old_remainder, 0, c, add_remainder);

      single_cell_product.push_back(c);
      addCells(mul_remainder, add_remainder, 0, old_remainder, add_remainder);
    }
    if (old_remainder)
      single_cell_product.push_back(old_remainder);

    sum = sum.add(BigInt(single_cell_product));
    shifted_cells.push_back(0);
  }

  return sum;
}

