// Climb Stairs.cpp: 定义控制台应用程序的入口点。
//

//Sample 
//5 8 10
//8 34 89

#include "stdafx.h"
#include <iostream>
using namespace std;

int stairs(int n)
{
	if (n == 1)
		return 1;
	if (n == 2)
		return 2;
	return stairs(n - 1) + stairs(n - 2);
}

int main()
{
	while (1)
	{
		int n;
		cin >> n;
		cout << stairs(n) << endl;;
	}
    return 0;
}

