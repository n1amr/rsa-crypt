#include "tests.h"
#include "bits/stdc++.h"
#include "bigint/old_bigint_tests.h"
using namespace std;

void runTests() {
  clock_t begin_time, end_time;
  begin_time = clock();

  runBigIntTests();

  end_time = clock();
  float elapsed_time = float(end_time - begin_time) / CLOCKS_PER_SEC;
  cout << "Total test time = " << elapsed_time << endl;
}
