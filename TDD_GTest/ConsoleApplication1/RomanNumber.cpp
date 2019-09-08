#include "stdafx.h"
#include "RomanNumber.h"

#define SYMBOLS_NUM 13

CRomanNumber::CRomanNumber()
{
}


CRomanNumber::~CRomanNumber()
{
}
std::string CRomanNumber::Convert(int i)
{
	if (i > 3999 || i <= 0)
	{
		throw std::exception("overflow,not support out of 1-3999");
	}
	std::string romanValue;
	std::string symbols[] ={ "M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I" };
	unsigned short int level[] = {1000,900,500,400,100,90,50,40,10,9,5,4,1};
	while (true)
	{
		for (int loop = 0; loop < SYMBOLS_NUM;loop++)
		{
			if (i >= level[loop])
			{
				romanValue= romanValue.append(symbols[loop]);
				i -= level[loop];
				break;
			}
		}
		if (i == 0)
			break;
	}
	return romanValue;
}
std::string CRomanNumber::ConvertOld(int i)
{
	/*
	»ù±¾×Ö·û
		I  1
		V  5
		X  10
		L  50
		C  100
		D  500
		M  1000
	*/
	if (i > 3999 || i<=0)
	{
		 throw std::exception("overflow,not support out of 1-3999");
	}
	std::string value;
	while (true)
	{
		if (i >= 1000)
		{
			value.append("M");
			i -= 1000;
		}
		else if (i >= 900)
		{
			value.append("CM");
			i -= 900;
		}
		else if (i >= 500)
		{
			value.append("D");
			i -= 500;
		}
		else if (i >= 400)
		{
			value.append("CD");
			i -= 400;
		}
		else if (i >= 100)
		{
			value.append("C");
			i -= 100;
		}
		else if (i >= 90)
		{
			value.append("XC");
			i -= 90;
		}
		else if (i >= 50)
		{
			value.append ("L");
			i -= 50;
		}
		else if (i >= 40)
		{
			value.append("XL");
			i -= 40;
		}
		else if (i >= 10)
		{
			value.append("X");
 			i -= 10;
		}
		else if (i >= 9)
		{
			value.append("IX");
			i -= 9;
		}
		else if (i >= 5)
		{
			value.append("V");
			i -= 5;
		}
		else if (i >= 4)
		{
			value.append("IV");
			i -= 4;
		}
		else if(i>= 1)
		{
			
			value.append("I");
			i -= 1;
			
		}
		else
		{
			break;
		}
	}
	return value;
}