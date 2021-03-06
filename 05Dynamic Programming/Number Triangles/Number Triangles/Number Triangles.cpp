// Number Triangles.cpp: 定义控制台应用程序的入口点。
//

//问题具有最优子结构性质
//无后效性

//描述
//7
//3   8
//8   1   0
//2   7   4   4
//4   5   2   6   5
//
//(图1)
//
//图1给出了一个数字三角形。从三角形的顶部到底部有很多条不同的路径。
//对于每条路径，把路径上面的数加起来可以得到一个和，你的任务就是找到最大的和。
//
//注意：路径上的每一步只能从一个数走到下一层上和它最近的左边的那个数或者右边的那个数。
//输入
//输入的是一行是一个整数N(1 < N <= 100)，给出三角形的行数。下面的N行给出数字三角形。
//数字三角形上的数的范围都在0和100之间。
//	输出
//	输出最大的和。
//	样例输入
//	5
//	7
//	3 8
//	8 1 0
//	2 7 4 4
//	4 5 2 6 5
//	样例输出
//	30

#include "stdafx.h"
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int n;
int a[110][110];
int manx[110][110];

int main()
{
	cin >> n;
	memset(manx, 0, sizeof(manx));
	memset(a, 0, sizeof(a));
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= i; j++)
			cin >> a[i][j];
	for (int i = 1; i<= n; i++)
		for (int j = 1; j <= i; j++)
		{
			manx[i][j] = max(manx[i - 1][j] + a[i][j], manx[i - 1][j - 1] + a[i][j]);
		}
	cout << *max_element(manx[n] + 1, manx[n] + n + 1) << endl;
	return 0;
}




























//#include <iostream>
//#include <algorithm>
//using namespace std;
//
//const int MAX = 101;
//int D[MAX][MAX];
//int * maxsum;
//int n;
//
//int main()
//{
//	cin >> n;
//	for (int i = 0; i < n; i++)
//		for (int j = 0; j <= i; j++)
//			cin >> D[i][j];
//	maxsum = D[n - 1];
//	for (int i = n - 2; i >= 0; i--)
//		for (int j = 0; j <= i; j++)
//			maxsum[j] = max(maxsum[j], maxsum[j + 1]) + D[i][j];
//	cout << maxsum[0] << endl;
//	return 0;
//}

//const int MAX = 101;
//int n;
//int maxsum[MAX][MAX];
//int D[MAX][MAX];
//
//int sumMax(int i, int j)
//{
//	if (maxsum[i][j] != -1)
//		return maxsum[i][j];
//	if (i == n)
//		maxsum[i][j] = D[i][j];
//	else
//	{
//		int x = sumMax(i + 1, j);
//		int y = sumMax(i + 1, j + 1);
//		maxsum[i][j] = max(x, y) + D[i][j];
//	}
//	return maxsum[i][j];
//}
//
//int main()
//{
//	cin >> n;
//	for (int i = 0; i <= n; i++)
//		for (int j = 0; j <= i; j++)
//		{
//			cin >> D[i][j];
//			maxsum[i][j] = -1;
//		}
//	cout << sumMax(0, 0) << endl;
//	system("pause");
//    return 0;
//}

