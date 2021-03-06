// Problem of Lights out.cpp: 定义控制台应用程序的入口点。
//

//描述
//有一个由按钮组成的矩阵，其中每行有6个按钮，共5行。每个按钮的位置上有一盏灯。
//当按下一个按钮后，该按钮以及周围位置(上边、下边、左边、右边)的灯都会改变一次。
//即，如果灯原来是点亮的，就会被熄灭；如果灯原来是熄灭的，则会被点亮。
//在矩阵角上的按钮改变3盏灯的状态；在矩阵边上的按钮改变4盏灯的状态；其他的按钮改变5盏灯的状态。
//
//在上图中，左边矩阵中用X标记的按钮表示被按下，右边的矩阵表示灯状态的改变。对矩阵中的每盏灯设置一个初始状态。
//请你按按钮，直至每一盏等都熄灭。与一盏灯毗邻的多个按钮被按下时，一个操作会抵消另一次操作的结果。
//在下图中，第2行第3、5列的按钮都被按下，因此第2行、第4列的灯的状态就不改变。
//
//请你写一个程序，确定需要按下哪些按钮，恰好使得所有的灯都熄灭。
//根据上面的规则，我们知道
//1）第2次按下同一个按钮时，将抵消第1次按下时所产生的结果。因此，每个按钮最多只需要按下一次；
//2）各个按钮被按下的顺序对最终的结果没有影响；
//3）对第1行中每盏点亮的灯，按下第2行对应的按钮，就可以熄灭第1行的全部灯。
//如此重复下去，可以熄灭第1、2、3、4行的全部灯。同样，按下第1、2、3、4、5列的按钮，可以熄灭前5列的灯。
//
//
//输入
//5行组成，每一行包括6个数字（0或1）。相邻两个数字之间用单个空格隔开。0表示灯的初始状态是熄灭的，1表示灯的初始状态是点亮的。
//输出
//5行组成，每一行包括6个数字（0或1）。相邻两个数字之间用单个空格隔开。
//其中的1表示需要把对应的按钮按下，0则表示不需要按对应的按钮。
//样例输入
//0 1 1 0 1 0
//1 0 0 1 1 1
//0 0 1 0 0 1
//1 0 0 1 0 1
//0 1 1 1 0 0
//样例输出
//1 0 1 0 0 1
//1 1 0 1 0 1
//0 0 1 0 1 1
//1 0 0 1 0 0
//0 1 0 0 0 0

#include "stdafx.h"
#include <iostream>
#include <cstring>
using namespace std;

int ori[8][8];
int result[8][8];

bool guess()
{
	for (int i = 1; i < 5; i++)
		for (int j = 1; j <= 6; j++)
		{
			result[i + 1][j] = (result[i][j] + result[i - 1][j] + result[i][j - 1] + result[i][j + 1] + ori[i][j]) % 2;
		}
	for (int k = 1; k <= 6; k++)
		if ((result[5][k] + result[4][k] + result[5][k - 1] + result[5][k + 1] + ori[5][k]) % 2 != 0)
		{
			return false;
		}
	return true;
}

void emu()
{
	int sum = 1 << 6;
	int b = 0;
	int c;
	while (sum--)
	{
		if (guess())
		{
			for (int i = 1; i <= 5; i++)
			{
				for (int j = 1; j <= 6; j++)
					cout << result[i][j] << " ";
				cout << endl;
			}
			break;
		}
		c = 1;
		result[1][c]++;
		b++;
		while (result[1][c] > 1)
		{
			result[1][c] = 0;
			c++;
			b--;
			result[1][c]++;
		}
	}
	
		
		
}

int main()
{
	memset(result, 0, sizeof(result));
	for (int i = 1; i <= 5; i++)
		for (int j = 1; j <= 6; j++)
			cin >> ori[i][j];
	emu();

	return 0;
}
































//#include <iostream>
//using namespace std;
//
//char orilights[5];
//char lights[5];
//char results[5];
//
//int GetBit(char c, int i)
//{
//	return (c >> i) & 1;
//}
//
//void SetBit(char &c, int i, int v)
//{
//	if (v)
//	{
//		c |= (1 << i);
//	}
//	else
//	{
//		c &= ~(1 << i);
//	}
//}
//
//void FlipBit(char &c, int i)
//{
//	c ^= (1 << i);
//}
//
//void OutPutResult(int t, char result[])
//{
//	cout << "PUZZLE #" << t << endl;
//	for (int i = 0; i < 5; i++)
//	{
//		for (int j = 0; j < 6; j++)
//		{
//			cout << GetBit(result[i], j);
//			if (j < 5)
//				cout << " ";
//		}
//		cout << endl;
//	}
//		
//}
//
//int main()
//{
//	int T;
//	cin >> T;
//	for(int t = 0 ; t < T; t++)
//	{
//		for (int i = 0; i < 5; i++)
//			for (int j = 0; j < 6; j++)
//			{
//				int s;
//				cin >> s;
//				SetBit(orilights[i], j, s);
//			}
//		for (int i = 0; i < 64; i++)
//		{
//			int switchs = i;
//			memcpy(lights, orilights, sizeof(orilights));
//			for (int j = 0; j < 5; j++)
//			{
//				results[j] = switchs;
//				for (int k = 0; k < 6; k++)
//				{
//					if (GetBit(results[j], k))
//					{
//						if (k > 0)
//							FlipBit(lights[j], k - 1);
//						if (k < 5)
//							FlipBit(lights[j], k + 1);
//						FlipBit(lights[j], k);
//					}				
//				}
//				if (j < 4)		
//					lights[j + 1] ^= switchs;
//				switchs = lights[j];
//			}
//			if (lights[4] == 0)
//			{
//				OutPutResult(t + 1, results);
//				break;
//			}
//		}
//	}
//
//	system("pause");
//    return 0;
//}

