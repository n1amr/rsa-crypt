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

#define SIGN_T bool
#define POSITIVE 0
#define NEGATIVE 1

class BigInt {
private:
public:
  CONTAINER_T<CELL_T> data;
  SIGN_T sign = POSITIVE;

  BigInt();
  BigInt(const CONTAINER_T<CELL_T> &init, SIGN_T sign = POSITIVE);
  BigInt(const string &s);

  static BigInt ZERO;
  static BigInt ONE;

  static bool isZero(const BigInt &n);
  static bool isPositive(const BigInt &n);
  static bool isNegative(const BigInt &n);

  static BigInt add(const BigInt &n1, const BigInt &n2);
  static BigInt multiply(const BigInt &n1, const BigInt &n2);
  static BigInt subtract(const BigInt &n1, const BigInt &n2);

  bool isZero() const;
  bool isPositive() const;
  bool isNegative() const;

  BigInt add(const BigInt &n) const;
  BigInt multiply(const BigInt &n) const;
  BigInt subtract(const BigInt &n) const;

  BigInt copy() const;
  BigInt invert() const;
  BigInt negate() const;

  string toCellsString() const;
  string toBitsString() const;
  vector<bool> toBitsVector() const;
  string toAbsDecimalString() const;
  string toDecimalString() const;


  BigInt operator+(const BigInt &n) const { return this->add(n); }

  BigInt operator-(const BigInt &n) const { return this->subtract(n); }

  BigInt operator*(const BigInt &n) const { return this->multiply(n); }

  friend ostream &operator<<(ostream &os, const BigInt &x) {
    return os << x.toDecimalString();
  }
};

#endif //RSA_BIGINT_H
