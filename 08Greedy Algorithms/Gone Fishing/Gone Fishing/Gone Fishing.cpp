// Gone Fishing.cpp: 定义控制台应用程序的入口点。
//

//描述
//John is going on a fishing trip.He has h hours available(1 <= h <= 16), and there are n lakes in the area(2 <= n <= 25) all reachable along a single, 
//one - way road.John starts at lake 1, but he can finish at any lake he wants.He can only travel from one lake to the next one, 
//but he does not have to stop at any lake unless he wishes to.For each i = 1, ..., n - 1, 
//the number of 5 - minute intervals it takes to travel from lake i to lake i + 1 is denoted ti(0 < ti <= 192).For example, 
//t3 = 4 means that it takes 20 minutes to travel from lake 3 to lake 4. To help plan his fishing trip, John has gathered some information about the lakes.
//For each lake i, the number of fish expected to be caught in the initial 5 minutes, denoted fi(fi >= 0), 
//is known.Each 5 minutes of fishing decreases the number of fish expected to be caught in the next 5 - minute interval by a constant rate of di(di >= 0).
//If the number of fish expected to be caught in an interval is less than or equal to di, there will be no more fish left in the lake in the next interval.
//To simplify the planning, John assumes that no one else will be fishing at the lakes to affect the number of fish he expects to catch.
//	Write a program to help John plan his fishing trip to maximize the number of fish expected to be caught.
//The number of minutes spent at each lake must be a multiple of 5.
//	输入
//	You will be given a number of cases in the input.Each case starts with a line containing n.This is followed by a line containing h.Next, 
//there is a line of n integers specifying fi(1 <= i <= n), then a line of n integers di(1 <= i <= n), and finally, a line of n - 1 integers ti(1 <= i <= n - 1).
//Input is terminated by a case in which n = 0.
//	输出
//	For each test case, print the number of minutes spent at each lake, separated by commas,
//for the plan achieving the maximum number of fish expected to be caught(you should print the entire plan on one line even if it exceeds 80 characters).
//This is followed by a line containing the number of fish expected.
//	If multiple plans exist, choose the one that spends as long as possible at lake 1, even if no fish are expected to be caught in some intervals.
//If there is still a tie, choose the one that spends as long as possible at lake 2, and so on.Insert a blank line between cases.
//	样例输入
//	2
//	1
//	10 1
//	2 5
//	2
//	4
//	4
//	10 15 20 17
//	0 3 4 3
//	1 2 3
//	4
//	4
//	10 15 50 30
//	0 3 4 3
//	1 2 3
//	0
//	样例输出
//	45, 5
//	Number of fish expected : 31
//
//	240, 0, 0, 0
//	Number of fish expected : 480
//
//	115, 10, 50, 35
//	Number of fish expected : 724

#include "stdafx.h"
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

struct Lake
{
	int initialfish;
	int nowfish;
	int decrease;
	int fromlast;
};

Lake lakes[30];
int n;
int hour;
int intervals;
int fishinter;
int fishsort[30][1000];
int totalfish[30];
int finalsumfish;
int endlake;

int waytimecost(int lak)
{
	int sum = 0;
	for (int i = 1; i <= lak; i++)
	{
		sum += lakes[i].fromlast;
	}
	return sum;
}

int bestlake(int lak, int inter)
{
	int maxfish = -1;
	int maxlake;
	for (int i = 1; i <= lak; i++)
	{
		if (lakes[i].nowfish > maxfish)
		{
			maxfish = max(maxfish, lakes[i].nowfish);
			maxlake = i;
		}	
	}
	if (maxfish <= 0)
		return -1;
	return maxlake;
}

void resetfish()
{
	for (int i = 1; i <= n; i++)
	{
		lakes[i].nowfish = lakes[i].initialfish;
	}
}

int main()
{
	while (cin >> n && n != 0)
	{
		cin >> hour;
		memset(fishsort, 0, sizeof(fishsort));
		memset(totalfish, 0, sizeof(totalfish));
		finalsumfish = -1;
		intervals = hour * 60 / 5;
		for (int i = 1; i <= n; i++)
		{
			cin >> lakes[i].initialfish;
		}
		for (int i = 1; i <= n; i++)
			cin >> lakes[i].decrease;
		lakes[1].fromlast = 0;
		for (int i = 2; i <= n; i++)
			cin >> lakes[i].fromlast;
		for (int i = 1; i <= n; i++)
		{
			fishinter = intervals - waytimecost(i);
			resetfish();
			for (int j = 1; j <= fishinter; j++)
			{
				int best = bestlake(i, j);
				if (best == -1)
				{
					fishsort[i][1] += (fishinter - j + 1);
					break;
				}	
				totalfish[i] += lakes[best].nowfish;
				fishsort[i][best]++;
				if (lakes[best].nowfish >= lakes[best].decrease)
				{
					lakes[best].nowfish -= lakes[best].decrease;
				}
				else
					lakes[best].nowfish = 0;
			}
		}
		for (int i = 1; i <= n; i++)
		{
			if (totalfish[i] > finalsumfish)
			{
				finalsumfish = max(finalsumfish, totalfish[i]);
				endlake = i;
			}	
		}
		int i;
		for (i = 1; i < n; i++)
		{
			cout << fishsort[endlake][i] * 5 << ", ";
		}
		cout << fishsort[endlake][i] * 5;
		cout << endl;
		cout << "Number of fish expected: " << finalsumfish << endl;
		cout << endl;

	}
    return 0;
}

