// Eight.cpp: 定义控制台应用程序的入口点。
//

//描述
//The 15 - puzzle has been around for over 100 years; even if you don't know it by that name, you've seen it.
//It is constructed with 15 sliding tiles, 
//each with a number from 1 to 15 on it, and all packed into a 4 by 4 frame with one tile missing.
//Let's call the missing tile 'x'; the object of the puzzle is to arrange the tiles so that they are ordered as: 
//1  2  3  4
//5  6  7  8
//9 10 11 12
//13 14 15  x
//
//where the only legal operation is to exchange 'x' with one of the tiles with which it shares an edge.
//As an example, the following sequence of moves solves a slightly scrambled puzzle :
//1  2  3  4    1  2  3  4    1  2  3  4    1  2  3  4
//5  6  7  8    5  6  7  8    5  6  7  8    5  6  7  8
//9  x 10 12    9 10  x 12    9 10 11 12    9 10 11 12
//13 14 11 15   13 14 11 15   13 14  x 15   13 14 15  x
//r->d->r->
//
//The letters in the previous row indicate which neighbor of the 'x' tile is swapped with the 'x' tile at each step; 
//legal values are 'r', 'l', 'u' and 'd', for right, left, up, and down, respectively.
//
//Not all puzzles can be solved; in 1870, a man named Sam Loyd was famous for distributing an unsolvable version of the puzzle, and
//frustrating many people.
//In fact, all you have to do to make a regular puzzle into an unsolvable one is to swap two tiles
//(not counting the missing 'x' tile, of course).
//
//In this problem, you will write a program for solving the less well - known 8 - puzzle, composed of tiles on a three by three
//arrangement.
//输入
//You will receive a description of a configuration of the 8 puzzle.
//The description is just a list of the tiles in their initial positions, with the rows listed from top to bottom, 
//and the tiles listed from left to right within a row, where the tiles are represented by numbers 1 to 8, plus 'x'.
//For example, this puzzle
//1  2  3
//x  4  6
//7  5  8
//
//is described by this list:
//
//1 2 3 x 4 6 7 5 8
//输出
//You will print to standard output either the word ``unsolvable'', if the puzzle has no solution, 
//or a string consisting entirely of the letters 'r', 'l', 'u' and 'd' that describes a series of moves that produce a solution.
//The string should include no spaces and start at the beginning of the line.
//样例输入
//2  3  4  1  5  x  7  6  8
//样例输出
//ullddrurdllurdruldr

#include "stdafx.h"
#include <iostream>
#include <cstring>
#include <queue>
#include <string>
#include <set>
using namespace std;

struct node
{
	int father;
	char move;
	int status;
	node(){}
	node(int f, char m, int sss) :father(f), move(m), status(sss) {}
};

string t;
char tt[10];
set<int> q;
char moves[4] = { 'u', 'l', 'r', 'd' };
node myque[400000];
int qHead = 0, qTail = 1;

int Newstatus(int i, int status)
{
	char temp[10];
	int pos;
	sprintf_s(temp, "%09d", status);
	for (int i = 0; i < 9; i++)
		if (temp[i] == '0')
		{
			pos = i;
			break;
		}
	switch (i)
	{
		case 0:
			if (pos < 3)
				return -1;
			else
			{
				temp[pos] = temp[pos - 3];
				temp[pos - 3] = '0';
			}
			break;
		case 1:
			if (pos % 3 == 0)
				return -1;
			else
			{
				temp[pos] = temp[pos - 1];
				temp[pos - 1] = '0';
			}
			break;
		case 2:
			if (pos % 3 == 2)
				return -1;
			else
			{
				temp[pos] = temp[pos + 1];
				temp[pos + 1] = '0';
			}
			break;
		case 3:
			if (pos > 5)
				return -1;
			else
			{
				temp[pos] = temp[pos + 3];
				temp[pos + 3] = '0';
			}
			break;
	}
	return atoi(temp);
}

bool bfs()
{
	while (qHead != qTail)
	{
		node n = myque[qHead];
		if (n.status == 123456780)
			return true;
		for (int i = 0; i < 4; i++)
		{
			int c = Newstatus(i, n.status);
			if (c == -1)
				continue;
			if (q.find(c) != q.end())
				continue;
			q.insert(c);
			myque[qTail++] = node(qHead, i, c);
			
		}
		qHead++;
	}
	return false;
}


