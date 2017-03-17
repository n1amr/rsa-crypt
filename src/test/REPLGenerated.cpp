
#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include "../main/bigint/BigInt.h"
#include "../main/REPL.h"

class REPLTest : public ::testing::Test {

};

TEST_F(REPLTest, test_encryption_4_bits_example_01) {
  eval("P=6");
  eval("Q=6");
  eval("E=227");
  EXPECT_EQ("No", eval("IsPPrime"));
  EXPECT_EQ("No", eval("IsQPrime"));

  eval("Quit");
}

TEST_F(REPLTest, test_encryption_4_bits_example_02) {
  eval("P=11");
  eval("Q=11");
  eval("E=151");
  EXPECT_EQ("Yes", eval("IsPPrime"));
  EXPECT_EQ("Yes", eval("IsQPrime"));
  EXPECT_EQ("121", eval("PrintN"));
  EXPECT_EQ("110", eval("PrintPhi"));
  EXPECT_EQ("51", eval("PrintD"));
  EXPECT_EQ("108", eval("EncryptPublic=97"));
  EXPECT_EQ("97", eval("EncryptPrivate=108"));
  EXPECT_EQ("97", eval("EncryptPrivate=108"));
  EXPECT_EQ("108", eval("EncryptPublic=97"));

  eval("Quit");
}

TEST_F(REPLTest, test_encryption_4_bits_example_03) {
  eval("P=9");
  eval("Q=6");
  eval("E=163");
  EXPECT_EQ("No", eval("IsPPrime"));
  EXPECT_EQ("No", eval("IsQPrime"));

  eval("Quit");
}

TEST_F(REPLTest, test_encryption_4_bits_example_04) {
  eval("P=13");
  eval("Q=11");
  eval("E=239");
  EXPECT_EQ("Yes", eval("IsPPrime"));
  EXPECT_EQ("Yes", eval("IsQPrime"));
  EXPECT_EQ("143", eval("PrintN"));
  EXPECT_EQ("120", eval("PrintPhi"));
  EXPECT_EQ("119", eval("PrintD"));
  EXPECT_EQ("119", eval("EncryptPublic=137"));
  EXPECT_EQ("137", eval("EncryptPrivate=119"));
  EXPECT_EQ("137", eval("EncryptPrivate=119"));
  EXPECT_EQ("119", eval("EncryptPublic=137"));

  eval("Quit");
}

TEST_F(REPLTest, test_encryption_4_bits_example_05) {
  eval("P=6");
  eval("Q=6");
  eval("E=137");
  EXPECT_EQ("No", eval("IsPPrime"));
  EXPECT_EQ("No", eval("IsQPrime"));

  eval("Quit");
}

TEST_F(REPLTest, test_encryption_4_bits_example_06) {
  eval("P=11");
  eval("Q=11");
  eval("E=251");
  EXPECT_EQ("Yes", eval("IsPPrime"));
  EXPECT_EQ("Yes", eval("IsQPrime"));
  EXPECT_EQ("121", eval("PrintN"));
  EXPECT_EQ("110", eval("PrintPhi"));
  EXPECT_EQ("71", eval("PrintD"));
  EXPECT_EQ("114", eval("EncryptPublic=4"));
  EXPECT_EQ("4", eval("EncryptPrivate=114"));
  EXPECT_EQ("4", eval("EncryptPrivate=114"));
  EXPECT_EQ("114", eval("EncryptPublic=4"));

  eval("Quit");
}

TEST_F(REPLTest, test_encryption_4_bits_example_07) {
  eval("P=9");
  eval("Q=6");
  eval("E=179");
  EXPECT_EQ("No", eval("IsPPrime"));
  EXPECT_EQ("No", eval("IsQPrime"));

  eval("Quit");
}

TEST_F(REPLTest, test_encryption_4_bits_example_08) {
  eval("P=13");
  eval("Q=11");
  eval("E=167");
  EXPECT_EQ("Yes", eval("IsPPrime"));
  EXPECT_EQ("Yes", eval("IsQPrime"));
  EXPECT_EQ("143", eval("PrintN"));
  EXPECT_EQ("120", eval("PrintPhi"));
  EXPECT_EQ("23", eval("PrintD"));
  EXPECT_EQ("113", eval("EncryptPublic=16"));
  EXPECT_EQ("16", eval("EncryptPrivate=113"));
  EXPECT_EQ("16", eval("EncryptPrivate=113"));
  EXPECT_EQ("113", eval("EncryptPublic=16"));

  eval("Quit");
}

TEST_F(REPLTest, test_encryption_4_bits_example_09) {
  eval("P=6");
  eval("Q=4");
  eval("E=211");
  EXPECT_EQ("No", eval("IsPPrime"));
  EXPECT_EQ("No", eval("IsQPrime"));

  eval("Quit");
}

TEST_F(REPLTest, test_encryption_4_bits_example_10) {
  eval("P=13");
  eval("Q=13");
  eval("E=139");
  EXPECT_EQ("Yes", eval("IsPPrime"));
  EXPECT_EQ("Yes", eval("IsQPrime"));
  EXPECT_EQ("169", eval("PrintN"));
  EXPECT_EQ("156", eval("PrintPhi"));
  EXPECT_EQ("55", eval("PrintD"));
  EXPECT_EQ("25", eval("EncryptPublic=77"));
  EXPECT_EQ("77", eval("EncryptPrivate=25"));
  EXPECT_EQ("77", eval("EncryptPrivate=25"));
  EXPECT_EQ("25", eval("EncryptPublic=77"));

  eval("Quit");
}

TEST_F(REPLTest, test_encryption_4_bits_example_11) {
  eval("P=9");
  eval("Q=6");
  eval("E=191");
  EXPECT_EQ("No", eval("IsPPrime"));
  EXPECT_EQ("No", eval("IsQPrime"));

  eval("Quit");
}

TEST_F(REPLTest, test_encryption_4_bits_example_12) {
  eval("P=11");
  eval("Q=11");
  eval("E=233");
  EXPECT_EQ("Yes", eval("IsPPrime"));
  EXPECT_EQ("Yes", eval("IsQPrime"));
  EXPECT_EQ("121", eval("PrintN"));
  EXPECT_EQ("110", eval("PrintPhi"));
  EXPECT_EQ("17", eval("PrintD"));
  EXPECT_EQ("14", eval("EncryptPublic=86"));
  EXPECT_EQ("86", eval("EncryptPrivate=14"));
  EXPECT_EQ("86", eval("EncryptPrivate=14"));
  EXPECT_EQ("14", eval("EncryptPublic=86"));

  eval("Quit");
}

TEST_F(REPLTest, test_encryption_4_bits_example_13) {
  eval("P=9");
  eval("Q=6");
  eval("E=191");
  EXPECT_EQ("No", eval("IsPPrime"));
  EXPECT_EQ("No", eval("IsQPrime"));

  eval("Quit");
}

TEST_F(REPLTest, test_encryption_4_bits_example_14) {
  eval("P=11");
  eval("Q=11");
  eval("E=181");
  EXPECT_EQ("Yes", eval("IsPPrime"));
  EXPECT_EQ("Yes", eval("IsQPrime"));
  EXPECT_EQ("121", eval("PrintN"));
  EXPECT_EQ("110", eval("PrintPhi"));
  EXPECT_EQ("31", eval("PrintD"));
  EXPECT_EQ("46", eval("EncryptPublic=2"));
  EXPECT_EQ("2", eval("EncryptPrivate=46"));
  EXPECT_EQ("2", eval("EncryptPrivate=46"));
  EXPECT_EQ("46", eval("EncryptPublic=2"));

  eval("Quit");
}

TEST_F(REPLTest, test_encryption_4_bits_example_15) {
  eval("P=4");
  eval("Q=9");
  eval("E=223");
  EXPECT_EQ("No", eval("IsPPrime"));
  EXPECT_EQ("No", eval("IsQPrime"));

  eval("Quit");
}

TEST_F(REPLTest, test_encryption_4_bits_example_16) {
  eval("P=13");
  eval("Q=13");
  eval("E=251");
  EXPECT_EQ("Yes", eval("IsPPrime"));
  EXPECT_EQ("Yes", eval("IsQPrime"));
  EXPECT_EQ("169", eval("PrintN"));
  EXPECT_EQ("156", eval("PrintPhi"));
  EXPECT_EQ("23", eval("PrintD"));
  EXPECT_EQ("96", eval("EncryptPublic=8"));
  EXPECT_EQ("8", eval("EncryptPrivate=96"));
  EXPECT_EQ("8", eval("EncryptPrivate=96"));
  EXPECT_EQ("96", eval("EncryptPublic=8"));

  eval("Quit");
}

TEST_F(REPLTest, test_encryption_4_bits_example_17) {
  eval("P=9");
  eval("Q=6");
  eval("E=163");
  EXPECT_EQ("No", eval("IsPPrime"));
  EXPECT_EQ("No", eval("IsQPrime"));

  eval("Quit");
}

TEST_F(REPLTest, test_encryption_4_bits_example_18) {
  eval("P=13");
  eval("Q=11");
  eval("E=151");
  EXPECT_EQ("Yes", eval("IsPPrime"));
  EXPECT_EQ("Yes", eval("IsQPrime"));
  EXPECT_EQ("143", eval("PrintN"));
  EXPECT_EQ("120", eval("PrintPhi"));
  EXPECT_EQ("31", eval("PrintD"));
  EXPECT_EQ("106", eval("EncryptPublic=128"));
  EXPECT_EQ("128", eval("EncryptPrivate=106"));
  EXPECT_EQ("128", eval("EncryptPrivate=106"));
  EXPECT_EQ("106", eval("EncryptPublic=128"));

  eval("Quit");
}

TEST_F(REPLTest, test_encryption_4_bits_example_19) {
  eval("P=9");
  eval("Q=6");
  eval("E=139");
  EXPECT_EQ("No", eval("IsPPrime"));
  EXPECT_EQ("No", eval("IsQPrime"));

  eval("Quit");
}

TEST_F(REPLTest, test_encryption_4_bits_example_20) {
  eval("P=11");
  eval("Q=11");
  eval("E=197");
  EXPECT_EQ("Yes", eval("IsPPrime"));
  EXPECT_EQ("Yes", eval("IsQPrime"));
  EXPECT_EQ("121", eval("PrintN"));
  EXPECT_EQ("110", eval("PrintPhi"));
  EXPECT_EQ("43", eval("PrintD"));
  EXPECT_EQ("70", eval("EncryptPublic=64"));
  EXPECT_EQ("64", eval("EncryptPrivate=70"));
  EXPECT_EQ("64", eval("EncryptPrivate=70"));
  EXPECT_EQ("70", eval("EncryptPublic=64"));

  eval("Quit");
}

TEST_F(REPLTest, test_encryption_8_bits_example_01) {
  eval("P=121");
  eval("Q=143");
  eval("E=41017");
  EXPECT_EQ("No", eval("IsPPrime"));
  EXPECT_EQ("No", eval("IsQPrime"));

  eval("Quit");
}

TEST_F(REPLTest, test_encryption_8_bits_example_02) {
  eval("P=233");
  eval("Q=229");
  eval("E=35419");
  EXPECT_EQ("Yes", eval("IsPPrime"));
  EXPECT_EQ("Yes", eval("IsQPrime"));
  EXPECT_EQ("53357", eval("PrintN"));
  EXPECT_EQ("52896", eval("PrintPhi"));
  EXPECT_EQ("46867", eval("PrintD"));
  EXPECT_EQ("51349", eval("EncryptPublic=48608"));
  EXPECT_EQ("48608", eval("EncryptPrivate=51349"));
  EXPECT_EQ("48608", eval("EncryptPrivate=51349"));
  EXPECT_EQ("51349", eval("EncryptPublic=48608"));

  eval("Quit");
}

TEST_F(REPLTest, test_encryption_8_bits_example_03) {
  eval("P=121");
  eval("Q=143");
  eval("E=52673");
  EXPECT_EQ("No", eval("IsPPrime"));
  EXPECT_EQ("No", eval("IsQPrime"));

  eval("Quit");
}

TEST_F(REPLTest, test_encryption_8_bits_example_04) {
  eval("P=157");
  eval("Q=197");
  eval("E=39779");
  EXPECT_EQ("Yes", eval("IsPPrime"));
  EXPECT_EQ("Yes", eval("IsQPrime"));
  EXPECT_EQ("30929", eval("PrintN"));
  EXPECT_EQ("30576", eval("PrintPhi"));
  EXPECT_EQ("5771", eval("PrintD"));
  EXPECT_EQ("9869", eval("EncryptPublic=16906"));
  EXPECT_EQ("16906", eval("EncryptPrivate=9869"));
  EXPECT_EQ("16906", eval("EncryptPrivate=9869"));
  EXPECT_EQ("9869", eval("EncryptPublic=16906"));

  eval("Quit");
}

TEST_F(REPLTest, test_encryption_8_bits_example_05) {
  eval("P=169");
  eval("Q=121");
  eval("E=47947");
  EXPECT_EQ("No", eval("IsPPrime"));
  EXPECT_EQ("No", eval("IsQPrime"));

  eval("Quit");
}

TEST_F(REPLTest, test_encryption_8_bits_example_06) {
  eval("P=241");
  eval("Q=149");
  eval("E=60167");
  EXPECT_EQ("Yes", eval("IsPPrime"));
  EXPECT_EQ("Yes", eval("IsQPrime"));
  EXPECT_EQ("35909", eval("PrintN"));
  EXPECT_EQ("35520", eval("PrintPhi"));
  EXPECT_EQ("21623", eval("PrintD"));
  EXPECT_EQ("28713", eval("EncryptPublic=28354"));
  EXPECT_EQ("28354", eval("EncryptPrivate=28713"));
  EXPECT_EQ("28354", eval("EncryptPrivate=28713"));
  EXPECT_EQ("28713", eval("EncryptPublic=28354"));

  eval("Quit");
}

TEST_F(REPLTest, test_encryption_8_bits_example_07) {
  eval("P=169");
  eval("Q=121");
  eval("E=37061");
  EXPECT_EQ("No", eval("IsPPrime"));
  EXPECT_EQ("No", eval("IsQPrime"));

  eval("Quit");
}

TEST_F(REPLTest, test_encryption_8_bits_example_08) {
  eval("P=173");
  eval("Q=179");
  eval("E=52807");
  EXPECT_EQ("Yes", eval("IsPPrime"));
  EXPECT_EQ("Yes", eval("IsQPrime"));
  EXPECT_EQ("30967", eval("PrintN"));
  EXPECT_EQ("30616", eval("PrintPhi"));
  EXPECT_EQ("28839", eval("PrintD"));
  EXPECT_EQ("15831", eval("EncryptPublic=8665"));
  EXPECT_EQ("8665", eval("EncryptPrivate=15831"));
  EXPECT_EQ("8665", eval("EncryptPrivate=15831"));
  EXPECT_EQ("15831", eval("EncryptPublic=8665"));

  eval("Quit");
}

TEST_F(REPLTest, test_encryption_8_bits_example_09) {
  eval("P=169");
  eval("Q=143");
  eval("E=39439");
  EXPECT_EQ("No", eval("IsPPrime"));
  EXPECT_EQ("No", eval("IsQPrime"));

  eval("Quit");
}

TEST_F(REPLTest, test_encryption_8_bits_example_10) {
  eval("P=199");
  eval("Q=163");
  eval("E=58451");
  EXPECT_EQ("Yes", eval("IsPPrime"));
  EXPECT_EQ("Yes", eval("IsQPrime"));
  EXPECT_EQ("32437", eval("PrintN"));
  EXPECT_EQ("32076", eval("PrintPhi"));
  EXPECT_EQ("8147", eval("PrintD"));
  EXPECT_EQ("15017", eval("EncryptPublic=24185"));
  EXPECT_EQ("24185", eval("EncryptPrivate=15017"));
  EXPECT_EQ("24185", eval("EncryptPrivate=15017"));
  EXPECT_EQ("15017", eval("EncryptPublic=24185"));

  eval("Quit");
}

TEST_F(REPLTest, test_encryption_8_bits_example_11) {
  eval("P=121");
  eval("Q=143");
  eval("E=60427");
  EXPECT_EQ("No", eval("IsPPrime"));
  EXPECT_EQ("No", eval("IsQPrime"));

  eval("Quit");
}

TEST_F(REPLTest, test_encryption_8_bits_example_12) {
  eval("P=181");
  eval("Q=223");
  eval("E=53917");
  EXPECT_EQ("Yes", eval("IsPPrime"));
  EXPECT_EQ("Yes", eval("IsQPrime"));
  EXPECT_EQ("40363", eval("PrintN"));
  EXPECT_EQ("39960", eval("PrintPhi"));
  EXPECT_EQ("17293", eval("PrintD"));
  EXPECT_EQ("8960", eval("EncryptPublic=8068"));
  EXPECT_EQ("8068", eval("EncryptPrivate=8960"));
  EXPECT_EQ("8068", eval("EncryptPrivate=8960"));
  EXPECT_EQ("8960", eval("EncryptPublic=8068"));

  eval("Quit");
}

TEST_F(REPLTest, test_encryption_8_bits_example_13) {
  eval("P=143");
  eval("Q=143");
  eval("E=33797");
  EXPECT_EQ("No", eval("IsPPrime"));
  EXPECT_EQ("No", eval("IsQPrime"));

  eval("Quit");
}

TEST_F(REPLTest, test_encryption_8_bits_example_14) {
  eval("P=163");
  eval("Q=251");
  eval("E=33749");
  EXPECT_EQ("Yes", eval("IsPPrime"));
  EXPECT_EQ("Yes", eval("IsQPrime"));
  EXPECT_EQ("40913", eval("PrintN"));
  EXPECT_EQ("40500", eval("PrintPhi"));
  EXPECT_EQ("6749", eval("PrintD"));
  EXPECT_EQ("11649", eval("EncryptPublic=34175"));
  EXPECT_EQ("34175", eval("EncryptPrivate=11649"));
  EXPECT_EQ("34175", eval("EncryptPrivate=11649"));
  EXPECT_EQ("11649", eval("EncryptPublic=34175"));

  eval("Quit");
}

