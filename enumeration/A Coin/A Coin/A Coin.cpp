// A Coin.cpp: 定义控制台应用程序的入口点。
//

//样例
//1
//ABCD EFGH even
//ABCI EFJK up
//ABIJ EFGH even

#include "stdafx.h"
#include <iostream>
using namespace std;

char Left[3][7];
char Right[3][7];
char Result[3][7];

//bool IsFake(char c, bool light)
//{
//	for (int i = 0; i < 3; i++)
//	{
//		char *pRight, *pLeft;
//		if (light)
//		{
//			pLeft = Left[i];
//			pRight = Right[i];
//		}
//		else
//		{
//			pLeft = Right[i];
//			pRight = Left[i];
//		}
//		switch (Result[i][0])
//		{
//			case 'u':
//				if (strchr(pRight, c) == NULL)
//					return false;
//				break;
//			case 'e':
//				if (strchr(pRight, c) || strchr(pLeft, c))
//					return false;
//				break;
//			case 'd':
//				if (strchr(pLeft, c) == NULL)
//					return false;
//				break;
//		}
//	}
//	return true;	
//}

bool IsFake(char c, bool light)
{
	char *pLeft, *pRight;
	for (int i = 0; i < 3; i++)
	{
		if (light)
		{
			pLeft = Left[i];
			pRight = Right[i];
		}
		else
		{
			pLeft = Right[i];
			pRight = Left[i];
		}
		switch (Result[i][0])
		{
			case 'u':
				if (strchr(pLeft, c) == NULL)
					return false;
				break;
			case 'e':
				if (strchr(pRight, c) || strchr(pLeft, c))
					return false;
				break;
			case 'd':
				if (strchr(pLeft, c) == NULL)
					return false;
				break;
		}
	}
	return true;
}



int main()
{	
	//int t;
	//cin >> t;
	//while (t--)
	//{
	//	for (int i = 0; i < 3; i++)
	//	{
	//		cin >> Left[i];
	//		cin >> Right[i];
	//		cin >> Result[i];
	//	}
	//	for (char c = 'A'; c <= 'L'; c++)
	//	{
	//		if (IsFake(c, true))
	//		{
	//			cout << c << " is the counterfeit coin and it is light.\n";
	//			break;
	//		}
	//		else if (IsFake(c, false))
	//		{
	//			cout << c << " is the counterfeit coin and it is heavy.\n";
	//			break;
	//		}
	//	}		
	//}

	int t;
	cin >> t;
	while (t--)
	{
		for (int i = 0; i < 3; i++)
		{
			cin >> Left[i];
			cin >> Right[i];
			cin >> Result[i];
		}
		for (char k = 'A'; k < 'L'; k++)
		{
			if (IsFake(k, true))
			{
				cout << k << " is the counterfeit coin and it is light.\n";
				break;
			}
			else if (IsFake(k, false))
			{
				cout << k << " is the counterfeit coin and it is heavy.\n";
				break;
			}
		}
	}


	system("pause");
    return 0;
}

