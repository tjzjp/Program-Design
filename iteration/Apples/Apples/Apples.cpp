// Apples.cpp: 定义控制台应用程序的入口点。
//

//Sample
//1
//7 3
//8

#include "stdafx.h"
#include <iostream>
using namespace std;

int f(int m, int n)
{
	if (n > m)
		return f(m, m);
	
	if (n == 0 && m !=0)
		return 0;	
	if (m == 0)
		return 1;
	return f(m, n - 1) + f(m - n, n);
}

int main()
{
	int m, n, t;
	cin >> t;
	while (t--) {
		cin >> m >> n;
		cout << f(m, n) << endl;
	}
	system("pause");
    return 0;
}

