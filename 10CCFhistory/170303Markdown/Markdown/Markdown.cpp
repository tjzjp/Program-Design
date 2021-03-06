// Markdown.cpp: 定义控制台应用程序的入口点。
//

//问题描述
//Markdown 是一种很流行的轻量级标记语言（lightweight markup language），广泛用于撰写带格式的文档。
//例如以下这段文本就是用 Markdown 的语法写成的：
//这些用 Markdown 写成的文本，尽管本身是纯文本格式，然而读者可以很容易地看出它的文档结构。
//同时，还有很多工具可以自动把 Markdown 文本转换成 HTML 甚至 Word、PDF 等格式，取得更好的排版效果。
//例如上面这段文本通过转化得到的 HTML 代码如下所示：
//本题要求由你来编写一个 Markdown 的转换工具，完成 Markdown 文本到 HTML 代码的转换工作。
//简化起见，本题定义的 Markdown 语法规则和转换规则描述如下：
//●区块：区块是文档的顶级结构。本题的 Markdown 语法有 3 种区块格式。
//在输入中，相邻两个区块之间用一个或多个空行分隔。输出时删除所有分隔区块的空行。
//○段落：一般情况下，连续多行输入构成一个段落。段落的转换规则是在段落的第一行行首插入 `<p>`，在最后一行行末插入 `< / p>`。
//○标题：每个标题区块只有一行，由若干个 `#` 开头，接着一个或多个空格，然后是标题内容，直到行末。`#` 的个数决定了标题的等级。
//转换时，`# Heading` 转换为 `<h1>Heading< / h1>`，`## Heading` 转换为 `<h2>Heading< / h2>`，以此类推。标题等级最深为 6。
//○无序列表：无序列表由若干行组成，每行由 `*` 开头，接着一个或多个空格，然后是列表项目的文字，直到行末。
//转换时，在最开始插入一行 `<ul>`，最后插入一行 `< / ul>`；对于每行，`* Item` 转换为 `<li>Item< / li>`。本题中的无序列表只有一层，不会出现缩进的情况。
//●行内：对于区块中的内容，有以下两种行内结构。
//○强调：`_Text_` 转换为 `<em>Text< / em>`。强调不会出现嵌套，每行中 `_` 的个数一定是偶数，且不会连续相邻。
//注意 `_Text_` 的前后不一定是空格字符。
//○超级链接：`[Text](Link)` 转换为 `<a href = "Link">Text< / a>`。超级链接和强调可以相互嵌套，但每种格式不会超过一层。
//输入格式
//输入由若干行组成，表示一个用本题规定的 Markdown 语法撰写的文档。
//输出格式
//输出由若干行组成，表示输入的 Markdown 文档转换成产生的 HTML 代码。
//样例输入
//# Hello
//
//Hello, world!
//样例输出
//<h1>Hello< / h1>
//<p>Hello, world!< / p>

#include "stdafx.h"
#include <iostream>
#include <string>
//#include<bits/stdc++.h>
using namespace std;


int work1(string &res, string &str, int i);
int work2(string &res, string &str, int i);

int work1(string &res, string &str, int i)
{
	res += "<a href=\"";
	int j = i;
	while (str[i] != '(')
		i++;
	i++;
	for (; str[i] != ')'; i++)
	{
		if (str[i] == '_')
			i = work2(res, str, i);
		else
			res += str[i];
	}
	res += "\">";
	int k = i;
	i = j;
	i++;
	for (; str[i] != ']'; i++)
	{
		if (str[i] == '_')
			i = work2(res, str, i);
		else
			res += str[i];
	}
	res += "</a>";
	return k;
}

int work2(string &res, string &str, int i)
{
	res += "<em>";
	i++;
	for (; str[i] != '_'; i++)
	{
		if (str[i] == '[')
			i = work1(res, str, i);
		else
			res += str[i];
	}
	res += "</em>";
	return i;
}

