#define _CRT_SECURE_NO_WARNINGS 1 
//方法1
/*#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void reverse(char* start, char* end)
{
	while (start<end)
	{
		char temp = *start;
		*start = *end;
		*end = temp;
		start++;
		end--;
	}
}
void reverse_string(char* str)
{
	
	while (*str)
	{
		char* temp = str;
		while (*str != ' ' && *str != '\0')
		{
			str++;
		}
		reverse(temp, str - 1);
		//此时的str指向空格的位置
		while (*str == ' ')
		{
			str++;
		}
	}
}
*/

// 牛客能跑过 但是编译器编译的时候就挂了  方法2
//#include <iostream>
//#include <string>
//#include <algorithm>
//using namespace std;
//
//int main()
//{
//	string str;
//	getline(cin, str);
//	reverse(str.begin(), str.end());
//	int i = 0;
//	auto start = str.begin();
//	auto end = str.begin();
//	while (*end)
//	{
//		//int count = 0;
//		while (*end != '\0'&& *end != ' ')
//		{
//			end++;
//		}
//		//reverse(str[i - count], str[i - 1]);
//		auto it1 = start;
//		auto it2 = end;
//		reverse(it1, it2);
//		end++;
//		start = end;
//		
//	}
//	cout << str << endl;
//	system("pause");
//} 
// 我的做法   方法三
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

void abc(char* start, char* end)
{
	while (start<end)
	{
		char temp = *start;
		*start = *end;
		*end = temp;
		start++;
		end--;
	}
}
int main()
{
	string str;
	getline(cin, str);
	reverse(str.begin(), str.end());
	int i = 0;
	while (str[i])
	{
		int count = 0;
		while (str[i] != '\0'&& str[i] != ' ')
		{
			i++;
			count++;
		}
		abc(str[i - count], str[i - 1]);
		while (str[i] == ' ')
		{
			i++;
		}
	}
	cout << str << endl;
	system("pause");
}