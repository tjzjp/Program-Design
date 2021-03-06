// Radar Installation.cpp: 定义控制台应用程序的入口点。
//

//描述
//Assume the coasting is an infinite straight line.Land is in one side of coasting, sea in the other.
//Each small island is a point locating in the sea side.And any radar installation, locating on the coasting, can only cover d distance, 
//so an island in the sea can be covered by a radius installation, if the distance between them is at most d.
//
//We use Cartesian coordinate system, defining the coasting is the x - axis.The sea side is above x - axis, and the land side below.
//Given the position of each island in the sea, and given the distance of the coverage of the radar installation, 
//your task is to write a program to find the minimal number of radar installations to cover all the islands.
//Note that the position of an island is represented by its x - y coordinates.
//
//Figure A Sample Input of Radar Installations
//输入
//The input consists of several test cases.The first line of each case contains two integers n(1 <= n <= 1000) and d, 
//where n is the number of islands in the sea and d is the distance of coverage of the radar installation.
//This is followed by n lines each containing two integers representing the coordinate of the position of each island.Then a blank line follows to separate the cases.
//
//The input is terminated by a line containing pair of zeros
//输出
//For each test case output one line consisting of the test case number followed by the minimal number of radar installations needed. 
//"-1" installation means no solution for that case.
//样例输入
//3 2
//1 2
//- 3 1
//2 1
//
//1 2
//0 2
//
//0 0
//样例输出
//Case 1: 2
//Case 2 : 1

#include "stdafx.h"
#include <iostream>
#include <algorithm>
using namespace std;

struct pos
{
	int x, y;
	double nl, nr;
	bool operator < (const pos a) const
	{
		return nl < a.nl;
	}
};

int n, d;
pos isl[1010];
int total;
int flag;
int t = 0;

int main()
{
	while (cin >> n >> d)
	{
		t++;
		total = 0;
		flag = 0;
		if (n == 0 && d == 0)
			break;
		for (int i = 0; i < n; i++)
		{
			cin >> isl[i].x >> isl[i].y;
			if (isl[i].y > d)
				flag = 1;
			double tmp = sqrt(d * d - isl[i].y * isl[i].y);
			isl[i].nl = isl[i].x - tmp;
			isl[i].nr = isl[i].x + tmp;
		}
		if (flag)
		{
			cout << "Case " << t << ": -1" << endl;
			continue;
		}
			

		sort(isl, isl + n);
		double minnr = -1000000000;
		for (int i = 0; i < n; i++)
		{
			if (isl[i].nl <= minnr)
				minnr = min(minnr, isl[i].nr);
			else
			{
				total++;
				minnr = isl[i].nr;
			}
		}
		cout << "Case " << t << ": " << total << endl;
	}
	
    return 0;
}

