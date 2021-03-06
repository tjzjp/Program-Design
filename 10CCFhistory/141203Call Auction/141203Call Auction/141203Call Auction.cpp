// 141203Call Auction.cpp: 定义控制台应用程序的入口点。
//

//问题描述
//某股票交易所请你编写一个程序，根据开盘前客户提交的订单来确定某特定股票的开盘价和开盘成交量。
//该程序的输入由很多行构成，每一行为一条记录，记录可能有以下几种：
//1. buy p s 表示一个购买股票的买单，每手出价为p，购买股数为s。
//2. sell p s 表示一个出售股票的卖单，每手出价为p，出售股数为s。
//3. cancel i表示撤销第i行的记录。
//如果开盘价为p0，则系统可以将所有出价至少为p0的买单和所有出价至多为p0的卖单进行匹配。
//因此，此时的开盘成交量为出价至少为p0的买单的总股数和所有出价至多为p0的卖单的总股数之间的较小值。
//你的程序需要确定一个开盘价，使得开盘成交量尽可能地大。如果有多个符合条件的开盘价，你的程序应当输出最高的那一个。
//输入格式
//输入数据有任意多行，每一行是一条记录。保证输入合法。股数为不超过108的正整数，出价为精确到恰好小数点后两位的正实数，且不超过10000.00。
//输出格式
//你需要输出一行，包含两个数，以一个空格分隔。第一个数是开盘价，第二个是此开盘价下的成交量。开盘价需要精确到小数点后恰好两位。
//样例输入
//buy 9.25 100
//buy 8.88 175
//sell 9.00 1000
//buy 9.00 400
//sell 8.92 400
//cancel 1
//buy 100.00 50
//样例输出
//9.00 450
//评测用例规模与约定
//对于100%的数据，输入的行数不超过5000。

#include "stdafx.h"
#include <iostream>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <queue>

//#include <iostream>  
//#include <queue>  
//#include <cstring>  
//#include <cstdio>  
//#include <string>
//using namespace std;
//
//const int N = 5000;
//
//struct trading {
//	int orderno;
//	char t;
//	float price;
//	long long quantity;
//	bool operator < (const trading& n) const {
//		if (t == 's')
//			return price > n.price;
//		else // t == 'b'  
//			return price < n.price;
//	}
//};
//
//bool cancelflag[N + 1];
//
//int main()
//{
//	trading t;
//	priority_queue<trading> sell, buy;
//	string strading;
//
//	// 变量初始化  
//	memset(cancelflag, false, sizeof(cancelflag));
//
//	// 输入数据  
//	int no = 0, tno;
//
//	while (cin >> strading) {
//		if (strading[0] == 'c') {
//			// 设置交易号  
//			no++;
//
//			// 输入取消的交易号  
//			cin >> tno;
//
//			// 设置取消标志  
//			cancelflag[tno] = true;
//		}
//		else if (strading[0] == 'b' || strading[0] == 's') {
//			// 设置交易号  
//			t.orderno = ++no;
//
//			// 输入交易价格和数量  
//			cin >> t.price >> t.quantity;
//
//			// 将交易分别放入买入和卖出的优先队列  
//			if (strading[0] == 'b') {
//				t.t = strading[0];
//				buy.push(t);
//			}
//			else {    // t.trading[0] == 's'  
//				t.t = strading[0];
//				sell.push(t);
//			}
//		}
//		else
//			break;
//	}
//
//	// 集合竞价处理  
//	t.price = 0;
//	t.quantity = 0;
//	trading b, s;
//	for (;;) {
//		// 清除被取消的订单（同时将队头放在b和s中）  
//		while (!buy.empty()) {
//			b = buy.top();
//			if (cancelflag[b.orderno])
//				buy.pop();
//			else
//				break;
//		}
//		while (!sell.empty()) {
//			s = sell.top();
//			if (cancelflag[s.orderno])
//				sell.pop();
//			else
//				break;
//		}
//
//		// 买卖队列只要有一个为空，则处理结束  
//		if (buy.empty() || sell.empty())
//			break;
//
//		// 集合竞价处理  
//		if (b.price >= s.price) {
//			t.quantity += min(b.quantity, s.quantity);
//			t.price = b.price;
//
//			if (b.quantity == s.quantity) {
//				buy.pop();
//				sell.pop();
//			}
//			else if (b.quantity > s.quantity) {
//				b.quantity -= s.quantity;
//				buy.pop();
//				buy.push(b);
//				sell.pop();
//			}
//			else {    // b.quantity < s.quantity  
//				buy.pop();
//				s.quantity -= b.quantity;
//				sell.pop();
//				sell.push(s);
//			}
//		}
//		else
//			break;
//	}
//
//	// 输出结果  
//	printf("%.2f", t.price);
//	cout << " " << t.quantity << endl;
//
//	return 0;
//}
//#include<bits/stdc++.h>
using namespace std;

