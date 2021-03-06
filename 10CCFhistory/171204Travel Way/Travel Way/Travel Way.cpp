// Travel Way.cpp: 定义控制台应用程序的入口点。
//

//问题描述
//小明和小芳出去乡村玩，小明负责开车，小芳来导航。
//小芳将可能的道路分为大道和小道。大道比较好走，每走1公里小明会增加1的疲劳度。
//小道不好走，如果连续走小道，小明的疲劳值会快速增加，连续走s公里小明会增加s2的疲劳度。
//例如：有5个路口，1号路口到2号路口为小道，2号路口到3号路口为小道，3号路口到4号路口为大道，
//4号路口到5号路口为小道，相邻路口之间的距离都是2公里。
//如果小明从1号路口到5号路口，则总疲劳值为(2 + 2)2 + 2 + 22 = 16 + 2 + 4 = 22。
//现在小芳拿到了地图，请帮助她规划一个开车的路线，使得按这个路线开车小明的疲劳度最小。
//输入格式
//输入的第一行包含两个整数n, m，分别表示路口的数量和道路的数量。路口由1至n编号，小明需要开车从1号路口到n号路口。
//接下来m行描述道路，每行包含四个整数t, a, b, c，表示一条类型为t，连接a与b两个路口，长度为c公里的双向道路。
//其中t为0表示大道，t为1表示小道。保证1号路口和n号路口是连通的。
//输出格式
//输出一个整数，表示最优路线下小明的疲劳度。
//样例输入
//6 7
//1 1 2 3
//1 2 3 2
//0 1 3 30
//0 3 4 20
//0 4 5 30
//1 3 5 6
//1 5 6 1
//样例输出
//76
//样例说明
//从1走小道到2，再走小道到3，疲劳度为52 = 25；然后从3走大道经过4到达5，疲劳度为20 + 30 = 50；最后从5走小道到6，疲劳度为1。总共为76。
//数据规模和约定
//对于30%的评测用例，1 ≤ n ≤ 8，1 ≤ m ≤ 10；
//对于另外20%的评测用例，不存在小道；
//对于另外20%的评测用例，所有的小道不相交；
//对于所有评测用例，1 ≤ n ≤ 500，1 ≤ m ≤ 105，1 ≤ a, b ≤ n，t是0或1，c ≤ 105。保证答案不超过106。

#include "stdafx.h"
#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
using namespace std;

struct way
{
	int typ, sou, des, len;
	way(int t, int s, int d, int l) :typ(t), sou(s), des(d), len(l) {};
};

int n, m;
vector<way> vec;
vector<int> v[100010];
int vis[100010];
int pre[100010];
int leng[100010];
bool islastsma[100010];
int lastsma[100010];
int ans = 1 << 30;

bool u(int i, int j, int k)
{
	
	if (vec[k].typ == 1)
	{
		if (islastsma[i])
		{
			int t = leng[i] - lastsma[i] * lastsma[i];
			if (t + pow(vec[k].len + lastsma[i], 2) < leng[j])
			{
				leng[j] = t + pow(vec[k].len + lastsma[i], 2);
				lastsma[j] = lastsma[i] + vec[k].len;
				islastsma[j] = true;
				return true;
			}
		}
		else
		{
			if (leng[i] + pow(vec[k].len, 2) < leng[j])
			{
				leng[j] = leng[i] + pow(vec[k].len, 2);
				lastsma[j] = vec[k].len;
				islastsma[j] = true;
				return true;
			}
		}
	}
	else
	{
			if (leng[i] + vec[k].len < leng[j])
			{
				leng[j] = leng[i] + vec[k].len;
				islastsma[j] = false;
				lastsma[j] = 0;
				return true;
			}
			
	}
	return false;
}

void bfs()
{
	queue<int> q;
	q.push(1);
	vis[1] = 1;
	while (!q.empty())
	{
		int w = q.front();
		q.pop();
		vis[w] = 0;
		for (int i = 0; i < v[w].size(); i++)
		{
			if (u(vec[v[w][i]].sou, vec[v[w][i]].des, v[w][i]))
				if (!vis[vec[v[w][i]].des])
				{
					q.push(vec[v[w][i]].des);
					vis[vec[v[w][i]].des] = 1;
				}
		}
	}

}

int main()
{
	cin >> n >> m;
	memset(pre, 0xff, sizeof(pre));
	memset(lastsma, 0, sizeof(lastsma));
	for (int i = 0; i <= n; i++)
	{
		leng[i] = 1 << 30;
		islastsma[i] = false;
	}
	leng[1] = 0;
	while (m--)
	{
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		vec.push_back(way(a, b, c, d));
		vec.push_back(way(a, c, b, d));
		v[b].push_back(vec.size() - 2);
		v[c].push_back(vec.size() - 1);
	}
	bfs();
	cout << leng[n] << endl;

	return 0;
}

































