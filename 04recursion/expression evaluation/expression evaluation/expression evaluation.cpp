// expression evaluation.cpp: 定义控制台应用程序的入口点。
//

//描述
//求一个可以带括号的小学算术四则运算表达式的值
//输入
//一行，一个四则运算表达式。'*'表示乘法，'/'表示除法
//输出
//一行，该表达式的值，保留小数点后面两位
//样例输入
//输入样例1：
//3.4
//输入样例2:
//7 + 8.3
//输入样例3 :
//	3 + 4.5*(7 + 2)*(3)*((3 + 4)*(2 + 3.5) / (4 + 5)) - 34 * (7 - (2 + 3))
//	样例输出
//	输出样例1 :
//3.40
//输出样例2 :
//	15.30
//	输出样例3：
//	454.75


#include "stdafx.h"
#include <iostream>
#include <iomanip>
using namespace std;

double expression();
double item();
double factor();
int ptr;
char s[1000];

int main()
{
	ptr = 0;
	double ans;
	cin >> s;
	ans = expression();
	cout << setiosflags(ios::fixed) << setprecision(2) << ans << endl;
	return 0;
}

double expression()
{
	double result = item();
	while (s[ptr] == '+' || s[ptr] == '-')
	{
		
		if (s[ptr] == '+')
		{
			ptr++;
			result += item();
		}
		else if (s[ptr] == '-')
		{
			ptr++;
			result -= item();
		}
	}
	return result;
}

double item()
{
	double result = factor();
	while (s[ptr] == '*' || s[ptr] == '/')
	{
		if (s[ptr] == '*')
		{
			ptr++;
			result *= factor();
		}
		else if (s[ptr] == '/')
		{
			ptr++;
			result /= factor();
		}
	}
	return result;
}

double factor()
{
	double result = 0;
	double points = 0;
	if (s[ptr] == '(')
	{
		ptr++;
		result = expression();
		ptr++;
	}
	while (isdigit(s[ptr]))
	{
		result = result * 10 + s[ptr] - '0';
		ptr++;
	}
	if (s[ptr] == '.')
	{
		ptr++;
		int t = 1;
		while (isdigit(s[ptr]))
		{
			double tt = s[ptr] - '0';
			int k = t;
			while (k--)
			{
				tt /= 10;
			}
			points += tt;
			t++;
			ptr++;
		}
	}

	result += points;
	return result;
}


































//#include <iostream>
//using namespace std;
//
//int factor_value();
//int term_value();
//int expression_value();
//
//int expression_value()
//{
//	int result = term_value();
//	bool more = true;
//	while (more)
//	{
//		char op = cin.peek();
//		if (op == '+' || op == '-')
//		{
//			cin.get();
//			int value = term_value();
//			if (op == '+')
//			{
//				result += value;
//			}
//			else
//			{
//				result -= value;
//			}
//		}
//		else
//			break;
//	}	
//	return result;
//}
//
//int term_value()
//{
//	int result = factor_value();
//	bool more = true;
//	while (more)
//	{
//		char op = cin.peek();
//		if (op == '*' || op == '/')
//		{
//			cin.get();
//			int value = factor_value();
//			if (op == '*')
//				result *= value;
//			else
//				result /= value;
//		}
//		else
//			break;
//	}	
//	return result;
//}
//
//int factor_value()
//{
//	int result = 0;
//	char c = cin.peek();
//	if (c == '(')
//	{
//		cin.get();
//		result = expression_value();
//		cin.get();
//	}
//	else
//	{
//		while (isdigit(c))
//		{
//			result = 10 * result + (c - '0');
//			cin.get();
//			c = cin.peek();			
//		}
//	}
//	return result;
//}
//
//int main()
//{
//	cout << expression_value() << endl;
//	system("pause");
//	return 0;
//}

//int main()
//{
//	cout << expression_value() << endl;
//	system("pause");
//    return 0;
//}
//
//int expression_value()
//{
//	int result = term_value();
//	bool more = true;
//	while (more)
//	{
//		char op = cin.peek();
//		if (op == '+' || op == '-')
//		{
//			cin.get();
//			int value = term_value();
//			if (op == '+')
//				result += value;
//			else
//				result -= value;
//		}
//		else
//			more = false;
//	}
//	return result;
//}
//
//int term_value()
//{
//	int result = factor_value();
//	bool more = true;
//	while (more)
//	{
//		char op = cin.peek();
//		if (op == '*' || op == '/')
//		{
//			cin.get();
//			int value = factor_value();
//			if (op == '*')
//				result *= value;
//			else
//				result /= value;
//		}
//		break;
//	}
//	return result;
//}
//
//int factor_value()
//{
//	int result = 0;
//	char c = cin.peek();
//	if (c == '(')
//	{
//		cin.get();
//		result = expression_value();
//		cin.get();
//	}
//	else
//	{
//		while (isdigit(c))
//		{
//			result = 10 * result + c - '0';
//			cin.get();
//			c = cin.peek();
//		}
//	}
//	return result;
//}