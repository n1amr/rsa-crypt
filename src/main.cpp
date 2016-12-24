#include <iostream>
#include <bits/stdc++.h>
#include "bigint/BigInt.h"
#include "bigint/DecimalHelpers.h"
using namespace std;
#define Int BigInt

int main() {
  Int x = 1;
  cout << x.compare_cells(200, 1) << endl;
  for (CELL_T i = 0; i < MAX_CELL_VALUE; ++i) {
    for (CELL_T j = 0; j < MAX_CELL_VALUE; ++j) {
      cout << ((int) i) << " - " << ((int) j) << " = " << ((int) (i - j)) << " " << x.compare_cells(i, j) << endl;
    }
  }
//  for (int i = 1; i < 10; ++i) {
//    x *= Int(i);
//  }
//  cout << x << endl;
  return 0;
}