int main()
{
	string str, res;
	bool flag1 = false;
	bool flag2 = false;

	while (getline(cin, str))
	{
		if (str.size() == 0)
		{
			if (flag1)
			{
				flag1 = false;
				res += "</ul>";
				res += "\n";
			}
			if (flag2)
			{
				flag2 = false;
				res += "</p>";
				res += "\n";
			}
			continue;
		}
		if (str[0] == '#')
		{
			int num = 0, i;
			for (i = 0; str[i] == '#'; i++)
				num++;
			res += "<h";
			res += (num + '0');
			res += ">";
			while (str[i] == ' ')
				i++;
			for (; str[i]; i++)
			{
				if (str[i] == '[')
					i = work1(res, str, i);
				else if (str[i] == '_')
					i = work2(res, str, i);
				else
					res += str[i];
			}
			res += "</h";
			res += (num + '0');
			res += ">\n";
		}
		else if (str[0] == '*')
		{
			if (!flag1)
			{
				res += "<ul>\n";
			}

			flag1 = true;
			
			res += "<li>";
			int i = 1;
			while (str[i] == ' ')
				i++;
			for (; str[i]; i++)
			{
				if (str[i] == '[')
					i = work1(res, str, i);
				else if (str[i] == '_')
					i = work2(res, str, i);
				else
					res += str[i];
			}
			res += "</li>\n";
		}
		else
		{
			if (!flag2)
			{
				res += "<p>";
			}
			else
			{
				res += "\n";
			}
			flag2 = true;
			int i = 0;
			for (; str[i]; i++)
			{
				if (str[i] == '[')
					i = work1(res, str, i);
				else if (str[i] == '_')
					i = work2(res, str, i);
				else
					res += str[i];
			}
		}
	}
	if (flag1)
	{
		flag1 = false;
		res += "</ul>";
		res += "\n";
	}
	if (flag2)
	{
		flag2 = false;
		res += "</p>";
		res += "\n";
	}
	cout << res;
	return 0;
}




















//40fen
//#include <iostream>
//#include <string>
//#include <cstring>
////#include<bits/stdc++.h>
//using namespace std;
//
//
//
//int main()
//{
//	string line;
//	bool flag1 = false, flag2 = false;
//	string reline[10005];
//	int hang = 0;
//	bool flag3 = false;
//	string link, text;
//	while (getline(cin, line))
//	{
//		if (line == "")
//		{
//			flag1 = true;
//			flag2 = false;
//			continue;
//		}
//		
//		int istitle = 0;
//		bool list = false;
//
//		for (int i = 0; i < line.size(); i++)
//		{
//			if (line[i] == '#' && istitle < 6)
//			{
//				istitle++;
//				while (line[i + 1] == ' ')
//				{
//					i++;
//				}
//				continue;
//			}
//			else if (line[i] == '*')
//			{
//				list = true;
//				while (line[i + 1] == ' ')
//					i++;
//				continue;
//			}
//			else if (line[i] == '_')
//			{
//				if (!flag3)
//				{
//					flag3 = true;
//					reline[hang] += "<em>";
//				}
//				else
//				{
//					flag3 = false;
//					reline[hang] += "</em>";
//				}
//				continue;
//			}
//			else if (line[i] == '[')
//			{
//				i++;
//				while (line[i] != ']')
//				{
//					if (line[i] == '_')
//					{
//						if (!flag3)
//						{
//							flag3 = true;
//							text += "<em>";
//						}
//						else
//						{
//							flag3 = false;
//							text += "</em>";
//						}
//						i++;
//						continue;
//					}
//					text += line[i];
//					i++;
//				}
//				continue;
//			}
//			
//			else if (line[i] == '(')
//			{
//				i++;
//				while (line[i] != ')')
//				{
//					if (line[i] == '_')
//					{
//						if (!flag3)
//						{
//							flag3 = true;
//							link += "<em>";
//						}
//						else
//						{
//							flag3 = false;
//							link += "</em>";
//						}
//						i++;
//						continue;
//					}
//					link += line[i];
//					i++;
//				}
//				reline[hang] += ("<a href=\"" + link + "\">" + text + "</a>");
//				link = "";
//				text = "";
//				continue;
//			}
//			
//			reline[hang] += line[i];
//		}
//		if (istitle)
//		{
//			string t1 = "<h";
//			string t2 = "</h";
//			string num;
//			num = (char)(istitle + '0');
//			t1 = t1 + num + ">";
//			t2 = t2 + num + '>';
//			reline[hang] = t1 + reline[hang] + t2;
//		}
//		else if (list)
//		{
//			string t1 = "<ul>";
//			string t2 = "</ul>";
//			string t3 = "<li>";
//			string t4 = "</li>";
//			string t5 = reline[hang];
//			if (flag1 && flag2)
//			{
//				reline[hang - 1] = t3 + t5 + t4;
//				reline[hang] = t2;
//			}
//			if (flag1 && !flag2)
//			{
//				reline[hang++] = t1;
//				reline[hang++] = t3 + t5 + t4;
//				reline[hang] = t2;
//				flag2 = true;
//			}
//		}
//		else if (!istitle)
//		{
//			string t1 = "<p>";
//			string t2 = "</p>";
//			if (flag1 && flag2)
//			{
//				int si = reline[hang - 1].size();
//				reline[hang - 1] = reline[hang - 1].substr(0, si - 4);
//				reline[hang] = reline[hang] + t2;
//			}
//			if (flag1 && !flag2)
//			{
//				reline[hang] = t1 + reline[hang] + t2;
//				flag2 = true;
//			}
//			
//			
//		}
//		
//		hang++;
//		
//	}
//	for (int i = 0; i < hang; i++)
//		cout << reline[i] << endl;
//    return 0;
//}
//
