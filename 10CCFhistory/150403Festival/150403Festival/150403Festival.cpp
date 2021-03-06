// 150403Festival.cpp: 定义控制台应用程序的入口点。
//

//问题描述
//有一类节日的日期并不是固定的，而是以“a月的第b个星期c”的形式定下来的，比如说母亲节就定为每年的五月的第二个星期日。
//现在，给你a，b，c和y1, y2(1850 ≤ y1, y2 ≤ 2050)，希望你输出从公元y1年到公元y2年间的每年的a月的第b个星期c的日期。
//提示：关于闰年的规则：年份是400的整数倍时是闰年，否则年份是4的倍数并且不是100的倍数时是闰年，其他年份都不是闰年。
//例如1900年就不是闰年，而2000年是闰年。
//为了方便你推算，已知1850年1月1日是星期二。
//输入格式
//输入包含恰好一行，有五个整数a, b, c, y1, y2。其中c = 1, 2, ……, 6, 7分别表示星期一、二、……、六、日。
//输出格式
//对于y1和y2之间的每一个年份，包括y1和y2，按照年份从小到大的顺序输出一行。
//如果该年的a月第b个星期c确实存在，则以"yyyy/mm/dd"的格式输出，即输出四位数的年份，两位数的月份，两位数的日期，
//中间用斜杠“ / ”分隔，位数不足时前补零。
//如果该年的a月第b个星期c并不存在，则输出"none"（不包含双引号)。
//样例输入
//5 2 7 2014 2015
//样例输出
//2014 / 05 / 11
//2015 / 05 / 10
//评测用例规模与约定
//所有评测用例都满足：1 ≤ a ≤ 12，1 ≤ b ≤ 5，1 ≤ c ≤ 7，1850 ≤ y1, y2 ≤ 2050。

#include "stdafx.h"
#include <iostream>
using namespace std;

int a, b, c, yy, y2;
int month[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

bool isleapyear(int y)
{
	if (y % 400 == 0 || (y % 4 == 0 && y % 100 != 0))
		return true;
	return false;
}

int weekday(int y, int m, int d)
{
	int days = 0;
	for (int i = 1850; i < y; i++)
		if (isleapyear(i))
			days += 366;
		else
			days += 365;
	if (isleapyear(y))
		month[2] = 29;
	else
		month[2] = 28;
	for (int i = 1; i < m; i++)
		days += month[i];
	days += d;
	int t = (days % 7) + 1;
	return t;
}



int main()
{
	cin >> a >> b >> c >> yy >> y2;
	weekday(1851, 1, 1);
	for (int i = yy; i <= y2; i++)
	{
		if (isleapyear(i))
			month[2] = 29;
		else
			month[2] = 28;
		int count = 0;
		int j;
		for (j = 1; j <= month[a]; j++)
		{
			if (weekday(i, a, j) == c)
				count++;
			if (count == b)
				break;
		}
		if (j == month[a] + 1)
			cout << "none" << endl;
		else
		{
			cout << i << '/';
			if (a < 10)
				cout << '0' << a << '/';
			else
				cout << a << '/';
			if (j < 10)
				cout << '0' << j << endl;
			else
				cout << j << endl;
		}
			

	}
	

    return 0;
}

