// Longest Increasing Subsequence.cpp: 定义控制台应用程序的入口点。
//

//描述
//一个数的序列bi，当b1 < b2 < ... < bS的时候，我们称这个序列是上升的。
//对于给定的一个序列(a1, a2, ..., aN)，我们可以得到一些上升的子序列(ai1, ai2, ..., aiK)，
//这里1 <= i1 < i2 < ... < iK <= N。
//比如，对于序列(1, 7, 3, 5, 9, 4, 8)，有它的一些上升子序列，如(1, 7), (3, 4, 8)等等。
//这些子序列中最长的长度是4，比如子序列(1, 3, 5, 8).
//
//	你的任务，就是对于给定的序列，求出最长上升子序列的长度。
//	输入
//	输入的第一行是序列的长度N(1 <= N <= 1000)。第二行给出序列中的N个整数，这些整数的取值范围都在0到10000。
//	输出
//	最长上升子序列的长度。
//	样例输入
//	7
//	1 7 3 5 9 4 8
//	样例输出
//	4


#include "stdafx.h"
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int a[1010];
int n;
int maxn[1010];

int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		maxn[i] = 1;
	}
		
	for (int i = 1; i < n; i++)
		for (int j = i + 1; j <= n; j++)
		{
			if (a[j] > a[i])
				maxn[j] = max(maxn[j], maxn[i] + 1);
		}
		
	cout << *max_element(maxn + 1, maxn + n + 1) << endl;
	return 0;
}




































//#include <iostream>
//#include <algorithm>
//using namespace std;
//
//const int MAXN = 1010;
//int maxLen[MAXN], a[MAXN], n;
//
//int main()
//{
//	cin >> n;
//	for (int i = 0; i < n; i++)
//	{
//		cin >> a[i];
//		maxLen[i] = 1;
//	}
//	for (int j = 1; j < n; j++)
//		for (int k = 0; k <= j; k++)
//		{
//			if (a[j] > a[k])
//				maxLen[j] = max(maxLen[k] + 1, maxLen[j]);
//		}
//	cout << *max_element(maxLen, maxLen + n) << endl;;
//    return 0;
//}
//
