// Subway Construction.cpp: 定义控制台应用程序的入口点。
//

//问题描述
//A市有n个交通枢纽，其中1号和n号非常重要，为了加强运输能力，A市决定在1号到n号枢纽间修建一条地铁。
//地铁由很多段隧道组成，每段隧道连接两个交通枢纽。经过勘探，有m段隧道作为候选，
//两个交通枢纽之间最多只有一条候选的隧道，没有隧道两端连接着同一个交通枢纽。
//现在有n家隧道施工的公司，每段候选的隧道只能由一个公司施工，每家公司施工需要的天数一致。
//而每家公司最多只能修建一条候选隧道。所有公司同时开始施工。
//作为项目负责人，你获得了候选隧道的信息，现在你可以按自己的想法选择一部分隧道进行施工，请问修建整条地铁最少需要多少天。
//输入格式
//输入的第一行包含两个整数n, m，用一个空格分隔，分别表示交通枢纽的数量和候选隧道的数量。
//第2行到第m + 1行，每行包含三个整数a, b, c，表示枢纽a和枢纽b之间可以修建一条隧道，需要的时间为c天。
//输出格式
//输出一个整数，修建整条地铁线路最少需要的天数。
//样例输入
//6 6
//1 2 4
//2 3 4
//3 6 7
//1 4 2
//4 5 5
//5 6 6
//样例输出
//6
//样例说明
//可以修建的线路有两种。
//第一种经过的枢纽依次为1, 2, 3, 6，所需要的时间分别是4, 4, 7，则整条地铁线需要7天修完；
//第二种经过的枢纽依次为1, 4, 5, 6，所需要的时间分别是2, 5, 6，则整条地铁线需要6天修完。
//第二种方案所用的天数更少。
//评测用例规模与约定
//对于20%的评测用例，1 ≤ n ≤ 10，1 ≤ m ≤ 20；
//对于40%的评测用例，1 ≤ n ≤ 100，1 ≤ m ≤ 1000；
//对于60%的评测用例，1 ≤ n ≤ 1000，1 ≤ m ≤ 10000，1 ≤ c ≤ 1000；
//对于80%的评测用例，1 ≤ n ≤ 10000，1 ≤ m ≤ 100000；
//对于100%的评测用例，1 ≤ n ≤ 100000，1 ≤ m ≤ 200000，1 ≤ a, b ≤ n，1 ≤ c ≤ 1000000。

//所有评测用例保证在所有候选隧道都修通时1号枢纽可以通过隧道到达其他所有枢纽。

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

struct way
{
	int sou, des, day;
	way(int s, int d, int dd) :sou(s), des(d), day(dd) {};
	bool operator< (way w)
	{
		return w.day > day;
	}
};

int n, m;
vector<way> w;
int pre[100010];

int f(int x)
{
	int f1 = x;
	int f0 = x;
	while (pre[f0] > 0)
		f0 = pre[f0];
	while (pre[f1] > 0)
	{
		int t = f1;
		f1 = pre[f1];
		pre[t] = f0;
	}
	return f0;
}

void u(int s, int e)
{
	int f1 = f(s);
	int f2 = f(e);
	if (f1 != f2)
	{
		if (f1 <= f2)
		{
			pre[f1] += pre[f2];
			pre[f2] = f1;
		}
		else
		{
			pre[f2] += pre[f1];
			pre[f1] = f2;
		}
	}
}

int main()
{
	cin >> n >> m;
	memset(pre, 0xff, sizeof(pre));
	while (m--)
	{
		int a, b, c;
		cin >> a >> b >> c;
		w.push_back(way(a, b, c));
	}
	sort(w.begin(), w.end());
	for (int i = 0; i < w.size(); i++)
	{
		u(w[i].sou, w[i].des);
		if (f(1) == f(n))
		{
			cout << w[i].day << endl;
			break;
		}
	}
	return 0;
}


























////并查集
//#include <iostream>
//#include <algorithm>
//#include <vector>
//#include <cstring>
//using namespace std;
//
//const int MAXN = 1e5 + 2;
//int N, M;
//int pre[MAXN];
//
//struct Edge
//{
//	Edge(int _n1, int _n2, int _days) :n1(_n1), n2(_n2), days(_days) {}
//	int n1, n2, days;
//	bool operator<(const Edge& e) const
//	{
//		return days < e.days;
//	}
//};
//vector<Edge> ve;
//
//int f(int x)
//{
//	int f0 = x, f1 = x;
//	for (; pre[f0] > 0;) f0 = pre[f0];
//	for (; pre[f1] > 0;)
//	{
//		int t = f1;
//		f1 = pre[f1];
//		pre[t] = f0;
//	}
//	return f0;
//}
//
//void u(int n1, int n2)
//{
//	int f1 = f(n1);
//	int f2 = f(n2);
//	if (f1 != f2)
//	{
//		if (pre[f1] <= pre[f2])
//		{
//			pre[f1] += pre[f2];
//			pre[f2] = f1;
//		}
//		else
//		{
//			pre[f2] += pre[f1];
//			pre[f1] = f2;
//		}
//	}
//}
//
//int main()
//{
//	memset(pre, -1, sizeof pre);
//	int a, b, c;
//	cin >> N >> M;
//	for (int i = 0; i < M; i++)
//	{
//		cin >> a >> b >> c;
//		//ve.push_back({ a,b,c });        // 用这个会编译错误的
//		ve.push_back(Edge(a, b, c));
//	}
//	sort(ve.begin(), ve.end());
//	for (int i = 0; i < ve.size(); i++)
//	{
//		u(ve[i].n1, ve[i].n2);
//		if (f(1) == f(N))
//		{
//			cout << ve[i].days << endl;
//			break;
//		}
//	}
//
//	return 0;
//}

