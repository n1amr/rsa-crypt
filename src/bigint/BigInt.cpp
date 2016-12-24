#include <bits/stdc++.h>
#include "BigInt.h"
#include "DecimalHelpers.h"
using namespace std;

CELLS_CONTAINER_T invert_cells(const CELLS_CONTAINER_T &cells);
void addCells(CELL_T cell1, CELL_T cell2, CELL_T remainder, CELL_T &ans, CELL_T &remainder_out);
void multiplyCells(CELL_T cell1, CELL_T cell2, CELL_T &ans, CELL_T &remainder_out);

BigInt::BigInt()
    : cells(CELLS_CONTAINER_T {0}) {}

BigInt::BigInt(const CELLS_CONTAINER_T &init, SIGN_T sign)
    : cells(CELLS_CONTAINER_T {init}), sign(sign) {}

BigInt::BigInt(const BigInt &n) : BigInt(n.cells, n.sign) {}

BigInt::BigInt(const BigInt &n, SIGN_T sign) : BigInt(n.cells, sign) {}

BigInt::BigInt(int n) : BigInt(to_string(n)) {}

BigInt::BigInt(long long n) : BigInt(to_string(n)) {}

BigInt::BigInt(const char *s) : BigInt((string) s) {}

BigInt::BigInt(const string &s) {
  if (!s.empty() && s[0] == '-')
    sign = NEGATIVE;
  string absDecimalString = sign == NEGATIVE ? s.substr(1) : s;
  vector<short> v = decimalStringToDecimalVec(absDecimalString);

  vector<bool> bitVector = decimalVecToBitsVec(v);
  while (bitVector.size() % CELL_BIT_LENGTH != 0)
    bitVector.push_back(0);

  int nBits = (int) bitVector.size();
  int nCells = (nBits + CELL_BIT_LENGTH - 1) / CELL_BIT_LENGTH;
  cells.reserve(nCells);

  for (int i = 0; i < nCells; i++) {
    int p = CELL_BIT_LENGTH * i;

    CELL_T cell = 0;
    for (int j = CELL_BIT_LENGTH - 1; j >= 0; --j) {
      cell = (CELL_T) ((cell << 1) + bitVector[p + j]);
    }
    cells.push_back(cell);
  }
}

BigInt BigInt::ZERO("0");
BigInt BigInt::ONE("1");

bool BigInt::isZero(const BigInt &n) {
  return compare(n, BigInt::ZERO) == 0;
}

bool BigInt::isPositive(const BigInt &n) {
  return compare(n, BigInt::ZERO) > 0;
}

bool BigInt::isNegative(const BigInt &n) {
  return compare(n, BigInt::ZERO) < 0;
}

bool BigInt::equals(const BigInt &n1, const BigInt &n2) {
  return compare(n1, n2) == 0;
}

bool BigInt::isLessThan(const BigInt &n1, const BigInt &n2) {
  return compare(n1, n2) < 0;
}

bool BigInt::isGreaterThan(const BigInt &n1, const BigInt &n2) {
  return compare(n1, n2) > 0;
}

BigInt BigInt::add(const BigInt &a, const BigInt &b) {
  int m = (int) a.cells.size();
  int n = (int) b.cells.size();
  int k = max(m, n);

  BigInt result;
  result.cells.reserve((unsigned long) (k + 1));
  result.cells.resize((unsigned long) k, 0);
  result.sign = a.sign;

  if (a.sign == b.sign) {
    CELL_T r = 0;
    for (int i = 0; i < k; ++i) {
      CELL_T a_i = (CELL_T) (i < m ? a.cells[i] : 0);
      CELL_T b_i = (CELL_T) (i < n ? b.cells[i] : 0);
      DOUBLE_CELL_T s = a_i + b_i + r;
      result.cells[i] = (CELL_T) (s);
      r = (CELL_T) (s >> CELL_BIT_LENGTH);
    }
    if (r)
      result.cells.push_back(r);
  } else {
    BigInt a_ = absolute(a);
    BigInt b_ = absolute(b);

    if (a_ == b_)
      return BigInt::ZERO;

    if (b_ > a_) {
      result.sign = b.sign;
      swap(a_, b_);
      swap(m, n);
    }

    CELL_T r = 0;
    for (int i = 0; i < k; ++i) {
      CELL_T a_i = (CELL_T) (i < m ? a_.cells[i] : 0);
      CELL_T b_i = (CELL_T) (i < n ? b_.cells[i] : 0);

      SIGNED_DOUBLE_CELL_T s = a_i - b_i - r;
      result.cells[i] = (CELL_T) (s);
      r = (CELL_T) (s < 0);
    }
  }
  return result;
}