TEST_F(REPLTest, test_encryption_8_bits_example_15) {
  eval("P=143");
  eval("Q=143");
  eval("E=57041");
  EXPECT_EQ("No", eval("IsPPrime"));
  EXPECT_EQ("No", eval("IsQPrime"));

  eval("Quit");
}

TEST_F(REPLTest, test_encryption_8_bits_example_16) {
  eval("P=227");
  eval("Q=233");
  eval("E=53267");
  EXPECT_EQ("Yes", eval("IsPPrime"));
  EXPECT_EQ("Yes", eval("IsQPrime"));
  EXPECT_EQ("52891", eval("PrintN"));
  EXPECT_EQ("52432", eval("PrintPhi"));
  EXPECT_EQ("22731", eval("PrintD"));
  EXPECT_EQ("47907", eval("EncryptPublic=6992"));
  EXPECT_EQ("6992", eval("EncryptPrivate=47907"));
  EXPECT_EQ("6992", eval("EncryptPrivate=47907"));
  EXPECT_EQ("47907", eval("EncryptPublic=6992"));

  eval("Quit");
}

TEST_F(REPLTest, test_encryption_8_bits_example_17) {
  eval("P=169");
  eval("Q=143");
  eval("E=58369");
  EXPECT_EQ("No", eval("IsPPrime"));
  EXPECT_EQ("No", eval("IsQPrime"));

  eval("Quit");
}

TEST_F(REPLTest, test_encryption_8_bits_example_18) {
  eval("P=239");
  eval("Q=229");
  eval("E=64157");
  EXPECT_EQ("Yes", eval("IsPPrime"));
  EXPECT_EQ("Yes", eval("IsQPrime"));
  EXPECT_EQ("54731", eval("PrintN"));
  EXPECT_EQ("54264", eval("PrintPhi"));
  EXPECT_EQ("10301", eval("PrintD"));
  EXPECT_EQ("26586", eval("EncryptPublic=33778"));
  EXPECT_EQ("33778", eval("EncryptPrivate=26586"));
  EXPECT_EQ("33778", eval("EncryptPrivate=26586"));
  EXPECT_EQ("26586", eval("EncryptPublic=33778"));

  eval("Quit");
}

TEST_F(REPLTest, test_encryption_8_bits_example_19) {
  eval("P=143");
  eval("Q=143");
  eval("E=46757");
  EXPECT_EQ("No", eval("IsPPrime"));
  EXPECT_EQ("No", eval("IsQPrime"));

  eval("Quit");
}

TEST_F(REPLTest, test_encryption_8_bits_example_20) {
  eval("P=131");
  eval("Q=227");
  eval("E=50387");
  EXPECT_EQ("Yes", eval("IsPPrime"));
  EXPECT_EQ("Yes", eval("IsQPrime"));
  EXPECT_EQ("29737", eval("PrintN"));
  EXPECT_EQ("29380", eval("PrintPhi"));
  EXPECT_EQ("15183", eval("PrintD"));
  EXPECT_EQ("6970", eval("EncryptPublic=29619"));
  EXPECT_EQ("29619", eval("EncryptPrivate=6970"));
  EXPECT_EQ("29619", eval("EncryptPrivate=6970"));
  EXPECT_EQ("6970", eval("EncryptPublic=29619"));

  eval("Quit");
}

TEST_F(REPLTest, test_encryption_16_bits_example_01) {
  eval("P=32881");
  eval("Q=37327");
  eval("E=3635919347");
  EXPECT_EQ("No", eval("IsPPrime"));
  EXPECT_EQ("No", eval("IsQPrime"));

  eval("Quit");
}

TEST_F(REPLTest, test_encryption_16_bits_example_02) {
  eval("P=49481");
  eval("Q=52957");
  eval("E=3920776109");
  EXPECT_EQ("Yes", eval("IsPPrime"));
  EXPECT_EQ("Yes", eval("IsQPrime"));
  EXPECT_EQ("2620365317", eval("PrintN"));
  EXPECT_EQ("2620262880", eval("PrintPhi"));
  EXPECT_EQ("424077029", eval("PrintD"));
  EXPECT_EQ("925636265", eval("EncryptPublic=46748275"));
  EXPECT_EQ("46748275", eval("EncryptPrivate=925636265"));
  EXPECT_EQ("46748275", eval("EncryptPrivate=925636265"));
  EXPECT_EQ("925636265", eval("EncryptPublic=46748275"));

  eval("Quit");
}

TEST_F(REPLTest, test_encryption_16_bits_example_03) {
  eval("P=36863");
  eval("Q=30227");
  eval("E=4225979353");
  EXPECT_EQ("No", eval("IsPPrime"));
  EXPECT_EQ("No", eval("IsQPrime"));

  eval("Quit");
}

TEST_F(REPLTest, test_encryption_16_bits_example_04) {
  eval("P=62701");
  eval("Q=34919");
  eval("E=2961762703");
  EXPECT_EQ("Yes", eval("IsPPrime"));
  EXPECT_EQ("Yes", eval("IsQPrime"));
  EXPECT_EQ("2189456219", eval("PrintN"));
  EXPECT_EQ("2189358600", eval("PrintPhi"));
  EXPECT_EQ("1626809167", eval("PrintD"));
  EXPECT_EQ("615845395", eval("EncryptPublic=1469457238"));
  EXPECT_EQ("1469457238", eval("EncryptPrivate=615845395"));
  EXPECT_EQ("1469457238", eval("EncryptPrivate=615845395"));
  EXPECT_EQ("615845395", eval("EncryptPublic=1469457238"));

  eval("Quit");
}

TEST_F(REPLTest, test_encryption_16_bits_example_05) {
  eval("P=37909");
  eval("Q=29503");
  eval("E=2515753169");
  EXPECT_EQ("No", eval("IsPPrime"));
  EXPECT_EQ("No", eval("IsQPrime"));

  eval("Quit");
}

TEST_F(REPLTest, test_encryption_16_bits_example_06) {
  eval("P=43573");
  eval("Q=33391");
  eval("E=3277710871");
  EXPECT_EQ("Yes", eval("IsPPrime"));
  EXPECT_EQ("Yes", eval("IsQPrime"));
  EXPECT_EQ("1454946043", eval("PrintN"));
  EXPECT_EQ("1454869080", eval("PrintPhi"));
  EXPECT_EQ("1130229031", eval("PrintD"));
  EXPECT_EQ("694765231", eval("EncryptPublic=940012767"));
  EXPECT_EQ("940012767", eval("EncryptPrivate=694765231"));
  EXPECT_EQ("940012767", eval("EncryptPrivate=694765231"));
  EXPECT_EQ("694765231", eval("EncryptPublic=940012767"));

  eval("Quit");
}

TEST_F(REPLTest, test_encryption_16_bits_example_07) {
  eval("P=40301");
  eval("Q=30997");
  eval("E=3142143581");
  EXPECT_EQ("No", eval("IsPPrime"));
  EXPECT_EQ("No", eval("IsQPrime"));

  eval("Quit");
}

TEST_F(REPLTest, test_encryption_16_bits_example_08) {
  eval("P=33191");
  eval("Q=40939");
  eval("E=2408574929");
  EXPECT_EQ("Yes", eval("IsPPrime"));
  EXPECT_EQ("Yes", eval("IsQPrime"));
  EXPECT_EQ("1358806349", eval("PrintN"));
  EXPECT_EQ("1358732220", eval("PrintPhi"));
  EXPECT_EQ("1291527689", eval("PrintD"));
  EXPECT_EQ("412083068", eval("EncryptPublic=1221577176"));
  EXPECT_EQ("1221577176", eval("EncryptPrivate=412083068"));
  EXPECT_EQ("1221577176", eval("EncryptPrivate=412083068"));
  EXPECT_EQ("412083068", eval("EncryptPublic=1221577176"));

  eval("Quit");
}

TEST_F(REPLTest, test_encryption_16_bits_example_09) {
  eval("P=50621");
  eval("Q=29999");
  eval("E=3968334719");
  EXPECT_EQ("No", eval("IsPPrime"));
  EXPECT_EQ("No", eval("IsQPrime"));

  eval("Quit");
}

TEST_F(REPLTest, test_encryption_16_bits_example_10) {
  eval("P=64969");
  eval("Q=38693");
  eval("E=3328993831");
  EXPECT_EQ("Yes", eval("IsPPrime"));
  EXPECT_EQ("Yes", eval("IsQPrime"));
  EXPECT_EQ("2513845517", eval("PrintN"));
  EXPECT_EQ("2513741856", eval("PrintPhi"));
  EXPECT_EQ("674078647", eval("PrintD"));
  EXPECT_EQ("1112901617", eval("EncryptPublic=2466366899"));
  EXPECT_EQ("2466366899", eval("EncryptPrivate=1112901617"));
  EXPECT_EQ("2466366899", eval("EncryptPrivate=1112901617"));
  EXPECT_EQ("1112901617", eval("EncryptPublic=2466366899"));

  eval("Quit");
}

TEST_F(REPLTest, test_encryption_16_bits_example_11) {
  eval("P=40309");
  eval("Q=26671");
  eval("E=3894299999");
  EXPECT_EQ("No", eval("IsPPrime"));
  EXPECT_EQ("No", eval("IsQPrime"));

  eval("Quit");
}

TEST_F(REPLTest, test_encryption_16_bits_example_12) {
  eval("P=34369");
  eval("Q=53717");
  eval("E=3903123881");
  EXPECT_EQ("Yes", eval("IsPPrime"));
  EXPECT_EQ("Yes", eval("IsQPrime"));
  EXPECT_EQ("1846199573", eval("PrintN"));
  EXPECT_EQ("1846111488", eval("PrintPhi"));
  EXPECT_EQ("122534297", eval("PrintD"));
  EXPECT_EQ("425660546", eval("EncryptPublic=756939400"));
  EXPECT_EQ("756939400", eval("EncryptPrivate=425660546"));
  EXPECT_EQ("756939400", eval("EncryptPrivate=425660546"));
  EXPECT_EQ("425660546", eval("EncryptPublic=756939400"));

  eval("Quit");
}

TEST_F(REPLTest, test_encryption_16_bits_example_13) {
  eval("P=26671");
  eval("Q=29143");
  eval("E=3645802613");
  EXPECT_EQ("No", eval("IsPPrime"));
  EXPECT_EQ("No", eval("IsQPrime"));

  eval("Quit");
}

TEST_F(REPLTest, test_encryption_16_bits_example_14) {
  eval("P=33179");
  eval("Q=56857");
  eval("E=3616356923");
  EXPECT_EQ("Yes", eval("IsPPrime"));
  EXPECT_EQ("Yes", eval("IsQPrime"));
  EXPECT_EQ("1886458403", eval("PrintN"));
  EXPECT_EQ("1886368368", eval("PrintPhi"));
  EXPECT_EQ("376548515", eval("PrintD"));
  EXPECT_EQ("1536563650", eval("EncryptPublic=709133191"));
  EXPECT_EQ("709133191", eval("EncryptPrivate=1536563650"));
  EXPECT_EQ("709133191", eval("EncryptPrivate=1536563650"));
  EXPECT_EQ("1536563650", eval("EncryptPublic=709133191"));

  eval("Quit");
}

TEST_F(REPLTest, test_encryption_16_bits_example_15) {
  eval("P=31921");
  eval("Q=47941");
  eval("E=3477957229");
  EXPECT_EQ("No", eval("IsPPrime"));
  EXPECT_EQ("No", eval("IsQPrime"));

  eval("Quit");
}

TEST_F(REPLTest, test_encryption_16_bits_example_16) {
  eval("P=51449");
  eval("Q=58411");
  eval("E=4102862083");
  EXPECT_EQ("Yes", eval("IsPPrime"));
  EXPECT_EQ("Yes", eval("IsQPrime"));
  EXPECT_EQ("3005187539", eval("PrintN"));
  EXPECT_EQ("3005077680", eval("PrintPhi"));
  EXPECT_EQ("1122481867", eval("PrintD"));
  EXPECT_EQ("1424983898", eval("EncryptPublic=2358984864"));
  EXPECT_EQ("2358984864", eval("EncryptPrivate=1424983898"));
  EXPECT_EQ("2358984864", eval("EncryptPrivate=1424983898"));
  EXPECT_EQ("1424983898", eval("EncryptPublic=2358984864"));

  eval("Quit");
}

TEST_F(REPLTest, test_encryption_16_bits_example_17) {
  eval("P=50621");
  eval("Q=29737");
  eval("E=2807006009");
  EXPECT_EQ("No", eval("IsPPrime"));
  EXPECT_EQ("No", eval("IsQPrime"));

  eval("Quit");
}

TEST_F(REPLTest, test_encryption_16_bits_example_18) {
  eval("P=57601");
  eval("Q=39791");
  eval("E=2424411697");
  EXPECT_EQ("Yes", eval("IsPPrime"));
  EXPECT_EQ("Yes", eval("IsQPrime"));
  EXPECT_EQ("2292001391", eval("PrintN"));
  EXPECT_EQ("2291904000", eval("PrintPhi"));
  EXPECT_EQ("1830286033", eval("PrintD"));
  EXPECT_EQ("1339952649", eval("EncryptPublic=721547750"));
  EXPECT_EQ("721547750", eval("EncryptPrivate=1339952649"));
  EXPECT_EQ("721547750", eval("EncryptPrivate=1339952649"));
  EXPECT_EQ("1339952649", eval("EncryptPublic=721547750"));

  eval("Quit");
}

TEST_F(REPLTest, test_encryption_16_bits_example_19) {
  eval("P=34393");
  eval("Q=29503");
  eval("E=4017726281");
  EXPECT_EQ("No", eval("IsPPrime"));
  EXPECT_EQ("No", eval("IsQPrime"));

  eval("Quit");
}

TEST_F(REPLTest, test_encryption_16_bits_example_20) {
  eval("P=54521");
  eval("Q=62201");
  eval("E=4280992171");
  EXPECT_EQ("Yes", eval("IsPPrime"));
  EXPECT_EQ("Yes", eval("IsQPrime"));
  EXPECT_EQ("3391260721", eval("PrintN"));
  EXPECT_EQ("3391144000", eval("PrintPhi"));
  EXPECT_EQ("55225731", eval("PrintD"));
  EXPECT_EQ("2290928217", eval("EncryptPublic=2985894439"));
  EXPECT_EQ("2985894439", eval("EncryptPrivate=2290928217"));
  EXPECT_EQ("2985894439", eval("EncryptPrivate=2290928217"));
  EXPECT_EQ("2290928217", eval("EncryptPublic=2985894439"));

  eval("Quit");
}

TEST_F(REPLTest, test_encryption_64_bits_example_01) {
  eval("P=6756800338979256107");
  eval("Q=14255490511306429163");
  eval("E=225550710307629669293439709502425079453");
  EXPECT_EQ("No", eval("IsPPrime"));
  EXPECT_EQ("No", eval("IsQPrime"));

  eval("Quit");
}

TEST_F(REPLTest, test_encryption_64_bits_example_02) {
  eval("P=13926228073013387591");
  eval("Q=15421173758199796661");
  eval("E=210080684855383446241745488143562521329");
  EXPECT_EQ("Yes", eval("IsPPrime"));
  EXPECT_EQ("Yes", eval("IsQPrime"));
  EXPECT_EQ("214758782910259374570324576026980633651", eval("PrintN"));
  EXPECT_EQ("214758782910259374540977174195767449400", eval("PrintPhi"));
  EXPECT_EQ("154634395213948537807046202969720444769", eval("PrintD"));
  EXPECT_EQ("30139863598339456095648561905112287421", eval("EncryptPublic=193001811617647802279230202404136521051"));
  EXPECT_EQ("193001811617647802279230202404136521051", eval("EncryptPrivate=30139863598339456095648561905112287421"));
  EXPECT_EQ("193001811617647802279230202404136521051", eval("EncryptPrivate=30139863598339456095648561905112287421"));
  EXPECT_EQ("30139863598339456095648561905112287421", eval("EncryptPublic=193001811617647802279230202404136521051"));

  eval("Quit");
}

TEST_F(REPLTest, test_encryption_64_bits_example_03) {
  eval("P=8907464351933085709");
  eval("Q=10905809796175954151");
  eval("E=323747128127806532704745839540699602923");
  EXPECT_EQ("No", eval("IsPPrime"));
  EXPECT_EQ("No", eval("IsQPrime"));

  eval("Quit");
}

TEST_F(REPLTest, test_encryption_64_bits_example_04) {
  eval("P=14804621901127885973");
  eval("Q=9664851802494823603");
  eval("E=232656040403941681075082233084593493069");
  EXPECT_EQ("Yes", eval("IsPPrime"));
  EXPECT_EQ("Yes", eval("IsQPrime"));
  EXPECT_EQ("143084476666370190928768383646933020719", eval("PrintN"));
  EXPECT_EQ("143084476666370190904298909943310311144", eval("PrintPhi"));
  EXPECT_EQ("6334018511845310349843360100322631781", eval("PrintD"));
  EXPECT_EQ("76684171854084439862248482572943653571", eval("EncryptPublic=66396736572293346453356546430811572589"));
  EXPECT_EQ("66396736572293346453356546430811572589", eval("EncryptPrivate=76684171854084439862248482572943653571"));
  EXPECT_EQ("66396736572293346453356546430811572589", eval("EncryptPrivate=76684171854084439862248482572943653571"));
  EXPECT_EQ("76684171854084439862248482572943653571", eval("EncryptPublic=66396736572293346453356546430811572589"));

  eval("Quit");
}

TEST_F(REPLTest, test_encryption_64_bits_example_05) {
  eval("P=11914174450361822393");
  eval("Q=9483217213790793511");
  eval("E=236932571115677259331289992565307556601");
  EXPECT_EQ("No", eval("IsPPrime"));
  EXPECT_EQ("No", eval("IsQPrime"));

  eval("Quit");
}

