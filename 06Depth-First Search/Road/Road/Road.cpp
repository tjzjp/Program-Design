// Road.cpp: 定义控制台应用程序的入口点。
//

//Description
//N cities named with numbers 1 ... N are connected with one - way roads.Each road has two parameters associated with it : 
//the road length and the toll that needs to be paid for the road(expressed in the number of coins).
//Bob and Alice used to live in the city 1. After noticing that Alice was cheating in the card game they liked to play, 
//Bob broke up with her and decided to move away - to the city N.He wants to get there as quickly as possible, but he is short on cash.
//
//We want to help Bob to find the shortest path from the city 1 to the city N that he can afford with the amount of money he has.
//Input
//The first line of the input contains the integer K, 0 <= K <= 10000, maximum number of coins that Bob can spend on his way.
//The second line contains the integer N, 2 <= N <= 100, the total number of cities.
//
//The third line contains the integer R, 1 <= R <= 10000, the total number of roads.
//
//Each of the following R lines describes one road by specifying integers S, D, L and T separated by single blank characters :
//S is the source city, 1 <= S <= N
//D is the destination city, 1 <= D <= N
//L is the road length, 1 <= L <= 100
//T is the toll(expressed in the number of coins), 0 <= T <= 100
//
//Notice that different roads may have the same source and destination cities.
//Output
//The first and the only line of the output should contain the total length of the shortest path from the city 1 to the city N 
//whose total toll is less than or equal K coins.
//If such path does not exist, only number - 1 should be written to the output.
//Sample Input
//5
//6
//7
//1 2 2 3
//2 4 3 3
//3 4 2 4
//1 3 4 1
//4 6 2 1
//3 5 2 0
//5 4 3 2
//Sample Output
//11

#include "stdafx.h"
#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

struct Roads
{
	int des, len, rol;
};
vector<Roads> vec[110];
int K, N, R, S, D, L, T;
int toll;
int ans2 = 1 << 30;
int leng;
int vis[110];
int minL[110][10010];

void dfs(int k)
{
	if (toll > K)
		return;
	if (leng >= ans2)
		return;
	
	if (k == N)
	{
		if (toll <= K)
			if (leng < ans2)
				ans2 = leng;
		return;
	}
	for (int i = 0; i < vec[k].size(); i++)
	{
		Roads  rs;
		rs = vec[k][i];
		if (rs.len + leng >= minL[rs.des][toll + rs.rol])
			continue;
		if (!vis[rs.des])
		{
			toll += rs.rol;
			leng += rs.len;
			minL[rs.des][toll] = min(minL[rs.des][toll], leng);
			vis[rs.des] = 1;
			dfs(rs.des);
			vis[rs.des] = 0;
			leng -= rs.len;
			toll -= rs.rol;
		}
	}
		

}

int main()
{
	cin >> K >> N >> R;
	toll = 0;
	leng = 0;
	memset(vis, 0, sizeof(vis));
	for (int i = 0; i < R; i++)
	{
		cin >> S >> D >> L >> T;
		Roads r;
		r.des = D;
		r.len = L;
		r.rol = T;
		vec[S].push_back(r);
	}
	for (int i = 0; i < 110; i++)
		for (int j = 0; j < 10010; j++)
			minL[i][j] = 1 << 30;
	vis[1] = 1;
	dfs(1);
	if (ans2 < (1 << 30))
		cout << ans2 << endl;
	else
		cout << "-1" << endl;
	return 0;
}


























//#include <iostream>
//#include <cstring>
//#include <vector>
//#include <algorithm>
//using namespace std;
//
//struct Road
//{
//	int d, L, t;
//};
//
//vector <vector <Road>> G(110);
//int minL[110][10010];
//int totalCost;
//int totalLen;
//int minLen;
//int K, N, R;
//int visited[110];
//
//void DFS(int k)
//{
//	if (k == N)
//	{
//			minLen = min(minLen, totalLen);
//			return;
//	}
//	for (int i = 0; i < G[k].size(); i++)
//	{
//		Road r = G[k][i];
//		if (visited[r.d])
//			continue;
//		if (totalCost + r.t > K)
//			continue;
//		if (totalLen + r.L >= minLen)
//			continue;
//		if (totalLen + r.L >= minL[r.d][totalCost + r.t])
//			continue;
//		totalCost += r.t;
//		totalLen += r.L;
//		minL[r.d][totalCost + r.t] = totalLen;
//		visited[k] = 1;
//		DFS(r.d);
//		totalCost -= r.t;
//		totalLen -= r.L;
//		visited[k] = 0;
//	}
//}
//
//int main()
//{
//	cin >> K >> N >> R;
//	for (int i = 0; i < R; i++)
//	{
//		int s;
//		Road r;
//		cin >> s >> r.d >> r.L >> r.t;
//		if (s != r.d)
//			G[s].push_back(r);
//	}
//	memset(visited, 0, sizeof(visited));
//	for (int i = 0; i < 110; i++)
//		for (int j = 0; j < 10010; j++)
//			minL[i][j] = 1 << 30;
//	minLen = 1 << 30;
//	visited[1] = 1;
//	totalLen = 0;
//	totalCost = 0;
//	DFS(1);
//	if (minLen < (1 << 30))
//		cout << minLen << endl;
//	else
//		cout << "-1" << endl;
//    return 0;
//}
//