struct trading
{
	char t;
	int no;
	double price;
	long long num;
	trading(){}
	trading(char tt, int n, double p, int nn) :t(tt), no(n), price(p), num(nn) {};
	bool operator<(const trading& t1) const
	{
		if (t == 's')
			return price > t1.price;
		else
			return price < t1.price;
	}
};

priority_queue<trading> buy;
priority_queue<trading> sell;
bool iscancel[5005];

int main()
{
	char c[10];
	double p;
	long long n;
	memset(iscancel, false, sizeof(iscancel));
	int h = 0;
	while (cin >> c)
	{
		h++;
		if (c[0] == 'c')
		{
			cin >> n;
			iscancel[n] = true;
		}
		else if (c[0] == 'b')
		{
			cin >> p >> n;
			buy.push(trading('b', h, p, n));
		}
		else if (c[0] == 's')
		{
			cin >> p >> n;
			sell.push(trading('s', h, p, n));
		}
		else
			break;
	}

	trading b, s, t;
	t.num = 0;
	while (1)
	{
		while (!buy.empty())
		{
			b = buy.top();
			if (iscancel[b.no])
				buy.pop();
			else
				break;
		}
		while (!sell.empty())
		{
			s = sell.top();
			if (iscancel[s.no])
				sell.pop();
			else
				break;
		}

		if (buy.empty() || sell.empty())
			break;

		if (b.price >= s.price)
		{
			t.num += min(b.num, s.num);
			t.price = b.price;
			if (b.num == s.num)
			{
				buy.pop();
				sell.pop();
			}
			else if	(b.num < s.num)
			{
				s.num -= b.num;
				sell.pop();
				buy.pop();
				sell.push(s);
			}
			else
			{
				b.num -= s.num;
				sell.pop();
				buy.pop();
				buy.push(b);
			}
		}
		else
			break;
	}
	cout << setiosflags(ios::fixed) << setprecision(2) << t.price << ' ';
	cout << t.num << endl;
	return 0;
}

//struct pock1
//{
//	int no;
//	double price;
//	int num;
//	pock1(){}
//	pock1(int o, double p, int n) :no(o), price(p), num(n) {};
//};
//
//struct pock2
//{
//	int no;
//	double price;
//	int num;
//	pock2() {}
//	pock2(int o, double p, int n) :no(o), price(p), num(n) {};
//};
//
//bool cmp1(pock1 p1, pock1 p2)
//{
//	return p1.price > p2.price;
//}
//
//bool cmp2(pock2 p1, pock2 p2)
//{
//	return p1.price < p2.price;
//}
//
//vector<pock1> vec1;
//vector<pock2> vec2;
//int vis[5005];
//
//int main()
//{
//	char t[10];
//	double a;
//	int b;
//	int tt;
//	int c = 1;
//	while (cin >> t)
//	{
//		if (t[0] == 'c')
//		{
//			cin >> b;
//			bool flag = false;
//			for (int i = 0; i < vec1.size(); i++)
//				if (vec1[i].no == b)
//				{
//					flag = true;
//					vec1.erase(vec1.begin() + i);
//					break;
//				}
//			if (!flag)
//			{
//				for (int i = 0; i < vec2.size(); i++)
//					if (vec2[i].no == b)
//					{
//						vec2.erase(vec2.begin() + i);
//						break;
//					}
//			}
//		}
//		else
//		{
//			cin >> a >> b;
//			if (t[0] == 'b')
//				vec1.push_back(pock1(c++, a, b));
//			else if (t[0] == 's')
//				vec2.push_back(pock2(c++, a, b));
//		}
//	}
//	sort(vec1.begin(), vec1.end(), cmp1);
//	sort(vec2.begin(), vec2.end(), cmp2);
//	double pri;
//	int busum = 0;
//	int ans1 = 0;
//	double ans2 = 0;
//
//	pock1 buy;
//	pock2 sell;
//	while (vec1.size() != 0 && vec2.size() != 0)
//	{
//		buy = vec1[0];
//		sell = vec2[0];
//		if (buy.price >= sell.price)
//		{
//			ans1 += min(buy.num, sell.num);
//			ans2 = buy.price;
//			if (buy.num == sell.num)
//			{
//				vec1.erase(vec1.begin());
//				vec2.erase(vec2.begin());
//			}
//			else if (buy.num < sell.num)
//			{
//				vec2[0].num -= buy.num;
//				vec1.erase(vec1.begin());
//			}
//			else
//			{
//				vec1[0].num -= sell.num;
//				vec2.erase(vec2.begin());
//			}
//		}
//		else
//			break;
//	}
//
//	
//	cout << setiosflags(ios::fixed) << setprecision(2) << ans2 << " ";
//	cout << ans1 << endl;
//
//    return 0;
//}

