// Division.cpp: 定义控制台应用程序的入口点。
//

//问题描述
//小葱喜欢除法，所以他给了你N个数a1, a2, ⋯, aN，并且希望你执行M次操作，每次操作可能有以下两种：
//给你三个数l, r, v，你需要将al, al + 1, ⋯, ar之间所有v的倍数除以v。
//给你两个数l, r，你需要回答al + al + 1 + ⋯ + ar的值是多少。
//输入格式
//第一行两个整数N, M，代表数的个数和操作的次数。
//接下来一行N个整数，代表N个数一开始的值。
//接下来M行，每行代表依次操作。每行开始有一个整数opt。
//如果opt = 1，那么接下来有三个数l, r, v，代表这次操作需要将第l个数到第r个数中v的倍数除以v；
//如果opt = 2，那么接下来有两个数l, r，代表你需要回答第l个数到第r个数的和。
//输出格式
//对于每一次的第二种操作，输出一行代表这次操作所询问的值。
//样例输入
//5 3
//1 2 3 4 5
//2 1 5
//1 1 3 2
//2 1 5
//样例输出
//15
//14
//评测用例规模与约定
//对于30%的评测用例，1 ≤ N, M ≤ 1000；
//对于另外20%的评测用例，第一种操作中一定有l = r；
//对于另外20%的评测用例，第一种操作中一定有l = 1, r = N；
//对于100%的评测用例，1 ≤ N, M ≤ 105，0 ≤ a1, a2, ⋯, aN ≤ 106, 1 ≤ v ≤ 106, 1 ≤ l ≤ r ≤ N。

#include "stdafx.h"
#include <iostream>
using namespace std;

int n, m;
int a[101024];
long long tree[101024];
int opt, l, r, v;

void update(int i, int x)
{
	while (i <= n)
	{
		tree[i] += x;
		i += -i&i;
	}
}

long long getsum(int i)
{
	long long sum = 0;
	while (i > 0)
	{
		sum += tree[i];
		i -= -i&i;
	}
	return sum;
}

int main()
{
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		update(i, a[i]);
	}

	while (m--)
	{
		cin >> opt >> l >> r;
		if (opt == 1)
		{
			cin >> v;
			if (v == 1)
				continue;
			while (l <= r)
			{
				if (a[l] >= v && a[l] % v == 0)
				{
					update(l, -(a[l] - a[l] / v));
					a[l] /= v;
				}
				l++;
			}
		}
		else
			cout << getsum(r) - getsum(l - 1) << endl;
	}
	return 0;
}




























//#include <iostream>
//using namespace std;
//
//long long a[100010];
//long long v, l, r;
//long long n, m;
////long long s[100010][100010];
//
//int main()
//{
//	cin >> n >> m;
//	for (size_t i = 1; i <= n; i++)
//		cin >> a[i];
//	/*for (size_t i = 1; i <= n; i++)
//		for (size_t j = i; j <= n; j++)*/
//
//	while (m--)
//	{
//		int opt;
//		cin >> opt;
//		if (opt == 1)
//		{
//			cin >> l >> r >> v;
//			size_t i;
//			for (i = l; i <= r; i++)
//				if (a[i] % v == 0)
//					break;
//			for (--i; i <= r; i += v)
//				a[i] /= v;
//		}
//		else if (opt == 2)
//		{
//			long long sum = 0;
//			cin >> l >> r;
//			for (size_t i = l; i <= r; i++)
//				sum += a[i];
//			cout << sum << endl;
//		}
//	}
//    return 0;
//}