TEST_F(REPLTest, test_encryption_64_bits_example_06) {
  eval("P=13529878248190553177");
  eval("Q=11564068132082840599");
  eval("E=174946187272310627324671193828860203713");
  EXPECT_EQ("Yes", eval("IsPPrime"));
  EXPECT_EQ("Yes", eval("IsQPrime"));
  EXPECT_EQ("156460433880861185876074231455324033023", eval("PrintN"));
  EXPECT_EQ("156460433880861185850980285075050639248", eval("PrintPhi"));
  EXPECT_EQ("35823136079153074347728715617586245681", eval("PrintD"));
  EXPECT_EQ("19090923314034864605342160187887791554", eval("EncryptPublic=108809620401055579520137015286792510181"));
  EXPECT_EQ("108809620401055579520137015286792510181", eval("EncryptPrivate=19090923314034864605342160187887791554"));
  EXPECT_EQ("108809620401055579520137015286792510181", eval("EncryptPrivate=19090923314034864605342160187887791554"));
  EXPECT_EQ("19090923314034864605342160187887791554", eval("EncryptPublic=108809620401055579520137015286792510181"));

  eval("Quit");
}

TEST_F(REPLTest, test_encryption_64_bits_example_07) {
  eval("P=7921383111601035893");
  eval("Q=10837848698941217321");
  eval("E=290425316370732685109315993167748856377");
  EXPECT_EQ("No", eval("IsPPrime"));
  EXPECT_EQ("No", eval("IsQPrime"));

  eval("Quit");
}

TEST_F(REPLTest, test_encryption_64_bits_example_08) {
  eval("P=14890543061084975159");
  eval("Q=11428313047948040143");
  eval("E=316909227322949949058602283116987545267");
  EXPECT_EQ("Yes", eval("IsPPrime"));
  EXPECT_EQ("Yes", eval("IsQPrime"));
  EXPECT_EQ("170173787556029572158249257057889807737", eval("PrintN"));
  EXPECT_EQ("170173787556029572131930400948856792436", eval("PrintPhi"));
  EXPECT_EQ("124894668385394368206699593650449942707", eval("PrintD"));
  EXPECT_EQ("30559501500483367385077647867552457490", eval("EncryptPublic=51622842520147039214674166819626280755"));
  EXPECT_EQ("51622842520147039214674166819626280755", eval("EncryptPrivate=30559501500483367385077647867552457490"));
  EXPECT_EQ("51622842520147039214674166819626280755", eval("EncryptPrivate=30559501500483367385077647867552457490"));
  EXPECT_EQ("30559501500483367385077647867552457490", eval("EncryptPublic=51622842520147039214674166819626280755"));

  eval("Quit");
}

TEST_F(REPLTest, test_encryption_64_bits_example_09) {
  eval("P=10192048780731182887");
  eval("Q=6177212851671541171");
  eval("E=191550353568142816634400890456549701777");
  EXPECT_EQ("No", eval("IsPPrime"));
  EXPECT_EQ("No", eval("IsQPrime"));

  eval("Quit");
}

TEST_F(REPLTest, test_encryption_64_bits_example_10) {
  eval("P=15375811020940280389");
  eval("Q=17416488387654063563");
  eval("E=291582055892697027405355006303020188549");
  EXPECT_EQ("Yes", eval("IsPPrime"));
  EXPECT_EQ("Yes", eval("IsQPrime"));
  EXPECT_EQ("267792634096969764955913209944448366007", eval("PrintN"));
  EXPECT_EQ("267792634096969764923120910535854022056", eval("PrintPhi"));
  EXPECT_EQ("100092853533347889299021700702754344197", eval("PrintD"));
  EXPECT_EQ("230290157628922819805472618833459619426", eval("EncryptPublic=51452319469961274871184604245127634622"));
  EXPECT_EQ("51452319469961274871184604245127634622", eval("EncryptPrivate=230290157628922819805472618833459619426"));
  EXPECT_EQ("51452319469961274871184604245127634622", eval("EncryptPrivate=230290157628922819805472618833459619426"));
  EXPECT_EQ("230290157628922819805472618833459619426", eval("EncryptPublic=51452319469961274871184604245127634622"));

  eval("Quit");
}

TEST_F(REPLTest, test_encryption_64_bits_example_11) {
  eval("P=11868283314625507271");
  eval("Q=11332101574017838043");
  eval("E=216217982978724726856405249465361644109");
  EXPECT_EQ("No", eval("IsPPrime"));
  EXPECT_EQ("No", eval("IsQPrime"));

  eval("Quit");
}

TEST_F(REPLTest, test_encryption_64_bits_example_12) {
  eval("P=15775588151326444481");
  eval("Q=14931968007856975091");
  eval("E=247621795334073433928508322536709869251");
  EXPECT_EQ("Yes", eval("IsPPrime"));
  EXPECT_EQ("Yes", eval("IsQPrime"));
  EXPECT_EQ("235560577580734029694915220896811422771", eval("PrintN"));
  EXPECT_EQ("235560577580734029664207664737628003200", eval("PrintPhi"));
  EXPECT_EQ("30508472940264301977366615654613299051", eval("PrintD"));
  EXPECT_EQ("172383763331739714804091413194922639963", eval("EncryptPublic=215487669534964163516764342733745599819"));
  EXPECT_EQ("215487669534964163516764342733745599819", eval("EncryptPrivate=172383763331739714804091413194922639963"));
  EXPECT_EQ("215487669534964163516764342733745599819", eval("EncryptPrivate=172383763331739714804091413194922639963"));
  EXPECT_EQ("172383763331739714804091413194922639963", eval("EncryptPublic=215487669534964163516764342733745599819"));

  eval("Quit");
}

TEST_F(REPLTest, test_encryption_64_bits_example_13) {
  eval("P=11374413057286673083");
  eval("Q=11033935978340310977");
  eval("E=263620003576625987751792328709976060697");
  EXPECT_EQ("No", eval("IsPPrime"));
  EXPECT_EQ("No", eval("IsQPrime"));

  eval("Quit");
}

TEST_F(REPLTest, test_encryption_64_bits_example_14) {
  eval("P=13822436919189471773");
  eval("Q=12321756696018171187");
  eval("E=275144628408955910236573608472564901033");
  EXPECT_EQ("Yes", eval("IsPPrime"));
  EXPECT_EQ("Yes", eval("IsQPrime"));
  EXPECT_EQ("170316704664311654797720037788018404551", eval("PrintN"));
  EXPECT_EQ("170316704664311654771575844172810761592", eval("PrintPhi"));
  EXPECT_EQ("34270431113331661198831690605641258801", eval("PrintD"));
  EXPECT_EQ("107774720630309445292336170079378749010", eval("EncryptPublic=83402783002900522326258430621077429845"));
  EXPECT_EQ("83402783002900522326258430621077429845", eval("EncryptPrivate=107774720630309445292336170079378749010"));
  EXPECT_EQ("83402783002900522326258430621077429845", eval("EncryptPrivate=107774720630309445292336170079378749010"));
  EXPECT_EQ("107774720630309445292336170079378749010", eval("EncryptPublic=83402783002900522326258430621077429845"));

  eval("Quit");
}

TEST_F(REPLTest, test_encryption_64_bits_example_15) {
  eval("P=8486808974449728631");
  eval("Q=12330179151028381633");
  eval("E=212408009834881329920049423969770888209");
  EXPECT_EQ("No", eval("IsPPrime"));
  EXPECT_EQ("No", eval("IsQPrime"));

  eval("Quit");
}

TEST_F(REPLTest, test_encryption_64_bits_example_16) {
  eval("P=9959533216352545673");
  eval("Q=10144397672192143069");
  eval("E=269189907529611729490688050914583576129");
  EXPECT_EQ("Yes", eval("IsPPrime"));
  EXPECT_EQ("Yes", eval("IsQPrime"));
  EXPECT_EQ("101033465576087091934452292367572890437", eval("PrintN"));
  EXPECT_EQ("101033465576087091914348361479028201696", eval("PrintPhi"));
  EXPECT_EQ("62162575456999167128518947054750638785", eval("PrintD"));
  EXPECT_EQ("6964890820424269993959144145180525558", eval("EncryptPublic=38350293661850814676462674652524537981"));
  EXPECT_EQ("38350293661850814676462674652524537981", eval("EncryptPrivate=6964890820424269993959144145180525558"));
  EXPECT_EQ("38350293661850814676462674652524537981", eval("EncryptPrivate=6964890820424269993959144145180525558"));
  EXPECT_EQ("6964890820424269993959144145180525558", eval("EncryptPublic=38350293661850814676462674652524537981"));

  eval("Quit");
}

TEST_F(REPLTest, test_encryption_64_bits_example_17) {
  eval("P=6805882509349782637");
  eval("Q=10438712385239157361");
  eval("E=270518917422889870844723222957076295141");
  EXPECT_EQ("No", eval("IsPPrime"));
  EXPECT_EQ("No", eval("IsQPrime"));

  eval("Quit");
}

TEST_F(REPLTest, test_encryption_64_bits_example_18) {
  eval("P=18433348803187282439");
  eval("Q=16086865671052577897");
  eval("E=191801621585442099771697072687421460589");
  EXPECT_EQ("Yes", eval("IsPPrime"));
  EXPECT_EQ("Yes", eval("IsQPrime"));
  EXPECT_EQ("296534806064531615966469305776787650783", eval("PrintN"));
  EXPECT_EQ("296534806064531615931949091302547790448", eval("PrintPhi"));
  EXPECT_EQ("277531804180025654773822983321530370613", eval("PrintD"));
  EXPECT_EQ("55138834080444667987142085312612357347", eval("EncryptPublic=271879585331132254090164376985576904774"));
  EXPECT_EQ("271879585331132254090164376985576904774", eval("EncryptPrivate=55138834080444667987142085312612357347"));
  EXPECT_EQ("271879585331132254090164376985576904774", eval("EncryptPrivate=55138834080444667987142085312612357347"));
  EXPECT_EQ("55138834080444667987142085312612357347", eval("EncryptPublic=271879585331132254090164376985576904774"));

  eval("Quit");
}

TEST_F(REPLTest, test_encryption_64_bits_example_19) {
  eval("P=7436768660678655667");
  eval("Q=9973118984838944933");
  eval("E=291242384624980817899599834396019649317");
  EXPECT_EQ("No", eval("IsPPrime"));
  EXPECT_EQ("No", eval("IsQPrime"));

  eval("Quit");
}

TEST_F(REPLTest, test_encryption_64_bits_example_20) {
  eval("P=15405359168643239137");
  eval("Q=12903052354592307539");
  eval("E=186506681045285650262761767414340426579");
  EXPECT_EQ("Yes", eval("IsPPrime"));
  EXPECT_EQ("Yes", eval("IsQPrime"));
  EXPECT_EQ("198776155894302340109442941440224953843", eval("PrintN"));
  EXPECT_EQ("198776155894302340081134529916989407168", eval("PrintPhi"));
  EXPECT_EQ("165656298640441004974496692080136366747", eval("PrintD"));
  EXPECT_EQ("113637930584172519098614848958953288180", eval("EncryptPublic=18959663429148131798591892114891218923"));
  EXPECT_EQ("18959663429148131798591892114891218923", eval("EncryptPrivate=113637930584172519098614848958953288180"));
  EXPECT_EQ("18959663429148131798591892114891218923", eval("EncryptPrivate=113637930584172519098614848958953288180"));
  EXPECT_EQ("113637930584172519098614848958953288180", eval("EncryptPublic=18959663429148131798591892114891218923"));

  eval("Quit");
}

TEST_F(REPLTest, test_encryption_128_bits_example_01) {
  eval("P=257011780336105575847819190919182809231");
  eval("Q=126671495232057965190848063353404208181");
  eval("E=115207221538606310019757358323321020506027233243398360805434487408611219980179");
  EXPECT_EQ("No", eval("IsPPrime"));
  EXPECT_EQ("No", eval("IsQPrime"));

  eval("Quit");
}

TEST_F(REPLTest, test_encryption_128_bits_example_02) {
  eval("P=195426791912270738646999107309413745089");
  eval("Q=284255182468895495295810904691141564873");
  eval("E=106423000083093869708288679596327049532941538550141411257853963480467620726211");
  EXPECT_EQ("Yes", eval("IsPPrime"));
  EXPECT_EQ("Yes", eval("IsQPrime"));
  EXPECT_EQ("55551078394333389235152725690431485782254458621035723471064918841026978658697", eval("PrintN"));
  EXPECT_EQ("55551078394333389235152725690431485781774776646654557237122108829026423348736", eval("PrintPhi"));
  EXPECT_EQ("29363473829347865681641726162935792181061287349434583826813745916175660005611", eval("PrintD"));
  EXPECT_EQ("8196823698370879272152032124272893760832264384163487104818600000997990156768", eval("EncryptPublic=29280545889306079200034053205988102717893914448219415615985288581747444795385"));
  EXPECT_EQ("29280545889306079200034053205988102717893914448219415615985288581747444795385", eval("EncryptPrivate=8196823698370879272152032124272893760832264384163487104818600000997990156768"));
  EXPECT_EQ("29280545889306079200034053205988102717893914448219415615985288581747444795385", eval("EncryptPrivate=8196823698370879272152032124272893760832264384163487104818600000997990156768"));
  EXPECT_EQ("8196823698370879272152032124272893760832264384163487104818600000997990156768", eval("EncryptPublic=29280545889306079200034053205988102717893914448219415615985288581747444795385"));

  eval("Quit");
}

TEST_F(REPLTest, test_encryption_128_bits_example_03) {
  eval("P=248034954872576530722589702285168465697");
  eval("Q=130813053582083012494661390317959113897");
  eval("E=112904003633782002050882694453420457198415631572949860476943598100600098078353");
  EXPECT_EQ("No", eval("IsPPrime"));
  EXPECT_EQ("No", eval("IsQPrime"));

  eval("Quit");
}

TEST_F(REPLTest, test_encryption_128_bits_example_04) {
  eval("P=173736882468115157914681438638806825941");
  eval("Q=177182936459790660957181947620140343573");
  eval("E=104981981180123374984602333735695173829919272342718282459591146850973879488031");
  EXPECT_EQ("Yes", eval("IsPPrime"));
  EXPECT_EQ("Yes", eval("IsQPrime"));
  EXPECT_EQ("30783211007070166088081799750605121576619928455911356049412069616829349027193", eval("PrintN"));
  EXPECT_EQ("30783211007070166088081799750605121576269008636983450230540206230570401857680", eval("PrintPhi"));
  EXPECT_EQ("11802263116060084119319484036367866058660176157896840835337263686778925066351", eval("PrintD"));
  EXPECT_EQ("22243960043518432397471578403598498866934292662486832457015233642698435405705", eval("EncryptPublic=21950616088924324620393082105704588560263801282057887916166852084178231231550"));
  EXPECT_EQ("21950616088924324620393082105704588560263801282057887916166852084178231231550", eval("EncryptPrivate=22243960043518432397471578403598498866934292662486832457015233642698435405705"));
  EXPECT_EQ("21950616088924324620393082105704588560263801282057887916166852084178231231550", eval("EncryptPrivate=22243960043518432397471578403598498866934292662486832457015233642698435405705"));
  EXPECT_EQ("22243960043518432397471578403598498866934292662486832457015233642698435405705", eval("EncryptPublic=21950616088924324620393082105704588560263801282057887916166852084178231231550"));

  eval("Quit");
}

TEST_F(REPLTest, test_encryption_128_bits_example_05) {
  eval("P=235598910265175379407176369048103307721");
  eval("Q=108387540938538624498751904387314927261");
  eval("E=65802934257871071756674268156668964943681025380680301829747003529716649830603");
  EXPECT_EQ("No", eval("IsPPrime"));
  EXPECT_EQ("No", eval("IsQPrime"));

  eval("Quit");
}

TEST_F(REPLTest, test_encryption_128_bits_example_06) {
  eval("P=246172215066127497584370239033876703367");
  eval("Q=215696608776830576222254462940097654941");
  eval("E=66496621204699102383803916875499024053076164803382418266670618824457321999677");
  EXPECT_EQ("Yes", eval("IsPPrime"));
  EXPECT_EQ("Yes", eval("IsQPrime"));
  EXPECT_EQ("53098511964844300604205429863957726886746678932036519883225283845448578886347", eval("PrintN"));
  EXPECT_EQ("53098511964844300604205429863957726886284810108193561809418659143474604528040", eval("PrintPhi"));
  EXPECT_EQ("21270993390411973366793256588672686050426951538305056933331546137752509360853", eval("PrintD"));
  EXPECT_EQ("28992048698052127114149021398844651753610345115225380988460106672828098675849", eval("EncryptPublic=36913076120538119566929001235012041426683165987943522664748900743480425165988"));
  EXPECT_EQ("36913076120538119566929001235012041426683165987943522664748900743480425165988", eval("EncryptPrivate=28992048698052127114149021398844651753610345115225380988460106672828098675849"));
  EXPECT_EQ("36913076120538119566929001235012041426683165987943522664748900743480425165988", eval("EncryptPrivate=28992048698052127114149021398844651753610345115225380988460106672828098675849"));
  EXPECT_EQ("28992048698052127114149021398844651753610345115225380988460106672828098675849", eval("EncryptPublic=36913076120538119566929001235012041426683165987943522664748900743480425165988"));

  eval("Quit");
}

TEST_F(REPLTest, test_encryption_128_bits_example_07) {
  eval("P=161983002296490010271568104677852982101");
  eval("Q=177804148622093132434035305366557020667");
  eval("E=112323425564025164901960341770121031390641375202041728704789008191235541066317");
  EXPECT_EQ("No", eval("IsPPrime"));
  EXPECT_EQ("No", eval("IsQPrime"));

  eval("Quit");
}

