#include <bits/stdc++.h>
#include "BigInt.h"
#include "DecimalHelpers.h"
using namespace std;

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

bool BigInt::isOdd(const BigInt &n) {
  return n.cells.size() > 0 && n.cells[0] % 2 == 1;
}

BigInt BigInt::add(const BigInt &a, const BigInt &b) {
  assert(a.cells.size() == 1 || a.cells.size() > 1 && a.cells.back() != 0);
  assert(b.cells.size() == 1 || b.cells.size() > 1 && b.cells.back() != 0);

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

    while (result.cells.size() > 1 && result.cells.back() == 0)
      result.cells.pop_back();
  }
  assert(result.cells.size() == 1 || result.cells.size() > 1 && result.cells.back() != 0);
  return result;
}

BigInt BigInt::multiply(const BigInt &a, const BigInt &b) {
  assert(a.cells.size() == 1 || a.cells.size() > 1 && a.cells.back() != 0);
  assert(b.cells.size() == 1 || b.cells.size() > 1 && b.cells.back() != 0);

  if (a.isZero() || b.isZero())
    return BigInt::ZERO;

  int m = (int) a.cells.size();
  int n = (int) b.cells.size();
  int k = m + n - 1;

  BigInt c;
  c.cells.resize((unsigned long) k + 1, 0);
  c.sign = a.sign ^ b.sign;

  DOUBLE_CELL_T s, r = 0;
  for (int j = 0; j < n; ++j) {
    r = 0;
    for (int i = 0; i < m; ++i) {
      s = (DOUBLE_CELL_T) a.cells[i] * b.cells[j] + c.cells[i + j] + r;
      c.cells[i + j] = (CELL_T) s;
      r = s >> CELL_BIT_LENGTH;
    }
    c.cells[j + m] = (CELL_T) r;
  }
  if (r == 0) {
    c.cells.pop_back();
  }

  assert(c.cells.size() == 1 || c.cells.size() > 1 && c.cells.back() != 0);
  return c;
}

BigInt BigInt::subtract(const BigInt &a, const BigInt &b) {
  assert(a.cells.size() == 1 || a.cells.size() > 1 && a.cells.back() != 0);
  assert(b.cells.size() == 1 || b.cells.size() > 1 && b.cells.back() != 0);
  BigInt c = add(a, b.negate());
  assert(c.cells.size() == 1 || c.cells.size() > 1 && c.cells.back() != 0);
  assert(a == b + c);
  return c;
}

BigInt BigInt::divide(const BigInt &n1, const BigInt &n2) {
  assert(n1.cells.size() == 1 || n1.cells.size() > 1 && n1.cells.back() != 0);
  assert(n2.cells.size() == 1 || n2.cells.size() > 1 && n2.cells.back() != 0);

  if (n1 < n2)
    return BigInt::ZERO;
  if (n1 == n2)
    return BigInt::ONE;
  if (n1 == BigInt::ZERO)
    return BigInt::ZERO;
  if (n2 == BigInt::ZERO)
    return -BigInt::ONE;

  CELL_T d = (CELL_T) (BASE / (1 + n2.cells.back()));
  BigInt D(d);

  BigInt a = n1 * D;
  BigInt b = n2 * D;

  assert(a >= b);
  assert(b >= ZERO);

  int m = (int) a.cells.size();
  int n = (int) b.cells.size();
  int k = m - n + 1;

  CELLS_CONTAINER_T a_r_cells = a.cells;
  REVERSE(a_r_cells);

  CELLS_CONTAINER_T q_cells;

  CELLS_CONTAINER_T r_cells;
  r_cells.reserve((unsigned long) (n + 1));
  r_cells.push_back(0);
  for (int i = 0; i < n; ++i) {
    r_cells.push_back(a_r_cells[i]);
  }
  REVERSE(r_cells);

  BigInt r(r_cells);

  assert(r.cells.back() == 0);

  for (int i = 0; i < k; ++i) {
    CELL_T q_i = div_next_quotient(r, b);
    q_cells.push_back(q_i);
    if (r.cells.size() > 1 && r.cells.back() == 0)
      r.cells.pop_back();
    r = r - BigInt(q_i) * b;

    if (i != k - 1) {
      r <<= CELL_BIT_LENGTH;
      r.cells[0] = a_r_cells[m - k + 1 + i];
    }
  }
  REVERSE(q_cells);
  while (q_cells.size() > 1 && q_cells.back() == 0) // TODO
    q_cells.pop_back();

  BigInt Q(q_cells, n1.sign ^ n2.sign);
  assert(n2 * Q <= n1);
  assert(n1 - n2 * Q < absolute(n2));
  assert(ZERO <= n1 - n2 * Q);
  assert(Q.cells.size() == 1 || Q.cells.size() > 1 && Q.cells.back() != 0);
  return Q;
}

BigInt BigInt::mod(const BigInt &n1, const BigInt &n2) {
  assert(n1.cells.size() == 1 || n1.cells.size() > 1 && n1.cells.back() != 0);
  assert(n2.cells.size() == 1 || n2.cells.size() > 1 && n2.cells.back() != 0);

  if (n1.isZero())
    return BigInt::ZERO;
  if (n2.isZero())
    return -1;

  BigInt c = n1 - (n1 / n2) * n2;
  assert(c.cells.size() == 1 || c.cells.size() > 1 && c.cells.back() != 0);
  return c;
}

BigInt BigInt::pow(const BigInt &n, const BigInt &p, const BigInt &m) {
  BigInt ans = BigInt::ONE;
  BigInt y = n % m;
  BigInt p_ = p;
  while (!p_.isZero()) {
    if (p_.isOdd()) {
      ans = (ans * y) % m;
    }
    p_ >>= 1;
    y = (y * y) % m;

  }
  return ans;
}

