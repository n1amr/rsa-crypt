#ifndef RSA_BIGINT_H
#define RSA_BIGINT_H

#include <bits/stdc++.h>
using namespace std;

#define CONTAINER_T deque
#define CELL_T unsigned char
#define CELL_TYPE_LENGTH (sizeof(CELL_T) * 8)


class BigInt {
private:
  CONTAINER_T<CELL_T> data;

public:
  BigInt();
  BigInt(const CONTAINER_T<CELL_T> &init);

  string toCellsString() const;
  string toBitsString() const;
  string toDecimalString() const;

  friend ostream &operator<<(ostream &os, const BigInt &x) {
    return os << x.toBitsString();
  }
};

#endif //RSA_BIGINT_H
