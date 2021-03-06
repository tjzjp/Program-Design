// 2816Red and Black.cpp: 定义控制台应用程序的入口点。
//

//描述
//有一间长方形的房子，地上铺了红色、黑色两种颜色的正方形瓷砖。你站在其中一块黑色的瓷砖上，只能向相邻的黑色瓷砖移动。
//请写一个程序，计算你总共能够到达多少块黑色的瓷砖。
//输入
//包括多个数据集合。每个数据集合的第一行是两个整数W和H，分别表示x方向和y方向瓷砖的数量。W和H都不超过20。在接下来的H行中，每行包括W个字符。
//每个字符表示一块瓷砖的颜色，规则如下
//1）‘.’：黑色的瓷砖；
//2）‘#’：白色的瓷砖；
//3）‘@’：黑色的瓷砖，并且你站在这块瓷砖上。该字符在每个数据集合中唯一出现一次。
//当在一行中读入的是两个零时，表示输入结束。
//输出
//对每个数据集合，分别输出一行，显示你从初始位置出发能到达的瓷砖数(记数时包括初始位置的瓷砖)。
//样例输入
//6 9
//....#.
//.....# 
//......
//......
//......
//......
//......
//#@...# 
//.#..#.
//0 0
//样例输出
//45

#include "stdafx.h"
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int w, h, sum;
char c[25][25];
int vis[25][25];
int v[25][25];

int posx[4] = { -1, 0, 0, 1 };
int posy[4] = { 0, -1, 1, 0 };
int ans;

void dfs(int x, int y)
{
	for (int i = 0; i < 4; i++)
	{
		int x1 = x + posx[i];
		int y1 = y + posy[i];
		if (x1 >= 0 && x1 < h && y1 >= 0 && y1 < w)
		{
			if (c[x1][y1] == '.')
			{
				if (!vis[y1][x1])
				{
					vis[y1][x1] = 1;
					sum++;
					dfs(x1, y1);
					
				}
			}
		}
		
	}
}

int main()
{
	while (cin >> w >> h)
	{
		int x1, y1;
		sum = 1;
		memset(vis, 0, sizeof(vis));
		memset(v, 0, sizeof(v));
		if (w == 0 && h == 0)
			break;
		for (int i = 0; i < h; i++)
		{
			cin >> c[i];
			for (int j = 0; j < w; j++)
			{
				if (c[i][j] == '@')
				{
					x1 = i;
					y1 = j;
					break;
				}
			}
		}
			
		dfs(x1, y1);
		cout << sum << endl;
			


	}
    return 0;
}




//#include <iostream>
//#include <cstring>
//using namespace std;
//char maze[30][30];
//int visited[30][30];
//int area = 0;
//int W, H;
//void dfs(int r, int c)
//{
//	if (r < 0 || c < 0 || r >= H || c >= W)
//		return;
//	if (maze[r][c] == '#' || visited[r][c])
//		return;
//	++area;
//	visited[r][c] = 1;
//	dfs(r + 1, c);
//	dfs(r - 1, c);
//	dfs(r, c + 1);
//	dfs(r, c - 1);
//
//}
//int main()
//{
//	while (1) {
//		cin >> W >> H;
//		if (W == 0 && H == 0)
//			break;
//		memset(visited, 0, sizeof(visited));
//		area = 0;
//		int sr, sc;
//		for (int i = 0; i < H; ++i)
//			for (int j = 0; j < W; ++j) {
//				cin >> maze[i][j];
//				if (maze[i][j] == '@') {
//					sr = i;
//					sc = j;
//				}
//			}
//		dfs(sr, sc);
//		cout << area << endl;
//	}
//}