// TODO
BigInt BigInt::multiply(const BigInt &a, const BigInt &b) {
  if (a.isZero() || b.isZero())
    return BigInt::ZERO;

  int m = (int) a.cells.size();
  int n = (int) b.cells.size();
  int k = m + n - 1;

  BigInt c;
  c.cells.reserve((unsigned long) (k + 1));
  c.cells.resize((unsigned long) k, 0);
  c.sign = a.sign ^ b.sign;

  DOUBLE_CELL_T r = 0;
  for (int h = 0; h < k; ++h) {
    long long s = r;
    for (int i = max(0, h - n + 1); i <= min(h, m - 1); ++i) {
      s += (long long) a.cells[i] * b.cells[h - i];
    }
    r = (DOUBLE_CELL_T) (s >> CELL_BIT_LENGTH);
    c.cells[h] = (CELL_T) (s);
  }
  if (r) {
    c.cells.push_back(r);
  }
  return c;
}

BigInt BigInt::subtract(const BigInt &n1, const BigInt &n2) {
  return add(n1, n2.negate());
}

// TODO
void divisionMoveCell(CELLS_CONTAINER_T &from, CELLS_CONTAINER_T &to) {
  if (!from.empty()) {
    REVERSE(to);
    to.push_back(from.back());
    REVERSE(to);
    from.pop_back();
  }
}

map<CELL_T, BigInt> lookup;

// TODO
CELL_T binary_find(const BigInt &x, const BigInt &denominator) {
  CELL_T l = 0, r = MAX_CELL_VALUE, m;
  while (l + 1 < r) {
    m = (CELL_T) ((l + r) / 2);
    if (x >= (lookup[m] = lookup.count(m) > 0 ? lookup[m] : denominator * BigInt(m)))
      l = m;
    else
      r = m;
  }
  return l;
}

// TODO not implemented
BigInt BigInt::divide(const BigInt &n1, const BigInt &n2) {
  lookup.clear();

  if (n1.isZero())
    return BigInt::ZERO;
  if (n2.isZero())
    return -1;

  bool sign = n1.isNegative() ^n2.isNegative();
  BigInt numerator = n1.isNegative() ? n1.negate() : n1;
  BigInt denominator = n2.isNegative() ? n2.negate() : n2;
  BigInt available;
  BigInt result;

  const CELLS_CONTAINER_T &denominator_cells = denominator.cells;
  CELLS_CONTAINER_T remaining_cells = numerator.cells;
  CELLS_CONTAINER_T &available_cells = available.cells;
  CELLS_CONTAINER_T &result_cells = result.cells;

  while (!remaining_cells.empty() || available >= denominator) {
    while (!remaining_cells.empty() && available < denominator) {
      result_cells.push_back(0);
      divisionMoveCell(remaining_cells, available_cells);
    }

    CELL_T d = binary_find(available, denominator);
    result_cells.push_back(d);
    available -= lookup[d];
    divisionMoveCell(remaining_cells, available_cells);
  }

  while (result_cells.size() > 1 && result_cells.back() == 0)
    result_cells.pop_back();
  REVERSE(result_cells);
  return sign ? result.negate() : result;
}

// TODO not implemented
BigInt BigInt::mod(const BigInt &n1, const BigInt &n2) {
  if (n1.isZero())
    return BigInt::ZERO;
  if (n2.isZero())
    return -1;

  return n1 - (n1 / n2) * n2;
}

bool BigInt::isZero() const {
  return isZero(*this);
}

bool BigInt::isPositive() const {
  return isPositive(*this);
}

bool BigInt::isNegative() const {
  return isNegative(*this);
}

bool BigInt::equals(const BigInt &n) const {
  return equals(*this, n);
}

bool BigInt::isLessThan(const BigInt &n) const {
  return isLessThan(*this, n);
}

bool BigInt::isGreaterThan(const BigInt &n) const {
  return isGreaterThan(*this, n);
}

BigInt BigInt::add(const BigInt &n) const {
  return add(*this, n);
}

BigInt BigInt::multiply(const BigInt &n) const {
  return multiply(*this, n);
}

