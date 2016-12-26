#include <iostream>
#include <bits/stdc++.h>
#include "bigint/BigInt.h"
#include "bigint/DecimalHelpers.h"
#include "App.h"
using namespace std;
#define Int BigInt

int main() {
#ifdef N1AMR_LOCAL_PC
  srand(time(NULL));
#endif
  App app;
  app.appLoop();
}