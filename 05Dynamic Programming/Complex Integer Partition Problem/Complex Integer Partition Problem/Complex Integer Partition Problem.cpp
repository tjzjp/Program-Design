// Complex Integer Partition Problem.cpp: 定义控制台应用程序的入口点。
//

//描述
//将正整数n 表示成一系列正整数之和，n = n1 + n2 + … + nk, 其中n1 >= n2 >= … >= nk >= 1 ，k >= 1 。
//正整数n 的这种表示称为正整数n 的划分。
//输入
//标准的输入包含若干组测试数据。每组测试数据是一行输入数据, 包括两个整数N 和 K。
//(0 < N <= 50, 0 < K <= N)
//	输出
//	对于每组测试数据，输出以下三行数据 :
//第一行: N划分成K个正整数之和的划分数目
//	第二行 : N划分成若干个不同正整数之和的划分数目
//	第三行 : N划分成若干个奇正整数之和的划分数目
//	样例输入
//	5 2
//	样例输出
//	2
//	3
//	3

#include "stdafx.h"
#include <iostream>
#include <cstring>
using namespace std;

const int MAXN = 55;
int n, k;
int isvis[MAXN][MAXN];
int isvis1[MAXN][MAXN];
int vis[MAXN][MAXN][MAXN];

int f(int n, int m, int k)
{
	if (vis[n][m][k] != -1)
		return vis[n][m][k];
	if (n == 0 && k == 0)
		return 1;
	if (k == 0)
		return 0;
	if (m == 0)
		return 0;
	if (n == 0)
		return 0;
	int result = f(n, m - 1, k);
	if (n >= m)
		result += f(n - m, m, k - 1);
	vis[n][m][k] = result;
	return result;
	
}

int f1(int n, int k)
{
	if (isvis[n][k] != -1)
		return isvis[n][k];
	if (n == 0)
		return 1;
	if (k == 0)
		return 0;
	int result = f1(n, k - 1);
	if (n >= k)
		result += f1(n - k, k - 1);
	isvis[n][k] = result;
	return result;
}

int f2(int n, int k)
{
	if (isvis1[n][k] != -1)
		return isvis1[n][k];
	if (n == 0)
		return 1;
	if (k == 0)
		return 0;
	int result = f2(n, k - 1);
	if ((k % 2) == 1 && n >= k)
		result += f2(n - k, k);
	isvis1[n][k] = result;
	return result;
}

int main()
{
	memset(vis, 0xff, sizeof(vis));
	memset(isvis, 0xff, sizeof(isvis));
	memset(isvis1, 0xff, sizeof(isvis));
	while (cin >> n >> k)
	{
		cout << f(n, n, k) << endl;	
		cout << f1(n, n) << endl;
		cout << f2(n, n) << endl;
	}
	

	return 0;
}































//#include <iostream>
//#include <cstring>
//using namespace std;
//#define MAXN 52
//
//int waysNK[MAXN][MAXN][MAXN];
//int waysND[MAXN][MAXN];
//int waysNO[MAXN][MAXN];
//int N, K;
//
//int WaysNK(int i, int j, int k)
//{
//	if (j == 0 && k == 0)
//		return 1;
//	if (k == 0)
//		return 0;
//	if (j == 0)
//		return 0;
//	if (i == 0)
//		return 0;
//	
//	if (waysNK[i][j][k] != -1)
//		return waysNK[i][j][k];
//	int result = WaysNK(i - 1, j, k);
//	if (j >= i)
//		result += WaysNK(i, j - i, k - 1);
//	waysNK[i][j][k] = result;
//	return result;
//}
//
//int WaysND(int i, int j)
//{
//	if (j == 0)
//		return 1;
//	if (i == 0)
//		return 0;
//	if (waysND[i][j] != -1)
//		return waysND[i][j];
//	int result = WaysND(i - 1, j);
//	if (i <= j)
//		result += WaysND(i - 1, j - i);
//	waysND[i][j] = result;
//	return result;
//}
//
//int WaysNO(int i, int j)
//{
//	if (j == 0)
//		return 1;
//	if (i == 0)
//		return 0;
//	if (waysNO[i][j] != -1)
//		return waysNO[i][j];
//	int result = WaysNO(i - 1, j);
//	if (i % 2 && i <= j)
//		result += WaysNO(i, j - i);
//	waysNO[i][j] = result;
//	return result;
//}
//
//int main()
//{
//	memset(waysNK, 0xff, sizeof(waysNK));
//	memset(waysND, 0xff, sizeof(waysND));
//	memset(waysNO, 0xff, sizeof(waysNO));
//	while (cin >> N >> K)
//	{
//		cout << WaysNK(N, N, K) << endl;
//		cout << WaysND(N, N) << endl;
//		cout << WaysNO(N, N) << endl;
//	}
//    return 0;
//}

