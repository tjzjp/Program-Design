// 150304Network Delay.cpp: 定义控制台应用程序的入口点。
//

//问题描述
//给定一个公司的网络，由n台交换机和m台终端电脑组成，交换机与交换机、交换机与电脑之间使用网络连接。
//交换机按层级设置，编号为1的交换机为根交换机，层级为1。
//其他的交换机都连接到一台比自己上一层的交换机上，其层级为对应交换机的层级加1。所有的终端电脑都直接连接到交换机上。
//当信息在电脑、交换机之间传递时，每一步只能通过自己传递到自己所连接的另一台电脑或交换机。
//请问，电脑与电脑之间传递消息、或者电脑与交换机之间传递消息、或者交换机与交换机之间传递消息最多需要多少步。
//输入格式
//输入的第一行包含两个整数n, m，分别表示交换机的台数和终端电脑的台数。
//第二行包含n - 1个整数，分别表示第2、3、……、n台交换机所连接的比自己上一层的交换机的编号。
//第i台交换机所连接的上一层的交换机编号一定比自己的编号小。
//第三行包含m个整数，分别表示第1、2、……、m台终端电脑所连接的交换机的编号。
//输出格式
//输出一个整数，表示消息传递最多需要的步数。
//样例输入
//4 2
//1 1 3
//2 1
//样例输出
//4
//样例说明
//样例的网络连接模式如下，其中圆圈表示交换机，方框表示电脑：
//
//其中电脑1与交换机4之间的消息传递花费的时间最长，为4个单位时间。
//样例输入
//4 4
//1 2 2
//3 4 4 4
//样例输出
//4
//样例说明
//样例的网络连接模式如下：
//
//其中电脑1与电脑4之间的消息传递花费的时间最长，为4个单位时间。
//评测用例规模与约定
//前30%的评测用例满足：n ≤ 5, m ≤ 5。
//前50%的评测用例满足：n ≤ 20, m ≤ 20。
//前70%的评测用例满足：n ≤ 100, m ≤ 100。
//所有评测用例都满足：1 ≤ n ≤ 10000，1 ≤ m ≤ 10000。

#include "stdafx.h"
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
//#include<bits/stdc++.h>
using namespace std;

int ans = 0;
int n, m;
vector<int> vec[10001 * 2];
int vis[10001 * 2];

struct node
{
	int des, depth;
	friend bool operator<(const node &n, const node &n1)
	{
		return n.depth > n1.depth;
	}
	node(){}
	node(int d, int de) :des(d), depth(de) {}
};

queue<node> q[10001 * 2];
int d[10001 * 2];

int bfs(int k, int &p)
{
	int ans = 0;
	memset(vis, 0, sizeof(vis));
	memset(d, 0, sizeof(d));
	q[k].push(node(k, 0));
	vis[k] = 1;
	d[k] = 0;
	p = k;
	int depth = 0;
	while (!q[k].empty())
	{
		node t = q[k].front();
		q[k].pop();
		int de = t.des;
		for (int i = 0; i < vec[de].size(); i++)
		{
			int tt = vec[de][i];
			if (!vis[tt])
			{
				d[tt] = d[de] + 1;
				if (d[tt] > ans)
				{
					p = tt;
					ans = d[tt];
				}
				vis[tt] = 1;
				q[k].push(node(tt, t.depth + 1));
			}
			
			
		}
	}
	return ans;
}

int main()
{
	cin >> n >> m;
	int i;
	for (i = 2; i <= n; i++)
	{
		int a;
		cin >> a;
		vec[i].push_back(a);
		vec[a].push_back(i);
	}
	for (i = n + 1; i <= n + m; i++)
	{
		int b;
		cin >> b;
		vec[i].push_back(b);
		vec[b].push_back(i);
	}
	memset(vis, 0, sizeof(vis));
	int p;
	ans = bfs(1, p);

	ans = max(ans, bfs(p, p));
	cout << ans << endl;
    return 0;
}

