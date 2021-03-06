// N Queen.cpp: 定义控制台应用程序的入口点。
//

//描述
//会下国际象棋的人都很清楚：皇后可以在横、竖、斜线上不限步数地吃掉其他棋子。
//如何将8个皇后放在棋盘上（有8 * 8个方格），使它们谁也不能被吃掉！这就是著名的八皇后问题。
//对于某个满足要求的8皇后的摆放方法，定义一个皇后串a与之对应，即a = b1b2...b8，其中bi为相应摆法中第i行皇后所处的列数。
//已经知道8皇后问题一共有92组解（即92个不同的皇后串）。
//给出一个数b，要求输出第b个串。串的比较是这样的：皇后串x置于皇后串y之前，当且仅当将x视为整数时比y小。
//输入
//第1行是测试数据的组数n，后面跟着n行输入。每组测试数据占1行，包括一个正整数b(1 <= b <= 92)
//输出
//输出有n行，每行输出对应一个输入。输出应是一个正整数，是对应于b的皇后串。
//样例输入
//2
//1
//92
//样例输出
//15863724
//84136275

#include "stdafx.h"
#include <iostream>
#include <cstring>
using namespace std;

int a[100][10];
bool f[3][50];
int b[10];
int t;
int n;
int m;

void queen(int k)
{
	int i;
	if (k == 9)
	{
		m++;
		for (i = 1; i <= 8; i++)
			a[m][i] = b[i];
	}
	for (i = 1; i <= 8; i++)
	{
		if (f[0][i] && f[1][k + i] && f[2][k - i + 8])
		{
			b[k] = i;
			f[0][i] = f[1][k + i] = f[2][k - i + 8] = 0;
			
			queen(k + 1);
			f[0][i] = f[1][k + i] = f[2][k - i + 8] = 1;
		}
	}
}

int main()
{
	memset(a, 0, sizeof(a));
	memset(f, 1, sizeof(f));
	memset(b, 0, sizeof(b));
	m = 0;
	queen(1);
	cin >> t;
	while (t--)
	{
		cin >> n;
		for (int i = 1; i <= 8; i++)
			cout << a[n][i];
		cout << endl;
	}
	
	return 0;
}





























//#include <iostream>
//using namespace std;
//
//int N;
//int QueenPos[100];
//
//void Queen(int k);
//
//int main()
//{
//	cin >> N;
//	Queen(0);
//	system("pause");
//    return 0;
//}
//
//void Queen(int k)
//{
//	if (k == N)
//	{
//		for (int i = 0; i < N; i++)
//			cout << QueenPos[i] + 1 << " ";
//		cout << endl;
//		return;
//	}
//	for (int i = 0; i < N; i++)
//	{
//		int j;
//		for (j = 0; j < k; j++)
//		{
//			if (i == QueenPos[j] || abs(i - QueenPos[j]) == abs(k - j))
//				break;
//		}
//		if (j == k)
//		{
//			QueenPos[k] = i;
//			Queen(k + 1);
//		}
//	}
//}
//
