#include "bigint_tests.h"
#include "bits/stdc++.h"
#include "../../bigint/BigInt.h"
#include "../../bigint/DecimalHelpers.h"
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

bool testSubtraction(string n1, string n2, string expected) {
  add_ops++;
  string output = BigInt::subtract(BigInt(n1), BigInt(n2)).toDecimalString();
  bool correct = expected == output;
  if (!correct)
    cout << n1 << " - " << n2 << " = " << expected << " != " << output << endl;
  return !correct;
}

bool testAdditionSubtractionSmallNumbers(long long n1_start, long long n2_start, long long steps) {
  for (long long i = n1_start; i < n1_start + steps; ++i) {
    for (long long j = n2_start; j < n2_start + steps; ++j) {
      bool bad =
          testAddition(to_string(i), to_string(j), to_string(i + j))
          || testAddition(to_string(i), to_string(-j), to_string(i - j))
          || testAddition(to_string(-i), to_string(j), to_string(-i + j))
          || testAddition(to_string(-i), to_string(-j), to_string(-i - j))
          || testSubtraction(to_string(i), to_string(-j), to_string(i + j))
          || testSubtraction(to_string(i), to_string(j), to_string(i - j))
          || testSubtraction(to_string(-i), to_string(-j), to_string(-i + j))
          || testSubtraction(to_string(-i), to_string(j), to_string(-i - j));
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

bool testMultiplication(string n1, string n2, string expected) {
  mul_ops++;
  string output = BigInt::multiply(BigInt(n1), BigInt(n2)).toDecimalString();
  bool correct = expected == output;
  if (!correct)
    cout << n1 << " * " << n2 << " = " << expected << " != " << output << endl;
  return !correct;
}

bool testMultiplicationSmallNumbers(long long n1_start, long long n2_start, long long steps) {
  for (long long i = n1_start; i < n1_start + steps; ++i) {
    for (long long j = n2_start; j < n2_start + steps; ++j) {
      bool bad = testMultiplication(to_string(i), to_string(j), to_string(i * j));
      if (bad)
        return bad;
    }
  }
  return 0;
}

bool testMultiplicationLongNumbers() {
  return testMultiplication(
      "49695700165340003591763298360793787790389700721006032962550750345751169893329781646405242590549172772653361935191472597091837344081386249491229556310016777875670909900770757760035554540680015525618951935911780761266142261603898700824084522153923122544256142742380519074007926967846888881440525780853947035022",
      "88352972791125599654602526729806289318058473276859480855617212988836676467159489722738068957562597567906068173874687651781669126218590167348485375483703607243201626118125468859381893195856552712039134967906750615111211852204440100709993128784338373228907267352165732599309856535472049222470403388325213434253",
      "4390762844544221301382902406733168845063887446673695681038901126589516324486872174593251287459038837673006252692795342760466061484950541992064671038090344069586993712870106532707591600212977801289036122525772195192015613446841363419443971696105292747800147575675918123780118961240020869192748281892848129172578166276883926228710835559697740220966300956149085285653936567962547064962956654474626823571911224071829917735208007842153479478149770430902294049999639836016794866595127246033598119912894381645536479187765278468631159417850565072273061142119867482306721963019196878894342252311339214292400044805671485408566");
}

bool testNegation(string input, string expected) {
  string output = (-BigInt(input)).toDecimalString();
  bool correct = expected == output;
  if (!correct)
    cout << "- " << input << " = " << expected << " != " << output << endl;
  return !correct;
}

bool testNegationSmallNumbers(long long start, long long steps) {
  for (long long i = start - steps; i <= start + steps; ++i) {
    bool bad = testNegation(to_string(i), to_string(-i));
    if (bad)
      return bad;
  }

  return 0;
}

bool testIsZero(string input, string expected) {
  string output = to_string(BigInt(input).isZero());
  bool correct = expected == output;
  if (!correct)
    cout << input << " == 0 => " << expected << " != " << output << endl;
  return !correct;
}

bool testIsPositive(string input, string expected) {
  string output = to_string(BigInt(input).isPositive());
  bool correct = expected == output;
  if (!correct)
    cout << input << " > 0 => " << expected << " != " << output << endl;
  return !correct;
}

bool testIsNegative(string input, string expected) {
  string output = to_string(BigInt(input).isNegative());
  bool correct = expected == output;
  if (!correct)
    cout << input << " < 0 => " << expected << " != " << output << endl;
  return !correct;
}

bool testIsZeroSmallNumbers(long long start, long long steps) {
  for (long long i = start - steps; i <= start + steps; ++i) {
    bool bad = testIsZero(to_string(i), to_string(i == 0));
    if (bad)
      return bad;
  }

  return 0;
}

bool testIsPositiveSmallNumbers(long long start, long long steps) {
  for (long long i = start - steps; i <= start + steps; ++i) {
    bool bad = testIsPositive(to_string(i), to_string(i > 0));
    if (bad)
      return bad;
  }

  return 0;
}

bool testIsNegativeSmallNumbers(long long start, long long steps) {
  for (long long i = start - steps; i <= start + steps; ++i) {
    bool bad = testIsNegative(to_string(i), to_string(i < 0));
    if (bad)
      return bad;
  }

  return 0;
}

bool testEquals(string n1, string n2, string expected) {
  string output = to_string(BigInt(n1) == BigInt(n2));
  bool correct = expected == output;
  if (!correct)
    cout << n1 << " == " << n2 << " => " << expected << " != " << output << endl;
  return !correct;
}

bool testEqualsSmallNumbers(long long start, long long steps) {
  for (long long i = start - steps; i <= start + steps; ++i) {
    for (long long j = start - steps; j <= start + steps; ++j) {
      bool bad = testEquals(to_string(i), to_string(j), to_string(i == j));
      if (bad)
        return bad;
    }
  }

  return 0;
}

bool testisLessThan(string n1, string n2, string expected) {
  string output = to_string(BigInt(n1) < BigInt(n2));
  bool correct = expected == output;
  if (!correct)
    cout << n1 << " < " << n2 << " => " << expected << " != " << output << endl;
  return !correct;
}

bool testIsLessThanSmallNumbers(long long start, long long steps) {
  for (long long i = start - steps; i <= start + steps; ++i) {
    for (long long j = start - steps; j <= start + steps; ++j) {
      bool bad = testisLessThan(to_string(i), to_string(j), to_string(i < j));
      if (bad)
        return bad;
    }
  }

  return 0;
}

bool testisGreaterThan(string n1, string n2, string expected) {
  string output = to_string(BigInt(n1) > BigInt(n2));
  bool correct = expected == output;
  if (!correct)
    cout << n1 << " > " << n2 << " => " << expected << " != " << output << endl;
  return !correct;
}

bool testIsGreaterThanSmallNumbers(long long start, long long steps) {
  for (long long i = start - steps; i <= start + steps; ++i) {
    for (long long j = start - steps; j <= start + steps; ++j) {
      bool bad = testisGreaterThan(to_string(i), to_string(j), to_string(i > j));
      if (bad)
        return bad;
    }
  }

  return 0;
}

bool testPostIncrement(long long n1) {
  BigInt x(to_string(n1));
  BigInt copy = x;
  BigInt result_1 = copy++;

  if (result_1 != x)
    cout << n1 << "++ before  => " << n1 << " != " << result_1 << endl;
  if (copy != x + BigInt::ONE)
    cout << n1 << "++ after  => " << (n1 + 1) << " != " << copy << endl;

  return result_1 != x || copy != x + BigInt::ONE;
}

bool testPreIncrement(long long n1) {
  BigInt x(to_string(n1));
  BigInt copy = x;
  BigInt result_1 = ++copy;

  if (result_1 != x + BigInt::ONE)
    cout << "++" << n1 << " before  => " << (n1 + 1) << " != " << result_1 << endl;
  if (copy != x + BigInt::ONE)
    cout << "++" << n1 << " after  => " << (n1 + 1) << " != " << copy << endl;

  return result_1 != x + BigInt::ONE || copy != x + BigInt::ONE;
}

bool testPostDecrement(long long n1) {
  BigInt x(to_string(n1));
  BigInt copy = x;
  BigInt result_1 = copy--;

  if (result_1 != x)
    cout << n1 << "-- before  => " << n1 << " != " << result_1 << endl;
  if (copy != x - BigInt::ONE)
    cout << n1 << "-- after  => " << (n1 - 1) << " != " << copy << endl;

  return result_1 != x || copy != x - BigInt::ONE;
}

bool testPreDecrement(long long n1) {
  BigInt x(to_string(n1));
  BigInt copy = x;
  BigInt result_1 = --copy;

  if (result_1 != x - BigInt::ONE)
    cout << "--" << n1 << " before  => " << (n1 - 1) << " != " << result_1 << endl;
  if (copy != x - BigInt::ONE)
    cout << "--" << n1 << " after  => " << (n1 - 1) << " != " << copy << endl;

  return result_1 != x - BigInt::ONE || copy != x - BigInt::ONE;
}

bool testIncrements(long long n1) {
  bool correct =
      testPostIncrement(n1)
      || testPreIncrement(n1)
      || testPostDecrement(n1)
      || testPreDecrement(n1);
  return !correct;
}

bool testIncrementsSmallNumbers(long long start, long long steps) {
  for (long long i = start - steps; i <= start + steps; ++i) {
    bool bad = testIncrements(i);
    if (bad)
      return bad;
  }

  return 0;
}

BigInt factorial(long long n) {
  BigInt product = BigInt::ONE;
  BigInt end = (BigInt) n;
  for (BigInt i = 1; i <= end; i++)
    product *= i;
  return product;
}

bool testFactorial(long long n, string expected) {
  BigInt result = factorial(n);
  string output = result.toDecimalString();
  bool correct = expected == output;
  if (!correct)
    cout << "factorial(" << n << ") = " << expected << " != " << output << endl;
  return !correct;
}

bool testShiftCells(string n, int n_cells_left, string expected) {
  string output = BigInt(n).shiftCells(n_cells_left).toDecimalString();
  bool correct = expected == output;
  if (!correct)
    if (n_cells_left >= 0)
      cout << n << " << " << n_cells_left * CELL_TYPE_LENGTH << " => " << expected << " != " << output << endl;
    else
      cout << n << " >> " << -n_cells_left * CELL_TYPE_LENGTH << " => " << expected << " != " << output << endl;
  return !correct;
}

bool testShiftCellsSmallNumbers(long long start, int shifts, long long steps) {
  for (long long i = start - steps; i <= start + steps; ++i) {
    for (int j = 0; j <= shifts; ++j) {
      long long expected = (i) << (j * CELL_TYPE_LENGTH);
      bool bad = testShiftCells(to_string(i), j, to_string(expected));
      expected = ((i) >> (j * CELL_TYPE_LENGTH));
      bad |= testShiftCells(to_string(i), -j, to_string(expected));
      if (bad)
        return bad;
    }
  }

  return 0;
}

bool testShiftBits(string n, int n_bits_left, string expected) {
  string output = BigInt(n).shiftBits(n_bits_left).toDecimalString();
  bool correct = expected == output;
  if (!correct)
    if (n_bits_left >= 0)
      cout << n << " << " << n_bits_left << " => " << expected << " != " << output << endl;
    else
      cout << n << " >> " << -n_bits_left << " => " << expected << " != " << output << endl;
  return !correct;
}

bool testShiftBitsSmallNumbers(long long start, int shifts, long long steps) {
  for (long long i = start - steps; i <= start + steps; ++i) {
    for (int j = 0; j <= shifts; ++j) {
      long long expected = i << j;
//      bool bad = 0;//TODO testShiftBits(to_string(i), j, to_string(expected));
      bool bad = testShiftBits(to_string(i), j, to_string(expected));
      expected = i >> j;
      bad |= testShiftBits(to_string(i), -j, to_string(expected));
      if (bad)
        return bad;
    }
  }

  return 0;
}

bool testShiftBitsLarge() {
  int n = 1565463521;
  BigInt x = n;
  for (int i = 1; i <= 100; ++i) {
    x <<= i;
  }
  string check = "248955115817378181928907367609155623287724881551510293745833109661562434923585474134853117854194778714960720217589990051666793682914059429066423572210259901998489966999786959801930402904011434071194986450650533481660393586476527601730398053595866492161451845678052430686652380887688024812207681378807237705461972255667891204439103870938148290300650860003845668812124232365568798546110678449536134295475337968727985501533039989241552379167675211169288349353549921707780941632570326910088064792384485375005805978187561284886874610369171149431363279330508567096340862915863700562548546780951716345644603800294736304889501149334228977743917710128884498727074388537054785721992788531813717262604510321302223269043659187623216999641666669307576295018746899609889939785044246884749676436115042363990582053591526609873343747438170244040154244168407192658283807717705339730215073953312162446170384562552115566558008318236686274672716371602213698444198487935552980173582564971557992551527864868613987630353023707523653359192746407734150332378565846426140128636005746292579848674694998710670304743663181036918346450849841471600949725090715144581178624240033022434203998973004421306401467015310888975782157013388301832833308092992117139777765019853480462207192756582054818210758011416695838279569634212257929607123008495427476560201326768015370082948806869590696118993018419281112239848215246994304410187944953024819960662155298040876902724360173444543369192202681968173886411449531679075389339909758323867236237918849264789360846519459119104";
  if (check != x.toDecimalString()) {
    cout << n << " << (101 * 100 / 2) = " << check << " != " << x << endl;
    return 1;
  }
  for (int i = 1; i <= 100; ++i) {
    x >>= i;
  }
  if (to_string(n) != x.toDecimalString()) {
    cout << "(" << n << " << (101 * 100 / 2)) >> (101 * 100 / 2) = " << n << " != " << x << endl;
    return 1;
  }
  return 0;
}

void runBigIntTests() {
  clock_t begin_time, end_time;
  begin_time = clock();

  testRepresentationOfSmallNumbers();
  testRepresentationOfLongNumbers();
  testRepresentationOf1024BitNumber();

  testConversionBetweenStringAndIntVectorShort();
  testConversionBetweenStringAndIntVectorLong();

  testIsZeroSmallNumbers(0, 1000);
  testIsPositiveSmallNumbers(0, 1000);
  testIsNegativeSmallNumbers(0, 1000);

  testEqualsSmallNumbers(0, 50);
  testEqualsSmallNumbers(MAX_CELL_VALUE, 50);

  testIsLessThanSmallNumbers(0, 50);
  testIsLessThanSmallNumbers(MAX_CELL_VALUE, 50);

  testIsGreaterThanSmallNumbers(0, 50);
  testIsGreaterThanSmallNumbers(MAX_CELL_VALUE, 50);

  testIncrementsSmallNumbers(0, 50);
  testIncrementsSmallNumbers(MAX_CELL_VALUE, 50);

  testNegationSmallNumbers(0, 500);
  testNegationSmallNumbers(MAX_CELL_VALUE, 500);

  testAdditionSubtractionSmallNumbers(0, 0, 50);
  testAdditionSubtractionSmallNumbers(MAX_CELL_VALUE - 5, MAX_CELL_VALUE - 5, 10);
  testAdditionSubtractionSmallNumbers(4654321, 46512, 50);
  testAdditionLongNumbers();

  testMultiplicationSmallNumbers(0, 0, 50);
  testMultiplicationSmallNumbers(MAX_CELL_VALUE - 5, MAX_CELL_VALUE - 5, 10);
  testMultiplicationSmallNumbers(523432261, 467115341, 50);
  testMultiplicationLongNumbers();

  testFactorial(171,
                "1241018070217667823424840524103103992616605577501693185388951803611996075221691752992751978120487585576464959501670387052809889858690710767331242032218484364310473577889968548278290754541561964852153468318044293239598173696899657235903947616152278558180061176365108428800000000000000000000000000000000000000000");

  testShiftCellsSmallNumbers(0, 6, 256);
  testShiftCellsSmallNumbers(MAX_CELL_VALUE, 6, 256);

  testShiftBitsSmallNumbers(0, 10, 256);
  testShiftBitsSmallNumbers(MAX_CELL_VALUE, 10, 256);

  testShiftBitsLarge();

  end_time = clock();
  float elapsed_time = float(end_time - begin_time) / CLOCKS_PER_SEC;
  cout << "Total BigInt tests time = " << elapsed_time
       << "(" << add_ops << " addition operations"
       << ", " << mul_ops << " multiplication operations" << ")" << endl;
}
