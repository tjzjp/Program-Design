// N Queen.cpp: 定义控制台应用程序的入口点。
//

//样例
//4
//2 4 1 3
//3 1 4 2

#include "stdafx.h"
#include <iostream>
using namespace std;

int N;
int QueenPos[100];

void Queen(int k);

int main()
{
	cin >> N;
	Queen(0);
	system("pause");
    return 0;
}

void Queen(int k)
{
	if (k == N)
	{
		for (int i = 0; i < N; i++)
			cout << QueenPos[i] + 1 << " ";
		cout << endl;
		return;
	}
	for (int i = 0; i < N; i++)
	{
		int j;
		for (j = 0; j < k; j++)
		{
			if (i == QueenPos[j] || abs(i - QueenPos[j]) == abs(k - j))
				break;
		}
		if (j == k)
		{
			QueenPos[k] = i;
			Queen(k + 1);
		}
	}
}

