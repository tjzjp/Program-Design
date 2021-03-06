// Zipper.cpp: 定义控制台应用程序的入口点。
//

//描述
//Given three strings, you are to determine whether the third string can be formed by combining the characters in the first two strings.
//The first two strings can be mixed arbitrarily, but each must stay in its original order.
//
//For example, consider forming "tcraete" from "cat" and "tree":
//
//String A : cat
//String B : tree
//String C : tcraete
//
//As you can see, we can form the third string by alternating characters from the two strings.As a second example, 
//consider forming "catrtee" from "cat" and "tree" :
//
//	String A : cat
//	String B : tree
//	String C : catrtee
//
//	Finally, notice that it is impossible to form "cttaree" from "cat" and "tree".
//	输入
//	The first line of input contains a single positive integer from 1 through 1000. It represents the number of data sets to follow.
//The processing for each data set is identical.The data sets appear on the following lines, one data set per line.
//
//	For each data set, the line of input consists of three strings, separated by a single space.
//All strings are composed of upper and lower case letters only.
//The length of the third string is always the sum of the lengths of the first two strings.
//The first two strings will have lengths between 1 and 200 characters, inclusive.
//	输出
//	For each data set, print:
//
//		Data set n : yes
//
//			if the third string can be formed from the first two, or
//
//				Data set n : no
//
//				if it cannot.Of course n should be replaced by the data set number.See the sample output below for an example.
//					样例输入
//					3
//					cat tree tcraete
//					cat tree catrtee
//					cat tree cttaree
//					样例输出
//					Data set 1: yes
//					Data set 2 : yes
//					Data set 3 : no

#include "stdafx.h"
#include <iostream>
#include <cstring>;
using namespace std;

char valid[210][210][410];
int l1, l2, l3;
char s1[210], s2[210], s3[410];

bool check(int a, int b, int c)
{
	if (c == l3)
		if (a == l1 && b == l2)
			return true;
		else
			return false;
	if (valid[a][b][c] != -1)
		return valid[a][b][c];
	bool b1 = false, b2 = false;
	if (s1[a] == s3[c])
		b1 = check(a + 1, b, c + 1);
	if (s2[b] == s3[c])
		b2 = check(a, b + 1, c + 1);
	valid[a][b][c] = b1 || b2;
	return b1 || b2;
}

int main()
{
	
	int t;
	int n = 0;
	
	cin >> t;
	while (t--)
	{
		cin >> s1 >> s2 >> s3;
		memset(valid, 0xff, sizeof(valid));
		l1 = strlen(s1);
		l2 = strlen(s2);
		l3 = strlen(s3);
		if (check(0, 0, 0))
			cout << "Data set " << ++n << ": yes" << endl;
		else
			cout << "Data set " << ++n << ": no" << endl;
	}
	return 0;
}































//#include <iostream>
//#include <string>
//#include <cstring>
//using namespace std;
//
//char s1[300], s2[300];
//char des[1000];
//int t;
//int L1, L2, L3;
//char valid[210][210][410];
//
//bool Valid(int as, int bs, int cs)
//{
//	if (cs == L3)
//		if (as == L1 && bs == L2)
//			return true;
//		else
//			return false;
//	if (valid[as][bs][cs] != -1)
//		return valid[as][bs][cs];
//	bool b1 = false, b2 = false;
//	if (s1[as] == des[cs])
//		b1 = Valid(as + 1, bs, cs + 1);
//	if (s2[bs] == des[cs])
//		b2 = Valid(as, bs + 1, cs + 1);
//	valid[as][bs][cs] = b1 || b2;
//	return b1 || b2;
//}
//
//int main()
//{
//	int n = 0;
//	cin >> t;
//	while (t--)
//	{
//		scanf_s("%s%s%s", s1, s2, des);
//		L1 = strlen(s1);
//		L2 = strlen(s2);
//		L3 = strlen(des);
//		memset(valid, 0xff, sizeof(valid));
//		if (Valid(0, 0, 0))
//			printf_s("Data set %d: yes\n", ++n);
//		else
//			printf_s("Data set %d: no\n", ++n);
//	}
//    return 0;
//}

