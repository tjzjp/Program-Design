// Thread.cpp: 定义控制台应用程序的入口点。
//

//描述
//有一个方格矩阵，矩阵边界在无穷远处。我们做如下假设：
//a.每走一步时，只能从当前方格移动一格，走到某个相邻的方格上；
//b.走过的格子立即塌陷无法再走第二次；
//c.只能向北、东、西三个方向走；
//请问：如果允许在方格矩阵上走n步，共有多少种不同的方案。2种走法只要有一步不一样，即被认为是不同的方案。
//输入 允许在方格上行走的步数n(n <= 20) 输出 计算出的方案数量 样例输入
//2
//样例输出
//7

#include "stdafx.h"
#include <iostream>
#include <cstring>
using namespace std;

int n;
int sum;
int vis[25][50];
int posx[3] = { 1, 0, 0 };
int posy[3] = { 0, -1, 1 };

void dfs(int i, int j, int m)
{
	if (m == n)
	{
		sum++;
		return;
	}
	
	for (int k = 0; k < 3; k++)
	{
		if (vis[i + posx[k]][j + posy[k]])
			continue;
		vis[i + posx[k]][j + posy[k]] = 1;
		dfs(i + posx[k], j + posy[k], m + 1);
		vis[i + posx[k]][j + posy[k]] = 0;
	}
}

int main()
{
	cin >> n;
	sum = 0;
	memset(vis, 0, sizeof(vis));
	vis[0][25] = 1;
	dfs(0, 25, 0);
	cout << sum << endl;
	return 0;
}

















//#include <iostream>
//#include <cstring>
//using namespace std;
//
//int visited[30][50];
//int n;
//
//int ways(int i, int j, int n)
//{
//	if (n == 0)
//		return 1;
//	visited[i][j] = 1;
//	int num = 0;
//	if (!visited[i + 1][j])
//		num += ways(i + 1, j, n - 1);
//	if (!visited[i][j - 1])
//		num += ways(i, j - 1, n - 1);
//	if (!visited[i][j + 1])
//		num += ways(i, j + 1, n - 1);
//	visited[i][j] = 0;
//	return num;
//}
//
//int main()
//{
//	memset(visited, 0, sizeof(visited));
//	cin >> n;
//	cout << ways(0, 25, n) << endl;
//    return 0;
//}

