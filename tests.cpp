#include "tests.h"
#include "bits/stdc++.h"
#include "BigInt.h"
#include "DecimalStringHelpers.h"
using namespace std;

bool testRepresentationOf1024BitNumber();

bool testRepresentationOfANumber(string s) {
  bool correct;
  bool reasonable_time;

  clock_t begin_time = clock();
  BigInt x(s);
  correct = s == x.toDecimalString();
  clock_t end_time = clock();
  float elapsed_time = float(end_time - begin_time) / CLOCKS_PER_SEC;
  reasonable_time = elapsed_time < 0.05;

  if (!correct || !reasonable_time) {
    cout << endl << "=========================" << endl;
    cout << "i = " << s << endl;
    cout << s << endl;
    cout << x.toDecimalString() << endl;
    cout << x << endl;
    cout << x.toCellsString() << endl;
    cout << x.toBitsString() << endl;
    cout << x.toDecimalString() << endl;
    cout << (correct ? "True" : "False") << endl;
    cout << "Elapsed time = " << elapsed_time << endl;

    return 1;
  }
  return 0;
}

int testRepresentationOfSmallNumbers() {
  stringstream ss;
  string s;
  long long start = 0;
  for (long long i = start; i < start + 100; ++i) {
    ss.str("");
    ss << i;
    s = ss.str();
    bool bad = testRepresentationOfANumber(s);
    if (bad)
      return 1;
  }
  return 0;
}

bool testRepresentationOfLongNumbers() {
  stringstream ss;
  string s;
  long long start = (long long int) 1e17;
  for (long long i = start; i < start + 100; ++i) {
    ss.str("");
    ss << i;
    s = ss.str();
    bool bad = testRepresentationOfANumber(s);
    if (bad)
      return 1;
  }
  return 0;
}

bool testRepresentationOf1024BitNumber() {
  string s = "179769313486231590772930519078902473361797697894230657273430081157732675805500963132708477322407536021120113879871393357658789768814416622492847430639474124377767893424865485276302219601246094119453082952085005768838150682342462881473913110540827237163350510684586298239947245938479716304835356329624224137216";
  bool bad = testRepresentationOfANumber(s);
  if (bad)
    return 1;
  return 0;
}

bool testConversionBetweenStringAndIntVector(const string &s) {
  auto v = decimalStringToDecimalVector(s);
  string s2 = decimalVectorToDecimalString(v);

  bool pass = s == s2;
  if (!pass) {
    cout << "testConversionBetweenStringAndIntVector" << endl;
    cout << s << " !+ " << s2 << endl;
    return 1;
  }
  return 0;
}

int testConversionBetweenStringAndIntVectorShort() {
  stringstream ss;
  string s;
  long long start = 0;
  for (long long i = start; i < start + 100; ++i) {
    ss.str("");
    ss << i;
    s = ss.str();
    bool bad = testConversionBetweenStringAndIntVector(s);
    if (bad)
      return 1;
  }
  return 0;
}

int testConversionBetweenStringAndIntVectorLong() {
  stringstream ss;
  string s;
  long long start = (long long int) 1e17;
  for (long long i = start; i < start + 100; ++i) {
    ss.str("");
    ss << i;
    s = ss.str();
    bool bad = testConversionBetweenStringAndIntVector(s);
    if (bad)
      return 1;
  }
  return 0;
}

void runTests() {
  clock_t begin_time = clock();

  testRepresentationOfSmallNumbers();
  testRepresentationOfLongNumbers();
  testRepresentationOf1024BitNumber();
  testConversionBetweenStringAndIntVectorShort();
  testConversionBetweenStringAndIntVectorLong();

  clock_t end_time = clock();
  float elapsed_time = float(end_time - begin_time) / CLOCKS_PER_SEC;
  cout << "Total test time = " << elapsed_time << endl;
}