int main()
{
	getline(cin, t);
	int j = 0;
	for (int i = 0; i < t.size(); i++)
	{
		if (t[i] != ' ')
			if (t[i] == 'x')
				tt[j++] = '0';
			else
				tt[j++] = t[i];
	}
	int start = atoi(tt);
	q.insert(start);
	myque[qHead] = node(-1, -1, start);
	
	char result[400000];
	int move = 0;
	if (bfs())
	{
		int pos = qHead;
		while (pos)
		{
			int aa = myque[pos].move;
			char a = moves[aa];
			result[move++] = a;
			pos = myque[pos].father;
		}
		for (int i = move - 1; i >= 0; i--)
			cout << result[i];
	}
	else
		cout << "unsolvable";
	cout << endl;
	return 0;
}


























//#include <iostream>
//#include <cstring>
//#include <set>
//using namespace std;
//
//const int MAXS = 400000;
//int goalStatus = 123456780;
//char result[MAXS];
//struct node
//{
//	int status;
//	int father;
//	char move;
//	node(int a,int b,char c):status(a),father(b), move(c){}
//	node(){}
//};
//char moves[4] = {'r', 'l', 'u', 'd'};
//int qHead = 0;
//int qTail = 1;
//node myque[MAXS];
//
//int NewStatus(int status, char move)
//{
//	char tmp[20];
//	int zeroPos;
//	sprintf_s(tmp, "%09d", status);
//	for (int i = 0; i < 9; i++)
//	{
//		if (tmp[i] == '0')
//		{
//			zeroPos = i;
//			break;
//		}
//	}
//	switch (move)
//	{
//		case 'r':
//			if (zeroPos % 3 == 2)
//				return -1;
//			else
//			{
//				tmp[zeroPos] = tmp[zeroPos + 1];
//				tmp[zeroPos + 1] = '0';
//			}
//			break;
//		case 'l':
//			if (zeroPos % 3 == 0)
//				return -1;
//			else
//			{
//				tmp[zeroPos] = tmp[zeroPos - 1];
//				tmp[zeroPos - 1] = '0';
//			}
//			break;
//		case 'u':
//			if (zeroPos <= 2)
//				return -1;
//			else
//			{
//				tmp[zeroPos] = tmp[zeroPos - 3];
//				tmp[zeroPos - 3] = '0';
//			}
//			break;
//		case 'd':
//			if (zeroPos >= 6)
//				return -1;
//			else
//			{
//				tmp[zeroPos] = tmp[zeroPos + 3];
//				tmp[zeroPos + 3] = '0';
//			}
//			break;
//	}
//	return atoi(tmp);
//}
//
//bool Bfs(int status)
//{
//	int newstatus;
//	set<int> expanded;
//	myque[qHead] = node(status, -1, 0);
//	expanded.insert(status);
//	while (qHead != qTail)
//	{
//		status = myque[qHead].status;
//		if (status == goalStatus)
//			return true;
//		for (int i = 0; i < 4; i++)
//		{
//			newstatus = NewStatus(status, moves[i]);
//			if (newstatus == -1)
//				continue;
//			if (expanded.find(newstatus) != expanded.end())
//				continue;
//			expanded.insert(newstatus);
//			myque[qTail++] = node(newstatus, qHead, moves[i]);
//		}
//		qHead++;
//	}
//	return false;
//}
//
//int main()
//{
//	char line1[50], line2[50];
//	while (cin.getline(line1, 48))
//	{
//		int i, j;
//		for (i = 0, j = 0; line1[i]; i++)
//		{
//			if (line1[i] != ' ')
//			{
//				if (line1[i] == 'x')
//					line2[j++] = '0';
//				else
//					line2[j++] = line1[i];
//			}
//		}
//		line2[j] = 0;
//		if (Bfs(atoi(line2)))
//		{
//			int moves = 0;
//			int pos = qHead;
//			do
//			{
//				result[moves++] = myque[pos].move;
//				pos = myque[pos].father;
//			} while (pos);
//			for (int i = moves - 1; i >= 0; i--)
//			{
//				cout << result[i];
//			}
//		}
//		else
//			cout << "unsolvbale" << endl;
//	}
//    return 0;
//}
//
