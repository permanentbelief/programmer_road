#define _CRT_SECURE_NO_WARNINGS 1 

#include <iostream>
#include <vector>
#include <string>

using namespace std;


#include <stdio.h>

//蔡勒公式推算出这一天是星期几
int cvrt(int y, int m, int c, int w, bool B){
	//   年    月   第几个  星期几 正数或者倒数
	int d,
		week,
		i;
	if (m == 1) //如果月数为1 就是13
	{
		m = 13;
		y--;
	}//公式要求1月、2月要转为上一年13、14月
	if (m == 2)  //如果月数为2  就是14
	{
		m = 14;
		y--;
	}
	i = 0;


	for (d = B ? 1 : 31; (d <= B) ? 31 : 1; B ? (d++) : (d--)) 
	{
		week = (d + 2 * m + 3 * (m + 1) / 5 + y + y / 4 - y / 100 + y / 400) % 7;//蔡勒公式
		//week 就是星期几的意思

		//因为公式week%7 是【0,6】,所以就是 +1
		if (week + 1 == w)
			++i;
		if (i == c)
			break;
	}
	return d;//d就是几号的意思
}

int main(void){
	int y;
	while (scanf("%d", &y) != EOF)
	{
		printf("%d-01-01\n", y);
		printf("%d-01-%02d\n", y, cvrt(y, 1, 3, 1, 1));
		printf("%d-02-%02d\n", y, cvrt(y, 2, 3, 1, 1));
		printf("%d-05-%02d\n", y, cvrt(y, 5, 1, 1, 0));//倒数
		printf("%d-07-04\n", y);
		printf("%d-09-%02d\n", y, cvrt(y, 9, 1, 1, 1));
		printf("%d-11-%02d\n", y, cvrt(y, 11, 4, 4, 1));
		printf("%d-12-25\n\n", y);
	}
	return 0;
}
//int main()
//{
//	int year;
//	while (cin >> year)
//	{
//		//2014年 1.1星期二
//		vector<string> vs;
//		int dif = 0;
//		if (year > 2014)
//			dif = (2014 - year) % 7;
//		else                                            
//			dif = (2014 - year) % 7;
//		for (int i = 0; i < 8; i++)
//		{
//			switch (i)
//			{
//			case 0: {
//						string str = to_string(year) + "-01-01";
//						vs.push_back(str);
//						break;
//			}
//			case 1:{
//					   int tmp = 20 + dif;
//					   string str2 = to_string(year) + "-01-";
//					   str2 += to_string(tmp);
//					   vs.push_back(str2);
//					   break;
//			};
//			case 2:{
//					   int tmp = 17 + dif;
//					   string str3 = to_string(year) + "-02-";
//					   str3 += to_string(tmp);
//					   vs.push_back(str3);
//					   break;
//			};
//			case 3:{
//					   int tmp = 26 + dif;
//					   string str4 = to_string(year) + "-05-";
//					   str4 += to_string(tmp);
//					   vs.push_back(str4);
//					   break;
//			};
//			case 4:{
//					   vs.push_back(to_string(year) + "-07-04");
//					   break;
//			};
//			case 5:{
//					   int tmp = 1 + dif;
//					   string str = to_string(year) + "-09-";
//					   str += to_string(tmp);
//					   vs.push_back(str);
//					   break;
//			};
//			case 6:{
//					   int tmp = 27 + dif;
//					   string str = to_string(year) + "-11-";
//					   str += to_string(tmp);
//					   vs.push_back(str);
//					   break;
//			};
//
//
//			case 7:{
//					   string str = to_string(year) + "-12-25";
//					   vs.push_back(str);
//					   break;
//			};
//			};
//		}
//		for (int i = 0; i < 8; i++)
//		{
//			cout << vs[i] << endl;
//		}
//	}
//}