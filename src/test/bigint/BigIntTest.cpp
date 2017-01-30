#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "../../main/bigint/BigInt.h"
#include "../../main/bigint/BigIntHelpers.h"

using namespace std;

class BigIntTest : public ::testing::Test {

};

TEST_F(BigIntTest, test_representation_of_small_numbers) {
  stringstream ss;
  string s;
  for (long long i = 0; i < 100; ++i) {
    ss.str("");
    ss << i;
    s = ss.str();
    BigInt x(s);
    ASSERT_EQ(s, x.toDecimalString());
  }
}

TEST_F(BigIntTest, test_representation_of_long_numbers) {
  stringstream ss;
  string s;
  long long start = (long long int) 1e17;
  for (long long i = start; i < start + 100; ++i) {
    ss.str("");
    ss << i;
    s = ss.str();
    BigInt x(s);
    ASSERT_EQ(s, x.toDecimalString());
  }
}

TEST_F(BigIntTest, test_representation_of1024_bit_number) {
  string s = "179769313486231590772930519078902473361797697894230657273430081157732675805500963132708477322407536021120113879871393357658789768814416622492847430639474124377767893424865485276302219601246094119453082952085005768838150682342462881473913110540827237163350510684586298239947245938479716304835356329624224137216";
  BigInt x(s);
  ASSERT_EQ(s, x.toDecimalString());
}

TEST_F(BigIntTest, test_conversion_between_string_and_int_vector_short) {
  stringstream ss;
  string s;
  long long start = 0;
  for (long long i = start; i < start + 100; ++i) {
    ss.str("");
    ss << i;
    s = ss.str();
    auto v = decimalStringToDecimalVec(s);
    string s2 = decimalVecToDecimalString(v);
    ASSERT_EQ(s, s2);
  }
}

TEST_F(BigIntTest, test_conversion_between_string_and_int_vector_long) {
  stringstream ss;
  string s;
  long long start = (long long int) 1e17;
  for (long long i = start; i < start + 100; ++i) {
    ss.str("");
    ss << i;
    s = ss.str();
    auto v = decimalStringToDecimalVec(s);
    string s2 = decimalVecToDecimalString(v);
    ASSERT_EQ(s, s2);
  }
}

TEST_F(BigIntTest, test_addition_subtraction_small_numbers_near_zero) {
  long long n1_start = 0;
  long long n2_start = 0;
  long long steps = 50;
  for (long long i = n1_start; i < n1_start + steps; i++) {
    for (long long j = n2_start; j < n2_start + steps; j++) {
      BigInt I(i);
      BigInt J(j);
      ASSERT_EQ(to_string(i + j), (I + J).toDecimalString());
      ASSERT_EQ(to_string(i - j), (I - J).toDecimalString());
      ASSERT_EQ(to_string(-i + j), (-I + J).toDecimalString());
      ASSERT_EQ(to_string(-i - j), (-I - J).toDecimalString());
    }
  }
}

TEST_F(BigIntTest, test_addition_subtraction_small_numbers_near_max_cell_value) {
  long long n1_start = MAX_CELL_VALUE - 5;
  long long n2_start = MAX_CELL_VALUE - 5;
  long long steps = 10;
  for (long long i = n1_start; i < n1_start + steps; i++) {
    for (long long j = n2_start; j < n2_start + steps; j++) {
      BigInt I(i);
      BigInt J(j);
      ASSERT_EQ(to_string(i + j), (I + J).toDecimalString());
      ASSERT_EQ(to_string(i - j), (I - J).toDecimalString());
      ASSERT_EQ(to_string(-i + j), (-I + J).toDecimalString());
      ASSERT_EQ(to_string(-i - j), (-I - J).toDecimalString());
    }
  }
}

TEST_F(BigIntTest, test_addition_subtraction_small_numbers) {
  long long n1_start = 4654321;
  long long n2_start = 46512;
  long long steps = 10;
  for (long long i = n1_start; i < n1_start + steps; i++) {
    for (long long j = n2_start; j < n2_start + steps; j++) {
      BigInt I(i);
      BigInt J(j);
      ASSERT_EQ(to_string(i + j), (I + J).toDecimalString());
      ASSERT_EQ(to_string(i - j), (I - J).toDecimalString());
      ASSERT_EQ(to_string(-i + j), (-I + J).toDecimalString());
      ASSERT_EQ(to_string(-i - j), (-I - J).toDecimalString());
    }
  }
}

