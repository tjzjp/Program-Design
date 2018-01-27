// Problem of Sinple Integer Partition.cpp: 定义控制台应用程序的入口点。
//


#include "stdafx.h"
#include <iostream>
using namespace std;

int f(int m, int n)
{
	if (n > m)
		return f(m, m);
	if (m == 0)
		return 1;
	if (n == 0)
		return 0;
	return f(m, n - 1) + f(m - n, n);
}

int main()
{
	int n;
	cin >> n;
	cout << f(n, n) << endl;
	system("pause");
    return 0;
}

