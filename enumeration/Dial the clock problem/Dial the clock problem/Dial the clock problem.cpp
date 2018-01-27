// Dial the clock problem.cpp: 定义控制台应用程序的入口点。
//

//描述
//有9个时钟，排成一个3 * 3的矩阵。现在需要用最少的移动，将9个时钟的指针都拨到12点的位置。
//共允许有9种不同的移动。如下表所示，每个移动会将若干个时钟的指针沿顺时针方向拨动90度。
//移动     影响的时钟
// 1         ABDE
// 2         ABC
// 3         BCEF
// 4         ADG
// 5         BDEFH
// 6         CFI
// 7         DEGH
// 8         GHI
// 9         EFHI
//输入
//从标准输入设备读入9个整数，表示各时钟指针的起始位置。0 = 12点、1 = 3点、2 = 6点、3 = 9点。
//输出
//输出一个最短的移动序列，使得9个时钟的指针都指向12点。按照移动的序号大小，输出结果。
//样例输入
//3 3 0
//2 2 2
//2 1 2
//样例输出
//4 5 8 9

#include "stdafx.h"
#include <iostream>
using namespace std;

int main()
{
	int min = 100;
	int times[9];
	int results[9];
	int i, i1, i2, i3, i4, i5, i6, i7, i8, i9;
	for (i = 0; i < 9; i++)
	{
		cin >> times[i];
	}
	for (i1 = 0; i1 < 4; i1++)
		for(i2 = 0; i2 < 4; i2++)
			for(i3 = 0; i3 < 4; i3++)
				for(i4 = 0; i4 < 4; i4++)
					for(i5 = 0;i5 < 4; i5++)
						for(i6 = 0; i6 < 4; i6++)
							for(i7 = 0; i7 <4; i7++)
								for(i8 = 0;i8 < 4; i8++)
									for (i9 = 0; i9 < 4; i9++)
									{
										if ((times[0] + i1 + i2 + i4) % 4 == 0 && (times[1] + i1 + i2 + i3 + i5) % 4 == 0
											&& (times[2] + i2 + i3 + i6) % 4 == 0 && (times[3] + i1 + i4 + i5 + i7) % 4 == 0
											&& (times[4] + i1 + i3 + i5 + i7 + i9) % 4 == 0 && (times[5] + i3 + i5 + i6 + i9) % 4 == 0
											&& (times[6] + i4 + i7 + i8) % 4 == 0 && (times[7] + i5 + i7 + i8 + i9) % 4 == 0
											&& (times[8] + i6 + i8 + i9) % 4 == 0)
										{
											int sum = i1 + i2 + i3 + i4 + i5 + i6 + i7 + i8 + i9;
											if (sum < min)
											{
												min = sum;
												results[0] = i1;
												results[1] = i2;
												results[2] = i3;
												results[3] = i4;
												results[4] = i5;
												results[5] = i6;
												results[6] = i7;
												results[7] = i8;
												results[8] = i9;
											}
										}
									}
	for (int j = 0; j < 9; j++)
	{
		if (results[j] != 0)
		{
			cout << j + 1 << " ";
			results[j]--;
		}
	}




	system("pause");
    return 0;
}