TEST_F(BigIntTest, test_addition_subtraction_long_numbers) {
  BigInt I(
      "139008452377144732764939786789661303114218850808529137991604824430036072629766435941001769154109609521811665540548899435521");
  BigInt J(
      "2824013958708217496949108842204627863351353911851577524683401930862693830361198499905873920995229996970897865498283996578123296865878390947626553088486946106430796091482716120572632072492703527723757359478834530365734912");
  ASSERT_EQ(
      "2824013958708217496949108842204627863351353911851577524683401930862693830361198499905873920995230135979350242643016761517910086527181505166477361617624937711255226127555345887008573074261857637333279171144375079265170433",
      (I + J).toDecimalString());
  ASSERT_EQ(
      "-2824013958708217496949108842204627863351353911851577524683401930862693830361198499905873920995229857962445488353551231638336507204575276728775744559348954501606366055410086354136691070723549418114235547813293981466299391",
      (I - J).toDecimalString());
  ASSERT_EQ(
      "2824013958708217496949108842204627863351353911851577524683401930862693830361198499905873920995229857962445488353551231638336507204575276728775744559348954501606366055410086354136691070723549418114235547813293981466299391",
      (-I + J).toDecimalString());
  ASSERT_EQ(
      "-2824013958708217496949108842204627863351353911851577524683401930862693830361198499905873920995230135979350242643016761517910086527181505166477361617624937711255226127555345887008573074261857637333279171144375079265170433",
      (-I - J).toDecimalString());
}

TEST_F(BigIntTest, test_multiplication_small_numbers_near_zero) {
  long long n1_start = 0;
  long long n2_start = 0;
  long long steps = 50;
  for (long long i = n1_start - steps; i < n1_start + steps; ++i) {
    for (long long j = n2_start - steps; j < n2_start + steps; ++j) {
      ASSERT_EQ(to_string(i * j), (BigInt(i) * BigInt(j)).toDecimalString());
    }
  }
}

TEST_F(BigIntTest, test_multiplication_small_numbers_near_max_cell_value) {
  long long n1_start = MAX_CELL_VALUE / 2 - 5;
  long long n2_start = MAX_CELL_VALUE / 2 - 5;
  long long steps = 10;
  for (long long i = n1_start - steps; i < n1_start + steps; ++i) {
    for (long long j = n2_start - steps; j < n2_start + steps; ++j) {
      ASSERT_EQ(to_string(i * j), (BigInt(i) * BigInt(j)).toDecimalString());
    }
  }
}

TEST_F(BigIntTest, test_multiplication_small_numbers) {
  long long n1_start = 523432261;
  long long n2_start = 467115341;
  long long steps = 10;
  for (long long i = n1_start - steps; i < n1_start + steps; ++i) {
    for (long long j = n2_start - steps; j < n2_start + steps; ++j) {
      ASSERT_EQ(to_string(i * j), (BigInt(i) * BigInt(j)).toDecimalString());
    }
  }
}

TEST_F(BigIntTest, test_multiplication_long_numbers) {
  ASSERT_EQ(
      "4390762844544221301382902406733168845063887446673695681038901126589516324486872174593251287459038837673006252692795342760466061484950541992064671038090344069586993712870106532707591600212977801289036122525772195192015613446841363419443971696105292747800147575675918123780118961240020869192748281892848129172578166276883926228710835559697740220966300956149085285653936567962547064962956654474626823571911224071829917735208007842153479478149770430902294049999639836016794866595127246033598119912894381645536479187765278468631159417850565072273061142119867482306721963019196878894342252311339214292400044805671485408566",
      (BigInt(
          "49695700165340003591763298360793787790389700721006032962550750345751169893329781646405242590549172772653361935191472597091837344081386249491229556310016777875670909900770757760035554540680015525618951935911780761266142261603898700824084522153923122544256142742380519074007926967846888881440525780853947035022")
       * BigInt(
          "88352972791125599654602526729806289318058473276859480855617212988836676467159489722738068957562597567906068173874687651781669126218590167348485375483703607243201626118125468859381893195856552712039134967906750615111211852204440100709993128784338373228907267352165732599309856535472049222470403388325213434253")).toDecimalString());
}

TEST_F(BigIntTest, test_division_small_numbers_near_zero) {
  long long n1_start = 0;
  long long n2_start = 0;
  long long steps = 50;
  for (long long i = n1_start - steps; i < n1_start + steps; ++i) {
    for (long long j = n2_start - steps; j < n2_start + steps; ++j) {
      if (j == 0)
        continue;
      ASSERT_EQ(to_string(i / j), (BigInt(i) / BigInt(j)).toDecimalString());
    }
  }
}