TEST_F(REPLTest, test_encryption_128_bits_example_08) {
  eval("P=190585193637779383189460640501668567597");
  eval("Q=221795561469628044632725002968552498537");
  eval("E=103501528634914158447530569802844836886027061605515758432539047974851862990987");
  EXPECT_EQ("Yes", eval("IsPPrime"));
  EXPECT_EQ("Yes", eval("IsQPrime"));
  EXPECT_EQ("42270950030689060912799985488505896386168252938739255107460388457552228105589", eval("PrintN"));
  EXPECT_EQ("42270950030689060912799985488505896385755872183631847679638202814082007039456", eval("PrintPhi"));
  EXPECT_EQ("28275533171125031479166189696839789661575557712535855824018607633658604658947", eval("PrintD"));
  EXPECT_EQ("14375483924721888570204346921061043562032864454656343696088426429406044249371", eval("EncryptPublic=37012381627833377016161959105003341389024007644941395611841685184473718155551"));
  EXPECT_EQ("37012381627833377016161959105003341389024007644941395611841685184473718155551", eval("EncryptPrivate=14375483924721888570204346921061043562032864454656343696088426429406044249371"));
  EXPECT_EQ("37012381627833377016161959105003341389024007644941395611841685184473718155551", eval("EncryptPrivate=14375483924721888570204346921061043562032864454656343696088426429406044249371"));
  EXPECT_EQ("14375483924721888570204346921061043562032864454656343696088426429406044249371", eval("EncryptPublic=37012381627833377016161959105003341389024007644941395611841685184473718155551"));

  eval("Quit");
}

TEST_F(REPLTest, test_encryption_128_bits_example_09) {
  eval("P=115417099707631958432357846680273410317");
  eval("Q=161558368671186324443100188584510211539");
  eval("E=97177055125430599600101319775660455747173613648202455320670156422827604097747");
  EXPECT_EQ("No", eval("IsPPrime"));
  EXPECT_EQ("No", eval("IsQPrime"));

  eval("Quit");
}

TEST_F(REPLTest, test_encryption_128_bits_example_10) {
  eval("P=261340526844853744590848908359033333497");
  eval("Q=240588127846068652044520769485307855903");
  eval("E=93125324635914473794322723205380514332240693753275356849227875592616094449893");
  EXPECT_EQ("Yes", eval("IsPPrime"));
  EXPECT_EQ("Yes", eval("IsQPrime"));
  EXPECT_EQ("62875428083908609272279022378054943812959022693833595858270500394135819082791", eval("PrintN"));
  EXPECT_EQ("62875428083908609272279022378054943812457094039142673461635130716291477893392", eval("PrintPhi"));
  EXPECT_EQ("21426236808799121824858121106881477378476568046572902501131377001055276841677", eval("PrintD"));
  EXPECT_EQ("21622518736761104545707327804498970279598639407753352118251715464364423192238", eval("EncryptPublic=35666951498718687696944939733521797750934102846216745879078034431826736769529"));
  EXPECT_EQ("35666951498718687696944939733521797750934102846216745879078034431826736769529", eval("EncryptPrivate=21622518736761104545707327804498970279598639407753352118251715464364423192238"));
  EXPECT_EQ("35666951498718687696944939733521797750934102846216745879078034431826736769529", eval("EncryptPrivate=21622518736761104545707327804498970279598639407753352118251715464364423192238"));
  EXPECT_EQ("21622518736761104545707327804498970279598639407753352118251715464364423192238", eval("EncryptPublic=35666951498718687696944939733521797750934102846216745879078034431826736769529"));

  eval("Quit");
}

TEST_F(REPLTest, test_encryption_128_bits_example_11) {
  eval("P=208600341163562837099246437000928447759");
  eval("Q=202173397818167879001654816451669722881");
  eval("E=84158610486475670028332513381283587447887510313377750701833794212986594069659");
  EXPECT_EQ("No", eval("IsPPrime"));
  EXPECT_EQ("No", eval("IsQPrime"));

  eval("Quit");
}

TEST_F(REPLTest, test_encryption_128_bits_example_12) {
  eval("P=268127044548766856919879654262251516049");
  eval("Q=276459591384893420121080030032445464867");
  eval("E=64569292355744418830136030111551247120922165148935106742182677091101404117829");
  EXPECT_EQ("Yes", eval("IsPPrime"));
  EXPECT_EQ("Yes", eval("IsQPrime"));
  EXPECT_EQ("74126293175191200021757511935582141086116333930115510166992389838285316150483", eval("PrintN"));
  EXPECT_EQ("74126293175191200021757511935582141085571747294181849889951430153990619169568", eval("PrintPhi"));
  EXPECT_EQ("66708984285033178579758174065967543057934015043469528797639471318695562986573", eval("PrintD"));
  EXPECT_EQ("57719596158958444598113819465055826243884263812470896773617462347076848921928", eval("EncryptPublic=61455031528376803715856421803126289953004337787555232440714173121983579870056"));
  EXPECT_EQ("61455031528376803715856421803126289953004337787555232440714173121983579870056", eval("EncryptPrivate=57719596158958444598113819465055826243884263812470896773617462347076848921928"));
  EXPECT_EQ("61455031528376803715856421803126289953004337787555232440714173121983579870056", eval("EncryptPrivate=57719596158958444598113819465055826243884263812470896773617462347076848921928"));
  EXPECT_EQ("57719596158958444598113819465055826243884263812470896773617462347076848921928", eval("EncryptPublic=61455031528376803715856421803126289953004337787555232440714173121983579870056"));

  eval("Quit");
}

TEST_F(REPLTest, test_encryption_128_bits_example_13) {
  eval("P=172524417160794629439456044816699520619");
  eval("Q=183769183093394642311326373257195192677");
  eval("E=76209787516049153565869871700223123763832694430024327574290590934397083342689");
  EXPECT_EQ("No", eval("IsPPrime"));
  EXPECT_EQ("No", eval("IsQPrime"));

  eval("Quit");
}

TEST_F(REPLTest, test_encryption_128_bits_example_14) {
  eval("P=255491003529532804753784132211024285809");
  eval("Q=279977462899255830858018529348596629159");
  eval("E=109420351332241386973553698388952258754456647152720688141536961095710053646721");
  EXPECT_EQ("Yes", eval("IsPPrime"));
  EXPECT_EQ("Yes", eval("IsQPrime"));
  EXPECT_EQ("71531722961783411376404983193613971216352191589854131201418814652702799304631", eval("PrintN"));
  EXPECT_EQ("71531722961783411376404983193613971215816723123425342565807011991143178389664", eval("PrintPhi"));
  EXPECT_EQ("7802305473929704164821981216123680861770197000119817584600113907215131317825", eval("PrintD"));
  EXPECT_EQ("10221456786168193667836741801410254615422683990467158952391300475552823583466", eval("EncryptPublic=59512548481894903059983706228665397623388126051291935584112037550141811043645"));
  EXPECT_EQ("59512548481894903059983706228665397623388126051291935584112037550141811043645", eval("EncryptPrivate=10221456786168193667836741801410254615422683990467158952391300475552823583466"));
  EXPECT_EQ("59512548481894903059983706228665397623388126051291935584112037550141811043645", eval("EncryptPrivate=10221456786168193667836741801410254615422683990467158952391300475552823583466"));
  EXPECT_EQ("10221456786168193667836741801410254615422683990467158952391300475552823583466", eval("EncryptPublic=59512548481894903059983706228665397623388126051291935584112037550141811043645"));

  eval("Quit");
}

TEST_F(REPLTest, test_encryption_128_bits_example_15) {
  eval("P=145843015354654560073764482406947769931");
  eval("Q=129214258518265962069966020351777622671");
  eval("E=96528459836308236374433784534544268207358796733952205639486744809886152909663");
  EXPECT_EQ("No", eval("IsPPrime"));
  EXPECT_EQ("No", eval("IsQPrime"));

  eval("Quit");
}

TEST_F(REPLTest, test_encryption_128_bits_example_16) {
  eval("P=334494855323137598453719864444597345769");
  eval("Q=238092969446782267437472211458974162661");
  eval("E=101423867535318605116481527630839824060485223578913727346123159032865389502649");
  EXPECT_EQ("Yes", eval("IsPPrime"));
  EXPECT_EQ("Yes", eval("IsQPrime"));
  EXPECT_EQ("79640873368557655118816609489842994472279124308637489325417417858629866131309", eval("PrintN"));
  EXPECT_EQ("79640873368557655118816609489842994471706536483867569459526225782726294622880", eval("PrintPhi"));
  EXPECT_EQ("1027513512228415276937217633220317410161802555928644407599250053315115848329", eval("PrintD"));
  EXPECT_EQ("54138746787279187998016300170592273723782123546798994725990649336744796828647", eval("EncryptPublic=17916333271556915198689232743274007928008095236519014331949692750524347950874"));
  EXPECT_EQ("17916333271556915198689232743274007928008095236519014331949692750524347950874", eval("EncryptPrivate=54138746787279187998016300170592273723782123546798994725990649336744796828647"));
  EXPECT_EQ("17916333271556915198689232743274007928008095236519014331949692750524347950874", eval("EncryptPrivate=54138746787279187998016300170592273723782123546798994725990649336744796828647"));
  EXPECT_EQ("54138746787279187998016300170592273723782123546798994725990649336744796828647", eval("EncryptPublic=17916333271556915198689232743274007928008095236519014331949692750524347950874"));

  eval("Quit");
}

TEST_F(REPLTest, test_encryption_128_bits_example_17) {
  eval("P=257815520743150165536286082235802176347");
  eval("Q=227938395320503552857705022447321928119");
  eval("E=80033795900590927458931364493049058238709678930188068605374389744841820534423");
  EXPECT_EQ("No", eval("IsPPrime"));
  EXPECT_EQ("No", eval("IsQPrime"));

  eval("Quit");
}

TEST_F(REPLTest, test_encryption_128_bits_example_18) {
  eval("P=229427034859334419297722898529611396567");
  eval("Q=333495825977447427706558923433709582729");
  eval("E=98438559471778366573588934174610242031174166688511746106842109125792854081871");
  EXPECT_EQ("Yes", eval("IsPPrime"));
  EXPECT_EQ("Yes", eval("IsQPrime"));
  EXPECT_EQ("76512958491970356184189472498421921105687751401094218617051583796596513091343", eval("PrintN"));
  EXPECT_EQ("76512958491970356184189472498421921105124828540257436770047301974633192112048", eval("PrintPhi"));
  EXPECT_EQ("17318120659877565027789613078092324568455159154599753890508614690470880760479", eval("PrintD"));
  EXPECT_EQ("71163424912866458129245605058570378035896350389120143805359383184481079617007", eval("EncryptPublic=35777011268570836846354725360832522032712437182811792128102891815216091610670"));
  EXPECT_EQ("35777011268570836846354725360832522032712437182811792128102891815216091610670", eval("EncryptPrivate=71163424912866458129245605058570378035896350389120143805359383184481079617007"));
  EXPECT_EQ("35777011268570836846354725360832522032712437182811792128102891815216091610670", eval("EncryptPrivate=71163424912866458129245605058570378035896350389120143805359383184481079617007"));
  EXPECT_EQ("71163424912866458129245605058570378035896350389120143805359383184481079617007", eval("EncryptPublic=35777011268570836846354725360832522032712437182811792128102891815216091610670"));

  eval("Quit");
}

TEST_F(REPLTest, test_encryption_128_bits_example_19) {
  eval("P=101151712972029816477856456882529378107");
  eval("Q=251918782733684764627602286536711660719");
  eval("E=103536143852572684043759840173161253657945605790938070269103658255150291355491");
  EXPECT_EQ("No", eval("IsPPrime"));
  EXPECT_EQ("No", eval("IsQPrime"));

  eval("Quit");
}

TEST_F(REPLTest, test_encryption_128_bits_example_20) {
  eval("P=207481375392597010851202112591892249773");
  eval("Q=331770806486424764717034920629855380061");
  eval("E=100626088435090661121482395257324948518759805644850519795162089101619479129717");
  EXPECT_EQ("Yes", eval("IsPPrime"));
  EXPECT_EQ("Yes", eval("IsQPrime"));
  EXPECT_EQ("68836263244914555931804870850720294327568185008915478281895479927933255976153", eval("PrintN"));
  EXPECT_EQ("68836263244914555931804870850720294327028932827036456506327242894711508346320", eval("PrintPhi"));
  EXPECT_EQ("14010463925005658669886400595918579421366418166250860635263639916564993156333", eval("PrintD"));
  EXPECT_EQ("66041727102282261918590740390480336812003149046636823494235947543867533159992", eval("EncryptPublic=23249262536259605220061310755303941150524293155329422230716928795028469058032"));
  EXPECT_EQ("23249262536259605220061310755303941150524293155329422230716928795028469058032", eval("EncryptPrivate=66041727102282261918590740390480336812003149046636823494235947543867533159992"));
  EXPECT_EQ("23249262536259605220061310755303941150524293155329422230716928795028469058032", eval("EncryptPrivate=66041727102282261918590740390480336812003149046636823494235947543867533159992"));
  EXPECT_EQ("66041727102282261918590740390480336812003149046636823494235947543867533159992", eval("EncryptPublic=23249262536259605220061310755303941150524293155329422230716928795028469058032"));

  eval("Quit");
}

TEST_F(REPLTest, test_encryption_256_bits_example_01) {
  eval("P=46698848908490221146561138607471654800604351289440369265187906237418105865791");
  eval("Q=68346945040007196372129072089896852701503594246133320691981417719409751126409");
  eval("E=10580602721607417007387928567828414109523285235192147467736465758457900644912542558944003103747748920614040250927297682542325978075711087296639486735138759");
  EXPECT_EQ("No", eval("IsPPrime"));
  EXPECT_EQ("No", eval("IsQPrime"));

  eval("Quit");
}

TEST_F(REPLTest, test_encryption_256_bits_example_02) {
  eval("P=85897818512081580124183307023854926435639894825348037354151179094986362184143");
  eval("Q=113455360866477522011802137044270142685509260110210114344306675225881741094789");
  eval("E=8390860463518315099288213590793365405538205218893699600777652813671201572704542697915274633093754651598697114351557096242908751354516483599333536383682067");
  EXPECT_EQ("Yes", eval("IsPPrime"));
  EXPECT_EQ("Yes", eval("IsQPrime"));
  EXPECT_EQ("9745567996931408952926014238112225056029971326806271452513478941047156981915169426517383077525367140414008403840680989552569580210974031170445718035730827", eval("PrintN"));
  EXPECT_EQ("9745567996931408952926014238112225056029971326806271452513478941047156981914970073338004518423231154969940278771559840397634022059275573316124849932451896", eval("PrintPhi"));
  EXPECT_EQ("2504003952347625569768062539603373191472848062747490074409258263116425241435044923328663754022362543617953672373082102413471362012416118827495343746798099", eval("PrintD"));
  EXPECT_EQ("5185765174795354603933971189181797792245339923617006958376252835908282271199203472903610988894226176916667800182606190733620597652170148478947988915849698", eval("EncryptPublic=9649456607021364866616603335816529714846337026723423029260937094799144105133616626260155568967228726427656423452466278553830576426965181609680135427530306"));
  EXPECT_EQ("9649456607021364866616603335816529714846337026723423029260937094799144105133616626260155568967228726427656423452466278553830576426965181609680135427530306", eval("EncryptPrivate=5185765174795354603933971189181797792245339923617006958376252835908282271199203472903610988894226176916667800182606190733620597652170148478947988915849698"));
  EXPECT_EQ("9649456607021364866616603335816529714846337026723423029260937094799144105133616626260155568967228726427656423452466278553830576426965181609680135427530306", eval("EncryptPrivate=5185765174795354603933971189181797792245339923617006958376252835908282271199203472903610988894226176916667800182606190733620597652170148478947988915849698"));
  EXPECT_EQ("5185765174795354603933971189181797792245339923617006958376252835908282271199203472903610988894226176916667800182606190733620597652170148478947988915849698", eval("EncryptPublic=9649456607021364866616603335816529714846337026723423029260937094799144105133616626260155568967228726427656423452466278553830576426965181609680135427530306"));

  eval("Quit");
}

TEST_F(REPLTest, test_encryption_256_bits_example_03) {
  eval("P=57671124321951469531465139572171153862341117436965266916883496972353054612057");
  eval("Q=72707498790104075113482410494703114077160119713972985192771995803089198435921");
  eval("E=11584680455685444456187324250247261485833885620108338207696879519877893616366727450251406530377424668353408698791879955646093542332013849279142743595700479");
  EXPECT_EQ("No", eval("IsPPrime"));
  EXPECT_EQ("No", eval("IsQPrime"));

  eval("Quit");
}

TEST_F(REPLTest, test_encryption_256_bits_example_04) {
  eval("P=106609620732279425420896178303042410505935681153806346492933727757431245978343");
  eval("Q=94226587354868707943033988365778194475062514575822033273083134855852155390131");
  eval("E=6757142970021655553933504069126308798032100974826762320412761968633709308982613954760937090342311489772223367095077608931410799227112705753507560981012123");
  EXPECT_EQ("Yes", eval("IsPPrime"));
  EXPECT_EQ("Yes", eval("IsQPrime"));
  EXPECT_EQ("10045460740799549351292974061979917104010038654989609326378375285281720449868128687931157714058546662062559590068098604446303609625379845596349303941932933", eval("PrintN"));
  EXPECT_EQ("10045460740799549351292974061979917104010038654989609326378375285281720449867927851723070565925182731895890769463117606250573981245613828733736020540564460", eval("PrintPhi"));
  EXPECT_EQ("575238339433812846949223940538346136091289716608782982133318610249967354135675536846725235135394898895489228481220685819911487834099381333322004673147447", eval("PrintD"));
  EXPECT_EQ("4125623783185844990159251438809234954590085504689867666745161473627952973509806665610001506161617748096485550648376861177035961085865355336119984717015732", eval("EncryptPublic=904068414094187242099124302094977188725356627739904410740574101551266861896530264312675892011801048641804878267796078204800653523491214768297033798758593"));
  EXPECT_EQ("904068414094187242099124302094977188725356627739904410740574101551266861896530264312675892011801048641804878267796078204800653523491214768297033798758593", eval("EncryptPrivate=4125623783185844990159251438809234954590085504689867666745161473627952973509806665610001506161617748096485550648376861177035961085865355336119984717015732"));
  EXPECT_EQ("904068414094187242099124302094977188725356627739904410740574101551266861896530264312675892011801048641804878267796078204800653523491214768297033798758593", eval("EncryptPrivate=4125623783185844990159251438809234954590085504689867666745161473627952973509806665610001506161617748096485550648376861177035961085865355336119984717015732"));
  EXPECT_EQ("4125623783185844990159251438809234954590085504689867666745161473627952973509806665610001506161617748096485550648376861177035961085865355336119984717015732", eval("EncryptPublic=904068414094187242099124302094977188725356627739904410740574101551266861896530264312675892011801048641804878267796078204800653523491214768297033798758593"));

  eval("Quit");
}

