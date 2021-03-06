// A Power Square Representation of 2.cpp: 定义控制台应用程序的入口点。
//

//描述
//任何一个正整数都可以用2的幂次方表示。例如：
//137 = 27 + 23 + 20
//同时约定方次用括号来表示，即ab可表示为a(b)。由此可知，137可表示为：
//2(7) + 2(3) + 2(0)
//进一步：7 = 22 + 2 + 20（21用2表示）
//3 = 2 + 20
//所以最后137可表示为：
//2(2(2) + 2 + 2(0)) + 2(2 + 2(0)) + 2(0)
//又如：
//1315 = 210 + 28 + 25 + 2 + 1
//所以1315最后可表示为：
//2(2(2 + 2(0)) + 2) + 2(2(2 + 2(0))) + 2(2(2) + 2(0)) + 2 + 2(0)
//输入
//一个正整数n（n≤20000）。
//输出
//一行，符合约定的n的0，2表示（在表示中不能有空格）。

#include "stdafx.h"
#include <iostream>
using namespace std;

int GetBit(int n, int i)
{
	return (n >> i) & 1;
}

void recur(int n)
{
	bool first = true;
	for (int i = 15; i >= 0; i--)
	{
		if (GetBit(n, i))
		{
			if (first)
				first = false;
			else
				cout << "+";
			if (i == 0)
				cout << "2(0)";
			else if (i == 1)
				cout << "2";
			else
			{
				cout << "2(";
				recur(i);
				cout << ")";
			}
		}
	}
	

}

int main()
{
	int n;
	cin >> n;
	recur(n);
	return 0;
}
































//#include <iostream>
//using namespace std;
//
//int n;
//
//int GetBit(int n, int i)
//{
//	return (n >> i) & 1;
//}
//
//void power_square(int n)
//{
//	bool first = true;
//	for (int i = 15; i >= 0; i--)
//	{
//		if (GetBit(n, i))
//		{
//			if (!first)
//			{
//				cout << "+";
//			}
//			else
//				first = false;
//			if (i == 0)
//				cout << "2(0)";
//			else if (i == 1)
//				cout << "2";
//			else
//			{
//				cout << "2(";
//				power_square(i);
//				cout << ")";
//			}
//		}
//	}
//}
//
//int main()
//{
//	cin >> n;
//	power_square(n);
//	system("pause");
//    return 0;
//}

