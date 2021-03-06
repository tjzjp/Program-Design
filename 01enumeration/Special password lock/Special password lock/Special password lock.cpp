// Special password lock.cpp: 定义控制台应用程序的入口点。
//

//描述
//有一种特殊的二进制密码锁，由n个相连的按钮组成（n<30），按钮有凹 / 凸两种状态，用手按按钮会改变其状态。
//	然而让人头疼的是，当你按一个按钮时，跟它相邻的两个按钮状态也会反转。
//当然，如果你按的是最左或者最右边的按钮，该按钮只会影响到跟它相邻的一个按钮。
//	当前密码锁状态已知，需要解决的问题是，你至少需要按多少次按钮，才能将密码锁转变为所期望的目标状态。
//	输入
//	两行，给出两个由0、1组成的等长字符串，表示当前 / 目标密码锁状态，其中0代表凹，1代表凸。
//	输出
//	至少需要进行的按按钮操作次数，如果无法实现转变，则输出impossible。
//	样例输入
//	011
//	000
//	样例输出
//	1

#include "stdafx.h"
#include <iostream>
#include <cstring>
using namespace std;

char ori[50];
char des[50];
int ope[50];
int orig[50];
int dest[50];
int ans = 50;

void guess(int len)
{
	for (int i = 1; i < len; i++)
		ope[i + 1] = (orig[i] + ope[i] + ope[i - 1] + dest[i]) % 2;
	if ((ope[len] + ope[len - 1] + orig[len]) % 2 == dest[len])
	{
		int temp = 0;
		for (int i = 1; i <= len; i++)
			temp += ope[i];
		if (temp < ans)
		{
			ans = temp;
		}
	}
}


void emu(int len)
{
	for (ope[1] = 0; ope[1] < 2; ope[1]++)
	{
		guess(len);
	}
	if (ans == 50)
		cout << "impossible" << endl;
	else
		cout << ans << endl;
}

int main()
{
	memset(ope, 0, sizeof(ope));
	cin >> ori;
	cin >> des;
	for (int i = 1; i <= strlen(ori); i++)
	{
		orig[i] = ori[i - 1] - '0';
		dest[i] = des[i - 1] - '0';
	}
	emu(strlen(ori));
	return 0;
}







































//#include <iostream>
//#include <string>
//using namespace std;
//
//int oriLock;
//int Lock;
//int destLock;
//
//int GetBit(int c, int i)
//{
//	return (c >> i) & 1;
//}
//
//void SetBit(int &c, int i, int v)
//{
//	if (v)
//	{
//		c |= (1 << i);
//	}
//	else 
//	{
//		c &= ~(1 << i);
//	}
//}
//
//void FlipBit(int &c, int i)
//{
//	c ^= (1 << i);
//}
//
//int main()
//{
//	char line[50];
//	cin >> line;
//	int N = strlen(line);
//	for (int i = 0; i < N; i++)
//	{
//		SetBit(oriLock, i, line[i] - '0');
//	}
//	cin >> line;
//	for (int i = 0; i < N; i++)
//	{
//		SetBit(destLock, i, line[i] - '0');
//	}
//	for (int i = 0; i < 2; i++)
//	{
//		Lock = oriLock;
//		int count = 0;
//		int curButton = i;
//		for (int j = 0; j < N; j++)
//		{
//			if (curButton)
//			{
//				count++;
//				if (j > 0)
//					FlipBit(Lock, j - 1);
//				FlipBit(Lock, j);
//				if (j < N - 1)
//					FlipBit(Lock, j + 1);
//			}
//			if (GetBit(Lock, j) != GetBit(destLock, j))
//				curButton = 1;
//			else
//				curButton = 0;
//		}
//		if (Lock == destLock)
//		{
//			cout << count << endl;
//			break;
//		}
//	}
//	system("pause");
//    return 0;
//}
//
