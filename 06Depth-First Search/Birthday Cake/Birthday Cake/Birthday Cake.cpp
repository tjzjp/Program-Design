// Birthday Cake.cpp: 定义控制台应用程序的入口点。
//

//描述
//7月17日是Mr.W的生日，ACM - THU为此要制作一个体积为Nπ的M层生日蛋糕，每层都是一个圆柱体。
//设从下往上数第i(1 <= i <= M)层蛋糕是半径为Ri, 高度为Hi的圆柱。当i < M时，要求Ri > Ri + 1且Hi > Hi + 1。
//由于要在蛋糕上抹奶油，为尽可能节约经费，我们希望蛋糕外表面（最下一层的下底面除外）的面积Q最小。
//令Q = Sπ
//请编程对给出的N和M，找出蛋糕的制作方案（适当的Ri和Hi的值），使S最小。
//（除Q外，以上所有数据皆为正整数）
//输入
//有两行，第一行为N（N <= 10000），表示待制作的蛋糕的体积为Nπ；第二行为M(M <= 20)，表示蛋糕的层数为M。
//输出
//仅一行，是一个正整数S（若无解则S = 0）。
//样例输入
//100
//2
//样例输出
//68
//提示
//圆柱公式
//体积V = πR2H
//侧面积A' = 2πRH
//底面积A = πR2

#include "stdafx.h"
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int N, M;
int v, s;
int ans = 1 << 30;
int mxr, mxh;
int sta[25][2];
int layer[25];
int sur[25];

void dfs(int rr, int hh, int n, int m)
{
	if (m == 0)
	{
		if (n)
			return;
		else
		{
			ans = min(ans, s);
			return;
		}
	}
	if (n <= 0)
		return;
	if (layer[m - 1] > n)
		return;
	if (sur[m - 1] + s > ans)
		return;
	for (int r = rr; r >= m; r--)
	{
		if (m == M)
			s = r * r;
		for (int h = hh; h >= m; h--)
		{
			s += 2 * r * h;
			dfs(r - 1, h - 1, n - r * r * h, m - 1);
			s -= 2 * r * h;
		}
	}
		

}

void pre()
{
	for (int i = 1; i < 25; i++)
	{
		layer[i] = layer[i - 1] + i * i * i;
		sur[i] = sur[i - 1] + 2 * i * i;
	}
}

int main()
{
	cin >> N >> M;
	s = 0;
	v = 0;
	int mxh = (int)((N - layer[M - 1]) / M / M);
	int mxr = (int)(sqrt((N - layer[M - 1]) / M));
	memset(sta, 0, sizeof(sta));
	dfs(mxh, mxr, N, M);
	if (ans < (1 << 30))
		cout << ans << endl;
	else
		cout << '0' << endl;
	return 0;
}





























//#include <iostream>
//#include <algorithm>
//#include <cstring>
//using namespace std;
//
//int N, M, S;
//int area;
//int minarea;
//int layer[25];
//int sur[25];
//
//void DFS(int v, int n, int h, int r)
//{
//	if (n == 0)
//	{
//		if (v)
//			return;
//		else
//		{
//			minarea = min(area, minarea);
//			return;
//		}	
//	}
//	if (v <= 0)
//		return;
//	if (layer[n - 1] > v)
//		return;
//	if (sur[n - 1] + area > minarea)
//		return;
//	for (int rr = r; rr >= n; rr--)
//	{
//		if (n == M)
//			area = rr * rr;
//		for (int hh = h; hh >= n; hh--)
//		{
//			area += 2 * rr * hh;
//			DFS(v - rr * rr * hh, n - 1, hh - 1, rr - 1);
//			area -= 2 * rr * hh;
//		}
//
//	}
//}
//
//void Layer()
//{
//	for (int i = 1; i < 25; i++)
//	{
//		layer[i] = layer[i - 1] + i * i * i;
//		sur[i] = sur[i - 1] + 2 * i * i;
//	}
//}
//
//int main()
//{
//	cin >> N >> M;
//	Layer();
//	minarea = 1 << 30;
//	int maxh = (N - layer[M - 1]) / M / M;
//	int maxr = int(sqrt((N - layer[M - 1]) / M));
//	DFS(N, M, maxh, maxr);
//	if (minarea < (1 << 30))
//		cout << minarea << endl;
//	else
//		cout << "0" << endl;
//    return 0;
//}
//
