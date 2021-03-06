// Word Sequence.cpp: 定义控制台应用程序的入口点。
//

//描述
//给出两个单词（开始单词和结束单词）以及一个词典。找出从开始单词转换到结束单词，所需要的最短转换序列。转换的规则如下：
//1、每次只能改变一个字母
//2、转换过程中出现的单词(除开始单词和结束单词)必须存在于词典中
//例如：
//开始单词为：hit
//结束单词为：cog
//词典为：[hot, dot, dog, lot, log, mot]
//那么一种可能的最短变换是： hit->hot->dot->dog->cog,
//所以返回的结果是序列的长度5；
//注意：
//1、如果不能找到这种变换，则输出0；
//2、词典中所有单词长度一样；
//3、所有的单词都由小写字母构成；
//4、开始单词和结束单词可以不在词典中。
//输入
//共两行，第一行为开始单词和结束单词（两个单词不同），以空格分开。第二行为若干的单词（各不相同），以空格分隔开来，表示词典。单词长度不超过5, 单词个数不超过30。
//输出
//输出转换序列的长度。
//样例输入
//hit cog
//hot dot dog lot log
//样例输出
//5
//
#include "stdafx.h"
#include <iostream>
#include <cstring>
#include <algorithm>
#include <string>
#include <queue>
using namespace std;

struct Change
{
	string s;
	int step;
};

int cnt = 0;
string des;
string s[35];
int len;
queue<Change> myque;
int vis[35];

void bfs()
{
	Change first;
	first.s = s[0];
	first.step = 0;
	myque.push(first);
	vis[0] = 1;
	while (!myque.empty())
	{
		Change now = myque.front();
		if (now.s == des)
		{
			cout << now.step + 1<< endl;
			return;
		}
		myque.pop();
		for (int i = 1; i < cnt; i++)
		{
			int t = 0;
			for (int j = 0; j < len; j++)
			{
				if (now.s[j] != s[i][j])
					t++;
			}	
			if (t == 1 && !vis[i])
			{
				vis[i] = 1;
				Change ADD;
				ADD.s = s[i];
				ADD.step = now.step + 1;
				myque.push(ADD);
			}
		}
	}
	cout << "0" << endl;
}

int main()
{
	memset(vis, 0, sizeof(vis));
	cin >> s[0] >> des;
	cnt = 1;
	while (cin >> s[cnt++]);
	s[cnt - 1] = des;
	len = des.length();
	bfs();
    return 0;
}

//#include <iostream>
//#include <string>
//#include <cstdio>
//using namespace std;
//
//int main()
//{
//	int i = 0;
//	string s[50];
//	while (cin >> s[i++]);
//	for (int j = 0; j < i; j++)
//		cout << s[i] << endl;
//	return 0;
//}