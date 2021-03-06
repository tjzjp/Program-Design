// 1321Chessboard Problem.cpp: 定义控制台应用程序的入口点。
//

//描述
//在一个给定形状的棋盘（形状可能是不规则的）上面摆放棋子，棋子没有区别。要求摆放时任意的两个棋子不能放在棋盘中的同一行或者同一列，
//请编程求解对于给定形状和大小的棋盘，摆放k个棋子的所有可行的摆放方案C。
//输入
//输入含有多组测试数据。
//每组数据的第一行是两个正整数，n k，用一个空格隔开，表示了将在一个n*n的矩阵内描述棋盘，以及摆放棋子的数目。 n <= 8, k <= n
//当为 - 1 - 1时表示输入结束。
//随后的n行描述了棋盘的形状：每行有n个字符，其中 # 表示棋盘区域，.表示空白区域（数据保证不出现多余的空白行或者空白列）。
//输出
//对于每一组数据，给出一行输出，输出摆放的方案数目C （数据保证C<2 ^ 31）。
//	样例输入
//	2 1
//  #.
//	.#
//	4 4
//	...#
//	..#.
//	.#..
//  #...
//	- 1 - 1
//	样例输出
//	2
//	1

#include "stdafx.h"
#include <iostream>
#include <cstring>
using namespace std;

int n, k;
char c[10][10];
int C;
int vis[10][10];

bool check(int m, int mm)
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
		{
			if (vis[i][j] == 1)
				if (i == m || j == mm)
					return false;
		}
	return true;
}

void dfs(int kk, int h)
{
	if (kk == k)
	{
		C++;
		return;
	}
	for (int i = h; i < n; i++)
		for (int j = 0; j < n; j++)
		{
			if (c[i][j] == '#' && (check(i, j)))
			{
				vis[i][j] = 1;
				dfs(kk + 1, i + 1);
				vis[i][j] = 0;
			}

		}

}

int main()
{
	while (cin >> n >> k)
	{
		C = 0;
		if (n == -1 && k == -1)
			break;
		for (int i = 0; i < n; i++)
			cin >> c[i];
		dfs(0, 0);
		cout << C << endl;
	}
}


//#include <iostream>
//#include <cstring>
//using namespace std;
//
//char b[10][10];
//int n, k;
//int a[10];
//int sum = 0;
//
//int DFS(int r, int x)
//{
//	if (x == 0)
//		return 1;
//	if (n - r < x)
//		return 0;
//	int sum = 0;
//	for (int j = 0; j < n; j++)
//	{
//		if (b[r][j] == '#')
//		{
//			int i;
//			for (i = 0; i < r; i++)
//			{
//				if (a[i] == j)
//					break;
//			}
//			if (i == r)
//			{
//				a[r] = j;
//				sum += DFS(r + 1, x - 1);
//			}				
//		}
//	}
//	a[r] = -1;
//	sum += DFS(r + 1, x);
//	return sum;
//}
//
//int main()
//{
//	while (cin >> n >> k && (n != -1 || k != -1))
//	{
//		memset(a, 0xff, sizeof(a));
//		int m = 0;
//		for (int i = 0; i < n; i++)
//			for (int j = 0; j < n; j++)
//			{
//				cin >> b[i][j];				
//			}
//		cout << DFS(0, k) << endl;
//	}
//    return 0;
//}

