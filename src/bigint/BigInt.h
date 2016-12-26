#ifndef RSA_BIGINT_H
#define RSA_BIGINT_H

#include <bits/stdc++.h>
using namespace std;

#define CELL_SIZE 32
#if CELL_SIZE == 8
#define CELL_T u_int8_t
#define DOUBLE_CELL_T u_int16_t
#define SIGNED_CELL_T int8_t
#define SIGNED_DOUBLE_CELL_T int16_t
#elif CELL_SIZE == 16
#define CELL_T u_int16_t
#define DOUBLE_CELL_T u_int32_t
#define SIGNED_CELL_T int16_t
#define SIGNED_DOUBLE_CELL_T int32_t
#elif CELL_SIZE == 32
#define CELL_T u_int32_t
#define DOUBLE_CELL_T u_int64_t
#define SIGNED_CELL_T int32_t
#define SIGNED_DOUBLE_CELL_T int64_t
#endif

#define CELL_BIT_LENGTH (sizeof(CELL_T) << 3)
#define BASE (((DOUBLE_CELL_T) 1 << CELL_BIT_LENGTH))
#define MAX_CELL_VALUE (BASE - 1)

#define CONTAINER_T vector
#define CELLS_CONTAINER_T CONTAINER_T<CELL_T>

#define SIGN_T bool
#define POSITIVE 0
#define NEGATIVE 1

class BigInt {
private:
  CELLS_CONTAINER_T cells;
  SIGN_T sign = POSITIVE;

public:
  BigInt();
  BigInt(const CELLS_CONTAINER_T &init, SIGN_T sign = POSITIVE);
  BigInt(const BigInt &n);
  BigInt(const BigInt &n, SIGN_T sign);
  BigInt(int n);
  BigInt(long long n);
  BigInt(const char *s);
  BigInt(const string &s);

  static BigInt ZERO;
  static BigInt ONE;

  inline static bool isZero(const BigInt &n);
  inline static bool isPositive(const BigInt &n);
  inline static bool isNegative(const BigInt &n);

  inline static bool equals(const BigInt &n1, const BigInt &n2);
  inline static bool isLessThan(const BigInt &n1, const BigInt &n2);
  inline static bool isGreaterThan(const BigInt &n1, const BigInt &n2);

  inline static bool isOdd(const BigInt &n);

  static BigInt add(const BigInt &a, const BigInt &b);
  static BigInt multiply(const BigInt &a, const BigInt &b);
  static BigInt subtract(const BigInt &a, const BigInt &b);
  static BigInt divide(const BigInt &n1, const BigInt &n2);
  static BigInt mod(const BigInt &n1, const BigInt &n2);
  static BigInt pow(const BigInt &n, const BigInt &power, const BigInt &m);
  static BigInt absolute(const BigInt &a);
  static int compare(const BigInt &a, const BigInt &b);

  bool isZero() const;
  bool isPositive() const;
  bool isNegative() const;

  bool equals(const BigInt &n) const;
  bool isLessThan(const BigInt &n) const;
  bool isGreaterThan(const BigInt &n) const;

  bool isOdd() const;

  inline BigInt add(const BigInt &n) const;
  inline BigInt multiply(const BigInt &n) const;
  inline BigInt subtract(const BigInt &n) const;
  inline BigInt divide(const BigInt &n) const;
  inline BigInt mod(const BigInt &n) const;
  BigInt pow(const BigInt &power, const BigInt &m = ZERO) const;
  inline BigInt absolute() const;
  inline int compare(const BigInt &n) const;

  inline BigInt copy() const;
  inline BigInt negate() const;

  BigInt shiftBits(int n_bits_left) const;

  // String conversions
  vector<bool> toBitsVector() const;
  string toCellsString() const;
  string toBinaryString() const;
  string toDecimalString() const;

  BigInt operator+(const BigInt &n) const;
  BigInt operator-(const BigInt &n) const;
  BigInt operator*(const BigInt &n) const;
  BigInt operator/(const BigInt &n) const;
  BigInt operator%(const BigInt &n) const;

  BigInt operator-() const;

  BigInt &operator+=(const BigInt &n);
  BigInt &operator-=(const BigInt &n);
  BigInt &operator*=(const BigInt &n);
  BigInt &operator/=(const BigInt &n);
  BigInt &operator%=(const BigInt &n);

  bool operator==(const BigInt &n) const;
  bool operator!=(const BigInt &n) const;
  bool operator<(const BigInt &n) const;
  bool operator>(const BigInt &n) const;
  bool operator<=(const BigInt &n) const;
  bool operator>=(const BigInt &n) const;

  BigInt operator<<(int n) const;
  BigInt operator>>(int n) const;

  BigInt &operator<<=(int n);
  BigInt &operator>>=(int n);

  BigInt operator++();
  BigInt operator++(int);
  BigInt operator--();
  BigInt operator--(int);

  friend ostream &operator<<(ostream &os, const BigInt &x) {
    return os << x.toDecimalString();
  }

private:
  inline static int sign_(SIGNED_DOUBLE_CELL_T c);
  inline static int compare_cells(CELL_T c1, CELL_T c2);
  static CELL_T div_next_quotient(const BigInt &u, const BigInt &v);
};

#endif //RSA_BIGINT_H
