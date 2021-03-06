// Merge Sort.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
using namespace std;

int a[10] = { 13, 27, 19, 2, 8, 12, 2, 8, 30, 89 };
int b[10];

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
	for (int c = 0; c < e - b + 1; c++)
		a[b + c] = temp[c];
}

void mergesort(int a[], int b, int e, int temp[])
{
	int m = b + (e - b) / 2;
	if (b < e)
	{
		mergesort(a, b, m, temp);
		mergesort(a, m + 1, e, temp);
		merge(a, b, e, m, temp);
	}
}

int main()
{
	int size = sizeof(a) / sizeof(int);
	mergesort(a, 0, size - 1, b);
	for (int i = 0; i < size - 1; i++)
		cout << a[i] << " ";
	cout << endl;
	return 0;
}
































//void Merge(int a[], int s, int m, int e, int temp[])
//{
//	int pb = 0;
//	int p1 = s;
//	int p2 = m + 1;
//	while (p1 <= m && p2 <= e)
//	{
//		if (a[p1] < a[p2])
//		{
//			temp[pb] = a[p1];
//			pb++;
//			p1++;
//		}
//		else
//		{
//			temp[pb++] = a[p2++];
//		}
//	}
//	while (p1 <= m)
//	{
//		temp[pb++] = a[p1++];
//	}
//	while (p2 <= e)
//	{
//		temp[pb++] = a[p2++];
//	}
//	for (int i = 0; i <= (e - s); i++)
//	{
//		a[s + i] = temp[i];
//	}
//}
//
//void MergeSort(int a[], int s, int e, int temp[])
//{
//	if (s < e)
//	{
//		int m = s + (e - s) / 2;
//		MergeSort(a, s, m, temp);
//		MergeSort(a, m + 1, e, temp);
//		Merge(a, s, m, e, temp);
//	}	
//}
//
//int main()
//{
//	int size = sizeof(a) / sizeof(int);
//	MergeSort(a, 0, size - 1, b);
//	for (int i = 0; i < size; i++)
//	{
//		cout << a[i] << " ";
//	}
//	cout << endl;
//	system("pause");
//    return 0;
//}