//
////以下程序只能得30分
//#include <iostream>
//#include <cstring>
//#include <queue>
//#define LL  long long
//
//using namespace std;
//
//struct edge
//{
//	int v, next, t, c;
//}e[110 * 4];
//
//struct node
//{
//	LL dis;
//	LL pre;
//	int v;
//	node(){}
//	node(int vv, LL ddis, LL ppre)
//	{
//		dis = ddis;
//		pre = ppre;
//		v = vv;
//	}
//	friend bool operator<(node n1, node n2)
//	{
//		if (n1.dis == n2.dis)
//			return n1.pre > n2.pre;
//		return n1.dis > n2.dis;
//	}
//};
//
//LL d[510], qx[510];
//int visited[510 * 2];
//int n, m;
//int head[510 * 2];
//int tot;
//const LL inf = 1e9;
//
//LL dj(int s, int t)
//{
//	priority_queue<node> q;
//	d[s] = qx[s] = 0;
//	
//	q.push(node(s, d[s], qx[s]));
//	while (!q.empty())
//	{
//		node te = q.top();
//		q.pop();
//		int u = te.v;
//		if (visited[u])
//			continue;
//		visited[u] = 1;
//		for (int i = head[u]; i + 1; i = e[i].next)
//		{
//			int v = e[i].v;
//			if (visited[v])
//				continue;
//			if (e[i].t)
//			{
//				LL len = d[u] - qx[u] * qx[u] + (qx[u] + e[i].c) * (qx[u] + e[i].c);
//				if (d[v] > len || (d[v] == len && (qx[v] > qx[u] + e[i].c)))
//				{
//					d[v] = len;
//					qx[v] = qx[u] + e[i].c;
//					q.push(node(v, d[v], qx[v]));
//				}
//			}
//			else
//			{
//				LL len = d[u] + e[i].c;
//				if (d[v] > len)
//				{
//					d[v] = len;
//					q.push(node(v, d[v], qx[v]));
//				}
//			}
//		}
//	}
//	return d[t];
//}
//
//
//void add(int v, int u, int t, int c)
//{
//	e[tot].t = t;
//	e[tot].c = c;
//	e[tot].v = v;
//	e[tot].next = head[u];
//	head[u] = tot++;
//}
//
//int main()
//{
//	tot = 0;
//	memset(head, -1, sizeof(head));
//	memset(visited, 0, sizeof(visited));
//	for (int i = 0; i < 510 * 2; i++)
//		d[i] = inf;
//	memset(qx, 0, sizeof(qx));
//	cin >> n >> m;
//	for (int i = 0; i < m; i++)
//	{
//		int t, a, b, c;
//		cin >> t >> a >> b >> c;
//		a--;
//		b--;
//		add(a, b, t, c);
//		add(b, a, t, c);
//	}
//	cout << dj(0, n - 1) << endl;
//	return 0;
//}



































//#include <iostream>
//#include <algorithm>
//#include <queue>
//#include<bits/stdc++.h>
//using namespace std;
//#define LL long long  
//const int maxn = 1e3 + 5;
//const int inf = 1e9 + 7;
//int n, head[maxn], vis[maxn], tot;
//LL d[maxn], qx[maxn];
//struct edge {
//	int v, next, val, type;
//}e[maxn * 100 * 4];
//struct node {
//	int v;
//	LL dis, pre;
//	node() {
//	}
//	node(int v, LL dis, LL pre) {
//		this->v = v;
//		this->dis = dis;
//		this->pre = pre;
//	}
//	friend bool operator<(node n1, node n2)
//	{
//		if (n1.dis == n2.dis)
//			return n1.pre>n2.pre;
//		return n1.dis>n2.dis;
//	}
//};
//
//LL dj(int s, int t)
//{
//	priority_queue<node>q;
//	d[s] = qx[s] = 0;
//	q.push(node(s, d[s], qx[s]));
//	d[s + n] = qx[s + n] = 0;
//	q.push(node(s + n, d[s + n], qx[s + n]));
//	while (!q.empty())
//	{
//		node te = q.top();
//		q.pop();
//		int u = te.v;
//		//	printf("u=%d\n",u+1);
//		if (vis[u])
//			continue;
//		vis[u] = 1;
//		for (int i = head[u]; i + 1; i = e[i].next)
//		{
//			int v = e[i].v;
//			if (vis[v])
//				continue;
//			//	printf("v=%d %d\n",v+1,e[i].val);
//			if (e[i].type)
//			{
//				LL  len = d[u] - qx[u] * qx[u] + (qx[u] + e[i].val)*(qx[u] + e[i].val);
//				if (d[v]>len || (d[v] == len&&qx[v]>qx[u] + e[i].val))
//				{
//					d[v] = len;
//					qx[v] = qx[u] + e[i].val;
//					q.push(node(v, d[v], qx[v]));
//				}
//			}
//			else
//			{
//				if (d[v]>d[u] + e[i].val)
//				{
//					d[v] = d[u] + e[i].val;
//					q.push(node(v, d[v], qx[v]));
//				}
//			}
//			//printf("%lld %lld\n",d[v],qx[v]);
//		}
//	}
//	return min(d[t], d[n + t]);
//}
//void init()
//{
//	tot = 0;
//	for (int i = 0; i<2 * n; i++)
//	{
//		head[i] = -1;
//		d[i] = inf;
//		if (i<n)
//			qx[i] = 0;
//		else
//			qx[i] = inf;
//		vis[i] = 0;
//	}
//}
//void add(int u, int v, int type, int val)
//{
//	e[tot].type = type;
//	e[tot].v = v;
//	e[tot].val = val;
//	e[tot].next = head[u];
//	head[u] = tot++;
//}
//int main()
//{
//	int m;
//	scanf_s("%d%d", &n, &m);
//	init();
//	while (m--)
//	{
//		int t, a, b, c;
//		scanf_s("%d%d%d%d", &t, &a, &b, &c);
//		a--;
//		b--;
//		add(a, b + n*t, t, c);
//		add(a + n, b + n*t, t, c);
//		add(b, a + n*t, t, c);
//		add(b + n, a + n*t, t, c);
//	}
//	printf_s("%lld\n", dj(0, n - 1));
//
//}
