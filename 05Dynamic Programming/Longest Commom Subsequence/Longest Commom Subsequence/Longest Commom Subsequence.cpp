// Longest Commom Subsequence.cpp: 定义控制台应用程序的入口点。
//

//描述
//我们称序列Z = < z1, z2, ..., zk >是序列X = < x1, x2, ..., xm >的子序列
//当且仅当存在 严格上升 的序列< i1, i2, ..., ik >，使得对j = 1, 2, ..., k, 有xij = zj。
//比如Z = < a, b, f, c > 是X = < a, b, c, f, b, c >的子序列。
//
//现在给出两个序列X和Y，你的任务是找到X和Y的最大公共子序列，也就是说要找到一个最长的序列Z，使得Z既是X的子序列也是Y的子序列。
//输入
//输入包括多组测试数据。每组数据包括一行，给出两个长度不超过200的字符串，表示两个序列。两个字符串之间由若干个空格隔开。
//输出
//对每组输入数据，输出一行，给出两个序列的最大公共子序列的长度。
//样例输入
//abcfbc         abfcab
//programming    contest
//abcd           mnp
//样例输出
//4
//2
//0

#include "stdafx.h"
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

char s1[210], s2[210];
int maxn[210][210];

int main()
{
	while (cin >> s1 >> s2)
	{
		int len1 = strlen(s1);
		int len2 = strlen(s2);
		memset(maxn, 0, sizeof(maxn));
		for (int i = 1; i <= len1; i++)
			for (int j = 1; j <= len2; j++)
			{
				if (s1[i - 1] == s2[j - 1])
					maxn[i][j] = maxn[i - 1][j - 1] + 1;
				else
					maxn[i][j] = max(maxn[i - 1][j], maxn[i][j - 1]);
			}
		cout << maxn[len1][len2] << endl;
	}
	return 0;
}

























//#include <iostream>
//#include <algorithm>
//using namespace std;
//const int MAX = 1000;
//char s1[MAX];
//char s2[MAX];
//int maxLen[MAX][MAX];
//
//int main()
//{
//	while (cin >> s1 >> s2)
//	{
//		int len1 = strlen(s1);
//		int len2 = strlen(s2);
//		for (int i = 0; i <= len1; i++)
//			maxLen[i][0] = 0;
//		for (int i = 0; i <= len2; i++)
//			maxLen[0][i] = 0;
//		for (int i = 1; i <= len1; i++)
//			for (int j = 1; j <= len2; j++)
//			{
//				if (s1[i - 1] == s2[j - 1])
//					maxLen[i][j] = maxLen[i - 1][j - 1] + 1;
//				else
//					maxLen[i][j] = max(maxLen[i - 1][j], maxLen[i][j - 1]);
//			}
//		cout << maxLen[len1][len2] << endl;
//	}
//    return 0;
//}
//
