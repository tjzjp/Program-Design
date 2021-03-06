// skiing.cpp: 定义控制台应用程序的入口点。
//

//描述
//Michael喜欢滑雪百这并不奇怪， 因为滑雪的确很刺激。可是为了获得速度，滑的区域必须向下倾斜，而且当你滑到坡底，
//你不得不再次走上坡或者等待升降机来载你。
//Michael想知道载一个区域中最长的滑坡。区域由一个二维数组给出。数组的每个数字代表点的高度。下面是一个例子
//1  2  3  4 5
//16 17 18 19 6
//15 24 25 20 7
//14 23 22 21 8
//13 12 11 10 9
//
//一个人可以从某个点滑向上下左右相邻四个点之一，当且仅当高度减小。在上面的例子中，一条可滑行的滑坡为24 - 17 - 16 - 1。
//当然25 - 24 - 23 - ... - 3 - 2 - 1更长。事实上，这是最长的一条。
//输入
//输入的第一行表示区域的行数R和列数C(1 <= R, C <= 100)。下面是R行，每行有C个整数，代表高度h，0 <= h <= 10000。
//输出
//输出最长区域的长度。
//样例输入
//5 5
//1 2 3 4 5
//16 17 18 19 6
//15 24 25 20 7
//14 23 22 21 8
//13 12 11 10 9
//样例输出
//25

#include "stdafx.h"
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

struct node
{
	int i, j, h;
}A[105 * 105];

bool comp(node a, node b)
{
	return a.h < b.h;
}

int R, C;
int ways[105][105];
int a[105][105];

void maxn(int k)
{
	int i = A[k].i;
	int j = A[k].j;
	if (A[k].h > a[i - 1][j])
		ways[i][j] = max(ways[i][j], ways[i - 1][j] + 1);
	if (A[k].h > a[i + 1][j])
		ways[i][j] = max(ways[i][j], ways[i + 1][j] + 1);
	if (A[k].h > a[i][j - 1])
		ways[i][j] = max(ways[i][j], ways[i][j - 1] + 1);
	if (A[k].h > a[i][j + 1])
		ways[i][j] = max(ways[i][j], ways[i][j + 1] + 1);
}

int main()
{
	cin >> R >> C;
	int ans = 0;
	memset(ways, 0, sizeof(ways));
	int num = 0;
	for (int i = 1; i <= R; i++)
		for (int j = 1; j <= C; j++)
		{
			cin >> a[i][j];
			A[num].i = i;
			A[num].j = j;
			A[num++].h = a[i][j];
			ways[i][j] = 1;
		}
	sort(A, A + num, comp);
			
	for (int i = 0; i < num; i++)
		maxn(i);

	for (int i = 1; i <= R; i++)
		for (int j = 1; j <= C; j++)
			ans = max(ans, ways[i][j]);
	cout << ans << endl;
	return 0;
}































//#include <iostream>
//#include <algorithm>
//using namespace std;
//
//int C, R;
//int L[100][100];
//int h[100][100];
//
//struct node
//{
//	int i;
//	int j;
//	int h;
//}A[100*100];
//
//bool cmp(node a, node b)
//{
//	return a.h < b.h;
//}
//
//void Longest(int num)
//{
//	int i = A[num].i;
//	int j = A[num].j;
//	if (h[i][j] > h[i - 1][j])
//		L[i][j] = max(L[i][j], L[i - 1][j] + 1);
//	if (h[i][j] > h[i + 1][j])
//		L[i][j] = max(L[i][j], L[i + 1][j] + 1);
//	if (h[i][j] > h[i][j - 1])
//		L[i][j] = max(L[i][j], L[i][j - 1] + 1);
//	if (h[i][j] > h[i][j + 1])
//		L[i][j] = max(L[i][j], L[i][j + 1] + 1);
//}
//
//int main()
//{
//	int ans = 0;
//	int num = 0;
//	memset(h, 0, sizeof(h));
//	memset(L, 0, sizeof(L));
//	cin >> R >> C;
//	for (int i = 1; i <= R; i++)
//		for (int j = 1; j <= C; j++)
//		{
//			cin >> h[i][j];
//			A[num].i = i;
//			A[num].j = j;
//			A[num++].h = h[i][j];
//			L[i][j] = 1;
//		}
//	sort(A, A + num, cmp);
//	
//	for (int i = 0; i < num; i++)
//		Longest(i);
//	for (int i = 1; i <= R; i++)
//		for (int j = 1; j <= C; j++)
//			ans = max(ans, L[i][j]);
//
//	cout << ans << endl;
//    return 0;
//}