// Monthly Expense.cpp: 定义控制台应用程序的入口点。
//

//描述
//农夫约翰是一个精明的会计师。他意识到自己可能没有足够的钱来维持农场的运转了。
//他计算出并记录下了接下来 N(1 ≤ N ≤ 100, 000) 天里每天需要的开销。
//约翰打算为连续的M(1 ≤ M ≤ N) 个财政周期创建预算案，他把一个财政周期命名为fajo月。
//每个fajo月包含一天或连续的多天，每天被恰好包含在一个fajo月里。
//约翰的目标是合理安排每个fajo月包含的天数，使得开销最多的fajo月的开销尽可能少。
//
//输入
//第一行包含两个整数N, M，用单个空格隔开。
//接下来N行，每行包含一个1到10000之间的整数，按顺序给出接下来N天里每天的开销。
//输出
//一个整数，即最大月度开销的最小值。
//样例输入
//7 5
//100
//400
//300
//100
//500
//101
//400
//样例输出
//500

#include "stdafx.h"
#include <iostream>
#include <algorithm>
using namespace std;

int N, M;
int X[1000000];

bool Valid(int Mid)
{
	int c = 1;
	int cur = 0;
	for (int i = 0; i < N; i++)
	{
		if (X[i] > Mid)
			return false;
		if (cur + X[i] > Mid)
		{
			cur += X[i];
			c++;
			if (c > M)
			{
				return false;
			}
		}
		else
			cur += X[i];
	}
	return true;
}

int main()
{
	int L = 1 << 30;
	int R = 0;
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		cin >> X[i];
		L = min(L, X[i]);
		R += X[i];
	}
	sort(X, X + N);
	int lastValid = 0;
	while (L <= R)
	{
		int mid = L + (R - L) / 2;
		if (Valid(mid))
		{
			lastValid = mid;
			R = mid - 1;
		}
		else
			L = mid + 1;
	}
	cout << lastValid;
	system("pause");
    return 0;
}

