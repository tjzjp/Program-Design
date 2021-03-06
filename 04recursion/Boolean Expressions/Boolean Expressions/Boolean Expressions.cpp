// Boolean Expressions.cpp: 定义控制台应用程序的入口点。
//

//描述
//The objective of the program you are going to produce is to evaluate boolean expressions as the one shown next :
//Expression: (V | V) & F & (F | V)
//where V is for True, and F is for False.The expressions may include the following operators : 
//!for not , &for and, | for or , the use of parenthesis for operations grouping is also allowed.
//To perform the evaluation of an expression, it will be considered the priority of the operators, 
//the not having the highest, and the or the lowest.The program must yield V or F, 
//as the result for each expression in the input file.
//输入
//The expressions are of a variable length, although will never exceed 100 symbols.Symbols may be separated 
//by any number of spaces or no spaces at all, therefore, the total length of an expression, as a number of characters, 
//is unknown.
//The number of expressions in the input file is variable and will never be greater than 20. 
//Each expression is presented in a new line, as shown below.
//输出
//For each test expression, print “Expression ” followed by its sequence number, 
//“: “, and the resulting value of the corresponding test expression.Separate the output for 
//consecutive test expressions with a new line.
//Use the same format as that shown in the sample output shown below.
//样例输入
//(V | V) & F & (F | V)
//!V | V & V & !F & (F | V) & (!F | F | !V & V)
//(F&F | V | !V & !F & !(F | F&V))
//样例输出
//Expression 1: F
//Expression 2 : V
//Expression 3 : V

#include "stdafx.h"
#include <iostream>
#include <cstring>
using namespace std;

char express[10000];
int ptr;
bool expression_value();
bool Express();

bool NotExpress()
{
	bool result;
	switch (express[++ptr])
	{
		case 'V':
			ptr++;
			return false;
			break;
		case 'F':
			ptr++;
			return true;
			break;
		case '(':
			ptr++;
			result = expression_value();
			ptr++;
			return !result;
			break;
		case '!':
			return !NotExpress();
			break;
	}
}

bool Express()
{
	bool result;
	switch (express[ptr])
	{
		case 'V':
			ptr++;
			return true;
			break;
		case 'F':
			ptr++;
			return false;
			break;
		case '(':
			ptr++;
			result = expression_value();
			ptr++;
			return result;
			break;
		case '!':
			return NotExpress();
			break;
	}
}

bool factor_value()
{
	bool result = Express();
	while (express[ptr] == '&')
	{
		ptr++;
		result &= Express();
	}
	return result;
}

bool expression_value()
{
	bool result = factor_value();
	while (express[ptr] == '|')
	{
		ptr++;
		result |= factor_value();
	}
	return result;
}

int main()
{
	int n = EOF - 1;
	bool ans;
	int t = 0;
	char c;
	int i = 0;
	while (n != EOF)
	{
		n = scanf_s("%c", &c);
		if (n == EOF || c == '\n')
		{
			express[i] = '\0';
			if (i > 0)
			{
				t++;
				ptr = 0;
				ans = expression_value();
				cout << "Expression " << t << ": ";
				if (ans)
					cout << "V" << endl;
				else
					cout << "F" << endl;
			}
			i = 0;
		}
		else if (c != ' ')
			express[i++] = c;
	}

	return 0;
}
































//#include <iostream>
//using namespace std;
//
//bool expression_value();
//bool item_value();
//bool factor_value();
//char express[100];
//int ptr;
//
//int main()
//{
//	int i = 0;
//	char c;
//	int n = EOF + 1;
//	int t = 1;
//	while (n != EOF)
//	{
//		n = scanf_s("%c", &c);
//		if (n == EOF || c == '\n')
//		{
//			express[i] = 0;
//			if (i > 0)
//			{
//				ptr = 0;
//				bool r = expression_value();
//				if (r)
//				{
//					cout << "Expression " << t++ << ": V" << endl;
//				}
//				else
//					cout << "Expression " << t++ << ": F" << endl;
//			}
//			i = 0;
//		}
//		else if(c != ' ')
//		{
//			express[i++] = c;
//		}
//	}
//
//	
//	system("pause");
//    return 0;
//}
//
//bool expression_value()
//{
//	bool result = item_value();
//	while (express[ptr] == '|')
//	{
//		++ptr;
//		result |= item_value();
//	}
//	return result;
//}
//
//bool item_value()
//{
//	bool result = factor_value();
//	while (express[ptr] == '&')
//	{
//		++ptr;
//		result &= factor_value();
//	}
//	return result;
//}
//
//bool NotExpress()
//{
//	bool result;
//	switch (express[++ptr])
//	{
//		case 'F':
//			ptr++;
//			return true;
//			break;
//		case 'V':
//			ptr++;
//			return false;
//			break;
//		case '!':
//			ptr++;
//			return !NotExpress();
//			break;
//		case '(':
//			ptr++;
//			result = expression_value();
//			ptr++;
//			return !result;
//			break;
//	}
//}
//
//bool factor_value()
//{
//	bool result;
//	switch (express[ptr])
//	{
//		case 'F':
//			ptr++;
//			return false;
//			break;
//		case 'V':
//			ptr++;
//			return false;
//			break;
//		case '!':
//			ptr++;
//			return NotExpress();
//			break;
//		case '(':
//			ptr++;
//			result = expression_value();
//			ptr++;
//			return result;
//			break;
//	}
//}

