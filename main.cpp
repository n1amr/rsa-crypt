#include <iostream>
#include <bits/stdc++.h>
#include "BigInt.h"

using namespace std;

int main() {
  cout << "Hello, World!" << endl;

  BigInt x(CONTAINER_T<CELL_T>({1, 2}));
  cout << x << endl;
  cout << x.toCellsString() << endl;
  cout << x.toBitsString() << endl;
  cout << x.toDecimalString() << endl;
  return 0;
}