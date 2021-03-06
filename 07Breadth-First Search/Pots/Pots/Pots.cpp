// Pots.cpp: 定义控制台应用程序的入口点。
//

//描述
//You are given two pots, having the volume of A and B liters respectively.The following operations can be performed :
//FILL(i)        fill the pot i(1 ≤ i ≤ 2) from the tap;
//DROP(i)      empty the pot i to the drain;
//POUR(i, j)    pour from pot i to pot j; after this operation either the pot j is full(and there may be some water left in the pot i), 
//or the pot i is empty(and all its contents have been moved to the pot j).
//Write a program to find the shortest possible sequence of these operations that will yield exactly C liters of water in one of the pots.
//输入
//On the first and only line are the numbers A, B, and C.These are all integers in the range from 1 to 100 and C≤max(A, B).
//输出
//The first line of the output must contain the length of the sequence of operations K.The following K lines must each describe one operation.
//If there are several sequences of minimal length, output any one of them.If the desired result can’t be achieved, 
//the first and only line of the file must contain the word ‘impossible’.
//样例输入
//3 5 4
//样例输出
//6
//FILL(2)
//POUR(2, 1)
//DROP(1)
//POUR(2, 1)
//FILL(2)
//POUR(2, 1)

#include "stdafx.h"
#include <iostream>
#include <cstring>
#include <queue>
#include <set>
using namespace std;

struct node
{
	int a, b;
	int father;
	int i, j;
	node(int aa, int bb, int f, int ii, int jj):a(aa), b(bb), father(f), i(ii), j(jj){}
	node(){}
};

//struct node2
//{
//	int a, b;
//	node2(int aa, int bb):a(aa), b(bb){}
//	node2() {}
//};

node myque[100000];
int qHead = 0, qTail = 1;
int A, B, C;
int visited[110][110];
int ways = 0;

node ACT(node x, int i, int j)
{
	node xx;
	int a = x.a;
	int b = x.b;
	if (i == 0 && j == 0)
		a = A;
	else if (i == 0 && j == 1)
		a = 0;
	else if (i == 0 && j == 2)
		if (a > B - b)
		{
			int tmp = B - b;
			a -= tmp;
			b = B;
		}
		else
		{
			b += a;
			a = 0;
		}
	else if (i == 1 && j == 0)
		b = B;
	else if (i == 1 && j == 1)
		b = 0;
	else if(i == 1 && j == 2)
		if (b > A - a)
		{
			int tmp = A - a;
			a = A;
			b -= tmp;
		}
		else
		{
			a += b;
			b = 0;
		}
	xx = node(a, b, qHead, i, j);
	return xx;
}

bool BFS()
{
	myque[qHead] = node(0, 0, -1, -1, -1);
	visited[0][0] = 1;
	while (qHead < qTail)
	{
		node ex = myque[qHead];
		if (ex.a == C || ex.b == C)
			return true;
		for (int i = 0; i <= 1; i++)
			for (int j = 0; j <= 2; j++)
			{
				if (ex.a == 0 && i == 0 && j >= 1)
					continue;
				if (ex.b == 0 && i == 1 && j >= 1)
					continue;
				if (ex.a == A && i == 0 && j == 0)
					continue;
				if (ex.b == B && i == 1 && j == 0)
					continue;
				node ne = ACT(ex, i, j);
				if (visited[ne.a][ne.b])
					continue;
				visited[ne.a][ne.b] = 1;
				myque[qTail++] = ne;
			}
		qHead++;
	}
	return false;
}

void print(node x)
{
	if (x.father != -1)
	{
		ways++;
		print(myque[x.father]);
		if (x.i == 0 && x.j == 0)
			cout << "FILL(1)" << endl;
		else if (x.i == 1 && x.j == 0)
			cout << "FILL(2)" << endl;
		else if (x.i == 0 && x.j == 1)
			cout << "DROP(1)" << endl;
		else if (x.i == 1 && x.j == 1)
			cout << "DROP(2)" << endl;
		else if (x.i == 0 && x.j == 2)
			cout << "POUR(1,2)" << endl;
		else if (x.i == 1 && x.j == 2)
			cout << "POUR(2,1)" << endl;
	}
	else
	{
		cout << ways << endl;
	}
	
}

int main()
{
	memset(visited, 0, sizeof(visited));
	cin >> A >> B >> C;
	if (BFS())
	{
		int ways = 1;
		int f = myque[qHead].father;
		print(myque[qHead]);
	}
	else
		cout << "impossible" << endl;

    return 0;
}

