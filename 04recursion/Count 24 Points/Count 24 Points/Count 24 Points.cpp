// Count 24 Points.cpp: 定义控制台应用程序的入口点。
//

//描述
//给出4个小于10个正整数，你可以使用加减乘除4种运算以及括号把这4个数连接起来得到一个表达式。
//现在的问题是，是否存在一种方式使得得到的表达式的结果等于24。
//
//这里加减乘除以及括号的运算结果和运算的优先级跟我们平常的定义一致（这里的除法定义是实数除法）。
//
//比如，对于5，5，5，1，我们知道5 * (5 – 1 / 5) = 24，因此可以得到24。又比如，对于1，1，4，2，我们怎么都不能得到24。
//输入
//输入数据包括多行，每行给出一组测试数据，包括4个小于10个正整数。最后一组测试数据中包括4个0，表示输入的结束，这组数据不用处理。
//输出
//对于每一组测试数据，输出一行，如果可以得到24，输出“YES”；否则，输出“NO”。
//样例输入
//5 5 5 1
//1 1 4 2
//0 0 0 0
//样例输出
//YES
//NO

#include "stdafx.h"
#include <iostream>
#include <cmath>
using namespace std;
#define EPS 1e-7

double a[5];

bool Count24(int k, double temp[])
{
	bool ans;
	if (k == 1)
	{
		if (fabs(temp[0] - 24) < EPS)
			return true;
		else
			return false;
	}
	double newtemp[5];
	for (int i = 0; i < k - 1; i++)
		for (int j = i + 1; j < k; j++)
		{
			int tt = 1;
			for (int m = 0; m < k; m++)
				if (m != i && m != j)
					newtemp[tt++] = temp[m];
			newtemp[0] = temp[i] + temp[j];
			if (Count24(k - 1, newtemp))
				return true;
			newtemp[0] = temp[i] - temp[j];
			if (Count24(k - 1, newtemp))
				return true;
			newtemp[0] = temp[j] - temp[i];
			if (Count24(k - 1, newtemp))
				return true;
			newtemp[0] = temp[i] * temp[j];
			if (Count24(k - 1, newtemp))
				return true;
			if (fabs(temp[j]) > EPS)
			{
				newtemp[0] = temp[i] / temp[j];
				if (Count24(k - 1, newtemp))
					return true;
			}
			if (fabs(temp[i]) > EPS)
			{
				newtemp[0] = temp[j] / temp[i];
				if (Count24(k - 1, newtemp))
					return true;
			}
		}
	return false;
}


int main()
{
	while (1)
	{
		for (int i = 0; i < 4; i++)
			cin >> a[i];
		if (a[0] == 0)
			break;
		if (Count24(4, a))
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	return 0;
}





























//#include <iostream>
//using namespace std;
//
//#define eps 1e-6
//double a[5];
//
//bool isZero(double b)
//{
//	if (fabs(b) <= eps)
//		return true;
//	else
//		return false;
//}
//
//bool Count24(double a[], int k)
//{
//	if (k == 1)
//	{
//		if (isZero(a[0] - 24))
//			return true;
//		else
//			false;
//	}
//	double b[5];
//	for (int i = 0; i < k; i++)
//		for (int j = i + 1; j < k; j++)
//		{
//			int n = 0;
//			for (int m = 0; m < k; m++)
//				if (m != i && m != j)
//					b[n++] = a[m];
//			b[n] = a[i] + a[j];
//			if (Count24(b, n + 1))
//				return true;
//			b[n] = a[i] - a[j];
//			if (Count24(b, n + 1))
//				return true;
//			b[n] = a[j] - a[i];
//			if (Count24(b, n + 1))
//				return true;
//			b[n] = a[i] * a[j];
//			if (Count24(b, n + 1))
//				return true;
//			if (!isZero(a[j]))
//			{
//				b[n] = a[i] / a[j];
//				if (Count24(b, n + 1))
//					return true;
//			}
//			if (!isZero(a[i]))
//			{
//				b[n] = a[j] / a[i];
//				if (Count24(b, n + 1))
//					return true;
//			}
//		}
//	return false;
//}
//
//int main()
//{
//	
//	while (cin >> a[0] >> a[1] >> a[2] >> a[3] && (a[0] != 0 && a[1] != 0 && a[2] != 0 && a[3] != 0))
//	{
//		if (Count24(a, 4))
//			cout << "YES" << endl;
//		else
//			cout << "NO" << endl;
//	}	
//	system("pause");
//	return 0;
//}


//#define eps 1e-5
//double a[5];
//
//bool isZero(double a)
//{
//	return fabs(a) <= eps;
//}
//
//bool count24(double a[], int n)
//{
//	if (n == 1)
//	{
//		if (isZero(a[0] - 24))
//			return true;
//		else
//			return false;
//	}
//	double b[5];
//	for (int i = 0; i < n; i++)
//		for (int j = i + 1; j < n; j++)
//		{			
//			int k = 0;
//			for (int m = 0; m < n; m++)
//				if (m != i && m != j)
//					b[k++] = a[m];
//			b[k] = a[i] + a[j];
//			if (count24(b, k + 1))
//				return true;
//			b[k] = a[i] - a[j];
//			if (count24(b, k + 1))
//				return true;
//			b[k] = a[j] - a[i];
//			if (count24(b, k + 1))
//				return true;
//			b[k] = a[i] * a[j];
//			if (count24(b, k + 1))
//				return true;
//			if (!isZero(a[j]))
//			{
//				b[k] = a[i] / a[j];
//				if (count24(b, k + 1))
//					return true;
//			}
//			if (!isZero(a[i]))
//			{
//				b[k] = a[j] / a[i];
//				if (count24(b, k + 1))
//					return true;
//			}			
//		}
//	return false;
//}
//
//
//int main()
//{
//	while (cin >> a[0] >> a[1] >> a[2] >> a[3] && a[0] != 0)
//	{
//		if (count24(a, 4))
//			cout << "YES" << endl;
//		else
//			cout << "NO" << endl;
//	}
//	
//    return 0;
//}

