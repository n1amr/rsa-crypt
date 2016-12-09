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
  reasonable_time = elapsed_time < 0.07;

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
  auto v = decimalStringToDecimalVec(s);
  string s2 = decimalVecToDecimalString(v);

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

bool testAddition(string n1, string n2, string ans) {
  BigInt x(n1);
  BigInt y(n2);
  BigInt z = x.add(y);

  bool correct = z.toDecimalString() == ans;
  if (!correct) {
    cout << n1 << " + " << n2 << " = " <<
         ans << " != " << z.toDecimalString() << endl;
  }
  return !correct;
}

bool testAdditionSmallNumbers() {
  int n1_start = 0;
  int n2_start = 0;
  for (int i = n1_start; i < n1_start + 100; ++i) {
    stringstream ss1;
    ss1 << i;
    string s1 = ss1.str();
    BigInt x(s1);
    for (int j = n2_start; j < n2_start + 100; ++j) {
      stringstream ss2;
      ss2 << j;
      string s2 = ss2.str();

      stringstream ss3;
      ss3 << (i + j);

      bool bad = testAddition(s1, s2, ss3.str());
      if (bad)
        return bad;
    }
  }
  return 0;
}

bool testAdditionSmallNumbers2() {
  int n1_start = 4654321;
  int n2_start = 46512;
  for (int i = n1_start; i < n1_start + 100; ++i) {
    stringstream ss1;
    ss1 << i;
    string s1 = ss1.str();
    BigInt x(s1);
    for (int j = n2_start; j < n2_start + 100; ++j) {
      stringstream ss2;
      ss2 << j;
      string s2 = ss2.str();

      stringstream ss3;
      ss3 << (i + j);

      bool bad = testAddition(s1, s2, ss3.str());
      if (bad)
        return bad;
    }
  }
  return 0;
}

bool testAdditionLongNumbers() {
  return testAddition(
      "139008452377144732764939786789661303114218850808529137991604824430036072629766435941001769154109609521811665540548899435521",
      "2824013958708217496949108842204627863351353911851577524683401930862693830361198499905873920995229996970897865498283996578123296865878390947626553088486946106430796091482716120572632072492703527723757359478834530365734912",
      "2824013958708217496949108842204627863351353911851577524683401930862693830361198499905873920995230135979350242643016761517910086527181505166477361617624937711255226127555345887008573074261857637333279171144375079265170433");
}

void runTests() {
  clock_t begin_time = clock();

  testRepresentationOfSmallNumbers();
  testRepresentationOfLongNumbers();
  testRepresentationOf1024BitNumber();
  testConversionBetweenStringAndIntVectorShort();
  testConversionBetweenStringAndIntVectorLong();
  testAdditionSmallNumbers();
  testAdditionSmallNumbers2();
  testAdditionLongNumbers();

  clock_t end_time = clock();
  float elapsed_time = float(end_time - begin_time) / CLOCKS_PER_SEC;
  cout << "Total test time = " << elapsed_time << endl;
}

