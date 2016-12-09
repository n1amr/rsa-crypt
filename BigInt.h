#ifndef RSA_BIGINT_H
#define RSA_BIGINT_H

#include <bits/stdc++.h>
using namespace std;

#define CONTAINER_T vector
#define CELL_T unsigned int
#define DOUBLE_CELL_T unsigned long long int
#define CELL_TYPE_LENGTH (sizeof(CELL_T) * 8)


class BigInt {
private:
  CONTAINER_T<CELL_T> data;

public:
  BigInt();
  BigInt(const CONTAINER_T<CELL_T> &init);
  BigInt(const string &s);

  string toCellsString() const;
  string toBitsString() const;
  vector<bool> toBitsVector() const;
  string toDecimalString() const;

  BigInt add(const BigInt &n);
  BigInt shiftCell();
  BigInt multiply(const BigInt &n);

  friend ostream &operator<<(ostream &os, const BigInt &x) {
    return os << x.toDecimalString();
  }
};

#endif //RSA_BIGINT_H
