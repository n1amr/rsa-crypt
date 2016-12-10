#include "tests.h"
#include "bits/stdc++.h"
#include "BigInt.h"
#include "DecimalStringHelpers.h"
using namespace std;

int mul_ops = 0;
int add_ops = 0;

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

bool testAddition(string n1, string n2, string expected) {
  add_ops++;
  string output = BigInt::add(BigInt(n1), BigInt(n2)).toDecimalString();
  bool correct = expected == output;
  if (!correct)
    cout << n1 << " + " << n2 << " = " << expected << " != " << output << endl;
  return !correct;
}

bool testAdditionSmallNumbers(long long n1_start, long long n2_start, long long steps) {
  for (long long i = n1_start; i < n1_start + steps; ++i) {
    for (long long j = n2_start; j < n2_start + steps; ++j) {
      bool bad = testAddition(to_string(i), to_string(j), to_string(i + j))
                 || testAddition(to_string(i), to_string(-j), to_string(i - j))
                 || testAddition(to_string(-i), to_string(j), to_string(-i + j))
                 || testAddition(to_string(-i), to_string(-j), to_string(-i - j));
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
      "2824013958708217496949108842204627863351353911851577524683401930862693830361198499905873920995230135979350242643016761517910086527181505166477361617624937711255226127555345887008573074261857637333279171144375079265170433")
         || testAddition(
      "139008452377144732764939786789661303114218850808529137991604824430036072629766435941001769154109609521811665540548899435521",
      "-2824013958708217496949108842204627863351353911851577524683401930862693830361198499905873920995229996970897865498283996578123296865878390947626553088486946106430796091482716120572632072492703527723757359478834530365734912",
      "-2824013958708217496949108842204627863351353911851577524683401930862693830361198499905873920995229857962445488353551231638336507204575276728775744559348954501606366055410086354136691070723549418114235547813293981466299391")
         || testAddition(
      "-139008452377144732764939786789661303114218850808529137991604824430036072629766435941001769154109609521811665540548899435521",
      "2824013958708217496949108842204627863351353911851577524683401930862693830361198499905873920995229996970897865498283996578123296865878390947626553088486946106430796091482716120572632072492703527723757359478834530365734912",
      "2824013958708217496949108842204627863351353911851577524683401930862693830361198499905873920995229857962445488353551231638336507204575276728775744559348954501606366055410086354136691070723549418114235547813293981466299391")
         || testAddition(
      "-139008452377144732764939786789661303114218850808529137991604824430036072629766435941001769154109609521811665540548899435521",
      "-2824013958708217496949108842204627863351353911851577524683401930862693830361198499905873920995229996970897865498283996578123296865878390947626553088486946106430796091482716120572632072492703527723757359478834530365734912",
      "-2824013958708217496949108842204627863351353911851577524683401930862693830361198499905873920995230135979350242643016761517910086527181505166477361617624937711255226127555345887008573074261857637333279171144375079265170433");
}

bool testMutliplication(string n1, string n2, string expected) {
  mul_ops++;
  string output = BigInt::multiply(BigInt(n1), BigInt(n2)).toDecimalString();
  bool correct = expected == output;
  if (!correct)
    cout << n1 << " * " << n2 << " = " << expected << " != " << output << endl;
  return !correct;
}

bool testMutliplicationSmallNumbers(long long n1_start, long long n2_start, long long steps) {
  for (long long i = n1_start; i < n1_start + steps; ++i) {
    for (long long j = n2_start; j < n2_start + steps; ++j) {
      bool bad = testMutliplication(to_string(i), to_string(j), to_string(i * j));
      if (bad)
        return bad;
    }
  }
  return 0;
}

bool testMutliplicationLongNumbers() {
  return testMutliplication(
      "49695700165340003591763298360793787790389700721006032962550750345751169893329781646405242590549172772653361935191472597091837344081386249491229556310016777875670909900770757760035554540680015525618951935911780761266142261603898700824084522153923122544256142742380519074007926967846888881440525780853947035022",
      "88352972791125599654602526729806289318058473276859480855617212988836676467159489722738068957562597567906068173874687651781669126218590167348485375483703607243201626118125468859381893195856552712039134967906750615111211852204440100709993128784338373228907267352165732599309856535472049222470403388325213434253",
      "4390762844544221301382902406733168845063887446673695681038901126589516324486872174593251287459038837673006252692795342760466061484950541992064671038090344069586993712870106532707591600212977801289036122525772195192015613446841363419443971696105292747800147575675918123780118961240020869192748281892848129172578166276883926228710835559697740220966300956149085285653936567962547064962956654474626823571911224071829917735208007842153479478149770430902294049999639836016794866595127246033598119912894381645536479187765278468631159417850565072273061142119867482306721963019196878894342252311339214292400044805671485408566");
}

void runTests() {
  clock_t begin_time, end_time;
  begin_time = clock();

  testRepresentationOfSmallNumbers();
  testRepresentationOfLongNumbers();
  testRepresentationOf1024BitNumber();
  testConversionBetweenStringAndIntVectorShort();
  testConversionBetweenStringAndIntVectorLong();
  testAdditionSmallNumbers(0, 0, 50);
  testAdditionSmallNumbers(4654321, 46512, 50);
  testAdditionLongNumbers();
  testMutliplicationSmallNumbers(0, 0, 50);
  testMutliplicationSmallNumbers(523432261, 467115341, 50);
  testMutliplicationLongNumbers();

  end_time = clock();
  float elapsed_time = float(end_time - begin_time) / CLOCKS_PER_SEC;
  cout << "Total test time = " << elapsed_time << endl
       << "  " << add_ops << " addition operations" << endl
       << "  " << mul_ops << " multiplication operations" << endl;
}