TEST_F(REPLTest, test_encryption_256_bits_example_05) {
  eval("P=55251365777271081495634829067201602462898091849681653894996663986597121252517");
  eval("Q=92885431077617621746556586110794396038668130775346551592212707338346150298807");
  eval("E=11054083994673239008242765656004844578743565263861652201362766610055858729681405200278863456903855370210498711228860574855253120374065825925377821141903657");
  EXPECT_EQ("No", eval("IsPPrime"));
  EXPECT_EQ("No", eval("IsQPrime"));

  eval("Quit");
}

TEST_F(REPLTest, test_encryption_256_bits_example_06) {
  eval("P=61615886095201862665166338164444460289029893752328225519722072480333636738441");
  eval("Q=83072944171885174343468564441414667378733385408587354640189098923976922040877");
  eval("E=8793860205670271863035585337127193106072567316394921094652467548013287593311743428227135042835146183882633925203780897336638801293564570905212831456135269");
  EXPECT_EQ("Yes", eval("IsPPrime"));
  EXPECT_EQ("Yes", eval("IsQPrime"));
  EXPECT_EQ("5118613065687940329680126634250884140728529480519078029668766411949086286508600221418627777822349592128430589502251133165783618165464079647432327559252757", eval("PrintN"));
  EXPECT_EQ("5118613065687940329680126634250884140728529480519078029668766411949086286508455532588360690785340957225824730374583369886622702585304168476028017000473440", eval("PrintPhi"));
  EXPECT_EQ("1814407642889076449113811884171883655192797382758174357176209231530589448946455405618034934499241947660152118280763673797996034042228618116073986516915629", eval("PrintD"));
  EXPECT_EQ("2358124772269682296207626003119766146373691314181391188498172661327004619202125135694609601477614560496068855840302258821650819496766495515384008886348621", eval("EncryptPublic=2664006229876029403562215063138943778386090706116765445698619310511438448646201475923128518653770706458406565875678635590575410968317750489606082877760480"));
  EXPECT_EQ("2664006229876029403562215063138943778386090706116765445698619310511438448646201475923128518653770706458406565875678635590575410968317750489606082877760480", eval("EncryptPrivate=2358124772269682296207626003119766146373691314181391188498172661327004619202125135694609601477614560496068855840302258821650819496766495515384008886348621"));
  EXPECT_EQ("2664006229876029403562215063138943778386090706116765445698619310511438448646201475923128518653770706458406565875678635590575410968317750489606082877760480", eval("EncryptPrivate=2358124772269682296207626003119766146373691314181391188498172661327004619202125135694609601477614560496068855840302258821650819496766495515384008886348621"));
  EXPECT_EQ("2358124772269682296207626003119766146373691314181391188498172661327004619202125135694609601477614560496068855840302258821650819496766495515384008886348621", eval("EncryptPublic=2664006229876029403562215063138943778386090706116765445698619310511438448646201475923128518653770706458406565875678635590575410968317750489606082877760480"));

  eval("Quit");
}

TEST_F(REPLTest, test_encryption_256_bits_example_07) {
  eval("P=83643616962455082725832636336533085055085979019283037554972546828552595098347");
  eval("Q=81423371497940833028024678356789619820441157335671794977700233158626335008249");
  eval("E=10781625560244401766294119991741580431398844567686145508743674172665430632462319606441710629031383487939441032693707516420372020939323324465651027198566773");
  EXPECT_EQ("No", eval("IsPPrime"));
  EXPECT_EQ("No", eval("IsQPrime"));

  eval("Quit");
}

TEST_F(REPLTest, test_encryption_256_bits_example_08) {
  eval("P=89382528700321074005583194581864620567320354363477926194712402830956574417791");
  eval("Q=108663546413314839540595075421342778533824644205259758140365957131771752123787");
  eval("E=8281094377071171613798818298071444478627819709113823994037220271045542233534279762871322612528351018806393396257651479641134931480512384307858818895969141");
  EXPECT_EQ("Yes", eval("IsPPrime"));
  EXPECT_EQ("Yes", eval("IsQPrime"));
  EXPECT_EQ("9712622555966784747480932516298506653600014281484210428612365077526573546600047318269171917612600587054324550714839831641288855202723397173321517287094517", eval("PrintN"));
  EXPECT_EQ("9712622555966784747480932516298506653600014281484210428612365077526573546599849272194058281699054408784321343315738686642720117518388318813358788960552940", eval("PrintPhi"));
  EXPECT_EQ("1262383563721823017923408387625652918350556368916890053668146471571925045029561031132282014671283979392248655216792189343226060205163388343860246440539561", eval("PrintD"));
  EXPECT_EQ("7223222563650173596149480833272339890439867447691192797908344515178276243732858939941737443682760660328375752521120966049852616333288251013801051874195934", eval("EncryptPublic=967424846228450039971359287205271449834298171148094431321728904965963727738296487996004206407182122360944758407407600362386220192337711055840139414151609"));
  EXPECT_EQ("967424846228450039971359287205271449834298171148094431321728904965963727738296487996004206407182122360944758407407600362386220192337711055840139414151609", eval("EncryptPrivate=7223222563650173596149480833272339890439867447691192797908344515178276243732858939941737443682760660328375752521120966049852616333288251013801051874195934"));
  EXPECT_EQ("967424846228450039971359287205271449834298171148094431321728904965963727738296487996004206407182122360944758407407600362386220192337711055840139414151609", eval("EncryptPrivate=7223222563650173596149480833272339890439867447691192797908344515178276243732858939941737443682760660328375752521120966049852616333288251013801051874195934"));
  EXPECT_EQ("7223222563650173596149480833272339890439867447691192797908344515178276243732858939941737443682760660328375752521120966049852616333288251013801051874195934", eval("EncryptPublic=967424846228450039971359287205271449834298171148094431321728904965963727738296487996004206407182122360944758407407600362386220192337711055840139414151609"));

  eval("Quit");
}

TEST_F(REPLTest, test_encryption_256_bits_example_09) {
  eval("P=74124479174549406133376248023791335030829102760405248241891721129681911973139");
  eval("Q=45966810525203545852284973773927133767257359099258541877281825678344183977463");
  eval("E=11257588591478282129263803054950740896390473666052139222808002769520177182281377291306852254968194136427168932224555578500243665739534179801773988381742523");
  EXPECT_EQ("No", eval("IsPPrime"));
  EXPECT_EQ("No", eval("IsQPrime"));

  eval("Quit");
}

TEST_F(REPLTest, test_encryption_256_bits_example_10) {
  eval("P=72085181527116833835504548216121920794261714692960039766913342450485791249103");
  eval("Q=91500726463623992328262943813617116541102308713514709863017530913376918986029");
  eval("E=12931005740141065001201839474994810935442457895281719630108423464235436239511959212877990301815109507936456749664367990650377298038025353338235412797599277");
  EXPECT_EQ("Yes", eval("IsPPrime"));
  EXPECT_EQ("Yes", eval("IsQPrime"));
  EXPECT_EQ("6595846476993398630079487384724794354423800381713869034385661489223406695614693580403521936743753212252499578659122703570310571756561532597122664115781987", eval("PrintN"));
  EXPECT_EQ("6595846476993398630079487384724794354423800381713869034385661489223406695614529994495531195917589444760469839621787339546904097006931601723758801405546856", eval("PrintPhi"));
  EXPECT_EQ("3771661356547097945149423011326863278978629748496476087897938210737953941714233763295556178949118337977645891315462792946822498222791416418909634113191245", eval("PrintD"));
  EXPECT_EQ("4880179673212721041128380483216528677137212449314983987987768969425314207521903770544567674188792288412451079309849935388137608284649101515359755751643145", eval("EncryptPublic=4051401861142837475387723741212121577950249135793785011690995133880977220435813671550741543598372181727524835923241727308478974348251257110168651004739796"));
  EXPECT_EQ("4051401861142837475387723741212121577950249135793785011690995133880977220435813671550741543598372181727524835923241727308478974348251257110168651004739796", eval("EncryptPrivate=4880179673212721041128380483216528677137212449314983987987768969425314207521903770544567674188792288412451079309849935388137608284649101515359755751643145"));
  EXPECT_EQ("4051401861142837475387723741212121577950249135793785011690995133880977220435813671550741543598372181727524835923241727308478974348251257110168651004739796", eval("EncryptPrivate=4880179673212721041128380483216528677137212449314983987987768969425314207521903770544567674188792288412451079309849935388137608284649101515359755751643145"));
  EXPECT_EQ("4880179673212721041128380483216528677137212449314983987987768969425314207521903770544567674188792288412451079309849935388137608284649101515359755751643145", eval("EncryptPublic=4051401861142837475387723741212121577950249135793785011690995133880977220435813671550741543598372181727524835923241727308478974348251257110168651004739796"));

  eval("Quit");
}

TEST_F(REPLTest, test_encryption_256_bits_example_11) {
  eval("P=55647834720297437037655082977554543067725531793551616186939402590772787863739");
  eval("Q=61280760561204873750332118978451261229901975454030085202685872004612126348777");
  eval("E=13276113879124773491633929870161719449181930237179466742272932019651452971005770024498196429773431363867527735794581511054091491284998256238829192165079323");
  EXPECT_EQ("No", eval("IsPPrime"));
  EXPECT_EQ("No", eval("IsQPrime"));

  eval("Quit");
}

TEST_F(REPLTest, test_encryption_256_bits_example_12) {
  eval("P=114550814762027617217447077577183749388438770077466051044780972832584729828469");
  eval("Q=86917547051344878866285586752807460761172533058931245561581734539395667770683");
  eval("E=12961506505369727276701603102746464322855323932625345505273879748740173128993482015511264221832815707328343964686573783148915055365983015300004875572364373");
  EXPECT_EQ("Yes", eval("IsPPrime"));
  EXPECT_EQ("Yes", eval("IsQPrime"));
  EXPECT_EQ("9956475831848426942786092403123287253288163077395974924009083429822574651905896832621129727633535823560356077117008225054587220183997750622729182216974327", eval("PrintN"));
  EXPECT_EQ("9956475831848426942786092403123287253288163077395974924009083429822574651905695364259316355137452090896026085906858613751450822887391387915357201819375176", eval("PrintPhi"));
  EXPECT_EQ("8510876128283594274320813011550201700046131412608661799631752984862867023536239662654489491795558777986095795319336953508845858076793333028561684071069085", eval("PrintD"));
  EXPECT_EQ("27512478876221629059831745691136967682502523635851672541753741288577881491729886981215740848235107502664007727493374592084714568887249608591699079877546", eval("EncryptPublic=7265962670827192575459779512979791280781063155016274422925497534210153490583174486620450224372025795315619287346954531940154611631239365927190894498239060"));
  EXPECT_EQ("7265962670827192575459779512979791280781063155016274422925497534210153490583174486620450224372025795315619287346954531940154611631239365927190894498239060", eval("EncryptPrivate=27512478876221629059831745691136967682502523635851672541753741288577881491729886981215740848235107502664007727493374592084714568887249608591699079877546"));
  EXPECT_EQ("7265962670827192575459779512979791280781063155016274422925497534210153490583174486620450224372025795315619287346954531940154611631239365927190894498239060", eval("EncryptPrivate=27512478876221629059831745691136967682502523635851672541753741288577881491729886981215740848235107502664007727493374592084714568887249608591699079877546"));
  EXPECT_EQ("27512478876221629059831745691136967682502523635851672541753741288577881491729886981215740848235107502664007727493374592084714568887249608591699079877546", eval("EncryptPublic=7265962670827192575459779512979791280781063155016274422925497534210153490583174486620450224372025795315619287346954531940154611631239365927190894498239060"));

  eval("Quit");
}

TEST_F(REPLTest, test_encryption_256_bits_example_13) {
  eval("P=35577806295103750867728313502137441374475253474697997546309273457165108988337");
  eval("Q=50216617759469763972679901083622199993798333006643145138466381726587683331677");
  eval("E=13104149155190283271021636653316708501796097347395274814582626917091043147713190145661316502834050895577957349720390337790110722722176003959940174060896973");
  EXPECT_EQ("No", eval("IsPPrime"));
  EXPECT_EQ("No", eval("IsQPrime"));

  eval("Quit");
}

TEST_F(REPLTest, test_encryption_256_bits_example_14) {
  eval("P=98686981016614681123595911363373421242057662127196422996975813821348211127799");
  eval("Q=69039516223646560568425651963276211917733594705938621834071645305179412251963");
  eval("E=8736833025342354704621897784208328627990599342412247754405468325607701423532772529748672853675573476732276786591871372858855600367235229121217750147280081");
  EXPECT_EQ("Yes", eval("IsPPrime"));
  EXPECT_EQ("Yes", eval("IsQPrime"));
  EXPECT_EQ("6813301426959269420514785703552024709418448789999338048404083310545384641532131124883546011494153776135862494458561464442068366157154256456914994581619437", eval("PrintN"));
  EXPECT_EQ("6813301426959269420514785703552024709418448789999338048404083310545384641531963398386305750252461754572535844825401673185235231112323208997788466958239676", eval("PrintPhi"));
  EXPECT_EQ("3545081284317293261058027427303306801165811312524964405730429004752513160215921442790009101159111546700772862757693871941249775848173621068273983837897437", eval("PrintD"));
  EXPECT_EQ("5119544113903246649324196777543997852329941830229428580990636760067347771212866847661759980337194925763273637878348814276980008523321434164963083899785579", eval("EncryptPublic=1117168302601956023770329772931302150946367797026076432048717992392350413478580761592962671611265741477355453367270737122827368589503136701363591363947307"));
  EXPECT_EQ("1117168302601956023770329772931302150946367797026076432048717992392350413478580761592962671611265741477355453367270737122827368589503136701363591363947307", eval("EncryptPrivate=5119544113903246649324196777543997852329941830229428580990636760067347771212866847661759980337194925763273637878348814276980008523321434164963083899785579"));
  EXPECT_EQ("1117168302601956023770329772931302150946367797026076432048717992392350413478580761592962671611265741477355453367270737122827368589503136701363591363947307", eval("EncryptPrivate=5119544113903246649324196777543997852329941830229428580990636760067347771212866847661759980337194925763273637878348814276980008523321434164963083899785579"));
  EXPECT_EQ("5119544113903246649324196777543997852329941830229428580990636760067347771212866847661759980337194925763273637878348814276980008523321434164963083899785579", eval("EncryptPublic=1117168302601956023770329772931302150946367797026076432048717992392350413478580761592962671611265741477355453367270737122827368589503136701363591363947307"));

  eval("Quit");
}

TEST_F(REPLTest, test_encryption_256_bits_example_15) {
  eval("P=53198158543972842551373932323250409965177627123423209876593250155973514346367");
  eval("Q=39429036498238118736206478705522851794322184375555683576137868451023562536477");
  eval("E=10984987545930646313158149001043271827957699868070577513523222758645475347649599198587061350968596738515324243891799414270184081961963630379201396946724501");
  EXPECT_EQ("No", eval("IsPPrime"));
  EXPECT_EQ("No", eval("IsQPrime"));

  eval("Quit");
}

TEST_F(REPLTest, test_encryption_256_bits_example_16) {
  eval("P=75351942201985297759977335286935142359224587105510877119738605381871156130117");
  eval("Q=79440041906765743186649810940122842484462530258360822545633181994040194802601");
  eval("E=13128274370814264135444906672978994612867289369926765555412438327845167103001286886944893940688107226446166128370014810292240050130804309671665483938733779");
  EXPECT_EQ("Yes", eval("IsPPrime"));
  EXPECT_EQ("Yes", eval("IsQPrime"));
  EXPECT_EQ("5985961446281902206790488038638578107324044469037335287465243191930620584398777259506874223792128561813031738460383551576705737861361152857963703886034317", eval("PrintN"));
  EXPECT_EQ("5985961446281902206790488038638578107324044469037335287465243191930620584398622467522765472751181934666804680475539864459341866161695781070587792535101600", eval("PrintPhi"));
  EXPECT_EQ("2769610648712891372625006626027888115062996085341252856082653229318274691873241639433176508318477311588695176253301995633196963974557373176256929539701019", eval("PrintD"));
  EXPECT_EQ("2275260791634429035895835014345202759886104544795606247172718130370760761159916124827383724729874194261308166854647522916138301969550193672140514183845018", eval("EncryptPublic=3643951445993887321667899896838034410094986465340921308124799684426348422282643407662955092800705447501639524150547998446129223629522718861326075691692820"));
  EXPECT_EQ("3643951445993887321667899896838034410094986465340921308124799684426348422282643407662955092800705447501639524150547998446129223629522718861326075691692820", eval("EncryptPrivate=2275260791634429035895835014345202759886104544795606247172718130370760761159916124827383724729874194261308166854647522916138301969550193672140514183845018"));
  EXPECT_EQ("3643951445993887321667899896838034410094986465340921308124799684426348422282643407662955092800705447501639524150547998446129223629522718861326075691692820", eval("EncryptPrivate=2275260791634429035895835014345202759886104544795606247172718130370760761159916124827383724729874194261308166854647522916138301969550193672140514183845018"));
  EXPECT_EQ("2275260791634429035895835014345202759886104544795606247172718130370760761159916124827383724729874194261308166854647522916138301969550193672140514183845018", eval("EncryptPublic=3643951445993887321667899896838034410094986465340921308124799684426348422282643407662955092800705447501639524150547998446129223629522718861326075691692820"));

  eval("Quit");
}

