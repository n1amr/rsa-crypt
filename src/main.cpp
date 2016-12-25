#include <iostream>
#include <bits/stdc++.h>
#include "bigint/BigInt.h"
#include "bigint/DecimalHelpers.h"
using namespace std;
#define Int BigInt

int main() {
//  cout << BigInt(7).pow(BigInt(5), BigInt("1000")) << endl;
  cout << BigInt::pow(BigInt(7), BigInt(5), BigInt("1000")) << endl;
  return 0;
}