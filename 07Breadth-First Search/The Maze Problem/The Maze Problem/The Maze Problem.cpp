// The Maze Problem.cpp: 定义控制台应用程序的入口点。
//

//描述
//定义一个二维数组：
//int maze[5][5] = {
//
//	0, 1, 0, 0, 0,
//
//	0, 1, 0, 1, 0,
//
//	0, 0, 0, 0, 0,
//
//	0, 1, 1, 1, 0,
//
//	0, 0, 0, 1, 0,
//
//};
//
//它表示一个迷宫，其中的1表示墙壁，0表示可以走的路，只能横着走或竖着走，不能斜着走，要求编程序找出从左上角到右下角的最短路线。
//
//输入
//一个5 × 5的二维数组，表示一个迷宫。数据保证有唯一解。
//输出
//左上角到右下角的最短路径，格式如样例所示。
//样例输入
//0 1 0 0 0
//0 1 0 1 0
//0 0 0 0 0
//0 1 1 1 0
//0 0 0 1 0
//样例输出
//(0, 0)
//(1, 0)
//(2, 0)
//(2, 1)
//(2, 2)
//(2, 3)
//(2, 4)
//(3, 4)
//(4, 4)

#include "stdafx.h"
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

struct node
{
	int r, c, pre;
};

node que[100];
int maze[6][6];
int visited[6][6];
int step[4][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };
int start = 0;
int endding = 1;

bool check(int r, int c)
{
	if (r < 0 || c < 0 || r >= 5 || c >= 5)
		return false;
	if (visited[r][c])
		return false;
	if (maze[r][c])	
		return false;
	return true;
}

void print(int s)//递归输出
{
	if (que[s].pre != -1)
	{
		print(que[s].pre);
		cout << "(" << que[s].r << ", " << que[s].c << ")" << endl;
	}	
}

void bfs(int x, int y)
{
	que[start].pre = -1;
	que[start].r = x;
	que[start].c = y;
	while (start < endding)
	{
		for (int i = 0; i < 4; i++)
		{
			int a = step[i][0] + que[start].r;
			int b = step[i][1] + que[start].c;
			if (check(a, b))
			{
				visited[a][b] = 1;
				que[endding].r = a;
				que[endding].c = b;
				que[endding].pre = start;
				endding++;
			}
			if (a == 4 && b == 4)
				print(start);
		}
		start++;
	}
}

int main()
{
	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 5; j++)
			cin >> maze[i][j];
	memset(visited, 0, sizeof(visited));
	visited[0][0] = 1;
	cout << "(0, 0)" << endl;
	bfs(0, 0);
	cout << "(4, 4)" << endl;
    return 0;
}

