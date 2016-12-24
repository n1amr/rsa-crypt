#ifndef RSA_BIGINT_H
#define RSA_BIGINT_H

#include <bits/stdc++.h>
using namespace std;

#define SMALL_CELL 1
#if SMALL_CELL
#define SIGNED_CELL_T char
#define SIGNED_DOUBLE_CELL_T short int
#else
#define SIGNED_CELL_T int
#define SIGNED_DOUBLE_CELL_T long long int
#endif

#define CELL_T unsigned SIGNED_CELL_T
#define DOUBLE_CELL_T unsigned SIGNED_DOUBLE_CELL_T

#define CELL_BIT_LENGTH (sizeof(CELL_T) * 8)
#define BASE ((1 << CELL_BIT_LENGTH))
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

  static BigInt add(const BigInt &a, const BigInt &b);
  static BigInt multiply(const BigInt &n1, const BigInt &n2);
  static BigInt subtract(const BigInt &n1, const BigInt &n2);
  static BigInt divide(const BigInt &n1, const BigInt &n2);
  static BigInt mod(const BigInt &n1, const BigInt &n2);

  bool isZero() const;
  bool isPositive() const;
  bool isNegative() const;

  bool equals(const BigInt &n) const;
  bool isLessThan(const BigInt &n) const;
  bool isGreaterThan(const BigInt &n) const;

  inline BigInt add(const BigInt &n) const;
  inline BigInt multiply(const BigInt &n) const;
  inline BigInt subtract(const BigInt &n) const;
  inline BigInt divide(const BigInt &n) const;
  inline BigInt mod(const BigInt &n) const;

  inline BigInt copy() const;
  inline BigInt invert() const;
  inline BigInt negate() const;

  BigInt shiftCells(int n_cells_left) const;
  BigInt shiftBits(int n_bits_left) const;

  string toCellsString() const;
  string toBitsString() const;
  vector<bool> toBitsVector() const;
  string toAbsDecimalString() const;
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

//private:
  inline static int sign_l(long long c);
  inline static int sign_(SIGNED_DOUBLE_CELL_T c);
  inline static int compare_cells(CELL_T c1, CELL_T c2);
  inline static int compare(const BigInt &a, const BigInt &b);

  static BigInt add_pos(const BigInt &a, const BigInt &b);
  static BigInt sub_pos(const BigInt &a, const BigInt &b);
  static BigInt absolute(const BigInt &a);
};

#endif //RSA_BIGINT_H
