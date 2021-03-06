// Best Addition Equalition.cpp: 定义控制台应用程序的入口点。
//

//描述
//给定n个1到9的数字，要求在数字之间摆放m个加号(加号两边必须有数字），使得所得到的加法表达式的值最小，并输出该值。
//例如，在1234中摆放1个加号，最好的摆法就是12 + 34, 和为36
//	输入
//	有不超过15组数据
//	每组数据两行。第一行是整数m，表示有m个加号要放(0 <= m <= 50)
//	第二行是若干个数字。数字总数n不超过50, 且 m <= n - 1
//	输出
//	对每组数据，输出最小加法表达式的值
//	样例输入
//	2
//	123456
//	1
//	123456
//	4
//	12345
//	样例输出
//	102
//	579
//	15

#include "stdafx.h"
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

struct BigInt
{
	int num[110];
	int len;
	BigInt operator+ (const BigInt & n)
	{
		int ml = max(len, n.len);
		BigInt result;
		int carry = 0;
		for (int i = 0; i < ml; i++)
		{
			result.num[i] = num[i] + n.num[i] + carry;
			if (result.num[i] >= 10)
			{
				result.num[i] -= 10;
				carry = 1;
			}
			else
				carry = 0;
		}
		if (carry == 1)
		{
			result.len = ml + 1;
			result.num[ml] = 1;
		}
		else
			result.len = ml;
		return result;
	}

	bool operator< (const BigInt & n)
	{
		if (len < n.len)
			return true;
		else if (len > n.len)
			return false;
		else
		{
			for (int i = len - 1; i >= 0; i--)
			{
				if (num[i] < n.num[i])
					return true;
				else if (num[i] > n.num[i])
					return false;
			}
			return false;
		}	
	}

	BigInt()
	{
		len = 1;
		memset(num, 0, sizeof(num));
	}

	BigInt(const char * n, int L)
	{
		memset(num, 0, sizeof(num));
		len = L;
		for (int i = 0; n[i]; i++)
			num[len - i - 1] = n[i] - '0';
	}

};



ostream & operator<<(ostream & o, const BigInt & n)
{
	for (int i = n.len - 1; i >= 0; i--)
	{
		o << n.num[i];
	}
	return o;
}

const int MAXN = 60;
char c[MAXN];
BigInt Num[MAXN][MAXN];
BigInt V[MAXN][MAXN];

int main()
{
	int m, n;
	BigInt inf;
	inf.len = MAXN - 1;
	inf.num[MAXN - 2] = 1;
	while (cin >> m)
	{
		cin >> c + 1;
		int n = strlen(c + 1);
		for (int i = 1; i <= n; i++)
			for (int j = i; j <= n; j++)
				Num[i][j] = BigInt(c + i, j - i + 1);
		for (int i = 1; i <= n; i++)
			V[0][i] = BigInt(c + 1, i);

		for (int i = 1; i <= m; i++)
			for (int j = 1; j <= n; j++)
			{
				if (i > j - 1)
					V[i][j] = inf;
				else
				{
					BigInt tempMin = inf;
					for (int k = i; k < j; k++)
					{
						BigInt t = V[i - 1][k] + Num[k + 1][j];
						if (t < tempMin)
							tempMin = t;
					}
					V[i][j] = tempMin;
				}
			}
		cout << V[m][n] << endl;
	}
		return 0;
}

























//#include <iostream>
//#include <algorithm>
//#include <cstring>
//using namespace std;
//
//struct BigInt
//{
//	int num[110];
//	int len;
//	BigInt operator+(const BigInt & n)
//	{
//		int ml = max(len, n.len);
//		BigInt result;
//		int carry = 0;
//		for (int i = 0; i < ml; i++)
//		{
//			result.num[i] = num[i] + n.num[i] + carry;
//			if (result.num[i] >= 10)
//			{
//				carry = 1;
//				result.num[i] -= 10;
//			}
//			else
//				carry = 0;
//		}
//		if (carry == 1)
//		{
//			result.len = ml + 1;
//			result.num[ml] = 1;
//		}
//		else
//			result.len = ml;
//		return result;
//	}
//
//	bool operator<(const BigInt & n)
//	{
//		if (len < n.len)
//			return true;
//		else if (len > n.len)
//			return false;
//		else
//		{
//			for (int i = len - 1; i >= 0; i--)
//			{
//				if (num[i] < n.num[i])
//					return true;
//				else if (num[i] > n.num[i])
//					return false;
//			}
//			return false;
//		}		
//	}
//
//	BigInt()
//	{
//		len = 1;
//		memset(num, 0, sizeof(num));
//	}
//
//	BigInt(const char * n, int L)
//	{
//		memset(num, 0, sizeof(num));
//		len = L;
//		for (int i = 0; n[i]; i++)
//		{
//			num[len - i - 1] = n[i] - '0';
//		}
//	}
//};
//
//ostream & operator <<(ostream & o, const BigInt & n)
//{
//	for (int i = n.len - 1; i >= 0; i--)
//		o << n.num[i];
//	return o;
//}
//
//const int MAXN = 60;
//char c[MAXN];
//BigInt V[MAXN][MAXN]; 
//BigInt Num[MAXN][MAXN];
//
//int main()
//{
//	int m, n;
//	BigInt inf;
//	inf.len = MAXN - 1;
//	inf.num[MAXN - 2] = 1;
//
//	while (cin >> m)
//	{
//		cin >> c + 1;
//		n = strlen(c + 1);
//		for (int i = 1; i <= n; i++)
//			for (int j = i; j <= n; j++)
//			{
//				Num[i][j] = BigInt(c + i, j - i + 1);
//			}
//		for (int i = 1; i <= n; i++)
//			V[0][i] = BigInt(c + 1, i);
//		for (int i = 1; i <= m; i++)
//			for (int j = 1; j <= n; j++)
//			{
//				if (i > j - 1)
//					V[i][j] = inf;
//				else
//				{
//					BigInt tmpMin = inf;
//					for (int k = i; k < j; k++)
//					{
//						BigInt tmp = V[i - 1][k] + Num[k + 1][j];
//						if (tmp < tmpMin)
//							tmpMin = tmp;
//					}
//					V[i][j] = tmpMin;
//				}
//			}
//		cout << V[m][n] << endl;
//	}
//    return 0;
//}
//
