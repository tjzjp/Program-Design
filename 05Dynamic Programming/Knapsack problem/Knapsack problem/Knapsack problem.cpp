// Knapsack problem.cpp: 定义控制台应用程序的入口点。
//

//Description
//Bessie has gone to the mall's jewelry store and spies a charm bracelet. 
//Of course, she'd like to fill it with the best charms possible from the N(1 ≤ N ≤ 3, 402) available charms.
//Each charm i in the supplied list has a weight Wi(1 ≤ Wi ≤ 400), a 'desirability' factor Di(1 ≤ Di ≤ 100), 
//and can be used at most once.Bessie can only support a charm bracelet whose weight is no more than M(1 ≤ M ≤ 12, 880).
//Given that weight limit as a constraint and a list of the charms with their weights and desirability rating, 
//deduce the maximum possible sum of ratings.
//Input
//* Line 1: Two space - separated integers : N and M
//* Lines 2..N + 1 : Line i + 1 describes charm i with two space - separated integers : Wi and Di
//Output
//* Line 1 : A single integer that is the greatest sum of charm desirabilities 
//that can be achieved given the weight constraints
//Sample Input
//4 6
//1 4
//2 6
//3 12
//2 7
//Sample Output
//23

#include "stdafx.h"
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;


int n, m;
int w[35000], d[35000];
int ways[12880];

int main()
{
	
	cin >> n >> m;
	memset(ways, 0, sizeof(ways));
	for (int i = 1; i <= n; i++)
	{
		cin >> w[i] >> d[i];
		
	}
	for (int i = 1; i <= n; i++)
		for (int j = m; j >= w[i]; j--)
		{
			ways[j] = max(ways[j], ways[j - w[i]] + d[i]);
		}
	cout << ways[m] << endl;
	return 0;
}





















//#include <iostream>
//#include <algorithm>
//#include <cstring>
//using namespace std;
//
//int N, M;
//int wi[35000], di[35000];
//int ways[35000];
//
//int main()
//{
//	cin >> N >> M;
//	memset(ways, 0, sizeof(ways));
//	for (int i = 1; i <= N; i++)
//		cin >> wi[i] >> di[i];
//
//	for (int i = 1; i <= N; i++)
//		for (int j = M; j >= wi[i]; j--)
//			ways[j] = max(ways[j], ways[j - wi[i]] + di[i]);
//	cout << ways[M] << endl;
//
//    return 0;
//}
//
