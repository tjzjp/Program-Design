// Crontab.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
//#include <bits/stdc++.h>
#include <string>
#include <iostream>
#include <map>
#include <cstring>
#include <vector>
#include <set>
#include <ctype.h>
using namespace std;

int n;
string s, t;

char vMon[][4] = { "", "jan", "feb", "mar", "apr", "may", "jun", "jul", "aug", "sep", "nov", "dec" };
char vWek[][4] = { "sun", "mon", "tue", "wed", "thu", "fri", "sat" };
int mtharray[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

map<string, int> mMon, mWek;
map<string, vector<string>> mrt;

void buildmonandwekmap()
{
	for (int i = 1; i <= 12; i++)
		mMon[vMon[i]] = i;
	for (int i = 0; i <= 6; i++)
		mWek[vWek[i]] = i;
}

int stoi(string &s)
{
	int len = s.size();
	int t = 0;
	for (int i = 0; i < len; i++)
	{
		t = t * 10 + s[i] - '0';
	}
	return t;
}

string itos(int a)
{
	string s = "";
	while (a)
	{
		int t = a % 10;
		s = (char)('0' + t) + s;
		a = a / 10;
	}
	return s;
}


void standard(string &s)
{
	int len = s.size();
	for (int i = 0; i < len; i++)
		s[i] = tolower(s[i]);
}

vector<string> splitsring(string &str, int TAG)
{
	str += ",";
	vector<string> vret;
	size_t found = str.find(',');
	while (found != string::npos)
	{
		string x = str.substr(0, found);
		str = str.substr(found + 1, str.size() - found - 1);
		size_t fdx = x.find('-');
		if (fdx == string::npos)
		{
			if (TAG == 1 && isalpha(x[0]))
				x = itos(mMon[x]);
			if (TAG == 2 && isalpha(x[0]))
				x = itos(mWek[x]);
			if (x.size() == 1)
				x = "0" + x;
			vret.push_back(x);
		}
		else
		{
			string L = x.substr(0, fdx), R = x.substr(fdx + 1, x.size() - fdx - 1);
			int left, right;
			if (TAG == 0)
			{
				left = stoi(L);
				right = stoi(R);
			}
			else if (TAG == 1)
			{
				left = (isalpha(L[0])) ? mMon[L] : stoi(L);
				right = (isalpha(R[0])) ? mMon[R] : stoi(R);
			}
			else if (TAG == 2)
			{
				left = (isalpha(L[0])) ? mWek[L] : stoi(L);
				right = (isalpha(R[0])) ? mWek[R] : stoi(R);
			}
			while (left <= right)
			{
				string num = itos(left);
				if (num.size() == 1)
					num = "0" + num;
				vret.push_back(num);
				left++;
			}
		}
		found = str.find(',');
	}
	return vret;
}

bool isleapyear(int y)
{
	if ((y % 4 == 0 && y % 100 != 0) || y % 400 == 0)
		return true;
	else
		return false;
}

string getweekday(string yyear, string mmonth, string dday)
{
	int year = stoi(yyear);
	int month = stoi(mmonth);
	int day = stoi(dday);
	int y = 1970;
	int sum = 0;
	while (y < year)
	{
		if (isleapyear(y))
			sum += 366;
		else
			sum += 365;
		y++;
	}
	int m = 1;
	while (m < month)
	{
		if (m == 2)
		{
			if (isleapyear(year))
				sum += 29;
			else
				sum += 28;
		}
		else
			sum += mtharray[m];
		m++;
	}
	sum += day;
	return "0" + itos((3 + sum % 7) % 7);
}

int main()
{
	cin >> n;
	cin >> s;
	cin >> t;

	buildmonandwekmap();

	string sy = s.substr(0, 4), ty = t.substr(0, 4), smon = s.substr(4, 6), tmon = t.substr(4, 6), 
		sd = s.substr(6, 8), td = t.substr(6, 8), sh = s.substr(8, 10), th = t.substr(8, 10), 
		smin = s.substr(10, 12), tmin = t.substr(10, 12);
	int syy, tyy, smmon, tmmon, sdd, tdd, shh, thh, smmin, tmmin;
	
	
	syy = stoi(sy);
	tyy = stoi(ty);
	
	for (int i = 0; i < n; i++)
	{
		vector<string> vminutes, vhours, vday_of_month, vmonth, vday_of_week;
		string minutes, hours, day_of_month, month, day_of_week, command;
		cin >> minutes >> hours >> day_of_month >> month >> day_of_week >> command;
		standard(month);
		standard(day_of_week);
		if (minutes == "*")
			minutes = "0-59";
		vminutes = splitsring(minutes, 0);
		if (hours == "*")
			hours = "0-23";
		vhours = splitsring(hours, 0);
		if (day_of_month == "*")
			day_of_month = "1-31";
		vday_of_month = splitsring(day_of_month, 0);
		if (month == "*")
			month = "1-12";
		vmonth = splitsring(month, 1);
		if (day_of_week == "*")
			day_of_week = "0-6";

		vday_of_week = splitsring(day_of_week, 2);

		set<string> wekexist;
		for (size_t i = 0; i < vday_of_week.size(); i++)
			wekexist.insert(vday_of_week[i]);
		int curyear = syy;
		while (curyear <= tyy)
		{
			if (isleapyear(curyear))
				mtharray[2] = 29;
			else
				mtharray[2] = 28;
			string year = itos(curyear);
			for (size_t mi = 0; mi < vmonth.size(); mi++)
			{
				string curmonth = vmonth[mi];
				
				for (size_t di = 0; di < vday_of_month.size(); di++)
				{
					string curday_of_month = vday_of_month[di];
					string wd = getweekday(year, curmonth, curday_of_month);
					if (wekexist.count(wd) == 0 || stoi(curday_of_month) > mtharray[stoi(curmonth)])
						continue;
					for (size_t hi = 0; hi < vhours.size(); hi++)
					{
						for (size_t mi = 0; mi < vminutes.size(); mi++)
						{
							string datetime = year + curmonth + curday_of_month + vhours[hi] + vminutes[mi];
							if (datetime < t && datetime >= s)
								mrt[datetime].push_back(command);
						}
					}
				}
					
			}
				
			curyear++;
		}

	}

	for (map<string, vector<string>>::iterator it = mrt.begin(); it != mrt.end(); it++)
	{
		map<string, int> isprt;
		for (size_t i = 0; i < it->second.size(); i++)
		{
			string dis = it->first + " " + it->second[i];
			cout << dis << endl;
		}
	}


    return 0;
}

//垃圾代码！！
//#include <string>
//#include <cmath>
//#include<stdlib.h>
//#include <map>
//#include <vector>
//#include <string>
//#include <iostream>
////#include<bits/stdc++.h>
//using namespace std;
//
//int month[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
//string mon[] = { "", "jan", "feb", "mar", "apr", "may", "jun", "jul", "aug", "sep", "oct", "nov", "dec" };
//string weekday[] = { "sun", "mon", "tue", "wed", "thu", "fri", "sat", "sun" };
//
//map<string, string> month_map;
//map<string, string> weekday_map;
//int n;
//string s, t;
//int s_y, s_mon, s_d, s_h, s_min;
//int t_y, t_mon, t_d, t_h, t_min;
//map<string, string> ma;
//vector<int> minut[25], hour[25], dayofmon[25], mont[25], dayofwee[25];
//vector<string> comma[25];
//
//void init()
//{
//	for (int i = 1; i <= 9; i++)
//	{
//		month_map[mon[i]] = (char)(i + '0');
//	}
//	for (int i = 10; i <= 12; i++)
//	{
//		month_map[mon[i]] = "1" + (char)((i - 10) + '0');
//	}
//	for (int i = 0; i <= 6; i++)
//	{
//		weekday_map[weekday[i]] = (char)(i + '0');
//	}
//}
//
//void classify(int k, int ss, int m)
//{
//	if (k == 0)
//	{
//		minut[m].push_back(ss);
//	}
//	else if (k == 1)
//	{
//		hour[m].push_back(ss);
//	}
//	else if (k == 2)
//	{
//		dayofmon[m].push_back(ss);
//	}
//	else if (k == 3)
//	{
//		mont[m].push_back(ss);
//	}
//	else if (k == 4)
//	{
//		dayofwee[m].push_back(ss);
//	}
//}
//
//int strtoint(string s)
//{
//	int i = 0, tmp = 0;
//	while (s[i] != 0)
//	{
//		tmp = tmp * 10 + (int)(s[i++] - '0');
//	}
//	return tmp;
//}
//
//void during(int k, string ss, int m)
//{
//	int p = ss.find('-');
//	string t1 = ss.substr(0, p - 1);
//	string t2 = ss.substr(p + 1, ss.size());
//	int tt1 = 0, tt2 = 0;
//	tt1 = strtoint(t1);
//	tt2 = strtoint(t2);
//	for (int i = tt1; i <= tt2; i++)
//	{
//		classify(k, i, m);
//	}
//}
//
//void change(int k, string ss, int m)
//{
//	if (ss.find('*') != string::npos)
//	{
//		if (k == 0)
//		{
//			for (int i = 1; i <= 59; i++)
//			{
//				minut[m].push_back(i);
//			}
//		}
//		else if (k == 1)
//		{
//			for (int i = 1; i <= 23; i++)
//			{
//				hour[m].push_back(i);
//			}
//		}
//		else if (k == 2)
//		{
//			for (int i = 1; i <= 31; i++)
//			{
//				dayofmon[m].push_back(i);
//			}
//		}
//		else if (k == 3)
//		{
//			for (int i = 1; i <= 12; i++)
//			{
//				mont[m].push_back(i);
//			}
//		}
//		else if (k == 4)
//		{
//			for (int i = 1; i <= 6; i++)
//			{
//				dayofwee[m].push_back(i);
//			}
//		}
//	}
//	else
//	{
//		int p;
//		while ((p = ss.find(',')) != string::npos)
//		{
//			string t1;
//			t1 = ss.substr(0, p - 1);
//			ss = ss.substr(p + 1, ss.size());
//
//			if (t1.find('-'))
//			{
//				during(k, t1, m);
//			}
//			else
//			{
//				int tt1 = strtoint(t1);
//				classify(k, tt1, m);
//			}
//		}
//		if (ss.find('-') != string::npos)
//		{
//			during(k, ss, m);
//		}
//		else
//		{
//			int sss = strtoint(ss);
//			classify(k, sss, m);
//		}
//
//	}
//
//}
//
//void standard(string& s)
//{
//	for (int i = 0; i < s.size(); i++)
//	{
//		s[i] = tolower(s[i]);
//	}
//}
//
//bool isleap(int y)
//{
//	if (y % 400 == 0 || (y % 4 == 0 && y % 100 != 0))
//	{
//		return true;
//	}
//	return false;
//}
//
//int isweekday(int y, int m, int d)
//{
//	int days = 0;
//	for (int i = 1970; i < y; i++)
//	{
//		if (isleap(i))
//		{
//			days += 366;
//		}
//		else
//		{
//			days += 365;
//		}
//	}
//	if (isleap(y))
//	{
//		month[2] = 29;
//	}
//	else
//	{
//		month[2] = 28;
//	}
//	for (int i = 1; i < m; i++)
//	{
//		days += month[i];
//	}
//	days += d;
//	int ans = ((days % 7) + 3) % 7;
//	return ans;
//}
//
//string tostr(int y, int mon, int day, int h, int minu)
//{
//	string tmp = "";
//	while (y != 0)
//	{
//		tmp = (char)((y % 10) + '0') + tmp;
//		y = y / 10;
//	}
//	if (mon < 10)
//	{
//		tmp += ("0" + (char)(mon - '0'));
//	}
//	else
//	{
//		tmp += (char)((y / 10) + '0');
//		tmp += (char)((y % 10) + '0');
//	}
//	if (day < 10)
//	{
//		tmp += ("0" + (char)(day - '0'));
//	}
//	else
//	{
//		tmp += (char)((day / 10) + '0');
//		tmp += (char)((day % 10) + '0');
//	}
//	if (h < 10)
//	{
//		tmp += ("0" + (char)(h - '0'));
//	}
//	else
//	{
//		tmp += (char)((h / 10) + '0');
//		tmp += (char)((h % 10) + '0');
//	}
//	if (minu < 10)
//	{
//		tmp += ("0" + (char)(minu - '0'));
//	}
//	else
//	{
//		tmp += (char)((minu / 10) + '0');
//		tmp += (char)((minu % 10) + '0');
//	}
//	return tmp;
//}
//
///* run this program using the console pauser or add your own getch, system("pause") or input loop */
//
//int main() {
//	init();
//	cin >> n >> s >> t;
//	s_y = t_y = 0;
//	for (int i = 0; i < 4; i++)
//	{
//		s_y = s_y * 10 + (int)(s[i] - '0');
//		t_y = t_y * 10 + (int)(t[i] - '0');
//	}
//	s_mon = t_mon = 0;
//	for (int i = 4; i < 6; i++)
//	{
//		s_mon = s_mon * 10 + (int)(s[i] - '0');
//		t_mon = t_mon * 10 + (int)(t[i] - '0');
//	}
//	s_d = t_d = 0;
//	for (int i = 6; i < 8; i++)
//	{
//		s_d = s_d * 10 + (int)(s[i] - '0');
//		t_d = t_d * 10 + (int)(t[i] - '0');
//	}
//	s_h = t_h = 0;
//	for (int i = 8; i < 10; i++)
//	{
//		s_h = s_h * 10 + (int)(s[i] - '0');
//		t_h = t_h * 10 + (int)(t[i] - '0');
//	}
//	s_min = t_min = 0;
//	for (int i = 10; i < 12; i++)
//	{
//		s_min = s_min * 10 + (int)(s[i] - '0');
//		t_min = t_min * 10 + (int)(t[i] - '0');
//	}
//
//	for (int ii = 0; ii < n; ii++)
//	{
//		getchar();
//		string str;
//		string minu, hou, dofmon, mo, dofwee, com;
//
//		getline(cin, str);
//		standard(str);
//		int i = 0;
//		int k = 0;
//		while (str[i] != 0)
//		{
//			if (str[i] == ' ')
//			{
//				k++;
//				i++;
//			}
//			if (k == 0)//minutes
//			{
//				if (str[i] != ' ')
//				{
//					minu += str[i];
//				}
//				change(0, minu, ii);
//			}
//			else if (k == 1)//hours
//			{
//				if (str[i] != ' ')
//				{
//					hou += str[i];
//				}
//				change(1, hou, ii);
//			}
//			else if (k == 2)//dayofmonth
//			{
//				if (str[i] != ' ')
//				{
//					dofmon += str[i];
//				}
//				change(2, dofmon, ii);
//			}
//			else if (k == 3)//month
//			{
//				if (str[i] != ' ')
//				{
//					if (isalpha(str[i]))
//					{
//						string tm = "";
//						tm += str[i];
//						tm += str[i + 1];
//						tm += str[i + 2];
//						mo += month_map[tm];
//						i = i + 2;
//					}
//					else
//					{
//						mo += str[i];
//					}
//				}
//				change(3, mo, ii);
//			}
//			else if (k == 4)//dayofweek
//			{
//				if (str[i] != ' ')
//				{
//					if (isalpha(str[i]))
//					{
//						string tm = "";
//						tm += str[i];
//						tm += str[i + 1];
//						tm += str[i + 2];
//						dofwee += weekday_map[tm];
//						i = i + 2;
//					}
//					else
//					{
//						dofwee += str[i];
//					}
//				}
//				change(4, dofwee, ii);
//			}
//			else if (k == 5)//command
//			{
//				if (str[i] != ' ')
//				{
//					com += str[i];
//				}
//				comma[ii].push_back(com);
//			}
//			i++;
//		}
//	}
//
//	//test
//	/*for (int i = 0; i < n; i++)
//	{
//		for (int m = 0; m < mont[i].size(); m++)
//		{
//			cout << mont[i][m] << endl;
//		}
//	}*/
//
//	for (int i = 0; i < n; i++)
//	{
//		for (int y = s_y; y <= t_y; y++)
//		{
//			for (int m = 0; m < mont[i].size(); m++)
//			{
//				if (mont[i][m] >= s_mon && mont[i][m] <= t_mon)
//				{
//					for (int d = 0; d < dayofmon[i].size(); d++)
//					{
//						if (dayofmon[i][d] >= s_d && dayofmon[i][d <= t_d])
//						{
//							for (int wee = 0; wee < dayofwee[i].size(); wee++)
//							{
//								if (dayofwee[i][wee] == isweekday(y, mont[i][m], dayofmon[i][d]))
//								{
//									for (int h = 0; h < hour[i].size(); h++)
//									{
//										if (hour[i][h] >= s_h && hour[i][h] <= t_h)
//										{
//											for (int minus = 0; minus < minut[i].size(); minus++)
//											{
//												if (minut[i][minus] >= s_min && minut[i][minus < t_min])
//												{
//													string last = tostr(y, mont[i][m], dayofmon[i][d], hour[i][h], minut[i][minus]);
//													ma[last] = comma[i][0];
//												}
//											}
//										}
//									}
//								}
//							}
//						}
//					}
//				}
//			}
//		}
//	}
//	map<string, string>::iterator it;
//	for (it = ma.begin(); it != ma.end(); it++)
//	{
//		cout << it->first << " " << it->second << endl;
//	}
//
//
//	return 0;
//
//
//}