TEST_F(REPLTest, test_encryption_256_bits_example_17) {
  eval("P=58728383212494658198945785920439928317364656978703337877915241888429167137177");
  eval("Q=84790582375971551849358424189320871267077282660094607115342620705249510088773");
  eval("E=8476734629070190549352151983296800744550967769849650516493234015606615840607404043103520037177646230960158383006137425728810700227012173143558448831894243");
  EXPECT_EQ("No", eval("IsPPrime"));
  EXPECT_EQ("No", eval("IsQPrime"));

  eval("Quit");
}

TEST_F(REPLTest, test_encryption_256_bits_example_18) {
  eval("P=103321026916384511597438356690474931261554739435848001311632135328290488045341");
  eval("Q=115172113321438340406302060066745847350373496719024340599786058231799689698439");
  eval("E=11717727759342650533278191858622218032756962296513153473679803336811983387535491879209561800866652519732227352456708126418092647534871371776869752134001987");
  EXPECT_EQ("Yes", eval("IsPPrime"));
  EXPECT_EQ("Yes", eval("IsQPrime"));
  EXPECT_EQ("11899701020501217942227483221219742738615097658220470876094059875604646335221802404428022353289802448131139243011384984035253543149888652902141878848922699", eval("PrintN"));
  EXPECT_EQ("11899701020501217942227483221219742738615097658220470876094059875604646335221583911287784530437798707714382022232773055799098670807977234708581788671178920", eval("PrintPhi"));
  EXPECT_EQ("10727443666398218486675305238998634342153755154231401705661628914659887622952260848435436951832341308913104165140533944496074697345017083063442218050057483", eval("PrintD"));
  EXPECT_EQ("1523676956400383739592196923392385962240766604089848788328201648176812567968187907259698291481982120114025109822747836832581071344378155552151874826733401", eval("EncryptPublic=832499445916618856725141077120576025469832586163497833974595224028504453531437201724719833355305571751100417973789552549021705461341419791939439529035035"));
  EXPECT_EQ("832499445916618856725141077120576025469832586163497833974595224028504453531437201724719833355305571751100417973789552549021705461341419791939439529035035", eval("EncryptPrivate=1523676956400383739592196923392385962240766604089848788328201648176812567968187907259698291481982120114025109822747836832581071344378155552151874826733401"));
  EXPECT_EQ("832499445916618856725141077120576025469832586163497833974595224028504453531437201724719833355305571751100417973789552549021705461341419791939439529035035", eval("EncryptPrivate=1523676956400383739592196923392385962240766604089848788328201648176812567968187907259698291481982120114025109822747836832581071344378155552151874826733401"));
  EXPECT_EQ("1523676956400383739592196923392385962240766604089848788328201648176812567968187907259698291481982120114025109822747836832581071344378155552151874826733401", eval("EncryptPublic=832499445916618856725141077120576025469832586163497833974595224028504453531437201724719833355305571751100417973789552549021705461341419791939439529035035"));

  eval("Quit");
}

TEST_F(REPLTest, test_encryption_256_bits_example_19) {
  eval("P=81160317625304649107623141288719449371445379085894256118551439489198102271031");
  eval("Q=90533728435031839153127114774907324563815976710171986875496115635760361701237");
  eval("E=7315699804629139785485620423386940748975425293389688198512609560781417755239246214642884499859290070160334251332911097214322506571873769096564172149348539");
  EXPECT_EQ("No", eval("IsPPrime"));
  EXPECT_EQ("No", eval("IsQPrime"));

  eval("Quit");
}

TEST_F(REPLTest, test_encryption_256_bits_example_20) {
  eval("P=72023618348287117816692366243998681966116992179861387357489755008301261650497");
  eval("Q=96847932032385644447079751540284368617699983254705012271194432534465722851949");
  eval("E=7808827608949848386603856884904992496979935363140867089271217361113985886186638934684425111927930776692653249634248673123186255052799744557735188146123621");
  EXPECT_EQ("Yes", eval("IsPPrime"));
  EXPECT_EQ("Yes", eval("IsQPrime"));
  EXPECT_EQ("6975338494521394398406806754499807064700867137084760657320905898720737750570112338329852485396436500259820697928772469734557245094805523815042325713268653", eval("PrintN"));
  EXPECT_EQ("6975338494521394398406806754499807064700867137084760657320905898720737750569943466779471812634172728142036414878188652759122678695176839627499558728766208", eval("PrintPhi"));
  EXPECT_EQ("6817937749251410637729157781161673146315249674514480735227736450037618366563745694428264759990293320985746371335661486007451616881500310607802743041724269", eval("PrintD"));
  EXPECT_EQ("1039789496778787464358809218878517780688550411518850182543572883918290292207279760104005719392734195199681725713633101333879999648254632263575507812817822", eval("EncryptPublic=96723900455950344537483462657969698487963770756689577138974417606901517518141218373087880061352837439886437758568210105277756943147839403387871188754779"));
  EXPECT_EQ("96723900455950344537483462657969698487963770756689577138974417606901517518141218373087880061352837439886437758568210105277756943147839403387871188754779", eval("EncryptPrivate=1039789496778787464358809218878517780688550411518850182543572883918290292207279760104005719392734195199681725713633101333879999648254632263575507812817822"));
  EXPECT_EQ("96723900455950344537483462657969698487963770756689577138974417606901517518141218373087880061352837439886437758568210105277756943147839403387871188754779", eval("EncryptPrivate=1039789496778787464358809218878517780688550411518850182543572883918290292207279760104005719392734195199681725713633101333879999648254632263575507812817822"));
  EXPECT_EQ("1039789496778787464358809218878517780688550411518850182543572883918290292207279760104005719392734195199681725713633101333879999648254632263575507812817822", eval("EncryptPublic=96723900455950344537483462657969698487963770756689577138974417606901517518141218373087880061352837439886437758568210105277756943147839403387871188754779"));

  eval("Quit");
}

TEST_F(REPLTest, test_encryption_512_bits_example_01) {
  eval("P=6639292457378108059622314700371733193999732703640091031063508849277561016160015455832603408300909906561443651243746733721647005878128465433904965096686381");
  eval("Q=7478466008227749559385210769834760190319140139300372437398819971118144706717895373425349722241463195428325083915735044091720412847659848370659887225384721");
  eval("E=100698194385277324284821335427414724425142954859343596056729596220835922716325058892945798186998735675580851712323392463003312305823449586605654820400820246585275593477585259384579459628949306511786757450242100862149448003787774720935842440210216669359064762208263033045596640172138428211017755197265722760271");
  EXPECT_EQ("No", eval("IsPPrime"));
  EXPECT_EQ("No", eval("IsQPrime"));

  eval("Quit");
}

TEST_F(REPLTest, test_encryption_512_bits_example_02) {
  eval("P=10872694113622967968818397116484883992552882331069176098543158179352817068654412875756497489656167186682462354562317397721555078259400876865554760859416903");
  eval("Q=11716532685517131017185961805137120903072630577851685269189315286051124842045322872170162542656762840442925538973441250148437042372055012935463964585716047");
  eval("E=124672789921544850254610281248007094704932149085196015623775431784729678592168595514660753069389882928021004632036270109867073030987418836737892445838231734125101870789413767037935417976248113660854088488136566945325769804769639857195052213732347746036187205100617816975200520963562382362092068497474079320107");
  EXPECT_EQ("Yes", eval("IsPPrime"));
  EXPECT_EQ("Yes", eval("IsQPrime"));
  EXPECT_EQ("127390275961893215339898475448951453444967946817816717095846430886005243949844014315297960706829733768859526239895485367039452865923719642644782126186256605712855395888011240794048567846860477136819343485395339609988840902434285822093276444519828755912537075925634179127883532928085997316503801591483150142441", eval("PrintN"));
  EXPECT_EQ("127390275961893215339898475448951453444967946817816717095846430886005243949844014315297960706829733768859526239895485367039452865923719642644782126186256583123628596747912254789689646224855581511306434564533971877515375498492375122357528517859796442982509950537740643369235662935965365860614000572757705009492", eval("PrintPhi"));
  EXPECT_EQ("123213614614758352414785571555809760959853938764980176701444554123233897021313938864423614057300382479429468382678140942147963494216169788695883278180925116956005312260225302103215154427676196627533435655486152817480636743653914004337330154706844874725721138662793194359406863222070675468774345198454340784703", eval("PrintD"));
  EXPECT_EQ("101580890053369027800782073874339887407444167462903813929687770665826985315580651132366785453265271120698441792793032394776981457288188016470523830632205998001139494708922497833706709044964500060301955857980502765356536556556461369791358956015504354668213194513633635790119774441695084624368208381625929713479", eval("EncryptPublic=95692674215196266940326646924014144755957815860121262948088839708646051459589171043719176891891993674223533925998458188828347205578874599599117010826916645663176471799738515315002621347044366904504856806495700015351134241705818258568900152935884300720181898643229315906137278446794415182569564536037238405247"));
  EXPECT_EQ("95692674215196266940326646924014144755957815860121262948088839708646051459589171043719176891891993674223533925998458188828347205578874599599117010826916645663176471799738515315002621347044366904504856806495700015351134241705818258568900152935884300720181898643229315906137278446794415182569564536037238405247", eval("EncryptPrivate=101580890053369027800782073874339887407444167462903813929687770665826985315580651132366785453265271120698441792793032394776981457288188016470523830632205998001139494708922497833706709044964500060301955857980502765356536556556461369791358956015504354668213194513633635790119774441695084624368208381625929713479"));
  EXPECT_EQ("95692674215196266940326646924014144755957815860121262948088839708646051459589171043719176891891993674223533925998458188828347205578874599599117010826916645663176471799738515315002621347044366904504856806495700015351134241705818258568900152935884300720181898643229315906137278446794415182569564536037238405247", eval("EncryptPrivate=101580890053369027800782073874339887407444167462903813929687770665826985315580651132366785453265271120698441792793032394776981457288188016470523830632205998001139494708922497833706709044964500060301955857980502765356536556556461369791358956015504354668213194513633635790119774441695084624368208381625929713479"));
  EXPECT_EQ("101580890053369027800782073874339887407444167462903813929687770665826985315580651132366785453265271120698441792793032394776981457288188016470523830632205998001139494708922497833706709044964500060301955857980502765356536556556461369791358956015504354668213194513633635790119774441695084624368208381625929713479", eval("EncryptPublic=95692674215196266940326646924014144755957815860121262948088839708646051459589171043719176891891993674223533925998458188828347205578874599599117010826916645663176471799738515315002621347044366904504856806495700015351134241705818258568900152935884300720181898643229315906137278446794415182569564536037238405247"));

  eval("Quit");
}

TEST_F(REPLTest, test_encryption_512_bits_example_03) {
  eval("P=6458453385810026854926472062192916913304236284775586796554387330431901002369258164961270767983660991950529069748294007967353726148411214747180527389257353");
  eval("Q=6730079657391556357459924483588526593899372125854706530561907231930264947168607871739379543772368688608924124066476719677662652107669748106310314631787863");
  eval("E=164383575725466259484585909366235176428591509422928766154055725665420267069101380379867019993896097052345316786587757269600727342132332666791313866661424435495636263643720209214805032757176955319295957991611708073447434910546060030712552008506800866469205965172547871334925418758059939603226516589315653280053");
  EXPECT_EQ("No", eval("IsPPrime"));
  EXPECT_EQ("No", eval("IsQPrime"));

  eval("Quit");
}

TEST_F(REPLTest, test_encryption_512_bits_example_04) {
  eval("P=12632957254240727301794761872645024927588775372013398061528215686239035355782119553003866283542399702824203216656219364524607899650127333035727684002559341");
  eval("Q=9864096033959314890930992894749323525888789133595233549866012883331221896850972789451935874514565331522509525000306340325007165979500326140550288098314351");
  eval("E=125407431805874951941267902230059566901362464166981041963701442759612924922225877211649260119469825509582754671941591477696068616185050037399809174868895560351387988677295625882084353730948994801136542181738265503364374030066717270647551040529161017938922081856815347407616806910378328184370389329230848642911");
  EXPECT_EQ("Yes", eval("IsPPrime"));
  EXPECT_EQ("Yes", eval("IsQPrime"));
  EXPECT_EQ("124612703548733514615156343156548720949359942362804020621390992783743572378374596241116968272738663652687568992225947832190490878880171098141306328507380256562996753462092978315667213178662814968187620228744750895359796537941128748993100201902153272107500010147296287985185368828960434746301180084911949402691", eval("PrintN"));
  EXPECT_EQ("124612703548733514615156343156548720949359942362804020621390992783743572378374596241116968272738663652687568992225947832190490878880171098141306328507380234065943465262050785589912445784314361490623114620113139501131226967683876115900757746099995215142465663434554631459480519213894805118642003806939848529000", eval("PrintPhi"));
  EXPECT_EQ("68638482079230539514487196644475120411858044552982989269189462912155093117949413876937289176871300271017353294213833609811656033760752381807182682829237201732752037231862885583646730133047284410181430707607626444279639617826446114506106706160038735990117256078688094174109699972336693364478649021613571950191", eval("PrintD"));
  EXPECT_EQ("86988875527583731714781871957416080248853252173723754325346510478172216090934065427923871114841383927712983579323895571384876598333255668232818999773447112236873513328236954054517398265296980839437011300075876004448727400960137955254191730400355765297336962061001697493616693938260572577455562416815452766578", eval("EncryptPublic=46488259300226364368679975182353645891901845028267753894754478742838362460671334819131573905266259104062983801798368859590001006420328767916392287513849857508160052054895403249363936251849069778543269069643136125989953588924643522851317475915823109903867502994487823147987542172552557576482774674325471490783"));
  EXPECT_EQ("46488259300226364368679975182353645891901845028267753894754478742838362460671334819131573905266259104062983801798368859590001006420328767916392287513849857508160052054895403249363936251849069778543269069643136125989953588924643522851317475915823109903867502994487823147987542172552557576482774674325471490783", eval("EncryptPrivate=86988875527583731714781871957416080248853252173723754325346510478172216090934065427923871114841383927712983579323895571384876598333255668232818999773447112236873513328236954054517398265296980839437011300075876004448727400960137955254191730400355765297336962061001697493616693938260572577455562416815452766578"));
  EXPECT_EQ("46488259300226364368679975182353645891901845028267753894754478742838362460671334819131573905266259104062983801798368859590001006420328767916392287513849857508160052054895403249363936251849069778543269069643136125989953588924643522851317475915823109903867502994487823147987542172552557576482774674325471490783", eval("EncryptPrivate=86988875527583731714781871957416080248853252173723754325346510478172216090934065427923871114841383927712983579323895571384876598333255668232818999773447112236873513328236954054517398265296980839437011300075876004448727400960137955254191730400355765297336962061001697493616693938260572577455562416815452766578"));
  EXPECT_EQ("86988875527583731714781871957416080248853252173723754325346510478172216090934065427923871114841383927712983579323895571384876598333255668232818999773447112236873513328236954054517398265296980839437011300075876004448727400960137955254191730400355765297336962061001697493616693938260572577455562416815452766578", eval("EncryptPublic=46488259300226364368679975182353645891901845028267753894754478742838362460671334819131573905266259104062983801798368859590001006420328767916392287513849857508160052054895403249363936251849069778543269069643136125989953588924643522851317475915823109903867502994487823147987542172552557576482774674325471490783"));

  eval("Quit");
}

TEST_F(REPLTest, test_encryption_512_bits_example_05) {
  eval("P=6143397223393135005915126185765620080967125848684698320724847004819733670696782652893462704017189713371827609072279469988462438413459104909238287061474257");
  eval("Q=5575114284918951214285051266748202302518372609972412493465246531819425170536484120574882068711774468731982760707324940172722414344462378663128786830667809");
  eval("E=173113459307406516130290490915059653281936108953786429961360431180231580021253339794167354841156997757133937350092086921162215299203618928312179260144533515175454958634423604801683256939723067828061343904938024541775464771653728159866341168885043412652754137946714057144824026604044422088441918265302486328949");
  EXPECT_EQ("No", eval("IsPPrime"));
  EXPECT_EQ("No", eval("IsQPrime"));

  eval("Quit");
}