TEST_F(BigIntTest, test_division_small_numbers_near_max_cell_value) {
  long long n1_start = MAX_CELL_VALUE - 5;
  long long n2_start = MAX_CELL_VALUE - 5;
  long long steps = 10;
  for (long long i = n1_start - steps; i < n1_start + steps; ++i) {
    for (long long j = n2_start - steps; j < n2_start + steps; ++j) {
      if (j == 0)
        continue;
      ASSERT_EQ(to_string(i / j), (BigInt(i) / BigInt(j)).toDecimalString());
    }
  }
}

TEST_F(BigIntTest, test_division_small_numbers) {
  long long n1_start = 523432261;
  long long n2_start = 467115341;
  long long steps = 10;
  for (long long i = n1_start - steps; i < n1_start + steps; ++i) {
    for (long long j = n2_start - steps; j < n2_start + steps; ++j) {
      if (j == 0)
        continue;
      ASSERT_EQ(to_string(i / j), (BigInt(i) / BigInt(j)).toDecimalString());
    }
  }
}

TEST_F(BigIntTest, test_division_long_numbers) {
  ASSERT_EQ(
      "2",
      (BigInt(
          "459325128745903883767300625269279534276046606148495054199206467103809034406958699371287010653270759160021297780128903612252577219519201561344684136341944397169610529274780014757567591812378011896124002086919274828189284812917250")
       / BigInt(
          "183529727911255996546025267298062893180584732768594808556172129888366764671594897227380689575625975679060681738746876517816691262185901673484853754837036072432016261181254688593818931958565527120391349679067506151112118522044401")).toDecimalString());
}

TEST_F(BigIntTest, test_mod_small_numbers_near_zero) {
  long long n1_start = 0;
  long long n2_start = 0;
  long long steps = 50;
  for (long long i = n1_start - steps; i < n1_start + steps; ++i) {
    for (long long j = n2_start - steps; j < n2_start + steps; ++j) {
      if (j == 0)
        continue;
      ASSERT_EQ(to_string(i % j), (BigInt(i) % BigInt(j)).toDecimalString());
    }
  }
}

TEST_F(BigIntTest, test_mod_small_numbers_near_max_cell_value) {
  long long n1_start = MAX_CELL_VALUE - 5;
  long long n2_start = MAX_CELL_VALUE - 5;
  long long steps = 10;
  for (long long i = n1_start - steps; i < n1_start + steps; ++i) {
    for (long long j = n2_start - steps; j < n2_start + steps; ++j) {
      if (j == 0)
        continue;
      ASSERT_EQ(to_string(i % j), (BigInt(i) % BigInt(j)).toDecimalString());
    }
  }
}

TEST_F(BigIntTest, test_mod_small_numbers) {
  long long n1_start = 523432261;
  long long n2_start = 467115341;
  long long steps = 10;
  for (long long i = n1_start - steps; i < n1_start + steps; ++i) {
    for (long long j = n2_start - steps; j < n2_start + steps; ++j) {
      if (j == 0)
        continue;
      ASSERT_EQ(to_string(i % j), (BigInt(i) % BigInt(j)).toDecimalString());
    }
  }
}

TEST_F(BigIntTest, test_mod_long_numbers) {
  ASSERT_EQ(
      "92265672923391890675250090673153747914877140611305437086862207327075505063768904916525631502018807801899934302635150576619194695147398214374976626667872252305578006912270637569929727895246957655341302728784262525965047768828448",
      (BigInt(
          "459325128745903883767300625269279534276046606148495054199206467103809034406958699371287010653270759160021297780128903612252577219519201561344684136341944397169610529274780014757567591812378011896124002086919274828189284812917250")
       % BigInt(
          "183529727911255996546025267298062893180584732768594808556172129888366764671594897227380689575625975679060681738746876517816691262185901673484853754837036072432016261181254688593818931958565527120391349679067506151112118522044401")).toDecimalString());
}

TEST_F(BigIntTest, test_is_zero_small_numbers) {
  long long start = 0;
  long long steps = 1000;
  for (long long i = start - steps; i <= start + steps; ++i) {
    ASSERT_EQ(i == 0, BigInt(i).isZero());
  }
}

TEST_F(BigIntTest, test_is_positive_small_numbers) {
  long long start = 0;
  long long steps = 1000;
  for (long long i = start - steps; i <= start + steps; ++i) {
    ASSERT_EQ(i > 0, BigInt(i).isPositive());
  }
}

