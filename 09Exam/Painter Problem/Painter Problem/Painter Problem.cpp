// Painter Problem.cpp: 定义控制台应用程序的入口点。
//

//描述
//有一个正方形的墙，由N*N个正方形的砖组成，其中一些砖是白色的，另外一些砖是黄色的。Bob是个画家，想把全部的砖都涂成黄色。
//但他的画笔不好使。当他用画笔涂画第(i, j)个位置的砖时， 位置(i - 1, j)、(i + 1, j)、(i, j - 1)、(i, j + 1)上的砖都会改变颜色。
//请你帮助Bob计算出最少需要涂画多少块砖，才能使所有砖的颜色都变成黄色。
//
//输入
//第一行是一个整数n(1≤n ≤15)，表示墙的大小。接下来的n行表示墙的初始状态。每一行包含n个字符。
//第i行的第j个字符表示位于位置(i, j)上的砖的颜色。“w”表示白砖，“y”表示黄砖。
//输出
//一行，如果Bob能够将所有的砖都涂成黄色，则输出最少需要涂画的砖数，否则输出“inf”。
//样例输入
//5
//wwwww
//wwwww
//wwwww
//wwwww
//wwwww
//样例输出
//15

#include "stdafx.h"
#include <iostream>
#include <cstring>
#include <set>
using namespace std;

const int MAXN = 20;
int a[MAXN][MAXN];
int p[MAXN][MAXN];
int N;
char c;

int guess(int b, int n)
{
	int counter = b;
	for (int i = 1; i < n; i++)
		for (int j = 1; j <= n; j++)
		{
			p[i + 1][j] = (a[i][j] + p[i][j] + p[i - 1][j] + p[i][j - 1] + p[i][j + 1] + 1) % 2;
			if (p[i + 1][j])
				counter++;

		}
	for (int i = 1; i <= n; i++)
	{
		if ((p[n][i] + p[n - 1][i] + p[n][i - 1] + p[n][i + 1]) % 2 == a[n][i])
			return 1 << 10;
	}
	return counter;
}

void emu(int n)
{
	int sum = 1 << n;
	set<int> number;
	int c, b;
	b = 0;
	while(sum--)
	{
		number.insert(guess(b, n));
		c = 1;
		p[1][c]++;
		b++;
		while (p[1][c] > 1)
		{
			p[1][c] = 0;
			b--;
			c++;
			p[1][c]++;
		}
	}
	if (*number.begin() == 1 << 10)
		cout << "inf" << endl;
	else
		cout << *number.begin() << endl;
}



int main()
{
	cin >> N;
	memset(p, 0, sizeof(p));
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
		{
			cin >> c;
			if (c == 'w')
				a[i][j] = 0;
			else
				a[i][j] = 1;
		}
	emu(N);
    return 0;
}

