#define _CRT_SECURE_NO_WARNINGS 1 
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
int main()
{

	string line;
	while (getline(cin, line))
	{
		// 王炸最大 直接输出
		if (line.find("joker JOKER") != -1)
			cout << "joker JOKER" << endl;
		else
		{
			int dash = line.find('-');
			// 分开两手牌
			string str1 = line.substr(0, dash);
			string str2 = line.substr(dash + 1);
			// 获取的空格的次数
			int c1 = count(str1.begin(), str1.end(), ' ');
			int c2 = count(str2.begin(), str2.end(), ' ');
			// 拿到第一张牌
			string first1 = str1.substr(0, str1.find(' '));
			string first2 = str2.substr(0, str2.find(' '));
			string str = "2345678910JQKA2jokerJOKER";
			if (c1 == c2)
			{
				//只要牌数相等，则第一张大的就是最大
				if (str.find(first1) > str.find(first2))
					cout << str1 << endl;
				else
					cout << str2 << endl;
			}
			else // 说明类型不同 且c1，c2为3说明有炸弹，则可以进行比较
			{
				if (c1 == 3)
					cout << str1 << endl;
				else if (c2 == 3)
					cout << str2 << endl;
				else
					cout << "ERROR" << endl;
			}
		}
	}
	system("pause");
}