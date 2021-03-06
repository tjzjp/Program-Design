// Sudoku.cpp: 定义控制台应用程序的入口点。
//

//描述
//Sudoku is a very simple task.A square table with 9 rows and 9 columns is divided to 9 smaller squares 3x3 as shown on the Figure.
//In some of the cells are written decimal digits from 1 to 9. The other cells are empty.
//The goal is to fill the empty cells with decimal digits from 1 to 9, one digit per cell, in such way that in each row, 
//in each column and in each marked 3x3 subsquare, all the digits from 1 to 9 to appear.Write a program to solve a given Sudoku - task.
//
//输入
//The input data will start with the number of the test cases.For each test case, 9 lines follow, corresponding to the rows of the table.
//On each line a string of exactly 9 decimal digits is given, corresponding to the cells in this line.
//If a cell is empty it is represented by 0.
//输出
//For each test case your program should print the solution in the same format as the input data.
//The empty cells have to be filled according to the rules.If solutions is not unique, then the program may print any one of them.
//样例输入
//1
//103000509
//002109400
//000704000
//300502006
//060000050
//700803004
//000401000
//009205800
//804000107
//样例输出
//143628579
//572139468
//986754231
//391542786
//468917352
//725863914
//237481695
//619275843
//854396127

#include "stdafx.h"
#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;

struct node
{
	char f[9][9];
	int a[9][9];//mark
	int b[9][9];//row
	int c[9][9];//col
};


char ini[9][9];
queue<node> q;
node head;
node initial;

void copy(char a[9][9], char b[9][9])
{
	for (int i = 0; i < 9; i++)
		for (int j = 0; j < 9; j++)
			b[i][j] = a[i][j];
}

bool checkNoZero(char a[9][9])
{
	for (int i = 0; i < 9; i++)
		for (int j = 0; j < 9; j++)
			if (a[i][j] == '0')
				return false;
	return true;
}

bool bfs()
{	
	q.push(initial);
	while (!q.empty())
	{
		head = q.front();
		q.pop();
		if (checkNoZero(head.f))
			return true;
		int i = 0, j = 0, k = 0;
		for (i = 0; i < 9; i++)
		{
			for (j = 0; j < 9; j++)
			{
				node now = head;
				char t = now.f[i][j];
				if (t != '0')
					continue;
				for (k = 0; k < 9; k++)
				{
					node nownow = head;
					int temp = i / 3 * 3 + j / 3;
					if (!nownow.a[temp][k] && !nownow.b[i][k] && !nownow.c[j][k])
					{
						nownow.f[i][j] = char(k + '1');
						nownow.a[temp][k] = 1;
						nownow.b[i][k] = 1;
						nownow.c[j][k] = 1;
						q.push(nownow);
					}
				}
				if (k == 9)
					break;
			}
			if (k == 9)
				break;
		}
			
				
		
	}
	return false;
}

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		memset(initial.a, 0, sizeof(initial.a));
		memset(initial.b, 0, sizeof(initial.b));
		memset(initial.c, 0, sizeof(initial.c));
		for (int i = 0; i < 9; i++)
			for (int j = 0; j < 9; j++)
			{
				cin >> ini[i][j];
				if (ini[i][j] != '0')
				{
					int t = ini[i][j] - '1';
					int temp = i / 3 * 3 + j / 3;
					initial.a[temp][t] = 1;
					initial.b[i][t] = 1;
					initial.c[j][t] = 1;
				}
			}
		copy(ini, initial.f);
		if (bfs())
		{
			for (int i = 0; i < 9; i++)
			{
				for (int j = 0; j < 9; j++)
					cout << head.f[i][j];
				cout << endl;
			}

		}
		else
		{
			cout << -1 << endl;
		}

	}
	
    return 0;
}

