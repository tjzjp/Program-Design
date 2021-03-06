// Santa Claus‘s Gifts.cpp: 定义控制台应用程序的入口点。
//

//描述
//圣诞节来临了，在城市A中圣诞老人准备分发糖果，现在有多箱不同的糖果，每箱糖果有自己的价值和重量，每箱糖果都可以拆分成任意散装组合带走。
//圣诞老人的驯鹿最多只能承受一定重量的糖果，请问圣诞老人最多能带走多大价值的糖果。
//输入
//第一行由两个部分组成，分别为糖果箱数正整数n(1 <= n <= 100)，驯鹿能承受的最大重量正整数w（0 < w < 10000），两个数用空格隔开。
//其余n行每行对应一箱糖果，由两部分组成，分别为一箱糖果的价值正整数v和重量正整数w，中间用空格隔开。
//	输出
//	输出圣诞老人能带走的糖果的最大总价值，保留1位小数。输出为一行，以换行符结束。
//	样例输入
//	4 15
//	100 4
//	412 8
//	266 7
//	591 2
//	样例输出
//	1193.0

#include "stdafx.h"
#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;
#define eps 1e-6

struct Candy
{
	int w, v;
	bool operator < (const Candy &c)
	{
		return double(v) / w - (double)c.v / c.w > eps;
	}
};

int n, w;
Candy candy[110];
int totalw = 0;
double totalv = 0;

int main()
{
	cin >> n >> w;
	for (int i = 0; i < n; i++)
	{
		cin >> candy[i].v >> candy[i].w;
	}
	sort(candy, candy + n);
	for (int i = 0; i < n; i++)
	{
		if (candy[i].w <= w - totalw)
		{
			totalw += candy[i].w;
			totalv += candy[i].v;
		}		
		else
		{
			int s = w - totalw;
			totalv += s * ((double)candy[i].v / candy[i].w);
			break;
		}
			
	}
	cout.setf(ios::fixed);
	cout << fixed << setprecision(1) << totalv << endl;
    return 0;
}

