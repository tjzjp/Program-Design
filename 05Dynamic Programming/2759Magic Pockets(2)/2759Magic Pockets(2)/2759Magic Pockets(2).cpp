// 2759Magic Pockets(2).cpp: 定义控制台应用程序的入口点。
//

//描述
//有一个神奇的口袋，总的容积是400，用这个口袋可以变出一些物品，这些物品的总体积必须是400。
//John现在有n个想要得到的物品，每个物品的体积分别是a1，a2……an。
//John可以从这些物品中选择一些，如果选出的物体的总体积是400，那么利用这个神奇的口袋，John就可以得到这些物品。
//现在的问题是，John有多少种不同的选择物品的方式。
//输入
//输入的第一行是正整数n(1 <= n <= 200)，表示不同的物品的数目。
//接下来的n行，每行有一个1到400之间的正整数，分别给出a1，a2……an的值。
//输出
//输出不同的选择物品的方式的数目对10000取模的结果（因为结果可能很大，为了避免高精度计算，只要求对10000取模的结果）。
//样例输入
//3
//200
//200
//200
//样例输出
//3

#include "stdafx.h"
#include <iostream>
#include <cstring>
using namespace std;

int n;
int a[210];
int ways[410][210];

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
	for (int i = 1; i <= 400; i++)
		for (int j = 1; j <= n; j++)
		{
			ways[i][j] = ways[i][j - 1];
			if (i >= a[j])
				ways[i][j] = (ways[i - a[j]][j - 1] + ways[i][j]) % 10000;

		}
	cout << ways[400][n] << endl;
    return 0;
}

