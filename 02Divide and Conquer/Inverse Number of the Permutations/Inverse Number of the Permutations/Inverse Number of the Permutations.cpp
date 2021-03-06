// Inverse Number of the Permutations.cpp: 定义控制台应用程序的入口点。
//

//描述
//在Internet上的搜索引擎经常需要对信息进行比较，
//比如可以通过某个人对一些事物的排名来估计他（或她）对各种不同信息的兴趣，从而实现个性化的服务。
//对于不同的排名结果可以用逆序来评价它们之间的差异。
//考虑1, 2, …, n的排列i1，i2，…，in，如果其中存在j, k，满足 j < k 且 ij > ik， 
//那么就称(ij, ik)是这个排列的一个逆序。
//一个排列含有逆序的个数称为这个排列的逆序数。
//例如排列 263451 含有8个逆序(2, 1), (6, 3), (6, 4), (6, 5), (6, 1), (3, 1), (4, 1), (5, 1)，
//因此该排列的逆序数就是8。显然，由1, 2, …, n 构成的所有n!个排列中，最小的逆序数是0，
//对应的排列就是1, 2, …, n；最大的逆序数是n(n - 1) / 2，对应的排列就是n, (n - 1), …, 2, 1。
//逆序数越大的排列与原始排列的差异度就越大。
//现给定1, 2, …, n的一个排列，求它的逆序数。
//
//
//输入
//第一行是一个整数n，表示该排列有n个数（n <= 100000)。
//第二行是n个不同的正整数，之间以空格隔开，表示该排列。
//输出
//输出该排列的逆序数。
//样例输入
//6
//2 6 3 4 5 1
//样例输出
//8

//提示
//1. 利用二分归并排序算法（分治）；
//2. 注意结果可能超过int的范围，需要用long long存储。

#include "stdafx.h"
#include <iostream>
using namespace std;

int n;
int a[100010];
int temp[100010];

void merge(int a[], int b, int e, int m, int temp[])
{
	int i = b;
	int j = m + 1;
	int k = 0;
	while (i <= m && j <= e)
	{
		if (a[i] < a[j])
			temp[k++] = a[i++];
		else
			temp[k++] = a[j++];
	}
	while (i <= m)
		temp[k++] = a[i++];
	while (j <= e)
		temp[k++] = a[j++];
	for (int c = 0; c < (e - b + 1); c++)
		a[c + b] = temp[c];
}

long long Count(int a[], int b, int e, int m)
{
	long long count = 0;
	int i = b;
	int j = m + 1;
	while (i <= m && j <= e)
	{
		if (a[i] > a[j])
		{
			count += m - i + 1;
			j++;
		}
		else
			i++;
	}
	return count;
}

long long mergesort(int a[], int b, int e, int temp[])
{
	long long count = 0;
	int m = b + (e - b) / 2;
	if (b < e)
	{
		count += mergesort(a, b, m, temp);
		count += mergesort(a, m + 1, e, temp);
		count += Count(a, b, e, m);
		merge(a, b, e, m, temp);
	}
	return count;
}

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	long long count = 0;
	count += mergesort(a, 0, n - 1, temp);
	cout << count << endl;

	return 0;
}




































//#include <iostream>
//#include <algorithm>
//using namespace std;
//
//int a[100100];
//int b[100100];
//int N;
//
//void Merge(int a[], int s, int m, int e, int temp[])
//{
//	int pb = 0;
//	int p1 = s, p2 = m + 1;
//	while (p1 <= m && p2 <= e)
//	{
//		if (a[p1] <= a[p2])
//			temp[pb++] = a[p1++];
//		else
//			temp[pb++] = a[p2++];
//	}
//	while (p1 <= m)
//		temp[pb++] = a[p1++];
//	while (p2 <= e)
//		temp[pb++] = a[p2++];
//	for (int i = 0; i < e - s + 1; i++)
//		a[s + i] = temp[i];
//}
//
//long long Count(int a[], int s, int m, int e)
//{
//	long long count = 0;
//	int i = s;
//	int j = m + 1;
//	while (i <= m && j <= e)
//	{
//		if (a[i] > a[j])
//		{
//			count += m - i + 1;
//			j++;
//		}
//		else
//		{
//			i++;
//		}
//	}
//	return count;
//}
//
//long long Mergesort(int a[], int s, int e, int temp[])
//{
//	long long count = 0;
//	if (s < e)
//	{
//		int m = s + (e - s) / 2;
//		count += Mergesort(a, s, m, temp);
//		count += Mergesort(a, m + 1, e, temp);
//		count += Count(a, s, m, e);	
//		Merge(a, s, m, e, temp);
//	}		
//	return count;
//}
//
//int main()
//{
//	long long count = 0;
//	cin >> N;
//	for (int i = 0; i < N; i++)
//	{
//		cin >> a[i];
//	}
//	count = Mergesort(a, 0, N - 1, b);
//	cout << count << endl;
//	system("pause");
//    return 0;
//}
//