TEST_F(REPLTest, test_encryption_512_bits_example_06) {
  eval("P=7208854837344753359646537603806365697793692438918044419517200479826766431617703557748058350768960684170813983906678827965033468751686624413996211510136239");
  eval("Q=7938711617070940947799999406934598540135204640963659392997862537689432419290507589219499716019688143006771479271843781749870427000756935972533879571387819");
  eval("E=174046357256199522710153032797388438462656331990355261438744178159852115946517174857810804911716042768779736058255364611686331288565938461859399809568705400950243109253224592829325965304647083005173672446798610032345123236027244243567722121246840027120989519472986144332209604067517156909169842895950722894989");
  EXPECT_EQ("Yes", eval("IsPPrime"));
  EXPECT_EQ("Yes", eval("IsQPrime"));
  EXPECT_EQ("57229019643006841924939594452533110258472980871023383964858214735316151523962646784813887991742984829564900685032254482574897611727636627361310792631440467462357920637401663046350533392077397417968342474796789312958602329282198619259886790938667785141541201446148625738406195254188340710157702180522995072741", eval("PrintN"));
  EXPECT_EQ("57229019643006841924939594452533110258472980871023383964858214735316151523962646784813887991742984829564900685032254482574897611727636627361310792631440452314791466221707355599813522651113159489071262593092976797895584813083347711048739823380600996492714023860685447215796480350292588266597315650431913548684", eval("PrintPhi"));
  EXPECT_EQ("20607981300825055685144833335060509485801486397018842716474117624921935047668092722509607595264156885843601817311463035943944833185496045761175809130017437256346119555919504860490592722452846055817614035995528481528666572041137968644472404319125364094404811555088154982888860865902109228997827633545847395961", eval("PrintD"));
  EXPECT_EQ("53696907700397749312345777629310914956408179380210915257744393288165867923245429612342517482660493179169926461854561958897989593007848030460056153628418251357623526556649252401416333617169354401478170254379792465666453965484498501885220219276020367914383223698015709006881545530918873205879305938885432338499", eval("EncryptPublic=36317691721847801443721955743847448683143286638768524039414915894962955222106148856316021666133060578119031701297478978144186716690330765200929514978760683603034542585914111302217883320976683370395442354940472446479702028806892616368888371856426886658837320372016159853256547582609212857611114507395951110659"));
  EXPECT_EQ("36317691721847801443721955743847448683143286638768524039414915894962955222106148856316021666133060578119031701297478978144186716690330765200929514978760683603034542585914111302217883320976683370395442354940472446479702028806892616368888371856426886658837320372016159853256547582609212857611114507395951110659", eval("EncryptPrivate=53696907700397749312345777629310914956408179380210915257744393288165867923245429612342517482660493179169926461854561958897989593007848030460056153628418251357623526556649252401416333617169354401478170254379792465666453965484498501885220219276020367914383223698015709006881545530918873205879305938885432338499"));
  EXPECT_EQ("36317691721847801443721955743847448683143286638768524039414915894962955222106148856316021666133060578119031701297478978144186716690330765200929514978760683603034542585914111302217883320976683370395442354940472446479702028806892616368888371856426886658837320372016159853256547582609212857611114507395951110659", eval("EncryptPrivate=53696907700397749312345777629310914956408179380210915257744393288165867923245429612342517482660493179169926461854561958897989593007848030460056153628418251357623526556649252401416333617169354401478170254379792465666453965484498501885220219276020367914383223698015709006881545530918873205879305938885432338499"));
  EXPECT_EQ("53696907700397749312345777629310914956408179380210915257744393288165867923245429612342517482660493179169926461854561958897989593007848030460056153628418251357623526556649252401416333617169354401478170254379792465666453965484498501885220219276020367914383223698015709006881545530918873205879305938885432338499", eval("EncryptPublic=36317691721847801443721955743847448683143286638768524039414915894962955222106148856316021666133060578119031701297478978144186716690330765200929514978760683603034542585914111302217883320976683370395442354940472446479702028806892616368888371856426886658837320372016159853256547582609212857611114507395951110659"));

  eval("Quit");
}

TEST_F(REPLTest, test_encryption_512_bits_example_07) {
  eval("P=8688003001390752601565952861101336683683554487780243612738442321959657106017281236069643014909832935760104646481630624641590000086364838684086167301522259");
  eval("Q=12259029162122509579151230269356978579861654193718067978340567174682346507027989930906369941883848663245025868809818836845469408232399795665908593759766811");
  eval("E=91368973525712701029985736284309369368118974214725203933303177111049033594142160353526414593616055500063333764165488797343507516240288176242161435487968590594565394907148323622603398264689995053225892074002131682439410313749063867928052559192137630046904088950626613946113286856650241216486667970803633682307");
  EXPECT_EQ("No", eval("IsPPrime"));
  EXPECT_EQ("No", eval("IsQPrime"));

  eval("Quit");
}

TEST_F(REPLTest, test_encryption_512_bits_example_08) {
  eval("P=12454820696346251965174875675710023033119115257158589314623460850524005595622940267044107031886129612255907401604986440726081895538255943501142455491520067");
  eval("Q=11459262499529384403247154090381676179500303451400899726478934177342661433263560998784784357046540447714235634916107608221960091435125108247169782918488967");
  eval("E=118319666761843635295462957372892986151886229694859498488452062614782827676004544879784632223633986488222807015596375882759643763447547449316917670406600219810469034369782423898020943371241016089579742259022310017473531262792323964879187185797367998613455500003857095998847118624616778661565487082846361741341");
  EXPECT_EQ("Yes", eval("IsPPrime"));
  EXPECT_EQ("Yes", eval("IsQPrime"));
  EXPECT_EQ("142723059744003059285619071565595163101139339191413996508042371044093739706350543845918835183955633092439212457946797535701679945881875997100370445068346346121091503702471231743975463693295255217867928260254539130043452939533140605177033655169805765092969873822886261650673274495267240300651073265137598600789", eval("PrintN"));
  EXPECT_EQ("142723059744003059285619071565595163101139339191413996508042371044093739706350543845918835183955633092439212457946797535701679945881875997100370445068346322207008307826834863321945697601596042598449219700765498027648425072866111718675767826278416832422909903679849740556624326453280266919599324952899188591756", eval("PrintPhi"));
  EXPECT_EQ("108445692009428153186449358688691261400134181949416291391181334722334794961580513886394369939431187394228732249097538965395545450037444489893593717026808771669049591012373937190942704229586198401923256844389999634483499437103756360723246257156581615895615468978553324383764912414023027691346719516882852463661", eval("PrintD"));
  EXPECT_EQ("87691676667594626882563670224029695921743217846166584488748440560712649302621061068084454535710939936617090337358953713824689198639207811814395943133519309988600416428959973020924833940288766641171459503644761869192489138595064230604967713289039245386109906657763869722147259018522540282483340919802496348713", eval("EncryptPublic=125691337468069690792529466352755175964391363592018975312333148676248630588994825066550534236149171627858771518677342260210090323020041083304097373448257489902749132150734661457949246739834648469834346485330899289636671600882996595206980499592301173569952270304827368175365187226706281528631004643320057763698"));
  EXPECT_EQ("125691337468069690792529466352755175964391363592018975312333148676248630588994825066550534236149171627858771518677342260210090323020041083304097373448257489902749132150734661457949246739834648469834346485330899289636671600882996595206980499592301173569952270304827368175365187226706281528631004643320057763698", eval("EncryptPrivate=87691676667594626882563670224029695921743217846166584488748440560712649302621061068084454535710939936617090337358953713824689198639207811814395943133519309988600416428959973020924833940288766641171459503644761869192489138595064230604967713289039245386109906657763869722147259018522540282483340919802496348713"));
  EXPECT_EQ("125691337468069690792529466352755175964391363592018975312333148676248630588994825066550534236149171627858771518677342260210090323020041083304097373448257489902749132150734661457949246739834648469834346485330899289636671600882996595206980499592301173569952270304827368175365187226706281528631004643320057763698", eval("EncryptPrivate=87691676667594626882563670224029695921743217846166584488748440560712649302621061068084454535710939936617090337358953713824689198639207811814395943133519309988600416428959973020924833940288766641171459503644761869192489138595064230604967713289039245386109906657763869722147259018522540282483340919802496348713"));
  EXPECT_EQ("87691676667594626882563670224029695921743217846166584488748440560712649302621061068084454535710939936617090337358953713824689198639207811814395943133519309988600416428959973020924833940288766641171459503644761869192489138595064230604967713289039245386109906657763869722147259018522540282483340919802496348713", eval("EncryptPublic=125691337468069690792529466352755175964391363592018975312333148676248630588994825066550534236149171627858771518677342260210090323020041083304097373448257489902749132150734661457949246739834648469834346485330899289636671600882996595206980499592301173569952270304827368175365187226706281528631004643320057763698"));

  eval("Quit");
}

TEST_F(REPLTest, test_encryption_512_bits_example_09) {
  eval("P=8196526922868287727394298506952531256535193533591000398814829405137354546759064792655939495669372256824636530003218435244820967674467006935281512758909999");
  eval("Q=6135103121570667566327744533780787423455476335109827347308009430717936443043099078500877583164245886577055138776865636617690526018670623952758376763900627");
  eval("E=123991704632523384667699076521589218223772150320416291969565518109652843859072744998876662642623166468562107708728395839364833171519599035791169201078305715172080864519810220199580887464366916886945704096777051699325072566121386139024196786713546532725141740014317923895881462560393252507668366173773458365573");
  EXPECT_EQ("No", eval("IsPPrime"));
  EXPECT_EQ("No", eval("IsQPrime"));

  eval("Quit");
}

TEST_F(REPLTest, test_encryption_512_bits_example_10) {
  eval("P=8935806557360378167712353675597627330291254257754438211388551562752826810083704471218702616598391750502288655809942462153843365960244710045886369786374111");
  eval("Q=8330313249020231797441222095335037598197382659642948802053016540389514481094323420522243075842431707635552148076237134399127726455891403401794431933141047");
  eval("E=97471401184284410231358594032389382560204935827158748541647566863164316760575807334495986387378322444973381794817526930280227713532432872088271730315796143395193356300517531663718417213441024715735941547815451145651707728859403285074777208223152279417389556990262579591578751041878018215426537107574647104511");
  EXPECT_EQ("Yes", eval("IsPPrime"));
  EXPECT_EQ("Yes", eval("IsQPrime"));
  EXPECT_EQ("74438067755461024146387023164484266128531379054184379451420208968982082852449446655113691212848232464381578946408699444574552261525403267509133570036979389094003410235622173325998265663315543915690913693652299500818262221547294314671772698129394659816649076375039820932375688982296694069335627862145272234217", eval("PrintN"));
  EXPECT_EQ("74438067755461024146387023164484266128531379054184379451420208968982082852449446655113691212848232464381578946408699444574552261525403267509133570036979371827883603855012208172422494730650615427053996296265286059250159079206003136643880957183702218993190938534235934752779136011204277933222180181343552719060", eval("PrintPhi"));
  EXPECT_EQ("64846041427052682109629460654662235412818768414524699836361336624673583043649134678893538725651253795045097549177560965698776996045147974391239175407360906762714412247834191852405986480385067999399911211312297762805306140204333683192297924642384968087769545857071202434814520265823914669616302538344548326291", eval("PrintD"));
  EXPECT_EQ("57164360766962560532899539165080967546038658103467112136987754553549628064934182104307887617055428677229402419563120749862385008502396953620755479186335515696384790096193727473473167601998248838674603582850314840468908015581797666147844967455162326273287031129468653346239755483147536646241442049964790768551", eval("EncryptPublic=48687972874809623285045471448633297116598301897612517486242433707799720263691660695543327909707031554204325601972023653170718545654602211415886187000416115719067849976639405097586259887460427093512590394810169214602859278612428561611002591227158235892881860163276896141398309116466403471933118708791509860538"));
  EXPECT_EQ("48687972874809623285045471448633297116598301897612517486242433707799720263691660695543327909707031554204325601972023653170718545654602211415886187000416115719067849976639405097586259887460427093512590394810169214602859278612428561611002591227158235892881860163276896141398309116466403471933118708791509860538", eval("EncryptPrivate=57164360766962560532899539165080967546038658103467112136987754553549628064934182104307887617055428677229402419563120749862385008502396953620755479186335515696384790096193727473473167601998248838674603582850314840468908015581797666147844967455162326273287031129468653346239755483147536646241442049964790768551"));
  EXPECT_EQ("48687972874809623285045471448633297116598301897612517486242433707799720263691660695543327909707031554204325601972023653170718545654602211415886187000416115719067849976639405097586259887460427093512590394810169214602859278612428561611002591227158235892881860163276896141398309116466403471933118708791509860538", eval("EncryptPrivate=57164360766962560532899539165080967546038658103467112136987754553549628064934182104307887617055428677229402419563120749862385008502396953620755479186335515696384790096193727473473167601998248838674603582850314840468908015581797666147844967455162326273287031129468653346239755483147536646241442049964790768551"));
  EXPECT_EQ("57164360766962560532899539165080967546038658103467112136987754553549628064934182104307887617055428677229402419563120749862385008502396953620755479186335515696384790096193727473473167601998248838674603582850314840468908015581797666147844967455162326273287031129468653346239755483147536646241442049964790768551", eval("EncryptPublic=48687972874809623285045471448633297116598301897612517486242433707799720263691660695543327909707031554204325601972023653170718545654602211415886187000416115719067849976639405097586259887460427093512590394810169214602859278612428561611002591227158235892881860163276896141398309116466403471933118708791509860538"));

  eval("Quit");
}

TEST_F(REPLTest, test_encryption_512_bits_example_11) {
  eval("P=5458775621002028752321945123233259390504068620368519429006305719893735086724427405816351650638221980983241815516909615155581218408115017763553742454828829");
  eval("Q=5147845361447695962785469986924985049833885311823852419180484371391535545355311646778561775034863284935933999479224202512640285873236889018518699088043193");
  eval("E=96221022653980970265655390676924431113148427007278274212016812439585024546235479132734454491610379464454699295735435675253556657038302887806585517487249149064126616107187226089855349466275223172125857708768230347304138983843014656382006545874331525954241210251013636537658227586136317798112885346065029119743");
  EXPECT_EQ("No", eval("IsPPrime"));
  EXPECT_EQ("No", eval("IsQPrime"));

  eval("Quit");
}

TEST_F(REPLTest, test_encryption_512_bits_example_12) {
  eval("P=11118262112328603188735583067309503951758420866167761468709800800085617648720698463240508036715214288681528599811481333870194104676024092887397704282439227");
  eval("Q=9316303809220482917996003550479566446107577529894887705963608923273502454481257345242785484412439275200032801515156670386070505488643989803662356581969601");
  eval("E=104399109583160383024059421944683647253405607214659590207453588091609399026086611540351868670510033030866438169570706156371945325261989553891482233799817153762416746582182191866191520193281448880091853395835563966128479400627890527545086665406052665695861836936038946069901362339828882959984795182837493334341");
  EXPECT_EQ("Yes", eval("IsPPrime"));
  EXPECT_EQ("Yes", eval("IsQPrime"));
  EXPECT_EQ("103581107668998738620437479056441090934667652272905092648918246843627342211901639926640781447329186652318897343713416481889218171154571428961650098268640407553830698300958131011451003950775833144423300699808861043900599063086061522520299726891186776701123369770723328089395143219978868038681487205960243938427", eval("PrintN"));
  EXPECT_EQ("103581107668998738620437479056441090934667652272905092648918246843627342211901639926640781447329186652318897343713416481889218171154571428961650098268640387119264776751872024279864386161705435278424904637159686370490875703965958320564491243597665649047559488209322001451390886955368703370598796145899379529600", eval("PrintPhi"));
  EXPECT_EQ("80457262167620862934251109608027043317548392309872544604589966753873376076033731872438449131378714721703711132506922727224122788739276362070674488407227454606501580867191964554268577170124028828468624200432999012008450031285259597728188001319714360739417824040496561644893468806492752641869366789802185282061", eval("PrintD"));
  EXPECT_EQ("86422734220668919222227612974582265611384408354652144064917040713034944767181969410637120547900907218568756200762575051597829134479950576404914169711635847372604479127706077618842035996643591884149562781950411574461397362617417791816778245116260863466052753601876057098724361090722297560034811635819872695472", eval("EncryptPublic=26607139556643363204418370237643583440053732710560835997265044622778483468618675952553903374105586861360913909548750406223725223397318005627583244140295497532082155566770247894398960408895196544736929363267199237398478711530458297621213575936112345748113734751307508958889097610958402325952790221833202314896"));
  EXPECT_EQ("26607139556643363204418370237643583440053732710560835997265044622778483468618675952553903374105586861360913909548750406223725223397318005627583244140295497532082155566770247894398960408895196544736929363267199237398478711530458297621213575936112345748113734751307508958889097610958402325952790221833202314896", eval("EncryptPrivate=86422734220668919222227612974582265611384408354652144064917040713034944767181969410637120547900907218568756200762575051597829134479950576404914169711635847372604479127706077618842035996643591884149562781950411574461397362617417791816778245116260863466052753601876057098724361090722297560034811635819872695472"));
  EXPECT_EQ("26607139556643363204418370237643583440053732710560835997265044622778483468618675952553903374105586861360913909548750406223725223397318005627583244140295497532082155566770247894398960408895196544736929363267199237398478711530458297621213575936112345748113734751307508958889097610958402325952790221833202314896", eval("EncryptPrivate=86422734220668919222227612974582265611384408354652144064917040713034944767181969410637120547900907218568756200762575051597829134479950576404914169711635847372604479127706077618842035996643591884149562781950411574461397362617417791816778245116260863466052753601876057098724361090722297560034811635819872695472"));
  EXPECT_EQ("86422734220668919222227612974582265611384408354652144064917040713034944767181969410637120547900907218568756200762575051597829134479950576404914169711635847372604479127706077618842035996643591884149562781950411574461397362617417791816778245116260863466052753601876057098724361090722297560034811635819872695472", eval("EncryptPublic=26607139556643363204418370237643583440053732710560835997265044622778483468618675952553903374105586861360913909548750406223725223397318005627583244140295497532082155566770247894398960408895196544736929363267199237398478711530458297621213575936112345748113734751307508958889097610958402325952790221833202314896"));

  eval("Quit");
}

TEST_F(REPLTest, test_encryption_512_bits_example_13) {
  eval("P=8874492446194815298634195147570178272716679821403078689964478633182418658749518759188791116605997838707034555448307831519510852858725143389152881237111167");
  eval("Q=10955215907630865176696883717579789810666278805270412677142326482857576096215042495481552029688780132856082640094373734522061315784308794465631518941104863");
  eval("E=134082671271411483620907002117253629346319426046350243438021961466894746159494147140678287517917431190308109593433328889279258830194318393840191693669762482231680328868301649987684921977061519053109626879174222059078559242173934968134805064767113910625028799986726407839329510609774725886441933704666550536837");
  EXPECT_EQ("No", eval("IsPPrime"));
  EXPECT_EQ("No", eval("IsQPrime"));

  eval("Quit");
}

