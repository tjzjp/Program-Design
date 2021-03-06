// Problem of Sinple Integer Partition.cpp: 定义控制台应用程序的入口点。
//

//描述
//将正整数n 表示成一系列正整数之和，n = n1 + n2 + … + nk, 其中n1 >= n2 >= … >= nk >= 1 ，k >= 1 。
//正整数n 的这种表示称为正整数n 的划分。正整数n 的不同的划分个数称为正整数n 的划分数。
//输入
//标准的输入包含若干组测试数据。每组测试数据是一个整数N(0 < N <= 50)。
//	输出
//	对于每组测试数据，输出N的划分数。
//	样例输入
//	5
//	样例输出
//	7
//	提示
//	5, 4 + 1, 3 + 2, 3 + 1 + 1, 2 + 2 + 1, 2 + 1 + 1 + 1, 1 + 1 + 1 + 1 + 1


#include "stdafx.h"
#include <iostream>
using namespace std;

int n;
int sum;

int recur(int n, int k)
{
	if (n < k)
		return recur(n, n);
	if (n == 0)
		return 1;
	if (k == 0)
		return 0;
	return recur(n, k - 1) + recur(n - k, k);
}

int main()
{
	while(cin >> n)
		cout << recur(n, n) << endl;
	return 0;
}

//#include <iostream>
//using namespace std;
//
//int f(int m, int n)
//{
//	if (n > m)
//		return f(m, m);
//	if (m == 0)
//		return 1;
//	if (n == 0)
//		return 0;
//	return f(m, n - 1) + f(m - n, n);
//}
//
//int main()
//{
//	int n;
//	cin >> n;
//	cout << f(n, n) << endl;
//    return 0;
//}

