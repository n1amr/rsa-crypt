#ifdef N1AMR_MULTIPLE_FILES

#include <iostream>
#include <bits/stdc++.h>
using namespace std;

#include "bigint/BigInt.h"
#include "bigint/BigIntHelpers.h"
#include "App.h"
#endif

int main() {
#ifdef N1AMR_LOCAL_PC
  srand(time(NULL));
#endif
  appLoop();
}