// Solving the root of the equation.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <iomanip>
using namespace std;
#define EPS 1e-6

double f(double x)
{
	return x * x * x - 5 * x * x + 10 * x - 80;
}


int main()
{
	double x1 = 0, x2 = 10;
	double mid = 0;
	while (abs(x1 - x2) > EPS)
	{
		mid = x1 + (x2 - x1) / 2.0;
		if (f(mid) >= 0)
			x2 = mid;
		else
			x1 = mid;
	}
	cout << setiosflags(ios::fixed) << setprecision(4) << mid << endl;
	return 0;
}

























//int main()
//{
//	int times = 1;
//	double x0 = 0;
//	double x1 = 100;
//	double y;
//	double mid = x0 + (x1 - x0) / 2;
//	while (fabs(f(mid)) > EPS)
//	{
//		times++;
//		if (f(mid) > 0)
//			x1 = mid;
//		else
//			x0 = mid;
//		mid = x0 + (x1 - x0) / 2;
//	}
//	cout << mid << endl;
//	cout << times << endl;
//	system("pause");
//    return 0;
//}

