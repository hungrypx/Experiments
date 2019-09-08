#pragma once
#include <string>
using namespace std;
class Tennis
{
private:
	string matchKind;
	string sideOne;
	string sideTwo;
	unsigned char    gameScoreOne;
	unsigned char    gameScoreTwo;
	unsigned char    setScoreOne;
	unsigned char    setScoreTwo;
	unsigned char    matchScoreOne;
	unsigned char    matchScoreTwo;
	unsigned char    pointsNumOne;
	unsigned char    pointsNumTwo;
	
	void clearSetScore();
	void clearGameScore();
	void clearMatchScore();

public:
	Tennis(string a, string b,string sex="M");
	string GetScore (string who);
	string TieBreak(string who);
	unsigned char GetPointsNum(string a);
	bool  isGamePoint(string &who);
	bool  isSetPoint(string &who);
	bool  isMatchPoint(string &who);
	bool  isTieBreak();
	string CombineScoreStr();
	void  SetGameScore(int playerOneScore, int playerTwoScore);
	void  SetSetScore(int playerOneScore, int playerTwoScore);
	void  SetMatchScore(int playerOneScore, int playerTwoScore);
};