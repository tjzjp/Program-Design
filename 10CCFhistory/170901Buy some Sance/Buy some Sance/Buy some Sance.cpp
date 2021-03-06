// Buy some Sance.cpp: 定义控制台应用程序的入口点。
//

//问题描述
//小明带着N元钱去买酱油。酱油10块钱一瓶，商家进行促销，每买3瓶送1瓶，或者每买5瓶送2瓶。请问小明最多可以得到多少瓶酱油。
//输入格式
//输入的第一行包含一个整数N，表示小明可用于买酱油的钱数。N是10的整数倍，N不超过300。
//输出格式
//输出一个整数，表示小明最多可以得到多少瓶酱油。
//样例输入
//40
//样例输出
//5
//样例说明
//把40元分成30元和10元，分别买3瓶和1瓶，其中3瓶送1瓶，共得到5瓶。
//样例输入
//80
//样例输出
//11
//样例说明
//把80元分成30元和50元，分别买3瓶和5瓶，其中3瓶送1瓶，5瓶送2瓶，共得到11瓶。

#include "stdafx.h"
#include <iostream>
#include <algorithm>
using namespace std;

int f(int n)
{
	if (n <= 0)
		return 0;
	if (n <= 2)
		return n;
	if (n <= 4)
		return n + 1;
	if (n == 5)
		return n + 2;
	return max(f(n - 3) + 4, f(n - 5) + 7);
}

int main()
{
	int sum = 0;
	int mon;
	cin >> mon;
	mon = mon / 10;
	cout << f(mon) << endl;
    return 0;
}

