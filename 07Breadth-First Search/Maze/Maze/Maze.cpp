// Maze.cpp: 定义控制台应用程序的入口点。
//

//Description
//Acm, a treasure - explorer, is exploring again.This time he is in a special maze, in which there are some doors(at most 5 doors, 
//represented by 'A', 'B', 'C', 'D', 'E' respectively).In order to find the treasure, Acm may need to open doors.However, 
//to open a door he needs to find all the door's keys (at least one) in the maze first.
//For example, if there are 3 keys of Door A, to open the door he should find all the 3 keys first (that's three 'a's which denote the keys of 'A' in the maze).
//Now make a program to tell Acm whether he can find the treasure or not.Notice that Acm can only go up, down, left and right in the maze.
//Input
//The input consists of multiple test cases.The first line of each test case contains two integers M and N(1 < N, M < 20), 
//which denote the size of the maze.The next M lines give the maze layout, with each line containing N characters.
//A character is one of the following : 'X' (a block of wall, which the explorer cannot enter), '.' (an empty block), 'S' (the start point of Acm), 
//'G' (the position of treasure), 'A', 'B', 'C', 'D', 'E' (the doors), 'a', 'b', 'c', 'd', 'e' (the keys of the doors).The input is terminated with two 0's. 
//This test case should not be processed. 
//	Output
//	For each test case, in one line output "YES" if Acm can find the treasure, or "NO" otherwise.
//	Sample Input
//	4 4
//	S.X.
//	a.X.
//	..XG
//	....
//	3 4
//	S.Xa
//	.aXB
//	b.AG
//	0 0
//	Sample Output
//	YES
//	NO

#include "stdafx.h"
#include <iostream>
#include <cstring>
using namespace std;

int step[4][2] = { {-1,0}, {1, 0}, {0, -1}, {0, 1} };
char s[25];
int M, N;
char map[25][25];
int startx, starty;
int key[10];
int fkey[10];
int vis[25][25];
int ok = 0;
int research = 1;

void reset(int i)
{
	for(int j = 0; j < M; j++)
		for (int k = 0; k < N; k++)
		{
			if (map[j][k] == char(i + 'a') || map[j][k] == char(i + 'A'))
				map[j][k] = '.';
		}
}

void dfs(int x, int y)
{
	if (ok || research)
		return;
	if (map[x][y] == 'G')
	{
		ok = 1;
		return;
	}
	vis[x][y] = 1;
	if (map[x][y] == 'X')
		return;
	if (map[x][y] >= 'A' && map[x][y] <= 'E')
		return;
	if (map[x][y] >= 'a' && map[x][y] <= 'e')
	{
		int num = map[x][y] - 'a';
		fkey[num]++;
		if (fkey[num] == key[num])
		{
			reset(num);
			research = 1;
			return;
		}
	}
	for (int i = 0; i < 4; i++)
	{
		int xx = x + step[i][0];
		int yy = y + step[i][1];
		if (xx < 0 || yy < 0 || xx >= M || yy >= N ||vis[xx][yy])
			continue;
		vis[xx][yy] = 1;
		dfs(xx, yy);
	}
}

int main()
{
	while (cin >> M >> N)
	{
		if (M == 0 && N == 0)
			break;
		memset(key, 0, sizeof(key));
		memset(fkey, 0, sizeof(fkey));
		for (int i = 0; i < M; i++)
		{
			cin >> s;
			for (int j = 0; j < N; j++)
			{
				map[i][j] = s[j];
				if (s[j] == 'S')
					startx = i, starty = j;
				else if (s[j] >= 'a' && s[j] <= 'e')
					key[s[j] - 'a']++;
			}
		}
		for (int i = 0; i < 5; i++)
			if (key[i] == 0)
				reset(i);
		//cout << "done" << endl;

		ok = 0;
		research = 1;
		while (research)
		{
			research = 0;
			memset(vis, 0, sizeof(vis));
			memset(fkey, 0, sizeof(fkey));
			vis[startx][starty] = 1;
			dfs(startx, starty);
		}

		if (ok)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	
    return 0;
}

