// Reverse Polish Notation.cpp: 定义控制台应用程序的入口点。
//

//Sample
//* + 11.0 12.0 + 24.0 35.0
//1357.0000

#include "stdafx.h"
#include <iostream>
using namespace std;

double exp()
{
	char s[20];
	cin >> s;
	switch (s[0])
	{
		case '+':
			return exp() + exp();
		case '-':
			return exp() - exp();
		case '*':
			return exp() * exp();
		case '/':
			return exp() / exp();
		default:
			return atof(s);
	}
}

int main()
{
	cout << exp() << endl;
	system("pause");
    return 0;
}

