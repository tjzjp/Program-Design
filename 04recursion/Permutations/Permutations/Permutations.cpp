// Permutations.cpp: 定义控制台应用程序的入口点。
//

//描述
//给定一个由不同的小写字母组成的字符串，输出这个字符串的所有全排列。 
//我们假设对于小写字母有'a' < 'b' < ... < 'y' < 'z'，而且给定的字符串中的字母已经按照从小到大的顺序排列。
//	输入
//	输入只有一行，是一个由不同的小写字母组成的字符串，已知字符串的长度在1到6之间。
//	输出
//	输出这个字符串的所有排列方式，每行一个排列。要求字母序比较小的排列在前面。字母序如下定义：
//
//	已知S = s1s2...sk, T = t1t2...tk，则S < T 等价于，存在p(1 <= p <= k)，使得
//	s1 = t1, s2 = t2, ..., sp - 1 = tp - 1, sp < tp成立。
//样例输入
//abc
//样例输出
//abc
//acb
//bac
//bca
//cab
//cba

#include "stdafx.h"
#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;

char s[10];
char ss[100][10];
char a[10];
bool t[10];
int len;
int num = 0;

void dfs(int k)
{
	if (k == len)
	{
		a[k] = 0;
		cout << a << endl;
	}
	for (int i = 0; i < len; i++)
	{
		if (t[i])
		{
			a[k] = s[i];
			t[i] = 0;
			dfs(k + 1);
			t[i] = 1;
		}
	}

}

int main()
{
	memset(t, 1, sizeof(t));
	cin >> s;
	len = strlen(s);
	sort(s, s + len);
	dfs(0);
	
	return 0;
}


//another solution
//#include <iostream>
//#include <algorithm>
//#include <string>
//#include <cstring>
//using namespace std;
//const int M = 8;
//char s[M];
//char permutations[M] = { 0 };
//bool used[M] = { 0 };
//int L = 0;
//
//void Permutation(int n)
//{
//	if (n == L)
//	{
//		permutations[L] = 0;
//		cout << permutations << endl;
//	}
//	for (int i = 0; i < L; i++)
//	{
//		if (!used[i])
//		{
//			used[i] = true;
//			permutations[n] = s[i];
//			Permutation(n + 1);
//			used[i] = false;
//		}
//	}
//}
//
//int main()
//{
//	cin >> s;
//	L = strlen(s);
//	sort(s, s + L);
//	Permutation(0);
//	
//	return 0;
//}

//#include <iostream>
//#include <algorithm>
//#include <string>
//#include <cstring>
//using namespace std;
//
//int main()
//{
//	char s[10];
//	cin >> s;
//	int L = strlen(s);
//	sort(s, s + L);
//	do
//	{
//		for (int i = 0; i < L; i++)
//			cout << s[i];
//		cout << endl;
//	} while (next_permutation(s, s + L));
//
//	return 0;
//}

