#include <bits/stdc++.h>
using namespace std;

#ifdef N1AMR_MULTIPLE_FILES

#include "BigInt.h"
#include "DecimalHelpers.h"
#endif

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

bool BigInt::equals(const BigInt &a, const BigInt &b) {
  return compare(a, b) == 0;
}

bool BigInt::isLessThan(const BigInt &a, const BigInt &b) {
  return compare(a, b) < 0;
}

bool BigInt::isGreaterThan(const BigInt &a, const BigInt &b) {
  return compare(a, b) > 0;
}

bool BigInt::isOdd(const BigInt &n) {
  return n.cells.size() > 0 && n.cells[0] % 2 == 1;
}

BigInt BigInt::add(const BigInt &a, const BigInt &b) {
  assert(a.cells.size() == 1 || a.cells.size() > 1 && a.cells.back() != 0);
  assert(b.cells.size() == 1 || b.cells.size() > 1 && b.cells.back() != 0);

  if (a.isZero())
    return b;
  if (b.isZero())
    return a;

  int m = (int) a.cells.size();
  int n = (int) b.cells.size();
  int k = max(m, n);

  BigInt ans;
  ans.cells.reserve((unsigned long) (k + 1));
  ans.cells.resize((unsigned long) k, 0);
  ans.sign = a.sign;

  if (a.sign == b.sign) {
    CELL_T r = 0;
    for (int i = 0; i < k; ++i) {
      CELL_T a_i = (CELL_T) (i < m ? a.cells[i] : 0);
      CELL_T b_i = (CELL_T) (i < n ? b.cells[i] : 0);
      DOUBLE_CELL_T s = (DOUBLE_CELL_T) a_i + b_i + r;
      ans.cells[i] = (CELL_T) (s);
      r = (CELL_T) (s >> CELL_BIT_LENGTH);
    }
    if (r)
      ans.cells.push_back(r);
  } else {
    BigInt a_ = absolute(a);
    BigInt b_ = absolute(b);

    if (a_ == b_)
      return BigInt::ZERO;

    if (b_ > a_) {
      ans.sign = b.sign;
      swap(a_, b_);
      swap(m, n);
    }

    CELL_T r = 0;
    for (int i = 0; i < k; ++i) {
      CELL_T a_i = (CELL_T) (i < m ? a_.cells[i] : 0);
      CELL_T b_i = (CELL_T) (i < n ? b_.cells[i] : 0);

      SIGNED_DOUBLE_CELL_T s = (DOUBLE_CELL_T) a_i - b_i - r;
      ans.cells[i] = (CELL_T) (s);
      r = (CELL_T) (s < 0);
    }

    while (ans.cells.size() > 1 && ans.cells.back() == 0)
      ans.cells.pop_back();
  }
  assert(ans.cells.size() == 1 || ans.cells.size() > 1 && ans.cells.back() != 0);
  return ans;
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

BigInt BigInt::divide(const BigInt &a, const BigInt &b) {
  assert(a.cells.size() == 1 || a.cells.size() > 1 && a.cells.back() != 0);
  assert(b.cells.size() == 1 || b.cells.size() > 1 && b.cells.back() != 0);

  if (b == BigInt::ZERO)
    throw "Zero division exception";
  if (a == BigInt::ZERO)
    return BigInt::ZERO;

  int a_to_b = compare(a, b);
  if (a_to_b < 0) // a < b
    return BigInt::ZERO;
  else if (a_to_b == 0) // a == b
    return BigInt::ONE;

  CELL_T d = (CELL_T) ((DOUBLE_CELL_T) BASE / ((DOUBLE_CELL_T) 1 + b.cells.back())); // Normalization factor
  BigInt D((long long) d);

  BigInt a_ = a * D;
  BigInt b_ = b * D;

  assert(a_ >= b_);
  assert(b_ >= ZERO);

  int m = (int) a_.cells.size();
  int n = (int) b_.cells.size();
  int k = m - n + 1;

  CELLS_CONTAINER_T q_cells;
  q_cells.resize((unsigned long) (k), 0);

  BigInt r = a_.shiftBits((int) -(CELL_BIT_LENGTH * (m - n)));

  assert(r.cells.back() != 0);
  assert(r.cells.size() == n);

  for (int i = 0; i < k; ++i) {
    assert(r.cells.back() != 0);
    assert(r.cells.size() <= n + 1);

    CELL_T q_0 = 0;
    BigInt Q((long long) q_0);
    if (r.cells.size() >= b_.cells.size()) {
      bool concat_zero = r.cells.size() == b_.cells.size();

      assert((concat_zero && r.cells.size() == b_.cells.size()) ||
             (!concat_zero && r.cells.size() == b_.cells.size() + 1));
      assert(b_.cells.back() != 0);
      assert(r > ZERO);
      assert(b_ > ZERO);

      DOUBLE_CELL_T estimate = (DOUBLE_CELL_T) min(
          (DOUBLE_CELL_T) BASE - 1,
          (DOUBLE_CELL_T) ((DOUBLE_CELL_T) (concat_zero ? 0 : r.cells[n] * BASE) + r.cells[n - 1]) / b_.cells[n - 1]
      );

      Q.cells[0] = (CELL_T) estimate;
      BigInt R = r - Q * b_;
      int error = 0;
      while (R < 0) {
        assert(error < 3);
        R = R + b_;
        error++;
      }
      Q.cells[0] -= error;

      assert(ZERO <= R);
      assert(b_ * Q + R == r);
      assert(Q.cells.size() == 1);
      q_0 = Q.cells[0];
    }
    q_cells[k - 1 - i] = q_0;
    r = r - Q * b_;

    if (i < k - 1) {
      r <<= CELL_BIT_LENGTH;
      r.cells[0] = a_.cells[k - 2 - i];
    }
  }
  while (q_cells.size() > 1 && q_cells.back() == 0) // TODO
    q_cells.pop_back();

  BigInt Q(q_cells, a.sign ^ b.sign);
  assert(b * Q <= a);
  assert(a - b * Q < absolute(b));
  assert(ZERO <= a - b * Q);
  assert(Q.cells.size() == 1 || Q.cells.size() > 1 && Q.cells.back() != 0);
  return Q;
}

BigInt BigInt::mod(const BigInt &n, const BigInt &m) {
  assert(n.cells.size() == 1 || n.cells.size() > 1 && n.cells.back() != 0);
  assert(m.cells.size() == 1 || m.cells.size() > 1 && m.cells.back() != 0);

  BigInt a = n - (n / m) * m;
  assert(a.cells.size() == 1 || a.cells.size() > 1 && a.cells.back() != 0);
  return a;
}

BigInt BigInt::pow(const BigInt &n, const BigInt &power, const BigInt &m) {
  BigInt ans = BigInt::ONE;
  BigInt p = power;
  if (m != ZERO) {
    BigInt tmp = n % m;
    while (!p.isZero()) {
      if (p.isOdd())
        ans = (ans * tmp) % m;
      p >>= 1;
      tmp = (tmp * tmp) % m;
    }
  } else {
    BigInt tmp = n;
    while (!p.isZero()) {
      if (p.isOdd())
        ans = (ans * tmp);
      p >>= 1;
      tmp = (tmp * tmp);
    }
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
  return add(*this, n.negate());
}

BigInt BigInt::divide(const BigInt &n) const {
  return divide(*this, n);
}

BigInt BigInt::mod(const BigInt &n) const {
  return mod(*this, n);
}

BigInt BigInt::pow(const BigInt &power, const BigInt &m) const {
  return BigInt::pow(*this, power, m);
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
  BigInt ans = c.size() > 0 ? BigInt(c, sign) : BigInt::ZERO;
  assert(ans.cells.size() == 1 || ans.cells.size() > 1 && ans.cells.back() != 0);
  return ans;
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

BigInt BigInt::operator+(const BigInt &n) const { return add(*this, n); }

BigInt BigInt::operator-(const BigInt &n) const { return subtract(*this, n); }

BigInt BigInt::operator*(const BigInt &n) const { return multiply(*this, n); }

BigInt BigInt::operator/(const BigInt &n) const { return divide(*this, n); }

BigInt BigInt::operator%(const BigInt &n) const { return mod(*this, n); }

BigInt BigInt::operator-() const { return this->negate(); }

BigInt &BigInt::operator+=(const BigInt &n) { return *this = add(*this, n); }

BigInt &BigInt::operator-=(const BigInt &n) { return *this = subtract(*this, n); }

BigInt &BigInt::operator*=(const BigInt &n) { return *this = multiply(*this, n); }

BigInt &BigInt::operator/=(const BigInt &n) { return *this = divide(*this, n); }

BigInt &BigInt::operator%=(const BigInt &n) { return *this = mod(*this, n); }

bool BigInt::operator==(const BigInt &n) const { return equals(*this, n); }

bool BigInt::operator!=(const BigInt &n) const { return !equals(*this, n); }

bool BigInt::operator<(const BigInt &n) const { return isLessThan(*this, n); }

bool BigInt::operator>(const BigInt &n) const { return isGreaterThan(*this, n); }

bool BigInt::operator<=(const BigInt &n) const { return !isGreaterThan(*this, n); }

bool BigInt::operator>=(const BigInt &n) const { return !isLessThan(*this, n); }

BigInt BigInt::operator<<(int n) const {
  return shiftBits(n);
}

BigInt BigInt::operator>>(int n) const {
  return shiftBits(-n);
}

BigInt &BigInt::operator<<=(int n) {
  return *this = this->shiftBits(n);
}

BigInt &BigInt::operator>>=(int n) {
  return *this = this->shiftBits(-n);
}

BigInt BigInt::operator++() {
  return *this = add(*this, ONE);
}

BigInt BigInt::operator++(int) {
  BigInt tmp = *this;
  *this = add(*this, ONE);
  return tmp;
}

BigInt BigInt::operator--() {
  return *this = add(*this, ONE.negate());
}

BigInt BigInt::operator--(int) {
  BigInt tmp = *this;
  *this = add(*this, ONE.negate());
  return tmp;
}

int BigInt::sign_(SIGNED_DOUBLE_CELL_T n) {
  return n > 0 ? 1 : n < 0 ? -1 : 0;
}

int BigInt::compare_cells(CELL_T a, CELL_T b) {
  return sign_((SIGNED_DOUBLE_CELL_T) (DOUBLE_CELL_T) a - (SIGNED_DOUBLE_CELL_T) (DOUBLE_CELL_T) b);
}

CELL_T BigInt::div_next_quotient(const BigInt &u, const BigInt &v) {
  assert(u.cells.size() == v.cells.size() + 1);
  assert(v.cells.back() != 0);
  assert(u > ZERO);
  assert(v > ZERO);

  int n = (int) v.cells.size();
  DOUBLE_CELL_T estimate = (DOUBLE_CELL_T) min(
      (DOUBLE_CELL_T) BASE - 1,
      ((DOUBLE_CELL_T) u.cells[n] * BASE + u.cells[n - 1]) / v.cells[n - 1]
  );

  BigInt u_ = u;
  if (u_.cells.size() > 1 && u_.cells.back() == 0)
    u_.cells.pop_back();
  BigInt Q((long long) estimate);
  BigInt R = u_ - Q * v;
  int error = 0;
  while (R < 0) {
    assert(error < 3);
    R = R + v;
    error++;
  }
  Q = Q - BigInt(error);

  assert(ZERO <= R);
  assert(v * Q + R == u_);
  assert(Q.cells.size() == 1);
  return Q.cells[0];
}
