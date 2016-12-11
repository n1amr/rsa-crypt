#ifndef RSA_BIGINT_H
#define RSA_BIGINT_H

#include <bits/stdc++.h>
using namespace std;

#define CONTAINER_T vector
//#define CELL_T unsigned int
//#define DOUBLE_CELL_T unsigned long long int
#define CELL_T unsigned char
#define DOUBLE_CELL_T unsigned short int
#define CELL_TYPE_LENGTH (sizeof(CELL_T) * 8)
#define SIGN_T bool
#define POSITIVE 0
#define NEGATIVE 1

class BigInt {
private:
  CONTAINER_T<CELL_T> data;
  SIGN_T sign = POSITIVE;

public:
  BigInt();
  BigInt(const CONTAINER_T<CELL_T> &init, SIGN_T sign = POSITIVE);
  BigInt(const string &s);

  string toCellsString() const;
  string toBitsString() const;
  vector<bool> toBitsVector() const;
  string toAbsDecimalString() const;
  string toDecimalString() const;

  BigInt add(const BigInt &n) const;
  BigInt multiply(const BigInt &n) const;

  BigInt invert() const;
  BigInt negate() const;

  static BigInt add(const BigInt &n1, const BigInt &n2);
  static BigInt multiply(const BigInt &n1, const BigInt &n2);

  friend ostream &operator<<(ostream &os, const BigInt &x) {
    return os << x.toDecimalString();
  }
};

#endif //RSA_BIGINT_H
