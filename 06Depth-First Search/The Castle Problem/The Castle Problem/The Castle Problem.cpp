// The Castle Problem.cpp: 定义控制台应用程序的入口点。
//

//描述
//
//  1   2   3   4   5   6   7
//  #############################
//1 #    | # | #   |   |   #
//  #####---#####---#---#####---#
//2 #   # | #   #   #   #   #
//  #---#####---#####---#####---#
//3 #   |   |   #   #   #   #   #
//  #---#########---#####---#---#
//4 #   #   |   |   |   |   #   #
//  #############################
//(图 1)
//
//#  = Wall   
//| = No wall
//- = No wall
//
//图1是一个城堡的地形图。请你编写一个程序，计算城堡一共有多少房间，最大的房间有多大。
//城堡被分割成mn(m≤50，n≤50)个方块，每个方块可以有0~4面墙。
//输入
//程序从标准输入设备读入数据。第一行是两个整数，分别是南北向、东西向的方块数。在接下来的输入行里，每个方块用一个数字(0≤p≤50)描述。
//用一个数字表示方块周围的墙，1表示西墙，2表示北墙，4表示东墙，8表示南墙。每个方块用代表其周围墙的数字之和表示。城堡的内墙被计算两次，
//方块(1, 1)的南墙同时也是方块(2, 1)的北墙。输入的数据保证城堡至少有两个房间。
//输出
//城堡的房间数、城堡中最大房间所包括的方块数。结果显示在标准输出设备上。
//样例输入
//4
//7
//11 6 11 6 3 10 6
//7 9 6 13 5 15 5
//1 10 12 7 13 7 5
//13 11 10 8 10 12 13
//样例输出
//5
//9

#include "stdafx.h"
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int m, n;
int a[55][55];
int Color[55][55];
int Room;
int area;
int ans;

void dfs(int ii, int jj)
{
	if (ii < 0 || ii > m || jj < 0 || jj > n)
		return;
	if (Color[ii][jj])
		return;
	Color[ii][jj] = Room;
	area++;
	if ((a[ii][jj] & 1) == 0)
		dfs(ii, jj - 1);
	if ((a[ii][jj] & 2) == 0)
		dfs(ii - 1, jj);
	if ((a[ii][jj] & 4) == 0)
		dfs(ii, jj + 1);
	if ((a[ii][jj] & 8) == 0)
		dfs(ii + 1, jj);
		
}

int main()
{
	cin >> m >> n;
	ans = 0;
	area = 0;
	memset(Color, 0, sizeof(Color));
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
		{
			cin >> a[i][j];
		}
	for (int i = 0; i < m; i++)
		for (int j = 0; j < n; j++)
		{
			if (!Color[i][j])
			{
				area = 0;
				Room++;
				dfs(i, j);

			}
			ans = max(area, ans);
		}
	cout << Room << endl;
	cout << ans << endl;
	return 0;
}


//#include <iostream>
//#include <cstring>
//#include <algorithm>
//using namespace std;
//
//int Color[60][60];
//int Wall[60][60];
//int m, n;
//int Room = 0, AreaRoom = 0, maxAreaRoom = 0;
//
//void DFS(int i, int j)
//{
//	if (Color[i][j])
//		return;
//	AreaRoom++;
//	Color[i][j] = Room;
//	if ((Wall[i][j] & 1) == 0)
//		DFS(i, j - 1);
//	if ((Wall[i][j] & 2) == 0)
//		DFS(i - 1, j);
//	if ((Wall[i][j] & 4) == 0)
//		DFS(i, j + 1);
//	if ((Wall[i][j] & 8) == 0)
//		DFS(i + 1, j);
//}
//
//int main()
//{
//	cin >> m >> n;
//	memset(Color, 0, sizeof(Color));
//	for (int i = 1; i <= m; i++)
//		for (int j = 1; j <= n; j++)
//		{
//			cin >> Wall[i][j];
//		}
//	for (int i = 1; i <= m; i++)
//		for (int j = 1; j <= n; j++)
//		{
//			if (!Color[i][j])
//			{
//				Room++;
//				AreaRoom = 0;
//				DFS(i, j);
//			}
//			maxAreaRoom = max(AreaRoom, maxAreaRoom);
//		}
//	cout << Room << endl;
//	cout << maxAreaRoom << endl;
//    return 0;
//}
//
