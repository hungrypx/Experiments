#include "pch.h"
#include "..\ConsoleApplication1\RomanNumber.h"

TEST(TestCaseName, TestName) {
  EXPECT_EQ(1, 1);
  EXPECT_TRUE(true);
}

TEST(CRomanNumberTest, Convert_one_I) {
	CRomanNumber number;
	auto roman = number.Convert(1);
	ASSERT_EQ(std::string("I"), roman);
}

TEST(CRomanNumberTest, Convert_two_II) {
	CRomanNumber number;
	auto roman = number.Convert(2);
	ASSERT_EQ(std::string("II"), roman);
}

TEST(CRomanNumberTest, Convert_three_III) {
	CRomanNumber number;
	auto roman = number.Convert(3);
	ASSERT_EQ(std::string("III"), roman);
}
TEST(CRomanNumberTest, Convert_four_IV) {
	CRomanNumber number;
	auto roman = number.Convert(4);
	ASSERT_EQ(std::string("IV"), roman);
}

TEST(CRomanNumberTest, Convert_five_V) {
	CRomanNumber number;
	auto roman = number.Convert(5);
	ASSERT_EQ(std::string("V"), roman);
}

TEST(CRomanNumberTest, Convert_six_VI) {
	CRomanNumber number;
	auto roman = number.Convert(6);
	ASSERT_EQ(std::string("VI"), roman);
}
TEST(CRomanNumberTest, Convert_2014_MMXIV) {
	CRomanNumber number;
	auto roman = number.Convert(2014);
	ASSERT_EQ(std::string("MMXIV"), roman);
}
TEST(CRomanNumberTest, Convert_1904_MCMIV) {
	CRomanNumber number;
	auto roman = number.Convert(1904);
	ASSERT_EQ(std::string("MCMIV"), roman);
}
TEST(CRomanNumberTest, Convert_1999_MCMXCIX) {
	CRomanNumber number;
	auto roman = number.Convert(1999);
	ASSERT_EQ(std::string("MCMXCIX"), roman);
}
TEST(CRomanNumberTest, ConvertOld_1999_MCMXCIX) {
	CRomanNumber number;
	auto roman = number.ConvertOld(1999);
	ASSERT_EQ(std::string("MCMXCIX"), roman);
}
TEST(CRomanNumberTest, Convert_0_Expect_Exception) {
	CRomanNumber number;
	EXPECT_THROW(number.Convert(0), std::exception);
}
TEST(CRomanNumberTest, Convert_4008_Expect_Exception) {
	CRomanNumber number;
	EXPECT_THROW(number.Convert(4008), std::exception);
}