BigInt BigInt::absolute(const BigInt &a) {
  return BigInt(a.cells, POSITIVE);
}

int BigInt::compare(const BigInt &a, const BigInt &b) {
  if (a.sign != b.sign)
    return a.sign == POSITIVE ? 1 : -1;

  int m = (int) a.cells.size() - 1;
  int n = (int) b.cells.size() - 1;

  if (m != n) {
    return m > n ? 1 : m < n ? -1 : 0;
  } else {
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

bool BigInt::isOdd() const {
  return BigInt::isOdd(*this);
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

BigInt BigInt::pow(const BigInt &p, const BigInt &m) const {
  return BigInt::pow(*this, p, m);
}

BigInt BigInt::absolute() const {
  return BigInt::absolute(*this);
}

int BigInt::compare(const BigInt &n) const {
  return compare(*this, n);
}

BigInt BigInt::copy() const {
  return *this;
}

BigInt BigInt::negate() const {
  assert(cells.size() == 1 || cells.size() > 1 && cells.back() != 0);
  if (isZero())
    return copy();
  BigInt c = BigInt(cells, !sign);
  assert(c.cells.size() == 1 || c.cells.size() > 1 && c.cells.back() != 0);
  return c;
}

BigInt BigInt::shiftBits(int n_bits_left) const {
  assert(cells.size() == 1 || cells.size() > 1 && cells.back() != 0);

  if (n_bits_left == 0)
    return copy();

  unsigned long m = (int) cells.size();

  bool left = n_bits_left > 0;
  int n_bits = left ? n_bits_left : -n_bits_left;
  int n_cells = n_bits / CELL_BIT_LENGTH;
  n_bits %= CELL_BIT_LENGTH;

  CELLS_CONTAINER_T c;
  if (left) {
    c.reserve(m + n_cells + 1);
    c.resize((unsigned long) n_cells, 0);

    CELL_T r = 0;
    for (int i = 0; i < m; ++i) {
      DOUBLE_CELL_T s = ((DOUBLE_CELL_T) cells[i] << n_bits) | r;
      c.push_back((CELL_T) s);
      r = (CELL_T) (s >> CELL_BIT_LENGTH);
    }
    if (r)
      c.push_back(r);

    while (c.size() > 1 && c.back() == 0)
      c.pop_back();
  } else { // Right
    if (n_bits >= m * CELL_BIT_LENGTH)
      return BigInt::ZERO;

    c.reserve(m - n_cells + 1);

    for (int i = n_cells; i < m - 1; ++i)
      c.push_back((CELL_T) (((DOUBLE_CELL_T) cells[i] | (DOUBLE_CELL_T) cells[i + 1] << CELL_BIT_LENGTH) >> n_bits));
    CELL_T r = cells.back() >> n_bits;
    if (r)
      c.push_back(r);
  }
  BigInt result = c.size() > 0 ? BigInt(c, sign) : BigInt::ZERO;
  assert(result.cells.size() == 1 || result.cells.size() > 1 && result.cells.back() != 0);
  return result;
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

string BigInt::toCellsString() const {
  stringstream ss;
  ss << ((sign == POSITIVE) ? "+" : "-") << " [";
  for (auto it = cells.rbegin(); it != cells.rend(); ++it)
    ss << ((unsigned long long int) *it) << ", ";
  ss << "]";
  return ss.str();
}

string BigInt::toBinaryString() const {
  auto v = toBitsVector();

  stringstream ss;
  if (sign == NEGATIVE)
    ss << "-";
  for (auto it = v.rbegin(); it != v.rend(); ++it)
    ss << (*it);
  return ss.str();
}

string BigInt::toDecimalString() const {
  vector<bool> bits = toBitsVector();

  vector<short> digits;
  digits.reserve(bits.size() / 3);
  digits.push_back(0);

  for (auto it = bits.rbegin(); it != bits.rend(); ++it) {
    digits = doubleDecimalVec(digits);
    digits = addToDecimalVec(digits, *it);
  }

  string d_str = decimalVecToDecimalString(digits);
  return sign == POSITIVE ? d_str : "-" + d_str;
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

int BigInt::sign_(SIGNED_DOUBLE_CELL_T c) {
  return c > 0 ? 1 : c < 0 ? -1 : 0;
}

int BigInt::compare_cells(CELL_T c1, CELL_T c2) {
  return sign_((SIGNED_DOUBLE_CELL_T) (DOUBLE_CELL_T) c1 - (SIGNED_DOUBLE_CELL_T) (DOUBLE_CELL_T) c2);
}

CELL_T BigInt::div_next_quotient(const BigInt &u, const BigInt &v) {
  assert(u.cells.size() == v.cells.size() + 1);
  assert(v.cells.back() != 0);
  assert(u > ZERO);
  assert(v > ZERO);

  int n = (int) v.cells.size();
  DOUBLE_CELL_T qhat = (DOUBLE_CELL_T) min(
      BASE - 1,
      ((DOUBLE_CELL_T) u.cells[n] * BASE + u.cells[n - 1]) / v.cells[n - 1]
  );

  int cnt = 0;
  BigInt Q(to_string(qhat));
  BigInt u_ = u;
  if (u_.cells.size() > 1 && u_.cells.back() == 0)
    u_.cells.pop_back();
  BigInt R = u_ - Q * v;
  while (R < 0) {
    assert(cnt < 3);
    Q = Q - ONE;
    R = R + v;
    cnt++;
  }

  assert(ZERO <= R);
//  assert(R <= v);
  assert(v * Q + R == u_);
  assert(Q.cells.size() == 1);
  return Q.cells[0];
}

