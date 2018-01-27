// Problem of Lights out.cpp: 定义控制台应用程序的入口点。
//

//样例
//2
//011010
//100111
//001001
//100101
//011100
//001010
//101011
//001011
//101100
//010100

#include "stdafx.h"
#include <iostream>
using namespace std;

char orilights[5];
char lights[5];
char results[5];

int GetBit(char c, int i)
{
	return (c >> i) & 1;
}

void SetBit(char &c, int i, int v)
{
	if (v)
	{
		c |= (1 << i);
	}
	else
	{
		c &= ~(1 << i);
	}
}

void FlipBit(char &c, int i)
{
	c ^= (1 << i);
}

void OutPutResult(int t, char result[])
{
	cout << "PUZZLE #" << t << endl;
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			cout << GetBit(result[i], j);
			if (j < 5)
				cout << " ";
		}
		cout << endl;
	}
		
}

int main()
{
	int T;
	cin >> T;
	for(int t = 0 ; t < T; t++)
	{
		for (int i = 0; i < 5; i++)
			for (int j = 0; j < 6; j++)
			{
				int s;
				cin >> s;
				SetBit(orilights[i], j, s);
			}
		for (int i = 0; i < 64; i++)
		{
			int switchs = i;
			memcpy(lights, orilights, sizeof(orilights));
			for (int j = 0; j < 5; j++)
			{
				results[j] = switchs;
				for (int k = 0; k < 6; k++)
				{
					if (GetBit(results[j], k))
					{
						if (k > 0)
							FlipBit(lights[j], k - 1);
						if (k < 5)
							FlipBit(lights[j], k + 1);
						FlipBit(lights[j], k);
					}				
				}
				if (j < 4)		
					lights[j + 1] ^= switchs;
				switchs = lights[j];
			}
			if (lights[4] == 0)
			{
				OutPutResult(t + 1, results);
				break;
			}
		}
	}

	system("pause");
    return 0;
}