//#include <iostream>
//#include <algorithm>
//#include <queue>
//#include <vector>
//#include <cstring>
//using namespace std;
//
//struct ways
//{
//	int sou, des, day;
//	ways(int s, int d, int dd) : sou(s), des(d), day(dd) {};
//
//};
//
//int n, m;
//vector<ways> vec;
//vector<int> v[100010];
//int opt[100010];
//bool vis[100010];
//
//void bfs(int k)
//{
//	queue<int> q;
//	q.push(k);
//	opt[k] = 0;
//	vis[k] = true;
//	while (!q.empty())
//	{
//		int t = q.front();
//		q.pop();
//		vis[t] = false;
//		for (int i = 0; i < v[t].size(); i++)
//		{
//			int tt = v[t][i];
//			int next = vec[tt].des;
//			int ttt = max(opt[t], vec[tt].day);
//			if (ttt < opt[next])
//			{
//				opt[next] = ttt;
//				if (!vis[next])
//				{
//					vis[next] = true;
//					q.push(next);
//				}
//			}
//		}
//	}
//}
//
//int main()
//{
//	cin >> n >> m;
//	for (int i = 1; i <= n; i++)
//		opt[i] = 1 << 30;
//	while (m--)
//	{
//		int a, b, c;
//		cin >> a >> b >> c;
//		vec.push_back(ways(a, b, c));
//		vec.push_back(ways(b, a, c));
//		v[a].push_back(vec.size() - 2);
//		v[b].push_back(vec.size() - 1);
//	}
//	bfs(1);
//	cout << opt[n] << endl;
//	return 0;
//}
//
//









//SPFA

//#include <iostream>
//#include <algorithm>
//#include <vector>
//#include <queue>
//using namespace std;
//
//#define LL long long
//
//const LL oo = 1e9;
//const LL MAXN = 1e5 + 5;
//const LL MAXM = 2 * 1e5 + 5;
//LL N, M;
//bool inq[MAXN] = { 0 };
//LL opt[MAXN];
//
//struct Edge
//{
//	Edge(LL _from, LL _to, LL _weight) :from(_from), to(_to), weight(_weight) {}
//	LL from, to;
//	LL weight;
//};
//vector<Edge> ve;
//vector<LL> v[MAXN];
//
//void bfs(LL s)
//{
//	queue<LL> q;
//	q.push(s);
//	inq[s] = true;
//	opt[s] = 0;
//	for (; !q.empty();)
//	{
//		int t = q.front();
//		q.pop();
//		inq[t] = false;
//		for (size_t i = 0; i < v[t].size(); i++)
//		{
//			LL e = v[t][i];
//			LL next = ve[e].to;
//			LL m;
//			if ((m = max(opt[t], ve[e].weight)) < opt[next])
//			{
//				opt[next] = m;
//				if (!inq[next])
//				{
//					q.push(next);
//					inq[next] = true;
//				}
//			}
//		}
//	}
//}
//
//int main()
//{
//	//  freopen("data.out", "r", stdin);
//	cin >> N >> M;
//	fill(opt + 1, opt + N + 1, oo);
//	LL f, t, w;
//	for (size_t i = 0; i < M; i++)
//	{
//		cin >> f >> t >> w;
//		ve.push_back(Edge(f, t, w));
//		ve.push_back(Edge(t, f, w));
//		v[f].push_back(ve.size() - 2);
//		v[t].push_back(ve.size() - 1);
//	}
//	bfs(1);
//	cout << opt[N] << endl;
//
//	return 0;
//}


//#include <iostream>
//#include <algorithm>
//#include <cstring>
//#include <vector>
//#include <map>
//#include <string>
//////#include<bits/stdc++.h>
//using namespace std;
//#define LL long long
//
//struct sub
//{
//	long long des;
//	long long day;
//};
//
//long long n, m;
//long long a, b, c;
//vector<sub> v[100010];
//long long pre[100010];
//int vis[100010];
//
//long long ans = 1 << 30;
//long long sum = 0;
//
//
//void dfs(long long k)
//{
//
//	if (k == n)
//	{
//		ans = min(sum, ans);
//		return;
//	}
//		
//	for (int i = 0; i < v[k].size(); i++)
//	{
//		long long last = sum;
//		
//		bool flag = false;
//		bool flag1 = false;
//		long long t = v[k][i].des;
//		long long last1 = pre[t];
//		if (vis[t])
//			continue;
//		vis[t] = 1;
//		long long d = v[k][i].day;
//		if (d > pre[t])
//		{
//			flag1 = true;
//			continue;
//		}
//			
//		pre[t] = min(pre[t], d);
//		if (sum < d)
//		{
//			sum = d;
//			flag = true;
//		}
//		//if (d >= ans || d >= pre[t])
//		//	continue;
//		//pre[t] = min(pre[t], d);
//		dfs(t);
//		vis[t] = 0;
//		if (flag)
//			sum = last;
//		if (flag1)
//			pre[t] = last1;
//	}
//}
//
//
//int main()
//{
//	memset(vis, 0, sizeof(vis));
//	cin >> n >> m;
//	for (size_t i = 0; i < m; i++)
//	{
//		cin >> a >> b >> c;
//		sub s1, s2;
//		s1.day = s2.day = c;
//		s1.des = b;
//		s2.des = a;
//		v[a].push_back(s1);
//		v[b].push_back(s2);
//	}
//	for (size_t i = 1; i <= n; i++)
//	{
//		vis[i] = 0;
//		pre[i] = 1 << 30;
//	}
//		
//	vis[1] = 1;
//	dfs(1);
//	cout << ans << endl;
//    return 0;
//}
//
