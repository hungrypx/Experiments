#include <stdio.h>
#include "CSingleton.h"
int main()
{
	cout << CSingleton::Func("test Func1") << endl;
	cout << CSingleton::Func("test Func2") << endl;
	cout << CSingleton::Func("test Func3") << endl;
    return 0;
}