TEST_F(REPLTest, test_encryption_512_bits_example_14) {
  eval("P=7459284035345007983895547484288636873913773887477707803946989687180133717022117172967227175482434430214395836879858463510479862651900208895497410257744967");
  eval("Q=12251613966282301051806701066166882231421901959885312398171738013454910929613444798190945579080519870165634248115277025695192563368185491503408804602852047");
  eval("E=168345455654599860152575359972591122839119252567093721974192598832066311672386518899132167335057999091471998172180393410892011536286869177445504911887793391018192487820592986914173474621929314184260592967217769920445415304710583246396771625481230663628033862430511043047254025200445010613907373621462879552691");
  EXPECT_EQ("Yes", eval("IsPPrime"));
  EXPECT_EQ("Yes", eval("IsQPrime"));
  EXPECT_EQ("91388268465899501172779021929338354811594854745599053696584735916394755185620334457959700689641575845423113349184611741680841715740846933623480442826914530532816577556494721151171416708557723442358481086670440169581039707668343552673265749132825147604755989334900217863614533466089883000745431569818959897449", eval("PrintN"));
  EXPECT_EQ("91388268465899501172779021929338354811594854745599053696584735916394755185620334457959700689641575845423113349184611741680841715740846933623480442826914510821918575929185685448922866253038618106682633723650238050853339072623696917111294590960070584650455609304815222728125327793663862915045032663604099300436", eval("PrintPhi"));
  EXPECT_EQ("88498646358448463308193951802797813178509626942847705683712152685137407899494431247256311287948182517186174218221671406115872035221903371596770893865838604520682447258568167201781749390025227223737483986594118875321778233175100235404716516261902259609731568280163761590249235150374203886585778674334350108847", eval("PrintD"));
  EXPECT_EQ("78799424247129568778159905694943725679769714648524497777566985118032787721137708203242667011395912694043508857983593571948847730429816202799196863491206188258525111753344697969732932134200231753436122849880577499411173929570225697811316614865143781569975883202357490614555564088374439868507155877479718775593", eval("EncryptPublic=25234173132177322820786532796294511035039329233679954061630465713097965428409884808219562791794636942990762465383482510133879092171985877142675730325907924256906721750070885983195263798354402033115096952437425405440805856090918055453061186683987101279232325254433384039930733615451195173749403603459769929031"));
  EXPECT_EQ("25234173132177322820786532796294511035039329233679954061630465713097965428409884808219562791794636942990762465383482510133879092171985877142675730325907924256906721750070885983195263798354402033115096952437425405440805856090918055453061186683987101279232325254433384039930733615451195173749403603459769929031", eval("EncryptPrivate=78799424247129568778159905694943725679769714648524497777566985118032787721137708203242667011395912694043508857983593571948847730429816202799196863491206188258525111753344697969732932134200231753436122849880577499411173929570225697811316614865143781569975883202357490614555564088374439868507155877479718775593"));
  EXPECT_EQ("25234173132177322820786532796294511035039329233679954061630465713097965428409884808219562791794636942990762465383482510133879092171985877142675730325907924256906721750070885983195263798354402033115096952437425405440805856090918055453061186683987101279232325254433384039930733615451195173749403603459769929031", eval("EncryptPrivate=78799424247129568778159905694943725679769714648524497777566985118032787721137708203242667011395912694043508857983593571948847730429816202799196863491206188258525111753344697969732932134200231753436122849880577499411173929570225697811316614865143781569975883202357490614555564088374439868507155877479718775593"));
  EXPECT_EQ("78799424247129568778159905694943725679769714648524497777566985118032787721137708203242667011395912694043508857983593571948847730429816202799196863491206188258525111753344697969732932134200231753436122849880577499411173929570225697811316614865143781569975883202357490614555564088374439868507155877479718775593", eval("EncryptPublic=25234173132177322820786532796294511035039329233679954061630465713097965428409884808219562791794636942990762465383482510133879092171985877142675730325907924256906721750070885983195263798354402033115096952437425405440805856090918055453061186683987101279232325254433384039930733615451195173749403603459769929031"));

  eval("Quit");
}

TEST_F(REPLTest, test_encryption_512_bits_example_15) {
  eval("P=8988015439267230057245376369550551664041262236750095426871287713670435643612476562648153887803334881704300330050357998275535166319074620832396770002245419");
  eval("Q=6924953695251392789325595036367526611724345922545586867667281448304032281278607471710600133414586252960362955627425392080612926750090761205788341866944751");
  eval("E=165527901161580406967992536204964962006183130114153534491208320991874753288072145011040270338496581773491069457119279900404650788049559233469205557048267444259484936857851228943862577030338098135211687221046904782169823941959298653433653465328385863315038456033149797986010177397071109631171346317774037177593");
  EXPECT_EQ("No", eval("IsPPrime"));
  EXPECT_EQ("No", eval("IsQPrime"));

  eval("Quit");
}

TEST_F(REPLTest, test_encryption_512_bits_example_16) {
  eval("P=7905423454004169727274607433005021420339954442708147347204138511709077840873086014302115475257518457473676185989904740923929708837940384535177060407016257");
  eval("Q=12513738696844238816366705529050945883097478253179636423785212816186050157565291568895050335245088787054010656174783233556256444911618376582022665277170077");
  eval("E=130344496611728064681231924618099211193888927619138202579443666632846072893061957417284658928304179181629270084155296048234222964883508049544252428174781031881228257244366382926209743067047994781160345396633515536459369316136314429070760936779768943542055639557917280937141259595161861838368185390984658431707");
  EXPECT_EQ("Yes", eval("IsPPrime"));
  EXPECT_EQ("Yes", eval("IsQPrime"));
  EXPECT_EQ("98926403391312020201234094852293876603291707818923466765654209242901729696874546062197559557246399414690795343999661079435411629508998024633260599378789418410079974768421793003078690964828815711133406005627460051442296178876527076881897129371990760167988535703784024255327709196223059920853639111252292941789", eval("PrintN"));
  EXPECT_EQ("98926403391312020201234094852293876603291707818923466765654209242901729696874546062197559557246399414690795343999661079435411629508998024633260599378789397990917823920013249361765728908861512273700710117843689062090968283748528638504313932206180257560744008016941859567353229010069310362092521911526608755456", eval("PrintPhi"));
  EXPECT_EQ("60382316051061335401747846573429736410387004703917727436825639623330229258924498575041297387477324367198196317884593987372782757321471522221534168379318592397002699482718579670041601244289473194453450141114092105685550162399697526795667152847373332308621486482869214500218579889814671289966853712332799294291", eval("PrintD"));
  EXPECT_EQ("440420183941590982466724483935836022919125810679706681251302519791020177408643338956228548120640705609492387441461107427496356567079543819121709778385672426163574696211969171126098367559918713234532154889621049689801950513717446708182972174495818851712698547385876447041435083769498802777353660049707301690", eval("EncryptPublic=95068566468232255894889863649484002346876757632542376856081511215510880359841951519365606560430796289054901309059577838910896897869837974118017787358669259283801861029168324773989470745868709550604149639118214801990962789115757912938479765334962289800469317150352515478306574066214119548501017728671043393612"));
  EXPECT_EQ("95068566468232255894889863649484002346876757632542376856081511215510880359841951519365606560430796289054901309059577838910896897869837974118017787358669259283801861029168324773989470745868709550604149639118214801990962789115757912938479765334962289800469317150352515478306574066214119548501017728671043393612", eval("EncryptPrivate=440420183941590982466724483935836022919125810679706681251302519791020177408643338956228548120640705609492387441461107427496356567079543819121709778385672426163574696211969171126098367559918713234532154889621049689801950513717446708182972174495818851712698547385876447041435083769498802777353660049707301690"));
  EXPECT_EQ("95068566468232255894889863649484002346876757632542376856081511215510880359841951519365606560430796289054901309059577838910896897869837974118017787358669259283801861029168324773989470745868709550604149639118214801990962789115757912938479765334962289800469317150352515478306574066214119548501017728671043393612", eval("EncryptPrivate=440420183941590982466724483935836022919125810679706681251302519791020177408643338956228548120640705609492387441461107427496356567079543819121709778385672426163574696211969171126098367559918713234532154889621049689801950513717446708182972174495818851712698547385876447041435083769498802777353660049707301690"));
  EXPECT_EQ("440420183941590982466724483935836022919125810679706681251302519791020177408643338956228548120640705609492387441461107427496356567079543819121709778385672426163574696211969171126098367559918713234532154889621049689801950513717446708182972174495818851712698547385876447041435083769498802777353660049707301690", eval("EncryptPublic=95068566468232255894889863649484002346876757632542376856081511215510880359841951519365606560430796289054901309059577838910896897869837974118017787358669259283801861029168324773989470745868709550604149639118214801990962789115757912938479765334962289800469317150352515478306574066214119548501017728671043393612"));

  eval("Quit");
}

TEST_F(REPLTest, test_encryption_512_bits_example_17) {
  eval("P=9414635005223976861689481267803933766592773060058280345207385213286203129224199199563507764976766913500074486541772685718857496143039861723801053637629987");
  eval("Q=5174563116941634408556709033325127422645580106982242517856995249919961701440199816568633136988388921863973189099366011846617334601914076196414323892827249");
  eval("E=91277900201377893616029453515246830671488447638239297330951521640575045549883632901789744059719806540805742327425788349864440746500162069114783500336423174112929889097389611760199550649095244152631344923636707035205199816768587702639694070002532989202746958083689967986487100412753769832732288098532886741889");
  EXPECT_EQ("No", eval("IsPPrime"));
  EXPECT_EQ("No", eval("IsQPrime"));

  eval("Quit");
}

TEST_F(REPLTest, test_encryption_512_bits_example_18) {
  eval("P=12605650535086086185988743007155416988167670207489040090066259525228628565380138682938690556196829563607755574015202257922606898551378362142348415233589711");
  eval("Q=12431002836068992245924754411381642536639800137449362249764223730833306165782674387368298215180320778990958266345100463375686201486254009586786789326447677");
  eval("E=141885697683117910859792079824155926304717628438549658413600465729565188925587094406811178831132287051922346858031338544917486327794905109213440898184263132322423434916189628812566354612977635081732981636299398265235825994678198009352264564145290929501374261338691013774772483821658746033891519692945151090029");
  EXPECT_EQ("Yes", eval("IsPPrime"));
  EXPECT_EQ("Yes", eval("IsQPrime"));
  EXPECT_EQ("156700877552149747023924659080915228708890954422268184506398379227292247983118526040516353576038320384223368195119322531494379266220216780474095397272994610784811805429111460560178104311196247301990348464734591357361488683496007425638982085743923383334585743974959117386713162267498398492573938764752527051347", eval("PrintN"));
  EXPECT_EQ("156700877552149747023924659080915228708890954422268184506398379227292247983118526040516353576038320384223368195119322531494379266220216780474095397272994585748158434274033028646680685774136722494520003526332251526878232621561276262825911778755152006184243145261118757083991863974398360860202209629547967013960", eval("PrintPhi"));
  EXPECT_EQ("82659894423477208501272231314884904511571365690170749124935804184821297879769559674174442537165276051857924391054961637187081571684937504854005906519286074628251748851038962650481191969667222166042305829622416500560967061433678029604715143632389896518804543426809859031629067416361114419106470688137504325469", eval("PrintD"));
  EXPECT_EQ("83524916451985028061345430291159851035747101197739378804012273866154870564476723546553254779308900399793691920740795487581181218265825589488485424508123137127024954018353772979575980569307896204062976508344008067242095937201964517782841649260750306594757001737115445559531437522282982767555284186077358683080", eval("EncryptPublic=123756670760997944145827811371039167153937507767625287317206165282673151786884306494867315220242871741288317967355281128132298022619879642310957519006144997769396498132305985329720356353291204854190858375200048973689455345893267362780075574283661017676014953765317890832982051839320731628306954420265815104449"));
  EXPECT_EQ("123756670760997944145827811371039167153937507767625287317206165282673151786884306494867315220242871741288317967355281128132298022619879642310957519006144997769396498132305985329720356353291204854190858375200048973689455345893267362780075574283661017676014953765317890832982051839320731628306954420265815104449", eval("EncryptPrivate=83524916451985028061345430291159851035747101197739378804012273866154870564476723546553254779308900399793691920740795487581181218265825589488485424508123137127024954018353772979575980569307896204062976508344008067242095937201964517782841649260750306594757001737115445559531437522282982767555284186077358683080"));
  EXPECT_EQ("123756670760997944145827811371039167153937507767625287317206165282673151786884306494867315220242871741288317967355281128132298022619879642310957519006144997769396498132305985329720356353291204854190858375200048973689455345893267362780075574283661017676014953765317890832982051839320731628306954420265815104449", eval("EncryptPrivate=83524916451985028061345430291159851035747101197739378804012273866154870564476723546553254779308900399793691920740795487581181218265825589488485424508123137127024954018353772979575980569307896204062976508344008067242095937201964517782841649260750306594757001737115445559531437522282982767555284186077358683080"));
  EXPECT_EQ("83524916451985028061345430291159851035747101197739378804012273866154870564476723546553254779308900399793691920740795487581181218265825589488485424508123137127024954018353772979575980569307896204062976508344008067242095937201964517782841649260750306594757001737115445559531437522282982767555284186077358683080", eval("EncryptPublic=123756670760997944145827811371039167153937507767625287317206165282673151786884306494867315220242871741288317967355281128132298022619879642310957519006144997769396498132305985329720356353291204854190858375200048973689455345893267362780075574283661017676014953765317890832982051839320731628306954420265815104449"));

  eval("Quit");
}

TEST_F(REPLTest, test_encryption_512_bits_example_19) {
  eval("P=10082554701625555851234290965543480914912979005695898461848293906163217503262983897143000648369967978433741842646548784801201967224398150609593575001021859");
  eval("Q=5517010490003258200286135350440764841531079828334988796508231143148575786291886246660540194849448227267088315824886812661254598501119695962384235643013893");
  eval("E=177931042881629559275411387684752192785236043353804643403412126012380248036172704898436756952200293558977896578683006387287617120948836889938095732310001665908706872928418397662061317377295359852191931823076500798107776268840631875871536885002843784877148119984044296030735673166806707542186287580392959406541");
  EXPECT_EQ("No", eval("IsPPrime"));
  EXPECT_EQ("No", eval("IsQPrime"));

  eval("Quit");
}

TEST_F(REPLTest, test_encryption_512_bits_example_20) {
  eval("P=8251763187044069883267792949115264297167062841907406728390387045528222699286544090435333834412933041283191552773174041189487492104887991650483897528103591");
  eval("Q=8989030543143733781570965612892937656521085304768167191665020719425461575058175510268551537411992232750070783467352266637374859865466933945945311387167441");
  eval("E=167752731902946968764271030993088099268730276990458473352730951951832780130919862531931550090592624668806134256977437696515474781527382683704912006536534541150538588819607303750706595415453449859615324014782279470009694431385207960415280373245682745614104355982650541695002815799704189366091069856106358697311");
  EXPECT_EQ("Yes", eval("IsPPrime"));
  EXPECT_EQ("Yes", eval("IsQPrime"));
  EXPECT_EQ("74175351323128223195222562871285462025130491628294009154803191126838971489810630803742604942377901205660780966769964644467763893633546764062736025349144042982016644651660196386716205624703693693841881427945736649379105593085597140967589644278340129795935685775043472337371912292346275717702646373893910380631", eval("PrintN"));
  EXPECT_EQ("74175351323128223195222562871285462025130491628294009154803191126838971489810630803742604942377901205660780966769964644467763893633546764062736025349144025741222914463856531547957643616501740005693734752371816593971340639401322796247988940392968304870661652512707231811064085429994305362777049944684995109600", eval("PrintPhi"));
  EXPECT_EQ("53094364639430270980825977802518874798316550254941396504892259344847796477600217005127398813611197774920905347273457343491282971211064958950850610852809457663861327931826441958434046860330560235439806775875896187872769480885737507845300748571626381193300400779093857524029836413214985869296273973788046713791", eval("PrintD"));
  EXPECT_EQ("33030506778485082183752590179185223428018430714252937669841912238316272254185887569298710178064619997630993129048485431381859956284904846334447856530518979080259638496970124829471922607786943679741949308810792216063876728872502219816680719022929132512214015935652072807475839215302130756298336514745950571615", eval("EncryptPublic=72185898909006011575043333004725989678377991908848926200552367016523985195499106773526709146386886506833000539329672769795666962440233091197896309747479597319444838060036432262061318582845939075738766746903749989939627425441786871490723413880777470691200065123634866293264510707953209195047627182684569650980"));
  EXPECT_EQ("72185898909006011575043333004725989678377991908848926200552367016523985195499106773526709146386886506833000539329672769795666962440233091197896309747479597319444838060036432262061318582845939075738766746903749989939627425441786871490723413880777470691200065123634866293264510707953209195047627182684569650980", eval("EncryptPrivate=33030506778485082183752590179185223428018430714252937669841912238316272254185887569298710178064619997630993129048485431381859956284904846334447856530518979080259638496970124829471922607786943679741949308810792216063876728872502219816680719022929132512214015935652072807475839215302130756298336514745950571615"));
  EXPECT_EQ("72185898909006011575043333004725989678377991908848926200552367016523985195499106773526709146386886506833000539329672769795666962440233091197896309747479597319444838060036432262061318582845939075738766746903749989939627425441786871490723413880777470691200065123634866293264510707953209195047627182684569650980", eval("EncryptPrivate=33030506778485082183752590179185223428018430714252937669841912238316272254185887569298710178064619997630993129048485431381859956284904846334447856530518979080259638496970124829471922607786943679741949308810792216063876728872502219816680719022929132512214015935652072807475839215302130756298336514745950571615"));
  EXPECT_EQ("33030506778485082183752590179185223428018430714252937669841912238316272254185887569298710178064619997630993129048485431381859956284904846334447856530518979080259638496970124829471922607786943679741949308810792216063876728872502219816680719022929132512214015935652072807475839215302130756298336514745950571615", eval("EncryptPublic=72185898909006011575043333004725989678377991908848926200552367016523985195499106773526709146386886506833000539329672769795666962440233091197896309747479597319444838060036432262061318582845939075738766746903749989939627425441786871490723413880777470691200065123634866293264510707953209195047627182684569650980"));

  eval("Quit");
}