BigInt BigInt::subtract(const BigInt &n) const {
  return subtract(*this, n);
}

BigInt BigInt::divide(const BigInt &n) const {
  return divide(*this, n);
}

BigInt BigInt::mod(const BigInt &n) const {
  return mod(*this, n);
}

BigInt BigInt::copy() const {
  return *this;
}

// TODO
BigInt BigInt::invert() const {
  return BigInt(invert_cells(this->cells));
}

BigInt BigInt::negate() const {
  if (isZero())
    return copy();
  return BigInt(cells, !sign);
}

// TODO
BigInt BigInt::shiftCells(int n_cells_left) const {
  CELLS_CONTAINER_T new_data = cells;

  REVERSE(new_data);
  if (n_cells_left > 0) {
    for (int i = 0; i < n_cells_left; ++i)
      new_data.push_back(0);
  } else {
    n_cells_left = -n_cells_left;
    for (int i = 0; !new_data.empty() && i < n_cells_left; ++i)
      new_data.pop_back();
  }
  REVERSE(new_data);

  return BigInt(new_data, sign);
}

// TODO
BigInt BigInt::shiftBits(int n_bits_left) const {
  CELLS_CONTAINER_T new_data = cells;

  bool left = n_bits_left > 0;
  int n_bits = abs(n_bits_left);
  int n_cells = (left ? 1 : -1) * (n_bits / CELL_BIT_LENGTH);

  if (n_cells) {
    new_data = shiftCells(n_cells).cells;
    n_bits %= CELL_BIT_LENGTH;
  }

  if (n_bits) {
    if (left) {
      CELL_T old_high_bits = 0;
      for (int i = 0; i < new_data.size(); ++i) {
        CELL_T current_cell = new_data[i];

        DOUBLE_CELL_T
            pr = (DOUBLE_CELL_T) (sign == NEGATIVE && i == new_data.size() - 1 ? (CELL_T) ~0 : 0);
        DOUBLE_CELL_T tmp = (pr << CELL_BIT_LENGTH | current_cell) << n_bits | old_high_bits;

        new_data[i] = (CELL_T) tmp;
        old_high_bits = (CELL_T) (tmp >> CELL_BIT_LENGTH);
      }
      if (old_high_bits)
        new_data.push_back(old_high_bits);

    } else {
      REVERSE(new_data);

      CELL_T old_low_bits = 0;
      for (int i = 0; i < new_data.size(); ++i) {
        DOUBLE_CELL_T pr = (DOUBLE_CELL_T)
            (sign == NEGATIVE && i == 0 ? ((CELL_T) ~0) << (CELL_BIT_LENGTH - n_bits) : 0);
        DOUBLE_CELL_T tmp = (pr << CELL_BIT_LENGTH)
                            | (((DOUBLE_CELL_T) new_data[i] << CELL_BIT_LENGTH) >> n_bits);

        new_data[i] = old_low_bits | ((CELL_T) (tmp >> CELL_BIT_LENGTH));
        old_low_bits = (CELL_T) tmp;
      }

      REVERSE(new_data);
    }
  }
  return BigInt(new_data, sign);
}

string BigInt::toCellsString() const {
  stringstream ss;
  ss << "BigInt(" << ((sign == POSITIVE) ? "+" : "-") << "{";
  for (auto it = cells.rbegin(); it != cells.rend(); ++it)
    ss << ((unsigned long long int) *it) << ", ";
  ss << "})";
  return ss.str();
}

string BigInt::toBitsString() const {
  auto v = toBitsVector();

  stringstream ss;
  ss << "BigInt(" << ((sign == POSITIVE) ? "+" : "-");
  for (auto it = v.rbegin(); it != v.rend(); ++it)
    ss << (*it);
  ss << ")";
  return ss.str();
}