TEST_F(BigIntTest, test_is_negative_small_numbers) {
  long long start = 0;
  long long steps = 1000;
  for (long long i = start - steps; i <= start + steps; ++i) {
    ASSERT_EQ(i < 0, BigInt(i).isNegative());
  }
}

TEST_F(BigIntTest, test_equals_small_numbers_near_zero) {
  long long start = 0;
  long long steps = 50;
  for (long long i = start - steps; i <= start + steps; ++i) {
    for (long long j = start - steps; j <= start + steps; ++j) {
      ASSERT_EQ(i == j, BigInt(i) == BigInt(j));
    }
  }
}

TEST_F(BigIntTest, test_equals_small_numbers_near_max_cell_value) {
  long long start = MAX_CELL_VALUE;
  long long steps = 50;
  for (long long i = start - steps; i <= start + steps; ++i) {
    for (long long j = start - steps; j <= start + steps; ++j) {
      ASSERT_EQ(i == j, BigInt(i) == BigInt(j));
    }
  }
}

TEST_F(BigIntTest, test_equals_small_numbers_1) {
  ASSERT_EQ(to_string(-1 == 255), to_string(BigInt(-1) == BigInt(255)));
}

TEST_F(BigIntTest, test_is_less_than_small_numbers_near_zero) {
  long long start = 0;
  long long steps = 50;
  for (long long i = start - steps; i <= start + steps; ++i) {
    for (long long j = start - steps; j <= start + steps; ++j) {
      ASSERT_EQ(i < j, BigInt(i) < BigInt(j));
    }
  }
}

TEST_F(BigIntTest, test_is_less_than_small_numbers_near_max_cell_value) {
  long long start = MAX_CELL_VALUE;
  long long steps = 50;
  for (long long i = start - steps; i <= start + steps; ++i) {
    for (long long j = start - steps; j <= start + steps; ++j) {
      ASSERT_EQ(i < j, BigInt(i) < BigInt(j));
    }
  }
}

TEST_F(BigIntTest, test_is_less_than_small_numbers_1) {
  ASSERT_EQ(to_string(-1 < 255), to_string(BigInt(-1) < BigInt(255)));
}

TEST_F(BigIntTest, test_is_greater_than_small_numbers_near_zero) {
  long long start = 0;
  long long steps = 50;
  for (long long i = start - steps; i <= start + steps; ++i) {
    for (long long j = start - steps; j <= start + steps; ++j) {
      ASSERT_EQ(i > j, BigInt(i) > BigInt(j));
    }
  }
}

TEST_F(BigIntTest, test_is_greater_than_small_numbers_near_max_cell_value) {
  long long start = MAX_CELL_VALUE;
  long long steps = 50;
  for (long long i = start - steps; i <= start + steps; ++i) {
    for (long long j = start - steps; j <= start + steps; ++j) {
      ASSERT_EQ(i > j, BigInt(i) > BigInt(j));
    }
  }
}

TEST_F(BigIntTest, test_is_greater_than_small_numbers1) {
  ASSERT_EQ(to_string(-1 > 255), to_string(BigInt(-1) > BigInt(255)));
}

TEST_F(BigIntTest, test_increments_small_numbers_near_zero) {
  long long start = 0;
  long long steps = 50;
  for (long long i = start - steps; i <= start + steps; ++i) {
    BigInt x(i);
    BigInt copy, result;

    copy = x;
    result = copy++;

    ASSERT_EQ(result, x);
    ASSERT_EQ(copy, x + BigInt::ONE);

    copy = x;
    result = copy--;

    ASSERT_EQ(result, x);
    ASSERT_EQ(copy, x - BigInt::ONE);

    copy = x;
    result = ++copy;

    ASSERT_EQ(result, x + BigInt::ONE);
    ASSERT_EQ(copy, x + BigInt::ONE);

    copy = x;
    result = --copy;

    ASSERT_EQ(result, x - BigInt::ONE);
    ASSERT_EQ(copy, x - BigInt::ONE);
  }
}

