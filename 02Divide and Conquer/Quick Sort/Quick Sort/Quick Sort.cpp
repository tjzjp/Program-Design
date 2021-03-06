// Quick Sort.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
using namespace std;

int a[] = {93, 27, 30, 2, 8, 12, 2, 8, 39, 89};

void swap(int &a, int &b)
{
	int t;
	t = a;
	a = b; 
	b = t;
}

void Quick(int a[], int b, int e)
{
	if (b >= e)
		return;
	int x = a[b];
	int i = b;
	int j = e;
	while (i != j)
	{
		while (j > i && a[j] >= x)
			j--;
		swap(a[i], a[j]);
		while (j > i && a[i] <= x)
			i++;
		swap(a[i], a[j]);
	}
	
	Quick(a, b, i - 1);
	Quick(a, i + 1, e);
}


int main()
{
	int size = sizeof(a) / sizeof(int);
	Quick(a, 0, size - 1);
	for (int i = 0; i <= size - 1; i++)
		cout << a[i] << ' ';
	cout << endl;

	return 0;
}




























//void swap(int & a, int & b)
//{
//	int t = a;
//	a = b;
//	b = t;
//}
//
//void Quick(int a[], int s, int e)
//{
//	if (s >= e)
//		return;
//	int k = a[s];
//	int i = s, j = e;
//	while (i != j)
//	{
//		while (j > i && k <= a[j])
//			j--;
//		swap(a[i], a[j]);
//		while (i < j && k >= a[i])
//			i++;
//		swap(a[i], a[j]);
//	}
//	Quick(a, s, i - 1);
//	Quick(a, i + 1, e);
//}
//
//int main()
//{
//	int size = sizeof(a) / sizeof(int);
//	Quick(a, 0, size - 1);
//	for (int i = 0; i < size; i++)
//		cout << a[i] << " ";
//	cout << endl;
//	system("pause");
//    return 0;
//}

