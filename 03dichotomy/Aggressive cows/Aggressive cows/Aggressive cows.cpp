// Aggressive cows.cpp: 定义控制台应用程序的入口点。
//

//描述
//Farmer John has built a new long barn, with N(2 <= N <= 100, 000) stalls.
//The stalls are located along a straight line at positions x1, ..., xN(0 <= xi <= 1, 000, 000, 000).
//
//His C(2 <= C <= N) cows don't like this barn layout and become aggressive towards each other once put into a stall. 
//To prevent the cows from hurting each other, FJ want to assign the cows to the stalls, such that the minimum distance 
//between any two of them is as large as possible. What is the largest minimum distance?
//输入
//* Line 1: Two space - separated integers : N and C
//
//* Lines 2..N + 1 : Line i + 1 contains an integer stall location, xi
//输出
//* Line 1 : One integer : the largest minimum distance
//样例输入
//5 3
//1
//2
//8
//4
//9
//样例输出
//3

#include "stdafx.h"
#include <iostream>
#include <algorithm>
using namespace std;


int N;
long long a[100100];
int C;

bool isValid(int d)
{
	int last = a[0];
	int settled = 1;
	for (int i = 0; i < N; i++)
	{
		if (a[i] - last >= d)
		{
			settled++;
			last = a[i];
			
		}
		if (settled >= C)
			return true;
	}
	return false;
}

int main()
{
	cin >> N;
	cin >> C;
	for (int i = 0; i < N; i++)
		cin >> a[i];
	sort(a, a + N);

	int L = a[0];
	int R = a[N - 1] / C + 1;
	int lastvalid = 0;
	while (L <= R)
	{
		int mid = L + (R - L) / 2;
		if (isValid(mid))
		{
			L = mid + 1;
			lastvalid = mid;
		}
			
		else
			R = mid - 1;
	}
	cout << lastvalid << endl;
	return 0;
}






































//#include <iostream>
//#include <algorithm>
//using namespace std;
//
//const int M = 1000000;
//int X[M];
//int N, C;
//
//bool valid(int d)
//{
//	int settled = 1;
//	int last = X[0];
//	for (int i = 0; i < N; i++)
//	{
//		if ((X[i] - last) >= d)
//		{
//			settled++;
//			last = X[i];
//			if (settled >= C)
//				return true;
//		}
//	}
//	return false;
//}
//
//int main()
//{	
//	cin >> N >> C;
//	for (int i = 0; i < N; i++)
//	{
//		cin >> X[i];
//	}
//	sort(X, X + N);
//	int L = X[0];
//	int R = X[N - 1] / C + 1;
//	int lastValid = 0;
//	while (L <= R)
//	{
//		int mid = L + (R - L) / 2;
//		if (valid(mid))
//		{
//			lastValid = mid;
//			L = mid + 1;
//		}
//		else
//			R = mid - 1;
//	}
//	cout << lastValid << endl;
//	system("pause");
//    return 0;
//}