TEST_F(BigIntTest, test_increments_small_numbers_near_max_cell_value) {
  long long start = MAX_CELL_VALUE;
  long long steps = 50;
  for (long long i = start - steps; i <= start + steps; ++i) {
    BigInt x(i);
    BigInt copy, result;

    copy = x;
    result = copy++;

    ASSERT_EQ(result, x);
    ASSERT_EQ(copy, x + BigInt::ONE);

    copy = x;
    result = copy--;

    ASSERT_EQ(result, x);
    ASSERT_EQ(copy, x - BigInt::ONE);

    copy = x;
    result = ++copy;

    ASSERT_EQ(result, x + BigInt::ONE);
    ASSERT_EQ(copy, x + BigInt::ONE);

    copy = x;
    result = --copy;

    ASSERT_EQ(result, x - BigInt::ONE);
    ASSERT_EQ(copy, x - BigInt::ONE);
  }
}

TEST_F(BigIntTest, test_negation_small_numbers_near_zero) {
  long long start = 0;
  long long steps = 500;
  for (long long i = start - steps; i <= start + steps; ++i) {
    ASSERT_EQ(to_string(-i), (-BigInt(i)).toDecimalString());
  }
}

TEST_F(BigIntTest, test_negation_small_numbers_near_max_cell_value) {
  long long start = MAX_CELL_VALUE;
  long long steps = 500;
  for (long long i = start - steps; i <= start + steps; ++i) {
    ASSERT_EQ(to_string(-i), (-BigInt(i)).toDecimalString());
  }
}

TEST_F(BigIntTest, test_factorial) {
  string ans = "1241018070217667823424840524103103992616605577501693185388951803611996075221691752992751978120487585576464959501670387052809889858690710767331242032218484364310473577889968548278290754541561964852153468318044293239598173696899657235903947616152278558180061176365108428800000000000000000000000000000000000000000";

  BigInt product = BigInt::ONE;
  BigInt end(171);
  for (BigInt i = 1; i <= end; i++)
    product *= i;
}

TEST_F(BigIntTest, test_shift_bits_small_numbers_near_zero) {
  long long start = 0;
  int shifts = sizeof(unsigned long long) / CELL_BIT_LENGTH;
  long long steps = 256;
  for (long long i = start - steps; i <= start + steps; ++i) {
    for (int j = 0; j <= shifts; ++j) {
      bool negative = i < 0;
      long long expected = ((abs(i)) << j) * (negative ? -1 : 1);
      string output = BigInt(i).shiftBits(j).toDecimalString();
      ASSERT_EQ(to_string(expected), output);
    }
  }
}

TEST_F(BigIntTest, test_shift_bits_small_numbers_near_max_cell_value) {
  long long start = MAX_CELL_VALUE;
  int shifts = sizeof(unsigned long long) / CELL_BIT_LENGTH;
  long long steps = 256;
  for (long long i = start - steps; i <= start + steps; ++i) {
    for (int j = 0; j <= shifts; ++j) {
      bool negative = i < 0;
      long long expected = ((abs(i)) << j) * (negative ? -1 : 1);
      string output = BigInt(i).shiftBits(j).toDecimalString();
      ASSERT_EQ(to_string(expected), output);
    }
  }
}

TEST_F(BigIntTest, test_shift_bits_large_numbers) {
  int n = 1565463521;
  BigInt x = n;
  for (int i = 1; i <= 100; ++i) {
    x <<= i;
  }
  string check = "248955115817378181928907367609155623287724881551510293745833109661562434923585474134853117854194778714960720217589990051666793682914059429066423572210259901998489966999786959801930402904011434071194986450650533481660393586476527601730398053595866492161451845678052430686652380887688024812207681378807237705461972255667891204439103870938148290300650860003845668812124232365568798546110678449536134295475337968727985501533039989241552379167675211169288349353549921707780941632570326910088064792384485375005805978187561284886874610369171149431363279330508567096340862915863700562548546780951716345644603800294736304889501149334228977743917710128884498727074388537054785721992788531813717262604510321302223269043659187623216999641666669307576295018746899609889939785044246884749676436115042363990582053591526609873343747438170244040154244168407192658283807717705339730215073953312162446170384562552115566558008318236686274672716371602213698444198487935552980173582564971557992551527864868613987630353023707523653359192746407734150332378565846426140128636005746292579848674694998710670304743663181036918346450849841471600949725090715144581178624240033022434203998973004421306401467015310888975782157013388301832833308092992117139777765019853480462207192756582054818210758011416695838279569634212257929607123008495427476560201326768015370082948806869590696118993018419281112239848215246994304410187944953024819960662155298040876902724360173444543369192202681968173886411449531679075389339909758323867236237918849264789360846519459119104";
  ASSERT_EQ(check, x.toDecimalString());
  for (int i = 1; i <= 100; ++i) {
    x >>= i;
  }
  ASSERT_EQ(to_string(n), x.toDecimalString());
}
