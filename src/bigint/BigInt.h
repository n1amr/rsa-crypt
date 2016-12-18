#ifndef RSA_BIGINT_H
#define RSA_BIGINT_H

#include <bits/stdc++.h>
using namespace std;

#define SMALL_CELL 1
#if SMALL_CELL
#define CELL_T unsigned char
#define DOUBLE_CELL_T unsigned short int
#else
#define CELL_T unsigned int
#define DOUBLE_CELL_T unsigned long long int
#endif

#define CELL_TYPE_LENGTH (sizeof(CELL_T) * 8)
#define MAX_CELL_VALUE (1 << CELL_TYPE_LENGTH)

#define CONTAINER_T vector
#define CELLS_CONTAINER_T CONTAINER_T<CELL_T>

#define SIGN_T bool
#define POSITIVE 0
#define NEGATIVE 1

class BigInt {
private:
  CELLS_CONTAINER_T data;
  SIGN_T sign = POSITIVE;

public:
  BigInt();
  BigInt(const CELLS_CONTAINER_T &init, SIGN_T sign = POSITIVE);
  BigInt(const BigInt &n);
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

  static BigInt add(const BigInt &n1, const BigInt &n2);
  static BigInt multiply(const BigInt &n1, const BigInt &n2);
  static BigInt subtract(const BigInt &n1, const BigInt &n2);

  bool isZero() const;
  bool isPositive() const;
  bool isNegative() const;

  bool equals(const BigInt &n) const;
  bool isLessThan(const BigInt &n) const;
  bool isGreaterThan(const BigInt &n) const;

  inline BigInt add(const BigInt &n) const;
  inline BigInt multiply(const BigInt &n) const;
  inline BigInt subtract(const BigInt &n) const;

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

  BigInt operator-() const;

  BigInt &operator+=(const BigInt &n);
  BigInt &operator-=(const BigInt &n);
  BigInt &operator*=(const BigInt &n);

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
};

#endif //RSA_BIGINT_H
