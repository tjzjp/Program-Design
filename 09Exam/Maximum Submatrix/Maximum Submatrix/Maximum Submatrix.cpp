// Maximum Submatrix.cpp: 定义控制台应用程序的入口点。
//
//描述
//已知矩阵的大小定义为矩阵中所有元素的和。给定一个矩阵，你的任务是找到最大的非空(大小至少是1 * 1)子矩阵。
//
//比如，如下4 * 4的矩阵
//
//0 - 2 - 7 0
//9 2 - 6 2
//- 4 1 - 4 1
//- 1 8 0 - 2
//
//的最大子矩阵是
//
//9 2
//- 4 1
//- 1 8
//
//这个子矩阵的大小是15。
//输入
//输入是一个N * N的矩阵。输入的第一行给出N(0 < N <= 100)。
//再后面的若干行中，依次（首先从左到右给出第一行的N个整数，再从左到右给出第二行的N个整数……）给出矩阵中的N2个整数，
//整数之间由空白字符分隔（空格或者空行）。已知矩阵中整数的范围都在[-127, 127]。
//	输出
//	输出最大子矩阵的大小。
//	样例输入
//	4
//	0 - 2 - 7 0 9 2 - 6 2
//	- 4 1 - 4  1 - 1
//
//	8  0 - 2
//	样例输出
//	15

#include "stdafx.h"
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAXN = 110;
int a[MAXN][MAXN];
int N;


int main()
{
	memset(a, 0, sizeof(a));
	int ans = 0;
	cin >> N;
	int temp;
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
		{
			cin >> temp;
			a[i][j] = a[i][j - 1] + temp;
		}
	for (int i = 1; i <= N; i++)
		for (int j = i; j <= N; j++)
		{
			int sub = 0;
			for (int k = 1; k <= N; k++)
			{
				if (sub < 0)
					sub = 0;
				int tt = a[k][j] - a[k][i - 1];
				sub += tt;
				ans = max(ans, sub);
			}
		}
	cout << ans << endl;
    return 0;
}

