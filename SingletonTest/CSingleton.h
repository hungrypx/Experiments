#pragma once
#ifndef CSingleton_H 
#define CSingleton_H
#include <string>
#include <iostream>
using namespace std;
class CSingleton
{
private:
	CSingleton()
	{
	}
	static bool initFlag;
	static void Init();
public:
	static string Func(string param);
	
};

#endif
