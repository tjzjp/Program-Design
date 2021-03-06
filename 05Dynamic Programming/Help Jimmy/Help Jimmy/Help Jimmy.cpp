// Help Jimmy.cpp: 定义控制台应用程序的入口点。
//

//Description
//"Help Jimmy" 是在下图所示的场景上完成的游戏。
//
//
//场景中包括多个长度和高度各不相同的平台。地面是最低的平台，高度为零，长度无限。
//
//Jimmy老鼠在时刻0从高于所有平台的某处开始下落，它的下落速度始终为1米 / 秒。
//当Jimmy落到某个平台上时，游戏者选择让它向左还是向右跑，
//它跑动的速度也是1米 / 秒。当Jimmy跑到平台的边缘时，开始继续下落。
//Jimmy每次下落的高度不能超过MAX米，不然就会摔死，游戏也会结束。
//
//设计一个程序，计算Jimmy到底地面时可能的最早时间。
//Input
//第一行是测试数据的组数t（0 <= t <= 20）。每组测试数据的第一行是四个整数N，X，Y，MAX，用空格分隔。
//N是平台的数目（不包括地面），
//X和Y是Jimmy开始下落的位置的横竖坐标，MAX是一次下落的最大高度。
//接下来的N行每行描述一个平台，包括三个整数，X1[i]，X2[i]和H[i]。
//H[i]表示平台的高度，X1[i]和X2[i]表示平台左右端点的横坐标。
//1 <= N <= 1000， - 20000 <= X, X1[i], X2[i] <= 20000，0 < H[i] < Y <= 20000（i = 1..N）。所有坐标的单位都是米。
//
//	Jimmy的大小和平台的厚度均忽略不计。如果Jimmy恰好落在某个平台的边缘，被视为落在平台上。所有的平台均不重叠或相连。
//测试数据保证问题一定有解。
//	Output
//	对输入的每组测试数据，输出一个整数，Jimmy到底地面时可能的最早时间。
//	Sample Input
//	1
//	3 8 17 20
//	0 10 8
//	0 10 13
//	4 14 3
//	Sample Output
//	23

#include "stdafx.h"
#include <iostream>
#include <algorithm>
using namespace std;

int t;
int n, x, y, maxh;
struct plat
{
	int x1, x2, h;
};

int compare(const void *p, const void *q)
{
	plat *p1 = (plat*)p;
	plat *q1 = (plat*)q;
	return p1->h - q1->h;
}
plat form[1005];

int dp[1005][2];
const int dif = 1e8;

void Leftjump(int k)
{
	int i = k - 1;
	while (i > 0 && form[k].h - form[i].h <= maxh)
	{
		if (form[k].x1 >= form[i].x1 && form[k].x1 <= form[i].x2)
		{
			dp[k][0] = form[k].h - form[i].h + min(dp[i][0] + form[k].x1 - form[i].x1, dp[i][1] + form[i].x2 - form[k].x1);
			return;
		}
		else
			i--;
	}
	if (form[k].h - form[i].h <= maxh)
		dp[k][0] = form[k].h - form[i].h;
	else
		dp[k][0] = dif;
}

void Rightjump(int k)
{
	int i = k - 1;
	while (i > 0 && form[k].h - form[i].h <= maxh)
	{
		if (form[k].x2 >= form[i].x1 && form[k].x2 <= form[i].x2)
		{
			dp[k][1] = form[k].h - form[i].h + min(dp[i][0] + form[k].x2 - form[i].x1, dp[i][1] + form[i].x2 - form[k].x2);
			return;
		}
		else
			i--;
	}
	if (form[k].h - form[i].h <= maxh)
		dp[k][1] = form[k].h - form[i].h;
	else
		dp[k][1] = dif;
}

int shorttimes()
{
	for (int i = 1; i <= n + 1; i++)
	{
		Leftjump(i);
		Rightjump(i);
	}
	return min(dp[n + 1][0], dp[n + 1][1]);
}

int main()
{
	cin >> t;
	while (t--)
	{
		cin >> n >> x >> y >> maxh;
		for (int i = 1; i <= n; i++)
			cin >> form[i].x1 >> form[i].x2 >> form[i].h;
		form[0].x1 = -20000;
		form[0].x2 = 20000;
		form[0].h = 0;
		form[n + 1].x1 = x;
		form[n + 1].x2 = x;
		form[n + 1].h = y;
		qsort(form, n + 1, sizeof(plat), compare);
		cout << shorttimes() << endl;
	}
	


	return 0;
}





















//#include <iostream>
//#include <algorithm>
//using namespace std;
//
//struct platform
//{
//	int x1;
//	int x2;
//	int height;
//};
//
//const int MAXN = 1010;
//const int def = 9000000;
//platform p[MAXN];
//int dp[MAXN][2];
//int N, X, Y, MAX;
//
//int compare(const void * p, const void *q)
//{
//	platform * p1 = (platform *)p;
//	platform * q1 = (platform *)q;
//	return p1->height - q1->height;
//}
//
//void LeftMinTime(int k)
//{
//	int i = k - 1;
//	while (i > 0 && p[k].height - p[i].height <= MAX)
//	{
//		if (p[k].x1 >= p[i].x1 && p[k].x1 <= p[i].x2)
//		{
//			dp[k][0] = p[k].height - p[i].height + min(dp[i][0] + p[k].x1 - p[i].x1, dp[i][1] + p[i].x2 - p[k].x1);
//			return;
//		}
//		else
//			i--;
//	}
//	if (p[k].height - p[i].height > MAX)
//		dp[k][0] = def;
//	else
//		dp[k][0] = p[k].height;  //掉到地面上
//
//}
//
//void RightMinTime(int k)
//{
//	int i = k - 1;
//	while (i > 0 && p[k].height - p[i].height <= MAX)
//	{
//		if (p[k].x2 >= p[i].x1 && p[k].x2 <= p[i].x2)
//		{
//			dp[k][1] = p[k].height - p[i].height + min(dp[i][0] + p[k].x2 - p[i].x1, dp[i][1] + p[i].x2 - p[k].x2);
//			return;
//		}
//		else
//			i--;
//	}
//	if (p[k].height - p[i].height > MAX)
//		dp[k][1] = def;
//	else
//		dp[k][1] = p[k].height;
//}
//
//int shortesttime()
//{
//	for (int i = 1; i <= N + 1; i++)
//	{
//		LeftMinTime(i);
//		RightMinTime(i);		
//	}
//	return min(dp[N + 1][0], dp[N + 1][1]);
//}
//
//
//
//int main()
//{
//	int t;
//	cin >> t;
//	while (t--)
//	{
//		cin >> N >> X >> Y >> MAX;
//		for (int i = 1; i <= N; i++)
//			cin >> p[i].x1 >> p[i].x2 >> p[i].height;
//		p[0].height = 0;
//		p[0].x1 = -20000;
//		p[0].x2 = 20000;
//		p[N + 1].x1 = p[N + 1].x2 = X;
//		p[N + 1].height = Y;
//		qsort(p, N + 2, sizeof(platform), compare);
//		cout << shortesttime() << endl;
//	}
//
//    return 0;
//}
//
