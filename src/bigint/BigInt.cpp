#include <bits/stdc++.h>
#include "BigInt.h"
#include "DecimalStringHelpers.h"
using namespace std;

CONTAINER_T<CELL_T> invert_cells(const CONTAINER_T<CELL_T> &cells);
void addCells(CELL_T cell1, CELL_T cell2, CELL_T remainder, CELL_T &ans, CELL_T &remainder_out);
void multiplyCells(CELL_T cell1, CELL_T cell2, CELL_T &ans, CELL_T &remainder_out);

BigInt::BigInt()
    : data(CONTAINER_T<CELL_T> {0}) {}

BigInt::BigInt(const CONTAINER_T<CELL_T> &init, SIGN_T sign)
    : data(CONTAINER_T<CELL_T> {init}), sign(sign) {}

BigInt::BigInt(const string &s) {
  if (!s.empty() && s[0] == '-')
    sign = NEGATIVE;
  string absDecimalString = sign == NEGATIVE ? s.substr(1) : s;
  vector<short> v = decimalStringToDecimalVec(absDecimalString);

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

  if (sign == NEGATIVE)
    data = this->negate().data;
}

BigInt BigInt::ZERO("0");
BigInt BigInt::ONE("1");

bool BigInt::isZero(const BigInt &n) {
  return n.data.size() == 1 && n.data[0] == 0;
}

bool BigInt::isPositive(const BigInt &n) {
  return !isZero(n) && n.sign == POSITIVE;
}

bool BigInt::isNegative(const BigInt &n) {
  return !isZero(n) && n.sign == NEGATIVE;
}

BigInt BigInt::add(const BigInt &n1, const BigInt &n2) {
  CONTAINER_T<CELL_T> result_cells;

  const CONTAINER_T<CELL_T> &cells_1 = n1.data;
  const CONTAINER_T<CELL_T> &cells_2 = n2.data;

  CELL_T c1, c2, remainder = 0, ans;
  int i = 0, j = 0;
  while (i < cells_1.size() || j < cells_2.size()) {
    c1 = (CELL_T) (i < cells_1.size() ? cells_1[i++] : n1.sign == POSITIVE ? 0 : ~0);
    c2 = (CELL_T) (j < cells_2.size() ? cells_2[j++] : n2.sign == POSITIVE ? 0 : ~0);

    addCells(c1, c2, remainder, ans, remainder);
    result_cells.push_back(ans);
  }

  if (n1.sign == n2.sign) {
    if (n1.sign == POSITIVE && remainder)  // POSITIVE + POSITIVE
      result_cells.push_back(remainder);
    else if (n1.sign == NEGATIVE && !remainder)  // NEGATIVE + NEGATIVE
      result_cells.push_back((CELL_T) (-2));

    return BigInt(result_cells, n1.sign);
  } else { // POSITIVE + NEGATIVE
    return BigInt(result_cells, (SIGN_T) (remainder ? POSITIVE : NEGATIVE));
  }
}

BigInt BigInt::multiply(const BigInt &n1, const BigInt &n2) {
  BigInt sum;

  const CONTAINER_T<CELL_T> &cells_1 = n1.data;
  const CONTAINER_T<CELL_T> &cells_2 = n2.data;

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

BigInt BigInt::subtract(const BigInt &n1, const BigInt &n2) {
  return BigInt::add(n1, n2.negate());
}

bool BigInt::isZero() const {
  return BigInt::isZero(*this);
}

bool BigInt::isPositive() const {
  return BigInt::isPositive(*this);
}

bool BigInt::isNegative() const {
  return BigInt::isNegative(*this);
}

BigInt BigInt::add(const BigInt &n) const {
  return BigInt::add(*this, n);
}

BigInt BigInt::multiply(const BigInt &n) const {
  return BigInt::multiply(*this, n);
}

BigInt BigInt::subtract(const BigInt &n) const {
  return BigInt::subtract(*this, n);
}

BigInt BigInt::copy() const {
  return *this;
}

BigInt BigInt::invert() const {
  return BigInt(invert_cells(this->data));
}

BigInt BigInt::negate() const {
  if (isZero())
    return copy();

  BigInt ans = BigInt::add(this->invert(), BigInt::ONE);
  ans.sign = !sign;
  return ans;
}

string BigInt::toCellsString() const {
  stringstream ss;
  ss << "BigInt(" << ((sign == POSITIVE) ? "+" : "-") << "{";
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
  v.reserve(data.size() * CELL_TYPE_LENGTH);

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

string BigInt::toAbsDecimalString() const {
  auto bits = toBitsVector();

  vector<short> digits;
  digits.reserve(bits.size() / 3);
  digits.push_back(0);

  for (auto it = bits.rbegin(); it != bits.rend(); ++it) {
    digits = doubleDecimalVec(digits);
    digits = addToDecimalVec(digits, *it);
  }

  return decimalVecToDecimalString(digits);
}

string BigInt::toDecimalString() const {
  if (sign == POSITIVE) {
    return toAbsDecimalString();
  } else {
    return "-" + negate().toAbsDecimalString();
  }
}

void addCells(CELL_T cell1, CELL_T cell2, CELL_T remainder, CELL_T &ans, CELL_T &remainder_out) {
  DOUBLE_CELL_T sum = ((DOUBLE_CELL_T) cell1) + cell2 + remainder;
  ans = (CELL_T) sum;
  remainder_out = (CELL_T) (sum >> (CELL_TYPE_LENGTH));
}

void multiplyCells(CELL_T cell1, CELL_T cell2, CELL_T &ans, CELL_T &remainder_out) {
  DOUBLE_CELL_T product = ((DOUBLE_CELL_T) cell1) * cell2;
  ans = (CELL_T) product;
  remainder_out = (CELL_T) (product >> (CELL_TYPE_LENGTH));
}

CONTAINER_T<CELL_T> invert_cells(const CONTAINER_T<CELL_T> &cells) {
  CONTAINER_T<CELL_T> result;
  result.reserve(cells.size());

  for (auto it = cells.begin(); it != cells.end(); ++it)
    result.push_back(~((CELL_T) (*it)));

  return result;
}