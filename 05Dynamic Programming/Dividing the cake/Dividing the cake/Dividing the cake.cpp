// Dividing the cake.cpp: 定义控制台应用程序的入口点。
//

//描述
//有一块矩形大蛋糕，长和宽分别是整数w 、h。现要将其切成m块小蛋糕，每个小蛋糕都必须是矩形、且长和宽均为整数。
//切蛋糕时，每次切一块蛋糕，将其分成两个矩形蛋糕。请计算：最后得到的m块小蛋糕中，最大的那块蛋糕的面积下限。
//假设w = 4, h = 4, m = 4，则下面的切法可使得其中最大蛋糕块的面积最小。
//
//假设w = 4, h = 4, m = 3，则下面的切法会使得其中最大蛋糕块的面积最小:
//
//
//输入
//共有多行，每行表示一个测试案例。
//每行是三个用空格分开的整数w, h, m ，其中1 ≤ w, h, m ≤ 20 ， m ≤ wh.当 w = h = m = 0 时不需要处理，表示输入结束。
//输出
//每个测试案例的结果占一行，输出一个整数，表示最大蛋糕块的面积下限。
//样例输入
//4 4 4
//4 4 3
//0 0 0
//样例输出
//4
//6

#include "stdafx.h"
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int w, h, m;
int top = 410;
int f[25][25][25];

void cake(int w, int h, int m)
{
	for (int i = 1; i <= w; i++)
		for (int j = 1; j <= h; j++)
		{
			f[i][j][1] = i * j;
			for (int k = 2; k <= m; k++)
			{
				f[i][j][k] = top;
				for (int r = 1; r < i; r++)
				{
					f[i][j][k] = min(f[i][j][k], max(f[r][j][k - 1], (i - r) * j));
					for (int p = 1; p < k; p++)
					{
						f[i][j][k] = min(f[i][j][k], max(f[r][j][p], f[i - r][j][k - p]));
					}
				}
				for (int c = 1; c < j; c++)
				{
					f[i][j][k] = min(f[i][j][k], max(f[i][c][k - 1], i * (j - c)));
					for (int p = 1; p < k; p++)
					{
						f[i][j][k] = min(f[i][j][k], max(f[i][c][p], f[i][j - c][k - p]));
					}
				}
			}
		}
}

int main()
{
	while (1)
	{
		memset(f, top, sizeof(f));
		cin >> w >> h >> m;
		if (w == 0)
			break;
		cake(w, h, m);
		cout << f[w][h][m] << endl;
	}
	return 0;
}
























//#include <iostream>
//#include <algorithm>
//using namespace std;
//
//#define N 25
//#define INF 50005
//
//int f[N][N][N];
//int w, h, m;
//
//
//int main()
//{
//	while (cin >> w >> h >> m && w != 0)
//	{
//		for (int i = 1; i <= w; i++)
//			for (int j = 1; j <= h; j++)
//			{
//				f[i][j][1] = i * j;
//				for (int k = 2; k <= m; k++)
//				{
//					f[i][j][k] = INF;
//					for (int r = 1; r < i; r++)
//					{
//						f[i][j][k] = min(f[i][j][k], max(f[r][j][k - 1], (i - r) * j));
//						for (int p = 1; p < k; p++)
//						{
//							f[i][j][k] = min(f[i][j][k], max(f[r][j][p], f[i - r][j][k - p]));
//						}
//					}
//					for (int c = 1; c < j; c++)
//					{
//						f[i][j][k] = min(f[i][j][k], max(f[i][c][k - 1], i * (j - c)));
//						for (int p = 1; p < k; p++)
//						{
//							f[i][j][k] = min(f[i][j][k], max(f[i][c][p], f[i][j - c][k - p]));
//						}
//					}
//				}	
//			}
//		cout << f[w][h][m] << endl;
//	}
//    return 0;
//}
//
