// 150904Expressway.cpp: 定义控制台应用程序的入口点。
//

//问题描述
//某国有n个城市，为了使得城市间的交通更便利，该国国王打算在城市之间修一些高速公路，
//由于经费限制，国王打算第一阶段先在部分城市之间修一些单向的高速公路。
//现在，大臣们帮国王拟了一个修高速公路的计划。
//看了计划后，国王发现，有些城市之间可以通过高速公路直接（不经过其他城市）或间接（经过一个或多个其他城市）到达，而有的却不能。
//如果城市A可以通过高速公路到达城市B，而且城市B也可以通过高速公路到达城市A，则这两个城市被称为便利城市对。
//国王想知道，在大臣们给他的计划中，有多少个便利城市对。
//输入格式
//输入的第一行包含两个整数n, m，分别表示城市和单向高速公路的数量。
//接下来m行，每行两个整数a, b，表示城市a有一条单向的高速公路连向城市b。
//输出格式
//输出一行，包含一个整数，表示便利城市对的数量。
//样例输入
//5 5
//1 2
//2 3
//3 4
//4 2
//3 5
//样例输出
//3
//样例说明
//
//城市间的连接如图所示。有3个便利城市对，它们分别是(2, 3), (2, 4), (3, 4)，请注意(2, 3)和(3, 2)看成同一个便利城市对。
//评测用例规模与约定
//前30%的评测用例满足1 ≤ n ≤ 100, 1 ≤ m ≤ 1000；
//前60%的评测用例满足1 ≤ n ≤ 1000, 1 ≤ m ≤ 10000；
//所有评测用例满足1 ≤ n ≤ 10000, 1 ≤ m ≤ 100000。

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <cstring>
#include <algorithm>
//#include<bits/stdc++.h>
using namespace std;

const int N = 10005;
vector<int> G[N];
int vis[N];

int time;
int LOW[N], DFN[N];
stack<int> s;
int istack[N];
int result = 0;

void dfs(int k)
{
	LOW[k] = DFN[k] = time++;
	vis[k] = 1;
	s.push(k);
	istack[k] = 1;
	for (int i = 0; i < G[k].size(); i++)
	{
		int t = G[k][i];
		if (!vis[t])
		{
			dfs(t);
			LOW[k] = min(LOW[t], LOW[k]);
		}
		else
			LOW[k] = min(LOW[t], LOW[k]);
	}
	int cnt = 0;
	int m;
	if (LOW[k] == DFN[k])
	{
		do
		{
			m = s.top();
			s.pop();
			istack[m] = 0;
			cnt++;
		} while (m != k);
		if (cnt > 1)
			result += (cnt - 1) * cnt / 2;
	}
}

int main()
{
	
	int n, m, a, b;
	cin >> n >> m;
	while (m--)
	{
		cin >> a >> b;
		G[a].push_back(b);
	}
	memset(vis, 0, sizeof(vis));
	
	for (int i = 1; i <= n; i++)
	{
		time = 1;
		if (!vis[i])
		{
			dfs(i);
		}
	}
	cout << result << endl;
	return 0;
}


//const int N = 10005;
//int n;          
//int DFN[N];
//int LOW[N];
//int time;      
//stack<int> s;  
//vector<int> G[N];
//int vis[N];    
//int instack[N]; 
//int result;
//
//void tarjan(int u) {
//	DFN[u] = LOW[u] = ++time; 
//	s.push(u);
//	instack[u] = 1;
//	vis[u] = 1;
//	for (int j = 0; j<G[u].size(); j++) {
//		int v = G[u][j];
//		if (vis[v] == 0) {
//			tarjan(v);
//			LOW[u] = min(LOW[u], LOW[v]);
//		}
//		else if (instack[v]) {
//			LOW[u] = min(LOW[u], DFN[v]);
//		}
//	}
//	int m;
//	int cnt = 0; 
//	if (DFN[u] == LOW[u]) {
//		do {
//			m = s.top();
//			instack[m] = 0;
//			s.pop();
//			cnt++;
//		} while (m != u);
//		if (cnt>1) {
//			result += cnt*(cnt - 1) / 2; 
//		}
//	}
//}
//int main() {
//
//	int m; 
//
//	cin >> n >> m;
//	result = 0; 
//	time = 0;
//	memset(vis, 0, sizeof(vis));
//
//	memset(G, 0, sizeof(G));
//	memset(DFN, 0, sizeof(DFN));
//	memset(LOW, 0, sizeof(LOW));
//	memset(instack, 0, sizeof(instack));
//	for (int i = 0; i<m; i++) {
//		int a, b;
//		cin >> a >> b;
//		G[a].push_back(b);
//	}
//	for (int i = 1; i <= n; i++) {
//		if (vis[i] == 0) {
//			vis[i] = 1;
//			tarjan(i);
//		}
//	}
//	cout << result << endl;;
//	return 0;
//}

//int n, m;
//int a, b;
//vector<int> vec[10010];
//int vis[10010][10010];
//
//int find(int x)
//{
//	return 0;
//}
//
//void dfs(int k)
//{
//	queue<int> q;
//	q.push(k);
//	while (!q.empty())
//	{
//		int tt = q.front();
//		q.pop();
//		for (int i = 0; i < vec[tt].size(); i++)
//		{
//			int t = vec[tt][i];
//			if (vis[k][t])
//				continue;
//			vis[k][t] = 1;
//			q.push(t);
//		}
//	}
//	
//}
//
//int main()
//{
//	cin >> n >> m;
//	memset(vis, 0, sizeof(vis));
//	while (m--)
//	{
//		cin >> a >> b;
//		vec[a].push_back(b);
//	}
//
//	for (int i = 1; i <= n; i++)
//	{
//		dfs(i);
//	}
//
//	int count = 0;
//	for (int i = 1; i <= n; i++)
//		for (int j = i + 1; j <= n; j++)
//		{
//			if (vis[i][j] && vis[j][i])
//				count++;
//		}
//	cout << count << endl;
//    return 0;
//}
//
