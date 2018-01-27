// Physical Period.cpp: 定义控制台应用程序的入口点。
//

//样例
//0 0 0 0： 21252
//0 0 0 100： 21152
//5 20 34 325： 19575
//4 5 6 7： 16994

#include "stdafx.h"
#include <iostream>
using namespace std;

int main()
{
	//int p, e, i, d, CaseNo = 0;
	//while (cin >> p >> e >> i >> d && p != -1)
	//{
	//	CaseNo++;
	//	int k;
	//	for (k = d + 1; (k - p) % 23; k++);
	//	for (; (k - e) % 28; k = k + 23);
	//	for (; (k - i) % 33; k = k + 28 * 23);
	//	cout << "Case" << CaseNo << ": the next triple peak occurs in " << k - d << "days." << endl;
	//}




	int p, e, i, d;
	int CaseNo = 0;
	while (cin >> p >> e >> i >> d && p != -1)
	{
		CaseNo++;
		int k;
		for (k = d + 1; (k - p) % 23; k++);
		for (; (k - e) % 28; k += 23);
		for (; (k - i) % 33; k += 28 * 23);
		cout << "Case" << CaseNo << ": the next triple peak occurs in " << k - d << " days.\n";
	}


	system("pause");


    return 0;
}

