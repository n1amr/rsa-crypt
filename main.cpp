#include <iostream>
#include <bits/stdc++.h>
#include "BigInt.h"
#include "DecimalStringHelpers.h"
using namespace std;

int main() {
  cout << "Hello, World!" << endl;

  CONTAINER_T<CELL_T> data({1, 2});
  BigInt x(data);
  cout << x << endl;
  cout << x.toCellsString() << endl;
  cout << x.toBitsString() << endl;
  cout << x.toDecimalString() << endl;

  string s = "123";
  cout << divideDecimalStringByTwo(s) << endl;

  return 0;
}