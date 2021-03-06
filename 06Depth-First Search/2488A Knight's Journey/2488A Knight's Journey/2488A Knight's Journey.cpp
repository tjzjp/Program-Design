// 2488A Knight's Journey.cpp: 定义控制台应用程序的入口点。
//

//描述
//Background
//The knight is getting bored of seeing the same black and white squares again and again and has decided to make a journey around the world.
//Whenever a knight moves, it is two squares in one direction and one square perpendicular to this.
//The world of a knight is the chessboard he is living on.
//Our knight lives on a chessboard that has a smaller area than a regular 8 * 8 board, but it is still rectangular.
//Can you help this adventurous knight to make travel plans ?
//
//Problem
//Find a path such that the knight visits every square once.The knight can start and end on any square of the board.
//输入
//The input begins with a positive integer n in the first line.
//The following lines contain n test cases.
//Each test case consists of a single line with two positive integers p and q, such that 1 <= p * q <= 26. 
//This represents a p * q chessboard,
//where p describes how many different square numbers 1, . . ., p exist, 
//q describes how many different square letters exist.These are the first q letters of the Latin alphabet : A, . . .
//输出
//The output for every scenario begins with a line containing "Scenario #i:", where i is the number of the scenario starting at 1. 
//Then print a single line containing the lexicographically first path that visits all squares of the chessboard 
//with knight moves followed by an empty line.
//The path should be given on a single line by concatenating the names of the visited squares.
//Each square name consists of a capital letter followed by a number.
//If no such path exist, you should output impossible on a single line.
//样例输入
//3
//1 1
//2 3
//4 3
//样例输出
//Scenario #1:
//A1
//
//Scenario #2:
//impossible
//
//Scenario #3:
//A1B3C1A2B4C2A3B1C3A4B2C4


#include "stdafx.h"
#include <iostream>
#include <cstring>
#include <queue>
#include <stack>
using namespace std;

int t, p, q;
int vis[30][30];
struct node
{
	int num;
	int lett;
};



node n[30];
int posp[8] = { -1, 1, -2, 2, -2, 2, -1, 1 };
int posq[8] = { -2, -2, -1, -1, 1, 1, 2, 2 };
bool flag;

void dfs(int a, int b, int k)
{
	if (p * q == k)
	{
		for (int i = 0; i < k; i++)
		{
			cout << (char)(n[i].lett + 'A');
			cout << (char)(n[i].num + '1');
		}
		cout << endl;
		flag = true;
	}
	else
	{
		
		for (int i = 0; i < 8; i++)
		{
			int num = a + posp[i];
			int lett = b + posq[i];
			if (num >= 0 && num < p && lett >= 0 && lett < q && !vis[num][lett] && !flag)
			{
				n[k].num = num;
				n[k].lett = lett;
				vis[num][lett] = 1;
				dfs(num, lett, k + 1);
				vis[num][lett] = 0;
			}
		}
	}
	
}

int main()
{
	cin >> t;
	int cas = 1;
	while (t--)
	{
		flag = false;
		memset(vis, 0, sizeof(vis));
		cin >> p >> q;
		
		cout << "Scenario #" << cas << ":" << endl;
		vis[0][0] = 1;
		n[0].num = 0;
		n[0].lett = 0;
		dfs(0, 0, 1);
		
		if (!flag)
			cout << "impossible" << endl;	
		cout << endl;
		cas++;
	}
    return 0;
}

