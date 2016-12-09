#include <iostream>
#include <bits/stdc++.h>
#include "BigInt.h"

using namespace std;

int main() {
  cout << "Hello, World!" << endl;

  CONTAINER_T<CELL_T> data({1, 2});
  BigInt x(data);
  cout << x << endl;
  cout << x.toCellsString() << endl;
  cout << x.toBitsString() << endl;
  cout << x.toDecimalString() << endl;
  return 0;
}