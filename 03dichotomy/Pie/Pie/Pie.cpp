// Pie.cpp: 定义控制台应用程序的入口点。
//

//描述
//我的生日要到了！根据习俗，我需要将一些派分给大家。我有N个不同口味、不同大小的派。有F个朋友会来参加我的派对，
//每个人会拿到一块派（必须一个派的一块，不能由几个派的小块拼成；可以是一整个派）。
//我的朋友们都特别小气，如果有人拿到更大的一块，就会开始抱怨。因此所有人拿到的派是同样大小的（但不需要是同样形状的），
//虽然这样有些派会被浪费，但总比搞砸整个派对好。当然，我也要给自己留一块，而这一块也要和其他人的同样大小。
//
//请问我们每个人拿到的派最大是多少？每个派都是一个高为1，半径不等的圆柱体。
//输入
//第一行包含两个正整数N和F，1 ≤ N, F ≤ 10 000，表示派的数量和朋友的数量。
//第二行包含N个1到10000之间的整数，表示每个派的半径。
//输出
//输出每个人能得到的最大的派的体积，精确到小数点后三位。
//样例输入
//3 3
//4 3 3
//样例输出
//25.133

#include "stdafx.h"
#include <iostream>
#include <algorithm>
#include <cmath>
#include <iomanip>
using namespace std;
#define EPS 1e-6
const double PI = acos(-1.0);

int N, F;
int a[10010];

bool isvalid(double d)
{
	int settled = 0;
	if (d < EPS)
		return true;
	for (int i = 0; i < N; i++)
	{
		double t = a[i];
		while (t >= d)
		{
			settled++;
			t = t - d;
		}
	}
	if (settled >= F + 1)
		return true;
	else
		return false;
}

int main()
{
	cin >> N >> F;
	int temp;
	for (int i = 0; i < N; i++)
	{
		cin >> temp;
		a[i] = temp * temp;
	}
	sort(a, a + N);
	double L = 0;
	double R = a[N - 1];
	double ans = 0;
	while ((R - L) > EPS)
	{
		double mid = L + (R - L) / 2.0;
		if (isvalid(mid))
		{
			L = mid;
			ans = mid;
		}
		else
			R = mid;
	}
	
	cout << setiosflags(ios::fixed) << setprecision(3) << L * PI << endl;

	return 0;
}



































//#include <iostream>
//#include <algorithm>
//#include <iomanip>
//using namespace std;
//#define EPS 1e-6
//const double PI = acos(-1.0); //错在这里
//
//int N, F;
//int X[10010];
//int Y[10010];
//
//bool Valid(double n)
//{
//	if (n < EPS)
//		return true;
//	int settled = 0;
//	for (int i = 0; i < N; i++)
//	{
//		double count = Y[i] / n;
//		settled += count;
//		if (settled >= F)
//			return true;
//	}
//	return false;
//}
//
//int main()
//{
//	cin >> N >> F;
//	++F;
//	for (int i = 0; i < N; i++)
//	{
//		cin >> X[i];
//	}
//	sort(X, X + N);
//	for (int i = 0; i < N; i++)
//		Y[i] = X[i] * X[i];
//	double L = 0, R = Y[N - 1];	
//	double lastValid = 0;
//	while ((R - L) > EPS)
//	{
//		double mid = L + (R - L) / 2;
//		if (Valid(mid))
//		{
//			lastValid = mid;
//			L = mid;
//		}
//		else
//			R = mid;
//	}
//	cout << setiosflags(ios::fixed) << setprecision(3) << L * PI;
//	system("pause");
//    return 0;
//}
//
