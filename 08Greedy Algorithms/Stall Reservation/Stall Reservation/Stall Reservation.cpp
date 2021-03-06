// Stall Reservation.cpp: 定义控制台应用程序的入口点。
//

//Description
//Oh those picky N(1 <= N <= 50, 000) cows!They are so picky that each one will only be milked over some precise time interval A.
//.B(1 <= A <= B <= 1, 000, 000), which includes both times A and B.
//Obviously, FJ must create a reservation system to determine which stall each cow can be assigned for her milking time.
//Of course, no cow will share such a private moment with other cows.
//
//Help FJ by determining :
//The minimum number of stalls required in the barn so that each cow can have her private milking period
//An assignment of cows to these stalls over time
//Many answers are correct for each test dataset; a program will grade your answer.
//Input
//Line 1: A single integer, N
//
//Lines 2..N + 1 : Line i + 1 describes cow i's milking interval with two space-separated integers.
//Output
//Line 1 : The minimum number of stalls the barn must have.
//
//Lines 2..N + 1 : Line i + 1 describes the stall to which cow i will be assigned for her milking period.
//Sample Input
//5
//1 10
//2 4
//3 6
//5 8
//4 7
//Sample Output
//4
//1
//2
//3
//2
//4
//Hint
//Explanation of the sample :
//
//Here's a graphical schedule for this output: 
//
//Time     1  2  3  4  5  6  7  8  9 10
//
//Stall 1 c1>>>>>>>>>>>>>>>>>>>>>>>>>>>
//
//Stall 2 ..c2>>>>>> c4>>>>>>>>> .. ..
//
//Stall 3 .. ..c3>>>>>>>>> .. .. .. ..
//
//Stall 4 .. .. ..c5>>>>>>>>> .. .. ..
//Other outputs using the same number of stalls are possible.

#include "stdafx.h"
#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;

struct Cow
{
	int a, b;
	int No;
	bool operator < (const Cow & c) const
	{
		return a < c.a;
	}
};

struct Stall
{
	int end;
	int No;
	bool operator < (const Stall & c) const
	{
		return end > c.end;
	}
	Stall(int e, int n) :end(e), No(n) {}
	Stall() {}
};

int N;
Cow cows[50050];
priority_queue<Stall> que;
int pos[50050];


int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> cows[i].a >> cows[i].b;
		cows[i].No = i;
	}
		
	sort(cows, cows + N);
	int total = 0;
	for (int i = 0; i < N; i++)
	{
		if (que.empty())
		{
			total++;
			que.push(Stall(cows[i].b, total));
			pos[cows[i].No] = total;
		}
		else
		{
			Stall pq = que.top();
			if (pq.end < cows[i].a)
			{
				que.pop();
				que.push(Stall(cows[i].b, pq.No));
				pos[cows[i].No] = pq.No;
			}
			else
			{
				total++;
				que.push(Stall(cows[i].b, total));
				pos[cows[i].No] = total;
			}
		}
	}
	cout << total << endl;
	for (int i = 0; i < N; i++)
	{
		cout << pos[i] << endl;
	}
    return 0;
}