vector<bool> BigInt::toBitsVector() const {
  vector<bool> v;
  v.reserve(cells.size() * CELL_BIT_LENGTH);

  for (auto it = cells.begin(); it != cells.end(); ++it) {
    CELL_T cell = *it;
    for (int i = 0; i < CELL_BIT_LENGTH; ++i) {
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
    return "-" + toAbsDecimalString();
  }
}

BigInt BigInt::operator+(const BigInt &n) const { return this->add(n); }

BigInt BigInt::operator-(const BigInt &n) const { return this->subtract(n); }

BigInt BigInt::operator*(const BigInt &n) const { return this->multiply(n); }

BigInt BigInt::operator/(const BigInt &n) const { return this->divide(n); }

BigInt BigInt::operator%(const BigInt &n) const { return this->mod(n); }

BigInt BigInt::operator-() const { return this->negate(); }

BigInt &BigInt::operator+=(const BigInt &n) { return *this = *this + n; }

BigInt &BigInt::operator-=(const BigInt &n) { return *this = *this - n; }

BigInt &BigInt::operator*=(const BigInt &n) { return *this = *this * n; }

BigInt &BigInt::operator/=(const BigInt &n) { return *this = *this / n; }

BigInt &BigInt::operator%=(const BigInt &n) { return *this = *this % n; }

bool BigInt::operator==(const BigInt &n) const { return this->equals(n); }

bool BigInt::operator!=(const BigInt &n) const { return !(*this == n); }

bool BigInt::operator<(const BigInt &n) const { return this->isLessThan(n); }

bool BigInt::operator>(const BigInt &n) const { return this->isGreaterThan(n); }

bool BigInt::operator<=(const BigInt &n) const { return !((*this) > n); }

bool BigInt::operator>=(const BigInt &n) const { return !((*this) < n); }

BigInt BigInt::operator<<(int n) const {
  return shiftBits(n);
}

BigInt BigInt::operator>>(int n) const {
  return shiftBits(-n);
}

BigInt &BigInt::operator<<=(int n) {
  return *this = *this << n;
}

BigInt &BigInt::operator>>=(int n) {
  return *this = *this >> n;
}

BigInt BigInt::operator++() {
  return *this = *this + BigInt::ONE;
}

BigInt BigInt::operator++(int) {
  BigInt tmp = *this;
  operator++();
  return tmp;
}

BigInt BigInt::operator--() {
  return *this = *this - BigInt::ONE;
}

BigInt BigInt::operator--(int) {
  BigInt tmp = *this;
  operator--();
  return tmp;
}

int BigInt::sign_l(long long c) {
  return c > 0 ? 1 : c < 0 ? -1 : 0;
}

int BigInt::sign_(SIGNED_DOUBLE_CELL_T c) {
  return c > 0 ? 1 : c < 0 ? -1 : 0;
}

int BigInt::compare_cells(CELL_T c1, CELL_T c2) {
  return sign_((SIGNED_DOUBLE_CELL_T) (DOUBLE_CELL_T) c1 - (SIGNED_DOUBLE_CELL_T) (DOUBLE_CELL_T) c2);
}

int BigInt::compare(const BigInt &a, const BigInt &b) {
  if (a.sign != b.sign)
    return a.sign == POSITIVE ? 1 : -1;

  int m = (int) a.cells.size() - 1;
  int n = (int) b.cells.size() - 1;

  if (m != n)
    return sign_l(m - n);
  else {
    int r = 0;
    for (int i = m; i >= 0; --i) {
      if (a.cells[i] != b.cells[i]) {
        r = compare_cells(a.cells[i], b.cells[i]);
        break;
      }
    }
    return a.sign == POSITIVE ? r : -r;
  }
}

BigInt BigInt::absolute(const BigInt &a) {
  return BigInt(a.cells, POSITIVE);
}

// TODO
void addCells(CELL_T cell1, CELL_T cell2, CELL_T remainder, CELL_T &ans, CELL_T &remainder_out) {
  DOUBLE_CELL_T sum = ((DOUBLE_CELL_T) cell1) + cell2 + remainder;
  ans = (CELL_T) sum;
  remainder_out = (CELL_T) (sum >> (CELL_BIT_LENGTH));
}

// TODO
void multiplyCells(CELL_T cell1, CELL_T cell2, CELL_T &ans, CELL_T &remainder_out) {
  DOUBLE_CELL_T product = ((DOUBLE_CELL_T) cell1) * cell2;
  ans = (CELL_T) product;
  remainder_out = (CELL_T) (product >> (CELL_BIT_LENGTH));
}

// TODO
CELLS_CONTAINER_T invert_cells(const CELLS_CONTAINER_T &cells) {
  CELLS_CONTAINER_T result;
  result.reserve(cells.size());

  for (auto it = cells.begin(); it != cells.end(); ++it)
    result.push_back(~((CELL_T) (*it)));

  return result;
}
