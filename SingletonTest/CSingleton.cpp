#include "CSingleton.h"
bool CSingleton::initFlag = false;
void CSingleton::Init()
{
	cout << "Init ok" << endl;
}
string CSingleton::Func(string param)
{
	if (!initFlag)
	{
		Init();
		initFlag = true;
	}
	return param;
}