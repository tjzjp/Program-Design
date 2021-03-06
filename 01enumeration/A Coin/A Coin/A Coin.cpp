// A Coin.cpp: 定义控制台应用程序的入口点。
//

//Description
//Sally Jones has a dozen Voyageur silver dollars.However, only eleven of the coins are true silver dollars; 
//one coin is counterfeit even though its color and size make it indistinguishable from the real silver dollars.
//The counterfeit coin has a different weight from the other coins but Sally does not know if it is heavier or lighter than the real coins.
//Happily, Sally has a friend who loans her a very accurate balance scale.
//The friend will permit Sally three weighings to find the counterfeit coin.
//For instance, if Sally weighs two coins against each other and the scales balance then she knows these two coins are true.
//Now if Sally weighs one of the true coins against a third coin and the scales do not balance 
//then Sally knows the third coin is counterfeit and she can tell whether it is light or heavy 
//depending on whether the balance on which it is placed goes up or down, respectively.
//By choosing her weighings carefully, Sally is able to ensure that she will find the counterfeit coin with exactly three weighings.
//Input
//The first line of input is an integer n(n > 0) specifying the number of cases to follow.
//Each case consists of three lines of input, one for each weighing.Sally has identified each of the coins with the letters A--L.
//Information on a weighing will be given by two strings of letters and then one of the words ``up'', ``down'', or ``even''. 
//The first string of letters will represent the coins on the left balance; the second string, the coins on the right balance. 
//(Sally will always place the same number of coins on the right balance as on the left balance.) 
//The word in the third position will tell whether the right side of the balance goes up, down, or remains even.
//Output
//For each case, the output will identify the counterfeit coin by its letter and tell whether it is heavy or light
//.The solution will always be uniquely determined.
//Sample Input
//1
//ABCD EFGH even
//ABCI EFJK up
//ABIJ EFGH even
//Sample Output
//K is the counterfeit coin and it is light.

#include "stdafx.h"





























//#include <iostream>
//#include <cstring>
//using namespace std;
//
//char leftside[3][7];
//char rightside[3][7];
//char results[3][7];
//
//bool isfake(char c, bool light)
//{
//	for (int i = 0; i < 3; i++)
//	{
//		switch (results[i][0])
//		{
//			case'e':
//				if (strchr(leftside[i], c) || strchr(rightside[i], c))
//					return false;
//				break;
//			case'u':
//				if (light)
//				{
//					if (strchr(rightside[i], c) == NULL)
//						return false;
//					break;
//				}
//				else
//				{
//					if (strchr(leftside[i], c) == NULL)
//						return false;
//					break;
//				}
//
//		}
//	}
//	return true;
//}
//
//int main()
//{
//	int t;
//	cin >> t;
//	while (t--)
//	{
//		for (int i = 0; i < 3; i++)
//		{
//			cin >> leftside[i];
//			cin >> rightside[i];
//			cin >> results[i];
//			if (results[i][0] == 'd')
//			{
//				char t[7];
//				memcpy(t, rightside[i], sizeof(t));
//				memcpy(rightside[i], leftside[i], sizeof(t));
//				memcpy(leftside[i], t, sizeof(t));
//				results[i][0] = 'u';
//			}
//		}
//		for (char c = 'A'; c <= 'L'; c++)
//		{
//			if (isfake(c, true))
//			{
//				cout << c << " is the counterfeit coin and it is light." << endl;
//				break;
//			}
//			else if (isfake(c, false))
//			{
//				cout << c << " is the counterfeit coin and it is heavy." << endl;
//				break;
//			}
//		}
//	}
//	return 0;
//}




//#include <iostream>
//using namespace std;
//
//char Left[3][7];
//char Right[3][7];
//char Result[3][7];
//
//
////bool IsFake(char c, bool light)
////{
////	for (int i = 0; i < 3; i++)
////	{
////		char *pRight, *pLeft;
////		if (light)
////		{
////			pLeft = Left[i];
////			pRight = Right[i];
////		}
////		else
////		{
////			pLeft = Right[i];
////			pRight = Left[i];
////		}
////		switch (Result[i][0])
////		{
////			case 'u':
////				if (strchr(pRight, c) == NULL)
////					return false;
////				break;
////			case 'e':
////				if (strchr(pRight, c) || strchr(pLeft, c))
////					return false;
////				break;
////			case 'd':
////				if (strchr(pLeft, c) == NULL)
////					return false;
////				break;
////		}
////	}
////	return true;	
////}
//
//bool IsFake(char c, bool light)
//{
//	char *pLeft, *pRight;
//	for (int i = 0; i < 3; i++)
//	{
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
//				if (strchr(pLeft, c) == NULL)
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
//
//
//
//int main()
//{	
//	//int t;
//	//cin >> t;
//	//while (t--)
//	//{
//	//	for (int i = 0; i < 3; i++)
//	//	{
//	//		cin >> Left[i];
//	//		cin >> Right[i];
//	//		cin >> Result[i];
//	//	}
//	//	for (char c = 'A'; c <= 'L'; c++)
//	//	{
//	//		if (IsFake(c, true))
//	//		{
//	//			cout << c << " is the counterfeit coin and it is light.\n";
//	//			break;
//	//		}
//	//		else if (IsFake(c, false))
//	//		{
//	//			cout << c << " is the counterfeit coin and it is heavy.\n";
//	//			break;
//	//		}
//	//	}		
//	//}
//
//	int t;
//	cin >> t;
//	while (t--)
//	{
//		for (int i = 0; i < 3; i++)
//		{
//			cin >> Left[i];
//			cin >> Right[i];
//			cin >> Result[i];
//		}
//		for (char k = 'A'; k < 'L'; k++)
//		{
//			if (IsFake(k, true))
//			{
//				cout << k << " is the counterfeit coin and it is light.\n";
//				break;
//			}
//			else if (IsFake(k, false))
//			{
//				cout << k << " is the counterfeit coin and it is heavy.\n";
//				break;
//			}
//		}
//	}
//
//
//	system("pause");
//    return 0;
//}
//
