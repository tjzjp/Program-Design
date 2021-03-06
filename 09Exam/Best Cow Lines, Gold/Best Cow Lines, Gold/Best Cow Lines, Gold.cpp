// Best Cow Lines, Gold.cpp: 定义控制台应用程序的入口点。
//

//FJ is about to take his N(1 <= N <= 30, 000) cows to the annual "Farmer of the Year" competition.
//In this contest every farmer arranges his cows in a line and herds them past the judges.
//
//The contest organizers adopted a new registration scheme this year: 
//simply register the initial letter of every cow in the order they will appear
//(e.g., If FJ takes Bessie, Sylvia, and Dora in that order, he just registers BSD).
//After the registration phase ends, every group is judged in increasing lexicographic order
//(i.e., alphabetical order) according to the string of the initials of the cows' names.
//
//FJ is very busy this year and has to hurry back to his farm, so he wants to be judged as early as possible.
//He decides to rearrange his cows, who have already lined up, before registering them.
//
//FJ marks a location for a new line of the competing cows.
//He then proceeds to marshal the cows from the old line to the new one by repeatedly sending 
//either the first or last cow in the(remainder of the) original line to the end of the new line.
//When he's finished, FJ takes his cows for registration in this new order.
//
//Given the initial order of his cows, determine the least lexicographic string of initials he can make this way.
//输入
//* Line 1: A single integer : N
//
//* Lines 2..N + 1 : Line i + 1 contains a single initial('A'..'Z') of the cow in the ith position in the original line
//输出
//The least lexicographic string he can make.
//Every line(except perhaps the last one) contains the initials of 80 cows('A'..'Z') in the newline.
//样例输入
//6
//A
//C
//D
//B
//C
//B
//样例输出
//ABCBCD
//提示
//INPUT DETAILS :
//
//FJ has 6 cows in this order : ACDBCB
//
//OUTPUT DETAILS :
//
//Step   Original     New
//#1     ACDBCB
//#2      CDBCB     A
//#3      CDBC      AB
//#4      CDB       ABC
//#5      CD        ABCB
//#6       D        ABCBC
//#7                ABCBCD

#include "stdafx.h"
#include <iostream>
using namespace std;

char s[30000 + 10];
int n;

void Greedy()
{
	int a = 0;
	int b = n - 1;
	bool left;
	int count = 0;
	while (a <= b)
	{
		for (int i = 0; a + i <= b; i++)
		{
			if (s[a + i] < s[b - i])
			{
				left = true;
				break;
			}
			else if (s[a + i] > s[b - i])
			{
				left = false;
				break;
			}
		}
		if (left)
			cout << s[a++];
		else
			cout << s[b--];
		count++;
		if (count % 80 == 0)
			cout << endl;
	}
	cout << endl;
}


int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> s[i];
	Greedy();
    return 0;
}

