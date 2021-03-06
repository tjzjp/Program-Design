// Magic Pocket.cpp: 定义控制台应用程序的入口点。
//

//描述
//有一个神奇的口袋，总的容积是40，用这个口袋可以变出一些物品，这些物品的总体积必须是40。
//John现在有n个想要得到的物品，每个物品的体积分别是a1，a2……an。
//John可以从这些物品中选择一些，如果选出的物体的总体积是40，那么利用这个神奇的口袋，
//John就可以得到这些物品。现在的问题是，John有多少种不同的选择物品的方式。
//输入
//输入的第一行是正整数n(1 <= n <= 20)，表示不同的物品的数目。
//接下来的n行，每行有一个1到40之间的正整数，分别给出a1，a2……an的值。
//输出
//输出不同的选择物品的方式的数目。
//样例输入
//3
//20
//20
//20
//样例输出
//3

#include "stdafx.h"
#include <iostream>
#include <cstring>
using namespace std;

int n;
int a[25];
int ways[50][25];

int main()
{
	cin >> n;
	memset(ways, 0, sizeof(ways));
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		ways[0][i] = 1;
	}
	ways[0][0] = 1;
	for (int i = 1; i <= 40; i++)
		for (int j = 1; j <= n; j++)
		{
			ways[i][j] = ways[i][j - 1];
			if (a[j] <= i)
				ways[i][j] = ways[i][j] + ways[i - a[j]][j - 1];
		}
	cout << ways[40][n] << endl;
	return 0;
}






























//#include <iostream>
//#include <cstring>
//using namespace std;
//
//int a[30];
//int n;
//int Ways[50][40];
//
//int main()
//{
//	cin >> n;
//	memset(Ways, 0, sizeof(Ways));
//	for (int i = 1; i <= n; i++)
//	{
//		cin >> a[i];
//		Ways[0][i] = 1;
//	}
//	Ways[0][0] = 1;
//	for (int w = 1; w <= 40; w++)
//		for (int k = 1; k <= n; k++)
//		{
//			Ways[w][k] = Ways[w][k - 1];
//			if (w - a[k] >= 0)
//				Ways[w][k] = Ways[w][k] + Ways[w - a[k]][k - 1];
//		}
//	cout << Ways[40][n];
//    return 0;
//}

