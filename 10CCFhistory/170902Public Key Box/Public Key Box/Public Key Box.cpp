// Public Key Box.cpp: 定义控制台应用程序的入口点。
//

//问题描述
//有一个学校的老师共用N个教室，按照规定，所有的钥匙都必须放在公共钥匙盒里，老师不能带钥匙回家。
//每次老师上课前，都从公共钥匙盒里找到自己上课的教室的钥匙去开门，上完课后，再将钥匙放回到钥匙盒中。
//钥匙盒一共有N个挂钩，从左到右排成一排，用来挂N个教室的钥匙。
//一串钥匙没有固定的悬挂位置，但钥匙上有标识，所以老师们不会弄混钥匙。
//每次取钥匙的时候，老师们都会找到自己所需要的钥匙将其取走，而不会移动其他钥匙。
//每次还钥匙的时候，还钥匙的老师会找到最左边的空的挂钩，将钥匙挂在这个挂钩上。
//如果有多位老师还钥匙，则他们按钥匙编号从小到大的顺序还。
//如果同一时刻既有老师还钥匙又有老师取钥匙，则老师们会先将钥匙全还回去再取出。
//今天开始的时候钥匙是按编号从小到大的顺序放在钥匙盒里的。
//有K位老师要上课，给出每位老师所需要的钥匙、开始上课的时间和上课的时长，
//假设下课时间就是还钥匙时间，请问最终钥匙盒里面钥匙的顺序是怎样的？
//输入格式
//输入的第一行包含两个整数N, K。
//接下来K行，每行三个整数w, s, c，分别表示一位老师要使用的钥匙编号、开始上课的时间和上课的时长。
//可能有多位老师使用同一把钥匙，但是老师使用钥匙的时间不会重叠。
//保证输入数据满足输入格式，你不用检查数据合法性。
//输出格式
//输出一行，包含N个整数，相邻整数间用一个空格分隔，依次表示每个挂钩上挂的钥匙编号。
//样例输入
//5 2
//4 3 3
//2 2 7
//样例输出
//1 4 3 2 5
//样例说明
//第一位老师从时刻3开始使用4号教室的钥匙，使用3单位时间，所以在时刻6还钥匙。
//第二位老师从时刻2开始使用钥匙，使用7单位时间，所以在时刻9还钥匙。
//每个关键时刻后的钥匙状态如下（X表示空）：
//时刻2后为1X345；
//时刻3后为1X3X5；
//时刻6后为143X5；
//时刻9后为14325。
//样例输入
//5 7
//1 1 14
//3 3 12
//1 15 12
//2 7 20
//3 18 12
//4 21 19
//5 30 9
//样例输出
//1 2 3 5 4
//评测用例规模与约定
//对于30%的评测用例，1 ≤ N, K ≤ 10, 1 ≤ w ≤ N, 1 ≤ s, c ≤ 30；
//对于60%的评测用例，1 ≤ N, K ≤ 50，1 ≤ w ≤ N，1 ≤ s ≤ 300，1 ≤ c ≤ 50；
//对于所有评测用例，1 ≤ N, K ≤ 1000，1 ≤ w ≤ N，1 ≤ s ≤ 10000，1 ≤ c ≤ 100。

#include "stdafx.h"
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

struct teacher
{
	int w, s, c;
	friend bool operator< (teacher t, teacher tt)
	{
		if (t.c == tt.c)
			return t.w < tt.w;
		return t.c < tt.c;
	}
};

struct teacher1
{
	int w, s, c;
	friend bool operator< (teacher1 t, teacher1 tt)
	{
		return t.s < tt.s;
	}
		
};

teacher tea[1010];
teacher1 tea1[1010];
int box[1010];
int n, k;
int w, s, c;
int mini = 10010, maxi = 0;

int main()
{
	cin >> n >> k;
	for (int i = 0; i < n; i++)
		box[i] = i + 1;
	for (int i = 0; i < k; i++)
	{
		cin >> w >> s >> c;
		c = s + c;
		tea[i].w = w;
		tea[i].s = s;
		tea[i].c = c;
		tea1[i].w = w;
		tea1[i].s = s;
		tea1[i].c = c;
		mini = min(mini, s);
		maxi = max(maxi, c);
	}
	sort(tea, tea + k);
	sort(tea1, tea1 + k);
	for (int i = mini, k = 0, k1 = 0; i <= maxi; i++)
	{
		while (i == tea[k].c)
		{
			for (int j = 0; j < n; j++)
				if (box[j] == 0)
				{
					box[j] = tea[k].w;
					k++;
					break;
				}
		}
		while (i == tea1[k1].s)
		{
			for (int j = 0; j < n; j++)
				if (box[j] == tea1[k1].w)
				{
					box[j] = 0;
					k1++;
					break;
				}
		}
	}
	for (int i = 0; i < n; i++)
		cout << box[i] << " ";
	cout << endl;
	return 0;
}





























//#include <iostream>
//#include <queue>
//#include <map>
//#include <algorithm>
//#include <cstring>
//using namespace std;
//
//struct teacher
//{
//	int w, s, t;
//	teacher(){}
//	teacher(int ww, int ss, int tt)
//	{
//		w = ww;
//		s = ss;
//		t = tt;
//	}
//	friend bool operator<(teacher t1, teacher t2)
//	{
//		if (t1.t == t2.t)
//			return t1.w > t2.w;
//		return t1.t > t2.t;
//	}
//};
//
//struct teacher1
//{
//	int w, s, t;
//	teacher1() {}
//	teacher1(int ww, int ss, int tt)
//	{
//		w = ww;
//		s = ss;
//		t = tt;
//	}
//	friend bool operator<(teacher1 t1, teacher1 t2)
//	{
//		if (t1.t == t2.t)
//			return t1.w > t2.w;
//		return t1.s > t2.s;
//	}
//};
//
//int a[1005];
//int n, k;
//
//int main()
//{
//	priority_queue<teacher> q;
//	priority_queue<teacher1> q1;
//	int box[1005];
//	memset(box, 0, sizeof(box));
//	cin >> n >> k;
//	for (int i = 1; i <= n; i++)
//		box[i] = i;
//	for (int i = 0; i < k; i++)
//	{
//		int w, s, c;
//		cin >> w >> s >> c;
//		int t = s + c;
//		q.push(teacher(w, s, t));
//		q1.push(teacher1(w, s, t));
//	}
//
//	while (!q.empty())
//	{
//		teacher tea = q.top();
//		q.pop();
//		int t = tea.t;
//		while (!q1.empty())
//		{
//			teacher1 tea1 = q1.top();
//			if (tea1.s < t)
//			{
//				for (int i = 1; i <= n; i++)
//					if (box[i] == tea1.w)
//					{
//						box[i] = 0;
//						break;
//					}	
//			}
//			else
//				break;
//			q1.pop();
//		}
//		for (int i = 1; i <= n; i++)
//			if (box[i] == 0)
//			{
//				box[i] = tea.w;
//				break;
//			}
//	}
//	
//	for (int i = 1; i <= n; i++)
//		cout << box[i] << " ";
//	cout << endl;
//    return 0;
//}
//
