#include "pch.h"
#include "..\ConsoleApplication1\Tennis.h"
TEST(TennisTest, GetScore_SimpleTest)
{
	Tennis tns("Novak","Rafael","M");
	EXPECT_STREQ("Novak:Rafael=0:0|0:0|15:0",tns.GetScore("Novak").data());

}
TEST(TennisTest, GetScore_LoveGameTest)
{
	Tennis tns("Novak","Rafael","M");
	EXPECT_STREQ("Novak:Rafael=0:0|0:0|15:0",tns.GetScore("Novak").data());
	EXPECT_STREQ("Novak:Rafael=0:0|0:0|30:0",tns.GetScore("Novak").data());
	EXPECT_STREQ("Novak:Rafael=0:0|0:0|40:0",tns.GetScore("Novak").data());
	EXPECT_STREQ("Novak:Rafael=0:0|1:0|0:0",tns.GetScore("Novak").data());
	EXPECT_STREQ("Novak:Rafael=0:0|1:0|15:0",tns.GetScore("Novak").data());
}
TEST(TennisTest, GetScore_CompleteGameTest)
{
	Tennis tns("Novak","Rafael","M");
	EXPECT_STREQ("Novak:Rafael=0:0|0:0|15:0", tns.GetScore("Novak").data());
	EXPECT_STREQ("Novak:Rafael=0:0|0:0|15:15", tns.GetScore("Rafael").data());
	EXPECT_STREQ("Novak:Rafael=0:0|0:0|30:15", tns.GetScore("Novak").data());
	EXPECT_STREQ("Novak:Rafael=0:0|0:0|40:15", tns.GetScore("Novak").data());
	EXPECT_STREQ("Novak:Rafael=0:0|0:0|40:30", tns.GetScore("Rafael").data());
	EXPECT_STREQ("Novak:Rafael=0:0|0:0|40:40", tns.GetScore("Rafael").data());
	EXPECT_STREQ("Novak:Rafael=0:0|0:0|40:AD", tns.GetScore("Rafael").data());
	EXPECT_STREQ("Novak:Rafael=0:0|0:0|40:40", tns.GetScore("Novak").data());
	EXPECT_STREQ("Novak:Rafael=0:0|0:0|AD:40", tns.GetScore("Novak").data());
	EXPECT_STREQ("Novak:Rafael=0:0|0:0|40:40", tns.GetScore("Rafael").data());
	EXPECT_STREQ("Novak:Rafael=0:0|0:0|40:AD", tns.GetScore("Rafael").data());
	EXPECT_STREQ("Novak:Rafael=0:0|0:1|0:0", tns.GetScore("Rafael").data());
	EXPECT_STREQ("Novak:Rafael=0:0|0:1|15:0", tns.GetScore("Novak").data());
}
TEST(TennisTest, GetScore_DeuceTest)
{
	Tennis tns("Novak","Rafael","M");
	tns.SetGameScore(40, 40);
	EXPECT_STREQ("Novak:Rafael=0:0|0:0|40:AD", tns.GetScore("Rafael").data());
	EXPECT_STREQ("Novak:Rafael=0:0|0:0|40:40", tns.GetScore("Novak").data());
	EXPECT_STREQ("Novak:Rafael=0:0|0:0|AD:40", tns.GetScore("Novak").data());
	EXPECT_STREQ("Novak:Rafael=0:0|0:0|40:40", tns.GetScore("Rafael").data());
	EXPECT_STREQ("Novak:Rafael=0:0|0:0|40:AD", tns.GetScore("Rafael").data());
	EXPECT_STREQ("Novak:Rafael=0:0|0:1|0:0", tns.GetScore("Rafael").data());
	EXPECT_STREQ("Novak:Rafael=0:0|0:1|15:0", tns.GetScore("Novak").data());
}
TEST(TennisTest, GetScore_GamePointTest)
{
	Tennis tns("Novak","Rafael","M");
	tns.SetGameScore(40, 30);
	tns.SetSetScore(3, 4);
	EXPECT_STREQ("Novak:Rafael=0:0|4:4|0:0", tns.GetScore("Novak").data());
}
TEST(TennisTest, GetScore_BWinSetPointTest)
{
	Tennis tns("Novak","Rafael","M");
	tns.SetSetScore(3, 5);
	tns.SetGameScore(15, 40);
	EXPECT_STREQ("Novak:Rafael=0:1|0:0|0:0", tns.GetScore("Rafael").data());
}
TEST(TennisTest, GetScore_NoSetPointTest)
{
	Tennis tns("Novak","Rafael","M");
	tns.SetSetScore(5, 5);
	tns.SetGameScore(15, 40);
	EXPECT_STREQ("Novak:Rafael=0:0|5:6|0:0", tns.GetScore("Rafael").data());
}
TEST(TennisTest, GetScore_AWinSetPointTest)
{
	Tennis tns("Novak","Rafael","M");
	tns.SetSetScore(6, 5);
	tns.SetGameScore(40,30);
	EXPECT_STREQ("Novak:Rafael=1:0|0:0|0:0", tns.GetScore("Novak").data());
}
TEST(TennisTest, GetScore_PointNumTest)
{
	Tennis tns("Novak","Rafael","M");
	tns.SetSetScore(6, 5);
	tns.SetGameScore(40, 15);
	EXPECT_EQ(2, tns.GetPointsNum("Novak"));
}
TEST(TennisTest, GetPointNum_Test_Expect_0)
{
	Tennis tns("Novak","Rafael","M");
	tns.SetSetScore(6, 5);
	tns.SetGameScore(30, 15);
	EXPECT_EQ(0, tns.GetPointsNum("Novak"));
}
TEST(TennisTest, GetPointNum_DecreaseTest_Expect_1)
{
	Tennis tns("Novak","Rafael","M");
	tns.SetSetScore(6, 5);
	tns.SetGameScore(40, 15);
	EXPECT_EQ(2, tns.GetPointsNum("Novak"));
	tns.GetScore("Rafael");
	EXPECT_EQ(1, tns.GetPointsNum("Novak"));
}
TEST(TennisTest, isGamePointTest_Expect_A_true)
{
	Tennis tns("Novak","Rafael","M");
	tns.SetGameScore(40, 15);
	string who;
	EXPECT_TRUE(tns.isGamePoint(who));
	EXPECT_EQ("Novak",who);
}
TEST(TennisTest, isSetPointTest_Expect_A_true)
{
	Tennis tns("Novak","Rafael","M");
	tns.SetSetScore(5, 4);
	tns.SetGameScore(40, 15);
	string who;
	EXPECT_TRUE(tns.isSetPoint(who));
	EXPECT_EQ("Novak", who);
}
TEST(TennisTest, isMatchPointTest_Expect_A_true)
{
	Tennis tns("Novak", "Rafael","M");
	tns.SetMatchScore(2, 1);
	tns.SetSetScore(5, 4);
	tns.SetGameScore(40, 15);
	string who;
	EXPECT_TRUE(tns.isMatchPoint(who));
	EXPECT_EQ("Novak", who);
}

TEST(TennisTest, GetScore_Expect_EnterTieBreak)
{
	Tennis tns("Novak", "Rafael", "M");
	tns.SetMatchScore(2, 1);
	tns.SetSetScore(6, 6);
	tns.SetGameScore(0,0);
	EXPECT_STREQ("Novak:Rafael=2:1|6:6|1:0",tns.GetScore("Novak").data());
}
TEST(TennisTest, GetScore_Expect_JSSetNotEnterTieBreak)
{
	Tennis tns("Novak", "Rafael", "M");
	tns.SetMatchScore(2, 2);
	tns.SetSetScore(6, 6);
	tns.SetGameScore(0, 0);
	EXPECT_STREQ("Novak:Rafael=2:2|6:6|15:0", tns.GetScore("Novak").data());
}
TEST(TennisTest, GetScore_Expect_TieBreakComplete)
{
	Tennis tns("Novak", "Rafael", "M");
	tns.SetMatchScore(2, 1);
	tns.SetSetScore(6, 6);
	tns.SetGameScore(6, 5);
	EXPECT_STREQ("Novak:Rafael=3:1|0:0|0:0", tns.GetScore("Novak").data());
}