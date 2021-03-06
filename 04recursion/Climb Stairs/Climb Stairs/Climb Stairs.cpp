// Climb Stairs.cpp: 定义控制台应用程序的入口点。
//

//描述
//树老师爬楼梯，他可以每次走1级或者2级，输入楼梯的级数，求不同的走法数
//例如：楼梯一共有3级，他可以每次都走一级，或者第一次走一级，第二次走两级
//也可以第一次走两级，第二次走一级，一共3种方法。
//输入
//输入包含若干行，每行包含一个正整数N，代表楼梯级数，1 <= N <= 30
//输出
//不同的走法数，每一行输入对应一行输出
//样例输入
//5
//8
//10
//样例输出
//8
//34
//89

#include "stdafx.h"
#include <iostream>
#include <cstring>
using namespace std;

long long t[35];
int visited[35];

long long f(int n)
{
	if (visited[n])
		return t[n];
	if (n == 1)
	{
		visited[n] = 1;
		t[n] = 1;
		return 1;
	}
		
	else if (n == 2)
	{
		visited[n] = 1;
		t[n] = 2;
		return 2;
	}
	else
	{
		visited[n] = 1;
		t[n] = f(n - 1) + f(n - 2);
		return t[n];
	}
		
}

int main()
{
	memset(visited, 0, sizeof(visited));
	int n;
	while (cin >> n)
	{
		cout << f(n) << endl;
	}
	
	return 0;
}


























//#include <iostream>
//using namespace std;
//
//int stairs(int n)
//{
//	if (n == 1)
//		return 1;
//	if (n == 2)
//		return 2;
//	return stairs(n - 1) + stairs(n - 2);
//}
//
//int main()
//{
//	while (1)
//	{
//		int n;
//		cin >> n;
//		cout << stairs(n) << endl;;
//	}
//    return 0;
//}
//
