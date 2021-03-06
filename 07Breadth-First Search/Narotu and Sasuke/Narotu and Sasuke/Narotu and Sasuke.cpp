// Narotu and Sasuke.cpp: 定义控制台应用程序的入口点。
//

//描述
//佐助被大蛇丸诱骗走了，鸣人在多少时间内能追上他呢？
//
//已知一张地图（以二维矩阵的形式表示）以及佐助和鸣人的位置。地图上的每个位置都可以走到，只不过有些位置上有大蛇丸的手下，需要先打败大蛇丸的手下才能到这些位置。
//鸣人有一定数量的查克拉，每一个单位的查克拉可以打败一个大蛇丸的手下。假设鸣人可以往上下左右四个方向移动，每移动一个距离需要花费1个单位时间，打败大蛇丸的手下不需要时间。
//如果鸣人查克拉消耗完了，则只可以走到没有大蛇丸手下的位置，不可以再移动到有大蛇丸手下的位置。佐助在此期间不移动，大蛇丸的手下也不移动。
//请问，鸣人要追上佐助最少需要花费多少时间？
//输入
//输入的第一行包含三个整数：M，N，T。代表M行N列的地图和鸣人初始的查克拉数量T。0 < M, N < 200，0 ≤ T < 10
//	后面是M行N列的地图，其中@代表鸣人， + 代表佐助。*代表通路，#代表大蛇丸的手下。
//	输出
//	输出包含一个整数R，代表鸣人追上佐助最少需要花费的时间。如果鸣人无法追上佐助，则输出 - 1。
//	样例输入
//	样例输入1
//	4 4 1
//  #@##
//	**##
//  ###+
//	****
//
//	样例输入2
//	4 4 2
//  #@##
//	**##
//  ###+
//	****
//	样例输出
//	样例输出1
//	6
//
//	样例输出2
//	4

#include "stdafx.h"
#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

struct node
{
	int x, y, t;
	int sum;
	node(int a, int b, int tt, int f) :x(a), y(b), t(tt), sum(f) {}
	node(){}
};
queue<node> q;
char map[200][200];
int M, N, T;
int startx, starty, desx, desy;
int step[4][2] = { {-1,0},{1,0},{0,-1},{0,1} };
int G[200][200];
int ans = 1 << 30;

bool check(int x, int y, int t)
{
	if (x < 0 || y < 0 || x >= M || y >= N)
		return false;
	if (t <= G[x][y])
		return false;
	return true;
}

bool bfs()
{
	q.push(node(startx, starty, T, 0));
	G[startx][starty] = T;
	while (!q.empty())
	{
		node p = q.front();
		int x =p.x;
		int y =p.y;
		if (x == desx && y == desy)
		{
			ans = p.sum;
			return true;
		}
			
		for (int i = 0; i < 4; i++)
		{
			int tt = p.t;
			int a = x + step[i][0];
			int b = y + step[i][1];
			
			if (check(a, b, tt))
			{
				if (tt > 0 && map[a][b] == '#')
				{
					tt--;
					q.push(node(a, b, tt, p.sum + 1));
					G[a][b] = tt;
				}
				else if(map[a][b] == '*' || map[a][b] == '+')
				{
					q.push(node(a, b, tt, p.sum + 1));
					G[a][b] = tt;
				}
			}
		}
		q.pop();
	}
	return false;
}

int main()
{
	cin >> M >> N >> T;
	memset(G, 0xff, sizeof(G));
	for (int i = 0; i< M; i++)
		for (int j = 0; j < N; j++)
		{
			cin >> map[i][j];
			if (map[i][j] == '@')
				startx = i, starty = j;
			if (map[i][j] == '+')
				desx = i, desy = j;
		}
	if (bfs())
	{
		cout << ans << endl;
	}
	else
		cout << "-1" << endl;

    return 0;
}

