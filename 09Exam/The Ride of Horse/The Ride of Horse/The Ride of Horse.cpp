// The Ride of Horse.cpp: 定义控制台应用程序的入口点。
//

//描述
//马在中国象棋以日字形规则移动。
//请编写一段程序，给定n*m大小的棋盘，以及马的初始位置(x，y)，要求不能重复经过棋盘上的同一个点，计算马可以有多少途径遍历棋盘上的所有点。
//输入
//第一行为整数T(T < 10)，表示测试数据组数。
//	每一组测试数据包含一行，为四个整数，分别为棋盘的大小以及初始位置坐标n, m, x, y。(0 <= x <= n - 1, 0 <= y <= m - 1, m < 10, n < 10)
//	输出
//	每组测试数据包含一行，为一个整数，表示马能遍历棋盘的途径总数，0为无法遍历一次。
//	样例输入
//	1
//	5 4 0 0
//	样例输出
//	32

#include "stdafx.h"
#include <iostream>
#include <cstring>
using namespace std;

struct pos
{
	int x, y;
};

pos dir[8] = { {-2, -1}, {-2, 1}, {2, -1}, {2, 1}, {-1, -2}, {-1, 2}, {1, -2}, {1, 2} };
int n, m;
int visited[10][10];
int ways;

void DFS(int c, int r, int k)
{
	if (k == n * m)
	{
		ways++;
	}
	else
	{
		for (int i = 0; i < 8; i++)
		{
			int tempx = c + dir[i].x;
			int tempy = r + dir[i].y;
			if (!visited[tempx][tempy] && tempx >= 0 && tempx < n && tempy >= 0 && tempy < m)
			{
				visited[tempx][tempy] = 1;
				DFS(tempx, tempy, k + 1);
				visited[tempx][tempy] = 0;
			}
		}
	}
}

int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		memset(visited, 0, sizeof(visited));
		pos p0;
		ways = 0;
		cin >> n >> m >> p0.x >> p0.y;
		visited[p0.x][p0.y] = 1;
		DFS(p0.x, p0.y, 1);
		cout << ways << endl;
	}
    return 0;
}

