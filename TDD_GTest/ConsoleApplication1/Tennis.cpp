#include "stdafx.h"
#include "Tennis.h"
Tennis::Tennis(string a, string b,string sex)
{
	matchKind = sex;
	sideOne = a;
	sideTwo = b;
	clearGameScore();
	clearSetScore();
	clearMatchScore();
	pointsNumOne = 0;
	pointsNumTwo = 0;
}
bool Tennis::isTieBreak()
{
	if (setScoreOne == setScoreTwo && setScoreOne == 6 &&
		!(matchScoreOne ==2 && matchScoreTwo == 2 && matchKind == "M")
		&& !(matchScoreOne == 1 && matchScoreTwo == 1 && matchKind == "F")
		)
	{
		return true;
	}
	else
	{
		return false;
	}
}
void Tennis::clearMatchScore()
{
	matchScoreOne = 0;
	matchScoreTwo = 0;
}
unsigned char Tennis::GetPointsNum(string a)
{
	pointsNumOne = 0;
	pointsNumTwo = 0;
	if (gameScoreOne == 40)
	{
		switch (gameScoreTwo)
		{
		case 0:
			pointsNumOne = 3;
			break;
		case 15:
			pointsNumOne = 2;
			break;
		case 30:
			pointsNumOne = 1;
			break;
		}
	}

	if (gameScoreTwo == 40)
	{
		switch (gameScoreOne)
		{
		case 0:
			pointsNumTwo = 3;
			break;
		case 15:
			pointsNumTwo = 2;
			break;
		case 30:
			pointsNumTwo = 1;
			break;
		}
	}

	if (gameScoreOne == 41)
		pointsNumOne = 1;

	if (gameScoreTwo == 41)
		pointsNumTwo = 1;

	if (sideOne == a)
		return pointsNumOne;
	else
		return pointsNumTwo;
}
void  Tennis::SetGameScore(int playerOneScore, int playerTwoScore)
{
	gameScoreOne = playerOneScore;
	gameScoreTwo = playerTwoScore;
	
}
void  Tennis::SetSetScore(int playerOneScore, int playerTwoScore)
{
	setScoreOne = playerOneScore;
	setScoreTwo = playerTwoScore;
}
void  Tennis::SetMatchScore(int playerOneScore, int playerTwoScore)
{
	matchScoreOne = playerOneScore;
	matchScoreTwo = playerTwoScore;
}
void Tennis::clearSetScore()
{
	setScoreOne = 0;
	setScoreTwo = 0;
}
void Tennis::clearGameScore()
{
	gameScoreOne = 0;
	gameScoreTwo = 0;
}
string Tennis::TieBreak(string who)
{
	if (who == sideOne)
	{
		gameScoreOne += 1;
		if (gameScoreOne >= 7 && gameScoreOne - gameScoreTwo == 2)
		{
			matchScoreOne += 1;
			clearGameScore();
			clearSetScore();
		}
	}
	else
	{
		gameScoreTwo += 1;
		if (gameScoreTwo >= 7 && gameScoreTwo - gameScoreOne == 2)
		{
			matchScoreTwo += 1;
			clearGameScore();
			clearSetScore();
		}
	}
	return CombineScoreStr();
}
string Tennis::GetScore(string who)
{
	if(isTieBreak())
	{
		return TieBreak(who);
	}
	if (sideOne == who)
	{
		switch (gameScoreOne)
		{
		case 60:
		case 0:
			gameScoreOne = 15;
			break;
		case 15:
			gameScoreOne = 30;
			break;
		case 30:
			gameScoreOne = 40;
			break;
		case 40:
			if (gameScoreTwo < 40)
			{
				gameScoreOne = 60;
			}
			else if (gameScoreTwo == 40)
			{
				gameScoreOne = 41;
			}
			else if (gameScoreTwo == 41)
			{
				gameScoreTwo = 40;
			}
			break;
		case 41:
			gameScoreOne = 60;
			break;
		}
	}
	else //sideTwo
	{
		switch (gameScoreTwo)
		{
		case 60:
		case 0:
			gameScoreTwo = 15;
			break;
		case 15:
			gameScoreTwo = 30 ;
			break;
		case 30:
			gameScoreTwo = 40;
			break;
		case 40:
			if (gameScoreOne < 40)
			{
				gameScoreTwo = 60;
			}
			else if (gameScoreOne == 40)
			{
				gameScoreTwo = 41;
			}
			else if (gameScoreOne == 41)
			{
				gameScoreOne = 40;
			}
			break;
		case 41:
			gameScoreTwo = 60;
			break;
		}
	}

	if (gameScoreOne == 60 || gameScoreTwo == 60)
	{
		if( gameScoreOne == 60)
		{ 
			clearGameScore();
			setScoreOne += 1 ;
		}
		else
		{
			clearGameScore();
			setScoreTwo +=1 ;
		}

	}
	if (setScoreOne >= 6 && setScoreOne - setScoreTwo >= 2)
	{
		matchScoreOne += 1;
		clearSetScore();
	}
	if (setScoreTwo >= 6 && setScoreTwo - setScoreOne >= 2)
	{
		matchScoreTwo += 1;
		clearSetScore();
	}
	if (setScoreOne == 7 && setScoreTwo == 6)
	{
		matchScoreOne += 1;
		clearSetScore();
	}
	if (setScoreOne == 6 && setScoreTwo == 7)
	{
		matchScoreTwo += 1;
		clearSetScore();
	}

		return CombineScoreStr();
}
string  Tennis::CombineScoreStr()
{

	string  scoreDisplayStr = sideOne + ":" + sideTwo + "="
		+ to_string(matchScoreOne) + ":" + to_string(matchScoreTwo) + "|"
		+ to_string(setScoreOne) + ":" + to_string(setScoreTwo) + "|"
		+ (gameScoreOne != 41 ? to_string(gameScoreOne) : "AD") + ":"
		+ (gameScoreTwo != 41 ? to_string(gameScoreTwo) : "AD");
	return scoreDisplayStr;
}
bool  Tennis::isGamePoint(string &who)
{
	if (GetPointsNum(sideOne) > 0 )
	{
		who = sideOne;
		return true;
	}
	else if (GetPointsNum(sideTwo) > 0 )
	{
		who = sideTwo;
		return true;
	}
	else
	{
		who = "";
		return false;
	}
}
bool  Tennis::isSetPoint(string &who)
{
	if (isGamePoint(who))
	{
		if (who == sideOne)
		{
			if (setScoreOne == 5 && setScoreTwo <= 4)
			{
				return true;
			}
			else if (setScoreOne == 6 && setScoreTwo == 6)
			{
				return true;
			}
			else if (setScoreOne - setScoreTwo == 1 && setScoreOne >=6 )
			{
				return true;
			}
			else
			{
				return false;
			}

		}
		if (who == sideTwo)
		{
			if (setScoreTwo == 5 && setScoreOne <= 4)
			{
				return true;
			}
			else if (setScoreOne == 6 && setScoreTwo == 6)
			{
				return true;
			}
			else if (setScoreTwo - setScoreOne == 1 && setScoreTwo >= 6)
			{
				return true;
			}
			else
			{
				return false;
			}

		}
	}
	return false;
}
bool  Tennis::isMatchPoint(string &who)
{
	if (isSetPoint(who))
	{
		if (who == sideOne)
		{
			if ( (matchScoreOne == 2 && matchKind == "M" )|| (matchScoreOne == 1 && matchKind == "F"))
			{
				return true;
			}
			else
				return false;
		}
		else if (who == sideTwo)
		{
			if ( (matchScoreTwo == 2 && matchKind == "M") || (matchScoreTwo == 1 && matchKind == "F"))
			{
				return true;
			}
			else
				return false;
		}
		else
		{
		}
	}
	return false;
}