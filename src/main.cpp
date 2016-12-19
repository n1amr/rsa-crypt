#include <iostream>
#include <bits/stdc++.h>
#include "bigint/BigInt.h"
#include "bigint/DecimalHelpers.h"
#include "tests/tests.h"
using namespace std;

int main() {
  cout << BigInt(-546310) / BigInt(-321) << endl;
  runTests();
  return 0;
}