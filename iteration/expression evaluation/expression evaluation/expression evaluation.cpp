// expression evaluation.cpp: 定义控制台应用程序的入口点。
//

//Sample
//(2+3)*(5+7)+9/3
//63

#include "stdafx.h"
#include <iostream>
using namespace std;

int factor_value();
int term_value();
int expression_value();

int expression_value()
{
	int result = term_value();
	bool more = true;
	while (more)
	{
		char op = cin.peek();
		if (op == '+' || op == '-')
		{
			cin.get();
			int value = term_value();
			if (op == '+')
			{
				result += value;
			}
			else
			{
				result -= value;
			}
		}
		else
			break;
	}	
	return result;
}

int term_value()
{
	int result = factor_value();
	bool more = true;
	while (more)
	{
		char op = cin.peek();
		if (op == '*' || op == '/')
		{
			cin.get();
			int value = factor_value();
			if (op == '*')
				result *= value;
			else
				result /= value;
		}
		else
			break;
	}	
	return result;
}

int factor_value()
{
	int result = 0;
	char c = cin.peek();
	if (c == '(')
	{
		cin.get();
		result = expression_value();
		cin.get();
	}
	else
	{
		while (isdigit(c))
		{
			result = 10 * result + (c - '0');
			cin.get();
			c = cin.peek();			
		}
	}
	return result;
}

int main()
{
	cout << expression_value() << endl;
	system("pause");
	return 0;
}

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