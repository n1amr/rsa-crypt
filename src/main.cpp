#include <iostream>
#include <bits/stdc++.h>
#include "bigint/BigInt.h"
#include "bigint/DecimalHelpers.h"
#include "tests/tests.h"
using namespace std;
#define Int BigInt

int main() {
  cout << (Int(-255).shiftBits(-8)) << endl;
  return 0;
}