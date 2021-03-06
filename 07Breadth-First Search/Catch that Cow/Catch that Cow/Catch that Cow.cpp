// Catch that Cow.cpp: 定义控制台应用程序的入口点。
//

//描述
//农夫知道一头牛的位置，想要抓住它。农夫和牛都位于数轴上，农夫起始位于点N(0 <= N <= 100000)，牛位于点K(0 <= K <= 100000)。农夫有两种移动方式：
//1、从X移动到X - 1或X + 1，每次移动花费一分钟
//2、从X移动到2*X，每次移动花费一分钟
//
//假设牛没有意识到农夫的行动，站在原地不动。农夫最少要花多少时间才能抓住牛？
//
//输入
//两个整数，N和K
//输出
//一个整数，农夫抓到牛所要花费的最小分钟数
//样例输入
//5 17
//样例输出
//4

#include "stdafx.h"
#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;

int N, K;
int vis[100010 * 2];
int v[100010 * 2];
int ans = 1 << 30;

struct node
{
	int pos, tim;
	node(int p, int t) :pos(p), tim(t) {};
};

queue<node> q;

void bfs()
{
	while (!q.empty())
	{
		node k = q.front();
		q.pop();
		if (k.pos == K)
		{
			ans = min(ans, k.tim);
			break;
		}
			
		for (int i = 0; i < 3; i++)
		{
			if (i % 3 == 0 && k.pos < K && !v[k.pos + 1])
			{
				int p = k.pos + 1;
				vis[p] = k.tim + 1;
				q.push(node(p, k.tim + 1));
				v[p] = 1;
			}
			else if (i % 3 == 1 && k.pos > 0 && !v[k.pos - 1])
			{
				int p = k.pos - 1;
				vis[p] = k.tim + 1;
				q.push(node(p, k.tim + 1));
				v[p] = 1;
			}
			else if(i % 3 == 2 && k.pos < K && !v[k.pos * 2])
			{
				int p = k.pos * 2;	
				vis[p] = k.tim + 1;
				q.push(node(p, k.tim + 1));
				v[p] = 1;
			}
		}

	}
	


}

int main()
{
	cin >> N >> K;
	for (int i = 0; i <= K * 2; i++)
		vis[i] = (1 << 30);
	memset(v, 0, sizeof(v));
	q.push(node(N, 0));
	vis[N] = 0;
	v[N] = 1;
	bfs();
	cout << vis[K] << endl;
	return 0;
}

























//#include <iostream>
//#include <cstring>
//#include <queue>
//using namespace std;
//
//const int MAXN = 100000 + 5;
//int visited[2 * (MAXN + 10)]; //数组要开够？？？
//
//struct node
//{
//	int x;
//	int step;
//	node(int a, int b) : x(a), step(b) {}
//};
//
//queue<node> q;
//int N, K;
//
//int main()
//{
//	cin >> N >> K;
//	memset(visited, 0, sizeof(visited));
//	q.push(node(N, 0));
//	visited[N] = 1;
//	while (!q.empty())
//	{
//		node s = q.front();
//		if (s.x == K)
//		{
//			cout << s.step << endl;
//			return 0;
//		}
//		else
//		{
//			if (!visited[s.x + 1] && s.x + 1 <= MAXN)
//			{				
//				q.push(node(s.x + 1, s.step + 1));
//				visited[s.x + 1] = 1;
//			}
//			if (!visited[s.x - 1] && s.x - 1 >= 0)
//			{
//				q.push(node(s.x - 1, s.step + 1));
//				visited[s.x - 1] = 1;
//			}
//			if (!visited[s.x * 2] && s.x * 2 <= MAXN)
//			{
//				q.push(node(s.x * 2, s.step + 1));
//				visited[s.x * 2] = 1;
//			}
//			q.pop();
//		}
//	}
//    return 0;
//}
//
