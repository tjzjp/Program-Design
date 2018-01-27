// Count 24 Points.cpp: 定义控制台应用程序的入口点。
//

//Sample
//5 5 5 1
//1 1 4 2
//0 0 0 0
//YES
//NO

#include "stdafx.h"
#include <iostream>
using namespace std;

#define eps 1e-5
double a[5];

bool isZero(double a)
{
	return fabs(a) <= eps;
}

bool count24(double a[], int n)
{
	if (n == 1)
	{
		if (isZero(a[0] - 24))
			return true;
		else
			return false;
	}
	double b[5];
	for (int i = 0; i < n; i++)
		for (int j = i + 1; j < n; j++)
		{			
			int k = 0;
			for (int m = 0; m < n; m++)
				if (m != i && m != j)
					b[k++] = a[m];
			b[k] = a[i] + a[j];
			if (count24(b, k + 1))
				return true;
			b[k] = a[i] - a[j];
			if (count24(b, k + 1))
				return true;
			b[k] = a[j] - a[i];
			if (count24(b, k + 1))
				return true;
			b[k] = a[i] * a[j];
			if (count24(b, k + 1))
				return true;
			if (!isZero(a[j]))
			{
				b[k] = a[i] / a[j];
				if (count24(b, k + 1))
					return true;
			}
			if (!isZero(a[i]))
			{
				b[k] = a[j] / a[i];
				if (count24(b, k + 1))
					return true;
			}			
		}
	return false;
}


int main()
{
	while (cin >> a[0] >> a[1] >> a[2] >> a[3] && a[0] != 0)
	{
		if (count24(a, 4))
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	
    return 0;
}

