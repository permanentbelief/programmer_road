//#define _CRT_SECURE_NO_WARNINGS 1 
//
//#include <iostream>
//#include <string>
//using namespace std;
//
//
//bool leapYear(int year)
//{
//	if (year % 100 == 0 || ((year % 4 == 0) && (year % 400 != 0)))
//	{
//		return true;
//	}
//	return false;
//}
//bool Prime(int month)
//{
//	if (month == 2 || month == 3 || month == 5 || month == 7 || month == 11)
//		return true;
//	return false;
//}
//
//int day_money(int month)
//{
//	if (month == 2 || month == 3 || month == 5 || month == 7 || month == 11)
//		return 1;
//	return 2;
//}
//int main()
//{
//	int year1 = 0;
//	int month1 = 0;
//	int day1 = 0;
//	int year2 = 0;
//	int month2 = 0;
//	int day2 = 0;
//	static int Moneys[] = { 0, 62, 28, 31, 60, 31, 60, 31, 62, 60, 62, 30, 62 };// 1 3 5 7 11
//	while (cin >> year1 >> month1 >> day1 >> year2 >> month2 >> day2)
//	{
//		int to_money = 0;
//		int from_money = 0;
//		for (int i = 0; i < month2; i++)
//		{
//			to_money += Moneys[i];
//		}
//		if (Prime(month2))
//			to_money += day2;
//		else
//			to_money += day2 * 2;
//		if (leapYear(year2) && month2 >= 3)
//			to_money += 2;
//		for (int i = 0; i < month1; i++)
//		{
//			from_money += Moneys[i];
//		}
//		if (leapYear(year1) && month1 >= 3)
//			from_money += 2;
//		if (Prime(month1))
//			from_money += day1;
//		else
//			from_money += day1 * 2;
//		if (year2 == year1)
//		{
//			cout << to_money - from_money + day_money(month1) << endl;;
//		}
//		else
//		{
//			int dif_money = 0;
//			if (leapYear(year1))
//			{
//				dif_money += (581 - from_money + day_money(month1));
//			}
//			else
//			{
//				dif_money += (579 - from_money + day_money(month1));
//			}
//			year1 += 1;
//			for (int i = year1; i < year2; i++)
//			{
//				if (leapYear(i))
//					dif_money += 581;
//				else
//					dif_money += 579;
//
//			}
//			dif_money += to_money;
//			cout << dif_money << endl;
//
//		}
//
//	}
//}