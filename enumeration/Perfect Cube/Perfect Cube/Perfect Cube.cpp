// Perfect Cube.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
using namespace std;

int main()
{
	int N;
	cin >> N;
	for (int a = 1; a <= N; a++)
		for (int b = 1; b <= a; b++)
			for (int c = b; c <= a; c++)
				for (int d = c; d <= a; d++)
					if (pow(a, 3) == pow(b, 3) + pow(c, 3) + pow(d, 3))
						cout << "Cube = " << a << ", Triple = (" << b << "," << c << "," << d << ")" << endl;


	system("pause");

    return 0;
}

